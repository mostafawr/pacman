#include <stack>
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;


enum Cell
{
    Door=4,
    Empty,
    Energizer,
    Pellet,
    Wall=0
};


class pacman {
public:
    CircleShape pacshape;

    Texture pactext;
    Vector2f pacpos;
    stack<float> velx;
    stack<float> vely;
   

  
public:
    pacman(const Vector2f& position = Vector2f(0.f, 0.f));
    void draw(RenderWindow& window);
    void setPosition(const sf::Vector2f& newPosition);
    void movepac(sf::Event::KeyEvent keyEvent,int [][19]);
    void updatePosition(int map[][19]);
private:
    sf::Clock clock; // Declare clock for timing
    int currentSpeed = 1; // Initial speed
    const int maxSpeed = 4;
};

bool map_collision(bool i_collect_pellets, bool i_use_door, short i_x, short i_y, array<array<Cell, 19>, 20>& i_map);
