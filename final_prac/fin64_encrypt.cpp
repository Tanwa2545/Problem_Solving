#include <bits/stdc++.h>
using namespace std;
#define MAX_N 25

int table[4][5];
list<int> num;

int main() {
  int n,s,m,count = 1;
  cin >> n >> s;
  for(int i=0;i<20;i++){
    if(i<n){
      cin >> m;
      num.push_back(m);
    }
    else{
      num.push_back(count);
      count++;
    }
  }
  for(int i=0;i<s;i++){
    m = num.back();
    num.pop_back();
    num.push_front(m);
  }
  // for(auto k:num){
  //   cout << k << " ";
  // }
  // cout << endl;
  for(int i=0;i<4;i++){
    for(int j=0;j<5;j++){
      if(!num.empty()){
        table[i][j] = num.front();
        num.pop_front();
      }
      else{
        table[i][j] = 0;
      }
    }
  }
  // for(int i=0;i<4;i++){
  //   for(int j=0;j<5;j++)
  //     cout << table[i][j] << " ";
  //   cout << endl;
  // }
  for(int i=0;i<5;i++){
    for(int j=0;j<4;j++){
      cout << table[j][i] << " ";
    }
  }
}