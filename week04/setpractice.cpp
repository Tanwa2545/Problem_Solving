#include <bits/stdc++.h>
using namespace std;

set<int> x;

int main() {
  int i,j,tmp;
  cin >> i >> j;
  for(int k=0;k<i;k++){
    cin >> tmp;
    x.insert(tmp);
  }
  for(int k=0;k<j;k++){
    cin >> tmp;
    auto lower = x.lower_bound(tmp);
    auto before = lower--;
    if(abs(*lower-tmp) > abs(tmp-*before) || lower != x.end()))
      cout << *before;
    else
      cout << *lower;
    cout << "\n";
  }
}