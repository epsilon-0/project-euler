#include <bits/stdc++.h>

using namespace std;

int nums[26][26] = {0};

int main() {
  for(int i = 0; i < 20; i++)
    for(int j = 0; j < 20; j++)
      cin >> nums[i+3][j+3];

  int mMax = -1;
  for(int i = 3; i < 23; i++)
    for(int j = 2; j < 23; j++)
      mMax = max(mMax, 
                 max( nums[i][j]*nums[i+1][j]*nums[i+2][j]*nums[i+3][j],
                     max( nums[i][j]*nums[i][j+1]*nums[i][j+2]*nums[i][j+3],
                         max( nums[i][j]*nums[i+1][j+1]*nums[i+2][j+2]*nums[i+3][j+3],
                              nums[i][j]*nums[i+1][j-1]*nums[i+2][j-2]*nums[i+3][j-3] ))));

  cout << mMax << endl;
}
