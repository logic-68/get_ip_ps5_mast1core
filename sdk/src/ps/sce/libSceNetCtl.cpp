#if (defined(PS4) && PS4) || (defined(PS5) && PS5)
#include <ps/sce/libkernel.hpp>
#include <ps/sce/sce.hpp>
#include <ps2/ps2.hpp>
#include <ps/sce/libSceNetCtl.hpp>

bool PS::Sce::LibSceNetCtl::isInitialized = false;
int PS::Sce::LibSceNetCtl::libSceNetCtl = 1;

uint64_t PS::Sce::LibSceNetCtl::psceNetCtlInit = 0;
uint64_t PS::Sce::LibSceNetCtl::psceNetCtlTerm = 0;
uint64_t PS::Sce::LibSceNetCtl::psceNetCtlGetInfo = 0;

int PS::Sce::LibSceNetCtl::Initialize()
{
    if (PS::Sce::LibSceNetCtl::isInitialized)
        return true;
    // Load LibSceNetCtl
    PS::Sce::LibSceNetCtl::libSceNetCtl = PS::Sce::Kernel::LoadStartModule("libSceNetCtl.sprx", 0, NULL, 0, 0, 0);
    if (PS::Sce::LibSceNetCtl::libSceNetCtl < 0)
        return false;
#if (defined(PS4) && PS4) || (defined(PS5) && PS5)
    PS::Sce::Kernel::Dlsym(libSceNetCtl, "sceNetCtlInit", &psceNetCtlInit);
    PS::Sce::Kernel::Dlsym(libSceNetCtl, "sceNetCtlTerm", &psceNetCtlTerm);
    PS::Sce::Kernel::Dlsym(libSceNetCtl, "sceNetCtlGetInfo", &psceNetCtlGetInfo);
#endif
    PS::Sce::LibSceNetCtl::isInitialized = true;
    return true;
}

uint32_t PS::Sce::LibSceNetCtl::NetCtlInit(void)
{
    return (uint32_t) PS::Breakout::call(PS::Sce::LibSceNetCtl::psceNetCtlInit);
}
uint32_t PS::Sce::LibSceNetCtl::NetCtlTerm(void)
{
    return (uint32_t) PS::Breakout::call(PS::Sce::LibSceNetCtl::psceNetCtlTerm);
}
uint32_t PS::Sce::LibSceNetCtl::NetCtlGetInfo(int code, SceNetCtlInfo *info)
{
    return (uint32_t) PS::Breakout::call(PS::Sce::LibSceNetCtl::psceNetCtlGetInfo, code, PVAR_TO_NATIVE(info));
}
#endif