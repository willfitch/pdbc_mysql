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

zend_class_entry *pdbc_mysql_database_meta_data_ce = NULL;
zend_object_handlers pdbc_mysql_dbmetadata_handlers;

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlMetaData_void, 0, 0, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlMetaData_getColumnPrivileges, 0, 0, 3)
	ZEND_ARG_INFO(0, catalog)
	ZEND_ARG_INFO(0, schema)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdbc_MysqlMetaData_getColumns, 0, 0, 3)
	ZEND_ARG_INFO(0, catalog)
	ZEND_ARG_INFO(0, schema)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO();

PDBC_METHOD(MysqlMetaData, getCatalogs)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getCatalogSeparator)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getCatalogTerm)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getColumnPrivileges)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getColumns)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getDatabaseMajorVersion)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getDatabaseMinorVersion)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getDriverName)
{
	RETURN_FALSE;
}

PDBC_METHOD(MysqlMetaData, getDriverVersion)
{
	RETURN_FALSE;
}

const zend_function_entry pdbc_mysql_metadata_methods[] = {
	PDBC_ME(MysqlMetaData, getCatalogs,				arginfo_pdbc_MysqlMetaData_void,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getCatalogSeparator,		arginfo_pdbc_MysqlMetaData_void,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getCatalogTerm,			arginfo_pdbc_MysqlMetaData_void,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getColumnPrivileges,		arginfo_pdbc_MysqlMetaData_getColumnPrivileges,	ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getColumns,				arginfo_pdbc_MysqlMetaData_getColumns,			ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getDatabaseMajorVersion,	arginfo_pdbc_MysqlMetaData_void,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getDatabaseMinorVersion,	arginfo_pdbc_MysqlMetaData_void,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getDriverName,			arginfo_pdbc_MysqlMetaData_void,				ZEND_ACC_PUBLIC)
	PDBC_ME(MysqlMetaData, getDriverVersion,		arginfo_pdbc_MysqlMetaData_void,				ZEND_ACC_PUBLIC)
	PHP_FE_END
};

static void pdbc_dbmetadata_free_object(zend_object *obj)
{
	zend_object_std_dtor(obj);	
}

static void pdbc_dbmetadata_destroy_object(zend_object *obj)
{
	zend_objects_destroy_object(obj);
}

static zend_object *pdbc_dbmetadata_create_object(zend_class_entry *ce)
{
	pdbc_mysql_metadata_t *intern;
	intern = ecalloc(1, sizeof(pdbc_mysql_metadata_t) + zend_object_properties_size(ce));

	zend_object_std_init(&intern->zo, ce);
	object_properties_init(&intern->zo, ce);

	intern->zo.handlers = &pdbc_mysql_dbmetadata_handlers;
	return &intern->zo;
}

void pdbc_mysql_define_db_metadata(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, MYSQL_CLASS_NAME_MYSQL_METADATA, pdbc_mysql_metadata_methods);
	pdbc_mysql_database_meta_data_ce = zend_register_internal_class(&ce);

	pdbc_mysql_database_meta_data_ce = zend_register_internal_class(&ce);
	zend_class_implements(pdbc_mysql_database_meta_data_ce, 1, pdbc_database_meta_data_ce);
	pdbc_mysql_database_meta_data_ce->create_object = pdbc_dbmetadata_create_object;
	
	memcpy(&pdbc_mysql_dbmetadata_handlers, zend_get_std_object_handlers(), sizeof(pdbc_mysql_dbmetadata_handlers));
	pdbc_mysql_dbmetadata_handlers.free_obj = pdbc_dbmetadata_free_object;
	pdbc_mysql_dbmetadata_handlers.dtor_obj = pdbc_dbmetadata_destroy_object;
	pdbc_mysql_dbmetadata_handlers.offset = XtOffsetOf(pdbc_mysql_metadata_t, zo);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: fdm=marker
 * vim: noet sw=4 ts=4
 */
