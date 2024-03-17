#include <SFML/Graphics.hpp>
#include <random>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "OKNO EB");
    sf::Clock clock;

    sf::CircleShape circle(35);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(150, 150);
    float speedX_circle = 150.0f;
    float speedY_circle = 150.0f;
    int hitCount_circle = 0;

    sf::RectangleShape square(sf::Vector2f(85, 85));
    square.setFillColor(sf::Color::Green);
    square.setPosition(400, 150);
    float speedX_square = 100.0f;
    float speedY_square = 100.0f;
    int hitCount_square = 0;

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(60, 0));
    triangle.setPoint(2, sf::Vector2f(30, 60));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(600, 150);
    float speedX_triangle = 200.0f;
    float speedY_triangle = 200.0f;
    int hitCount_triangle = 0;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 255);

    while (window.isOpen()) {
        sf::Time dt = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        circle.move(speedX_circle * dt.asSeconds(), speedY_circle * dt.asSeconds());
        square.move(speedX_square * dt.asSeconds(), speedY_square * dt.asSeconds());
        triangle.move(speedX_triangle * dt.asSeconds(), speedY_triangle * dt.asSeconds());

        if (circle.getPosition().x <= 0 || circle.getPosition().x + circle.getRadius() * 2 >= 800) {
            speedX_circle = -speedX_circle;
            hitCount_circle++;
            circle.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        }
        if (circle.getPosition().y <= 0 || circle.getPosition().y + circle.getRadius() * 2 >= 600) {
            speedY_circle = -speedY_circle;
            hitCount_circle++;
            circle.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        }

        if (square.getPosition().x <= 0 || square.getPosition().x + square.getSize().x >= 800) {
            speedX_square = -speedX_square;
            hitCount_square++;
            square.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        }
        if (square.getPosition().y <= 0 || square.getPosition().y + square.getSize().y >= 600) {
            speedY_square = -speedY_square;
            hitCount_square++;
            square.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        }

        if (triangle.getPosition().x <= 0 || triangle.getPosition().x + 60 >= 800) {
            speedX_triangle = -speedX_triangle;
            hitCount_triangle++;
            triangle.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        }
        if (triangle.getPosition().y <= 0 || triangle.getPosition().y + 60 >= 600) {
            speedY_triangle = -speedY_triangle;
            hitCount_triangle++;
            triangle.setFillColor(sf::Color(dist(mt), dist(mt), dist(mt)));
        }

        sf::Font font;
        font.loadFromFile("arial.ttf");

        sf::Text text_circle;
        text_circle.setFont(font);
        text_circle.setCharacterSize(20);
        text_circle.setFillColor(sf::Color::White);
        text_circle.setPosition(circle.getPosition().x + 10, circle.getPosition().y + 10);
        text_circle.setString(" " + std::to_string(hitCount_circle));

        sf::Text text_square;
        text_square.setFont(font);
        text_square.setCharacterSize(20);
        text_square.setFillColor(sf::Color::White);
        text_square.setPosition(square.getPosition().x + 30, square.getPosition().y + 30);
        text_square.setString(" " + std::to_string(hitCount_square));

        sf::Text text_triangle;
        text_triangle.setFont(font);
        text_triangle.setCharacterSize(20);
        text_triangle.setFillColor(sf::Color::White);
        text_triangle.setPosition(triangle.getPosition().x + 18, triangle.getPosition().y + 10);
        text_triangle.setString(" " + std::to_string(hitCount_triangle));

        window.clear();
        window.draw(circle);
        window.draw(text_circle);
        window.draw(square);
        window.draw(text_square);
        window.draw(triangle);
        window.draw(text_triangle);
        window.display();
    }

    return 0;
}
