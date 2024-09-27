#include <bits/stdc++.h>
using namespace std;
#define MAX_M 5010

struct iv {
  int l, r;
  // Custom comparison function
  bool operator<(const iv& other){
    int diff1 = r - l;
    int diff2 = other.r - other.l;
    if (diff1 != diff2) {
      // Sort by largest difference first
      return diff1 > diff2;
    } else {
      // If differences are equal, sort by lower l value
      return l < other.l;
    }
  }
};

int main() {
  int n,m,l,r,nline,current,count;
  cin >> n;
  for(int i=0;i<n;i++){
    vector<iv> intervals;
    vector<pair<int, int>> ans;
    nline = 0;
    cin >> m;
    while(true){
      cin >> l >> r;
      if(l==0 && r==0) break;
      intervals.push_back({l,r});
      nline++;
    }
    sort(intervals.begin(), intervals.end());
    // cout << "Sorted intervals for test case " << i + 1 << ":" << endl;
    // for (const auto& interval : intervals)
    //   cout << interval.l << " " << interval.r << endl;
    current = 0;
    count = 0;
    ans.clear();
    for(int j=0;j<nline;j++){
      if(intervals[j].r > current && intervals[j].l <= current){
        count++;
        current = intervals[j].r;
        ans.push_back({intervals[j].l, intervals[j].r});
      }
      if(current > m) break;
    }
    if(i!=0) cout << "\n";
    if(!count)
      cout << count;
    else{
      cout << count << "\n";
      for(auto k:ans)
        cout << k.first << " " << k.second << "\n";
    }
  }
}

// int main() {
//   int n,m,l,r,nline;
//   cin >> n;
//   for(int i=0;i<n;i++){
//     nline = 0;
//     cin >> m;
//     while(true){
//       cin >> l >> r;
//       if(l==0 && r==0) break;
//       intervals[i].first = -(r-l);
//       intervals[i].second.first = l;
//       intervals[i].second.second = r;
//       nline++;
//       cout << intervals[i].first << " " << intervals[i].second.first << " " << intervals[i].second.second << endl;
//     }
//     cout << nline << endl;
//     sort(intervals, intervals+nline);
//     for(int j=0;j<MAX_M;j++)
//       if(intervals[j].first != 0)
//         cout << intervals[j].second.first << " " << intervals[j].second.second << endl;
//   }
// }