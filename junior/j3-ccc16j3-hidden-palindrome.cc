//https://dmoj.ca/problem/ccc16j3
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
private:
  void printString(int i, int j, string& s) {
    for (; i <= j; ++i) {
      //cout << s[i];
    }
    //cout << endl;
  }
  bool isPalindrome(int i, int j, string& s) {
    if (i > j) return false;
    //cout << "isPalindrome=?" << i << ":" << j << " ";
    printString(i, j, s);
    for (int k = i, l = j; k < l; k++, --l) {
      if (s[k] != s[l]) return false;
    }

    //cout << "isPalindrome= :-) ";
    printString(i, j, s);
    return true;
  }
public:
  int longestPalindrome(string& s) {
    int count = 0;
    int maxLen = 1;

    for (int i = 0; i < s.length(); ++i) {
      for (int j = s.length() - 1; i < j; --j) {
        // if a longer string was found, no need to search more
        if (maxLen > (j - i + 1)) break;
        //cout << count << " ";
        count += 1;
        if (isPalindrome(i, j, s)) {
          maxLen = max(maxLen, j - i + 1);
        }
      }
    }
    return maxLen;
  }
};

int run(string& s) {
  Solution sol;
  int len = sol.longestPalindrome(s);
  //cout << s << ":=" << len << endl;
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
void t5() {
  string s = "abcdefghijklmnopqrstuvwxyz0123456789dcba";
  int n = run(s);
  assert(n == 1);
}

int main() {
  // t0();
  // t1();
  // t2();
  // t3();
  // t4();
  // t5();

  string s;
  cin >> s;
  Solution sol;
  cout << sol.longestPalindrome(s);
  return 0;
}
