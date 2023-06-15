class Solution {
public:
    void subsethelper(vector<int>&nums, int index, vector<int> &subset, vector<vector<int>> &ans)
    {
        if(index == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        //include ith ele
        subset.push_back(nums[index]);
        //ask recursion to do task
        subsethelper(nums, index+1,subset, ans);
        //donot include ith element
        subset.pop_back();
        //ask recursion to do task
        while(index+1 < nums.size() && nums[index] == nums[index+1])
        {
            index++;
        }
        subsethelper(nums, index+1, subset, ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        subsethelper(nums, 0, subset, ans);
        return ans;
    }
};
