class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int maxCount = 0, currentCount = 0;

        // Initialize first window
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) currentCount++;
        }
        maxCount = currentCount;

        // Slide the window
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i - k])) currentCount--; // remove left char
            if (isVowel(s[i])) currentCount++;     // add right char
            maxCount = max(maxCount, currentCount);
        }

        return maxCount;
    }
};
