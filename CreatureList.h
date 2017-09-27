
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "CreatureNode.h"
using namespace std;

#ifndef CREATURE_LIST_H
#define CREATURE_LIST_H

class CreatureList
{
public:
   // Constructor methods
   CreatureList();
   ~CreatureList();

   // Other methods
   void spawn_creature();  // Add parameters
   void kill_creature(int ID);   // Add parameters
   void blast_creatures(); // Add parameters
   void move_creatures();  // Add parameters
   void print_creatures() const;

private:
   // Debugging flag
   static const bool DEBUG = false;

   // Object attributes
   static const int Xmin = 0;
   static const int Xmax = 200;
   static const int Ymin = 0;
   static const int Ymax = 200;
   int count;
   CreatureNode *head;
};
#endif
