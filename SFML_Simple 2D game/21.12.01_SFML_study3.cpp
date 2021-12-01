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

    // �Ƿ��л��ɹ�
    bool SwitchAnimation(std::string const& name);

    std::string GetCurrentAnimationName() const;
private:
    // ͨ�����ֲ����Ѿ���ӹ��Ķ���Ч�� Animation
    Animator::Animation* FindAnimation(std::string const& name);

    void SwitchAnimation(Animator::Animation* animation);

    // sprite ������
    sf::Sprite& m_Sprite;
    sf::Time m_CurrentTime;
    std::list<Animator::Animation> m_Animations;
    Animator::Animation* m_CurrentAnimation;

};
Animator::Animation& Animator::CreateAnimation(std::string const& name,
    std::string const& textureName, sf::Time const& duration, bool loop) {

    m_Animations.push_back(
        Animator::Animation(name, textureName, duration, loop));
    // �����ǰû�ж���Ч������ʹ�ø���Ӷ���Ч��
    if (m_CurrentAnimation == nullptr)
        SwitchAnimation(&m_Animations.back());

    return m_Animations.back();
}
void Animator::SwitchAnimation(Animator::Animation* animation) {
    // �ı侫�������
    if (animation != nullptr) {
        m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName));
    }
    m_CurrentAnimation = animation;
    m_CurrentTime = sf::Time::Zero; // ����ʱ��
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

    // ��ȡ��ǰ֡
    float scaledTime = m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds();
    int numFrames = m_CurrentAnimation->m_Frames.size();
    int currentFrame = static_cast<int>(scaledTime * numFrames);


    // ��������ڽ��У�����㵱ǰ֡
    if (m_CurrentAnimation->m_looping) {
        currentFrame %= numFrames;
    }
    else if (currentFrame >= numFrames) { // �����ǰ֡��С���ܵ�֡������Ϊ���һ֡
        currentFrame = numFrames - 1;
    }

    // ����Ϊ��ǰ֡
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
    sf::RenderWindow window(sf::VideoMode(600, 800), "Bad Squares!");  //�������ڴ���
    window.setFramerateLimit(60);
    //  ���� 1
    sf::Vector2i spriteSize(32, 32);  //����֡�Ĵ�С
    sf::Sprite SRock;
    Animator animator(SRock);
    auto& idleAnimation = animator.CreateAnimation("Idle", "images/rock_small.png", sf::seconds(1), true);;
    idleAnimation.AddFrames(sf::Vector2i(0, 0), spriteSize, 16);

    while (window.isOpen()) //��Ϸѭ��
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
//    sf::RenderWindow window(sf::VideoMode(600, 800), "Bad Squares!");  //�������ڴ���
//
//    sf::Texture texture;
//    if (!texture.loadFromFile("111.jpg"))
//    {
//        return -1;
//    }
//
//    sf::Sprite sprite(texture);
//    sf::Vector2i spriteSize(32, 32);
//    //��spriteͼ������Ϊ�����ĵ�һ֡
//    sprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));
//
//    int frameNum = 8; //Animation consists of 8 frames
//    float animationDuration = 1; // 1 seconds 
//
//    sf::Time deltaTime;
//    sf::Time elapsedTime;
//    sf::Clock clock;
//
//    while (window.isOpen()) //��Ϸѭ��
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
//    //ֻ�������һ��AssetManager ʵ��
//    //�����׳��쳣
//    assert(sInstance == nullptr);
//    sInstance = this;
//}
//sf::Texture& AssetManager::GetTexture(std::string const& filename)
//{
//    auto& texMap = sInstance->m_Textures;
//
//    //�鿴Textures�Ƿ��Ѽ���
//    auto pairFound = texMap.find(filename);
//
//    //����ǣ����� texture
//    if (pairFound != texMap.end())
//    {
//        return pairFound->second;
//    }
//    else //���򣬼���texture��������
//    {
//        //��texture��ͼ�д���һ��Ԫ��
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
