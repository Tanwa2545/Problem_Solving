#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<list<int>> station(100100);

int main() {
  int n,m,st,j;
  cin >> m;
  char k;
  for(int i=1;i<=m;i++){
    cin >> k;
    if(k=='N'){
      cin >> n >> st;
      station[st].push_back(n);
    }
    else if(k=='M'){
      cin >> n >> j;
      station[j].splice(station[j].end(),station[n]);
    }
  }
  for (int i=1;i<=100000;i++){
    for (auto l=station[i].begin();l!=station[i].end();l++){
      cout << *l << "\n";
    }
  }
  // for (auto s: station) {
  //   for (auto t: s) cout << t << endl;
  // }
}