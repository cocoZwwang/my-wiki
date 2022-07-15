#include <cstdio>
#include <cstring> 
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100010;
int n, c,x[N];

bool check(int k,int cnt){
    cnt--;
    for(int i=1,j=0;i<n&&cnt;i++){
        if(x[i]-x[j]>=k){
            j=i;
            cnt--;
        }
    } 
    return cnt==0;
}
//标签：二分 最大值最小
// #define LOCAL
int main(){
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;++i) scanf("%d",&x[i]);
    sort(x,x+n);
    int l=0,r=x[n-1]-x[0];
    while(l<=r){
        int md=l+(r-l)/2;
        if(check(md,c)) l=md+1;
        else r=md-1;
    }
    printf("%d\n",r);
}