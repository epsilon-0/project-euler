#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int num){
  int reversed = 0, n = num;
  while(n > 0){
    reversed = reversed*10 + (n % 10);
    n /= 10;
  }
  if(reversed == num)
    return true;
  return false;
}

vector<int> palindrome;

int main() {
  for(int i = 100; i <= 999; i++)
    for(int j = i; j <= 999; j++)
      if(isPalindrome(i*j))
        palindrome.push_back(i*j);
  sort(palindrome.begin(), palindrome.end());
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int pos = palindrome.size() - 1;
    while(palindrome[pos] >= n){
      pos--;
    }
    cout << palindrome[pos] << endl;
  }
}
