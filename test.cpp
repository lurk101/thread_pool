#include <unistd.h>

#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>

#include "ctpl.h"

using namespace std;
using namespace ctpl;

static mutex mtx;

static void thrd(int id, int D) {
    this_thread::sleep_for(chrono::seconds(3));
    mtx.lock();
    cout << D << endl;
    mtx.unlock();
}

int main() {
    cpu_set_t mask;
    sched_getaffinity(0, sizeof(cpu_set_t), &mask);
    thread_pool pool(CPU_COUNT(&mask));
    cout << "running with " << CPU_COUNT(&mask) << " threads" << endl;
    for (int D = 1; D <= 25; D++)
        pool.push(thrd, D);
}
