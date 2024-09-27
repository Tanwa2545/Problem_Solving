#include <iostream>
#include <list>
using namespace std;

int main() {
  int m,k;
  char st;
  list<int> lst;
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> st >> k;
    if(st=='I'){
      lst.push_front(k);
    }
    else if(st=='A'){
      lst.push_back(k);
    }
    else if(st=='D'){
      auto v = lst.begin();
      for(int j=0;j<k-1;j++){
        v++;
      }
      if(k <= lst.size())
        lst.erase(v);
    }
  }
  for (auto i=lst.begin();i!=lst.end();i++)
    cout << *i << "\n";
}