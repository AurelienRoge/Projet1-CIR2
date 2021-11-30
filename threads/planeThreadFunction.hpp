#include "airport.hpp"

void planeThreadFunction(Waiting_planes &waiting_planes,planeList &plane_List, bool &stop_thread){
    while (!stop_thread)
    {
        Plane plane;
        bool planeGenerated = false;
        std::this_thread::sleep_for(2s);
        if (rand()%100 < 50){
            plane = add_plane_sometimes(waiting_planes,plane_List);
            planeGenerated = true;
        }
        else{
            cout << "Plane not generated" << endl;
        }
        if(planeGenerated) {
            cout << plane.coordsToString() << endl;
            plane.updateDestination(100, 100);
            plane.updateCoordinates();
            cout << plane.coordsToString() << endl;
        }
    }
}