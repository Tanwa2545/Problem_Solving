#include <bits/stdc++.h>
using namespace std;

set<int> unsortedpos;
vector<int> pos;

int main(){
  int n,k,l,x;
  cin >> n >> k >> l;
  for(int i = 0;i<n;i++){
    cin >> x;
    unsortedpos.insert(x);
  }
  for(auto i:unsortedpos)
    pos.push_back(i);
  int distance = k+l, max = 0;
  for(int i = 0;i<(n-distance);i++){
    if(pos[i+distance]-pos[i] > max)
      max = pos[i+distance]-pos[i];
  }
  cout << max;
  // for(auto j:pos)
  //   cout << j << ", ";
  // cout << k << l;
}