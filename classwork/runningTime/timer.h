//
// Created by David on 2/15/24.
//
#include <chrono>

template<typename Units>
class timer {
public:
    void start();

    void end();

    typename Units::rep count() const;

private:
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::duration diff{};
};

template<typename Units>
void timer<Units>::start() {
    start_time = std::chrono::steady_clock::now();

}

template<typename Units>
void timer<Units>::end() {
    diff = std::chrono::steady_clock::now() - start_time;
}

template<typename Units>
typename Units::rep timer<Units>::count() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
}