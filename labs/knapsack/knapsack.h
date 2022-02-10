/*
 * Author: Victor Lells (vicle728)
 *
 * Problem: Knapsack
 *
 * Time Complexity: Look at individual functions.
 *
 * Use: Compile and run!
 */

#include <vector>

struct Item{
  // Index used for answer.
  int w;
  int v;
  Item(int iW, int iV);
};

/*
 * Function: Knapsack
 *
 * Use: Generates a 2D array of all possible situations depending on
 * the weight and value of items as well as the capacity of the
 * knapsack. We then traverse backwards from the optimal solution at
 * v[numberOfItems][capacity] until we have "Emptied" the knapsack.
 *
 * Input :
 * - c : Knapsack Capacity.
 * - items : Items to fill the knapsack with.
 * - result : Result output.
 *
 * Output:
 * - result: The indices of the items in the optimal solution.
 *
 * TC: O(capacity*numberOfItems)
 */
void knapsack(int, std::vector<Item>*, int, std::vector<int>*);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
