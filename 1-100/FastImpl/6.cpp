// Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/description/

#include <iostream>
#include <string>
#include <vector>

std::string convert(const std::string& s, int numRows) {
    if (numRows == 1 || s.length() <= numRows) {
        return s;
    }

    std::vector<std::string> rows(numRows);
    int currRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[currRow] += c;
        if (currRow == 0 || currRow == numRows - 1) {
            goingDown = !goingDown;
        }
        currRow += goingDown ? 1 : -1;
    }

    std::string result;
    for (const std::string& row : rows) {
        result += row;
    }

    return result;
}

int main() {
    std::string str = "PAYPALISHIRING";
    int numRows = 3;
    std::cout << "Zigzag conversion: " << convert(str, numRows) << std::endl;
    return 0;
}
