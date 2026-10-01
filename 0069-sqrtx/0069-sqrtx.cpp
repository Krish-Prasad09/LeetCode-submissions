class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int s=1, e=x/2+1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(1LL*mid*mid<=x){
                s=mid+1;
            }
            else e=mid-1;
        }
        return e;
    }
};