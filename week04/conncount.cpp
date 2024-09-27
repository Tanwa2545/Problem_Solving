#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int> visited (MAX);
vector<vector<int>> edges(MAX);

void dfs(int node){
  if(visited[node])
    return;
  visited[node] = 1;
  //cout << "inserting " << node << "\n";
  for(auto i: edges[node]){
    //cout << " going to " << i << "\n";
    if(!visited[i])
      dfs(i);
  }
  //cout << "backtracking from " << node << "\n";
}

int main() {
  int n, m, count = 0;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  /*for(int i=1;i<=n;i++){
    for(auto j=edges[i].begin();j!=edges[i].end();j++)
      cout << *j << ", ";
    cout << "el\n";
  }*/
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      //cout << "not found : " << i << "\n";
      dfs(i);
      count++;
      /*for(auto k: visited)
        cout << k << ", ";
      cout << "visited\n";*/
    }
  }
  cout << count;
}