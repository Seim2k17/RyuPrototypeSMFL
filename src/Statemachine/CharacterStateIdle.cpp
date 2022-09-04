#include <Ryu/Statemachine/CharacterStateIdle.h>
#include <Ryu/Statemachine/CharacterStateRun.h>
#include <Ryu/Statemachine/CharacterState.h>

#include <iostream>

using namespace ryu;

CharacterStateIdle::CharacterStateIdle(){}

CharacterStateIdle::~CharacterStateIdle(){}

CharacterState* 
CharacterStateIdle::handleInput(CharacterBase& character,EInput input)
{
    switch (input)
    {
       case EInput::PRESSLEFT:
       case EInput::PRESSRIGHT:
       {
           return new CharacterStateRun();    
       }

       case EInput::PRESSUP:
       case EInput::PRESSDOWN:
       {
           return new CharacterStateRun();    
       }
     
    default:
        break;
    }

    return nullptr;
}
     
void 
CharacterStateIdle::update(CharacterBase& character)
{
    std::cout << "IDLE"<< std::endl;
}


void
CharacterStateIdle::enter(CharacterBase& character)
{

}

void
CharacterStateIdle::exit(CharacterBase& character)
{

}