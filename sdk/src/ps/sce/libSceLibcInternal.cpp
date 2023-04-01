#if (defined(PS4) && PS4) || (defined(PS5) && PS5)
#include <ps/sce/libkernel.hpp>
#include <ps/sce/sce.hpp>
#include <ps2/ps2.hpp>
#include <ps/sce/libSceLibcInternal.hpp>

bool PS::Sce::LibcInternal::isInitialized = false;
int PS::Sce::LibcInternal::libcInternal = 1;

uint64_t PS::Sce::LibcInternal::pmemset_s = 0;
uint64_t PS::Sce::LibcInternal::pmemcpy = 0;

int PS::Sce::LibcInternal::Initialize()
{
    if (PS::Sce::LibcInternal::isInitialized)
        return true;
    // Load libSceLibcInternal
    PS::Sce::LibcInternal::libcInternal = PS::Sce::Kernel::LoadStartModule("libSceLibcInternal.sprx", 0, NULL, 0, 0, 0);
    if (PS::Sce::LibcInternal::libcInternal < 0)
        return false;
    #if (defined(PS4) && PS4) || (defined(PS5) && PS5) 
    PS::Sce::Kernel::Dlsym(libcInternal, "memset_s", &pmemset_s);
    PS::Sce::Kernel::Dlsym(libcInternal, "memcpy", &pmemcpy);
    #endif

    PS::Sce::LibcInternal::isInitialized = true;
    return true;
}

uint32_t PS::Sce::LibcInternal::Memset_s(void *s, rsize_t smax, int c, rsize_t n)
{
    return (uint32_t)PS::Breakout::call(PS::Sce::LibcInternal::pmemset_s, PVAR_TO_NATIVE(s), smax, c, n);
}
uint32_t PS::Sce::LibcInternal::Memcpy(const void *s1, const void *s2, size_t n)
{
    return (uint32_t)PS::Breakout::call(PS::Sce::LibcInternal::pmemcpy, PVAR_TO_NATIVE(s1), PVAR_TO_NATIVE(s2), n);
}
#endif