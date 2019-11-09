#include <iostream>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
private:
  unordered_map<int,int> seqMap;
private:
  void generateArithmeticSequences() {
    int a = 0, b = 0, c = 0, d = 0;
    for (a = 0; a < 2; ++a) {
      for (b = 1; b < 3; ++b) {
        for (c = 0; c < 6; ++c) {
          for (d = 0; d < 10; ++d) {
            if (a == 0) {
                if (b == c == d) {
                  
                }
            } else {
              if (a == b == c == d) {

              } else if (a < b < c < d) {

              } else if (a > b > c > d) {

              }
            }
          }
        }
      }
    }
  }
public:
  int numTimes(int D) {
    cout << "Hello, World";
    return 0;
  }

};

void test0() {
  Solution s;
  int n = s.numTimes(34);
  assert(n == 1);
}

int main() {
  test0();
}
