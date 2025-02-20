#include "lib.hpp"
#include "nn/fs.hpp"

HOOK_DEFINE_INLINE(MountSDCard) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        nn::fs::MountSdCardForDebug("sd");
    }
};

static const char VERISON[] = "Game Version: 1.0.2";

HOOK_DEFINE_REPLACE(GetVersionString) {
    static const char* Callback() {
        return VERISON;
    }
};

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking environment. */
    exl::hook::Initialize();
    MountSDCard::InstallAtOffset(0x1eb74);
    GetVersionString::InstallAtOffset(0x1fcc4);
}

extern "C" NORETURN void exl_exception_entry() {
    /* Note: this is only applicable in the context of applets/sysmodules. */
    EXL_ABORT("Default exception handler called!");
}