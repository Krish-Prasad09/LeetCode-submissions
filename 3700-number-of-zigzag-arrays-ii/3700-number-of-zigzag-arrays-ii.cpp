#define ll long long int
#define mod 1000000007LL

class Solution {
public:
    vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B){
        int n=A.size();
        vector<vector<ll>> C(n,vector<ll>(n,0));

        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(A[i][k]==0) continue;
                for(int j=0;j<n;j++){
                    if(B[k][j]==0) continue;
                    C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
                }
            }
        }
        return C;
    }

    vector<vector<ll>> power(vector<vector<ll>> base,long long exp){
        int n=base.size();
        vector<vector<ll>> result(n,vector<ll>(n,0));

        for(int i=0;i<n;i++){
            result[i][i]=1;
        }

        while(exp){
            if(exp&1) result=multiply(result,base);
            base=multiply(base,base);
            exp>>=1;
        }
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        ll m=r-l+1;

        if(n==1) return m%mod;

        int S=2*m;

        vector<vector<ll>> T(S,vector<ll>(S,0));

        // Dk -> Ui  (k < i)
        for(int i=1;i<=m;i++){
            for(int k=1;k<i;k++){
                T[i-1][m+k-1]=1;
            }
        }

        // Uk -> Di  (k > i)
        for(int i=1;i<=m;i++){
            for(int k=i+1;k<=m;k++){
                T[m+i-1][k-1]=1;
            }
        }

        vector<ll> dp2(S,0);

        for(int v=1;v<=m;v++){
            dp2[v-1]=v-1;       // up[v]
            dp2[m+v-1]=m-v;    // down[v]
        }

        if(n==2){
            ll ans=0;
            for(ll x:dp2) ans=(ans+x)%mod;
            return ans;
        }

        vector<vector<ll>> P=power(T,n-2);

        vector<ll> finalState(S,0);

        for(int i=0;i<S;i++){
            for(int j=0;j<S;j++){
                finalState[i]=(finalState[i]+P[i][j]*dp2[j])%mod;
            }
        }

        ll ans=0;
        for(ll x:finalState){
            ans=(ans+x)%mod;
        }

        return ans;
    }
};