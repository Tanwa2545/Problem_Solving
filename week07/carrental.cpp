#include <bits/stdc++.h>
using namespace std;

int contract[110], trip[110], weight[110], parcel[1010];

int main() {
  int k, n;
  cin >> k >> n;
  for(int i=0;i<k;i++){
    cin >> contract[i] >> trip[i] >> weight[i];
  }
  for(int i=0;i<n;i++){
    cin >> parcel[i];
  }
  int cheapest = 1e9;
  for(int i=0;i<k;i++){
    int maxcarry = weight[i], count = 1, allow = 1, sum = 0;
    for(int j=0;j<n;j++){
      if(parcel[j] > maxcarry){
        allow = 0;
        break;
      }
      if(sum + parcel[j] > maxcarry){
        sum = parcel[j];
        count++;
      }
      else if(sum + parcel[j] == maxcarry){
        sum = 0;
        count++;
      }
      else
        sum += parcel[j];
    }
    if(contract[i] + (trip[i]*count) < cheapest && allow)
      cheapest = contract[i] + (trip[i]*count);
    //cout << "Current : " << i << " is : " << cheapest << ", " << contract[i] << ", " << count << endl;
  }
  cout << cheapest << "\n";
}