#include <bits/stdc++.h>

using namespace std;

int order[10005], maxOrder[10005];

int main() {
  for (int i = 1; i < 10005; i++) {
    int n = i;
    while (n % 2 == 0)
      n /= 2;
    while (n % 5 == 0)
      n /= 5;
    if (n == 1)
      order[i] = 0;
    else {
      int o = 1;
      int r = 10 % n;
      int s = r;
      while ((r * 10) % n != s) {
        r = (r * 10) % n;
        o++;
      }
      order[i] = o;
    }
  }

  int mMax = 1;
  maxOrder[1] = 1;
  for (int i = 2; i < 10005; i++) {
    if (order[mMax] < order[i]) {
      mMax = i;
    }
    maxOrder[i] = mMax;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << maxOrder[n - 1] << endl;
  }
}
