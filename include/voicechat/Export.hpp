#pragma once

#if defined(__GNUC__) || defined(__clang__)
#define VOICECHAT_API __attribute__((visibility("default")))
#else
#define VOICECHAT_API
#endif
