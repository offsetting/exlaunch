#include "lib.hpp"
#include "nn/fs.hpp"

namespace inst = exl::armv8::inst;
namespace reg = exl::armv8::reg;

struct FrontEndCharacterName {
	const char* carName;
	const char* localizedName;
	const char* carNameUpper;
};

const char* g_AllCharacterNames[43] = {
    "cars3_arvy",
    "cars3_bg_explodingminion",
    "cars3_bg_gremlin_purple",
    "cars3_bg_pacer",
    "cars3_bg_yugo",
    "cars3_bg_zapor",
    "cars3_bobby",
    "cars3_brick",
    "cars3_chickhicks",
    "cars3_crazy8_airborne",
    "cars3_crazy8_bill",
    "cars3_crazy8_broadside",
    "cars3_crazy8_highimpact",
    "cars3_cruz",
    "cars3_dochudson",
    "cars3_drdamage",
    "cars3_dronered",
    "cars3_dronetruck",
    "cars3_dronewhite",
    "cars3_fillmore",
    "cars3_flo",
    "cars3_fritter",
    "cars3_guido",
    "cars3_jacksonstorm",
    "cars3_king",
    "cars3_louise",
    "cars3_luigi",
    "cars3_mack",
    "cars3_mater",
    "cars3_materthegreater",
    "cars3_mcqueen",
    "cars3_mcqueen_hudson",
    "cars3_natalie",
    "cars3_ramone",
    "cars3_river",
    "cars3_sally",
    "cars3_sarge",
    "cars3_sheriff",
    "cars3_smokey",
    "cars3_superfan",
    "cars3_tankcoat",
    "cars3_trippledent",
    "cars3_tucker",
    // "cars3_​chicklone" // shoutout fastplayer
};

FrontEndCharacterName g_FECarNames[30] = {
    {
        .carName = "Cars3_McQueen",
        .localizedName = "LightningMcQueen",
        .carNameUpper = "CARS3_MCQUEEN",
    },
    {
        .carName = "Cars3_Cruz",
        .localizedName = "Cruz",
        .carNameUpper = "CARS3_CRUZ",
    },
    {
        .carName = "Cars3_Mater",
        .localizedName = "Mater",
        .carNameUpper = "CARS3_MATER",
    },
    {
        .carName = "Cars3_Sally",
        .localizedName = "Sally",
        .carNameUpper = "CARS3_SALLY",
    },
    {
        .carName = "Cars3_Ramone",
        .localizedName = "Ramone",
        .carNameUpper = "CARS3_RAMONE",
    },
    {
        .carName = "Cars3_Guido",
        .localizedName = "Guido",
        .carNameUpper = "CARS3_GUIDO",
    },
    {
        .carName = "Cars3_MaterTheGreater",
        .localizedName = "MaterTheGreater",
        .carNameUpper = "CARS3_MATERTHEGREATER",
    },
    {
        .carName = "Cars3_Bobby",
        .localizedName = "BobbySwift",
        .carNameUpper = "CARS3_BOBBYSWIFT",
    },
    {
        .carName = "Cars3_Brick",
        .localizedName = "BrickYardley",
        .carNameUpper = "CARS3_BRICKYARDLEY",
    },
    {
        .carName = "Cars3_ChickHicks",
        .localizedName = "ChickHicks",
        .carNameUpper = "CARS3_CHICKHICKS",
    },
    {
        .carName = "Cars3_Natalie",
        .localizedName = "Natalie",
        .carNameUpper = "CARS3_NATALIECERTAIN",
    },
    {
        .carName = "Cars3_McQueen_Hudson",
        .localizedName = "McQueenHudson",
        .carNameUpper = "CARS3_DINOCO_MCQUEEN",
    },
    {
        .carName = "Cars3_Arvy",
        .localizedName = "Arvy",
        .carNameUpper = "CARS3_ARVY",
    },
    {
        .carName = "Cars3_DrDamage",
        .localizedName = "DrDamage",
        .carNameUpper = "CARS3_DRDAMAGE",
    },
    {
        .carName = "Cars3_Fritter",
        .localizedName = "MissFritter",
        .carNameUpper = "CARS3_MISSFRITTER",
    },
    {
        .carName = "Cars3_TrippleDent",
        .localizedName = "TripleDent",
        .carNameUpper = "CARS3_TRIPLEDENT",
    },
    {
        .carName = "Cars3_TankCoat",
        .localizedName = "TankCoat",
        .carNameUpper = "CARS3_TANKCOAT",
    },
    {
        .carName = "Cars3_JacksonStorm",
        .localizedName = "JacksonStorm",
        .carNameUpper = "CARS3_JACKSONSTORM",
    },
    {
        .carName = "Cars3_Tucker",
        .localizedName = "JuniorMoon",
        .carNameUpper = "CARS3_JUNIORMOON",
    },
    {
        .carName = "Cars3_Louise",
        .localizedName = "Louise",
        .carNameUpper = "CARS3_LOUISE",
    },
    {
        .carName = "Cars3_River",
        .localizedName = "RiverScott",
        .carNameUpper = "CARS3_RIVERSCOTT",
    },
    {
        .carName = "Cars3_Smokey",
        .localizedName = "Smokey",
        .carNameUpper = "CARS3_SMOKEY",
    },
    {
        .carName = "Cars3_Mack",
        .localizedName = "Mack",
        .carNameUpper = "CARS3_MACK",
    },
    {
        .carName = "Cars3_DocHudson",
        .localizedName = "DocHudson",
        .carNameUpper = "CARS3_DOCHUDSON",
    },
    {
        .carName = "Cars3_Crazy8_HighImpact",
        .localizedName = "",
        .carNameUpper = "",
    },
    {
        .carName = "Cars3_Crazy8_Airborne",
        .localizedName = "",
        .carNameUpper = "",
    },
    {
        .carName = "Cars3_Crazy8_Bill",
        .localizedName = "",
        .carNameUpper = "",
    },
    {
        .carName = "Cars3_Crazy8_Broadside",
        .localizedName = "",
        .carNameUpper = "",
    },
    {
        .carName = "Cars3_Sheriff",
        .localizedName = "",
        .carNameUpper = "",
    },
    {
        .carName = "Cars3_Sheriff",
        .localizedName = "",
        .carNameUpper = "",
    },
};

