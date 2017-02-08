#include <bits/stdc++.h>

using namespace std;

const int MAXN = 29000;

int factor[MAXN], sumOfFactors[MAXN];

int main() {
  for(int i = 0; i < MAXN; i++)
    factor[i] = sumOfFactors[i] = -1;
  factor[0] = factor[1] = 1;
  for(int i = 2; i < sqrt(MAXN) + 5; i++)
    if(factor[i] == -1)
      for(int j = i*i; j < MAXN; j += i)
        if(factor[j] == -1)
          factor[j] = i;
  
  sumOfFactors[0] = 0; sumOfFactors[1] = 1;
  for(int i = 2; i < MAXN; i++)
    if(factor[i] == -1)
      sumOfFactors[i] = i+1;
    else{
      int prod = 1;
      int sum = 1;
      int kkk = i;
      while(kkk % factor[i] == 0){
        prod *= factor[i];
        sum += prod;
        kkk /= factor[i];
      }

      sumOfFactors[i] = sum * sumOfFactors[kkk];
    }

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n > 28123){
      cout << "YES\n";
      continue;
    }
    bool isSum = false;
    for(int i = 1; i < n; i++)
      if(factor[i] != -1 && sumOfFactors[i] > 2*i && sumOfFactors[n-i] > 2*(n-i)){
        isSum = true;
        break;
      }
    if(isSum)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  
}
