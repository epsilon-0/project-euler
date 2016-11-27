#include <bits/stdc++.h>

using namespace std;

int rowNumber[40005] = {0};
long long nums[40005] = {0};
long long maxPossible[40005] = {0};

int main() {
  int pos = 1;
  for(int i = 1; i < 105; i++)
    for(int j = 0; j < i; j++)
      rowNumber[pos++] = i;

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int totalNums = n*(n+1)/2;
    for(int i = 1; i <= totalNums; i++){
      cin >> nums[i];
      maxPossible[i] = 0;
    }

    maxPossible[1] = nums[1];
    for(int i = 1; i <= totalNums; i++){
      int child1 = i + rowNumber[i];
      int child2 = child1 + 1;
      maxPossible[child1] = max(maxPossible[child1], maxPossible[i] + nums[child1]);
      maxPossible[child2] = max(maxPossible[child2], maxPossible[i] + nums[child2]);
    }
    cout << *max_element(maxPossible + 1, maxPossible + totalNums + 1) << endl;
  }
}
