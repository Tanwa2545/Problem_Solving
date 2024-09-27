#include <iostream>
using namespace std;

int main() {
  int n, size = 0, max = 1;
  int count[300];
  cin >> n;
  for(int i=0;i<300;i++){
    count[i] = 0;
  }
  for(int i=0;i<n;i++){
    cin >> size;
    count[size-1]+=1;
  }
  for(int i=0;i<300;i++){
    if(count[i]!=0 && count[i]>max){
      max = count[i];
    }
  }
  cout << max;
}