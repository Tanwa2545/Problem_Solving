#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
map<int, int> visited;

int main() {
  int n,m,u,v;
  while(cin >> n >> m){
    if(n+m == 0) break;
    vector<int> indegree(n+10);
    queue<int> q;
    for(int i=0;i<m;i++){
      cin >> u >> v;
      adj[u].push_back(v);
      indegree[v]++;
    }
    for(int i=1;i<=n;i++){
      if(indegree[i]==0){
        q.push(i);
        visited[i] = 1;
      }
    }
    while(!q.empty()){
      int node = q.front();
      cout << node << " ";
      q.pop();
      for(int i=0;i < adj[node].size();i++){
        int child = adj[node][i];
        indegree[child]--;
        if(indegree[child]==0 && visited[child]==0){
          q.push(child);
          visited[child] = 1;
        }
      }
    }
    cout << "\n";
    adj.clear();
    visited.clear();
  }
}