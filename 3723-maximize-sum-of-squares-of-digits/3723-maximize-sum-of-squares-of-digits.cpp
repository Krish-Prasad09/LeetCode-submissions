class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        vector<int> arr(n,0);
        for(int i=0; i<n; i++){
            if(sum<=9 && sum>=0){
                arr[i]=sum;
                sum-=sum;
            }
            else if(sum>9){
                arr[i]=9;
                sum-=9;
            }
        }
        if(sum>0) return "";
        string s;
        for(int i=0; i<n; i++){
            s+=(arr[i]+'0');
        }
        return s;
    }
};