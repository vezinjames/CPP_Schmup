#include "Background.h"

Background::Background()
{
    if (!texture.loadFromFile("kenney_pixel-shmup\\Tilemap\\tiles_packed.png"))
    {
        //error
    }
    
    int height = 0;
    for (int l = 0; l < 44; ++l)
    {
        std::vector<sf::Sprite*> tileline;
        int width = -1;
        for (int i = 0; i < 21; ++i)
        {
            sf::Sprite* test = new sf::Sprite();
            test->setTexture(texture);
            test->setTextureRect(RandomTexture(rand() % 5));
            test->setPosition(16 * width, 16*l);
            tileline.push_back(test);
            width += 1;
        }
        tilemap.push_back(tileline);
    }
}

sf::IntRect Background::RandomTexture(int index)
{
    if (index == 0)
    {
        return sf::IntRect(32, 64, 16, 16);
    }
    else if (index == 1)
    {
        return sf::IntRect(128, 160, 16, 16);
    }
    else if (index == 2)
    {
        return sf::IntRect(0, 80, 16, 16);
    }
    else if (index == 3)
    {
        return sf::IntRect(96, 48, 16, 16);
    }
    else if (index == 4)
    {
        return sf::IntRect(96, 64, 16, 16);
    }
}
    
void Background::Scroll()
{
    for (auto tileline : tilemap)
    {
        for (auto tile : tileline)
        {
            tile->move(0.f, 1.f);
            if (tile->getPosition().y >= 336)
            {
                tile->setPosition(tile->getPosition().x, -15.f);
            }
        }
    }
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = &texture;
    states.transform = getTransform();
    states.transform.scale(2.f, 2.f);
    for (auto element : tilemap)
    {
        for (auto tile : element)
        {
            target.draw(*tile, states);
            
        }
        
    }
}