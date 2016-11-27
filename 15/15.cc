#include <bits/stdc++.h>

using namespace std;

class Choice{
public:
  Choice(int inputSize, long long modulus):
    maxSize(inputSize),
    MOD(modulus) {
    factorial.resize(maxSize, 1ll);
    inverse.resize(maxSize, 1ll);
    inverseFactorial.resize(maxSize, 1ll);

    for(int i = 2; i < inputSize; i++)
      inverse[i] = MOD - ( ((MOD / i)*inverse[MOD % i] + MOD) % MOD);

    for(int i = 2; i < inputSize; i++){
      factorial[i] = (factorial[i-1] * ((long long) i)) % MOD;
      inverseFactorial[i] = (inverseFactorial[i-1] * inverse[i]) % MOD;
    }
  }

  int choose(int m, int n){
    return (int) ((((factorial[m] * inverseFactorial[n]) % MOD) * inverseFactorial[m-n]) % MOD);
  }

  vector<long long> factorial, inverseFactorial, inverse;
  const int maxSize;
  const long long MOD;
};

int main() {
  Choice chc(10000, (long long) 1e9 + 7);
  int t;
  cin >> t;
  while(t--){
    int m, n;
    cin >> m >> n;
    cout << chc.choose(m+n, n) << endl;
  }
}
