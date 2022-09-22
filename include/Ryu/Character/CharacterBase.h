#pragma once

#include <SFML/Graphics.hpp>
#include <Ryu/Statemachine/CharacterState.h>
#include <Ryu/Core/AssetManager.h>
#include <Ryu/Core/AssetIdentifiers.h>
#include <Ryu/Scene/SceneNode.h>

using namespace ryu;

namespace ryu{



class CharacterBase : public SceneNode {

public:
    enum class ECharacterState{
        None,
        Idle,
        Walk,
        Run,
        //...
    };

    enum class EMoveDirecton
    {
        None,
        Up,
        Down,
        Left,
        Right,
        UpLeft,
        UpRight,
        DownLeft,
        DownRight
    };


    public:
        // TODO: implement rule of 5 !
        // (morph one character into another ^^)
        CharacterBase();
        explicit CharacterBase(ECharacterState startState);
        ~CharacterBase();

        virtual void handleInput(EInput input);
        virtual void update(sf::Time deltaTime);
        virtual void loadTextures();
        
        virtual void setTextureOnCharacter(Textures::CharacterID textureId);
        virtual void setTexture(AssetManager<sf::Texture, Textures::CharacterID> &textureManager, Textures::CharacterID id);
        sf::Drawable& getSprite() { return mCharacterSprite;}

        void changeColor(sf::Color color);

        // TODO: make private/setter and make Vector or st ? -> see Game.cpp
        bool mIsMovingUp=false;
        bool mIsMovingDown=false;
        bool mIsMovingLeft=false;
        bool mIsMovingRight=false;

    protected:
        // TODO: use smart pointers instead ?!!! and move semantics
        CharacterState* mCharacterState;
        ECharacterState mECharacterState;

    private:
        sf::Sprite mCharacterSprite;
        EMoveDirecton mMoveDirection;
        

        float PlayerSpeed = 75.f;

};

} /// namespace ryu