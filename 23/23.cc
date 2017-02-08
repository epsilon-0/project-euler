#include <bits/stdc++.h>

using namespace std;

int factor[100005], sumOfFactors[100005];

int main() {
  for(int i = 0; i < 100005; i++)
    factor[i] = sumOfFactors[i] = -1;
  factor[0] = factor[1] = 1;
  for(int i = 2; i < sqrt(100005) + 5; i++)
    if(factor[i] == -1)
      for(int j = i*i; j < 100005; j += i)
        if(factor[j] == -1)
          factor[j] = i;
  
  sumOfFactors[0] = 0; sumOfFactors[1] = 1;
  for(int i = 2; i < 100005; i++)
    if(factor[i] == -1)
      sumOfFactors[i] = 1;
    else
      sumOfFactors[i] = factor[i]*(sumOfFactors[i/factor[i]]);

  for(int i = 0; i < 100; i++)
    cout << i << " " << sumOfFactors[i] << endl;

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    bool isSum = false;
    for(int i = 1; i < n; i++)
      if(factor[i] != -1 && sumOfFactors[i] > i && sumOfFactors[n-i] > n-i){
        isSum = true;
        break;
      }
    if(isSum)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  
}
