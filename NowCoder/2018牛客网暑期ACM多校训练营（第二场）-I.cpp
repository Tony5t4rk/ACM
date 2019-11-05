#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
 
bool s1[maxn], s2[maxn];
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    read(n); read(m);
    int ans = n * 2;
    mem(s1, 0);
    mem(s2, 0);
    for (int i = 0, x, y; i < m; ++i) {
        read(x); read(y);
        if (!s1[x]) {
            s1[x] = 1;
            ans--;
        }
        if (!s2[y]) {
            s2[y] = 1;
            ans--;
        }
    }
    if (n % 2 && !s1[n / 2 + 1] && !s2[n / 2 + 1]) {
        ans--;
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
