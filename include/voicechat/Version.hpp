#pragma once

#include <cstdint>
#include <string_view>

namespace voicechat {

inline constexpr std::string_view Name = "GlobalVoiceChat";
inline constexpr std::string_view Author = "Kunal";
inline constexpr std::string_view Description = "Global push-to-talk voice chat for Minecraft Bedrock.";
inline constexpr std::string_view Version = "0.0.1";
inline constexpr std::uint32_t SdkVersion = 1;
inline constexpr std::string_view RuntimeLibrary = "libGlobalVoiceChat.so";

}
