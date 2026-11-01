/*
 * Problem: Bitwise Operators (HackerRank - C)
 *
 * Task Description:
 * Given a set S = {1, 2, 3, ..., n} and a threshold integer 'k', find the maximum
 * possible values for:
 *   1. a & b (Bitwise AND)
 *   2. a | b (Bitwise OR)
 *   3. a ^ b (Bitwise XOR)
 * for all pairs (a, b) from set S where a < b, such that the result of the bitwise
 * operation is strictly less than 'k'. Print each maximum on a new line.
 *
 * Input Format:
 * A single line containing two space-separated integers, 'n' and 'k'.
 *
 * Constraints:
 * 2 <= n <= 1000
 * 2 <= k <= n
 *
 * Sample Input:
 * 5 4
 *
 * Sample Output:
 * 2
 * 3
 * 3
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/**
 * Function: calculate_the_maximum
 * Iterates through all unique pairs (i, j) where 1 <= i < j <= n, computes their
 * bitwise AND, OR, and XOR values, and tracks the highest result strictly under 'k'.
 */
void calculate_the_maximum(int n, int k) {
    int i, j;
    
    // Trackers for the maximum valid AND (a1), OR (b1), and XOR (c1) values found so far.
    // Initialized to 0 because if no result is less than 'k', 0 must be printed.
    int a1 = 0, b1 = 0, c1 = 0;
    
    // Temporary variables to hold the current pair's bitwise results
    int m1, m2, m3;

    // Outer loop selects the first number 'i' from 1 up to n
    for (i = 1; i <= n; i++) {
        
        // Inner loop starts at 'i + 1' to ensure i < j and avoid duplicate pairs
        for (j = i + 1; j <= n; j++) {
            
            // Perform the three bitwise operations on the pair (i, j)
            m1 = i & j; // Bitwise AND: 1 if both bits are 1
            m2 = i | j; // Bitwise OR:  1 if at least one bit is 1
            m3 = i ^ j; // Bitwise XOR: 1 if the bits are different

            // Update maximum AND if the current result is larger than a1 AND strictly less than k
            if (m1 > a1 && m1 < k) {
                a1 = m1;
            }
            
            // Update maximum OR if the current result is larger than b1 AND strictly less than k
            if (m2 > b1 && m2 < k) {
                b1 = m2;
            }
            
            // Update maximum XOR if the current result is larger than c1 AND strictly less than k
            if (m3 > c1 && m3 < k) {
                c1 = m3;
            }
        }
    }

    // Print the maximum values under 'k' for AND, OR, and XOR on separate lines
    printf("%d\n", a1);
    printf("%d\n", b1);
    printf("%d\n", c1);
}

int main() {
    int n, k;

    // Read upper limit 'n' and threshold 'k'
    scanf("%d %d", &n, &k);
    
    // Compute and display the maximum bitwise results
    calculate_the_maximum(n, k);

    return 0;
}