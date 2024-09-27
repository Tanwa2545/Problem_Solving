#include <bits/stdc++.h>
using namespace std;

char mazemap[21][21];
int visited[21][21];
int moveable = 0;
int n = 0;

void traversemaze(int a, int b, int x, int y, int key){
  if(a < 0 || a >= n || b < 0 || b >= n || visited[a][b] == 1 || moveable)
    return;
  if(mazemap[a][b] == '#')
    return;
  if(mazemap[a][b] == 'O' && !key)
    return;
  if(a==x && b==y){
    //cout << "found at : " << a << ", " << b << ", " << key << endl;
    moveable = 1;
    return;
  }
  //cout << "passing : " << a << ", " << b << ", " << key << endl;
  //cout << mazemap[a][b] << ", " << visited[a][b] << ", " << key << endl;
  if(mazemap[a][b] == 'O' && visited[a][b] != 1 && key){
    visited[a][b] = 1;
    traversemaze(a, b+1, x, y, 0);
    traversemaze(a, b-1, x, y, 0);
    traversemaze(a+1, b, x, y, 0);
    traversemaze(a-1, b, x, y, 0);
  }
  else{
    visited[a][b] = 1;
    traversemaze(a, b+1, x, y, key);
    traversemaze(a, b-1, x, y, key);
    traversemaze(a+1, b, x, y, key);
    traversemaze(a-1, b, x, y, key);
  }
  //cout << "backtrack : " << a << ", " << b << endl;
  return;
}

int main() {
  int q,a,b,x,y;
  cin >> n >> q;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> mazemap[i][j];
      visited[i][j] = 0;
    }
  }
  for(int i=0;i<q;i++){
    cin >> a >> b >> x >> y;
    moveable = 0;
    traversemaze(a-1,b-1,x-1,y-1,1);
    for(int k=0;k<n;k++){
      for(int j=0;j<n;j++){
        visited[k][j] = 0;
      }
    }
    cout << ((moveable)? "yes\n":"no\n");
  }
}