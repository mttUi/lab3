#include <SFML/Graphics.hpp>
#include <array> 
#include <random> 
#include <chrono> 
#include <thread>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "фигурки");

    float circleRadius = 100.0f; // Радиус круга
    sf::CircleShape circle(circleRadius);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(100, 400);
    float circleSpeed = 0.2f;
    bool circleReachedTop = false;
    sf::Clock circleClock;

    int circleColorChange = 0;

    sf::Clock delayClock;
    bool delayOver = false;

    std::array<sf::Color, 10> baseColors = { sf::Color::Red, sf::Color::Green, sf::Color::Blue,
                                            sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta, sf::Color::White, sf::Color(139, 0, 255), sf::Color(1, 50, 32), sf::Color(255, 165, 0) };
    int currentColorIndex = 0; // Индекс для цветов

    // Основной цикл программы
    while (window.isOpen())
    {
        float deltaTime = delayClock.getElapsedTime().asSeconds();

        if (!delayOver && deltaTime >= 3)
        {
            delayOver = true;
            delayClock.restart();
        }

        deltaTime = delayOver ? 0.1f : 0;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (delayOver)
        {
            if (circle.getPosition().y > 0) // Проверка для верхней границы
                circle.move(0, -circleSpeed * deltaTime);
            else if (!circleReachedTop)
            {
                circleReachedTop = true;
                circleClock.restart();
            }
            else if (circleClock.getElapsedTime().asSeconds() >= 1)
            {
                circle.setFillColor(baseColors[currentColorIndex]);
                circleColorChange++;
                if (circleColorChange >= 5) {
                    float randomX = std::rand() % static_cast<int>(window.getSize().x - 2 * circleRadius); // Случайное X в пределах экрана
                    float randomY = std::rand() % static_cast<int>(window.getSize().y - 2 * circleRadius); // Случайное Y в пределах экрана

                    circle.setPosition(randomX, randomY);
                    circleColorChange = 0;
                }
                currentColorIndex = (currentColorIndex + 1) % baseColors.size();
                circleClock.restart();
            }

            window.clear();
            window.draw(circle);
            window.display();
        }
    }

    return 0;
}
