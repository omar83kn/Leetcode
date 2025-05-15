#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant, dire;

        // Initialize queues with the indices of senators
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Simulate rounds
        while (!radiant.empty() && !dire.empty()) {
            int r_index = radiant.front();
            int d_index = dire.front();
            radiant.pop();
            dire.pop();

            if (r_index < d_index) {
                // Radiant bans Dire
                radiant.push(r_index + n);
            } else {
                // Dire bans Radiant
                dire.push(d_index + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
