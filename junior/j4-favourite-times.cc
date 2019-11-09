#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> seqVector;
private:
  bool isSeq(int a, int b, int c, int d) {
    if (a == 1 && b > 2) return false;
    if (a == 0) {
        if (b == c && c == d) return true;
        if (c - b == d - c) return true;
    } else {
      if (a == b && b == c && c == d) return true;
      if ((b - a == c - b) && (c - b == d - c)) return true;
    }
    return false;
  }

  void generateArithmeticSequences() {
    int nSeq = 0;
    int a = 0, b = 0, c = 0, d = 0;
    for (a = 0; a < 2; ++a) {
      for (b = 1; b < 10; ++b) {
        for (c = 0; c < 6; ++c) {
          for (d = 0; d < 10; ++d) {
            if (isSeq(a, b, c, d) == true) {
              nSeq += 1;
              int min = (a * 10 + b) * 60 + (c * 10) + d;
              if (a == 1 && b == 2) {
                min = c * 10 + d;
              }
              cout << "seq= " << a << b << ":" << c << d << " minutes=" << min << " nSeq=" << nSeq << endl;
              seqVector.push_back(min);
            }
          }
        }
      }
    }
  }

  int numTimesHelper(int D) {
    int nTimes = 0;
    for (int i = 0; i < seqVector.size(); ++i) {
      if (seqVector[i] > D) {
        break;
      }
      nTimes += 1;
    }
    return nTimes;
  }

public:
  int numTimes(int D) {
    generateArithmeticSequences();
    sort(seqVector.begin(), seqVector.end());
    return numTimesHelper(D);
  }
};

void test0() {
  Solution s;
  int n = s.numTimes(33);
  assert(n == 0);
}

void test1() {
  Solution s;
  int n = s.numTimes(34);
  assert(n == 1);
}

void test2() {
  Solution s;
  int n = s.numTimes(180);
  assert(n == 11);
}

void test3() {
  Solution s;
  int n = s.numTimes(671);
  cout << "test3=" << n << endl;
  assert(n == 31);
}

void test4() {
  Solution s;
  int n = s.numTimes(6710);
  cout << "test4=" << n << endl;
  assert(n == 31);
}

int main() {
  test0();
  test1();
  test2();
  test3();
  test4();
  return 0;
}
