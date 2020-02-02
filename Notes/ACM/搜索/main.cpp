#include<bits/stdc++.h>
#define ll long long

#define fr(i,n) for(int i=0;i<n;i++)
#define frs(i,n,flag)   for(int i=0;i<n&&flag;i++)

#define frr(i,j,n) for(int i=j;i<n;i++)
#define r_frr(i,j,n) for(int i=n-1;i>=j;i--)

#define frrs(i,j,n,flag)    for(int i=j;i<n&&flag;i++)
#define r_frrs(i,j,n,flag)    for(int i=n-1;i>=j&&flag;i--)


#define yes "yes"
#define no  "no"

#define arend(i,n) ((i!=n-1)?" ":"\n")
#define memset0(dp) memset(dp,0,sizeof(dp))
#define min_get(a,b) a = min(a,b)
#define max_get(a,b) a = max(a,b)
#define PI  3.14159265354

#define print_arr(begin,end)    for(auto it = begin;it!=end;it++)  cout<<*it<<arend(it,end);
#define log_this(name,value)    cout<<name<<": "<<value<<endl;

#define e5 100005
#define e6 1000006

using namespace std;
int     to_int(string s)    {stringstream ss;ss<<s<<endl;int a;ss>>a;return a;}
string  to_str(double a)    {stringstream ss;ss<<a<<endl;return ss.str();}


int n,m;
char a[100][100];
int nextx[]={1,0,0,-1};
int nexty[]={0,-1,1,0};
char nextc[] = "DLRU";
string dp[100][100];

string dfs(int i,int j){


    string ans = "";
    if(i==n-1&&j==m-1){
        ans = "C";
    }else if(dp[i][j].length()!=0){
        ans = dp[i][j];
    }else{
        fr(p,4){
            int x = i+nextx[p];
            int y = j+nexty[p];
            if(0<=x&&x<n&&0<=y&&y<m&&a[x][y]=='0'){
                a[x][y] = '1';

                string ret = nextc[p]+dfs(x,y);

                if((ret[ret.length()-1]=='C')&&(ans==""||(ans.length()>=ret.length()&&ans>ret))){
                    ans = ret;
                }
                a[x][y] = '0';
            }
        }

        if(ans==""){
            ans = "F";
        }

        dp[i][j] = ans;
    }
    //cout<<i<<" "<<j<<" "<<ans<<endl;
    return ans;
}

/*
4 6
010000
000100
001001
110000
*/

int main(){

    cin.tie(0);
    //ios::sync_with_stdio(false);
    cout<<setiosflags(ios::fixed)<<setprecision(0);

    //freopen("maze.txt", "r", stdin);
    //freopen("1.out", "w", stdout)

    while(cin>>n>>m){
        //入口 0,0 出口 29,49
        fr(i,n) fr(j,m) cin>>a[i][j];
        a[0][0] = '1';
        string ans = dfs(0,0);
        cout<<ans.substr(0,ans.length()-1)<<endl;
    }
    return 0;
}
