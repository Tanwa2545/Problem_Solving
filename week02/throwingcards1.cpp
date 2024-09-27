#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,tmp,k=0,isfirst=1;
  list<int> input;
  list<int> discarded;
  while(1){
    cin >> n;
    if(n==0)
      break;
    input.push_back(n);
    k++;
  }
  for(auto i:input){
    discarded.clear();
    isfirst = 1;
    cout << "Discarded cards:";
    for(int j=1;j<=i;j++){
      discarded.push_back(j);
    }
    for(int j=1;j<i;j++){
      if(isfirst){
        cout << " " << discarded.front();
        isfirst = 0;
      }
      else
        cout << ", " << discarded.front();
      discarded.pop_front();
      tmp = discarded.front();
      discarded.pop_front();
      discarded.push_back(tmp);
    }
    cout << "\nRemaining card: " << discarded.front() << "\n";
  }
}