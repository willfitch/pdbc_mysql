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

#include "zend_interfaces.h"
#include "php_pdbc.h"

zend_class_entry *pdbc_mysql_connection_ce = NULL;
zend_object_handlers = pdbc_mysql_connection_handlers;

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

const zend_function_entry pdbc_mysql_connection_methods[] = {
	PDBC_ME(Connection, close,						arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, commit,						arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, createStatement,			arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, getAutoCommit,				arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, getCatalog,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, getClientInfo,				arginfo_pdbc_MysqlConnection_clientInfo,					ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, getMetaData,				arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, getNetworkTimeout,			arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, getSchema,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, getTransactionalIsolation,	arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, isClosed,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, prepareCall,				arginfo_pdbc_MysqlConnection_prepareCall,				ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, prepareStatement,			arginfo_pdbc_MysqlConnection_prepareStatement,			ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, rollback,					arginfo_pdbc_MysqlConnection_void,						ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, setAutoCommit,				arginfo_pdbc_MysqlConnection_setAutoCommit,				ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, setNetworkTimeout,			arginfo_pdbc_MysqlConnection_setNetworkTimeout,			ZEND_ACC_PUBLIC)
	PDBC_ME(Connection, setTransactionIsolation,	arginfo_pdbc_MysqlConnection_setTransactionIsolation,	ZEND_ACC_PUBLIC)
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

	INIT_CLASS_ENTRY(ce, CLASS_NAME_CONNECTION, pdbc_mysql_connection_methods);
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
