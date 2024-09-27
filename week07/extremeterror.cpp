#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000010

long long boss[MAX_N];
long long business[MAX_N];
long long netinc[MAX_N];

int main(){
  int t,n,k,pos,neg;
  long long profit;
  cin >> t;
  for(int i=0;i<t;i++){
    pos = 1, neg = 0, profit = 0;
    cin >> n >> k;
    for(int j=0;j<n;j++)
      cin >> boss[j];
    for(int j=0;j<n;j++)
      cin >> business[j];
    for(int j=0;j<n;j++)
      netinc[j] = business[j] - boss[j];
    sort(netinc,netinc+n);
    while(netinc[n-pos]>=0 && pos <= n){
      profit += netinc[n-pos];
      pos++;
    }
    while(pos+neg <= n){
      if(k>0)
        k--;
      else
        profit += netinc[neg];
      neg++;
    }
    if(profit <= 0)
      cout << "Case " << i+1 << ": No Profit\n";
    else
      cout << "Case " << i+1 << ": " << profit << "\n";
  }
}