class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            string word = "";
            // Collect characters of a word
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }
            if (!word.empty()) {
                words.push_back(word);
            }

            // Skip spaces between words
            while (i < n && s[i] == ' ') i++;
        }

        // Reverse the words vector
        reverse(words.begin(), words.end());

        // Join with a single space
        string result = "";
        for (int j = 0; j < words.size(); ++j) {
            result += words[j];
            if (j != words.size() - 1) result += ' ';
        }

        return result;
    }
};
