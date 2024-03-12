#include <SFML/Graphics.hpp>
#include <random>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Shapes Up and Right");

    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(50, 600);
    float speedX_circle = 0.0f;
    float speedY_circle = -0.2f;
    bool colorChanged_circle = false;

    sf::RectangleShape square(sf::Vector2f(60, 60));
    square.setFillColor(sf::Color::Green);
    square.setPosition(200, 600);
    float speedX_square = 0.0f;
    float speedY_square = -0.1f;
    bool colorChanged_square = false;

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(30, 0));
    triangle.setPoint(2, sf::Vector2f(15, 30));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(350, 600);
    float speedX_triangle = 0.0f;
    float speedY_triangle = -0.3f;
    bool colorChanged_triangle = false;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 255);

    sf::Clock clock;
    sf::Time elapsedTime = clock.getElapsedTime();
    while (elapsedTime.asSeconds() < 2) {
        elapsedTime = clock.getElapsedTime();
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        circle.move(speedX_circle, speedY_circle);
        square.move(speedX_square, speedY_square);
        triangle.move(speedX_triangle, speedY_triangle);

        // Reflect logic here

        if (circle.getPosition().y <= 0) {
            if (!colorChanged_circle) {
                circle.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
                colorChanged_circle = true;
            }
            speedY_circle = 0;
            speedX_circle = 0.1f;
        }
        if (square.getPosition().y <= 0) {
            if (!colorChanged_square) {
                square.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
                colorChanged_square = true;
            }
            speedY_square = 0;
            speedX_square = 0.2f;
        }
        if (triangle.getPosition().y <= 0) {
            if (!colorChanged_triangle) {
                triangle.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
                colorChanged_triangle = true;
            }
            speedY_triangle = 0;
            speedX_triangle = 0.3f;
        }

        if (circle.getPosition().x + circle.getRadius() * 2 >= 800) {
            speedX_circle = 0;
            speedY_circle = 0;
        }
        if (square.getPosition().x + square.getSize().x >= 800) {
            speedX_square = 0;
            speedY_square = 0;
        }
        if (triangle.getPosition().x + 30 >= 800) {
            speedX_triangle = 0;
            speedY_triangle = 0;
        }

        window.clear();
        window.draw(circle);
        window.draw(square);
        window.draw(triangle);
        window.display();
    }

    return 0;
}
