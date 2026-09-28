class Solution {
public:
    // Encodes a list of strings into a single string
    // Example: ["hello", "5star"] -> "5#hello5#5star"
    string encode(vector<string>& strs) {
        string encoded = "";
        
        for (auto s : strs) {
            // Append: length + delimiter + actual string
            encoded += to_string(s.size()) + "#" + s;
        }
        
        return encoded;
    }

    // Decodes a single string back into a list of strings
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        int n = s.size();

        while (i < n) {
            // Step 1: Find where '#' is located
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // Step 2: Extract length from index i to (j - 1)
            // s.substr(start_index, length_of_substring)
            // Starts at index 'i', takes (j - i) characters (stops right before '#')
            int length = stoi(s.substr(i, j - i));

            // Step 3: Extract actual string right after '#'
            // Starts at index (j + 1) for 'length' characters (indices: j + 1 to j + length)
            string str = s.substr(j + 1, length);
            decoded.push_back(str);

            // Step 4: Jump index 'i' to the start of the next block (index: j + 1 + length)
            i = j + 1 + length;
        }

        return decoded;
    }
};