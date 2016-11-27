#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE  = 5000006;

int chainSize[MAXSIZE] = {0}, idOfMax[MAXSIZE] = {0};

int collatzChainSize(long long n){
  if(n == 1)
    return 1;
  if(n < MAXSIZE && chainSize[(int) n] != 0){  
    return chainSize[(int) n];
  }
  long long nextNum = (n % 2 == 0)? n/2 : 3*n+1;
  int ans = 1 + collatzChainSize(nextNum);
  if(n < MAXSIZE)
    chainSize[(int) n] = ans;
  return ans;
}

/*
int collatzChainSize(long long n){
  int ans = 1;
  while(n > 1){
    n = (n % 2 == 0)? n/2 : 3*n+1;
    ans++;
  }
  return ans;
}
*/
void init(){
  chainSize[1] = 1;
  for(int i = 2; i < MAXSIZE; i++){
    chainSize[i] = collatzChainSize((long long) i);
  }
}

int main() {
  init();
  idOfMax[1] = 1;
  int mMax = 1;
  int mId = 1;
  for(int i = 2; i < MAXSIZE; i++){
    if(mMax <= chainSize[i]){
      mMax = chainSize[i];
      mId = i;
    }
    idOfMax[i] = mId;
  }
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << idOfMax[n] << endl;
  }
}
