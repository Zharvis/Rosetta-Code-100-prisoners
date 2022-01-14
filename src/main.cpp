/*
The Problem
100 prisoners are individually numbered 1 to 100
A room having a cupboard of 100 opaque drawers numbered 1 to 100, that cannot be seen from outside.
Cards numbered 1 to 100 are placed randomly, one to a drawer, and the drawers all closed; at the start.
Prisoners start outside the room
They can decide some strategy before any enter the room.
Prisoners enter the room one by one, can open a drawer, inspect the card number in the drawer, then close the drawer.
A prisoner can open no more than 50 drawers.
A prisoner tries to find his own number.
A prisoner finding his own number is then held apart from the others.
If all 100 prisoners find their own numbers then they will all be pardoned. If any don't then all sentences stand.

The task
Simulate several thousand instances of the game where the prisoners randomly open drawers
Simulate several thousand instances of the game where the prisoners use the optimal strategy mentioned in the Wikipedia article, of:
First opening the drawer whose outside number is his prisoner number.
If the card within has his number then he succeeds otherwise he opens the drawer with the same number as that of the revealed card. (until he opens his maximum).

Show and compare the computed probabilities of success for the two strategies, here, on this page.
http://rosettacode.org/wiki/100_prisoners
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Drawer
{
    int prisonerId = -1;
};


int main()
{
    // creating array of prisoners with their numbers 
    unsigned const int numPrisoners = 100;
    unsigned int prisoners[numPrisoners];
    for (unsigned int i = 0; i < numPrisoners; i++)
    {
        prisoners[i] = i;
    }

    Drawer drawers[numPrisoners];
    srand(time(NULL));
    for (size_t i = 0; i < numPrisoners; i++)
    {
        while (drawers[i].prisonerId == -1)
        {
            unsigned int temp = rand() % numPrisoners;
            bool isAlreadyInDrawer = false;
            for (int j = 0; j < i; j++)
            {
                if (temp == drawers[j].prisonerId)
                {
                    isAlreadyInDrawer == true;
                }
            }
            if (!isAlreadyInDrawer)
            {
                drawers[i].prisonerId = temp;
            }
        }
    }
    
    for (size_t i = 0; i < numPrisoners; i++)
    {
        std::cout << drawers[i].prisonerId << ' ';
    }
    
    
}
