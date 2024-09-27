#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adj;
set<int> totalcountry;

int main(){
  int r,c,a,b,x,y;
  cin >> r >> c >> a >> b >> x >> y;
  int arr[r+10][c+10];
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      cin >> arr[i][j];
      totalcountry.insert(arr[i][j]);
      if(i > 1){
        //cout << "checking : (" << i << "," << j << ") : " << arr[i][j] << ", " << arr[i-1][j] << endl;
        if(arr[i][j] != arr[i-1][j]){
          adj[arr[i][j]].insert(arr[i-1][j]);
          adj[arr[i-1][j]].insert(arr[i][j]);
        }
      }
      if(j > 1){
        //cout << "checking : (" << i << "," << j << ") : " << arr[i][j] << ", " << arr[i][j-1] << endl;
        if(arr[i][j] != arr[i][j-1]){
          adj[arr[i][j]].insert(arr[i][j-1]);
          adj[arr[i][j-1]].insert(arr[i][j]);
        }
      }
    }
  }
  int tcountry = totalcountry.size();
  bool seen[tcountry];
  int layer[tcountry];
  int deg[tcountry];
  int start = arr[a][b], finish = arr[x][y];
  if(start == finish)
    cout << 0 << endl;
  else{
    for(auto k:adj){
      deg[k.first] = k.second.size();
    }
    for(int u = 1; u <= tcountry; u++) {
      seen[u] = false;
      layer[u] = -1;
    }
    list<int> q;
    q.push_back(start);
    seen[start] = true;
    layer[start] = 0;
    while(!q.empty()) {
      int u = q.front();
      if(u == finish)
        break;
      q.pop_front();
      for(int d=0; d<deg[u]; d++) {
        int v = adj[u][d];
        if(!seen[v]) {
          q.push_back(v);
          seen[v] = true;
          layer[v] = layer[u] + 1;
        }
      }
    }
  }
  // for(int i=1;i<=r;i++){
  //   for(int j=1;j<=c;j++){
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << layer[finish] << endl;
  for(auto k:adj){
    cout << k.first << " -> ";
    for(auto v:k.second)
      cout << v << ", ";
    cout << endl;
  }
}