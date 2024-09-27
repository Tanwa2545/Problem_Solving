#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010

vector<int> adj[MAX_N];
vector<long long> weights[MAX_N];
vector<pair<int,int>> edges;
vector<long long> edge_weights;
int deg[MAX_N];
set<pair<int,int>> Q;
vector<pair<long long,int>> sedges;
int set_parent[MAX_N];
int set_rank[MAX_N];
int n,m;

void init_set()
{
  for(int i=0; i<n; i++) {
    set_parent[i] = i;
    set_rank[i] = 1;
  }
}

int set_find(int u)
{
  if(set_parent[u] == u) {
    return u;
  } else {
    return set_find(set_parent[u]);
  }
}

void set_union(int pu, int pv)
{
  pu = set_find(pu);
  pv = set_find(pv);
  if(pu == pv)
    return;
  if(set_rank[pv] > set_rank[pu]) {
    set_parent[pu] = pv;
  } else if(set_rank[pu] > set_rank[pv]) {
    set_parent[pv] = pu;
  } else {
    set_parent[pv] = pu;
    set_rank[pu]++;
  }
}

int main(){
  int a,b,w,last_i=0,total=0,ecount=0,firsttime=1;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> a >> b >> w;  a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    weights[a].push_back(w);
    weights[b].push_back(w);
    deg[a]++;
    deg[b]++;
    edges.push_back(make_pair(a,b));
    edge_weights.push_back(w);
    sedges.push_back(make_pair(w,i));
  }
  init_set();
  sort(sedges.begin(), sedges.end());
  for(int i=0; i<m; i++) {
    int e = sedges[i].second;
    int u = edges[e].first;
    int v = edges[e].second;
    int w = edge_weights[e];
    int pu = set_find(u);
    int pv = set_find(v);
    if(pu != pv) {
      last_i = i;
      total += w;
      ecount++;
      set_union(pu,pv);
    }
    else if(firsttime){
      last_i = i;
      total += w;
      set_union(pu,pv);
      ecount++;
      firsttime=0;
    }
  }
  // for(auto k:sedges)
  //   cout << k.first << " " << k.second << endl;
  // cout << "--\n";
  // for(auto k:edge_weights)
  //   cout << k << endl;
  if(ecount<n)
    cout << -1;
  else
    cout << total;
}