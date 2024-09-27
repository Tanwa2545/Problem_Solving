#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[110][110];
map<pair<int,int>,int> visited;
list<pair<int,int>> Q;
bool seen[110][110];
int layer[110][110];

int main() {
  int n, r;
  cin >> n >> r;
  if(r*r >= 20000)
    adj[0][0].push_back({100,100});
  for(int i=0;i<n;i++){
    int x, y, x1, y1;
    cin >> x >> y;
    visited[{x,y}] = 0;
    if(x*x+y*y <= r*r){
      adj[x][y].push_back({0,0});
      adj[0][0].push_back({x,y});
    }
    if((100-x)*(100-x)+(100-y)*(100-y) <= r*r)
      adj[x][y].push_back({100,100});
    for(auto k:visited){
      x1 = k.first.first;
      y1 = k.first.second;
      //cout << "checking if connected? : (" << x << ", " << y << ") and (" << x1 << ", " << y1 << ") : ";
      if((x1-x)*(x1-x)+(y1-y)*(y1-y) <= r*r && !(x1==x && y1==y)){
        adj[x][y].push_back({x1,y1});
        adj[x1][y1].push_back({x,y});
        //cout << "yes";
      }
      //cout << endl;
    }
  }
  for(int i=0;i<=100;i++) {
    for(int j=0;j<=100;j++) {
      seen[i][j] = false;
      layer[i][j] = -1;
      // if(!adj[i][j].empty()) {
      //   cout << "adj[" << i << "][" << j << "]: ";
      //   for(const auto &pairv : adj[i][j]) {
      //     cout << "(" << pairv.first << ", " << pairv.second << ") ";
      //   }
      //   cout << endl;
      // }
    }
  }
  Q.push_back({0,0});
  seen[0][0] = true;
  layer[0][0] = 0;
  while(!Q.empty()) {
    pair<int,int> u = Q.front();
    Q.pop_front();
    for(const auto &pairv : adj[u.first][u.second]){
      if(!seen[pairv.first][pairv.second]) {
        Q.push_back({pairv.first,pairv.second});
        seen[pairv.first][pairv.second] = true;
        layer[pairv.first][pairv.second] = layer[u.first][u.second] + 1;
      }
      if(pairv.first == 100 && pairv.second == 100){
        Q.clear();
        break;
      }
    }
  }
  cout << layer[100][100] << endl;
}