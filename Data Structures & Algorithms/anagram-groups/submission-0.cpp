class Solution {
public:
// This is Wrong solution, the approach, and the idea to sort and then use map is correct. But the implementation is wrong & inefficient
        // vector<string> dup;
        // for (int i=0; i<strs.size(); i++) {
        //     dup.push_back(strs[i]);
        //     // cout<<i<<" ";
        // }
        // for (auto i : dup) {
        //     sort(i.begin(), i.end());
        //     // cout<<i<<" ";
        // }
        // unordered_map<string, vector<int>> mp;
        // for(int i=0; i<dup.size(); i++) {
        //     mp[dup[i]].push_back(i);
        // }
        // vector<vector<string>> ans;
        // for(auto it : mp) {
        //     vector<string>temp;
        //         for(int i=1; i<=it.second.size(); i++) {
        //             temp.push_back(strs[i]);
        //         }
        //      ans.push_back(temp);
        // }
        // return ans;


// Brute Force - with Correct implementation:  Map: (string -> vector<string>)
// Key-> sorted word (unique)
// Aur Value-> vector of words correspondng to this key

// In 1 iteraion: ek Copy le word ka, uska sorted version ko Key bana (kyuki woh unique rahega),
// fir iterate krke; uss same key k liye joh values aayenge (apne Input strs ke) usko daalte rahe

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> mp;
    for(auto s : strs) {
        string C = s;
        sort(C.begin(), C.end());
        mp[C].push_back(s);
    }

    vector<vector<string>> ans;
    for(auto it : mp) {
        vector<string> temp;
        for(int i=0; i<it.second.size(); i++) {
            temp.push_back(it.second[i]);
        }
        ans.push_back(temp);
    }
    return ans;
    
    }
};
