
#include "hero.hpp"
  


hero *hero::hero_ptr = 0;

class State;

hero::hero(std::string &name_):name(name_),state(new Idle),previousState(0)
{
    state->execute(*this);
}

hero* hero::instance(std::string &name_)
{
 if(!hero_ptr)
 {
   hero_ptr = new hero(name_);
 }

 return hero_ptr;
}



 void State::execute(hero &my_hero) {};



void Idle::execute(hero &my_hero)
{
 std::cout<<"I am idle"<<std::endl;
 
  char input;
  std::cin>>input;
  switch(input)
  {
   case 'd':
   delete my_hero.state;
   my_hero.state = new Walk;
   my_hero.state->execute(my_hero);
   break;
   case 'w':
   my_hero.previousState = my_hero.state ;
   my_hero.state = new Jump;
   my_hero.state->execute(my_hero);
   break;
   default :
   delete my_hero.state;
   my_hero.state = new Idle;
   my_hero.state->execute(my_hero);
   break;
  }

 
}



void Walk::execute(hero &my_hero)
{
 std::cout<<"I am Walking"<<std::endl;
 
  char input;
  std::cin>>input;
  switch(input)
  {
   case 'd':
   delete my_hero.state;
   my_hero.state = new Run;
   my_hero.state->execute(my_hero);
   break;
   case 'w':
   my_hero.previousState = my_hero.state ;
   my_hero.state = new Jump;
   my_hero.state->execute(my_hero);
   break;
   case 'a' :
   delete my_hero.state;
   my_hero.state = new Idle;
   my_hero.state->execute(my_hero);
   break;
   default :
   delete my_hero.state;
   my_hero.state = new Walk;
   my_hero.state->execute(my_hero);
   break;
  }

 
}


void Run::execute(hero &my_hero)
{
 std::cout<<"I am Running"<<std::endl;
 
  char input;
  std::cin>>input;
  switch(input)
  {
   
   case 'w':
   my_hero.previousState = my_hero.state ;
   my_hero.state = new Jump;
   my_hero.state->execute(my_hero);
   break;
   case 'a' :
   delete my_hero.state;
   my_hero.state = new Walk;
   my_hero.state->execute(my_hero);
   break;
   default :
   delete my_hero.state;
   my_hero.state = new Run;
   my_hero.state->execute(my_hero);
   break;
  }

 
}



void Jump::execute(hero &my_hero)
{
 std::cout<<"I am Jumping"<<std::endl;

  delete my_hero.state;
  my_hero.state = my_hero.previousState;
  my_hero.previousState = 0;
  my_hero.state->execute(my_hero);
 
}
