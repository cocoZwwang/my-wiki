#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
const int N=10010;
int n,k;
double L[N];

int calc(double len){
    int res=0;
    for(int i=0;i<n;++i) res+=(int)(L[i]/len);
    return res;
}
//标签：二分 求最大值 实数二分
// #define LOCAL
int main(){
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%lf",&L[i]);
    }
    double l=0,r=100010;
    //100 次循环精度可以达到 10^-30，基本上是没有问题的
    for(int i=0;i<100;i++){
       double md=(l+r)/2;
       if(calc(md)>=k) l=md;
       else r=md;
    }
    printf("%.2f\n",floor(r*100)/100);
    return 0;
}