
#ifndef ZIRCON_SYSTEM_HOST_BANJO_INCLUDE_BANJO_SOURCE_MANAGER_H_
#define ZIRCON_SYSTEM_HOST_BANJO_INCLUDE_BANJO_SOURCE_MANAGER_H_

#include <memory>
#include <vector>

#include "banjo/source_file.h"
#include "string_view.h"

namespace banjo {

class SourceManager {
public:
    // Returns whether the filename was successfully read.
    bool CreateSource(StringView filename);
    void AddSourceFile(std::unique_ptr<SourceFile> file);

    const std::vector<std::unique_ptr<SourceFile>>& sources() const { return sources_; }

private:
    std::vector<std::unique_ptr<SourceFile>> sources_;
};

} // namespace banjo

#endif // ZIRCON_SYSTEM_HOST_BANJO_INCLUDE_BANJO_SOURCE_MANAGER_H_
