#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <string>
#include <optional>
#include "plane.hpp"

using namespace std;
std::mutex airport_mutex;

class Airport
{
    vector<Plane> planes;
    coordinatesXY coords;


public:
    string identification;
    Airport(){
        coords.setX(rand()%501);
        coords.setY(rand()%501);
    }
    void add_a_plane(Plane &plane)
    {
        airport_mutex.lock();
        planes.push_back(plane);
        airport_mutex.unlock();
    }
    void planesVectorPrint(){
        cout << "Liste avions dans l'aeroport : " << endl;
        for(int i = 0; i < planes.size(); i++){
            cout << i << ": " << planes.at(i) << endl;

        }
    }
    void printCoords(){
        cout << identification << " X : " << coords.getX() << " Y : " << coords.getY() << endl;
    }
    coordinatesXY coordinates(){
        return coords;
    }
    friend ostream &operator<<(ostream &os, const Airport &airport);
};

ostream &operator<<(ostream &os, const Airport &airport)
{
    os << "Available planes\n";
    for (auto &plane : airport.planes)
    {
        os << plane.identification << endl;
    }
    return os;
}

void airport_control(Airport &airport, Waiting_planes &waiting_planes, bool &stop_thread)
{
    while (!stop_thread)
    {
        while (waiting_planes.is_a_plane_available())
        {
            if (auto plane = waiting_planes.get_a_plane())
            {
                cout << "Add a plane " << plane.value().identification << endl;
                airport.add_a_plane(*plane);
                //airport.planesVectorPrint();
            }
        }
    }
}

class airportList{
    vector<Airport> list;
public:
    void newAirportInList(Airport airport){
        list.push_back(airport);
    }
    void printList(){
        for (int i = 0; i < list.size(); i++) {
            cout << list.at(i);
        }
    }
    coordinatesXY AiportAtIndexCoords(int index);
    void AiportAtIndexPrintCoords(int index);
    Airport getAirportAtIndex(int index){
        return list.at(index);
    }
};

coordinatesXY airportList::AiportAtIndexCoords(int index) {
    return list.at(index).coordinates();
}

void airportList::AiportAtIndexPrintCoords(int index){
    list.at(index).printCoords();
}

