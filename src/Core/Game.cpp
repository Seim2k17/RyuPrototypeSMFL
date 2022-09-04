#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include <Ryu/Core/Game.h>

using namespace ryu;

Game::Game()
: mWindow(sf::VideoMode(1024, 768), "SFML Application"),
mPlayer(std::make_unique<CharacterBase>())
{
	//mPlayer = std::make_unique<CharacterBase>();
}

void Game::run()
{
	sf::Clock clock;
	while (mWindow.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::handleUserInput(sf::Keyboard::Key key, bool keyPressed)
{
	//std::cout << std::to_string(key) << (keyPressed ? " pressed" : " released") << std::endl;
	switch(key)
	{
		case sf::Keyboard::W:
		case sf::Keyboard::Up:
		{
			mPlayer->mIsMovingUp = keyPressed;
			mPlayer->handleInput(keyPressed ? EInput::PRESSUP : EInput::RELEASEUP);
			break;
		}

		case sf::Keyboard::S:
		case sf::Keyboard::Down:
		{
			mPlayer->mIsMovingDown = keyPressed;
			mPlayer->handleInput(keyPressed ? EInput::PRESSUP : EInput::RELEASEDOWN);
			break;
		}
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
		{
			mPlayer->mIsMovingRight = keyPressed;
			mPlayer->handleInput(keyPressed ? EInput::PRESSRIGHT : EInput::RELEASERIGHT);
			break;
		}
		case sf::Keyboard::A:
		case sf::Keyboard::Left:
		{
			mPlayer->mIsMovingLeft = keyPressed;
			mPlayer->handleInput(keyPressed ? EInput::PRESSLEFT : EInput::RELEASELEFT);
			break;
		}
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::KeyPressed:
			{
				handleUserInput(event.key.code,true);
				break;
			}
			case sf::Event::KeyReleased:
			{
				handleUserInput(event.key.code,false);
				break;
			}
			case sf::Event::Closed:
			{
				mWindow.close();
				break;
			}
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	mPlayer->update(deltaTime);
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer->getSprite());
	mWindow.display();
}
