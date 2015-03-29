<?php

$handler = "db4";
require_once(dirname(__FILE__) .'/test.inc');
echo "database handler: $handler\n";
if (($db_file = dba_open($db_filename, "rl", $handler)) !== FALSE) {
    echo "database file created\n";
    dba_close($db_file);
} else {
    echo "Error creating $db_filename\n";
} 
require(dirname(__FILE__) .'/clean.inc'); 
?>
