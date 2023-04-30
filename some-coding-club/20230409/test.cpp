#include <iostream>
using namespace std;

template<int size>
struct ConstArray{
  int arr[size];

  // 'constexpr' constructor:
  constexpr ConstArray():arr(){
    for(int i = 0; i < size; i++)
      arr[i] = i;
  }

  constexpr ConstArray(initializer_list<initializer_list<int>> init):arr(){
    static_assert(init.size() == size);
    for(int i = 0; i < size; i++)
      arr[i] = init.begin()[i].begin()[0];
  }

  // This member function should have 'const':
  void print() const{
    for(int i = 0; i < size; i++)
      cout << arr[i] << endl;
  }
};

int main() {
  constexpr int n = 2;
  constexpr ConstArray arr = ConstArray<n>{{{1,1}, {2,2}}};
  arr.print();

  return 0;
}