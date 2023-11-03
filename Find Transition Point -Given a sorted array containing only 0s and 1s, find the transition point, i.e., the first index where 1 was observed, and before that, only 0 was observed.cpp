class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) 
    {
        // code here
        int flag=0;
        for(int i=0;i<n;i++)
        {
           if (arr[i]==1)
           {
             flag=1;
             return i;
             break;
            }
           else
           {
             continue;
            }
        }
        if(flag!=1)
        {
           return -1;
        }
    }
};
