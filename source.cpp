#include <thread>
#include <iostream>
#include <string>
#include "threads/planeThreadFunction.hpp"

using namespace std;

int main()
{
    //	vector<Plane> planes;
    Airport airport;
    Waiting_planes waiting_planes;
    bool stop_thread = false;



    Plane planeTab[30];//Tableau de 30 avions
    for(int i = 0; i < 30; i++){
        Plane plane;
        plane.identification = "AF" + to_string(101+i);
        waiting_planes.add_a_plane(plane);

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
   for(int i = 0; i  < 1; i++){
        planeThreads.emplace_back(planeBehaviour, ref(planeTab[i]), ref(stop_thread));

    }
    std::thread airport_thread(airport_control, std::ref(airport), std::ref(waiting_planes), std::ref(stop_thread));
    //std::thread planeGlobalThread(planeThreadFunction, std::ref(waiting_planes), std::ref(planeTab), ref(stop_thread));
    //std::thread coordinatesUpdateThread(updatePlanesCoordinates, std::ref(plane_List), std::ref(stop_thread));


    while (1)
    {
        //cout << "Boucle while" << endl;

        string name;
        cin >> name;
        if (name == "0")
        {
            stop_thread = true;
            break;
        }
        Plane plane;
        plane.identification = name;
        waiting_planes.add_a_plane(plane);



    }

    if (airport_thread.joinable())
    {
        airport_thread.join();
    }

    /*if (planeGlobalThread.joinable())
    {
        planeGlobalThread.join();
    }*/

    cout<<airport;

    std::cout << "Finish\n";

    return 0;
}
