#include <bits/stdc++.h>
#include "probelib.h"
#include <cstdio>
using namespace std;

int n;
int ans;

int probing(int s, int e){
  if(e == s) return e;
  if(probe_check(s, (s+e)/2)){
    return probing(s, (s+e)/2);
  }
  else{
    return probing((s+e)/2+1, e);
  }
}

int main(){
  int n = probe_init();
  int ans = probing(0,n);
  probe_answer(ans);
}