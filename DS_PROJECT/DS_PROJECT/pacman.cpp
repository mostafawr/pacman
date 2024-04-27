#include "pacman.h"



pacman::pacman(const Vector2f& position)
{


    pacshape.setPosition(position);
    pacshape.setRadius(15.5);
   

}

void pacman::draw(sf::RenderWindow& window) {
    window.draw(pacshape);
}

void pacman::setPosition(const sf::Vector2f& newPosition) {
    pacpos = newPosition;
    pacshape.setPosition(pacpos);
}


















void pacman::movepac(sf::Event::KeyEvent keyEvent, int map[][19]) {
   
    const float speed = 1; 

   
    if (velx.empty() && vely.empty()) {
        velx.push(0);
        vely.push(0);
    }

    int i = static_cast<int>(pacshape.getPosition().y / 32);
    int j = static_cast<int>(pacshape.getPosition().x / 32);

  
    if (keyEvent.code == sf::Keyboard::W ) {
        velx.push(0);
        vely.push(-speed);
    }
    else if (keyEvent.code == sf::Keyboard::A) {
        velx.push(-speed);
        vely.push(0);
    }
    else if (keyEvent.code == sf::Keyboard::S ) {
        velx.push(0);
        vely.push(speed);
    }
    else if (keyEvent.code == sf::Keyboard::D && j ) {
        velx.push(speed);
        vely.push(0);
    }
    updatePosition(map);
    // Move Pac-Man according to velocity
    
        pacshape.move(velx.top(), vely.top() );
      

}




void pacman::updatePosition(int map[][19]) {
    int i = static_cast<int>(pacshape.getPosition().y / 32);
    int j = static_cast<int>(pacshape.getPosition().x / 32);
    int i_mod = static_cast<int>(pacshape.getPosition().y) % 32;
    int j_mod = static_cast<int>(pacshape.getPosition().x) % 32;

    
    if ((vely.top() != 0 && map[i + (vely.top() > 0 ? 1 : -1)][j] == 0) ||
        (velx.top() != 0 && map[i][j + (velx.top() > 0 ? 1 : -1)] == 0)) {
        while (!velx.empty()) {
            velx.pop();
        }
        while (!vely.empty()) {
            vely.pop();
        }
        
        velx.push(0);
        vely.push(0);
    }
}
