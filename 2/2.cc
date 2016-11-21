#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--){
    unsigned long long n;
    cin >> n;
    unsigned long long f1 = 1, f2 = 1, ans = 0;
    while(f2 <= n){
      unsigned long long temp = f1 + f2;
      f1 = f2;
      f2 = temp;
      if(f2 % 2 == 0 && f2 <= n)
        ans += f2;
    }

    cout << ans << endl;
  }
}
