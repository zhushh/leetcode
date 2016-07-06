// https://leetcode.com/problems/bulls-and-cows/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int record[10] = {0};
        int cache[10] = {0};
        int bulls = 0;
        int cows = 0;
        int n = secret.size();
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i])
                bulls++;
            else {
                record[secret[i] - '0']++;
                cache[guess[i] - '0']++;
                if (record[guess[i] - '0'] > 0) {
                    cows++;
                    record[guess[i] - '0']--;
                    cache[guess[i] - '0']--;
                }
                if (cache[secret[i] - '0'] > 0) {
                    cows++;
                    cache[secret[i] - '0']--;
                    record[secret[i] - '0']--;
                }
            }
        }
        return std::to_string(bulls)+"A"+std::to_string(cows)+"B";
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}