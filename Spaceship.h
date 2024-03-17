#pragma once
#include "Entity.h"
#include "Projectile.h"


class Spaceship : public Entity
{
public:
    Spaceship();

    sf::Clock clock;
    sf::Texture texture;
    sf::Sprite shipSprite;
    std::vector<Projectile*> projectiles;

    void moveLeft();
    void moveRight();
    void shoot();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
