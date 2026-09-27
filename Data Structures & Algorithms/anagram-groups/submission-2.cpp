class Solution {
public:

vector<vector<string>> groupAnagrams(vector<string>& strs) {

// unordered_map<vector<int> , vector<string>> mp;  --> Can't use
//In C++:  unordered_map does not have a built-in hash function for vector<int>, 
// so using vector<int> as a key causes a compilation error.

// Instead Convert the freq Array for each Word: into a String, and use that as KEY
   
    unordered_map<string, vector<string>> mp;
    for(auto s : strs) {
        vector<int> f(26,0);
        for(char c : s) {
            f[c -'a']++;
        }

    // Convert character frequencies into a unique string key , and For that String Use;
    // separator to avoid collision : "111" for both [1,11] and [11,1] is incorrect. hence use separaotr in btw
        string Key = "";
        for(int i=0; i<26; i++) {
            Key += "Separator" + to_string(f[i]);   
        }

        mp[Key].push_back(s);
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

// T --> O(m.n)    : m->no. of words.  &  n->length of the word
// In our Brute force, Sorting appraoch: T --> O(m. nlog(n))
