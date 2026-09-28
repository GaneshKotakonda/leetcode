class Solution {
public:
    int maxDepth(string s) {
        int counter =0;
        int maxi =0;
        for ( char ch : s){
            if(ch=='('){
                counter++;
            }
            maxi = max(maxi , counter);
             if(ch==')'){
                counter--;
            }
        }
   
   return maxi;  }
};