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
    int n;
    cin >> n;
    cout << sv.primes[n-1] << endl;
  }
}
