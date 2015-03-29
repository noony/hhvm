<?php
require_once(dirname(__FILE__) .'/test.inc');
echo "database handler: $handler\n";
if (($db_file=dba_open($db_filename, "n", $handler))!==FALSE) {
    dba_insert("key1", "Content String 1", $db_file);
    dba_insert("key2", "Content String 2", $db_file);
    $a = dba_firstkey($db_file);
    $i=0;
    while($a) {
        $a = dba_nextkey($db_file);
        $i++;
    }
    echo $i;
    for ($i=1; $i<3; $i++) {
        echo dba_exists("key$i", $db_file) ? "Y" : "N";
    }
    echo "\n";
    var_dump(dba_optimize());
    var_dump(dba_optimize(""));
    var_dump(dba_optimize($db_file));
    dba_close($db_file);
} else {
    echo "Error creating database\n";
}

===DONE===
<?php exit(0); 
	require(dirname(__FILE__) .'/clean.inc'); 
?>
