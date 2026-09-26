class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;
        
        vector<int> Count_Alphabet(26,0);

        for (int i=0; i<s.length(); i++) {
            Count_Alphabet[s[i] - 'a'] ++;
            Count_Alphabet[t[i] - 'a'] --;
        }

        for(auto it : Count_Alphabet) {
            if(it !=0) return false;
        }

        return true;
    }
};

// T -> O(n+m)
// S -> O(1)