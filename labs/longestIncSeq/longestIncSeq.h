/*
 * Author: Victor Lells (vicle728)
 * Problem: Longest Increasing Subsequence
 * Time Complexity: Look at individual functions.
 * Use: Include this file.
 */
#include <vector>

/*
 * Function: lie (longest increasing sub sequence)
 *
 * Algo: We go through the sequence elements in order, maintaining the
 * longest increasing subsequence with the smallest largest value at
 * each index. We guarantee that it's the longest increasing
 * subsequence as we always choosen the lowest value possible for a
 * certain subsequence length.
 *
 * Input :
 * - seq: The sequence of numbers.
 * - N: Number of numbers in sequence.
 *
 * Output:
 * - Result vector with the indexes of the increasing
 * subsequence. (Increasing Order)
 *
 * TC: O(N log(N)) as we go through the elements and do a single
 * binary search.
 */
std::vector<long> lis(std::vector<long>, long);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
