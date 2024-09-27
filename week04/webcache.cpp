#include <bits/stdc++.h>
using namespace std;

map<int, int> cache;
list<int> order;

int main() {
  int n, m, tmp, count = 0;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> tmp;
    if(cache.find(tmp) == cache.end()){
      order.push_back(tmp);
      count++;
      if(order.size() > n){
        cache.erase(order.front());
        cache.insert(pair<int, int>(tmp, 1));
        order.pop_front();
      }
      else
        cache.insert(pair<int, int>(tmp, 1));
    }
  }
  //for(auto k: cache)
  //  cout << k.first << " " << k.second << endl;
  cout << count;
}
/*for(int i=0; i<m; i++){
  int found = 0;
  cin >> tmp;
  for(auto k:cache){
    if(k == tmp)
      found = 1;
  }
  if(!found){
    count++;
    if(cache.size()>=n){
      cache.pop_front();
      cache.push_back(tmp);
    }
    else
      cache.push_back(tmp);
  }
}*/