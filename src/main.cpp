// put the whole SFML folder into minGW folder with libs and shit ...
// please be smart next time and use 32 bit SFML version instead of banging your head in the wall and reading whole
// stackoverflow instead of studing!
// importing not the whole Graphics didn't work
// had to tweak CMAKE with -static flag only
// was missing https://upyourgears.ru/files/libz.a , no idea if that was 64 or 32 bit
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>


using namespace std; // Have a look here, go to nub tut... stop running
//using namespace sf;

constexpr int windowWidth{1024}, windowHeight{768};
constexpr float ballRadius{5.f}, ballVelocity(1.f);

struct Ball {
    // SFML circle shape is used
    sf::CircleShape shape;

    // 2D vextor that stores our ball's velocity
    sf::Vector2f velocity{-ballVelocity, -ballVelocity};
    // ball constructor
    // mX , mY starting x and y coordinates

    Ball(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(sf::Color::Red);
        shape.setOutlineThickness(10);
        shape.setOutlineColor(sf::Color(150, 50, 250));
        shape.setOrigin(ballRadius, ballRadius);
    }

    void updateLocation() { shape.move(velocity); }
};


int main(int argc, char **argv) {

    // ball instantiation
    Ball cannonBall{windowWidth / 3, windowHeight / 3};
    // Game window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, 32), "Scuko!");
    window.setFramerateLimit(60);
    // Game loop
    while (window.isOpen()) { ;
        window.clear(sf::Color::Black);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        cannonBall.updateLocation();
        window.draw(cannonBall.shape);
        window.display();
    }
    return 0;
}