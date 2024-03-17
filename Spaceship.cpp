#include "Spaceship.h"

#include "Projectile.h"


Spaceship::Spaceship()
{
    CurrentLife = 3;
    MaxLife = 3;
    Damage = 1;
    

    if (!texture.loadFromFile("D:\\Users\\VisualStudio\\Cours\\Projets\\Shmup\\kenney_pixel-shmup\\Tilemap\\ships_packed.png", sf::IntRect(0,0,32,32)))
    {
        //error
    }
    shipSprite.setTexture(texture);
    
    if(CurrentLife == 0)
    {
        this->Destroyed();
    }
    setPosition(32.0f, 256.0f);
    
}

void Spaceship::shoot()
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asSeconds() > 0.5f)
    {
        projectiles.push_back(new Projectile(this));
        clock.restart();
    }
}

void Spaceship::moveLeft()
{
    Transformable::move(-4.0f, 0.0f);
}
void Spaceship::moveRight()
{
    Transformable::move(4.0f, 0.0f);   
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = getTransform();
    target.draw(shipSprite, states);
}

