class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=n-1, j=m-1;
        vector<int> right(n,0);
        int righm=0;
        while(i>=0){
            if (j >= 0 && word1[i] == word2[j]){
                righm++;
                j--;
            }
            right[i]=righm;
            i--;
        }
        bool replace=true;
        i=0,j=0;
        vector<int> seq;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(replace && (i<n-1 && right[i+1]>=m-j-1)){
                seq.push_back(i);
                j++;
                replace=false;
            }
            i++;
        }
        if (j != m) return {};
        return seq;
    }
};