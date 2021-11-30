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
    planeList plane_List;
    bool stop_thread = false;
    std::thread airport_thread(airport_control, std::ref(airport), std::ref(waiting_planes), std::ref(stop_thread));
    std::thread add_plane(planeThreadFunction, std::ref(waiting_planes), std::ref(plane_List), ref(stop_thread));
    //std::thread coordinatesUpdateThread(updatePlanesCoordinates, std::ref(plane_List), std::ref(stop_thread));
    Plane testPlane;
    testPlane.identification = "TestPlane";
    testPlane.updateDestination(100,10);
    testPlane.printTrajectory();
    cout << "New coords :" << testPlane.coordsToString();
    plane_List.newPlaneInList(testPlane);
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

    if (add_plane.joinable())
    {
        add_plane.join();
    }

    cout<<airport;

    std::cout << "Finish\n";

    return 0;
}
