class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if(m>n) swap(m,n);
        int l=1;
        int r=9e8;
        while(l<=r){
            int mid=l + (r-l)/2;
            if(calc(m,n,mid)<k) l=mid+1;
            else r=mid-1;
        }
        return l;
    }

    int calc(int m, int n,int mid){
        int res=0;
        for(int i=1;i<=m;++i){
            res+=n*i<=mid?n:mid/i;
        }
        return res;
    }
};