#include <Ryu/Character/CharacterIchi.h>
#include <Ryu/Core/Category.h>

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
//namespace ryu {

CharacterIchi::CharacterIchi(ECharacterState startState, std::unique_ptr<b2World>& phWorld,  const sf::Vector2f &position)
: CharacterBase(startState, phWorld, position)
 , ichiTextureManager()
{
    loadTextures();

    //mCharacterAnimation.setPosition({100.f,50.f});
    mCharacterState->enter(*this);
      
}

void
CharacterIchi::setTextureOnCharacter(Textures::LevelID textureId)
{
    setTexture(ichiTextureManager, textureId);
}

void
CharacterIchi::loadTextures()
{
    // At the moment we should not switch textures often on an object so we put every animatzion/level in one big spritesheet
    // and load it at the startup of the level
    // we should check what happens when we change outfits etc...
    // case level 1:
    ichiTextureManager.load(Textures::LevelID::Level1,"assets/spritesheets/ichi/ichi_spritesheet_level1.png");
    /*
    ichiTextureManager.load(Textures::CharacterID::IchiIdleRun,"assets/spritesheets/ichi/01_sheet_ichi_run.png");
    ichiTextureManager.load(Textures::CharacterID::IchiFallingLow,"assets/spritesheets/ichi/03_sheet_ichi_fall_low.png");
    */
    // Outfit combat
    //ichiTextureManager.load(Textures::CharacterID::IchiKatanaWalk,"assets/spritesheets/ichi/02_sheet_ichi_katana_walk.png");
}

unsigned int 
CharacterIchi::getCategory() const
{
    return static_cast<unsigned>(Category::Type::Player);
}

void
CharacterIchi::moveCharacter(sf::Vector2f velocity)
{
    //std::cout << "MOVE CHAR " << velocity.x << "," << velocity.y << "\n";
    /* TODO: tmp here/constran movement*/

    bool xMove = true;
    bool yMove = true;
   
    if(velocity.x == 0.f && velocity.y == 0.f)
    {
        setMovement({0.f,0.f});
    }

    // TODO: here we need to check if movement in the wanted direction is allowed
    if((xMove && velocity.x != 0.f) || (yMove && velocity.y != 0.f))
    {
        setMovement(velocity);
    }
    //std::cout << "move: " << (int)getMoveDirection() << "\n";
}

void
CharacterIchi::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    // t.b.c
    CharacterBase::drawCurrent(target,states);
    // draw PlayerSprite
    target.draw(mCharacterAnimation);
}

void 
CharacterIchi::update(sf::Time deltaTime)
{
    CharacterBase::update(deltaTime);
    
    //b2Vec2 v = getBody()->GetLinearVelocity();
    //g_debugDraw.DrawString(5, m_textLine, "Character Linear Velocity: %f", v.y);

    //auto posi = getBody()->GetLinearVelocity(); //>GetLinearVelocityFromLocalPoint({getPosition().x,getPosition().y});
    //std::cout << "ichi(y):" << v.y <<"\n";
    //mCharacterAnimation.setPosition({posi.x*50,posi.y*50});

    
}

//} /// namespace ryu