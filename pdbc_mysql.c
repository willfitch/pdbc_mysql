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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_pdbc_mysql.h"
#include <mysql.h>

static zend_object *pdbc_mysql_create_connection(pdbc_handle_t *);
static zend_object *pdbc_mysql_get_driver_instance();

/* If you declare any globals in php_pdbc_mysql.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(pdbc_mysql)
*/

/* True global resources - no need for thread safety here */
static int le_pdbc_mysql;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("pdbc_mysql.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_pdbc_mysql_globals, pdbc_mysql_globals)
    STD_PHP_INI_ENTRY("pdbc_mysql.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_pdbc_mysql_globals, pdbc_mysql_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_pdbc_mysql_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_pdbc_mysql_init_globals(zend_pdbc_mysql_globals *pdbc_mysql_globals)
{
	pdbc_mysql_globals->global_value = 0;
	pdbc_mysql_globals->global_string = NULL;
}
*/
/* }}} */

static zend_object *pdbc_mysql_get_driver_instance()
{
	zend_object *obj;
	return obj;
}

static zend_object *pdbc_mysql_create_connection(pdbc_handle_t *handle)
{
	zend_object *obj;
	return obj;
}

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(pdbc_mysql)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	pdbc_driver_t *driver;
	zend_string *name;
	driver = emalloc(sizeof(pdbc_driver_t));

	name = zend_string_init("mysql", sizeof("mysql") - 1, 0);

	driver->name = name;
	driver->get_driver_instance = pdbc_mysql_get_driver_instance;
	driver->create_connection = pdbc_mysql_create_connection;

	pdbc_register_driver(driver);
	pdbc_mysql_define_driver(TSRMLS_C);
	pdbc_mysql_define_connection(TSRMLS_C);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(pdbc_mysql)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(pdbc_mysql)
{
#if defined(COMPILE_DL_PDBC_MYSQL) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(pdbc_mysql)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(pdbc_mysql)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "PDBC MySQL Driver", "enabled");
	php_info_print_table_row(2, "PDBC MySQL Driver Version", PHP_PDBC_MYSQL_VERSION);
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ pdbc_mysql_functions[]
 *
 * Every user visible function must have an entry in pdbc_mysql_functions[].
 */
const zend_function_entry pdbc_mysql_functions[] = {
	PHP_FE_END
};
/* }}} */

/* {{{ pdbc_mysql_module_entry
 */
zend_module_entry pdbc_mysql_module_entry = {
	STANDARD_MODULE_HEADER,
	"pdbc_mysql",
	pdbc_mysql_functions,
	PHP_MINIT(pdbc_mysql),
	PHP_MSHUTDOWN(pdbc_mysql),
	PHP_RINIT(pdbc_mysql),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(pdbc_mysql),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(pdbc_mysql),
	PHP_PDBC_MYSQL_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PDBC_MYSQL
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(pdbc_mysql)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
