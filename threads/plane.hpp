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
    float speed = 10;
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
    if((coords.getX() < destination.getX() - 10 || coords.getX() > destination.getX() + 10) && (coords.getY() < destination.getY() - 10 || coords.getY() > destination.getY() + 10)){
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
    if(coords.distanceFrom(destination) > 250){
        if(speed < 90){
            speed += 20;
        }
    }
    else if(coords.distanceFrom(destination) > 160){
        if (speed > 80){
            speed -= 20;
        }
        else{
            speed += 15;
        }
    }
    else if((coords.distanceFrom(destination) < 105) && speed > 30){
        speed -= 25;
    }
    else if(coords.distanceFrom(destination) < 5){
        speed = 1;
    }
    else{
        speed = 10;
    }
}

bool Plane::isTraveling(){
    return !atDestination;
}



