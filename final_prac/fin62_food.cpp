#include <bits/stdc++.h>
using namespace std;
#define MAX_N 5010

int people[MAX_N];
int skip[MAX_N][MAX_N];
int n,k;

void find_val(int i, int f){
  int pp = people[f];
  if(i<0 || f<0 || i>n) return;
  if(skip[i][f]!=-1) return;
  cout << "yo ";
  if(f-pp >= 0 && skip[i+1][f-pp]==-1) find_val(i+1, f-pp);
  if(skip[i+2][f]==-1) find_val(i+2, f);
  if(f<pp){
    skip[i][f] = skip[i+1][f];
  }
  else{
    if(skip[i+2][f] + pp < skip[i+1][f-pp])
      skip[i][f] = skip[i+2][f] + pp;
    else
      skip[i][f] = skip[i+1][f-pp];
  }
  return;
}

int main(){
  cin >> n >> k;
  for(int i=0;i<n;i++){
    cin >> people[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      skip[i][j] = -1;
  }
  find_val(0,k);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout << skip[i][j] << " ";
    cout << endl;
  }
}