class Solution {
public:
int k=0;
    void backtrack(int index , int sum , int target , vector<vector<int>>&ans,
    vector<int>&curr , vector<int> nums ){
         if(sum==target){
                ans.push_back(curr);
                return;
            }
            if(sum >target || index==nums.size()){
                return;
            }
            
           

            curr.push_back(nums[index]);
            sum+=nums[index];
           

            backtrack(index, sum , target , ans , curr , nums);

            curr.pop_back();
            sum-= nums[index];
            backtrack(index+1, sum , target , ans , curr , nums);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(0 , 0 ,target , ans ,curr ,candidates );
        return ans;

    }
};