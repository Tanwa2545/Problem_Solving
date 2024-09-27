#include <bits/stdc++.h>
using namespace std;

long long ages[100010];
long long inversion = 0;

void merge(int l, int m, int r){
  list<int> left(ages + l, ages + m + 1);
  list<int> right(ages + m + 1, ages + r + 1);
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
      inversion += left.size();
      // cout << "right less than left " << l << " " << m << " " << r << " " << left.size() << endl;
    }
  }
}

void count_inv(int l,int r){
  if(l==r) return;
  int m = (l+r)/2;
  count_inv(l,m);
  count_inv(m+1,r);
  merge(l,m,r);
}

int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> ages[i];
  count_inv(1,n);
  // for(int i=1; i<=n; i++){
  //   cout << ages[i];
  //   if(i!=n)
  //     cout << " ";
  // }
  cout << inversion << "\n";
}