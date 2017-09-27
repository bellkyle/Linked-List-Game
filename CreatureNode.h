#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifndef CREATURE_NODE_H
#define CREATURE_NODE_H

class CreatureNode
{
public:
   // Constructor methods
   CreatureNode();
   ~CreatureNode();

   // Set methods
   void set(const int identity, const int Xpos, const int Ypos,
            const float Xvel, const float Yvel, const int creatureHealth,
            const int creatureStrength);  // Add parameters
   void setID(const int identity);
   void setXposition(const int Xpos);
   void setYposition(const int Ypos);
   void setXvelocity(const float Xvel);
   void setYvelocity(const float Yvel);
   void setHealth(const int creatureHealth);
   void setStrength(const int creatureStrength);
   void setNext(CreatureNode* ptr);

   // Get methods
   float get() const;
   int getID() const;
   int getXposition() const;
   int getYposition() const;
   float getXvelocity() const;
   float getYvelocity() const;
   int getHealth() const;
   int getStrength() const;
   CreatureNode* getNext() const;

   // Other methods
   void print() const;

private:
   // Debugging flag
   static const bool DEBUG = false;

   // Object attributes
   int ID;
   int Xposition;
   int Yposition;
   float Xvelocity, Yvelocity;
   int health;
   int strength;
   CreatureNode * next;
};
#endif
