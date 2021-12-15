#include <thread>
#include <iostream>
#include <string>
#include "threads/planeThreadFunction.hpp"

using namespace std;

Plane planeTab[30];//Tableau de 30 avions

int main()
{
    Airport airport;
    bool stop_thread = false;



    for(int i = 0; i < 30; i++){
        Plane plane;
        plane.identification = "AF" + to_string(101+i);
        plane.planeIndex = i;
        planeTab[i] = plane;
        planeTab[i].updateDestination(20,20);
    }


    for(int i = 0; i < 6; i++){
        Airport airport;
        airport.identification = "Airport " + to_string(i+1);
        airport_List.push_back(airport);
        airport_List.at(i).printCoords();
    }

    vector <thread> planeThreads;
   for(int i = 0; i  < 2; i++){
        planeThreads.emplace_back(planeBehaviour, ref(planeTab[i]), ref(stop_thread));

    }

    while (1)
    {

        cout << "\n====GLOBAL AF101 X : " << allPlanesCoordinates[0].getX() << endl;




    }


}
