class Solution {
public:
typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<vector<int>> vec(n,vector<int>(3,0));
        for(int i=0; i<n; i++){
            vec[i][0]=nums1[i];
            vec[i][1]=i;
            vec[i][2]=nums2[i];
        }
        sort(vec.begin(),vec.end());
        vector<ll> result(n,0);
        priority_queue<int,vector<int>,greater<int>> pq;
        ll sum=0;

        for(int i=0; i<n; i++){
            if(i>0 && vec[i-1][0]==vec[i][0]){
                result[vec[i][1]]=result[vec[i-1][1]];
            }
            else result[vec[i][1]]=sum;
            sum+=vec[i][2];
            pq.push(vec[i][2]);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
        }
        return result;
    }
};