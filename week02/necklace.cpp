#include <bits/stdc++.h>
using namespace std;

list<int> necklace[300100];

int main() {
  int n,x,y;
  cin >> n;
  int fromto[n+10];
  for(int i = 1; i <= n; i++){
    necklace[i].push_back(i);
  }
  for(int i = 1; i < n; i++){
    cin >> x >> y;
    fromto[x] = y;
    int yy = y;
    auto it = necklace[y].begin();
    it++;
    if(necklace[y].empty()){
      while(necklace[y].empty()){
        y = fromto[y];
      }
      fromto[x] = y;
      //cout << y << ", " << yy << endl;
      it = necklace[y].begin();
      it++;
      for(auto k:necklace[y]){
        if(k == yy)
          break;
        it++;
      }
      //cout << y << ", " << *it ;
    }
    necklace[y].splice(it, necklace[x]);
    /*for(int i = 1; i <= n; i++){
      if(!necklace[i].empty()){
        for(auto k:necklace[i])
          cout << k << " ";
      }
      cout << "and " << endl;
    }
    cout << "next" << endl;*/
  }
  for(int i = 1; i <= n; i++){
    if(!necklace[i].empty()){
      for(auto k:necklace[i])
        cout << k << " ";
    }
  }
}