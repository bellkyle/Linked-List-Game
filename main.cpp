
#include <cstdlib>
#include "CreatureNode.h"
#include "CreatureList.h"

int main()
{
   // Variables
   CreatureList list;
   int count = 0;
   int number = 0;

   // Spawn some random creatures
   cout << "\nTesting spawn_creature method\n";
   cout << "Enter number of creatures to spawn: ";
   cin >> count;
   for (int i=0; i<count; i++)
   {
      list.spawn_creature(); // Add parameters
   }
   list.print_creatures();

   // Blast some random creatures
   cout << "\nTesting blast_creatures method\n";
   cout << "Enter number of blasts to simulate: ";
   cin >> number;
   for (int i=0; i<number; i++)
   {
      list.blast_creatures(); // Add parameters
   }
   list.print_creatures();

   // Kill some random creatures
   cout << "\nTesting kill_creatures method\n";
   cout << "Enter number of creatures to kill: ";
   cin >> number;
   int ID;
   for (int i=0; i<number; i++)
   {
      //random number generator to generate a random ID
      ID = rand() % count;
      list.kill_creature(ID); // Add parameters
   }
   list.print_creatures();

   // Move some random creatures
   cout << "\nTesting move_creatures method\n";
   cout << "Enter number of movements to simulate: ";
   cin >> number;
   for (int i=0; i<number; i++)
   {
      list.move_creatures(); // Add parameters
   }
   list.print_creatures();
}
