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

int main() {
  Seive sv(1000006);
  int t;
  cin >> t;
  while(t--){
    long long n;
    cin >> n;
    long long maxFactor = 1;
    for(int p : sv.primes){
      if(n % p == 0){
        maxFactor = (long long) p;
        while(n % p == 0)
          n = (long long) n/p;
      }
    }
    maxFactor = max(n, maxFactor);
    cout << maxFactor << endl;
  }
}
