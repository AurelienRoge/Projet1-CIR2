#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <string>
#include <optional>


using namespace std;
mutex waiting_planes_mutex;

struct Plane
{
    string identification;
};

class Waiting_planes
{
    queue<Plane> planes;

public:
    void add_a_plane(Plane &plane)
    {
        waiting_planes_mutex.lock();
        planes.push(plane);
        waiting_planes_mutex.unlock();
    }
    bool is_a_plane_available()
    {
        return !(planes.empty());
    }
    optional<Plane> get_a_plane()
    {
        if (is_a_plane_available())
        {
            waiting_planes_mutex.lock();
            auto plane = planes.front();
            planes.pop();
            waiting_planes_mutex.unlock();
            return plane;
        }
        return nullopt;
    }
};

void add_plane_sometimes(Waiting_planes &waiting_planes, bool &stop_thread)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(100, 800);
    while (!stop_thread)
    {
        std::this_thread::sleep_for(3s);
        Plane plane;
        plane.identification = "AF" + to_string(distribution(generator));
        waiting_planes.add_a_plane(plane);
    }
}