#include "Entity.h"

Entity::Entity()
{
    
}

Entity::Entity(float posX, float posY)
{
    setPosition(posX, posY);
}

float Entity::GetCurrentLife()
{
    return CurrentLife;
}

float Entity::GetMaxLife()
{
    return MaxLife;
}

float Entity::GetDamage()
{
    return CurrentLife - Damage;
}

float Entity::DoDamage(Entity& target)
{
    return target.CurrentLife - Damage;
}

void Entity::Destroyed()
{
    delete this;
}
