#include <bits/stdc++.h>

using namespace std;

int scoreOfName(string name){
  int score = 0;
  for(char c : name)
    score += c - 'A' + 1;
  return score;
}

int main() {
  int n;
  cin >> n;
  vector<string> names;
  while(n--){
    string name;
    cin >> name;
    names.push_back(name);
  }
  sort(names.begin(), names.end());
  map<string, int> scores;
  for(int i = 0; i < names.size(); i++){
    scores[names[i]] = (i+1) * scoreOfName(names[i]);
  }
  int q;
  cin >> q;
  while(q--){
    string name;
    cin >> name;
    cout << scores[name] << endl;
  }
}
