<?php

$handler = "db4";
require_once(dirname(__FILE__) .'/test.inc');
echo "database handler: $handler\n";

var_dump(file_put_contents($db_filename, "Dummy contents"));

if (($db_file = dba_popen($db_filename, "n", $handler)) !== FALSE) {
    if (file_exists($db_filename)) {
        echo "database file created\n";
        dba_insert("key1", "This is a test insert", $db_file);
        echo dba_fetch("key1", $db_file), "\n";
        dba_close($db_file);
    } else {
        echo "File did not get created\n";
    }
} else {
    echo "Error creating $db_filename\n";
} 
require(dirname(__FILE__) .'/clean.inc'); 
?>
