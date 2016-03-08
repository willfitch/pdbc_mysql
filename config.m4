dnl $Id$
dnl config.m4 for extension pdbc_mysql

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(pdbc_mysql, for pdbc_mysql support,
[  --with-pdbc-mysql[=FILE]         Include pdbc_mysql support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(pdbc_mysql, whether to enable pdbc_mysql support,
dnl Make sure that the comment is aligned:
dnl [  --enable-pdbc_mysql           Enable pdbc_mysql support])

if test "$PHP_PDBC_MYSQL" != "no"; then

  MYSQL_CONFIG=$PHP_PDBC_MYSQL  
  MYSQL_LIB_NAME='mysqlclient'

  if test "$enable_maintainer_zts" = "yes"; then
    MYSQL_LIB_CFG='--libs_r'
    MYSQL_LIB_NAME='mysqlclient_r'
  else
    MYSQL_LIB_CFG='--libs'
  fi

  AC_MSG_CHECKING([for PDBC includes])

  if test -f $abs_srcdir/include/ext/pdbc/php_pdbc.h; then
    PDBC_INCLUDE=$abs_srcdir/ext
  elif test -f $abs_srcdir/ext/pdbc/php_pdbc.h; then
    PDBC_INCLUDE=$abs_srcdir/ext
  elif test -f $phpincludedir/ext/pdbc/php_pdbc.h; then
    PDBC_INCLUDE=$phpincludedir/ext
  else
    AC_MSG_ERROR([Unable to find PDBC header file php_pdbc.h])
  fi

  AC_MSG_RESULT($PDBC_INCLUDE)
    
  if test -x "$MYSQL_CONFIG" && $MYSQL_CONFIG $MYSQL_LIB_CFG > /dev/null 2>&1; then
    PDBC_INCLINE=`$MYSQL_CONFIG --cflags | $SED -e "s/'//g"`
    PDBC_LIBLINE=`$MYSQL_CONFIG $MYSQL_LIB_CFG | $SED -e "s/'//g"`
  else
    AC_MSG_RESULT([mysql_config not found])
    AC_MSG_ERROR([please specify the mysql_config location or reinstall mysql])
  fi

  dnl
  dnl Check the library
  dnl
  PHP_CHECK_LIBRARY($MYSQL_LIB_NAME, mysql_set_server_option,
  [
    PHP_EVAL_INCLINE($PDBC_INCLINE)
    PHP_EVAL_LIBLINE($PDBC_LIBLINE, PDBC_SHARED_LIBADD)
    AC_DEFINE(HAVE_MYSQLILIB, 1, [ ])
    PHP_CHECK_LIBRARY($MYSQL_LIB_NAME, mysql_set_character_set,
    [ ],[
      AC_MSG_ERROR([MySQLI doesn't support versions < 4.1.13 (for MySQL 4.1.x) and < 5.0.7 for (MySQL 5.0.x) anymore. Please update your libraries.])
    ],[$PDBC_LIBLINE])
  ],[
    AC_MSG_ERROR([wrong mysql library version or lib not found. Check config.log for more information.])
  ],[
    $PDBC_LIBLINE
  ])

  dnl
  dnl Check the library for mysql_stmt_next_result
  dnl
  PHP_CHECK_LIBRARY($MYSQL_LIB_NAME, mysql_stmt_next_result,
  [
    AC_DEFINE(HAVE_STMT_NEXT_RESULT,             1, [ ])
  ],[
  ],[
    $PDBC_LIBLINE
  ])

  LDFLAGS=$PDBC_LIBLINE

  PDBC_MYSQL_CLASSES="\
    pdbc_mysql_driver.c \
    pdbc_mysql_connection.c \
    pdbc_mysql_metadata.c \
  ";

  PHP_SUBST(PDBC_SHARED_LIBADD)

  PHP_NEW_EXTENSION(pdbc_mysql, pdbc_mysql.c $PDBC_MYSQL_CLASSES, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
