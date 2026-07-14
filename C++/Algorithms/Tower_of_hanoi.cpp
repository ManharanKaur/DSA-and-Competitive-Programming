// Tower of Hanoi: A classic problem in computer science and mathematics.
// The problem is to move a stack of disks from one peg to another, subject to the following rules:
// 1. Only one disk can be moved at a time.
// 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty peg.
// 3. No disk may be placed on top of a smaller disk.
// How Algorithm work

#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi
// n      : Number of disks
// source : Starting rod
// helper : Auxiliary rod
// dest   : Destination rod
void towerOfHanoi(int n, char source, char helper, char dest)
{

    // Base case:
    // If there is only one disk, move it directly.
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }

    // Step 1:
    // Move the top (n-1) disks from source to helper,
    // using destination as the auxiliary rod.
    towerOfHanoi(n - 1, source, dest, helper);

    // Step 2:
    // Move the largest disk to destination.
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;

    // Step 3:
    // Move the (n-1) disks from helper to destination,
    // using source as the auxiliary rod.
    towerOfHanoi(n - 1, helper, source, dest);
}

int main()
{
    int n;
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}