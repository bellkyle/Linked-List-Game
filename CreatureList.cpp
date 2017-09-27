#include "CreatureList.h"
#include <stdlib.h>

//-----------------------------------------------------------
//constructor
CreatureList::CreatureList()
{
   if (DEBUG) cout << "list constructor\n";
   //head needs to start at NULL
   head = NULL;
   count = 0;
}

//-----------------------------------------------------------
//destructor
CreatureList::~CreatureList()
{
   // Walk list to delete nodes
   if (DEBUG) cout << "list destructor\n";
   CreatureNode *next;
   CreatureNode *curr = head;
   //while loop to delete all the nodes in the list
   while(curr != NULL)
   {
      next = curr->getNext();
      delete curr;
      curr = next;
   }
}

//-----------------------------------------------------------
//method to spawn creatures in a random location
void CreatureList::spawn_creature() // Add parameters
{
   // Insert new node at head of list
   if (DEBUG) cout << "spawn creature\n";
   CreatureNode * ptr = new CreatureNode;
   //random number generator for x position
   int random = rand() % Xmax - Xmin;
   ptr->setXposition(random);
   //random number generator for y position
   random = rand() % Ymax - Ymin;
   ptr->setYposition(random);
   //random number generator for x velocity
   random = rand() % 20 + (-10);
   ptr->setXvelocity(random);
   //random number generator for y velocity
   random = rand() % 20 + (-10);
   ptr->setYvelocity(random);
   //ID set to current count number
   ptr->setID(count);
   //inserting the new node at the head
   ptr->setNext(head);
   head = ptr;
   count++;
}

//-----------------------------------------------------------
//method to kill random creatures
void CreatureList::kill_creature(int ID) // Add parameters
{
   // Walk list to find node
   if (DEBUG) cout << "kill creature\n";
   CreatureNode *curr = head;
   CreatureNode *prev = head;
   //while loop to get the node with the matching ID
   while((curr != NULL) && (curr->getID() != ID))
   {
      prev = curr;
      curr = curr->getNext();
   }
   /*if statement to make sure curr it not null
     if it is NULL then it would mess up the whole list
     if it went through the following if statements*/
   if(curr != NULL)
   {
      //if else statement to delete a node from the list
      if(curr == head)
         head = curr->getNext();
      else
         prev->setNext(curr->getNext());
      count--;
   }
   //delete curr
   delete curr;
}

//-----------------------------------------------------------
//method to blast creatures
void CreatureList::blast_creatures() // Add parameters
{
   // Walk list to blast creatures
   if (DEBUG) cout << "blast creatures\n";
   CreatureNode *curr = head;
   CreatureNode *prev = head;
   //distance variable
   int distance;
   //blast radius
   int blastRadius = 40;
   //Xrandom and Yrandom is the blast point
   int Xrandom = rand() % Xmax - Xmin;
   int Yrandom = rand() % Ymax - Ymin;
   while(curr != NULL)
   {
      //calculate the distance with the distance formula
      distance = sqrt(pow((Xrandom - (curr->getXposition())), 2)
                   + pow((Yrandom - (curr->getYposition())), 2));
      //if statement to lower the health of creature based on location
      if(distance <= (blastRadius/4))
         curr->setHealth(0);
      else if(distance > (blastRadius/4) && distance <= (blastRadius/2))
      {
         int health = (curr->getHealth()) - 50;
         curr->setHealth(health);
      }
      else if(distance > (blastRadius/2) && distance <= blastRadius)
      {
         int health = (curr->getHealth()) - 25;
         curr->setHealth(health);
      }
      //if statement to tell if the creatures health is a 0
      if(curr->getHealth() <= 0)
      {
         //if the health is a 0 then the creature dies and is deleted
         if(curr == head)
            head = curr->getNext();
         else
            prev->setNext(curr->getNext());
         delete curr;
         curr = prev->getNext();
         count--;
      }
      //if health is not zero we go to the next creature
      else
      {
         prev = curr;
         curr = curr->getNext();
      }
   }

}

//-----------------------------------------------------------
//method to move creatures based on the velocity
void CreatureList::move_creatures() // Add parameters
{
   // Walk list to move creatures
   if (DEBUG) cout << "move creatures\n";
   CreatureNode *ptr = head;
   while(ptr != NULL)
   {
      //add the velocity to the position
      ptr->setXposition(ptr->getXposition() + ptr->getXvelocity());
      ptr->setYposition(ptr->getYposition() + ptr->getYvelocity());
      //if the creature reaches the boundary it stops there
      if(ptr->getXposition() < Xmin)
         ptr->setXposition(Xmin);
      else if(ptr->getXposition() > Xmax)
         ptr->setXposition(Xmax);
      else if(ptr->getYposition() < Ymin)
         ptr->setYposition(Ymin);
      else if(ptr->getYposition() > Ymax)
         ptr->setYposition(Ymax);
      ptr = ptr->getNext();
   }
}

//-----------------------------------------------------------
//print method
void CreatureList::print_creatures() const
{
   // Walk list to print creatures
   if (DEBUG) cout << "print creatures\n";
   CreatureNode * ptr = head;
   cout << "The number of creatures is " << count << endl;
   //walking the list to print the creatures
   while(ptr != NULL)
   {
      ptr->print();
      ptr = ptr->getNext();
   }
}