constexpr auto CAR_NAME_LIST_LEN = sizeof(g_AllCharacterNames) / sizeof(const char*);
constexpr auto FE_CAR_NAME_LIST_LEN = sizeof(g_FECarNames) / sizeof(FrontEndCharacterName);
constexpr auto FE_CAR_NAME_LIST_OFFSET = 24; // Points to the first non-playable character.

static_assert(FE_CAR_NAME_LIST_OFFSET < FE_CAR_NAME_LIST_LEN, "FrontEnd list offset must be less than the size!");

HOOK_DEFINE_INLINE(PatchAllCharacterNames) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[19] = reinterpret_cast<std::uintptr_t>(&g_AllCharacterNames);
    }
};

HOOK_DEFINE_INLINE(PatchFECarNames10Indirect) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[10] = reinterpret_cast<std::uintptr_t>(&g_FECarNames);
    }
};

HOOK_DEFINE_INLINE(PatchFECarNames26Indirect) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[26] = reinterpret_cast<std::uintptr_t>(&g_FECarNames);
    }
};

HOOK_DEFINE_INLINE(PatchFECarNames8) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[8] = reinterpret_cast<std::uintptr_t>(&g_FECarNames);
    }
};

HOOK_DEFINE_INLINE(PatchFECarNames21) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[21] = reinterpret_cast<std::uintptr_t>(&g_FECarNames);
    }
};

HOOK_DEFINE_INLINE(PatchFECarNames26WithOffset) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[26] = reinterpret_cast<std::uintptr_t>(&g_FECarNames) - 0x680;
    }
};

HOOK_DEFINE_INLINE(PatchFECarNames26) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[26] = reinterpret_cast<std::uintptr_t>(&g_FECarNames);
    }
};

HOOK_DEFINE_INLINE(PatchFECarNames27WithOffset) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        ctx->X[27] = reinterpret_cast<std::uintptr_t>(&g_FECarNames) - 0x680;
    }
};

HOOK_DEFINE_INLINE(MountSDCard) {
    static void Callback(exl::hook::InlineCtx* ctx) {        
        nn::fs::MountSdCardForDebug("sd");
        nn::fs::CreateFile("sd:/cars3/exlaunch.log", 0);
    }
};

void LogStringToFile(std::string_view data) {
    nn::fs::FileHandle handle{};
    if (R_FAILED(nn::fs::OpenFile(&handle, "sd:/cars3/exlaunch.log", nn::fs::OpenMode::OpenMode_ReadWrite))) {
        return;
    }
    long currentSize = 0;
    if (R_FAILED(nn::fs::GetFileSize(&currentSize, handle))) {
        nn::fs::CloseFile(handle);
        return;
    }
    if (R_FAILED(nn::fs::SetFileSize(handle, currentSize + data.size()))) {
        nn::fs::CloseFile(handle);
        return;
    }
    if (R_FAILED(nn::fs::WriteFile(handle, currentSize, data.data(), data.size(), nn::fs::WriteOption::CreateOption(nn::fs::WriteOptionFlag_Flush)))) {
        nn::fs::CloseFile(handle);
        return;
    }
    nn::fs::CloseFile(handle);
}

static const char VERISON[] = "itsmeft24";

HOOK_DEFINE_REPLACE(GetVersionString) {
    static const char* Callback() {
        return VERISON;
    }
};

