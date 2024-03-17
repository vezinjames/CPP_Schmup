#include "Projectile.h"

#include <set>

#include "Spaceship.h"

Projectile::Projectile(Spaceship* spaceship)
{
    Damage = 1;

    if (!texture.loadFromFile("D:\\Users\\VisualStudio\\Cours\\Projets\\Shmup\\kenney_pixel-shmup\\Tilemap\\tiles_packed.png", sf::IntRect(0,0,16,16)))
    {
        //error
    }
    texture.setRepeated(false);
    projectileSprite.setTexture(texture);

    setPosition(spaceship->getPosition().x, spaceship->getPosition().y - 16.0f);
    //setOrigin(-8,-8);
    
}

void Entity::move()
{
    Transformable::move(0.0f, -4.0f);
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = getTransform();
    target.draw(projectileSprite, states);
}