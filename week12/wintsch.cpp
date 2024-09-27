#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1010

int start[MAX_N];
int endd[MAX_N];
int weight[MAX_N];
int max_val[MAX_N];
int prevind[MAX_N];

void find_max(int n){
  int s = start[n], i=0;
  //cout << "current : " << n;
  if(n<=0) return;
  while(i<n){
    if(endd[n-i] <= s)
      break;
    i++;
  }
  if(max_val[n-1] == 0)
    find_max(n-1);
  //cout << "current : " << n << " and " << i << ", comparing " << max_val[n-1] << " and " << max_val[n-i] + weight[n];
  max_val[n] = max(max_val[n-1], max_val[n-i] + weight[n]);
  if(max_val[n-i]+weight[n] > max_val[n-1]){
    prevind[n] = n-i;
  }
  else{
    prevind[n] = n-1;
  }
  //cout << ", max : " << max_val[n] << ", previous : " << prevind[n] << endl;
  return;
}

int main() {
  int n;
  list<int> ans;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> start[i] >> endd[i] >> weight[i];
    max_val[i] = 0;
  }
  max_val[0] = 0;
  prevind[0] = 0;
  find_max(n);
  cout << max_val[n] << "\n";
  int tmp = n, count = 0;
  while(true){
    count++;
    ans.push_front(tmp);
    if(prevind[tmp] == 0) break;
    tmp = prevind[tmp];
  }
  cout << count << "\n";
  // for(int i=1;i<=n;i++)
  //   cout << prevind[i] << " ";
  // cout << "\n";
  for(auto k:ans)
    cout << k << " ";
}