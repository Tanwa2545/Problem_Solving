#include <bits/stdc++.h>
using namespace std;

set<int> boatcap;
list<int> week;
set<int>::iterator ite;
set<int>::reverse_iterator rite;

int main(){
  int n,m,x,y,count = 0;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    cin >> x;
    boatcap.insert(x);
  }
  for(int i=0;i<m;i++){
    cin >> y;
    week.push_back(y);
  }
  for(int i=0;i<m;i++){
    int current = week.front();
    week.pop_front();
    cout << endl;
    rite = boatcap.rbegin();
    //cout << "current week : " << i << " has " << current << " using " << *boatcap.lower_bound(current) << " max is " << *rite << "\n";
    if(current > *rite)
      break;
    ite = boatcap.lower_bound(current);
    count++;
    boatcap.erase(ite);
  }
  cout << count;
}