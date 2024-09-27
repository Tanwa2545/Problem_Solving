#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010

pair<int, int> house[MAX_N];

int main() {
  int n,l,fence = 0,count = 0;
  cin >> n >> l;
  for(int i=0;i<n;i++){
    cin >> house[i].first >> house[i].second;
  }
  sort(house,house+n);
  for(int i=0;i<n;i++){
    if(fence < house[i].second){
      fence = house[i].first + l;
      count++;
    }
  }
  cout << count;
}