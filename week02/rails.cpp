#include <bits/stdc++.h>
using namespace std;

//string input;
list<int> inpblock;
list<int> station;

int main() {
  int input,n;
  while(true){
    cin >> input;
    if(input == 0){
      break;
    }
    else{
      int endofblock = 0;
      while(!endofblock){
        int trainnum = 1, k;
        inpblock.clear();
        station.clear();
        for(int i = 0; i < input; i++){
          cin >> n;
          if(n == 0){
            endofblock = 1;
            break;
          }
          else{
            inpblock.push_back(n);
          }
        }
        if(!endofblock){
          for(int i=0; i<input; i++){
            k = inpblock.front();
            if(!station.empty() || station.front() != k || k<=input){
              for(int j=trainnum; j<=k; j++){
                //cout << "add" << j << ", ";
                station.push_front(trainnum);
                trainnum++;
              }
            }
            //cout << k << station.front();
            if(station.front() == k){
              //cout << "popping" << station.front() << ", ";
              station.pop_front();
            }
            inpblock.pop_front();
          }
          if(station.empty()) cout << "Yes";
          else cout << "No";
        }
        cout << "\n";
      }
    }
  }
}
  /*while(getline(cin, input)){
    int endofblock = 1,trainnum = 1, n, k, line = stoi(input);
    while(endofblock){
      for(int i = 0; i < line; i++){
        cin >> n;
        if(n == 0){
          endofblock = 0;
          break;
        }
        else{
          inpblock.push_back(n);
        }
      }
      if(!endofblock){
        for(int i=0; i<line; i++){
          k = inpblock.front();
          if(!station.empty() && station.front() != k && k<=line){
            for(int j=trainnum; j<=k; j++){
              station.push_back(trainnum);
              trainnum++;
            }
          }
          if(station.front() == k)
            station.pop_front();
          inpblock.pop_front();
        }
        if(station.empty()) cout << "YES";
        else cout << "NO";
      }
      cout << "\n";
    }
  }*/