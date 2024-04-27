#pragma once
#include <SFML/Graphics.hpp>
class Tile
{
    int sizeX;
    int sizeY;
    int posX;
    int posY;
    sf::Sprite sprite;

public:
    Tile(sf::Texture&, sf::Sprite, int, int, int xOfRect = 264, int sX = 32, int sY = 32);
    int getPosY();
    int getPosX();
    void draw(sf::RenderWindow& window);

};
class Map
{

    std::vector <Tile> tilemap;

public:
    void generate(sf::RenderWindow& window, sf::Texture& tileTexture, int xOfRect = 264);
    std::vector <Tile> getTilemap();
};