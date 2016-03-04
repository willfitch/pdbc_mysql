--TEST--
Check for pdbc_mysql presence
--SKIPIF--
<?php if (!extension_loaded("pdbc_mysql")) print "skip"; ?>
--FILE--
<?php
var_dump(class_exists('php\pdbc\MysqlDriver'));
?>
--EXPECT--
bool(true)
