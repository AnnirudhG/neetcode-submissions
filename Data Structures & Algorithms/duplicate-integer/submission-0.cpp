class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }

        if(st.size() == nums.size()) return false;

        return true;
    }
};