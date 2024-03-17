#pragma once
#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{
public:
    Entity();
    Entity(float posX, float posY);
    
    //float x,y;
    float CurrentLife;
    float MaxLife;
    float Damage;

    float GetCurrentLife();
    float GetMaxLife();
    float GetDamage();
    float DoDamage(Entity&);

    void move();

    void Destroyed();
};
