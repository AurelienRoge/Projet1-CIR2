#include <thread>
#include <iostream>
#include <string>
#include "threads/planeThreadFunction.hpp"
#include <SFML/Graphics.hpp>


using namespace  sf;
using namespace std;

#ifdef _MSC_VER
#define _PATH_IMG_ "../../../../../img/"
#else
#define _PATH_IMG_ "../img/"
#endif



const string path_image(_PATH_IMG_);
Plane planeTab[15];//Tableau de 15 avions

int main()
{
    Text Aeroport, Aeroport1, Aeroport2, Aeroport3, Aeroport4, Aeroport5, Aeroport6, Aeroport7, Aeroport8, Aeroport9;

    Font font;
    if (!font.loadFromFile("../arial.ttf")) cout<< "erreur police"<<endl;
    Aeroport.setFont(font);
    Aeroport.setCharacterSize(20);
    Aeroport1.setFont(font);
    Aeroport1.setCharacterSize(20);
    Aeroport2.setFont(font);
    Aeroport2.setCharacterSize(20);
    Aeroport3.setFont(font);
    Aeroport3.setCharacterSize(20);
    Aeroport4.setFont(font);
    Aeroport4.setCharacterSize(20);
    Aeroport5.setFont(font);
    Aeroport5.setCharacterSize(20);
    Aeroport6.setFont(font);
    Aeroport6.setCharacterSize(20);
    Aeroport7.setFont(font);
    Aeroport7.setCharacterSize(20);
    Aeroport8.setFont(font);
    Aeroport8.setCharacterSize(20);
    Aeroport9.setFont(font);
    Aeroport9.setCharacterSize(20);


    bool stop_thread = false;
    RenderWindow app(VideoMode(1002, 1024, 32), "Air traffic simulation - Aurelien Roge et Guillaume Leroy");


    Sprite backgroundSprite, Airport_logoSprite[10];
    Texture planeImage, backgroundImage, Airport_logoImage;
    backgroundSprite.setScale(sf::Vector2f(1.0, 1.0));
    Sprite PlaneTabSprite[15];




    if (!backgroundImage.loadFromFile(path_image+"background.jpg") ||
        !planeImage.loadFromFile(path_image+"plane.png")||!Airport_logoImage.loadFromFile(path_image+"airport_logo.png")) {
        cerr << "Erreur pendant le chargement des images" << endl;
        return EXIT_FAILURE; // On ferme le programme
    }

    backgroundSprite.setTexture(backgroundImage);

    for (int i = 0; i < 10; ++i) {
        Airport_logoSprite[i].setTexture(Airport_logoImage);
        Airport_logoSprite[i].setScale(sf::Vector2f(0.008,0.008));
    }


    for (int i = 0; i < 15; ++i) {
        PlaneTabSprite[i].setTexture(planeImage);
        PlaneTabSprite[i].setScale(sf::Vector2f(0.008, 0.008));
    }


    Airport airport(292,651);
    Airport_logoSprite[0].setPosition(292,651);
    airport.identification = "Paris";
    airport_List.push_back(airport);
    airport_List.at(0).printCoords();
    Aeroport.setString("Paris");
    Aeroport.setPosition(292,671);
    Aeroport.setFillColor(Color::Black);


    Airport airport1(169,486);
    Airport_logoSprite[1].setPosition(169,486);
    airport1.identification = "Dublin";
    airport_List.push_back(airport1);
    airport_List.at(1).printCoords();
    Aeroport1.setString("Dublin");
    Aeroport1.setPosition(169,506);
    Aeroport1.setFillColor(Color::Black);

    Airport airport2(125,851);
    Airport_logoSprite[2].setPosition(125,851);
    airport2.identification = "Madrid";
    airport_List.push_back(airport2);
    airport_List.at(2).printCoords();
    Aeroport2.setString("Madrid");
    Aeroport2.setPosition(125,871);
    Aeroport2.setFillColor(Color::Black);

    Airport airport3(18,880);
    Airport_logoSprite[3].setPosition(18,880);
    airport3.identification = "Lisbonne";
    airport_List.push_back(airport3);
    airport_List.at(3).printCoords();
    Aeroport3.setString("Lisbonne");
    Aeroport3.setPosition(18,900);
    Aeroport3.setFillColor(Color::Black);

    Airport airport4(479,851);
    Airport_logoSprite[4].setPosition(479,851);
    airport4.identification = "Rome";
    airport_List.push_back(airport4);
    airport_List.at(4).printCoords();
    Aeroport4.setString("Rome");
    Aeroport4.setPosition(479,871);
    Aeroport4.setFillColor(Color::Black);

    Airport airport5(474,451);
    Airport_logoSprite[5].setPosition(474,451);
    airport5.identification = "Copenhague";
    airport_List.push_back(airport5);
    airport_List.at(5).printCoords();
    Aeroport5.setString("Copenhague");
    Aeroport5.setPosition(474,471);
    Aeroport5.setFillColor(Color::Black);

    Airport airport6(539,360);
    Airport_logoSprite[6].setPosition(539,360);
    airport6.identification = "Stockholm";
    airport_List.push_back(airport6);
    airport_List.at(6).printCoords();
    Aeroport6.setString("Stockholm");
    Aeroport6.setPosition(539,380);
    Aeroport6.setFillColor(Color::Black);

    Airport airport7(559,574);
    Airport_logoSprite[7].setPosition(559,574);
    airport7.identification = "Varsovie";
    airport_List.push_back(airport7);
    airport_List.at(7).printCoords();
    Aeroport7.setString("Varsovie");
    Aeroport7.setPosition(559,594);
    Aeroport7.setFillColor(Color::Black);

    Airport airport8(494,564);
    Airport_logoSprite[8].setPosition(494,564);
    airport8.identification = "Berlin";
    airport_List.push_back(airport8);
    airport_List.at(8).printCoords();
    Aeroport8.setString("Berlin");
    Aeroport8.setPosition(494,584);
    Aeroport8.setFillColor(Color::Black);

    Airport airport9(829,807);
    Airport_logoSprite[9].setPosition(829,807);
    airport9.identification = "Istanbul";
    airport_List.push_back(airport9);
    airport_List.at(9).printCoords();
    Aeroport9.setString("Istanbul");
    Aeroport9.setPosition(829,827);
    Aeroport9.setFillColor(Color::Black);


    for(int i = 0; i < 15; i++){
        Plane plane;

        plane.identification = "AF" + to_string(101+i);
        plane.planeIndex = i;
        planeTab[i] = plane;
        planeTab[i].setCoords(airport_List.at(rand()%10).coordinates());
        planeTab[i].updateDestination(airport_List.at(rand()%10).coordinates());

    }

    vector <thread> planeThreads;
    for(int i = 0; i  < 15; i++){
        planeThreads.emplace_back(planeBehaviour, ref(planeTab[i]), ref(stop_thread));

    }



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
        app.draw(Airport_logoSprite[0]);
        app.draw(Airport_logoSprite[1]);
        app.draw(Airport_logoSprite[2]);
        app.draw(Airport_logoSprite[3]);
        app.draw(Airport_logoSprite[4]);
        app.draw(Airport_logoSprite[5]);
        app.draw(Airport_logoSprite[6]);
        app.draw(Airport_logoSprite[7]);
        app.draw(Airport_logoSprite[8]);
        app.draw(Airport_logoSprite[9]);

        for (int i = 0; i < 15; ++i) {
            PlaneTabSprite[i].setPosition(allPlanesCoordinates[i].getX(),allPlanesCoordinates[i].getY());
            app.draw(PlaneTabSprite[i]);
        }

        app.draw(Aeroport);
        app.draw(Aeroport1);
        app.draw(Aeroport2);
        app.draw(Aeroport3);
        app.draw(Aeroport4);
        app.draw(Aeroport5);
        app.draw(Aeroport6);
        app.draw(Aeroport7);
        app.draw(Aeroport8);
        app.draw(Aeroport9);






        app.display();
    }


}
