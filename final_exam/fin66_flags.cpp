#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10010

long long way[MAX_N];
long long flags[MAX_N];

void find_sol(int n){
  long long count=0;
  if(n<2 || way[n]!=-1) return;
  if(way[n]==-1) find_sol(n-1);
  for(int i=0;i<=n;i++){
    if(flags[n] > flags[n-i]){
      for(int j=0;j<=n-i;j++){
        if(flags[j] > flags[n-i]){
          count++;
          // cout << "+1 at " << flags[j] << "," << flags[n-i] << "," << flags[n] << endl;
        }
      }
    }
  }
  // cout << n << " " << count << endl;
  way[n] = way[n-1] + count;
  return;
}

int main(){
  int n,change=1;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> flags[i];
    way[i] = -1;
  }
  for(int i=0;i<n-1;i++){
    if(change == 1 && flags[i] < flags[i+1])
      continue;
    else if(change == 0 && flags[i] > flags[i+1])
      continue;
    else
      change--;
  }
  if(change>=0) cout << 0;
  else{
    way[0] = 0;
    way[1] = 0;
    find_sol(n-1);
    // for(int i=0;i<n;i++){
    //   cout << way[i] << " ";
    // }
    cout << way[n-1];
  }
}