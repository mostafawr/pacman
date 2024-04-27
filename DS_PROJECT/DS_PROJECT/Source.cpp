#include "pacman.h"

#include "map.h"
using namespace sf;


using namespace sf;
int main() {
    //SPRITESHEET
    sf::Texture spriteSheet;
    spriteSheet.loadFromFile("spriteSheet.png");




    RenderWindow window(sf::VideoMode(1280, 1024, 32), "Pac-Man");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    //pacman Pacman(startPosition);

    Vector2f position;
    Event event;

    Map map;

    while (window.isOpen()) {


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W ||
                    event.key.code == sf::Keyboard::A ||
                    event.key.code == sf::Keyboard::S ||
                    event.key.code == sf::Keyboard::D) {
                    
                       
                    
                   
                }
            }
        }
          
   
      //  Pacman.movepac(event.key, Map);

        window.clear();

        map.generate(window, spriteSheet, 264);
       // Pacman.draw(window);
        window.display();
    }
    return 0;
}