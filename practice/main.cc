#include <chrono>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int random_with_rand()
{
    return rand() % 200;
}

int random_with_random_device()
{
    static random_device rd;
    return static_cast<int>(rd() % 200);
}

int random_with_mt19937()
{
    static mt19937 generator(random_device{}());
    static uniform_int_distribution<int> distribution(0, 199);

    return distribution(generator);
}

int random_with_minstd()
{
    static minstd_rand generator(
        static_cast<unsigned int>(
            chrono::steady_clock::now().time_since_epoch().count()));
    static uniform_int_distribution<int> distribution(0, 199);

    return distribution(generator);
}

int random_with_knuth()
{
    static knuth_b generator(random_device{}());
    static uniform_int_distribution<int> distribution(0, 199);

    return distribution(generator);
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<pair<string, function<int()>>> generators = {
        {"rand()", random_with_rand},
        {"random_device", random_with_random_device},
        {"mt19937", random_with_mt19937},
        {"minstd_rand", random_with_minstd},
        {"knuth_b", random_with_knuth},
    };

    cout << "Five random numbers generated in different ways:" << endl;

    for (const auto &generator : generators)
    {
        cout << generator.first << ": " << generator.second() << endl;
    }

    return 0;
}
