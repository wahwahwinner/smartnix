
// The definitions corresponding to the declarations in this file are
// automatically generated by the build system.  See rules.mk for the
// gory details.

#ifndef ZIRCON_SYSTEM_HOST_FIDL_INCLUDE_FIDL_JSON_SCHEMA_H_
#define ZIRCON_SYSTEM_HOST_FIDL_INCLUDE_FIDL_JSON_SCHEMA_H_

#include <string>

class JsonSchema {
public:
    static std::string& schema() { return schema_; }

private:
    static std::string schema_;
};

#endif // ZIRCON_SYSTEM_HOST_FIDL_INCLUDE_FIDL_JSON_SCHEMA_H_
