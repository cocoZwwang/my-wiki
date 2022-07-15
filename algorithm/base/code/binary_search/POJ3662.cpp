#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pi;
const int P=20100; // 要记得向前星无向边的容量是边数的两倍
const int N=1010;
int n,p,k,d[N],e[P];
priority_queue<pi,vector<pi>,greater<pi>> pq; //小根堆
struct Edge{
    int to, w,next;
}edges[P];
int id,head[P];

void add(int u, int v, int w){
    edges[++id].to=v;
    edges[id].next=head[u];
    edges[id].w=w;
    head[u]=id;
}

int djk(int x){
    memset(d,-1,sizeof(d));
    while(pq.size()) pq.pop(); //这里一定要注意清空队列
    d[1]=0;
    pq.push(make_pair(0,1));
    while(pq.size()){
        pi t=pq.top(); pq.pop();
        int w=t.first, u=t.second;
        if(u==n) break;
        if(d[u]!=-1&&d[u]<w) continue;
        for(int i=head[u];i;i=edges[i].next){
            int v=edges[i].to;
            if(d[v]==-1||(d[v]>d[u]+(edges[i].w>=x))){
                d[v]=d[u] + (edges[i].w>=x);
                pq.push(make_pair(d[v],v));
            }
        }
    }
    return d[n];
}

//#define LOCAL
int main(){
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d %d",&n,&p,&k);
    int u,v,w;
    for(int i=0;i<p;++i){
       scanf("%d %d %d",&u,&v,&w);
       add(u,v,w);
       add(v,u,w);
       e[i]=w;
    }
    int mik=djk(0);
    if(mik<0) printf("%d\n",-1);
    else if(mik<=k) printf("%d\n",0);
    else {
        sort(e,e+p);
        int l=1,r=p-1;
        while(l<=r){
            int md=(l+r)/2;
            int ret=djk(e[md]);
            if(ret<k+1) r=md-1;
            else l=md+1;
        }
        printf("%d\n",e[r]);
    }
}