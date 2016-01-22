/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2015 Facebook, Inc. (http://www.facebook.com)     |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#include "hphp/runtime/ext/gd/ext_dba.h"

#include "php_gdbm.h"
#include "php_ndbm.h"
#include "php_dbm.h"
#include "php_cdb.h"
#include "php_db1.h"
#include "php_db2.h"
#include "php_db3.h"
#include "php_db4.h"
#include "php_flatfile.h"
#include "php_inifile.h"
#include "php_qdbm.h"
#include "php_tcadb.h"

namespace HPHP {

///////////////////////////////////////////////////////////////////////////////
// engines

static DbaEngineMap DbaEngines;
using DbaEnginePtr = std::shared_ptr<DbaEngine>;

class DbaEngineMapInitializer {
public:
  DbaEngineMapInitializer() {
    DbaEngines["dbm"] = DbaEnginePtr(new hash_md2());
    DbaEngines["ndbm"] = DbaEnginePtr(new hash_md2());
    DbaEngines["gdbm"] = DbaEnginePtr(new hash_md2());
    // TODO db2, db3, db4
    DbaEngines["cdb"] = DbaEnginePtr(new hash_md2());
    DbaEngines["cdb_make"] = DbaEnginePtr(new hash_md2());
    DbaEngines["flatfile"] = DbaEnginePtr(new hash_md2());
    DbaEngines["inifile"] = DbaEnginePtr(new hash_md2());
    DbaEngines["qdbm"] = DbaEnginePtr(new hash_md2());
  }
};

static HashEngineMapInitializer s_engine_initializer;

///////////////////////////////////////////////////////////////////////////////

Variant HHVM_FUNCTION(dba_open, const String& path, const String mode, const String handler, const Array& args) {
  auto stream = File::Open(filename, "rb");
  if (!stream) {
    raise_warning("failed to open file: %s", filename.c_str());
    return false;
  }
  int itype = php_getimagetype(stream);
  stream->close();
  if (itype == IMAGE_FILETYPE_UNKNOWN) return false;
  return itype;
}

///////////////////////////////////////////////////////////////////////////////

class DbaExtension final : public Extension {
 public:
  DbaExtension() : Extension("dba", NO_EXTENSION_VERSION_YET) {}

  void moduleInit() override {
    HHVM_FE(dba_open)
    HHVM_FE(dba_popen)
    HHVM_FE(dba_close)
    HHVM_FE(dba_delete)
    HHVM_FE(dba_exists)
    HHVM_FE(dba_fetch)
    HHVM_FE(dba_insert)
    HHVM_FE(dba_replace)
    HHVM_FE(dba_firstkey)
    HHVM_FE(dba_nextkey)
    HHVM_FE(dba_optimize)
    HHVM_FE(dba_sync)
    HHVM_FE(dba_handlers)
    HHVM_FE(dba_list)
    HHVM_FE(dba_key_split)

    HHVM_RC_INT(EXIF_USE_MBSTRING, 0);

    loadSystemlib();
  }
} s_dba_extension;

///////////////////////////////////////////////////////////////////////////////
}
