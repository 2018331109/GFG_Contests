 class Solution
{
public:
    int solve(int a[], int l, int r, int n, int c)  
    {
        int cnt = 0;
        if(l<0 || r>=n || a[l]!=a[r])
        {
            return 0;
        }
        while (l >= 0 && a[l] == c)
        {
            l--;
            cnt++;
        }

        while(r<n && a[r] == c)
        {
            r++;
            cnt++;
        }

        if(cnt>=3)
        {
            if(a[l]==a[r] && l>=0 && r<n)
            {
                cnt += solve(a, l, r, n, a[l]);  
            }
            else
            {
                return cnt;
            }
        }
        else
        {
            return 0;
        }
        return cnt;
    }

    int maxBoxes(int n, int k, int c, int a[])
    {
        int ans = 0;

        for (int i = 1; i < n ; i++)
        {
            int res = 0;
            if (a[i - 1] == a[i] && a[i] == c)
            {
                res = 3;  
                int l = i - 2;
                int r = i + 1;
                if(a[l]==a[r] && l>=0 && r<n)
                {
                    res += solve(a, l, r, n, a[l]);  
                }

            }
            ans = max(ans, res);
        }
        ans=max(ans-1, 0);
        return ans;
    }
};
