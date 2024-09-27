#include <bits/stdc++.h>
using namespace std;

char boxmap[31][31];
int moveable = 0;

void traversemaze(int r, int c, int n, int m){
  if(r >= n-1 || c >= m-1 || r<0 || c<0)  return;
  //cout << "not oob\n";
  if(boxmap[r][c]=='#' || boxmap[r][c+1]=='#' || boxmap[r+1][c]=='#' || boxmap[r+1][c+1]=='#')  return;
  if(boxmap[r][c]=='x' && boxmap[r][c+1]=='x' && boxmap[r+1][c]=='x' && boxmap[r+1][c+1]=='x')  return;
  //cout << "not wall\n";
  if(r==n-2){
    moveable = 1;
    //cout << "moveable\n";
    return;
  }
  boxmap[r][c] = 'x';
  boxmap[r][c+1] = 'x';
  boxmap[r+1][c] = 'x';
  boxmap[r+1][c+1] = 'x';
  traversemaze(r+1, c, n, m);
  traversemaze(r, c+1, n, m);
  traversemaze(r-1, c, n, m);
  traversemaze(r, c-1, n, m);
  return;
}

int main(){
  int n,m;
  cin >> n >> m;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      cin >> boxmap[i][j];
    }
  }
  for(int i = 0;i<m-1;i++)
    traversemaze(0,i,n,m);
  cout << ((moveable)? "yes":"no");
}