class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        int n=queries.size();
        vector<int> arr;
        int lalla=0;
        for(int i=n-1; i>=-1; i--){
            if(i==-1){
                arr.push_back(0^lalla);
                break;
            }
            int value=queries[i][0];
            int xv=queries[i][1];
            if(value==0) arr.push_back(xv^lalla);
            else{
                lalla^=xv;
            }
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};
