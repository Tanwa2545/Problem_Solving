#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55

int cuts_pos[MAX_N];
int best_cuts[MAX_N][MAX_N];

void find_cuts(int x,int y){
  if(best_cuts[x][y]!=-1) return;
  best_cuts[x][y]=0;
  for(int i=x+1;i<y;i++){
    if(best_cuts[x][i]==-1) find_cuts(x,i);
    if(best_cuts[i][y]==-1) find_cuts(i,y);
    if(best_cuts[x][y]==0)
      best_cuts[x][y] = best_cuts[x][i] + best_cuts[i][y] + cuts_pos[y] - cuts_pos[x];
    else
      best_cuts[x][y] = min(best_cuts[x][y],best_cuts[x][i] + best_cuts[i][y] + cuts_pos[y] - cuts_pos[x]);
  }
  // cout << "at " << x << " " << y << " " << best_cuts[x][y] << endl;
  return;
}

int main() {
  int l,n;
  while(cin >> l){
    if(l==0) break;
    cin >> n;
    cuts_pos[0]=0;
    for(int i=1;i<=n;i++){
      cin >> cuts_pos[i];
      for(int j=0;j<=n;j++)
        best_cuts[i][j]=-1;
    }
    for(int i=0;i<=n+1;i++){
      for(int j=0;j<=n+1;j++)
        best_cuts[i][j] = -1;
    }
    cuts_pos[n+1]=l;
    find_cuts(0,n+1);
    // for(int i=0;i<=n+1;i++){
    //   for(int j=0;j<=n+1;j++)
    //     cout << best_cuts[i][j] << " ";
    //   cout << endl;
    // }
    cout << "The minimum cutting is " << best_cuts[0][n+1] << ".\n";
  }
}