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
    bool atDestination = true;
    trajectory trajectoire;
public:
    string coordsToString();
    void updateDestination(coordinatesXY newDestination);
    void updateDestination(float X, float Y);
    void printTrajectory(){
        trajectoire.printTrajectory();
    }
    void updateSpeed(float newSpeed);
    void updateCoordinates();
    bool isTraveling();

    friend ostream &operator<<(ostream &os, const Plane &plane);
};

ostream &operator<<(ostream &os, const Plane &plane){
    os << "Plane " << plane.identification << " at coordinates :" << "X : " << plane.coords.getX()<< " Y :" << plane.coords.getY();

    return os;
}

void Plane::updateDestination(coordinatesXY newDestination) {

    atDestination = false;
    destination = newDestination;
    trajectoire.calculateTrajectory(coords,destination);
}

void Plane::updateDestination(float X, float Y) {

    atDestination = false;
    coordinatesXY tmp(X,Y);
    trajectoire.calculateTrajectory(coords,tmp);
    destination = tmp;
}

void Plane::updateCoordinates() {
    if((coords.getX() != destination.getX()) && (coords.getY() != destination.getY())){
        float newX = this->coords.getX() + speed * trajectoire.getCoeffX();
        float newY = this->coords.getY() + speed * trajectoire.getCoeffY();
        coords.setX(newX);
        coords.setY(newY);
    }
    else{
        atDestination = true;
    }
}

string Plane::coordsToString() {
    string s = "X : " + to_string(coords.getX()) + " Y :" + to_string(coords.getY());
    return s;
}

void Plane::updateSpeed(float newSpeed) {
    speed = newSpeed;
}

bool Plane::isTraveling(){
    return !atDestination;
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


/*Plane add_plane_sometimes(Waiting_planes &waiting_planes,Plane* &plane_List)
{
    Plane plane;
    plane.identification = "AF" + to_string(rand()%1000 + 100);
    waiting_planes.add_a_plane(plane);
    plane_List.newPlaneInList(plane);
    //plane_List.printList();
    return plane;
}

void updatePlanesCoordinates(Plane* list, bool &stop_thread){
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

void planeMovement(){

}*/

