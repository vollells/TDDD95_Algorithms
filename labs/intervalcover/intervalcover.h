/*
 * Author: Victor Lells (vicle728)
 *
 * Problem: I am solving Interval Cover or the task of covering a
 * certain interval with the fewest intervals from a given set.
 *
 * Time Complexity: Look at individual functions.
 *
 * Use: Compile and run!
 */

#include <vector>

struct interval{
  // Index used for answer.
  int index;
  double start;
  double end;
};

/*
 * Function: less_than overload for struct interval
 *
 * Use: Being able to compare the start times of different intervals!
 *
 * Input :
 * - lhs : Left hand side interval.
 * - rhs : Right hand side interval.
 *
 * Output:
 * - bool: True if lhs start position is earlier than rhs, otherwise
 *   false.
 *
 * TC: Constant
 */
bool operator<(const interval&, const interval&);

/*
 * Function: cover
 *
 * Use: Computes an optimal coverage by greedily selecting a possible
 * interval if it's better than what previously considered
 * optimal. This is done until a non-possible interval with a required
 * specific start point is found or we have no more intervals to consider.
 *
 * Input :
 * - interval_goal : The start and end points which need to be covered.
 * - intervals: vector of possible intervals.
 *
 * Output:
 * - cover: Vector<int> of the interval indices for the optimal
 *    coverage of interval_goal.
 *
 * TC: O(nlog(n))
 */
std::vector<int> cover(interval, std::vector<interval>);


/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
