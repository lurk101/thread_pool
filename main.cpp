#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#include <unistd.h>
#endif

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

static void thrd(int id, int t) {
    this_thread::sleep_for(chrono::seconds(3));
    mtx.lock();
    cout << t << endl;
    mtx.unlock();
}

int main() {
    thread_pool pool;
    cout << "running on " << pool.size() << " threads" << endl;
    for (int t = 1; t <= 25; t++) pool.push(thrd, t);
}
