class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj , vector<int>& vis ){
        vis[node] = 1;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]==1&&vis[i]==0){
                dfs(i , adj , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(), 0);
        int count =0;
        for(int i=0;i<isConnected.size();i++){
            if(vis[i]==0){
                count++;
                dfs(i ,isConnected , vis );
            }
        }
   return count; }
};