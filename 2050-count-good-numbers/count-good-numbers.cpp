class Solution {
public:
    long long powi(long long x , long long n){
        long long mod = 1000000007;
        if(n==0){
            return 1;
        }
            long long half = powi(x, n/2);
            if(n%2==0){

                return (half* half) % mod;
            }else{
                return (half* half*x) % mod;
            }
    }
    int countGoodNumbers(long long n) {
        long long mod = 1000000007;
        if(n%2==0){
            return (powi(5,(n/2))*powi(4, (n/2))%mod);
        }else{
            return (powi(5, (n/2)+1)*powi(4, (n/2))%mod);
        }
    }
};