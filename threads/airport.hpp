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
    Airport(float x, float y){
        coords.setX(x);
        coords.setY(y);
    }
    /*void planesVectorPrint(){
        cout << "Liste avions dans l'aeroport : " << endl;
        for(int i = 0; i < planes.size(); i++){
            cout << i << ": " << planes.at(i) << endl;

        }
    }*/
    void printCoords(){
        cout << identification << " X : " << coords.getX() << " Y : " << coords.getY() << endl;
    }
    coordinatesXY coordinates(){
        return coords;
    }
    friend ostream &operator<<(ostream &os, const Airport &airport);
};
vector <Airport> airport_List;

ostream &operator<<(ostream &os, const Airport &airport)
{
    os << "Available planes\n";
    for (auto &plane : airport.planes)
    {
        os << plane.identification << endl;
    }
    return os;
}




