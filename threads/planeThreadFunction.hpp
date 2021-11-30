#include "airport.hpp"
bool planesGenerated = false;//Garde en mémoire si on a déjà généré nos avions
void planeThreadFunction(Waiting_planes &waiting_planes,planeList &plane_List, bool &stop_thread){

    Plane planeTab[30];//Tableau de 30 avions
    if (planesGenerated == false){
        for(int i = 0; i < 30; i++){
            Plane plane;
            plane.identification = "AF" + to_string(101+i);

            waiting_planes.add_a_plane(plane);
            plane_List.newPlaneInList(plane);//Useless?

            planeTab[i] = plane;
            planeTab[i].updateDestination(20,20);
            planesGenerated = true;
        }
    }

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