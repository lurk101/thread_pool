#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

#include <unistd.h>

#include "ctpl.h"

using namespace std;
using namespace ctpl;

static void thrd(int id, int D) { this_thread::sleep_for(chrono::seconds(3)); }

int main() {
    cpu_set_t mask;
    sched_getaffinity(0, sizeof(cpu_set_t), &mask);
    thread_pool pool(CPU_COUNT(&mask));
    cout << "running with " << CPU_COUNT(&mask) << " threads" << endl;
    for (int D = 1; D <= 25; D++)
        pool.push(thrd, D);
}
