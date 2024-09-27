#include <bits/stdc++.h>
using namespace std;

int ostrich[11][11];

int main() {
  int r,c,b,t,max_per_rnd,count = 0,iszero,line;
  cin >> r >> c >> b >> t;
  max_per_rnd = b/t;
  for(int i=0;i<r;i++){
    iszero = 1;
    line = 0;
    for(int j=0;j<c;j++){
      cin >> ostrich[i][j];
      line+=ostrich[i][j];
    }
    count += line/max_per_rnd;
    // cout << count << " " << (line%max_per_rnd!=0) << (line > max_per_rnd) << (line < max_per_rnd) << " ";
    // cout << "\n" << line << " " << max_per_rnd << "\n";
    if((line%max_per_rnd != 0 && line > max_per_rnd) || line < max_per_rnd) count++;
    if(line==0) count--;
    // cout << count << "\n";
  }
  cout << count;
}