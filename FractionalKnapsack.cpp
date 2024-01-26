// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
//Note: Unlike 0/1 knapsack, you are allowed to break the item here. 
// Your Task :
//Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size N and returns a double value representing the maximum value in knapsack.

#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
}
class Solution
{
     public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        // Sorting is not required in this approach

        double totalValue = 0.0;

        // Calculate the value per weight for each item and store in a pair
        pair<double, int> valuePerWeight[n];
        for (int i=0;i<n;++i) 
        {
            valuePerWeight[i].first = (double)arr[i].value / arr[i].weight;
            valuePerWeight[i].second = i;
        }

        // Sort the array of indices based on value per weight in descending order
        sort(valuePerWeight, valuePerWeight + n, greater<pair<double, int>>());

        // Loop through each item
        for (int i = 0; i < n; ++i) 
        {
            int index = valuePerWeight[i].second;

            // If the current item can be completely added to the knapsack
            if (arr[index].weight <= W) 
            {
                totalValue += arr[index].value;
                W -= arr[index].weight;
            } 
            else 
            {  // If the current item cannot be completely added
                // Add the fractional part of the current item to the knapsack
                double fraction = (double)W / arr[index].weight;
                totalValue += fraction * arr[index].value;
                break;  // Since the knapsack is full
            }
        }

        return totalValue;
    }
        
};
