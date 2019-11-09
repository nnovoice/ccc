#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
  bool isPossible(int a, int b, int c, int d, int nCharge) {
      int xDiff = c - a;
      int yDiff = d - b;

      xDiff = (xDiff < 0) ? (0 - xDiff) : xDiff;
      yDiff = (yDiff < 0) ? (0 - yDiff) : yDiff;

      int minChargeNeeded = xDiff + yDiff;

      // not enough charge?
      if (nCharge < minChargeNeeded) return false;

      // both are even?
      if (nCharge % 2 == 0 && minChargeNeeded % 2 == 0) return true;

      // both are odd?
      if (nCharge % 2 != 0 && minChargeNeeded % 2 != 0) return true;

      return false;
  }
};

int main() {
    int a = 0, b = 0, c = 0, d = 0, nCharge = 0;
    cin >> a >> b >> c >> d >> nCharge;

    Solution sol;
    bool isPossible = sol.isPossible(a, b, c, d, nCharge);
    char cPos = (isPossible) ? 'Y' : 'N';
    cout << cPos;

    return 0;
}

void t0() {
  int a = 3, b = 4, c = 3, d = 3, nCharge = 3;
  Solution sol;
  bool isPossible = sol.isPossible(a, b, c, d, nCharge);
  assert(isPossible == true);
}
void t1() {
  int a = 10, b = 2, c = 10, d = 4, nCharge = 5;
  Solution sol;
  bool isPossible = sol.isPossible(a, b, c, d, nCharge);
  assert(isPossible == false);
}

int main0() {
  t0();
  return 0;
}
