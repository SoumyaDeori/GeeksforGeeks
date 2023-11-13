class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int len1=s1.length();
        int len2=s2.length();
        
        if(len1 != len2)
        {
            return false;
        }
        string concatenate=s1+s1;
        
        return (concatenate.find(s2)!=std::string::npos);
    }
};
