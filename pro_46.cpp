//关键点：问题可以被描述为一个更小规模的一个子问题，所以可以采用递归解决问题
//全排列问题：描述为每次从数组中取一个数，该数与剩下的子数组的组成的全排列，即是问题的解

class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }    
        
        do_permute(nums, 0, result);
        return result;
    }
    
    void do_permute(vector<int>& nums, int cur, vector<vector<int>>& result) {
        if (cur == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        
        for (size_t i = cur; i < nums.size(); ++i) {
            std::swap(nums[i], nums[cur]);
            do_permute(nums, cur + 1, result);
            std::swap(nums[i], nums[cur]);
        }
    }
};



//非递归算法，采用字典序的解法，待补充
