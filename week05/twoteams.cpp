#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
map<int, int> color;

int bfs(int start) {
  queue<int> q;
  map<int, int> visited;
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
      } 
      else if (color[neighbor] == color[node]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int n,m,a,b,fail = 0,count = 0;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    if(i==0 || fail){
      color[a] = 1;
      color[b] = 2;
    }
    else{
      if((color[a] != 1 && color[a] != 2) && (color[b] != 1 && color[b] != 2)){
        color[a] = 1;
        color[b] = 2;
      }
      else if(color[a] != 1 && color[a] != 2)
        color[a] = 3-color[b];
      else if(color[b] != 1 && color[b] != 2)
        color[b] = 3-color[a];
      else{
        if(color[a] == color[b]){
          color.clear();
          if(!bfs(a)){
            fail = 1;
          }
        }
      }
    }
    if(!fail)
      count++;
  }
  cout << count;
}