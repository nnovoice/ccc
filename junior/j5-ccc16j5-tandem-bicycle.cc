//https://dmoj.ca/problem/ccc16s2 is the same as j5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:

public:
  int getTotalSpeed() {
    const int MAX_N = 100;
    int type = 0, n = 0, a = 0, b = 0;
    vector<int> d(MAX_N, 0);
    vector<int> p(MAX_N, 0);

    cin >> type;
    cin >> n;

//    cout << type << endl;
//    cout << n << endl;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        d[i] = a;
        //cout << d[i] << " ";
    }
    //cout << endl;

    for (int i = 0; i < n; ++i) {
      cin >> b;
      p[i] = b;
      //cout << p[i] << " ";
    }
    //cout << endl;

    sort(d.begin(), d.begin() + n);
    sort(p.begin(), p.begin() + n);

    if (type == 2) {
        reverse(p.begin(), p.begin() + n);
    }

    int totalTime = 0;
    for (int i = 0; i < n; ++i) {
        //cout << "(" << p[i] << "," << d[i] << ")  ";
        totalTime += max(p[i], d[i]);
    }
    //cout << endl;

    return totalTime;
  }
};

int main() {
  Solution sol;
  cout << sol.getTotalSpeed();
  return 0;
}
