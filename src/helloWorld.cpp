#include "helloWorld.h"

using namespace godot;

void helloWorld::_register_methods()
{
    register_method("_process", &helloWorld::_process);
    register_method("move", &helloWorld::move);
}
    
    helloWorld::helloWorld(/* args */)
    {
    }
    
    helloWorld::~helloWorld()
    {
    }

void helloWorld::_init()
{
    Godot::print("hello World");
    
}

void helloWorld::_process(float delta)
{
    time+= delta;
    int moveDirection = 0;
    Input * input = Input::get_singleton();
    if(input->is_action_pressed("ui_right")){
        moveDirection = 1;
    }
    if(input->is_action_pressed("ui_left")){
        moveDirection = -1;
    }

    Vector2 moveVector = Vector2(((time * 10) * moveDirection) + currentPos.x, 0 + currentPos.y);
    move(moveVector);
}

void helloWorld::move(Vector2 position){
    Node * testnode = get_node("moveSpriteObject");
    if(testnode != NULL){
        currentSprite = cast_to<Sprite>(testnode);
        currentPos = currentSprite->get_global_position();
    }
    currentSprite->set_global_position(position);
    currentPos = position;
}