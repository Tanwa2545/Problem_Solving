#include <iostream>
using namespace std;

int main() {
  long i,n,k,min=0,count=0;
  cin >> n >> k;
  long arr[n+10];
  for(i=0;i<n;i++){
    cin >> arr[i];
    if(i==0)
      min = arr[i];
    else if(arr[i]<min)
      min = arr[i];
  }
  for(i=0;i<n;i++){
    if(arr[i]*(k-1) < (min*k))
      count += 1;
  }
  cout << count;
}