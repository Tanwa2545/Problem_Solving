#include <bits/stdc++.h>
using namespace std;



int traversemaze(string &board[],int x, int y, int jump, int n){
  if(x==n-1 && y==n-1)
    return 1;
  string newboard = board;
  set<int> pathlength;
  newboard[x][y] = "#";
  if(x+1<n && newboard[x+1][y] != "#"){
    pathlength.insert(traversemaze(newboard,x+1,y,jump,n));
  }
  if(y+1<n && newboard[x][y+1] != "#"){
    pathlength.insert(traversemaze(newboard,x,y+1,jump,n));
  }
  if(x-1>=0 && newboard[x-1][y] != "#"){
    pathlength.insert(traversemaze(newboard,x-1,y,jump,n));
  }
  if(y-1>=0 && newboard[x][y-1] != "#"){
    pathlength.insert(traversemaze(newboard,x,y-1,jump,n));
  }
  if(!jump){
    jump = 1;
    if(x-2>=0 && y+1<n && newboard[x-2][y+1] != "#"){
      pathlength.insert(traversemaze(newboard,x-2,y+1,jump,n));
    }
    if(x-2>=0 && y-1>=0 && newboard[x-2][y-1] != "#"){
      pathlength.insert(traversemaze(newboard,x-2,y-1,jump,n));
    }
    if(x-1>=0 && y+2<n && newboard[x-1][y+2] != "#"){
      pathlength.insert(traversemaze(newboard,x-1,y+2,jump,n));
    }
    if(x-1>=0 && y-2>=0 && newboard[x-1][y-2] != "#"){
      pathlength.insert(traversemaze(newboard,x-1,y-2,jump,n));
    }
    if(x+1<n && y+2<n && newboard[x+1][y+2] != "#"){
      pathlength.insert(traversemaze(newboard,x+1,y+2,jump,n));
    }
    if(x+1<n && y-2>=0 && newboard[x+1][y-2] != "#"){
      pathlength.insert(traversemaze(newboard,x+1,y-2,jump,n));
    }
    if(x+2<n && y+1<n && newboard[x+2][y+1] != "#"){
      pathlength.insert(traversemaze(newboard,x+2,y+1,jump,n));
    }
    if(x+2<n && y-1>=0 && newboard[x+2][y-1] != "#"){
      pathlength.insert(traversemaze(newboard,x+2,y-1,jump,n));
    }
  }
  int shortest = *pathlength.rend();
  return shortest+1;
}

int main(){
  int n;
  cin >> n;
  string cboard[n+10];
  for(int i=0;i<n;i++){
    cin >> cboard[i];
  }
  int shortestpath = traversemaze(cboard,0,0,0,n);
  for(int i=0;i<n;i++){
    for(auto k:cboard[i])
      cout << k << " ";
    cout << endl;
  }
  cout << shortestpath;
}