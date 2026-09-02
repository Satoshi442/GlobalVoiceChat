#include "core/Runtime.hpp"
#include <pl/Mod.hpp>

class GlobalVoiceChatMod {
public:
    static GlobalVoiceChatMod& instance() {
        static GlobalVoiceChatMod mod;
        return mod;
    }

    bool load(pl::mod::ModContext& context) { return voicechat::core::Runtime::get().load(context); }
    bool enable(pl::mod::ModContext& context) { return voicechat::core::Runtime::get().enable(context); }
    bool disable(pl::mod::ModContext& context) { return voicechat::core::Runtime::get().disable(context); }
    bool unload(pl::mod::ModContext& context) { return voicechat::core::Runtime::get().unload(context); }
};

PL_REGISTER_MOD(GlobalVoiceChatMod, GlobalVoiceChatMod::instance())
