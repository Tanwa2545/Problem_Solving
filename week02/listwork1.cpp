#include <iostream>
#include <list>
using namespace std;

int main() {
  int m,n;
  char k;
  list<int> lst;
  cin >> m;
  for(int i=0;i<m;i++){
    cin >> k >> n;
    if(k=='I'){
      lst.push_front(n);
    }
    if(k=='D'){
      auto v = lst.begin();
      for(int j=0;j<n-1;j++){
        v++;
      }
      if(n <= lst.size())
        lst.erase(v);
    }
  }
  for (auto i=lst.begin();i!=lst.end();i++)
    cout << *i << "\n";
}