dnl $Id$
dnl config.m4 for extension pdbc_mysql

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(pdbc_mysql, for pdbc_mysql support,
[  --with-pdbc-mysql             Include pdbc_mysql support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(pdbc_mysql, whether to enable pdbc_mysql support,
dnl Make sure that the comment is aligned:
dnl [  --enable-pdbc_mysql           Enable pdbc_mysql support])

if test "$PHP_PDBC_MYSQL" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-pdbc_mysql -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/pdbc_mysql.h"  # you most likely want to change this
  dnl if test -r $PHP_PDBC_MYSQL/$SEARCH_FOR; then # path given as parameter
  dnl   PDBC_MYSQL_DIR=$PHP_PDBC_MYSQL
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for pdbc_mysql files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PDBC_MYSQL_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PDBC_MYSQL_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the pdbc_mysql distribution])
  dnl fi

  dnl # --with-pdbc_mysql -> add include path
  dnl PHP_ADD_INCLUDE($PDBC_MYSQL_DIR/include)

  dnl # --with-pdbc_mysql -> check for lib and symbol presence
  dnl LIBNAME=pdbc_mysql # you may want to change this
  dnl LIBSYMBOL=pdbc_mysql # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PDBC_MYSQL_DIR/$PHP_LIBDIR, PDBC_MYSQL_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PDBC_MYSQLLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong pdbc_mysql lib version or lib not found])
  dnl ],[
  dnl   -L$PDBC_MYSQL_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PDBC_MYSQL_SHARED_LIBADD)

  PHP_NEW_EXTENSION(pdbc_mysql, pdbc_mysql.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
