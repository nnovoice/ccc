//https://dmoj.ca/problem/ccc16j3
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
private:
  void printPalindrome(int i, int j, string& s) {
    for (; i <= j; ++i) {
      cout << s[i];
    }
    cout << endl;
  }
  bool isPalindrome(int i, int j, string& s) {
    if (i > j) return false;

    for (int k = i, l = j; k != l; k++, --l) {
      if (s[k] != s[l]) return false;
    }

    printPalindrome(i, j, s);
    return true;
  }
public:
  int longestPalindrome(string& s) {
    int maxLen = 1;
    int i = 0, j = s.length() - 1;
    for (int i = 0; i < j; ++i, --j) {
        // if a longer string was found, no need to search more
        if (maxLen > (j - i + 1)) break;

        if (isPalindrome(i, j, s)) {
          maxLen = max(maxLen, j - i + 1);
        } else {
          if (isPalindrome(i + 1, j, s)) {
            maxLen = max(maxLen, j - i);
          } else {
            if (isPalindrome (i, j - 1, s)) {
              maxLen = max(maxLen, j - i);
            }
          }
        }
    }
    return maxLen;
  }
};

int run(string& s) {
  Solution sol;
  int len = sol.longestPalindrome(s);
  cout << s << ":=" << len << endl;
  return (len);
}
void t0() {
  string s = "banana";
  int n = run(s);
  assert(n == 5);
}
void t1() {
  string s = "abracadabra";
  int n = run(s);
  assert(n == 3);
}
void t2() {
  string s = "abracaddabra";
  int n = run(s);
  assert(n == 4);
}
void t3() {
  string s = "panamanap";
  int n = run(s);
  assert(n == 9);
}
void t4() {
  string s = "pa";
  int n = run(s);
  assert(n == 1);
}

int main() {
  t0();
  t1();
  t2();
  t3();
  t4();
  //t5();
  return 0;
}
