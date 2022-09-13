#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class SceneNode : public sf::Drawable, 
                public sf::Transformable, 
                private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> Ptr;

    public:
        SceneNode();

        void attachChild(Ptr child);
        Ptr detachChild(const SceneNode& node);
    
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        std::vector<Ptr> mChildren;
        SceneNode* mParent;
};