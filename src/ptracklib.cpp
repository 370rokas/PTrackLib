#include "../include/ptracklib.h"

void ptrack::Tracker::start() {
    p_start = std::chrono::high_resolution_clock::now();
}

uint64_t ptrack::Tracker::getElapsed(ptrack::TimeFormat TFormat,
                                     std::chrono::time_point<std::chrono::high_resolution_clock> start,
                                     std::chrono::time_point<std::chrono::high_resolution_clock> end) {

    auto elapsedTime = end - start;
    uint64_t elapsedNs = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsedTime).count();

    switch(TFormat){
        case TimeFormat::NS:
        {
            return elapsedNs;
        }
        case TimeFormat::US:
        {
            return elapsedNs / 1000;
        }
        case TimeFormat::MS:
        {
            return elapsedNs / 1000000;
        }
        case TimeFormat::S:
        {
            return elapsedNs / 1000000000;
        }
    }
}

uint64_t ptrack::Tracker::get(ptrack::TimeFormat TFormat) {
    return getElapsed(TFormat, p_start, std::chrono::high_resolution_clock::now());
}

uint64_t ptrack::Tracker::get() {
    return getElapsed(TimeFormat::MS, p_start, std::chrono::high_resolution_clock::now());
}

void ptrack::AccTracker::start() {
    p_start = std::chrono::high_resolution_clock::now();
    clearTimes();
}

void ptrack::AccTracker::clearTimes() {
    loggedTimes.clear();
}

uint64_t ptrack::AccTracker::lastTime(ptrack::TimeFormat TFormat) {
    return getElapsed(TFormat, p_start, loggedTimes.back());
}

uint64_t ptrack::AccTracker::averageTime(ptrack::TimeFormat TFormat) {
    uint64_t sum = 0;
    int amount = 0;

    for (auto it = loggedTimes.begin(); it != loggedTimes.end(); it++) {
        sum += getElapsed(TFormat, p_start, *it);
        amount++;
    }

    return sum / amount;
}

std::vector<uint64_t> ptrack::AccTracker::getAllTimes(ptrack::TimeFormat TFormat) {
    std::vector<uint64_t> results;

    for (auto it = loggedTimes.begin(); it != loggedTimes.end(); it++) {
        results.push_back(getElapsed(TFormat, p_start, *it));
    }

    return results;
}

void ptrack::AccTracker::log() {
    loggedTimes.push_back(std::chrono::high_resolution_clock::now());
}


