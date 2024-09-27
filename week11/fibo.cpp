#include <bits/stdc++.h>
using namespace std;

int fibval[100010];

int fib(int n){
  if(n==0) return 0;
  if(n==1) return 1;
  if(fibval[n]!=0) 
    return fibval[n];
  fibval[n] = (fib(n-1)+fib(n-2)) % 199933;
  return fibval[n];
}

int main() {
  int n;
  cin >> n;
  cout << fib(n);
}