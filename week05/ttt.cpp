#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> problem;

void bfs(map<int, vector<int>>& adj, int start) {
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
        problem[node].push_back(neighbor);
        problme[neighbor].push_back(node);
        cout << node << " " << neighbor << "\n";
        // adj[node].erase(neighbor);
        // adj[neighbor].erase(node);
      }
    }
  }
  return;
}

int main() {
  int n,m,u,v;
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
  bfs(adj, start);
  // for(auto k:adj){
  //   for(auto j:k.second)
  //     cout << j << ", ";
  //   cout << endl;
  // }
}