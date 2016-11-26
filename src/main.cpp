// put the whole SFML folder into minGW folder with libs and shit ...
// importing not the whole Graphics didn't work
// had to tweak CMAKE with -static flag only
// was missing https://upyourgears.ru/files/libz.a , no idea if that was 64 or 32 bit

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std; // Have a look here, go to nub tut... stop running

class Human {
public:
    string name;
    int age;
    int life_force;
};


class Builder : public Human {

public:
    void build() {
        life_force -= 10;
        cout << "Tuk tuk tuk";
    };

public:
    void information() {
        cout << "My name is " << name << ".I am " << age << endl;
    }


};


int main(int argc, char **argv) {

    sf::RenderWindow window(sf::VideoMode(1080, 720, 32), "Scuko!");
    Builder bob;
    bob.name = "Bob";
    bob.age = 57;
    bob.information();
    bob.build();


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Green);
        window.display();
    }
    return 0;
}