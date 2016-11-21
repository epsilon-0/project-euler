#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    long long n;
    cin >> n;
    n--;
    long long max3 = n/3, max5 = n/5, max15 = n/15;
    long long res = (max3*(max3+1)*3)/2 + (max5*(max5+1)*5)/2 - (max15*(max15+1)*15)/2;
    cout << res << endl;
  }
}