#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <string>
#include <optional>
#include <cstdio>
#include <cstdlib>
#include "./tools/coordinatesXY.hpp"


using namespace std;
mutex waiting_planes_mutex;

struct Plane
{
    string identification;
private:
    coordinatesXY coords;
public:
    string coordsToString();

    friend ostream &operator<<(ostream &os, const Plane &plane);
};

ostream &operator<<(ostream &os, const Plane &plane){
    os << "Plane " << plane.identification << "at coordinates :" << "X : " << plane.coords.getX()<< " Y :" << plane.coords.getY();

    return os;
}

string Plane::coordsToString() {
    string s = "X : " + to_string(coords.getX()) + " Y :" + to_string(coords.getY());
    return s;
}
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

class planeList{
    vector<Plane> list;
public:
    void newPlaneInList(Plane plane){
        list.push_back(plane);
    }
    void printList(){
        for (int i = 0; i < list.size(); i++) {
            cout << list.at(i);
        }
    }
};

void add_plane_sometimes(Waiting_planes &waiting_planes,planeList &plane_List, bool &stop_thread)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(100, 800);
    while (!stop_thread)
    {
        std::this_thread::sleep_for(3s);
        Plane plane;
        plane.identification = "AF" + to_string(distribution(generator))+ " coordinates " + plane.coordsToString();
        waiting_planes.add_a_plane(plane);
        plane_List.newPlaneInList(plane);
    }
}

