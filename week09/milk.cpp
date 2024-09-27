#include <bits/stdc++.h>
#define MAX_N 100010
using namespace std;

// vector<int> connect;
map<int, set<int>> adj;

void insertion(int a, int b){
  // cout << "Check : " << a << " and " << b << " Lower bound : " << *adj[a].lower_bound(b) << " " << (*adj[a].lower_bound(b) == b) << endl;
  if(*adj[a].lower_bound(b) == b || a == b)
    return;
  adj[a].insert(b);
  adj[b].insert(a);
  // cout << "inserting : " << a << " and " << b << endl << "we have : ";
  // for(auto i : adj[a]){
  //   cout << i << " ";
  // }
  // cout << endl;
  for(auto i : adj[a]){
    insertion(i,b);
  }
  for(auto i : adj[b]){
    insertion(i,a);
  }
  return;
}

void check(int a, int b){
  if(*adj[a].lower_bound(b) == b)
    cout << "yes\n";
  else
    cout << "no\n";
}

int main() {
  int n,q,a,b;
  char s;
  cin >> n >> q;
  for(int i = 0; i < q; i++){
    cin >> s >> a >> b;
    if(s == 'c'){
      insertion(a,b);
    }
    if(s == 'q'){
      check(a,b);
    }
  }
  // for(int i = 1; i <= n; i++){
  //   cout << i << " : ";
  //   for(auto k: adj[i]){
  //     cout << k << " ";
  //   }
  //   cout << endl;
  // }
}