#include <bits/stdc++.h>
using namespace std;
#define MAX_N 110

int morning[MAX_N];
int evening[MAX_N];

int main() {
  int n,d,r,total;
  while(cin >> n >> d >> r){
    total = 0;
    if(n==0 && d==0 && r==0) break;
    for(int i=0;i<n;i++)
      cin >> morning[i];
    for(int i=0;i<n;i++)
      cin >> evening[i];
    sort(morning,morning+n);
    sort(evening,evening+n);
    reverse(evening,evening+n);
    for(int i=0;i<n;i++){
      if(morning[i] + evening[i] > d){
        total += (morning[i] + evening[i] - d) * r;
      }
    }
    cout << total << "\n";
  }
}