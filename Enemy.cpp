#include "Enemy.h"

Enemy::Enemy()
{
    CurrentLife = 1;
    MaxLife = 1;
    Damage = 1;

    if (!texture.loadFromFile("D:\\Users\\VisualStudio\\Cours\\Projets\\Shmup\\kenney_pixel-shmup\\Tilemap\\ships_packed.png", sf::IntRect(64,0,32,32)))
    {
        //error
    }
    enemySprite.setTexture(texture);
    if(CurrentLife == 0)
    {
        this->Destroyed();
    }
    setPosition(64.0f, 128.0f);
    setRotation(180);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = getTransform();
    target.draw(enemySprite, states);
}
