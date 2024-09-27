#include <bits/stdc++.h>
using namespace std;

int ages[2000010];

void merge(int l, int m, int r){
  list<int> left(ages + l, ages + m + 1);
  list<int> right(ages + m + 1, ages + r + 1);
  // for(auto k:left)
  //   cout << k << ", ";
  // cout << endl;
  // for(auto k:right)
  //   cout << k << ", ";
  // cout << endl;
  // cout << left.size() << " size " << right.size() << endl;
  for(int i = l; i <= r; i++){
    if(left.empty()){
      ages[i] = right.front();
      right.pop_front();
    }
    else if(right.empty()){
      ages[i] = left.front();
      left.pop_front();
    }
    else if(left.front() < right.front()){
      ages[i] = left.front();
      left.pop_front();
    }
    else{
      ages[i] = right.front();
      right.pop_front();
    }
  }
}

void merge_sort(int l,int r){
  if(l==r) return;
  int m = (l+r)/2;
  merge_sort(l,m);
  merge_sort(m+1,r);
  merge(l,m,r);
}

int main() {
  int n;
  while(cin >> n){
    if(n==0) break;
    for(int i=1; i<=n; i++)
      cin >> ages[i];
    merge_sort(1,n);
    for(int i=1; i<=n; i++){
      cout << ages[i];
      if(i!=n)
        cout << " ";
    }
    cout << "\n";
  }
}