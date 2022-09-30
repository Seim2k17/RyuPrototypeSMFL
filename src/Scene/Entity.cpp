#include <Ryu/Scene/Entity.h>

//namespace ryu {

Entity::~Entity() {}

void
Entity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}
        
void
Entity::setVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}
        
sf::Vector2f
Entity::getVelocity() const
{
    return mVelocity;
}

void
Entity::updateCurrent(sf::Time dt)
{
    move(mVelocity * dt.asSeconds()); /// == setPosition(getPosition() + offset)
}

//} /// namespace ryu
