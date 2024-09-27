#include <bits/stdc++.h>
using namespace std;

map<int, int> likecount;

int main() {
  int n,pos,maxlike = 0,maxlikepost = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> pos;
    if (likecount.find(pos) != likecount.end())
      likecount[pos]++;
    else
      likecount[pos] = 1;
    if (likecount[pos] >= maxlike){
      maxlike = likecount[pos];
      maxlikepost = pos;
    }
    cout << maxlikepost << "\n";
  }
}