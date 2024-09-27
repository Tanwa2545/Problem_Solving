#include <iostream>
using namespace std;

int main() {
  int n,k,t, count=0, pos=1, check=0;
  cin >> n >> k >> t;
  while((pos!=1 || check==0) && pos!=t){
    check = 1;
    pos += (pos+k > n)? k-n:k;
    count+=1;
  }
  count += (pos==t)? 1:0;
  cout << count;
}