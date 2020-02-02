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

int f[5003];

int getf(int t){
    if(f[t]==t) return t;
    return f[t] = getf(f[t]);
}

void merge(int a,int b){
    int t1 = getf(a);
    int t2 = getf(b);
    if(t1!=t2){
        f[t2] = t1;
    }
}

bool query(int a,int b){
    int t1 = getf(a);
    int t2 = getf(b);
    return t1==t2;
}

int main(){

    cin.tie(0);
    //ios::sync_with_stdio(false);
    cout<<setiosflags(ios::fixed)<<setprecision(0);

    //freopen("maze.txt", "r", stdin);
    //freopen("1.out", "w", stdout)

    int n,m,p;
    while(cin>>n>>m>>p){
        fr(i,n+1)   f[i] = i;
        fr(i,m){
            int a,b;
            cin>>a>>b;
            merge(a,b);
        }
        fr(i,p){
            int a,b;
            cin>>a>>b;
            cout<<(query(a,b)?"Yes":"No")<<endl;
        }
    }

    return 0;
}
