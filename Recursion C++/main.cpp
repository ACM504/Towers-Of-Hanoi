//
//  main.cpp
//  Recursion C++
//
//  Created by Alkia Mitchell on 3/29/15.
//  Copyright (c) 2015 Alkia Mitchell. All rights reserved.
//

#include <iostream>
using namespace std;

// n refers to the maximum number of disks we wish to move.
// from is the tower where the disks currently exist.
// to is the tower we want the disks to be moved to.
// other is the tower that temporally stores towers. This is necessary in order for us to shuffle disks
        //around without violating the rules.


void TowerOfHanoi(int n, int from, int to, int other)
{
    //This is our standard termination case. We get to here when we are operating on the
    //smallest possible disk.   
    if(n == 1)
    {
        std::cout << "Move disk " << n << " from tower " << from << " to tower " << to << endl;
    }
    else
    {
        //Move all disks smaller than this one over to the other.
        //We are now using the to tower as the other tower. This causes each recursion to ping-pong
        //the spare and dest towers.
        TowerOfHanoi(n - 1, from, other, to);
        
        //Move the remaining disk to the to tower.
        std::cout << "Move disk "  << n << " from tower " << from << " to tower " << to << endl;
        
        //Move the disks we just moved to the other back over to the to tower.
        TowerOfHanoi(n - 1, other, to, from);
    }
}

int main(int argc, const char * argv[])
{
    int n;
    cout << "Enter the number of discs: ";
    cin >> n;
    TowerOfHanoi(n, 1, 3, 2);
    return 0;
}

