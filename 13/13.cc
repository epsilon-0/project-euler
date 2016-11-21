#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  while(n--){
    string str;
    cin >> str;
    long long temp = stoll(str.substr(0, 14));
    ans += temp;
  }
  int length = (int) log10(ans) + 1;
  long long finalAnswer = (long long) ans / pow(10, length - 10);
  printf("%lld\n", finalAnswer);
}
