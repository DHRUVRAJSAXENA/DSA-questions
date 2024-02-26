#include <iostream>
#include <bitset>
using namespace std;

bool check(string str, int start, int end) {
    if (start >= end) return true;

    if (str[start] != str[end]) return false;

    return check(str, start + 1, end - 1);
}

bool checkPalindrome(long long N) {
    // Determine the number of bits required to represent N
    int numBits = 64 - __builtin_clzll(N);

    // Convert N to binary representation with the determined number of bits
    string str = bitset<64>(N).to_string().substr(64 - numBits);

    return check(str, 0, numBits - 1);
}

int main() {
    long long N = 7;
    if (checkPalindrome(N))
        cout << "Binary representation is a palindrome." << endl;
    else
        cout << "Binary representation is not a palindrome." << endl;
    return 0;
}
