#include <bits/stdc++.h>
using namespace std;

int bfs(map<int, vector<int>>& adj, int start) {
  queue<int> q;
  map<int, int> visited;
  map<int, int> color;
  q.push(start);
  visited[start] = true;
  color[start] = 1;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for(int neighbor:adj[node]) {
      if(!visited[neighbor]) {
        color[neighbor] = 3-color[node];
        q.push(neighbor);
        visited[neighbor] = 1;
      } else if (color[neighbor] == color[node]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int k,n,m,u,v;
  cin >> k;
  for(int i=0;i<k;i++){
    map<int, vector<int>> adj;
    cin >> n >> m;
    int start = -1;
    for(int j=0;j<m;j++){
      cin >> u >> v;
      if (start == -1)
        start = u;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans = bfs(adj, start);
    if(ans)
      cout << "yes";
    else
      cout << "no";
    cout << "\n";
    // for(auto k:adj){
    //   for(auto j:k.second)
    //     cout << j << ", ";
    //   cout << endl;
    // }
  }
}