#include <bits/stdc++.h>

using namespace std;

class Seive{
public:
  Seive(int inputSize) : 
      maxSize(inputSize)
   {
    isComposite.resize(inputSize, false);
    isComposite[0] = isComposite[1] = true;
    for(int i = 2; i < sqrt(maxSize) + 1 && i < maxSize; i ++)
      if(!isComposite[i]){
        for(int j = i*i; j < maxSize; j += i)
          isComposite[j] = true;
      }
    for(int i = 2; i < maxSize; i++)
      if(!isComposite[i])
        primes.push_back(i);
  }

  int maxSize;
  vector<bool> isComposite;
  vector<int> primes;
};

Seive sv(sqrt(42000) + 2);

int numFactors[42000] = {0};

int main() {
  int t;
  cin >> t;
  numFactors[1] = 1;
  for(int i = 2; i < 42000; i++){
    int triangle = i*(i+1)/2;
    int ans = 1;
    for(int p : sv.primes){
      int power = 0;
      while(triangle % p == 0 && triangle > 0){
        triangle /= p;
        power++;
      }
      ans *= power + 1;
    }
    if(triangle > 1)
      ans *= 2;
    numFactors[i] = ans;
  }
  while(t--){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i < 42000; i++){
      if(numFactors[i] > n){
        ans = i;
        break;
      }
    }
    cout << ans*(ans+1)/2 << endl;
  }
}
