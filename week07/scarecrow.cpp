#include <bits/stdc++.h>
using namespace std;

char field[110];
int cover[110];

int main() {
  int t,n,count;
  cin >> t;
  for(int i=0;i<t;i++){
    count = 0;
    cin >> n;
    for(int j=0;j<n;j++){
      cover[j] = 0;
    }
    for(int j=0;j<n;j++){
      cin >> field[j];
    }
    for(int j=0;j<n;j++){
      if(field[j]=='.' && cover[j]!=1){
        //cout << "+1 at " << j+1 << endl;
        count+=1;
        cover[j]=1;
        cover[j+1]=1;
        cover[j+2]=1;
      }
    }
    cout << "Case " << i+1 << ": " << count << "\n";
  }
}
//not need cover but just skip 3 tiles instead and use while