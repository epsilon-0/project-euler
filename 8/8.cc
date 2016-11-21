#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;
    int mMax = -1;
    for(int i = 0; i < n-k; i++){
      int currProd = 1;
      for(int j = 0; j < k; j++)
        currProd *= num[i+j] - '0';
      mMax = max(currProd, mMax);
    }

    cout << mMax << endl;
        
  }
}
