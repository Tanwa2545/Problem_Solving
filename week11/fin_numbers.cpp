#include <bits/stdc++.h>
#define MAX_N 100010
#define LOW -1e6
using namespace std;

int stairs[MAX_N];
int required[MAX_N];
int score[MAX_N];
int prevn[MAX_N];

void findscore(int n){
  // cout << "findscore(" << n << ") " << score[n] << endl;
  if(score[n] != LOW || n<=3) return;
  findscore(n-1);
  findscore(n-2);
  findscore(n-3);
  for(int i=1;i<=3;i++){
    if(required[n-i]){
      score[n] = score[n-i] + stairs[n];
      prevn[n] = n-i;
      return;
    }
  }
  if(stairs[n] >= 0){
    score[n] = score[n-1] + stairs[n];
    prevn[n] = n;
    return;
  }
  vector<pair<int,int>> tmp;
  for(int i=1;i<=3;i++){
    if(prevn[i-1] + 3 >= n){
      tmp.push_back({score[n-i],prevn[n-i]});
      cout << "+1 ";
    }
    else{
      tmp.push_back({score[n-i] + stairs[n-i],n-i});
      cout << "+2 ";
    }
  }
  cout << "tmp now : ";
  for(auto k:tmp){
    cout << k.first << ", " << k.second << endl;
  }
  if(tmp[0] > tmp[1] && tmp[0] > tmp[2]){
    score[n] = tmp[0].first;
    prevn[n] = tmp[0].second;
  }
  else if(tmp[1] > tmp[0] && tmp[1] > tmp[2]){
    score[n] = tmp[1].first;
    prevn[n] = tmp[1].second;
  }
  else{
    score[n] = tmp[2].first;
    prevn[n] = tmp[2].second;
  }
}

int main() {
  int n,req = 1;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> stairs[i];
    score[i] = LOW;
  }
  for(int i=1;i<=n;i++){
    cin >> required[i];
    req = (required[i])? i : req;
  }
  score[0] = 0;
  prevn[0] = 0;
  for(int i=1;i<=3;i++){
    if(required[i]){
      score[i] = score[i-1] + stairs[i];
      prevn[i] = i;
    }
    else{
      if(stairs[i] >= 0){
        score[i] = score[i-1] + stairs[i];
        prevn[i] = i;
      }
      else{
        score[i] = 0;
        prevn[i] = 0;
      }
    }
  }
  findscore(n);
  // for(int i=1;i<=n;i++){
  //   cout << score[i] << " ";
  // }
  // cout << endl;
  cout << score[n];
}
/*
5
-99 -1 -2 -9 -3
0 0 0 0 0

5
-1 -1 -2 -1 -3
0 0 0 0 0

5
1 2 3 4 5
0 0 0 0 0

7
-1 -10 -5 -5 -5 -5 -5
0 1 0 0 0 0 0

7
-1 -10 -5 -5 -5 -5 -5
1 1 1 1 1 1 1
*/