class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }

        vector<pair<int,int>> temp;  // pair to keep track of both the ele and its freq
        for (auto it : mp) {
            temp.push_back({it.second, it.first}); 
            // as will be sorted based on the first ele of each pair i.e their freq
        }
        sort(temp.rbegin(), temp.rend()); // descending order

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(temp[i].second); // i.e that ele
        }
        return res;
    }
};
