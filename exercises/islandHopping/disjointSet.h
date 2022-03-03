/*
 * Author: Victor Lells (vicle728)
 *
 * Problem: DisjointSet Data structure.
 *
 * Time Complexity: Look at individual functions.
 *
 * Use: Include disjointSet.cpp at compilation.
 */

#include <vector>

class DisjointSet {
public:
  long length;

  DisjointSet(long);
  ~DisjointSet();
  /*
   * Function: setUnion
   *
   * Use: Goes through the "tree" and finds the root of a and root of
   * b. It then sets the parent of b's root to the root of a. This
   * makes them share the same root and therefore they are in the same
   * set.
   *
   * Input :
   * - a: An element in a set.
   * - b: An element in a set.
   *
   * Output:
   * - void
   *
   * TC: O(log n)
   */
  void setUnion(long, long);
  /*
   * Function: setFind
   *
   * Use: Goes through the "tree" and tries to find the root of the
   * set, this is done by returning iff we reach a node with itself as
   * it's parent. When the root is found we also optimize the "tree"
   * for future operations, this is done by setting every node as the
   * child of the root node.
   *
   * Input :
   * - a : An element in a set.
   *
   * Output:
   * - root: The root node of the set.
   *
   * TC: O(log n)
   */
  long setFind(long);

private:
  std::vector<long> *disjointSet;
};
