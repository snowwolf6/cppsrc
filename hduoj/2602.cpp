#include<iostream>
#include<memory.h>
using namespace std;
#define Size 1111
int va[Size],vo[Size];
int dp[Size];
int Max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int t,n,v;
    int i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>v;
        for(i=1;i<=n;i++)
            cin>>va[i];
        for(i=1;i<=n;i++)
            cin>>vo[i];
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=v;j>=vo[i];j--)
            {
                dp[j]=Max(dp[j],dp[j-vo[i]]+va[i]); 
            }
        }
        cout<<dp[v]<<endl;
    }
    return 0;
}