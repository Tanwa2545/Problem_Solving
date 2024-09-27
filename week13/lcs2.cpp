#include <bits/stdc++.h>
using namespace std;
#define MAX_N 210

int lcs[MAX_N][MAX_N];
pair<int,int> prev_pos[MAX_N][MAX_N];
string s1, s2;
list<char> ans;

void find_lcs(int n, int m){
  int equal = 0;
  if(n<=0 || m<=0) return;
  if(lcs[n][m]!=-1) return;
  if(lcs[n-1][m-1]==-1)
    find_lcs(n-1, m-1);
  if(lcs[n][m-1]==-1)
    find_lcs(n, m-1);
  if(lcs[n-1][m]==-1)
    find_lcs(n-1, m);
  if(s1[n-1]==s2[m-1])
    equal = 1;
  if(lcs[n-1][m] >= lcs[n][m-1] && lcs[n-1][m] >= lcs[n-1][m-1] + equal){
    lcs[n][m] = lcs[n-1][m];
    prev_pos[n][m] = {n-1, m};
  }
  else if(lcs[n][m-1] >= lcs[n-1][m] && lcs[n][m-1] >= lcs[n-1][m-1] + equal){
    lcs[n][m] = lcs[n][m-1];
    prev_pos[n][m] = {n, m-1};
  }
  else{
    lcs[n][m] = lcs[n-1][m-1] + equal;
    prev_pos[n][m] = {n-1, m-1};
  }
  return;
}

int main() {
  int l1, l2;
  cin >> s1 >> s2;
  l1 = s1.length();
  l2 = s2.length();
  for(int i=0;i<=l1;i++)
    lcs[i][0] = 0;
  for(int i=0;i<=l2;i++)
    lcs[0][i] = 0;
  for(int i=1;i<=l1;i++){
    for(int j=1;j<=l2;j++){
      lcs[i][j] = -1;
    }
  }
  find_lcs(l1,l2);
  cout << lcs[l1][l2] << "\n";
  // cout << "score table\n";
  // for(int i=1;i<=l1;i++){
  //   for(int j=1;j<=l2;j++)
  //     cout << lcs[i][j] << " ";
  //   cout << "\n";
  // }
  // for(int i=1;i<=l1;i++){
  //   for(int j=1;j<=l2;j++){
  //     cout << prev_pos[i][j].first << "," << prev_pos[i][j].second << " ";
  //   }
  //   cout << "\n";
  // }
  while(l1>0 && l2>0){
    if(prev_pos[l1][l2].first == l1-1 && prev_pos[l1][l2].second == l2-1){
      ans.push_front(s2[l2-1]);
      l1--;
      l2--;
    }
    else if(prev_pos[l1][l2].first == l1-1)
      l1--;
    else
      l2--;
  }
  for(auto i:ans)
    cout << i;
}