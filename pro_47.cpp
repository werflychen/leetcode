//变种题：如果数组存在重复，则每次替换过的元素，不用再进行替换，用个map记录
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        
        map<int, bool> m_tmp;
        for (size_t i = cur; i < nums.size(); ++i) {
            if (m_tmp.find(nums[i]) != m_tmp.end()) {
                    continue;
            }
            m_tmp[nums[i]] = true;
            
            std::swap(nums[i], nums[cur]);
            do_permute(nums, cur + 1, result);
            std::swap(nums[i], nums[cur]);
        }
    }
};
