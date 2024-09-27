#include <bits/stdc++.h>
#define MAX_N 100010
using namespace std;

pair<int, int> jobs[MAX_N];
set<int> fee;

int main() {
  int n,d,c,current = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> d >> c;
    jobs[i] = {d, c};
  }
  sort(jobs,jobs+n);
  // for(int i=0;i<n;i++){
  //   cout << jobs[i].first << " " << jobs[i].second << endl;
  // }
  for(int i=0;i<n;i++){
    current += jobs[i].second;
    if(current > jobs[i].first + 10)
      fee.insert(current - jobs[i].first - 10);
  }
  // for(auto i : fee){
  //   cout << i << endl;
  // }
  // cout << *fee.rbegin() << " " << *fee.end() << endl;
  if(fee.empty())
    cout << "0" << endl;
  else
    cout << *fee.rbegin()*1000;
}