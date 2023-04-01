#pragma once

#if (defined(PS4) && PS4) || (defined(PS5) && PS5)
#include <types.hpp>
#include <ps/sce/libkernel.hpp>
namespace PS
{
    namespace Sce
    {
        class LibcInternal
        {
        public:
            static int Initialize();
            static uint32_t Memset_s(void *s, rsize_t smax, int c, rsize_t n);
            static uint32_t Memcpy(const void *s1, const void *s2, size_t n);
        private:
            static bool isInitialized;
            static int libcInternal;
            static uint64_t pmemset_s;
            static uint64_t pmemcpy;
        };
    }
}

#endif