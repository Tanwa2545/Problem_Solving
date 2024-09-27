#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
  int n,max = 1;
  cin >> n;
  int order[n+10];
  int alrd_chk[n+10];
  for(int i=1;i<=n;i++){
    cin >> order[i];
    alrd_chk[i] = 0;
  }
  for(int i=1;i<=n;i++){
    int count = 1,index = i;
    while(order[index] != i && count < n && alrd_chk[index] != 1){
      alrd_chk[index] = 1;
      index = order[index];
      count++;
    }
    if (count > max){
      max = count;
    }
  }
  cout << max;
}