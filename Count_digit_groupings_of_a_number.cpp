//Given a string str consisting of digits, you can divide it into sub-groups by separating the string into substrings.
//For example, "112" can be divided as {"1", "1", "2"}, {"11", "2"}, {"1", "12"}, and {"112"}.
//A valid grouping can be done if you are able to divide sub-groups where the sum of digits in a sub-group is less than or equal to the sum of the digits of the sub-group immediately right to it.
//Your task is to determine the total number of valid groupings that could be done for a given string.

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
	int TotalCount(string str){
	    // Code here
	    int length=str.length();
        int x=0;
        for (int i=0; i<length; i++) {
            x += str[i]-'0';
        }
        // Initialize a 2D table of size (length+1)x(x+1)
        vector<vector<int>> dp(length+1, vector<int>(x+1, 0));
        // Base case: set all values in the last row to 1
        for (int s=0; s<=x; s++) {
            dp[length][s] = 1;
        }
        // Fill the table in bottom-up manner
        for (int position=length-1; position>=0; position--) {
            for (int previous_sum=0; previous_sum<=x; previous_sum++) {
                int sum=0;
                int res=0;
                // Compute the number of sub-strings with sum >= previous_sum
                for (int i=position; i<length; i++) {
                    sum += (str[i]-'0');
                        if (sum>=previous_sum) {
                            res+=dp[i + 1][sum];
                        }
                    }
                // Store the result in the current position of the table
                dp[position][previous_sum]=res;
            }
        }
        // Return the value in the top-left corner of the table
        return dp[0][0];
  }
};
