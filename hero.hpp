#include <iostream>
#ifndef HERO_HPP
#define HERO_HPP
enum class Action 
    {
        IDLE, 
        DUCK,
        RUN,
        WALK,
        JUMP
    };



class State;

class hero
{ 
public:

static hero* instance(std::string &name_);
State *state;
State *previousState;

private:

std::string name;
static hero *hero_ptr;
hero(std::string &name_);

};

class State
{
public:
virtual void execute(hero &my_hero)=0;
};

class Idle :public State
{
public:    
void execute(hero &my_hero);
};

class Walk :public State
{
public:    
void execute(hero &my_hero);
};

class Run :public State
{
public:    
void execute(hero &my_hero); 
};

class Jump :public State
{
public:    
void execute(hero &my_hero);
};
#endif