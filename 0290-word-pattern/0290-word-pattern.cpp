class Solution {
public:
    bool wordPattern(string pattern, string s) {
                // Split s into words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Check length match
        if (words.size() != pattern.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // If char already mapped
            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            }
            // If word already mapped
            else if (wordToChar.count(w)) {
                if (wordToChar[w] != c) return false;
            }
            // First time seeing this char and word → create mapping
            else {
                charToWord[c] = w;
                wordToChar[w] = c;
            }
        }

        return true;
    }
};