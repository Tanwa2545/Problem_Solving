#include <bits/stdc++.h>
using namespace std;
#define MAX_N 210

int lcs[MAX_N][MAX_N];
int prev_pos[MAX_N][MAX_N];
string s1, s2;

void find_lcs(int n, int m){
  int equal = 0;
  if(n<=0 || m<=0) return;
  if(lcs[n][m-1]==-1)
    find_lcs(n, m-1);
  if(lcs[n-1][m]==-1)
    find_lcs(n-1, m);
  if(lcs[n-1][m-1]==-1)
    find_lcs(n-1, m-1);
  if(s1[n-1]==s2[m-1])
    equal = 1;
  if(lcs[n-1][m-1] + equal > lcs[n][m-1] && lcs[n-1][m-1] + equal > lcs[n-1][m]){
    lcs[n][m] = lcs[n-1][m-1] + equal;
  }
  else if(lcs[n-1][m] > lcs[n][m-1]){
    lcs[n][m] = lcs[n-1][m];
  }
  else{
    lcs[n][m] = lcs[n][m-1];
  }
  return;
}

int main() {
  int l1, l2;
  cin >> s1 >> s2;
  l1 = s1.length();
  l2 = s2.length();
  for(int i=0;i<=s1.length();i++)
    lcs[i][0] = 0;
  for(int i=0;i<=s2.length();i++)
    lcs[0][i] = 0;
  for(int i=1;i<=s1.length();i++){
    for(int j=1;j<=s2.length();j++){
      lcs[i][j] = -1;
    }
  }
  find_lcs(l1,l2);
  cout << lcs[l1][l2];
}