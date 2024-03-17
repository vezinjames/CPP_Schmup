#pragma once
#include <SFML/Graphics.hpp>

class Background : public sf::Drawable, public sf::Transformable
{
public:
    sf::Texture texture;
    sf::Sprite bgSprite1;
    sf::Sprite bgSprite2;
    sf::Sprite bgSprite3;

    std::vector<std::vector<sf::Sprite*>> tilemap;

    sf::RenderStates renderMap;
    Background();

    void generation_map();
    void Scroll();
    void Tick();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::IntRect RandomTexture(int);
    
};
