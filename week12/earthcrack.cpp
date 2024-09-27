#include <bits/stdc++.h>
#define MAX_N 510
using namespace std;

int earth[MAX_N][MAX_N];
int crackscore[MAX_N][MAX_N];
int m,n;

void find_crack(int x,int y){
  int score = 1e9;
  if(x<0 || y<0 || x>=m || y>=n) return;
  if(x==0){
    crackscore[x][y] = earth[x][y];
    return;
  }
  if(y > 0 && crackscore[x-1][y-1]==0) find_crack(x-1,y-1);
  if(y < n-1 && crackscore[x-1][y+1]==0) find_crack(x-1,y+1);
  if(crackscore[x-1][y]==0) find_crack(x-1,y);
  if(y > 0 && crackscore[x-1][y-1] < score)
    score = crackscore[x-1][y-1];
  if(y < n-1 && crackscore[x-1][y+1] < score)
    score = crackscore[x-1][y+1];
  if(crackscore[x-1][y] < score)
    score = crackscore[x-1][y];
  crackscore[x][y] = score + earth[x][y];
  return;
}

int main() {
  int t,minscore;
  cin >> t;
  for(int i=0;i<t;i++){
    minscore = 1e9;
    cin >> m >> n;
    for(int j=0;j<m;j++){
      for(int k=0;k<n;k++){
        cin >> earth[j][k];
        crackscore[j][k] = 0;
      }
    }
    for(int k=0;k<n;k++){
      find_crack(m-1,k);
      if(crackscore[m-1][k] < minscore) minscore = crackscore[m-1][k];
    }
    // for(int j=0;j<m;j++){
    //   for(int k=0;k<n;k++)
    //     cout << crackscore[j][k] << " ";
    //   cout << endl;
    // }
    cout << minscore << endl;
  }
}