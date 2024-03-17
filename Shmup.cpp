// Shmup.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Background.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Spaceship.h"
#include "SFML/Graphics.hpp"

int main()
{
    sf::Clock clock;
    Background background;
    Spaceship spaceship;
    Enemy enemy;
    std::vector<Projectile*> projectiles;
    std::vector<Background*> tiles;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Schmup");
    window.setFramerateLimit(60);
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        /*for(int index; index <= window.getSize().x; index++)
        {
            
        }*/
        
        window.draw(background);
        background.Scroll();
        
        for (int index = 0; index < tiles.size(); index++)
        {
            tiles[index]->setPosition(16.0f, 16.0f);
            window.draw(*tiles[index]);
        }
        
        window.draw(spaceship);
        window.draw(enemy);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spaceship.getPosition().x >= +0)
            spaceship.moveLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spaceship.getPosition().x < window.getSize().x - 32.0f)
            spaceship.moveRight();
        
        
            
        spaceship.shoot();
        for (int index = 0; index < spaceship.projectiles.size(); index++ )
        {
            spaceship.projectiles[index]->move();
            window.draw(*spaceship.projectiles[index]);
            if(spaceship.projectiles[index]->getPosition().y > window.getSize().y)
            {
                delete(spaceship.projectiles[index]);
            }
        }
        
        
        
        // end the current frame
        window.display();
    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
