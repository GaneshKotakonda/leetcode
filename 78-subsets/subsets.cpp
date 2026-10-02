class Solution {
public:
    void backtrack( int index,vector<int>& nums, vector<int>& curr , vector<vector<int>>& ans ){
            if(index == nums.size()){
                ans.push_back(curr);
                return ;
            }
           
        curr.push_back(nums[index]);
        backtrack(index+1, nums, curr , ans);
        curr.pop_back();
        backtrack(index+1, nums, curr, ans);



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(0 , nums,curr , ans);
        return ans;
    }
};