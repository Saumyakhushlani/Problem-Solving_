class Solution {
  public:
    void solve(vector<int>& c, int target, vector<int>& tmp,vector<vector<int>>& res, int sum,int idx){
        if(sum>target|| idx==c.size()){
            return;
        }
        else if(sum==target){
            res.push_back(tmp);
            return;
        }
        tmp.push_back(c[idx]);
        solve(c,target,tmp,res,sum+c[idx],idx);
        tmp.pop_back();
        solve(c,target,tmp,res,sum,idx+1);

    }
    vector<vector<int>> targetSumComb(vector<int> &candidates, int target) {
        // code here
        vector<vector<int>>res;
        vector<int>tmp;
        solve(candidates,target,tmp,res,0,0);
        return res;
    }
};