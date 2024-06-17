#if defined(_WIN32)
#include <Windows.h>
#if _MSVC_LANG >= 202002L
#include <bit>
#endif  // _MSVC_LANG >= 202002L
#elif !defined(_WIN32) && (defined(__unix__) || defined(__unix))
#include <sched.h>
#endif

#include "getnumproc.hpp"

int getnumproc(void) {
    // get number of avalable cores, this is the only OS dependent code
    // so far.
    int count = 0;
#if !defined(_WIN32) && (defined(__unix__) || defined(__unix))
    cpu_set_t mask;
    if (!sched_getaffinity(0, sizeof(mask), &mask)) count = CPU_COUNT(&mask);
#elif defined(_WIN32)
    DWORD_PTR process, system;
    if (GetProcessAffinityMask(GetCurrentProcess(), &process, &system)) {
#if _MSVC_LANG >= 202002L
        count = std::popcount(system);
#else
        while (system) {
            if (system & 1) count++;
            system >>= 1;
        }
#endif  // _MSVC_LANG >= 202002L
    } else {
        // may be we hav't PROCESS_QUERY_INFORMATION access right
        SYSTEM_INFO sysinfo;
        GetSystemInfo(&sysinfo);
        count = sysinfo.dwNumberOfProcessors;
    }
#endif  // defined(_WIN32)
    return count;
}
