#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Shapes");

    // Создание трех кругов разного размера, цвета и скорости
    sf::CircleShape circle1(20);
    circle1.setFillColor(sf::Color::Red);
    circle1.setPosition(100, 100);
    float speed1 = 0.5f;

    sf::CircleShape circle2(30);
    circle2.setFillColor(sf::Color::Green);
    circle2.setPosition(400, 300);
    float speed2 = 0.5f;

    sf::CircleShape circle3(15);
    circle3.setFillColor(sf::Color::Blue);
    circle3.setPosition(700, 200);
    float speed3 = 0.5f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Движение каждого круга
        circle1.move(speed1, speed1);
        circle2.move(speed2, speed2);
        circle3.move(speed3, speed3);

        // Отражение от границ экрана
        if (circle1.getPosition().x <= 0 || circle1.getPosition().x + circle1.getRadius() * 2 >= 800) {
            speed1 = -speed1;
        }
        if (circle1.getPosition().y <= 0 || circle1.getPosition().y + circle1.getRadius() * 2 >= 600) {
            speed1 = -speed1;
        }

        if (circle2.getPosition().x <= 0 || circle2.getPosition().x + circle2.getRadius() * 2 >= 800) {
            speed2 = -speed2;
        }
        if (circle2.getPosition().y <= 0 || circle2.getPosition().y + circle2.getRadius() * 2 >= 600) {
            speed2 = -speed2;
        }

        if (circle3.getPosition().x <= 0 || circle3.getPosition().x + circle3.getRadius() * 2 >= 800) {
            speed3 = -speed3;
        }
        if (circle3.getPosition().y <= 0 || circle3.getPosition().y + circle3.getRadius() * 2 >= 600) {
            speed3 = -speed3;
        }

        // Отрисовка кругов на экране
        window.clear();
        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.display();
    }

    return 0;
}
