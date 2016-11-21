#include <bits/stdc++.h>

using namespace std;

int chainSize[5000006] = {0};

int preCompute(int i){
  if(i == 1){
    chainSize[1] = 1;
    return 1;
  }

  int nextNum = ((i % 2 == 0)? i/2 : 3*i + 1);
  if(i > 5000006){
    return 1 + preCompute(nextNum);
  }
  else if( i < 5000006 && chainSize[i] == 0){
    preCompute(nextNum);
    chainSize[i] = chainSize[nextNum] + 1;
  }
  return chainSize[i];
}

void init(){
  for(int i = 1; i < 5000006; i++){
    chainSize[i] = preCompute(i);
    cout << i << endl;
  }
}

int main() {
  preCompute(4255);
  init();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
  }
}
