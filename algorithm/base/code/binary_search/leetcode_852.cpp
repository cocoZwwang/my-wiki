class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n=arr.length;
        int l=0, r=n-1;
        while(l<r){
            int md=(l+r)/2;
            if(arr[md+1]>arr[md]) l=md+1;
            else r=md;
        }
        return l;
    }
}