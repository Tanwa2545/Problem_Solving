#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500010

long long sat[MAX_N];
long long x[MAX_N];
long long y[MAX_N];
long long z[MAX_N];

void find_val(int i){
  if(i<0 || sat[i]!=-1) return;
  if(i>1 && sat[i-1] == -1) find_val(i-1);
  if(i>2 && sat[i-2] == -1) find_val(i-2);
  if(i>4 && sat[i-4] == -1) find_val(i-4);
  long long a = max(sat[i-4] + z[i-4],max(sat[i-2] + y[i-2],sat[i-1] + x[i-1]));
  sat[i] = a;
  return;
}

int main() {
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i] >> z[i];
    sat[i] = -1;
  }
  sat[0] = 0;
  for(int i=0;i<=3;i++)
    sat[n+i] = -1;
  find_val(n);
  find_val(n+1);
  find_val(n+2);
  find_val(n+3);
  // for(int i=0;i<n+4;i++){
  //   cout << sat[i] << " ";
  // }
  cout << sat[n+3];
}