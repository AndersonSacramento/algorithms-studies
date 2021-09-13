#include <iostream>


class QuickUnion{
  // Used to represent the connections between two nodes
  int* unions_;
  // The number of nodes
  int size_;
public:

  // Initialize union-find data structure with N objects (0 to N-1)
  QuickUnion(int n): unions_{ new int[n] }, size_{n}
  {
    for(auto i=0; i!=size_; ++i)
      unions_[i] = i;
  }

  ~QuickUnion(){ delete[] unions_; }

  // Add connection between p and q
  void MakeUnion(int p, int q)
  {
    unions_[p] = q;
  }

  // Apply MakeUnion over an array of connections limited by n connection operations
  void MakeUnions(const int (&nodes)[][2], int n)
  {
    for(auto i=0; i!=n; ++i)
      MakeUnion(nodes[i][0], nodes[i][1]);
  }

  // Return the root of node p
  int Root(int p)
  {
    return unions_[p];
  }

  // Are p and q in the same component?
  bool Connected(int p, int q)
  {
    int q_root = Root(q);
    while(q != q_root){
      if(q_root == p)
        return true;
      q = q_root;
      q_root = Root(q);
    }
    return false;
  }

  // Print status of connection between nodes p and q
  void PrintConnected(int p, int q)
  {
    std::cout << "connected(" << p <<", "<< q <<") ? "
              << (Connected(p, q)? "true" : "false")
              << std::endl;  
  }
};



int main(){

  QuickUnion qunion = QuickUnion(10);

  qunion.MakeUnions({{4, 3},
                     {3, 8},
                     {6, 5},
                     {9, 4},
                     {2, 1}}, 5);
      
  qunion.PrintConnected(0, 7);
  qunion.PrintConnected(8, 9);

  
  return 0;
}
