#include <bits/stdc++.h>

using namespace std;

long long factorial(long long n){
  long long prod = 1;
  for(long long i = 2; i <= n; i++)
    prod *= i;
  return prod;
}

vector<int> permutation(const vector<int>& numbers, unsigned int permNumber){

  if(numbers.size() == 1){
    // cout << numbers[0] << " :: ";
    // cout << permNumber << " :: ";
    // cout << numbers[0] << endl;
    return numbers;
  }
  int smallFact = factorial(numbers.size() - 1);

  vector<int> copy = numbers;
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(permNumber <= (i+1)*smallFact){
      copy.erase(copy.begin() + i);
      vector<int> remainingPerm = permutation(copy, permNumber - i*smallFact);
      remainingPerm.insert(remainingPerm.begin(), numbers[i]);
      // cout << smallFact << " ;; ";
      // for(int j : numbers)
      //   cout << j << " ";
      // cout << " :: ";
      // cout << permNumber << " :: ";
      // for(int j : remainingPerm)
      //   cout << j << " ";
      // cout << endl;
      return remainingPerm;
    }
  }
  vector<int> temp;
  return temp;
}

int main() {
  int t;
  cin >> t;

  vector<int> numbers;

  for(int i = 0; i < 13; i++)
    numbers.push_back(i);
  while(t--){
    long long permNumber;
    cin >> permNumber;
    auto answer = permutation(numbers, permNumber);
    for(int i : answer)
      cout << (char) ('a'+i);
    cout << endl;
  }
}
