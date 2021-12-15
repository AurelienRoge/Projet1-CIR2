#include <thread>
#include <iostream>
#include <string>
#include "threads/planeThreadFunction.hpp"
#include <SFML/Graphics.hpp>


using namespace  sf;
using namespace std;

#ifdef _MSC_VER
#define _PATH_IMG_ "../img/"
#endif



const string path_image(_PATH_IMG_);
Plane planeTab[15];//Tableau de 15 avions

int main()
{
    sf::err().rdbuf(NULL);
    Text text[15];
    Text aure;
    Font font;
    if (!font.loadFromFile("../arial.ttf")) cout<< "erreur police"<<endl;
    text[15].setFont(font);
    text[15].setCharacterSize(48);

    aure.setFont(font);
    aure.setCharacterSize(48);

    bool stop_thread = false;
    RenderWindow app(VideoMode(1002, 1024, 32), "My Camera");


    Sprite backgroundSprite;
    Texture planeImage, backgroundImage;
    backgroundSprite.setScale(sf::Vector2f(1.0, 1.0));
    Sprite PlaneTabSprite[15];

    if (!backgroundImage.loadFromFile(path_image+"background.jpg") ||
        !planeImage.loadFromFile(path_image+"plane.png")) {
        cerr << "Erreur pendant le chargement des images" << endl;
        return EXIT_FAILURE; // On ferme le programme
    }

    backgroundSprite.setTexture(backgroundImage);


    for (int i = 0; i < 15; ++i) {
        PlaneTabSprite[i].setTexture(planeImage);
        PlaneTabSprite[i].setScale(sf::Vector2f(0.008, 0.008));
    }



    for(int i = 0; i < 15; i++){
        Plane plane;
        plane.identification = "AF" + to_string(101+i);
        plane.planeIndex = i;
        planeTab[i] = plane;
        planeTab[i].updateDestination(20,20);
    }

    for (int i = 0; i < 15; ++i) {
        text[i].setString(planeTab[i].identification);
        //text[i].setColor(Color::Green);
    }




    vector <thread> planeThreads;
   for(int i = 0; i  < 15; i++){
        planeThreads.emplace_back(planeBehaviour, ref(planeTab[i]), ref(stop_thread));

    }


   Airport airport(292,651);
   airport.identification = "Paris";
   airport_List.push_back(airport);
   airport_List.at(0).printCoords();

    Airport airport1(169,486);
    airport1.identification = "Dublin";
    airport_List.push_back(airport1);
    airport_List.at(1).printCoords();

    Airport airport2(125,851);
    airport2.identification = "Madrid";
    airport_List.push_back(airport2);
    airport_List.at(2).printCoords();

    Airport airport3(18,880);
    airport3.identification = "Lisbonne";
    airport_List.push_back(airport3);
    airport_List.at(3).printCoords();

    Airport airport4(479,851);
    airport4.identification = "Rome";
    airport_List.push_back(airport4);
    airport_List.at(4).printCoords();

    Airport airport5(474,451);
    airport5.identification = "Copenhague";
    airport_List.push_back(airport5);
    airport_List.at(5).printCoords();

    Airport airport6(539,360);
    airport6.identification = "Stockholm";
    airport_List.push_back(airport6);
    airport_List.at(6).printCoords();

    Airport airport7(559,574);
    airport7.identification = "Varsovie";
    airport_List.push_back(airport7);
    airport_List.at(7).printCoords();

    Airport airport8(494,564);
    airport8.identification = "Berlin";
    airport_List.push_back(airport8);
    airport_List.at(8).printCoords();

    Airport airport9(829,807);
    airport9.identification = "Istanbul";
    airport_List.push_back(airport9);
    airport_List.at(9).printCoords();







    while (app.isOpen()){
        Event event;

        while (app.pollEvent(event))
        {
            if ((event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == Event::Closed)
            {
                app.close();
            }
        }



        app.clear();
        app.draw(backgroundSprite);
        for (int i = 0; i < 15; ++i) {
            text[i].setPosition(200,400);
            PlaneTabSprite[i].setPosition(allPlanesCoordinates[i].getX(),allPlanesCoordinates[i].getY());
            app.draw(PlaneTabSprite[i]);
            app.draw(text[3]);
        }





        app.display();
    }


}
