#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1010

pair<double,double> pos[MAX_N];

int main() {
  int n,d,l=1,x,y;
  while(cin >> n >> d){
    int fail = 0;
    if(n==0 && d==0) break;
    for(int i=0;i<n;i++){
      cin >> x >> y;
      if(y>d){
        fail = 1;
      }
      else{
        pos[i].first = x - sqrt(d*d - y*y);
        pos[i].second = x + sqrt(d*d - y*y);
      }
    }
    if(fail) cout << "Case " << l << ": -1\n";
    else{
      int k = 0, count = 0;
      double cover = -1e9;
      sort(pos,pos+n);
      // for(auto j:pos)
      //   if(j.first!=0) cout << j.first << " " << j.second << endl;
      while(k<n){
        // cout << cover << endl;
        while(k<n && pos[k].first <= cover){
          k++;
          cover = (cover < pos[k].second) ? cover : pos[k].second;
        }
        // cout << "+1 at : " << k << " and " << cover << endl;
        count++;
        cover = pos[k].second;
      }
      cout << "Case " << l << ": " << count-1 << "\n";
    }
    // else{
    //   int k = 0;
    //   sort(pos,pos+n);
    //   for(auto j:pos)
    //     if(j.first!=0) cout << j.first << " " << j.second << endl;
    //   while(k<n){
    //     while(k<n && pos[k].first-sqrt(d*d-pos[k].second*pos[k].second) <= cover){
    //       k++;
    //     }
    //     cout << k << " cover " << pos[k].first + sqrt(d*d - pos[k].second*pos[k].second) << endl;
    //     count++;
    //     cover = pos[k].first + sqrt(d*d - pos[k].second*pos[k].second);
    //   }
    //   cout << "Case " << l << ": " << count-1 << "\n";
    // }
    l++;
  }
}