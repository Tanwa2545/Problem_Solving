#include <bits/stdc++.h>
using namespace std;

//list<int> price;
list<int> totalprice;

int main() {
  int n, prev = 0, inp, count = 0;
  int price[110];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> inp;
    prev+=inp;
    price[i] = prev;
    totalprice.push_back(prev);
  }
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        totalprice.push_back(price[j] - price[i]);
    }
  }
  totalprice.sort();
  prev = 0;
  for(auto k:totalprice){
    if(k != prev){
      count++;
      prev = k;
    }
  }
  cout << count;
}