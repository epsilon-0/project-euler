#include <bits/stdc++.h>

using namespace std;

vector<int> topologicalSort(vector<vector<int> >& adj){
  priority_queue<int, vector<int>, greater<int> > heap;
  vector<int> indeg(adj.size(), 0);
  for(unsigned int i = 0; i < adj.size(); i++)
    for(int neighbour : adj[i])
      indeg[neighbour]++;
  for(unsigned int i = 0; i < adj.size(); i++){
    if(indeg[i] == 0){
      heap.push(i);
    }
  }
  vector<int> order;
  while(!heap.empty()){
    int next = heap.top();
    heap.pop();
    order.push_back(next);
    for(int neighbour : adj[next]){
      indeg[neighbour]--;
      if(indeg[neighbour] == 0){
        heap.push(neighbour);
      }
    }
  }
  if(order.size() != adj.size())
    order.clear();
  return order;
}

vector<vector<int> > adj;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  adj.resize(200);
  set<int> chars;
  for(int i = 0; i < t; i++){
    string c;
    cin >> c;
    adj[c[0]-'!'].push_back(c[1]-'!');
    adj[c[1]-'!'].push_back(c[2]-'!');
    chars.insert(c[0]-'!');
    chars.insert(c[1]-'!');
    chars.insert(c[2]-'!');
  }
  auto order = topologicalSort(adj);
  if(order.empty()){
    cout << "SMTH WRONG\n";
  }
  else{
    for(unsigned int i : order)
    if(chars.count(i) > 0)
      cout << (char) ('!' + i);
    cout << endl;
  }
}
