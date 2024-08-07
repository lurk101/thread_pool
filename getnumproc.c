// get number of avalable cores, this is the only OS dependent code
// so far.

#if defined(_WIN32)

#include "getnumproc.h"

#include <Windows.h>

int getnumproc(void) {
    // get number of avalable cores, this is the only OS dependent code
    // so far.
    DWORD_PTR process, system;
    int count;
    if (GetProcessAffinityMask(GetCurrentProcess(), &process, &system)) {
        for (count = 0; system; system >>= 1)
            if (system & 1) count++;
    } else {
        // maybe we havn't PROCESS_QUERY_INFORMATION access right
        SYSTEM_INFO sysinfo;
        GetSystemInfo(&sysinfo);
        count = sysinfo.dwNumberOfProcessors;
    }
    return count;
}

#elif defined(__GNUC__)

#if !defined(_GNU_SOURCE)
#define _GNU_SOURCE
#endif
#include <sched.h>

#include "getnumproc.h"

int getnumproc(void) {
    cpu_set_t mask;
    if (!sched_getaffinity(0, sizeof(mask), &mask)) return CPU_COUNT(&mask);
    return 1;
}

#endif
