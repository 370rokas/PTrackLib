#ifndef PTRACKLIB_PTRACKLIB_H
#define PTRACKLIB_PTRACKLIB_H

#include <chrono>
#include <vector>

namespace ptrack {
    enum TimeFormat {
        S,      // Seconds
        MS,     // Millisecond
        US,     // Microsecond
        NS      // Nanosecond
    };

    class Tracker {
    protected:
        uint64_t getElapsed(
                ptrack::TimeFormat TFormat,
                std::chrono::time_point<std::chrono::high_resolution_clock> start,
                std::chrono::time_point<std::chrono::high_resolution_clock> end);

        std::chrono::time_point<std::chrono::high_resolution_clock> p_start;
    public:
        /**
         * Restarts the tracker
         */
        virtual void start();

        /**
         * Gets the elapsed time
         * @return Elapsed time in milliseconds (MS)
         */
        uint64_t get();

        /**
         * Gets the elapsed time in a desired time format
         * @param TFormat The desired time format (ptrack::TimeFormat)
         * @return Elapsed time in the desired time format
         */
        uint64_t get(ptrack::TimeFormat TFormat);
    };

    class AccTracker : public Tracker {
    protected:
        std::vector<std::chrono::time_point<std::chrono::high_resolution_clock>> loggedTimes;
    public:
        /**
         * Restarts the tracker, automatically clears all cached times
         */
        void start() override;

        /**
         * Clears all the cached times
         */
        void clearTimes();

        /**
         * Registers a new time
         */
        void log();

        /**
         * Gets the amount of logged times
         * @return Amount of logged times
         */
        inline int timeAmount() { return loggedTimes.size(); };

        /**
         * Gets the last logged time's elapsed time
         * @param TFormat The desired time format (ptrack::TimeFormat)
         * @return Time of the last logged time (from the start)
         */
        uint64_t lastTime(ptrack::TimeFormat TFormat);

        /**
         * Gets the average logged time
         * @param TFormat The desired time format (ptrack::TimeFormat)
         * @return Average logged time
         */
        uint64_t averageTime(ptrack::TimeFormat TFormat);

        /**
         * Gets all the logged times
         * @param TFormat The desired time format (ptrack::TimeFormat)
         * @return A vector containing all the logged times
         */
        std::vector<uint64_t> getAllTimes(ptrack::TimeFormat TFormat);
    };
}



#endif //PTRACKLIB_PTRACKLIB_H
