#include <iostream>
using namespace std;

int main() {
  int n,i,j,count=0;
  cin >> n;
  int arr[n+10];
  for(i=0;i<n;i++){
    cin >> arr[i];
  }
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      count += (arr[j] > arr[i])? 1:0;
    }
  }
  cout << count;
}