class Solution
{
public:
    vector<int> topK(vector<int> &nums, int k)
    { 
        // Code here 
        unordered_map<int, int> frequencyMap; 
        for (int num : nums) 
        { 
            frequencyMap[num]++;
        } 
        multiset<pair<int, int>> sortedSet;
        for (auto entry : frequencyMap)
        {
            sortedSet.insert({entry.second, entry.first}); 
            if (sortedSet.size() > k)
            { 
                sortedSet.erase(sortedSet.begin());
            } 
        } 
       vector<int> result; 
       for (auto it = sortedSet.rbegin(); it != sortedSet.rend(); ++it) 
       {
           result.push_back(it->second); 
       }
        return result; 
    } 
};
