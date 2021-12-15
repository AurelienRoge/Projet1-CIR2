#include "airport.hpp"

void planeBehaviour(Plane plane, bool &stop_thread);


void planeBehaviour(Plane plane, bool &stop_thread){
    while(!stop_thread){
        std::this_thread::sleep_for(1s);
        if(plane.isTraveling()){
            planeCoordsMutex.lock();
            plane.updateCoordinates();
            planeCoordsMutex.unlock();
            plane.speedController();
            cout << plane.identification << " : " << plane.coordsToString() << endl;

        }
        else{
            cout << "Plane is at destination" << endl;
            this_thread::sleep_for(chrono::seconds(rand()%10));
            cout << "Taking off to new destination" << endl;
            int index = rand()%6;
            plane.updateDestination(airport_List.at(index).coordinates());
            airport_List.at(index).printCoords();
            cout << "New trajectory is :";
            plane.printTrajectory();
        }
    }
}

