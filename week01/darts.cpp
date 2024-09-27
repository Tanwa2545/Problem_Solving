#include <iostream>
using namespace std;

int main() {
  int n;
  int score = 0;

  cin >> n;
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    int d = x*x + y*y;
    if (d <= 4){
      score += 5;
    }
    else if (d <= 16){
      score += 4;
    }
    else if (d <= 36){
      score += 3;
    }
    else if (d <= 64){
      score += 2;
    }
    else if (d <= 100){
      score += 1;
    }
  }
  cout << score;
}