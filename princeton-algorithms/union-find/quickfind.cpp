#include <iostream>


class QuickFind{
  // Used to represent the connections between two nodes
  int* unions_;
  // The number of nodes
  int size_;
public:

  // Initialize union-find data structure with N objects (0 to N-1)
  QuickFind(int n): unions_{ new int[n] }, size_{n}
  {
    for(auto i=0; i!=size_; ++i)
      unions_[i] = i;
  }

  ~QuickFind(){ delete[] unions_; }
  
  // Add connection between p and q
  void MakeUnion(int p, int q)
  {
    auto p_root = Root(p);
    auto q_root = Root(q);
    for(auto i=0; i!=size_; ++i){
      if (unions_[i] == p_root)
        unions_[i] = q_root;
    }
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
    return Root(p) == Root(q);
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

  QuickFind qfind = QuickFind(10);

  qfind.MakeUnions({{4, 3},
                    {3, 8},
                    {6, 5},
                    {9, 4},
                    {2, 1}}, 5);
      
  qfind.PrintConnected(0, 7);
  qfind.PrintConnected(8, 9);

  qfind.MakeUnion(5, 0);
  qfind.MakeUnion(6, 7);

  qfind.PrintConnected(0, 7);
  
  return 0;
}