HOOK_DEFINE_TRAMPOLINE(OpenFile) {
    static bool Callback(void* _this, const char* fileName, int nOpenFlags) {
        char workBuffer[256] = {0};
        std::size_t len = 0;
        for (std::size_t i = 0; i < 256; i++) {
            if (fileName[i] == 0) {
                break;
            }
            workBuffer[i] = fileName[i];
            len++;
        }
        workBuffer[len] = '\n';
        len++;
        LogStringToFile(std::string_view(workBuffer, len));
        return Orig(_this, fileName, nOpenFlags);
    }
};

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking environment. */
    exl::hook::Initialize();

    /* Mounts the SD Card right after `rom:/` is mounted. */
    MountSDCard::InstallAtOffset(0x1eb74);

    /* Patches the version string that appears at the title screen */
    GetVersionString::InstallAtOffset(0x1fcc4);
    
    /* Dumps every file opened to `sd:/cars3/exlaunch.log`. */
    OpenFile::InstallAtOffset(0x6564);
    
    /* Patches the index-offsets used to determine the max character count at the CSS. */
    // 6dc5c4 = cmp x20, #0x17
    exl::patch::CodePatcher countPatcher(0x6dc5c4);
    countPatcher.WriteInst(inst::CmpImmediate(reg::X20, FE_CAR_NAME_LIST_OFFSET));
    countPatcher.Seek(0x67f950);
    countPatcher.WriteInst(inst::CmpImmediate(reg::X24, FE_CAR_NAME_LIST_OFFSET));
    countPatcher.Seek(0x6e31a0);
    countPatcher.WriteInst(inst::Movz(reg::W0, FE_CAR_NAME_LIST_OFFSET * 4));
    countPatcher.Seek(0x6e31fc);
    countPatcher.WriteInst(inst::CmpImmediate(reg::W8, FE_CAR_NAME_LIST_OFFSET));

    /* Unlocks all cars! */
    countPatcher.Seek(0x6dc54c);
    countPatcher.WriteInst(inst::Movz(reg::W8, 0));

    /* Patch various functions to redirect the original game's g_FECarNames list to ours. */
    PatchFECarNames8::InstallAtOffset(0x6dc4d4);
    PatchFECarNames21::InstallAtOffset(0x6e69b8);
    PatchFECarNames26WithOffset::InstallAtOffset(0x6e3354);
    PatchFECarNames26::InstallAtOffset(0x6e3a3c);
    PatchFECarNames27WithOffset::InstallAtOffset(0x6e32bc);
    PatchFECarNames10Indirect::InstallAtOffset(0x894a84);
    PatchFECarNames26Indirect::InstallAtOffset(0x67f8dc);

    /* Patches HUDTauntParams::Setup to consider all of our g_AllCharacterNames entries. */
    exl::patch::CodePatcher patcher(0x005abae8);
    
    // 0x005abae8 = cmp w8, #0x2b
    patcher.Seek(0x005abae8);
    patcher.WriteInst(inst::CmpImmediate(reg::W8, CAR_NAME_LIST_LEN));

    // 0x005abb24 = mov w9, #0x2b
    patcher.Seek(0x005abb24);
    patcher.WriteInst(inst::Movz(reg::W9, CAR_NAME_LIST_LEN));

    // 0x005abb28 = cmp w8, #0x2b
    patcher.Seek(0x005abb28);
    patcher.WriteInst(inst::CmpImmediate(reg::W8, CAR_NAME_LIST_LEN));

    // 0x005abb80 = cmp w9, #0x2a
    patcher.Seek(0x005abb80);
    patcher.WriteInst(inst::CmpImmediate(reg::W9, CAR_NAME_LIST_LEN - 1));

    // 0x005abb88 = mov w8, #0x2b
    patcher.Seek(0x005abb88);
    patcher.WriteInst(inst::Movz(reg::W8, CAR_NAME_LIST_LEN));

    // 0x005abbd0 = cmp w9, #0x2b
    patcher.Seek(0x005abbd0);
    patcher.WriteInst(inst::CmpImmediate(reg::W9, CAR_NAME_LIST_LEN));

    // 0x005abbdc = sub x9, x9, #0x2b
    patcher.Seek(0x005abbdc);
    patcher.WriteInst(inst::SubsImmediate(reg::X9, reg::X9, CAR_NAME_LIST_LEN));

    // 0x005abbf0 = mov w8, #0x2b
    patcher.Seek(0x005abbf0);
    patcher.WriteInst(inst::Movz(reg::W8, CAR_NAME_LIST_LEN));

    // 0x005abc18 = mov w19, #0x2b
    patcher.Seek(0x005abc18);
    patcher.WriteInst(inst::Movz(reg::W19, CAR_NAME_LIST_LEN));

    // 0x005abc20 = mov w8, #0x2b
    patcher.Seek(0x005abc20);
    patcher.WriteInst(inst::Movz(reg::W8, CAR_NAME_LIST_LEN));
    
    /* Patches HUDTauntParams::Setup to use our list instead of the original game's. */
    PatchAllCharacterNames::InstallAtOffset(0x5abc80);
}

extern "C" NORETURN void exl_exception_entry() {
    /* Note: this is only applicable in the context of applets/sysmodules. */
    EXL_ABORT("Default exception handler called!");
}