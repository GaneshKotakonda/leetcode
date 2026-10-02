class Solution {
public:
  void backtrack(int n ,string& curr, vector<string>& ans, int open , int close ){

        if(curr.size()==n*2){

            ans.push_back(curr);
        }
if(open<n){
curr.push_back('(');
   backtrack(n ,curr, ans, open+1, close);
     curr.pop_back();
}
if(open>close){

curr.push_back(')');
     backtrack(n ,curr, ans, open , close+1);
       curr.pop_back();
}

  }
    vector<string> generateParenthesis(int n) {


        string curr;
        vector<string> ans;
        backtrack(n,curr, ans, 0 , 0);
        return ans;


    }
};