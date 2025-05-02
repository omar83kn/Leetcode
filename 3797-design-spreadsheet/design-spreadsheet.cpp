#include <string>
#include <unordered_map>
#include <utility>

class Spreadsheet {
private:
    int numRows;
    std::unordered_map<long long, int> cells; // Maps (row, col) to value

    // Convert cell reference (e.g., "A1") to (row, col) coordinates
    std::pair<int, int> parseCell(const std::string& cell) {
        int col = cell[0] - 'A'; // Column 'A' -> 0, 'B' -> 1, etc.
        int row = 0;
        for (size_t i = 1; i < cell.size(); ++i) {
            row = row * 10 + (cell[i] - '0');
        }
        return {row - 1, col}; // Convert 1-based row to 0-based
    }

    // Parse an operand (cell reference or integer) and return its value
    int parseOperand(const std::string& operand) {
        if (operand[0] >= 'A' && operand[0] <= 'Z') {
            // Operand is a cell reference
            auto [row, col] = parseCell(operand);
            long long key = (long long)row * 26 + col;
            return cells.count(key) ? cells[key] : 0; // Return cell value or 0 if unset
        } else {
            // Operand is an integer
            int value = 0;
            for (char c : operand) {
                value = value * 10 + (c - '0');
            }
            return value;
        }
    }

public:
    Spreadsheet(int rows) : numRows(rows) {
        // Initialize empty spreadsheet
    }
    
    void setCell(std::string cell, int value) {
        auto [row, col] = parseCell(cell);
        long long key = (long long)row * 26 + col;
        cells[key] = value;
    }
    
    void resetCell(std::string cell) {
        auto [row, col] = parseCell(cell);
        long long key = (long long)row * 26 + col;
        cells.erase(key);
    }
    
    int getValue(std::string formula) {
        // Remove '=' and split at '+'
        std::string operand1, operand2;
        size_t plusPos = formula.find('+');
        operand1 = formula.substr(1, plusPos - 1); // Skip '='
        operand2 = formula.substr(plusPos + 1);
        return parseOperand(operand1) + parseOperand(operand2);
    }
};