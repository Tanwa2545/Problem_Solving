#include <bits/stdc++.h>
using namespace std;

vector<int> price(100010);

int main() {
  int i,j,tmp,totalprice=0;
  cin >> i >> j;
  for(int k = 0; k < i; k++){
    cin >> tmp;
    totalprice+=tmp;
    price[k]=totalprice;
  }
  for(int k = 0; k < j; k++){
    cin >> tmp;
    auto n = upper_bound(price.begin(),price.begin()+i,tmp);
    cout << (n-price.begin()) << endl;
  }
}