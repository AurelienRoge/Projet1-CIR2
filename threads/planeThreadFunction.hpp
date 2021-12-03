#include "airport.hpp"

void planeBehaviour(Plane plane, bool &stop_thread);

void planeThreadFunction(Waiting_planes &waiting_planes,Plane* planeTab, bool &stop_thread){

    while (!stop_thread){

        std::this_thread::sleep_for(1s);
        for(int i = 0; i < 3; i++){//Pour le moment j'affiche que les 3 premiers pour faire mes tests
            if (i == 2){
                planeTab[i].updateSpeed(1);
            }
            planeTab[i].updateCoordinates();
            cout << i << " : " << planeTab[i].identification << " : " << planeTab[i].coordsToString() << endl;
        }
    }
}

void planeBehaviour(Plane plane, bool &stop_thread){
    while(!stop_thread){
        std::this_thread::sleep_for(1s);
        if(plane.isTraveling()){
            plane.updateCoordinates();
            cout << plane.identification << " : " << plane.coordsToString() << endl;

        }
        else{
            cout << "Plane is at destination" << endl;
            this_thread::sleep_for(chrono::seconds(rand()%10));
            cout << "Taking off to new destination" << endl;
            int index = rand()%7;
            plane.updateDestination(airport_List.at(index).coordinates());
            airport_List.at(index).printCoords();
            cout << "New trajectory is :";
            plane.printTrajectory();
        }
    }
}

