#include <bits/stdc++.h>
#define MAX_N 100010
using namespace std;

int banana[MAX_N];
int dp[MAX_N];
int maxb = -1, n;

void findmax(int i){
  if(i < 3) return;
    //if(maxb < score) maxb = score;
  if(dp[i] == -1){
    findmax(i-3);
    findmax(i-4);
    findmax(i-5);
  }
  int a = max(max(dp[i-3], dp[i-4]), dp[i-5]);
  dp[i] = a + banana[i];
}

int main() {
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> banana[i];
    dp[i] = -1;
  }
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = banana[2];
  findmax(n-1);
  findmax(n-2);
  findmax(n-3);
  // for(int i=0;i<n;i++){
  //   cout << dp[i] << "\n";
  // }
  cout << max(max(dp[n-1], dp[n-2]), dp[n-3]);
}