#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string> &ans, string output, string mapping[], int index, string digits) {
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(ans, output, mapping, index + 1, digits);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() == 0) return ans;
    string output;
    int index = 0; // Initialize index
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(ans, output, mapping, index, digits);
    return ans;
}

int main() {
    string digits = "23"; // Example digits
    vector<string> combinations = letterCombinations(digits);
    
    // Printing the combinations
    cout << "Combinations for digits " << digits << ":" << endl;
    for(const string& combination : combinations) {
        cout << combination << endl;
    }
    
    return 0;
}
