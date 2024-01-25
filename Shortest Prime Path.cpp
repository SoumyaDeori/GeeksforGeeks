/*You are given two four digit prime numbers num1 and num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPrime(int num) {
      if (num < 2) return false;
      for (int i = 2; i * i <= num; ++i) {
          if (num % i == 0) return false;
      }
      return true;
     }

    int solve(int num1, int num2) {
        if (num1 == num2) return 0;

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({num1, 0});
        visited.insert(num1);

        while (!q.empty()) {
            int current = q.front().first;
            int distance = q.front().second;
            q.pop();

        for (int i = 0; i < 4; ++i) {
            for (char digit = '0'; digit <= '9'; ++digit) {
                if (i == 0 && digit == '0') continue; // Skip leading zero
                string newNumStr = to_string(current);
                newNumStr[i] = digit;
                int newNum = stoi(newNumStr);
                
                if (newNum == num2) {
                    return distance + 1;
                }

                if (isPrime(newNum) && visited.find(newNum) == visited.end()) {
                    q.push({newNum, distance + 1});
                    visited.insert(newNum);
                }
            }
        }
    }

    return -1;  // If no path is found
  }
};

