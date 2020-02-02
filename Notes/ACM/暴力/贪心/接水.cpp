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
#define INF 9999999
using namespace std;
int     to_int(string s)    {stringstream ss;ss<<s<<endl;int a;ss>>a;return a;}
string  to_str(double a)    {stringstream ss;ss<<a<<endl;return ss.str();}

ll dp[1*e6];

int main(){

    cin.tie(0);
    //ios::sync_with_stdio(false);
    cout<<setiosflags(ios::fixed)<<setprecision(0);
    /*
    int n;
    while(cin>>n){
        fill(dp,dp+n,INF);
        ll inp;
        fr(i,n){
            cin>>inp;
            *lower_bound(dp,dp+n,inp) = inp;
        }
        int l = lower_bound(dp,dp+n,INF) - dp;
        fr(i,l){
            cout<<dp[i]<<arend(i,l);
        }
    }
    */

    int n,m; int a[100];
    while(cin>>n>>m){
        fr(i,n) cin>>a[i];
        sort(a,a+n);
        priority_queue<int,vector<int>,greater<int>>d;

        int j = 0,ans = 0;
        fr(i,n){
            int min_d;
            if(d.size()==m){
                min_d = d.top(); d.pop();
            }else{
                min_d = 0;
            }
            //cout<<min_d<<" "<<a[i]<<endl;;
            d.push(min_d+a[i]);
            ans += min_d+a[i];
            j++;
            if(j==m)    j=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
