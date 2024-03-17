#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
    Enemy();

    sf::Texture texture;
    sf::Sprite enemySprite;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
