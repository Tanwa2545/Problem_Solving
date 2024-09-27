#include <bits/stdc++.h>
using namespace std;
#define MAX_N 210

string rna;
int max_match[MAX_N][MAX_N];

void find_match(int x, int y){
  if(max_match[x][y] != -1) return;
  max_match[x][y] = 0;
  if(x>=y || y-x<=4) return;
  if(max_match[x][y-1] == -1) find_match(x,y-1);
  int match, ans = max_match[x][y-1];
  for(int i=x;i<y-4;i++){
    match = 0;
    // cout << "at : " << x << "," << i << "," << y << " : " << rna[x] << " " << rna[i] << " " << rna[y] << endl;
    if((rna[i] == 'C' && rna[y] == 'G') || (rna[i] == 'G' && rna[y] == 'C') || (rna[i] == 'A' && rna[y] == 'U') || (rna[i] == 'U' && rna[y] == 'A')){
      if(max_match[x][i-1] == -1) find_match(x,i-1);
      if(max_match[i+1][y-1] == -1) find_match(i+1,y-1);
      ans = max(ans, max_match[x][i-1] + max_match[i+1][y-1] + 1);
      // cout << "max_match[" << x << "][" << y << "] = " << ans << " i= " << i << " " << max_match[x][i-1] << " " << max_match[i+1][y-1] << endl;
    }
  }
  max_match[x][y] = ans;
  return;
}

int main() {
  cin >> rna;
  int n = rna.length();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      max_match[i][j] = -1;
  }
  find_match(0,n-1);
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++)
  //     cout << max_match[i][j] << " ";
  //   cout << endl;
  // }
  cout << max_match[0][n-1];
}