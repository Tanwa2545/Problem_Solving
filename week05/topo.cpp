#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
queue<int> q;
map<int, int> visited;

int main(){
  int n,m,u,v;
  cin >> n >> m;
  vector<int> indegree(n+10);
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
  if(q.empty())
    cout << "no";
  else{
    while(!q.empty()){
      int node = q.front();
      cout << node << "\n";
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
  }
  /*for(int i=1;i<=n;i++)
    cout << indegree[i] << ", ";
  cout << endl;
  for(auto k:adj){
    cout << k.first << " -> ";
    for(auto v:k.second)
      cout << v << ", ";
    cout << endl;
  }
  for(auto k:topo)
    cout << k << ", ";*/
}