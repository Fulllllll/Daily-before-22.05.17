#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp> 
using namespace sf;

class Animation0
{
public:
    float Frame, speed;
    Sprite sprite;
    std::vector<IntRect> frames;

    Animation0(Texture& t, int x, int y, int w, int h, int count, float Speed)
    {
        Frame = 0;
        speed = Speed;

        for (int i = 0; i < count; i++)
            frames.push_back(IntRect(x + i * w, y, w, h));

        sprite.setTexture(t);
        sprite.setOrigin(w / 2, h / 2);
        sprite.setTextureRect(frames[0]);
    }
    void update()
    {
        Frame += speed;
        int n = frames.size();
        if (Frame >= n) Frame -= n;
        if (n > 0) sprite.setTextureRect(frames[int(Frame)]);
    }

    bool isEnd()
    {
        return Frame + speed >= frames.size();
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "Bad Squares!");  //创建窗口代码
    window.setFramerateLimit(60);
    // 16 asteroid  方法 0
    sf::Texture t1;
    if (!t1.loadFromFile("images/rock.png"))
    {
        return -1;
    }
    Animation0 Rock(t1, 0, 0, 64, 64, 16, 0.2);
    Rock.sprite.setPosition(100, 100);

    while (window.isOpen()) //游戏循环
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        Rock.update();


        window.clear();
        window.draw(Rock.sprite);
        window.display();

    }
    return 0;
}