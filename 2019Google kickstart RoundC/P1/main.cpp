#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > vis;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int dtoi(char c)
{
    switch(c){
    case 'E':
        return 0;
        break;
    case 'W':
        return 1;
        break;
    case 'S':
        return 2;
        break;
    case 'N':
        return 3;
        break;
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin>>t;
    for(int cnt=1; cnt<=t; cnt++)
    {
        int n,r,c,sr,sc;
        int er,ec;
        string s;
        cin>>n>>r>>c>>sr>>sc;
        cin>>s;
        vis.clear();
        //memset(grid,0,sizeof(grid));
        int curr=sr,curc=sc,curd;
        int i=0;
        while(i<=s.size())
        {
            bool visited=false;
            for(int j=0; j<vis.size(); j++)
            {
                if(vis[j].first==curr&&vis[j].second==curc)
                    visited=true;
            }
            if(!visited)
            {
                if(i<s.size())
                {
                    curd=dtoi(s[i]);
                    vis.push_back({curr,curc});
                    i++;
                }
                else
                {
                    break;
                }
            }
            if(curr+dr[curd]>r || curr+dr[curd]<1 ||curc+dc[curd]>c ||curc+dc[curd]<1)
                break;
            curr+=dr[curd];
            curc+=dc[curd];
            //cout<<curr<<" "<<curc<<endl;
        }
        printf("Case #%d: %d %d\n",cnt,curr,curc);
    }
    return 0;
}
