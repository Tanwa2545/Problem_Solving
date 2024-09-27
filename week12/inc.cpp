#include <bits/stdc++.h>
#define MAX_N 1010
using namespace std;

int seq[MAX_N];
int maxlen[MAX_N];
int l_from[MAX_N];

void inc(int n){
  int l = 0,from = -1;
  if(n == 0){
    maxlen[n] = 1;
    l_from[n] = -1;
    return;
  }
  for(int i=n-1;i>=0;i--){
    if(maxlen[i] == 0){
      inc(i);
    }
    if(seq[i] < seq[n] && maxlen[i] > l){
      l = maxlen[i];
      from = i;
    }
  }
  if(from == -1){
    maxlen[n] = 1;
    l_from[n] = -1;
    return;
  }
  else{
    maxlen[n] = l+1;
    l_from[n] = from;
  }
  return;
}

void printans(int n){
  if(n == -1) return;
  printans(l_from[n]);
  cout << seq[n] << " ";
}

int main() {
  int n,max = 0,index = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> seq[i];
  }
  inc(n-1);
  for(int i=0;i<n;i++){
    //cout << i << "," << maxlen[i] << "," << max << " ";
    if(maxlen[i] >= max){
      index = i;
      max = maxlen[i];
    }
  }
  // cout << endl;
  // for(int i=0;i<n;i++){
  //   cout << l_from[i] << " ";
  // }
  // cout << endl;
  cout << maxlen[index] << endl;
  printans(index);
}