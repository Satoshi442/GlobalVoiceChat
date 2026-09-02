#pragma once

#include <pl/Mod.hpp>

namespace voicechat::core {

// Runtime owns the mod's lifecycle. In Phase 0 it does nothing but prove
// that load/enable/disable/unload are being called correctly by the
// Preloader, and that we can tell the launcher process apart from the
// actual Minecraft process (same check BedrockTools uses).
class Runtime {
public:
    static Runtime& get();

    bool load(pl::mod::ModContext& context);
    bool enable(pl::mod::ModContext& context);
    bool disable(pl::mod::ModContext& context);
    bool unload(pl::mod::ModContext& context);

private:
    // Returns true only when running inside the launcher/Minecraft process,
    // as opposed to some other process that happens to load this .so.
    bool launcherContext() const;

    bool mEnabled = false;
};

}
