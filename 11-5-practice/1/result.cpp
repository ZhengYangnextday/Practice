#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define ll long long
const int mod = 1e9 + 7;
ll c2(int n){
  ll cal = n;
  cal = cal * (cal - 1) / 2;
  return cal % mod;
}
ll calculate(ll* a, int index){
  ll now = c2(a[index]);
  ll other = 0;
  for(int i = index - 1; i >= index - 1 -i; i--){
    if(i == index - 1 -i){
      other += c2(a[index - 1 - i]);
      other = other % mod;
      break;
    }
    else{
      other += a[i] * a[index - 1 - i];
      other = other % mod;
    }
  }
  now = now * other % mod;
  return now;
}
int main(){
  ll* a = (ll*)malloc(5000 * sizeof(ll));//分配内存空间
  ll result = 0;
  memset(a, 0, 5000 * sizeof(ll));//初始化，将所有数据置为0
  int n = 0;
  scanf("%d", &n);
  int index = -1;
  for(int i = 0; i < n; i++){  
    scanf("%d", &index);
    index--;
    a[index]++;
  }
  for(int i = 0; i < 5000; i++){
    if(n <= 0){
      break;
    }
    result += calculate(a, i);
    result = result % mod;
    n -= a[i];
  }
  printf("%lld", result);
  return 0;
}