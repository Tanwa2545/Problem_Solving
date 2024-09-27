#include <iostream>
using namespace std;

int main() {
  int x=0,y=0,i=0;
  char arr[1100];
  cin >> arr;
  while(true){
    if (arr[i]=='N'){
      y+=1;
    }
    else if (arr[i]=='E'){
      x+=1;
    }
    else if (arr[i]=='S'){
      y-=1;
    }
    else if (arr[i]=='W'){
      x-=1;
    }
    else if (arr[i]=='Z'){
      if (x>0)
        x-=1;
      else if (x<0)
        x+=1;
      if (y>0)
        y-=1;
      else if (y<0)
        y+=1;
    }
    else
      break;
    i+=1;
  }
  cout << x << ' ' << y;
}