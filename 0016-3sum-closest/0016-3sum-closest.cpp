class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n=arr.size();
        int mini=INT_MAX;
        int ans=0;
        sort(arr.begin(),arr.end());
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(i!=j && i!=k && j!=k){
        //                 int sum=arr[i]+arr[j]+arr[k];
        //                 if(abs(target-sum)<mini){
        //                     mini=abs(target-sum);
        //                     ans=sum;
        //                 }
        //                 else if(abs(target-sum)>mini) break;
        //             }
        //         }
        //     }
        // }
        
        
        for(int i=0; i<n-2; i++){
            int l=i+1, r=n-1;
            while(l<r){
                int sum=arr[i]+arr[l]+arr[r];
                if(sum>target){
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                if(sum==target){
                    return target;
                }
                if(abs(target-sum)<mini){
                            mini=abs(target-sum);
                            ans=sum;
                        }
            }

        }
        return ans;
    }
};