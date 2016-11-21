#include <bits/stdc++.h>

using namespace std;

long long primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
long long power[12];
int main() {
  int t;
  cin >> t;
  while(t--){
    memset(power, 0, sizeof(power));
    long long ans = 1;
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
      long long num = i;
      for(int j = 0; j < 12; j++){
        long long pp = 0;
        while(num % primes[j] == 0){
          pp++;
          num /= primes[j];
        }
        power[j] = max(pp, power[j]);
      }
    }
    for(int i = 0; i < 12; i++)
      ans *= (long long) pow(primes[i], power[i]);

    cout << ans << endl;
  }
}
