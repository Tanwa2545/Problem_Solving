#include<iostream>
#include<algorithm>
#define MAX_N 100009
using namespace std;
struct iv {
  int start_time;
  int end_time;
  friend bool operator<(const iv& l, const iv& r)
  {
    return false;
  }
};
pair<int, iv> intervals[MAX_N];
int main() {
  int n, count = 0, max = -1;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> intervals[i].second.start_time >> intervals[i].second.end_time;
    intervals[i].first = intervals[i].second.end_time;
    if(intervals[i].second.start_time > max) max = intervals[i].second.start_time;
  }
  sort(intervals, intervals+n);
  for(int i = 0; i < n; i++)
    cout << intervals[i].second.start_time << " " << intervals[i].second.end_time << endl;
  int start = intervals[0].second.start_time;
  int i = 0;
  while(true){
    while(true){
      if(intervals[i].second.start_time>=start){
        count++;
        start=intervals[i].second.end_time;
        break;
      }
      i++;
    }
    if(start > max)
      break;
  }
  cout << count;
}