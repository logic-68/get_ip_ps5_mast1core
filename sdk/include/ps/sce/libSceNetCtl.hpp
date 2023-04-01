#pragma once

#if (defined(PS4) && PS4) || (defined(PS5) && PS5)
#include <types.hpp>
#include <ps/syscall/socket.hpp>
#include <ps/sce/libkernel.hpp>

namespace PS
{
    namespace Sce
    {
        class LibSceNetCtl
        {
        public:
            static int Initialize();
            static uint32_t NetCtlInit();
            static uint32_t NetCtlTerm();
            static uint32_t NetCtlGetInfo(int code, SceNetCtlInfo *info);
        private:
            static bool isInitialized;
            static int libSceNetCtl;
            static uint64_t psceNetCtlInit;
            static uint64_t psceNetCtlTerm;
            static uint64_t psceNetCtlGetInfo;
        };
    }
}
#endif