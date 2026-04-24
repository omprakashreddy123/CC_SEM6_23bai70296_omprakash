class Solution {
public:
    bool check(int n,vector<int>& batteries,long long mid){
               long long total=0;
                long long required = 1LL * n * mid; 
               for(long long b:batteries){
                total+=min(b,mid);
               }
               if(total>=required){
                return true;
               }
               return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
     long long l=1;
     long long sum=0;
     long long r;
     long long ans=0;
        for(int i=0;i<batteries.size();i++){
            sum+=batteries[i];
        }
        r=sum/n;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(n,batteries,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
               r= mid-1;
            }
        }
        return ans;
    }
};
