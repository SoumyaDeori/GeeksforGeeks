class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1,string str2)
    {
        // Your code here
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 != len2)
        {
            return false;
        }

        if (len1 < 2) 
        {
             return str1 == str2;
        }

       string leftRot=str1.substr(2)+str1.substr(0,2);
       string rightRot=str1.substr(len1-2)+str1.substr(0,len1-2);

       return (leftRot==str2||rightRot==str2);
    }
    
};
