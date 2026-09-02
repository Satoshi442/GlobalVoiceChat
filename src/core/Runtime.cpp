#include "Runtime.hpp"

#include <voicechat/Version.hpp>

#include <android/log.h>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

#define VC_LOG_TAG "GlobalVoiceChat"
#define VC_LOG(...) __android_log_print(ANDROID_LOG_INFO, VC_LOG_TAG, __VA_ARGS__)

namespace voicechat::core {

Runtime& Runtime::get() {
    static Runtime runtime;
    return runtime;
}

bool Runtime::launcherContext() const {
    int fd = open("/proc/self/cmdline", O_RDONLY);
    if (fd < 0) return false;
    char command[256]{};
    const auto size = read(fd, command, sizeof(command) - 1);
    close(fd);
    if (size <= 0) return false;
    return std::strcmp(command, "org.levimc.launcher") == 0
        || std::strcmp(command, "org.levimc.launcher:minecraft") == 0
        || std::strcmp(command, "com.mojang.minecraftpe") == 0;
}

bool Runtime::load(pl::mod::ModContext& context) {
    VC_LOG("load() called - version %s", std::string(Version).c_str());
    VC_LOG("resourceDir=%s", context.resourceDir().string().c_str());
    VC_LOG("configDir=%s", context.configDir().string().c_str());
    VC_LOG("launcherContext=%s", launcherContext() ? "true" : "false");
    return true;
}

bool Runtime::enable(pl::mod::ModContext&) {
    mEnabled = true;
    VC_LOG("enable() called - mod is now active");
    return true;
}

bool Runtime::disable(pl::mod::ModContext&) {
    mEnabled = false;
    VC_LOG("disable() called - mod is now inactive");
    return true;
}

bool Runtime::unload(pl::mod::ModContext&) {
    mEnabled = false;
    VC_LOG("unload() called");
    return true;
}

}
