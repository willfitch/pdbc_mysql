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

zend_class_entry *pdbc_mysql_connection_ce = NULL;
zend_object_handlers pdbc_mysql_connection_handlers;

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection_void, 0, 0, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection_clientInfo, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection_prepareCall, 0, 0, 0)
	ZEND_ARG_INFO(0, sql)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection_prepareStatement, 0, 0, 0)
	ZEND_ARG_INFO(0, sql)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection_setAutoCommit, 0, 0, 0)
	ZEND_ARG_INFO(0, autoCommit)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection_setNetworkTimeout, 0, 0, 0)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection_setTransactionIsolation, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlConnection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO();

PDBC_METHOD(MysqlConnection, __construct)
{
	zend_string *url = NULL;
	zend_string *user = NULL;
	zend_string *password = NULL;
	pdbc_driver_t *driver = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "S|SS", &url, &user, &password) == FAILURE) {
		return;
	}
}

PDBC_METHOD(MysqlConnection, close)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, commit)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, createStatement)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, getAutoCommit)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, getCatalog)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, getClientInfo)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, getMetaData)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, getNetworkTimeout)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, getSchema)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, getTransactionIsolation)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, isClosed)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, prepareCall)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, prepareStatement)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, rollback)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, setAutoCommit)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, setNetworkTimeout)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlConnection, setTransactionIsolation)
{
	RETURN_FALSE;
}

const zend_function_entry pdbc_mysql_connection_methods[] = {
	PDBC_ME(MysqlConnection, __construct,				arginfo_pdbc_MysqlConnection___construct,				ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PDBC_ME(MysqlConnection, close,						arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, commit,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, createStatement,			arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, getAutoCommit,				arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, getCatalog,				arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, getClientInfo,				arginfo_pdbc_MysqlConnection_clientInfo,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, getMetaData,				arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, getNetworkTimeout,			arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, getSchema,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, getTransactionIsolation,	arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, isClosed,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, prepareCall,				arginfo_pdbc_MysqlConnection_prepareCall,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, prepareStatement,			arginfo_pdbc_MysqlConnection_prepareStatement,			ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, rollback,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, setAutoCommit,				arginfo_pdbc_MysqlConnection_setAutoCommit,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, setNetworkTimeout,			arginfo_pdbc_MysqlConnection_setNetworkTimeout,			ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlConnection, setTransactionIsolation,	arginfo_pdbc_MysqlConnection_setTransactionIsolation,	ZEND_ACC_PUBLIC)
	PHP_FE_END
};


static zend_object *pdbc_mysql_connection_create_object(zend_class_entry *ce)
{
	pdbc_mysql_connection_t *intern;
	intern = ecalloc(1, sizeof(pdbc_mysql_connection_t) + zend_object_properties_size(ce));

	zend_object_std_init(&intern->zo, ce);
	object_properties_init(&intern->zo, ce);

	intern->zo.handlers = &pdbc_mysql_connection_handlers;
	return &intern->zo;
}

static void pdbc_mysql_connection_free_object(zend_object *obj)
{
	zend_object_std_dtor(obj);
}

static void pdbc_mysql_connection_destroy_object(zend_object *obj)
{
	zend_objects_destroy_object(obj);
}

void pdbc_mysql_define_connection(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, MYSQL_CLASS_NAME_CONNECTION, pdbc_mysql_connection_methods);
	pdbc_mysql_connection_ce = zend_register_internal_class(&ce);
	zend_class_implements(pdbc_mysql_connection_ce, 1, pdbc_connection_ce);
	pdbc_mysql_connection_ce->create_object = pdbc_mysql_connection_create_object;

	memcpy(&pdbc_mysql_connection_handlers, zend_get_std_object_handlers(), sizeof(pdbc_mysql_connection_handlers));
	pdbc_mysql_connection_handlers.free_obj = pdbc_mysql_connection_free_object;
	pdbc_mysql_connection_handlers.dtor_obj = pdbc_mysql_connection_destroy_object;
	pdbc_mysql_connection_handlers.offset = XtOffsetOf(pdbc_mysql_connection_t, zo);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: fdm=marker
 * vim: noet sw=4 ts=4
 */
