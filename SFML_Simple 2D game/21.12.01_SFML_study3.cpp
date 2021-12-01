#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp> 
#include <list>
using namespace sf;


#include "AssetManager.h"

struct Animation {
    std::string m_Name;
    std::string m_TextureName;
    std::vector<sf::IntRect> m_Frames;
    sf::Time m_Duration;
    bool m_looping;

    Animation(std::string const& name, std::string const& textureName,
        sf::Time const& duration, bool looping)
        : m_Name(name), m_TextureName(textureName),
        m_Duration(duration), m_looping(looping) {}

    void AddFrames(sf::Vector2i const& startFrom,
        sf::Vector2i const& frameSize, unsigned int frames) {

        sf::Vector2i current = startFrom;
        for (unsigned int i = 0; i < frames; i++) {
            m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
            current.x += frameSize.x;
        }
    }
};
struct Animator {
public:
    struct Animation {
        std::string m_Name;
        std::string m_TextureName;
        std::vector<sf::IntRect> m_Frames;
        sf::Time m_Duration;
        bool m_looping;

        Animation(std::string const& name, std::string const& textureName,
            sf::Time const& duration, bool looping)
            : m_Name(name), m_TextureName(textureName),
            m_Duration(duration), m_looping(looping) {}

        void AddFrames(sf::Vector2i const& startFrom,
            sf::Vector2i const& frameSize, unsigned int frames) {

            sf::Vector2i current = startFrom;
            for (unsigned int i = 0; i < frames; i++) {
                m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
                current.x += frameSize.x;
            }
        }
    };

    Animator(sf::Sprite& sprite)
        : m_Sprite(sprite), m_CurrentTime(), m_CurrentAnimation(nullptr) {}

    Animator::Animation& CreateAnimation(std::string const& name,
        std::string const& textureName, sf::Time const& duration, bool loop = false);

    void Update(sf::Time const& dt);

    // 是否切换成功
    bool SwitchAnimation(std::string const& name);

    std::string GetCurrentAnimationName() const;
private:
    // 通过名字查找已经添加过的动画效果 Animation
    Animator::Animation* FindAnimation(std::string const& name);

    void SwitchAnimation(Animator::Animation* animation);

    // sprite 的引用
    sf::Sprite& m_Sprite;
    sf::Time m_CurrentTime;
    std::list<Animator::Animation> m_Animations;
    Animator::Animation* m_CurrentAnimation;

};
Animator::Animation& Animator::CreateAnimation(std::string const& name,
    std::string const& textureName, sf::Time const& duration, bool loop) {

    m_Animations.push_back(
        Animator::Animation(name, textureName, duration, loop));
    // 如果当前没有动画效果，则使用刚添加动画效果
    if (m_CurrentAnimation == nullptr)
        SwitchAnimation(&m_Animations.back());

    return m_Animations.back();
}
void Animator::SwitchAnimation(Animator::Animation* animation) {
    // 改变精灵的纹理
    if (animation != nullptr) {
        m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName));
    }
    m_CurrentAnimation = animation;
    m_CurrentTime = sf::Time::Zero; // 重置时间
}
bool Animator::SwitchAnimation(std::string const& name) {
    auto animation = FindAnimation(name);
    if (animation != nullptr) {
        SwitchAnimation(animation);
        return true;
    }
    return false;
}
Animator::Animation* Animator::FindAnimation(std::string const& name) {
    for (auto it = m_Animations.begin(); it != m_Animations.end(); it++) {
        if (it->m_Name == name) {
            return &*it;
        }
    }
    return nullptr;
}
std::string Animator::GetCurrentAnimationName() const {
    if (m_CurrentAnimation != nullptr) {
        return m_CurrentAnimation->m_Name;
    }

    return "";
}
void Animator::Update(sf::Time const& dt) {
    if (m_CurrentAnimation == nullptr) return;

    m_CurrentTime += dt;

    // 获取当前帧
    float scaledTime = m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds();
    int numFrames = m_CurrentAnimation->m_Frames.size();
    int currentFrame = static_cast<int>(scaledTime * numFrames);


    // 如果动画在进行，则计算当前帧
    if (m_CurrentAnimation->m_looping) {
        currentFrame %= numFrames;
    }
    else if (currentFrame >= numFrames) { // 如果当前帧不小于总的帧数，设为最后一帧
        currentFrame = numFrames - 1;
    }

    // 设置为当前帧
    m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}

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
    //  方法 1
    sf::Vector2i spriteSize(32, 32);  //单个帧的大小
    sf::Sprite SRock;
    Animator animator(SRock);
    auto& idleAnimation = animator.CreateAnimation("Idle", "images/rock_small.png", sf::seconds(1), true);;
    idleAnimation.AddFrames(sf::Vector2i(0, 0), spriteSize, 16);

    while (window.isOpen()) //游戏循环
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear();
        window.draw(Rock.sprite); 
        window.display();

    }
    return 0;
}



