#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--){
    int p;
    cin >> p;
    int mMax = -1;
    for(int a = 1; a < p; a++){
      int num = p*p - 2*a*p, den = 2*(p - a);
      if(num > 0 && num % den == 0){
        int b = num/den;
        int c = p - a - b;
        if(a + b > c && a*a + b*b == c*c && c > 0)
          mMax = max(a*b*c, mMax);
      }
    }
    cout << mMax << endl;
  }
}
