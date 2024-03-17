#pragma once
#include "Entity.h"

class Spaceship;

class Projectile : public Entity
{
public:
    Projectile(Spaceship*);

    sf::Texture texture;
    sf::Sprite projectileSprite;
    
    float pSpeed = 1;
    

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
