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
mutex planeCoordsMutex;

coordinatesXY allPlanesCoordinates[30];
class Plane
{

private:
    coordinatesXY coords;
    coordinatesXY destination;
    float speed = 0.1;
    bool atDestination = true;
    trajectory trajectoire;
public:
    int planeIndex = 0;
    string identification;
    string coordsToString();
    void updateDestination(coordinatesXY newDestination);
    void updateDestination(float X, float Y);
    void printTrajectory(){
        trajectoire.printTrajectory();
    }
    void speedController();
    void updateCoordinates();
    bool isTraveling();
    float getSpeed(){
        return speed;
    }


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
    //On vérifie que l'avion n'est pas déjà à destination (avec une petite marge d'erreur)
    if((coords.getX() < destination.getX() - 1 || coords.getX() > destination.getX() + 1) && (coords.getY() < destination.getY() - 1 || coords.getY() > destination.getY() + 1)){
        float newX = this->coords.getX() + speed * trajectoire.getCoeffX();
        float newY = this->coords.getY() + speed * trajectoire.getCoeffY();
        coords.setX(newX);
        coords.setY(newY);
        allPlanesCoordinates[planeIndex] = coords;
    }
    else{
        atDestination = true;
        speed = 0;
    }
}

string Plane::coordsToString() {
    string s = "X : " + to_string(coords.getX()) + " Y :" + to_string(coords.getY());
    return s;
}

void Plane::speedController() {
    if(coords.distanceFrom(destination) > 3.5){
        if(speed < 1){
            speed += 0.2;
        }
    }
    else if(coords.distanceFrom(destination) > 3.5){
        if (speed > 1){
            speed -= 0.2;
        }
        else{
            speed += 0.1;
        }
    }
    else if((coords.distanceFrom(destination) < 1.05) && speed > 1){
        speed -= 0.1;
    }
    else if(coords.distanceFrom(destination) < 0.5){
        speed = 0.1;
    }
    else{
        speed = 0.1;
    }
}

bool Plane::isTraveling(){
    return !atDestination;
}



