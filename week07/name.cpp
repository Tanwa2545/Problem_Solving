#include <bits/stdc++.h>
using namespace std;

string s,t;

int main(){
  cin >> s >> t;
  int n=0, strlen = s.length(), count = 0;
  for(int i=0; i < t.length();i++){
    if(t[i]==s[n]){
      n++;
      if(n>=strlen){
        count++;
        n=0;
      }
    }
  }
  cout << count << "\n";
}