/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Will Fitch <willfitch@php.net>                               |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_PDBC_MYSQL_H
#define PHP_PDBC_MYSQL_H
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "pdbc/php_pdbc.h"
#include <mysql.h>

extern zend_module_entry pdbc_mysql_module_entry;
#define phpext_pdbc_mysql_ptr &pdbc_mysql_module_entry

#define PHP_PDBC_MYSQL_VERSION "0.1.0" 
#define PHP_PDBC_MYSQL_MAJOR_VERSION 0
#define PHP_PDBC_MYSQL_MINOR_VERSION 1

#ifdef PHP_WIN32
#	define PHP_PDBC_MYSQL_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_PDBC_MYSQL_API __attribute__ ((visibility("default")))
#else
#	define PHP_PDBC_MYSQL_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define Z_MYCON_P(zv) pdbc_mysql_connect_fetch_object(Z_OBJ_P(zv))

#define MYSQL_CLASS_NAME_DRIVER "php\\pdbc\\MysqlDriver"
#define MYSQL_CLASS_NAME_CONNECTION "php\\pdbc\\MysqlConnection"
#define MYSQL_CLASS_NAME_MYSQL_METADATA "php\\pdbc\\MysqlDatabaseMetaData"
#define MYSQL_CLASS_NAME_RESULTSET "php\\pdbc\\MysqlResultSet"
#define MYSQL_CLASS_NAME_STATEMENT "php\\pdbc\\MysqlStatement"
#define MYSQL_CLASS_NAME_DRIVER_MANAGER "php\\pdbc\\MysqlDriverManager"
#define MYSQL_CLASS_NAME_TYPES "php\\pdbc\\MysqlTypes"

extern zend_class_entry *pdbc_mysql_connection_ce;
extern zend_class_entry *pdbc_mysql_driver_ce;

typedef struct {
	zend_object zo;
} pdbc_mysql_driver_t;

typedef struct {
	struct _mysql_connection {
		MYSQL *mysql;
	} conn;

	pdbc_handle_t *handle;
	zend_object zo;
} pdbc_mysql_connection_t;

typedef struct {
	zend_object zo;
} pdbc_mysql_metadata_t;
/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(pdbc_mysql)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(pdbc_mysql)
*/

PHP_PDBC_MYSQL_API void pdbc_mysql_define_driver(TSRMLS_D);
PHP_PDBC_MYSQL_API void pdbc_mysql_define_connection(TSRMLS_D);
PHP_PDBC_MYSQL_API void pdbc_mysql_define_db_metadata(TSRMLS_D);

static inline pdbc_mysql_connection_t *pdbc_mysql_connect_fetch_object(zend_object *obj)
{
    return (pdbc_mysql_connection_t *)((char *)(obj) - XtOffsetOf(pdbc_mysql_connection_t, zo));
}


/* Always refer to the globals in your function as PDBC_MYSQL_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define PDBC_MYSQL_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(pdbc_mysql, v)

#if defined(ZTS) && defined(COMPILE_DL_PDBC_MYSQL)
ZEND_TSRMLS_CACHE_EXTERN();
#endif

#endif	/* PHP_PDBC_MYSQL_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
