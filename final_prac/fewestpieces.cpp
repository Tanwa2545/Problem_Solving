#include <bits/stdc++.h>
using namespace std;
#define MAX_N 35

int coffee[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];
int m,n;

int fewest(int x, int y){
  int a=0,b=0,c=0,d=0,i=0;
  while(y-i>=0){
    a+=coffee[x][y-i];
    i++;
  }
  i=0;
  while(x-i>=0){
    b+=coffee[x-i][y];
    i++;
  }
  i=0;
  while(x+i<m){
    c+=coffee[x+i][y];
    i++;
  }
  i=0;
  while(y+i<n){
    d+=coffee[x][y+i];
    i++;
  }
  return min(min(a,b),min(c,d));
}

int main() {
  cin >> m >> n;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
      cin >> coffee[i][j];
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(j==0 || j==n-1 || i==0 || i==m-1){
        ans[i][j] = coffee[i][j];
      }
      else{
        ans[i][j] = fewest(i,j);
        // cout << "at x = " << i << " y = " << j << " ans = " << ans[i][j] << "\n";
      }
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }
}