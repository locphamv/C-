#include <iostream>

using namespace std;

// Recursive function to solve Tower of Hanoi
// n: number of disks to move
// source: the peg we are moving from
// target: the peg we are moving to
// aux: the peg we can use as temporary storage
void hanoi(int n, int source, int target, int aux) {
    // Base case: No disks left to move
    if (n == 0) {
        return;
    }
    
    // Step 1: Move top n-1 disks from source to aux, using target as temporary
    hanoi(n - 1, source, aux, target);
    
    // Step 2: Move the nth (largest) disk from source to target
    cout << source << " " << target << "\n";
    
    // Step 3: Move the n-1 disks from aux to target, using source as temporary
    hanoi(n - 1, aux, target, source);
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        // Calculate and print the total number of moves: (2^n) - 1
        // We use bitwise left shift (1 << n) to calculate 2^n efficiently
        cout << (1 << n) - 1 << "\n";
        
        // Start the recursive process: 
        // Move 'n' disks from peg 1 to peg 3, using peg 2 as auxiliary.
        hanoi(n, 1, 3, 2);
    }
    
    return 0;
}