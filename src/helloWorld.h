#ifndef helloworld_H
#define helloworld_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Input.hpp>
#include <Sprite.hpp>
#include <GlobalConstants.hpp>
namespace godot {
    class helloWorld : public Node2D 
    {
        GODOT_CLASS(helloWorld, Node2D)
    private:
        /* data */
        float time = 0;
        Vector2 currentPos;
        Sprite * currentSprite;
    public:
        static void _register_methods();
        helloWorld(/* args */);
        ~helloWorld();

        void _init();

        void _process(float delta);

        void move(Vector2 position);
    };

    
}
#endif