//int frameNum = 8; //Animation consists of 8 frames
//float animationDuration = 1; // 1 seconds
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(600, 800), "Bad Squares!");  //创建窗口代码
//
//    sf::Texture texture;
//    if (!texture.loadFromFile("111.jpg"))
//    {
//        return -1;
//    }
//
//    sf::Sprite sprite(texture);
//    sf::Vector2i spriteSize(32, 32);
//    //将sprite图像设置为动画的第一帧
//    sprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));
//
//    int frameNum = 8; //Animation consists of 8 frames
//    float animationDuration = 1; // 1 seconds 
//
//    sf::Time deltaTime;
//    sf::Time elapsedTime;
//    sf::Clock clock;
//
//    while (window.isOpen()) //游戏循环
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if(event.type==sf::Event::EventType::Closed)
//                window.close();
//
//
//        }
//        // Returns the elapsed time and restarts the clock
//        deltaTime = clock.restart();
//
//        //Handle input
//
//        //Accumulate time with each time
//        elapsedTime += deltaTime;
//        float timeAsSeconds = elapsedTime.asSeconds();
//
//        //Get the current animation frame
//        int animFrame = static_cast<int>((timeAsSeconds / animationDuration) * frameNum) % frameNum;
//
//        // Set the texture rectangle, depending on the frame
//        sprite.setTextureRect(sf::IntRect(animFrame * spriteSize.x, 0, spriteSize.x, spriteSize.y));
//
//        window.draw(sprite);
//    }
//
//    return 0;
//}
 
 
 
 
 
 
 
//#include <SFML/Graphics.hpp>
//#include"AssetManager.h"
//#include<cassert>
//
//
//AssetManager* AssetManager::sInstance = nullptr;
//AssetManager::AssetManager()
//{
//    //只允许存在一个AssetManager 实例
//    //否则抛出异常
//    assert(sInstance == nullptr);
//    sInstance = this;
//}
//sf::Texture& AssetManager::GetTexture(std::string const& filename)
//{
//    auto& texMap = sInstance->m_Textures;
//
//    //查看Textures是否已加载
//    auto pairFound = texMap.find(filename);
//
//    //如果是，返回 texture
//    if (pairFound != texMap.end())
//    {
//        return pairFound->second;
//    }
//    else //否则，加载texture并返回它
//    {
//        //在texture贴图中创建一个元素
//        auto& texture = texMap[filename];
//        texture.loadFromFile(filename);
//        return texture;
//    }
//}
//int main()
//{
//
//    sf::RenderWindow window(sf::VideoMode(640, 480), "AssetManager");
//    AssetManager manager;
//
//    //Create sprites
//    //sf::Sprite sprite1 = sf::Sprite(AssetManager::GetTexture("myTexture1.png"));
//    //sf::Sprite sprite2 = sf::Sprite(AssetManager::GetTexture("myTexture2.png"));
//    //sf::Sprite sprite3 = sf::Sprite(AssetManager::GetTexture("myTexture1.png"));
//    while (window.isOpen())
//    {
//        // Game loop
//    }
//    // After main() returns, the manager is destoryed
//    system("pause");
//    return 0;
//}
