#include <bits/stdc++.h>
using namespace std;

string input;
list<char> beiju;
list<char>::iterator pos;

int main() {
  while(getline(cin, input)){
    int isfront=0;
    for(auto k:input){
      if(k == '['){
        pos = beiju.begin();
        isfront = 1;
      }
      else if(k == ']')
        isfront = 0;
      else{
        if(isfront){
          beiju.insert(pos, k);
        }
        else
          beiju.push_back(k);
      }
    }
    for(auto k:beiju){
      cout << k;
    }
    cout << endl;
    beiju.clear();
  }
}