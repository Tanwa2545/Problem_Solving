#include <iostream>
using namespace std;

int main() {
  int n,t,prev;
  cin >> n >> t;
  int inp[n+10], code[n+10];
  for(int i = 0; i < n; i++){
    cin >> inp[i];
    code[i] = 0;
  }
  if(t == 2){
    for(int i=1;i<n;i++){
      prev = inp[i-1];
      if (inp[i]-prev > prev){
        inp[i] = inp[i] - 2*prev;
      }
      else{
        inp[i] = inp[i] - prev;
      }
    }
  }
  //prev = inp[0];
  for(int i=1;i<n;i++){
    prev = inp[i-1];
    code[i] = (inp[i] > prev)? 1:0;
  }
  code[0] = (inp[0] > n)? 1:0;
  for(int i = 0; i < n; i++){
    cout << code[i] << "\n";
  }
}