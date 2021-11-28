#include <thread>
#include <iostream>
#include <string>
#include "threads/airport.hpp"

using namespace std;

int main()
{
    //	vector<Plane> planes;
    Airport airport;
    Waiting_planes waiting_planes;
    planeList plane_List;
    bool stop_thread = false;
    std::thread airport_thread(airport_control, std::ref(airport), std::ref(waiting_planes), std::ref(stop_thread));
    std::thread add_plane(add_plane_sometimes, std::ref(waiting_planes), std::ref(plane_List), ref(stop_thread));
    cout << "Test test test1" << endl;
    while (1)
    {

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
