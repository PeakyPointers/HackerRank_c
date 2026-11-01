/*
 * Problem: Printing Pattern Using Loops (HackerRank - C)
 * 
 * Task Description:
 * Given an integer 'n', print a concentric square pattern of numbers from 1 to n,
 * where the outermost border is filled with 'n', the next inner ring is 'n - 1',
 * decreasing down to '1' at the exact center of the grid.
 * Each number in a row must be separated by a single space.
 *
 * Input Format:
 * A single integer, n.
 *
 * Constraints:
 * 1 <= n <= 1000
 *
 * Sample Input:
 * 4
 *
 * Sample Output:
 * 4 4 4 4 4 4 4
 * 4 3 3 3 3 3 4
 * 4 3 2 2 2 3 4
 * 4 3 2 1 2 3 4
 * 4 3 2 2 2 3 4
 * 4 3 3 3 3 3 4
 * 4 4 4 4 4 4 4
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Helper Function: minimal_val
 * Finds and returns the smallest of the four wall distances (Top, Left, Bottom, Right).
 * Uses '<=' to properly handle ties when a cell is equally close to two walls (like corners).
 */
int minimal_val(int Top, int Left, int Bottom, int Right) {
    if (Top <= Left && Top <= Bottom && Top <= Right) {
        return Top;
    }
    else if (Left <= Top && Left <= Bottom && Left <= Right) {
        return Left;
    }
    else if (Bottom <= Left && Bottom <= Top && Bottom <= Right) {
        return Bottom;
    }
    else if (Right <= Left && Right <= Top && Right <= Bottom) {
        return Right;
    }
    else {
        return 0; // Fallback (unreachable since one of the 4 values is always <= the others)
    }
}

int main() 
{
    int i, j, n, size, min_val, top, left, right, bottom, print_val;
    
    // Read the input integer 'n'
    scanf("%d", &n);

    // A pattern that counts from n down to 1 and back up to n has (2*n - 1) rows and columns.
    // Example: For n = 4, size = 2(4) - 1 = 7 (indices 0 to 6).
    size = 2 * n - 1;

    // Outer loop iterates through each row (i) from 0 to size - 1
    for (i = 0; i < size; i++) {
        
        // Inner loop iterates through each column (j) from 0 to size - 1
        for (j = 0; j < size; j++) {
            
            // Calculate how many steps the current cell (i, j) is from all 4 borders.
            // Note: Since indexing starts at 0, the last row/column index is (size - 1), which equals (2*n - 2).
            top    = i;               // Steps from the Top border (Row 0)
            left   = j;               // Steps from the Left border (Col 0)
            bottom = (2 * n - 2) - i; // Steps remaining to reach the Bottom border (Row 2*n - 2)
            right  = (2 * n - 2) - j; // Steps remaining to reach the Right border (Col 2*n - 2)

            // Find the distance to the closest border
            min_val = minimal_val(top, left, bottom, right);

            // Subtract the shortest border distance from 'n' to get the ring's number
            print_val = n - min_val;

            // Print the number followed by a '\t' or single spacing 
            printf("%d ", print_val);
        }
        
        // Move to a new line after finishing each row
        printf("\n");
    }
    
    return 0;
}