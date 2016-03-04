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

#include "php_pdbc_mysql.h"

zend_class_entry *pdbc_mysql_driver_ce = NULL;
zend_object_handlers pdbc_mysql_driver_handlers;

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_mysql_Driver_void, 0, 0, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_mysql_Driver_acceptsUrl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_mysql_Driver_connect, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO();

PDBC_METHOD(MysqlDriver, __construct)
{
}

PDBC_METHOD(MysqlDriver, acceptsUrl)
{
	zend_string *url = NULL;
	pdbc_conn_info_t *conn = NULL;
	char error[256];

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &url) == FAILURE) {
		return;
	}

	if ((conn = pdbc_parse_url(url, error)) == NULL) {
		RETURN_FALSE;
	}

	if (strcmp(conn->driver->val, "mysql") == 0) {
		pdbc_free_url(conn);
		RETURN_TRUE;
	}

	pdbc_free_url(conn);
	RETURN_FALSE;
}

PDBC_METHOD(MysqlDriver, connect)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlDriver, getMajorVersion)
{
	zend_long version = PHP_PDBC_MYSQL_MAJOR_VERSION;
	RETURN_LONG(version);
}

PDBC_METHOD(MysqlDriver, getMinorVersion)
{
	zend_long version = PHP_PDBC_MYSQL_MINOR_VERSION;
	RETURN_LONG(version);
}

const zend_function_entry pdbc_mysql_driver_methods[] = {
	PDBC_ME(MysqlDriver, __construct,		arginfo_pdbc_mysql_Driver_void,			ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PDBC_ME(MysqlDriver, acceptsUrl,			arginfo_pdbc_mysql_Driver_acceptsUrl,	ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlDriver, connect,			arginfo_pdbc_mysql_Driver_connect,		ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlDriver, getMajorVersion,	arginfo_pdbc_mysql_Driver_void,			ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlDriver, getMinorVersion,	arginfo_pdbc_mysql_Driver_void,			ZEND_ACC_PUBLIC)
	PHP_FE_END
};

static zend_object *pdbc_mysql_driver_create_object(zend_class_entry *ce)
{
	pdbc_mysql_driver_t *intern;
	intern = ecalloc(1, sizeof(pdbc_driver_manager_t) + zend_object_properties_size(ce));

	zend_object_std_init(&intern->zo, ce);
	object_properties_init(&intern->zo, ce);

	intern->zo.handlers = &pdbc_mysql_driver_handlers;
	return &intern->zo;
}

static void pdbc_mysql_driver_free_object(zend_object *obj)
{
	zend_object_std_dtor(obj);
}

static void pdbc_mysql_driver_destroy_object(zend_object *obj)
{
	zend_objects_destroy_object(obj);
}

void pdbc_mysql_define_driver(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, MYSQL_CLASS_NAME_DRIVER, pdbc_mysql_driver_methods);
	pdbc_mysql_driver_ce = zend_register_internal_class(&ce);
	pdbc_mysql_driver_ce->create_object = pdbc_mysql_driver_create_object;

	memcpy(&pdbc_mysql_driver_handlers, zend_get_std_object_handlers(), sizeof(pdbc_mysql_driver_handlers));
	pdbc_mysql_driver_handlers.free_obj = pdbc_mysql_driver_free_object;
	pdbc_mysql_driver_handlers.dtor_obj = pdbc_mysql_driver_destroy_object;
	pdbc_mysql_driver_handlers.offset = XtOffsetOf(pdbc_mysql_driver_t, zo);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: fdm=marker
 * vim: noet sw=4 ts=4
 */
