#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010

int height[MAX_N];

int main(){
  int c,n,h,ta,td;
  cin >> c;
  for(int i=0;i<c;i++){
    cin >> n >> h >> ta >> td;
    for(int j=0;j<n;j++)
      cin >> height[j];
    sort(height,height+n);
    // for(int j=0;j<n;j++)
    //   cout << height[j] << " ";
    // cout << endl;
    if(ta*2 <= td){
      cout << "Case " << i+1 << ": " << ta*n << "\n";
    }
    else{
      int j = 0, count_ta = 0, count_td = 0;
      while(count_td*2 + count_ta < n){
        if(height[j] + height[n-j-count_ta-1] < h && j!=n-j-count_ta-1){
          //cout << "we got " << height[j] << " and " << height[n-j-count_ta-1] << "\n";
          j++;
          count_td++;
        }
        else{
          count_ta++;
        }
      }
      //cout << count_ta << " " << count_td << "\n";
      cout << "Case " << i+1 << ": " << ta*count_ta + td*count_td << "\n";
    }
  }
}