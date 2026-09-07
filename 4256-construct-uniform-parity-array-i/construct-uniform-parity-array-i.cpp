class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> nums2(nums1.size(),0);
            //all even 
            int even =1;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                nums2[i]=nums1[i];
            }else{
                for(int j=0;j<nums1.size();j++){
                    if(j==i)continue;
                    if((nums1[i] -nums1[j])%2==0){
                        nums2[i]=nums1[i];
                    }
                }
                if(nums2[i]==0){
                    even =0;
                    break;
                }
            }
        }

        //all odd;
         int odd =1;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                nums2[i]=nums1[i];
            }else{
                for(int j=0;j<nums1.size();j++){
                    if(j==i)continue;
                    if((nums1[i] -nums1[j])%2!=0){
                        nums2[i]=nums1[i];
                    }
                }
                if(nums2[i]==0){
                    odd =0;
                    break;
                }
            }
        }

   if(odd || even ){
    return true;
   } else{
    return false;
   }
   }
};