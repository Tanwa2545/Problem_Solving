#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010

int info[MAX_N];
int rating[MAX_N];
int tmp[MAX_N];
int last_m[MAX_N];

int main(){
  int n,m,k;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> info[i];
  }
  for(int i=0;i<n;i++){
    rating[i] = 0;
    tmp[i] = 0;
    last_m[i] = -1;
  }
  for(int i=0;i<m;i++){
    k = info[i];
    if(last_m[k]+6 >= i || last_m[k]==-1){
      tmp[k]++;
      cout << "+1 at " << k << " " << tmp[k] << endl;
    }
    else{
      if(rating[k] < tmp[k]) rating[k] = tmp[k];
      tmp[k] = 1;
      cout << "exit at " << i << " " << rating[k] << " " << last_m[k] << endl;
    }
    last_m[k] = i;
  }
  for(int i=0;i<n;i++){
    if(rating[k] < tmp[k]) rating[k] = tmp[k];
  }
  for(int i=0;i<n;i++){
    cout << tmp[i] << " ";
  }
  cout << endl;
  for(int i=0;i<n;i++){
    cout << rating[i] << " ";
  }
  
}