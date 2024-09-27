#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, f;
  cin >> n;
  int food[n+10];
  for(int i = 0; i < n; i++){
    cin >> f;
    food[i] = f;
  }
  int prev = food[0], max = 1, streak = 1;
  for(int i = 1; i < n; i++){
    if(food[i] == prev+1)
      streak++;
    else
      streak = 1;
    if(streak > max)
      max = streak;
    prev = food[i];
  }
  //cout << max << ", " << streak << ", " << prev << endl;
  for(int i = 0; i < n; i++){
    //cout << food[i] << ", " << prev << endl;
    if(food[i] == prev+1)
      streak++;
    else
      break;
    prev = food[i];
    //cout << streak << endl;
  }
  if(streak > max)
    max = streak;
  cout << max;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//   int n, f;
//   cin >> n;
//   int food[n+10];
//   for(int i = 1; i <= n; i++){
//     cin >> f;
//     food[i] = f;
//   }
//   int max = 1, count = 0;
//   for(int i = 0; i < n; i++){
//     count = 0;
//     for(int j = 1; j <= n; j++){
//       int index = (i+j>n)? i+j-n:i+j;
//       //cout << index << ", " << food[index] << ", " << j << "\n";
//       if(food[index] == j){
//         count++;
//         //cout << i << " : " << count << "\n";
//       }
//     }
//     if(count > max)
//       max = count;
//   }
//   cout << max;
// }