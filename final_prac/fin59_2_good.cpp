#include <bits/stdc++.h>
using namespace std;
#define MAX_N 25

int goods[MAX_N][MAX_N];
int n,m;

int find_val(int x, int y){
  cout << x << " " << y << endl;
  int sum = 0,count = 0;
  for(int i=0;i<n;i++){
    if(i!=x){
      if(goods[i][y] > goods[x][y]) sum += goods[i][y]-goods[x][y];
      else sum += goods[x][y]-goods[i][y];
      count++;
    }
  }
  for(int i=0;i<m;i++){
    if(i!=y){
      if(goods[x][i] > goods[x][y]) sum += goods[x][i]-goods[x][y];
      else sum += goods[x][y]-goods[x][i];
      count++;
    }
  }
  //cout << x << " " << y << " : " << sum << " " << count << endl;
  return sum/count;
}

int main(){
  int min_d = 1e9,d,pos_x,pos_y;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> goods[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      d = find_val(i,j);
      //cout << "d = " << d << " " << min_d << endl;
      if(d < min_d){
        min_d = d;
        pos_x = i;
        pos_y = j;
        //cout << "min = " << min_d << " " << pos_x << " " << pos_y << endl;
      }
    }
  }
  cout << goods[pos_x][pos_y] << endl;
}