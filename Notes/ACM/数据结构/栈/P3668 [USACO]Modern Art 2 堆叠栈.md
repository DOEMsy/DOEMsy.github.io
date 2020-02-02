# P3668 [USACO]Modern Art 2 堆叠栈

## 题目背景

小TY的同学HF也想创作艺术

HF只有一块长条状的画布(画条)，所以每一次涂色只能涂上连续几个单位的颜料，同样新的颜料可以完全覆盖旧的颜料

由于他的颜料同样非常傲娇，每次涂完要等上1day才能完全干，只有旧颜料干了以后才能用新颜料覆盖

现在小HF用了2017个年头终于画出了一个大作品，自己非常满意

现在他想复制这份作品

现在给你一个长度为N(N≤1e5)的画条

上面有若干种颜色，每位的数字表示一种颜色，0表示没有涂色

为了快捷，每次涂色可以用一种颜色填充一个区间，同一种颜色只能使用一次

每次可以涂色好几次，但是这些区间必须分别连续切两两不能相交

然后等待1day油漆干了后再同样操作，输出创作完成并全干了后的最少时间

## 输入格式

第一行为N，画条长度

一下N行每行一个数表示颜色

## 输出格式

输出一个整数表示最少天数。数据若不合法则输出-1

## 输入输出样例

**输入 #1**

```
7
0
1
4
5
1
3
3
```

**输出 #1**

```
2
```

$\\$

## 解题

### 方案1：

贪心法可以得到最优解，根据每种颜色的填充长度，长的先填充。每个颜色只能用一次，每个涂抹区域一定是包含或不相交的关系，如果存在相互覆盖一部分则无法填图，所以每次涂抹只需要判断边界。

每天都选取当前最长的颜色填充，然后用剩下的颜色插入缝隙

复杂度$O(n^2)$，超时了

### 方案2：

 我们把问题转化一下

根据方案1的分析，一个颜色只能涂一次，而且只需要记录涂抹的起点和终点即可

由于新颜色需要等一天才能覆盖旧颜色的设定，所以在一个块中最多的颜色叠加层数即为答案

```
                        7         >>>
                        6     **********
                        5                 ++++
                        3   ------------
                        1  =======================
                          0123456789.............n-1
```

通过维护一个颜色栈，遇到颜色起点推入，遇到颜色终点推出

而且根据上面的分析，颜色必须是包含或不相交的关系，所以每次推出的一定是最近一次压入的颜色

否则存在部分相交，无法填涂输出-1

```C++
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


struct color{//[l,r]
    int l;
    int r;
};
int line[1*e5];

int main(){

    cin.tie(0);
    //ios::sync_with_stdio(false);
    cout<<setiosflags(ios::fixed)<<setprecision(0);

    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);

    int n;
    while(cin>>n){
        //初始化录入颜色并记录起点和终点
        map<int,color>colors;
        fr(i,n){
            cin>>line[i];
            if(line[i]!=0){
                colors[line[i]].r = -1;
                colors[line[i]].l = n;
            }
        }

        fr(i,n){
            if(line[i]!=0){
                min_get(colors[line[i]].l, i);
                max_get(colors[line[i]].r, i);
            }
        }
		
        //解题部分
        int ans;
        bool can = true;
        stack<int>st;
        fr(i,n){
            auto it = colors.find(line[i]);
            if(it!=colors.end()){
                if(it->second.l==i){
                    st.push(line[i]);
                    max_get(ans,int(st.size()));
                }
                if(line[i]!=st.top()){
                    can = false;
                    break;
                }
                if(it->second.r==i){
                    st.pop();
                }
            }
        }
        if(can){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}

```

$\\$

## 扩展

### 这种题可以变成

一条时间线上，有$n$个工作，一台机器只能在同一时间做一个工作，每个工作拥有一个起点时间和一个终点时间，问最少需要几台机器才能做完全部工作

### 分析

这种题和上面的差别不大，但是有一点不同的是**不同工作之间的时间段可以存在相互部分覆盖或者完全重叠**

这样导致我们无法继续使用栈来解题

但是道理都是一样的，时间点工作叠加数量的最大值即为所求

我们可以使用线段树（杀鸡偃月刀），空间四倍，时间$Olog n$，但是你的输入是线性 X

或者我们可以维护一个工作集合，到点入，到点出，集合的最大大小即为所求，复杂度$Onlogm$，$n$是时间线长度，$m$是工作的数量。我们也可以用$hash$表代替（或者说是模拟？）集合，牺牲空间将复杂度降到$On$

### 总结

其实题目都很简单

在原题中画布为横轴，天数为纵轴，我们可以得到一个函数图像（画布的点到天数的映射）

这个图的意义是**第$i$块色块变成成品至少需要几天**，由于题目中给出的设定，所以$ans = \max \limits_{0<i<n}(color\_num_i)$

同理在扩展题中，映射关系是**第$i$个时间点的所有工作至少需要几个机器**，$ans = \max \limits_{0<i<n}(work\_num_i)$

我们所需要的就是根据题目要求，求出这种映射关系