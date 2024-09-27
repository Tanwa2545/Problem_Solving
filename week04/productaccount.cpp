#include <bits/stdc++.h>
using namespace std;

map<int, int> cargo;

int main() {
  int m,type,pos,n;
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> type >> pos;
    if(type == 1){
      cin >> n;
      if(cargo.find(pos) != cargo.end())
        cargo[pos]+=n;
      else
        cargo[pos] = n;
    }
    else if(type == 2){
      if(cargo.find(pos) != cargo.end())
        cout << cargo[pos] << "\n";
      else
        cout << 0 << "\n";
    }
    else{
      cin >> n;
      if(cargo.find(pos) != cargo.end()){
        if(n > cargo[pos]){
          cout << cargo[pos] << "\n";\
          cargo[pos] = 0;
        }
        else{
          cout << n << "\n";
          cargo[pos]-=n;
        }
      }
      else
        cout << 0 << "\n";
    }
  }
}