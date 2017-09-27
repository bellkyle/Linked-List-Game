#include "CreatureNode.h"

//-----------------------------------------------------------
//constructor
CreatureNode::CreatureNode()
{
   if (DEBUG) cout << "node constructor\n";
   ID = 0;
   Xposition = 0;
   Yposition = 0;
   Xvelocity = 0.0;
   Yvelocity = 0.0;
   health = 100;
   strength = 100;
   //setting next to NULL so it will work properly
   next = NULL;
}

//-----------------------------------------------------------
//destructor
CreatureNode::~CreatureNode()
{
   if (DEBUG) cout << "node destructor\n";
}

//-----------------------------------------------------------
//general set for all of the variables
void CreatureNode::set(const int identity, const  int Xpos, const  int Ypos,
                       const float Xvel, const float Yvel, const int creatureHealth,
                       const int creatureStrength) // Add parameters
{
   ID = identity;
   Xposition = Xpos;
   Yposition = Ypos;
   Xvelocity = Xvel;
   Yvelocity = Yvel;
   health = creatureHealth;
   strength = creatureStrength;
}

//setter for ID
void CreatureNode::setID(const int identity)
{
   ID = identity;
}

//setter for x position
void CreatureNode::setXposition(const  int Xpos)
{
   Xposition = Xpos;
}

//setter for y position
void CreatureNode::setYposition(const  int Ypos)
{
   Yposition = Ypos;
}

//setter for x velocity
void CreatureNode::setXvelocity(const float Xvel)
{
   Xvelocity = Xvel;
}

//setter for y velocity
void CreatureNode::setYvelocity(const float Yvel)
{
   Yvelocity = Yvel;
}

//setter for health
void CreatureNode::setHealth(const int creatureHealth)
{
   health = creatureHealth;
}

//setter for strength
void CreatureNode::setStrength(const int creatureStrength)
{
   strength = creatureStrength;
}

//setter for the next pointer
void CreatureNode::setNext(CreatureNode* ptr)
{
   next = ptr;
}
//-----------------------------------------------------------
float CreatureNode::get() const
{
   return 0.0;
}

//getter for ID
int CreatureNode::getID() const
{
   return ID;
}

//getter for x position
int CreatureNode::getXposition() const
{
   return Xposition;
}

//getter for y position
int CreatureNode::getYposition() const
{
   return Yposition;
}

//getter for x velocity
float CreatureNode::getXvelocity() const
{
   return Xvelocity;
}

//getter for y velocity
float CreatureNode::getYvelocity() const
{
   return Yvelocity;
}

//getter for health
int CreatureNode::getHealth() const
{
   return health;
}

//getter for strength
int CreatureNode::getStrength() const
{
   return strength;
}

//getter for next pointer
CreatureNode* CreatureNode::getNext() const
{
   return next;
}

//-----------------------------------------------------------
//print method
void CreatureNode::print() const
{
   cout << "ID: " << ID;
   cout << " Xposition: " << Xposition;
   cout << " Yposition: " << Yposition;
   cout << " Xvelocity: " << Xvelocity;
   cout << " Yvelocity: " << Yvelocity;
   cout << " Health: " << health;
   cout << " Strength: " << strength << endl;
}
