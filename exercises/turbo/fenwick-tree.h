class FenwickTree {
public:
  long length;

  FenwickTree(long);
  ~FenwickTree();
  void add(long, long);
  long sum(long);
  long sum(long, long);

private:
  long *fenwickTree;
};
