#include <bits/stdc++.h>
using namespace std;

list<int> value;

int main() {
  int n,p,v,count=0,max=0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p >> v;
    value.push_front(v);
  }
  for(auto k:value){
    if(k>max){
      max = k;
    }
    else
      count++;
  }
  cout << count;
}