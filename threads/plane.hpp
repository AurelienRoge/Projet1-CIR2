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
#include "../tools/trajectory.h++"


using namespace std;
mutex waiting_planes_mutex;

struct Plane
{
    string identification;
private:
    coordinatesXY coords;
    coordinatesXY destination;
    float speed = 10;
    trajectory trajectoire;
public:
    string coordsToString();
    void updateDestination(coordinatesXY newDestination);
    void updateDestination(float X, float Y);
    void printTrajectory(){
        trajectoire.printTrajectory();
    }
    void updateCoordinates();

    friend ostream &operator<<(ostream &os, const Plane &plane);
};

ostream &operator<<(ostream &os, const Plane &plane){
    os << "Plane " << plane.identification << " at coordinates :" << "X : " << plane.coords.getX()<< " Y :" << plane.coords.getY();

    return os;
}

void Plane::updateDestination(coordinatesXY newDestination) {
    destination = newDestination;
    trajectoire.calculateTrajectory(coords,destination);
}

void Plane::updateDestination(float X, float Y) {
    coordinatesXY tmp(X,Y);
    destination = tmp;
    trajectoire.calculateTrajectory(coords,destination);
}

void Plane::updateCoordinates() {
    float newX = speed*trajectoire.getCoeffX();
    float newY = speed*trajectoire.getCoeffY();
    coords.setX(newX);
    coords.setY(newY);
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
private:
    int size;
public:
    vector<Plane> list;
    void newPlaneInList(Plane plane){
        list.push_back(plane);
    }
    void printList(){
        cout << "planeListPrint :" << endl;
        for (int i = 0; i < list.size(); i++) {
            cout << i << ":" << list.at(i) << endl;
        }
    }
    int getSize(){
        return list.size();
    }
};

Plane add_plane_sometimes(Waiting_planes &waiting_planes,planeList &plane_List)
{
    Plane plane;
    plane.identification = "AF" + to_string(rand()%1000 + 100);
    waiting_planes.add_a_plane(plane);
    plane_List.newPlaneInList(plane);
    //plane_List.printList();
    return plane;
}

void updatePlanesCoordinates(planeList list, bool &stop_thread){
    while(!stop_thread){
        std::this_thread::sleep_for(2s);
        if(!stop_thread) {
            cout << "List size : " << list.list.size() << endl;
            for (int i = 0; i < list.getSize(); i++) {
                list.list.at(i).updateDestination(100,100);
                list.list.at(i).updateCoordinates();
            }
        }

    }
}

void placeMovement(){

}

