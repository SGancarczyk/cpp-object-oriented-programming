// This program requires cpp 11+ version
#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class Timer {
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::time_point<clock> time_point;

    std::string label;
    time_point start_time;
    bool running = false;
    std::chrono::duration<double> current_elapsed;
    std::vector<double> results;

public:
    Timer(const std::string& name = "") : label(name), current_elapsed(std::chrono::duration<double>::zero()) {}

    // Start timing
    void start() {
        if (!running) {
            start_time = clock::now();
            running = true;
        }
    }

    // Stop timing and store result
    void stop() {
        if (running) {
            auto end_time = clock::now();
            current_elapsed = end_time - start_time;
            results.push_back(current_elapsed.count());
            running = false;
        }
    }

    // Reset current elapsed time and stop the timer
    void reset() {
        current_elapsed = std::chrono::duration<double>::zero();
        running = false;
    }

    // Access to all recorded results
    const std::vector<double>& getResults() const {
        return results;
    }


    ~Timer() {
        if (running) stop();

        if (!results.empty()) {
            std::cout << "\n[" << (label.empty() ? "Timer" : label) << "] - Measurement history:\n"; // If label is empty(default) cout will be Timer, otherwise print label
            for (size_t i = 0; i < results.size(); ++i) {
                std::cout << "  #" << i + 1 << ": " << std::fixed << std::setprecision(4)
                          << results[i] << " [s]\n";
            }
        } else {
            std::cout << "[" << (label.empty() ? "Timer" : label) << "] - No measurements recorded.\n"; // If measurement never started
        }
    }
};

int main() {
    // Timer 1: Measures a loop simulation
    Timer loopTimer("Loop Delay");

    for (int i = 0; i < 3; ++i) {
        loopTimer.start();

        // Simulate workload
        for (volatile int j = 0; j < 80000000 + i * 10000000; ++j); // slightly increasing delay

        loopTimer.stop();
    }

    // Timer 2: No label (defaults to "Timer")
    Timer unnamedTimer;

    unnamedTimer.start();
    for (volatile int k = 0; k < 50000000; ++k);
    unnamedTimer.stop();

    // Results will be automatically printed for both timers when they go out of scope - destructor initalization( in reversed order )
    return 0;
}