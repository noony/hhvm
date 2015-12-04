HHVM_DEFINE_EXTENSION("gd"
  IS_ENABLED EXT_DBA
  SOURCES
    ext_dba.cpp
    dba_cdb.cpp
    dba_db1.cpp
    dba_db2.cpp
    dba_db3.cpp
    dba_db4.cpp
    dba_dbm.cpp
    dba_flatfile.cpp
    dba_gdbm.cpp
    dba_inifile.cpp
    dba_ndbm.cpp
    dba_qdbm.cpp
    dba_tcadb.cpp
    libcdb/cdb.cpp
    libcdb/cdb_make.cpp
    libcdb/uint32.cpp
    libflatfile/flatfile.cpp
    libinifile/inifile.cpp
  HEADERS
    libcdb/cdb.h
    libcdb/cdb_make.h
    libcdb/uint32.h
    libflatfile/flatfile.h
    libinifile/inifile.h
    php_cdb.h
    php_db1.h
    php_db2.h
    php_db3.h
    php_db4.h
    php_dba.h
    php_dbm.h
    php_flatfile.h
    php_gdbm.h
    php_inifile.h
    php_ndbm.h
    php_qdbm.h
    php_tcadb.h
  SYSTEMLIB
    ext_dba.php
)
