#include <bits/stdc++.h>

using namespace std;



bool good[300][300][300];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin>>t;
    for(int cnt=1; cnt<=t; cnt++)
    {
        memset(good,0,sizeof(good));
        int r,c,k;
        cin>>r>>c>>k;
        int circuit[r][c];
        //int premax[c];
        //int premin[c];
        //int maxn=-1;
        //int minn=10000;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>circuit[i][j];
            }
        }
        int minTree[r][2*c];
        for(int i=0; i<r; i++)
        {
            for(int j=c; j<2*c; j++)
            {
                minTree[i][j]=circuit[i][j-c];
            }
            for(int j=c-1; j>=1; j--)
            {
                minTree[i][j]=min(minTree[i][2*j],minTree[i][2*j+1]);
            }
        }
        int maxTree[r][2*c];
        for(int i=0; i<r; i++)
        {
            for(int j=c; j<2*c; j++)
            {
                maxTree[i][j]=circuit[i][j-c];
            }
            for(int j=c-1; j>=1; j--)
            {
                maxTree[i][j]=max(maxTree[i][2*j],maxTree[i][2*j+1]);
            }
        }





        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                bool ok=true;
                good[j][j][i]=ok;
                for(int jj=j+1; jj<c; jj++)
                {
                    bool okk=true;
                    int minn=10000,maxn=-1;
                    int l=j+c,r=jj+c;
                    while(l<r)
                    {
                        if(l%2==1)
                        {
                            minn=min(minn,minTree[i][l]);
                            l+=1;
                        }
                        if(r%2==1)
                        {
                            minn=min(minn,minTree[i][r]);
                            r-=1;
                        }
                        l/=2;
                        r/=2;
                    }

                    l=j+c,r=jj+c;
                    while(l<r)
                    {
                        if(l%2==1)
                        {
                            maxn=max(maxn,maxTree[i][l]);
                            l+=1;
                        }
                        if(r%2==1)
                        {
                            maxn=min(maxn,maxTree[i][r]);
                            r-=1;
                        }
                        l/=2;
                        r/=2;
                    }
                    if(maxn-minn>k)
                    {
                        ok=false;
                    }
                    good[j][jj][i]=ok;
                }
            }
        }







        int ans=0;
        for(int i=0; i<c; i++)
        {
            for(int j=c-1; j>=i; j--)
            {
                int w=j-i+1;
                if(w*300<ans) break;
                //cout<<ans<<endl;
                for(int ii=0; ii<r; ii++)
                {
                    for(int jj=ii; jj<r; jj++)
                    {
                        if(!good[i][j][jj]) break;
                        ans=max(ans,w*(jj-ii+1));
                        //cout<<ans<<endl;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",cnt,ans);
    }
    return 0;
}

