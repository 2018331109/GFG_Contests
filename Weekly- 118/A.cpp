 class Solution {
  public:
    int findMin(int a[], int n)
    {
        // add your code here
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2)
            {
                f++;
            }
        }
        if(f==n)
        {
            if(n%2)
            {
                return -1;
            }
            else
            {
                return 0;
            }
            
        }
        
        if(f%2==0)
        {
            return 0;
        }
        else
        {
            int cnt=100;
            for(int i=0;i<n;i++)
            {
                if(a[i]%2==0)
                {
                    int c=0;
                    while(a[i]%2==0)
                    {
                        a[i]/=2;
                        c++;
                    }
                    cnt=min(cnt, c);
                }
            }
            
            return cnt;
        }
        
    }
};
