#include "Game.h"



//私有函数
void Game::initVarbles()
{
	this->window = nullptr;

	//Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 20.f;
	this->enemySpawnTimer = enemySpawnTimerMax;
	this->maxEnemies = 10;
}

void Game::initWindow()
{
	videoMode.height = 600;
	videoMode.width = 800;
	window = new sf::RenderWindow(videoMode, "First", sf::Style::Default);
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(sf::Vector2f(50.f, 50.f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

//构造与析构
Game::Game()
{
	this->initVarbles();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions
void Game::spawnEnemy()
{
	/*
		敌人的颜色，位置，形状(已确定)
		随机生成位置
		随机颜色
		添加至enemy vetor.

		敌人落地会被移除，点击会移除敌人
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),0
		/*static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))*/
	);

	this->enemy.setFillColor(sf::Color::Green);

	//spawn
	this->enemies.push_back(this->enemy);
}
void Game::pollEvents()
{
	//Event rolling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updataMousePostions()
{
	/*
		retrun void 
		updata the mouse positions:
			- Moes
	*/
	this->mousePosWindows = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindows);
}

void Game::updataEnemies()
{
	/*
		根据 game 里的敌人生成时间及敌人数量，来生成updata敌人
		Moves the enemies downwards
		Remove the enemies at the edge of the screen.//TODO
	*/
	//updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else this->enemySpawnTimer += 1.f; 
	}

	//move the enemy
	for (int i = 0; i < this->enemies.size();i++)	
	{
		bool deleted = false;
		this->enemies[i].move(0.f, 5.f);
		//check if click upon    //特性 按住不送也会生效
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) /*|| sf::Mouse::isButtonPressed(sf::Mouse::Middle)*/)
		{
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
			{
				deleted = true;
				this->points++;
			}
		}
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			deleted = true;
		}
		if(deleted == true)
			this->enemies.erase(this->enemies.begin() + i);
	}
}

void Game::updata()
{
	this->pollEvents();
	this->updataEnemies();
	this->updataMousePostions();

	////relative to screen
	////std::cout << "Mouse pos" 
	////	<< sf::Mouse::getPosition().x << " "
	////	<< sf::Mouse::getPosition().y << "\n";
	////relative to windows
	//std::cout << "Mouse pos " 
	//	<< sf::Mouse::getPosition(*this->window).x << " "
	//	<< sf::Mouse::getPosition(*this->window).y << "\n";
}
void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}
void Game::render()
{
	this->window->clear();
	this->renderEnemies();
	this->window->display();
	std::cout << "Pionts:" << this->points << "\n";
}
