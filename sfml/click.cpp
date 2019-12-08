#include <iostream>
#include <SFML/Graphics.hpp>

// g++ -o game click.cpp -lsfml-graphics -lsfml-window -lsfml-system -std=c++17 -g


int main()
{
    constexpr std::size_t kNENTITIES { 10 };
    std::size_t nEnts = 0;

    std::vector<sf::RectangleShape> m_enities {};
    m_enities.reserve(kNENTITIES);

    sf::RenderWindow window(sf::VideoMode(500, 500), "Window");
    window.setMouseCursorVisible(false);
    sf::RectangleShape rect(sf::Vector2f(20.0f, 20.0f)), rect2(sf::Vector2f(20.0f, 20.0f));
    rect2.setFillColor(sf::Color::Black);
    rect.setFillColor(sf::Color::Red);
    window.clear(sf::Color::Black);

    sf::Vector2i posis[2];
    posis[0] = sf::Vector2i(0, 0);
    posis[1] = sf::Vector2i(0, 0);

    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        auto x0 = posis[0].x, y0 = posis[0].y;
        rect2.setPosition(x0, y0);
        window.draw(rect2); // Pintamos negro en 0.

        posis[1] = sf::Mouse::getPosition(window); // Pillamos mouse en 1.

        auto x1 = posis[1].x, y1 = posis[1].y;
        rect.setPosition(x1, y1);

        for(auto e : m_enities)
        {
            window.draw(e);
        }

        if((x1 >= 0 && x1 <= 500) && (y1 >= 0 && y1 <= 500))
        {
            window.draw(rect); // Pintamos rojo en 1.
            std::cout << "X: " << posis[1].x << "\tY: " << posis[1].y << "\n";
            window.display();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                if(nEnts < kNENTITIES)
                {
                    auto& e = m_enities.emplace_back(sf::RectangleShape(sf::Vector2f(20.0f, 20.0f)));
                    e.setPosition(x0, y0);
                    e.setFillColor(sf::Color::Green);
                    window.draw(e);
                    ++nEnts;
                }

                while(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
            }
        }

        posis[0] = posis[1]; // Pasamos 1 a 0.
        window.display();
    }

    window.close();

    return 0;
}   