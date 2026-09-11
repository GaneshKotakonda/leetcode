class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int ans = nums[0];
        int pro = 1;
        for(int i =1;i<nums.size();i++){
            pro = pro * nums[i];
            if(nums[i]<0){
                swap(mini , maxi);
            }
            mini = min(nums[i], nums[i]*mini);
            maxi = max(nums[i], maxi*nums[i]);
            ans  = max(ans , maxi);
        }
  return ans;  }
};