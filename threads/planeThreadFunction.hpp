#include "airport.hpp"

void planeBehaviour(Plane plane, bool &stop_thread);


void planeBehaviour(Plane plane, bool &stop_thread){
    while(!stop_thread){
        std::this_thread::sleep_for(0.016s);
        if(plane.isTraveling()){
            planeCoordsMutex.lock();
            plane.updateCoordinates();
            planeCoordsMutex.unlock();
            plane.speedController();
            cout << plane.identification << " Speed : " << to_string(plane.getSpeed()) << endl;

        }
        else{
            cout << "Plane is at destination" << endl;
            this_thread::sleep_for(chrono::seconds(2s));
            cout << "Taking off to new destination" << endl;
            srand((plane.planeIndex + 1)*time(NULL));
            cout << "seed:" << plane.planeIndex*rand() << endl;
            int index = rand()%10;
            plane.updateDestination(airport_List.at(index).coordinates());
            airport_List.at(index).printCoords();
            cout << "New trajectory is :";
            plane.printTrajectory();
        }
    }
}

