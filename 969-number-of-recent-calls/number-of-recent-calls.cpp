#include <queue>

class RecentCounter {
private:
    std::queue<int> q;

public:
    RecentCounter() {
        // No initialization needed
    }
    
    int ping(int t) {
        q.push(t);
        // Remove pings older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};
