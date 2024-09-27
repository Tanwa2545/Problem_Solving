#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010

int cost[MAX_N];
int cover[MAX_N];
int min_cost[MAX_N];

int find_cost(int x, int y){
  if(min_cost[x] == -1)
}

int main() {
  int n,c,s;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> cost[i] >> cover[i];
  }
  find_cost(0,n-1);
}