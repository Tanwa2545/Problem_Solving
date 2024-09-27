#include <iostream>
#include <list>
using namespace std;

int main() {
  int n,inp,tmp;
  string k;
  list<int> lst;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> k;
    if(k=="li" || k=="ri"){
      cin >> inp;
      (k=="li")? lst.push_front(inp):lst.push_back(inp);
    }
    else if((k=="lr" || k=="rr") && !lst.empty()){
      if (k=="lr"){
        tmp = lst.front();
        lst.pop_front();
        lst.push_back(tmp);
      }
      else{
        tmp = lst.back();
        lst.pop_back();
        lst.push_front(tmp);
      }
    }
  }
  for (auto i=lst.begin();i!=lst.end();i++)
    cout << *i << "\n";
}