#include <gtest/gtest.h>
#include <ptracklib.h>

long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void wait() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

TEST(Trackers, Basic) {
    ASSERT_NO_THROW({
        ptrack::Tracker Tracker;

        wait();

        ASSERT_GT(Tracker.get(), 0);
        ASSERT_GT(Tracker.get(ptrack::TimeFormat::NS), 0);
    });
}

TEST(Trackers, Accumulating) {
    ptrack::AccTracker Tracker;

    for (int i = 0; i < 2; i++) {
        wait();
        Tracker.log();
    }

    ASSERT_EQ(Tracker.timeAmount(), 2);
    ASSERT_GT(Tracker.lastTime(ptrack::TimeFormat::MS), 0);
    Tracker.clearTimes();

    for (int i = 0; i < 3; i++) {
        wait();
        Tracker.log();
    }

    ASSERT_GT(Tracker.averageTime(ptrack::TimeFormat::MS), 0);
    ASSERT_GT(Tracker.getAllTimes(ptrack::TimeFormat::MS).size(), 0);

    Tracker.start();
    for (int i = 0; i < 2; i++) {
        wait();
        Tracker.log();
    }

    ASSERT_EQ(Tracker.timeAmount(), 2);
}