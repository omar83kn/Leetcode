#include <vector>

class ATM {
private:
    std::vector<long long> notes; // Count of banknotes for $20, $50, $100, $200, $500
    const std::vector<int> denominations = {20, 50, 100, 200, 500};

public:
    ATM() {
        notes = std::vector<long long>(5, 0); // Initialize with 0 notes for each denomination
    }
    
    void deposit(std::vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            notes[i] += banknotesCount[i];
        }
    }
    
    std::vector<int> withdraw(int amount) {
        std::vector<long long> tempNotes = notes; // Create a copy to avoid modifying original if withdrawal fails
        std::vector<int> result(5, 0); // Result array for withdrawn notes
        
        // Try to withdraw from largest to smallest denomination
        for (int i = 4; i >= 0; --i) {
            if (amount >= denominations[i] && tempNotes[i] > 0) {
                long long notesToUse = std::min((long long)(amount / denominations[i]), tempNotes[i]);
                result[i] = notesToUse;
                amount -= notesToUse * denominations[i];
            }
        }
        
        // Check if exact amount is withdrawn
        if (amount > 0) {
            return {-1}; // Withdrawal not possible
        }
        
        // Update original notes if withdrawal succeeds
        for (int i = 0; i < 5; ++i) {
            notes[i] -= result[i];
        }
        
        return result;
    }
};