class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // vector<int> ans;

// This is Wrong Solution -> We cannot just sort the array, since its asked to return the 
// indices of those elements. once we sort it, we will lose those unique indices.. also in line 14,15;
// we need to return.. otherwise it will go in a an infinite loop..

        // sort(nums.begin(), nums.end());
        // int s = 0;  int e = nums.size()-1;
        // while(s<e) {
        //     if((nums[s] + nums[e]) == target) {
        //         ans.push_back(s);
        //         ans.push_back(e);
        //     }
        //     else if((nums[s] + nums[e]) < target) {
        //         s++;
        //     }
        //     else{
        //         e--;
        //     }
        // }
        // return ans;

// We need to store the Indices of the elements, say with help of pair<int,int>..then Sort that 
// vector of pairs..and then Apply 2pointer Approach, ..

    vector<pair<int,int>> v;
    for(int i=0; i<nums.size(); i++) {
        v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end());  // its gets sorted based on the 1st ele of pair (nums[i])

    int s = 0;
    int e = nums.size()-1;

    while(s<e) {
        int K = (v[s].first + v[e].first);   // Not used (nums[s] + nums[e]) --> kyuki thats not SORTED

        if(K == target) { // its given: Return the answer with the smaller index first, hence
            int mini = min(v[s].second , v[e].second);
            int maxi = max(v[s].second , v[e].second);
            return {mini, maxi};
        }

        else if(K < target) s++;

        else e--;
    }

    return {-1,-1};  //in case a pair is not found
    }
};

// T-> O(N.logN)
// S-> O(N)