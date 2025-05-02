#include <unordered_map>

class FrequencyTracker {
private:
    std::unordered_map<int, int> numFreq; // number -> frequency
    std::unordered_map<int, int> freqCount; // frequency -> count of numbers with this frequency

public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        // Get current frequency
        int oldFreq = numFreq[number];
        // Decrease count of old frequency
        if (oldFreq > 0) {
            freqCount[oldFreq]--;
            if (freqCount[oldFreq] == 0) {
                freqCount.erase(oldFreq);
            }
        }
        // Increase frequency of number
        numFreq[number]++;
        // Increase count of new frequency
        freqCount[numFreq[number]]++;
    }
    
    void deleteOne(int number) {
        // Check if number exists
        if (numFreq[number] == 0) return;
        
        // Get current frequency
        int oldFreq = numFreq[number];
        // Decrease count of old frequency
        freqCount[oldFreq]--;
        if (freqCount[oldFreq] == 0) {
            freqCount.erase(oldFreq);
        }
        // Decrease frequency of number
        numFreq[number]--;
        // Increase count of new frequency (0 or decremented)
        if (numFreq[number] > 0) {
            freqCount[numFreq[number]]++;
        } else {
            numFreq.erase(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        return freqCount.find(frequency) != freqCount.end() && freqCount[frequency] > 0;
    }
};