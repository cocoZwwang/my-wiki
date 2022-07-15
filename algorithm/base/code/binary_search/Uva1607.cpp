#include <bits/stdc++.h>
using namespace std;
const int N=100010;
const int M=200010;
struct gate{
    int a,b,o;
}gates[M];
int n,m;

int calc(int cnt){
    for(int i=1;i<=m;++i){
        int a=gates[i].a;
        int b=gates[i].b;
        int ia=a<0?(-a<=cnt):gates[a].o;
        int ib=b<0?(-b<=cnt):gates[b].o;
        gates[i].o=~(ia&ib);
        gates[i].o&=1;
    }
    return gates[m].o;
}

// #define LOCAL
int main(){
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;++i){
            scanf("%d %d",&gates[i].a,&gates[i].b);
        }
        int u=calc(0);
        int v=calc(n);
        if(u==v){
            for(int i=0;i<n;++i) printf("%c",'1');
            printf("\n");
        }else{
            int l=0,r=n;
            while(l<r){
                int md=(l+r)/2;
                if(calc(md)==u) l=md+1;
                else r=md;
            } 
            char ch;
            for(int i=1;i<=n;++i){
                ch=i<r?'1':(i==r?'x':'0');
                printf("%c",ch);
            }
            printf("\n");
        }
    }
    return 0;
}