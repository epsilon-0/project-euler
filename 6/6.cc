#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    long long sumOfSquares = 0;
    long long squareOfSums = 0;
    for(long long i = 1; i <= n; i++){
      sumOfSquares += i*i;
      squareOfSums += i;
    }
    squareOfSums *= squareOfSums;

    cout << squareOfSums - sumOfSquares << endl;
  }
}
