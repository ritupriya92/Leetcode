class Solution {
public:
    void subsetHelper(vector<int>&nums, int index, vector<int> &sub, vector<vector<int>> &ans)
    {
        if(index == nums.size()) {
            ans.push_back(sub);
            return;
        }
        //include ith ele
        sub.push_back(nums[index]);
        subsetHelper(nums, index+1, sub, ans);

        //pop ith ele
        sub.pop_back();
        subsetHelper(nums, index+1, sub, ans);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        subsetHelper(nums, 0, sub, ans);
        return ans;
    }
};
