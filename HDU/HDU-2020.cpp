#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2600;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

struct cmp {
    bool operator () (const int &a, const int &b) {
        return abs(a) < abs(b);
    }
};

int main(){
    //fre();
    int n;
    while (~scanf("%d", &n), n) {
        priority_queue<int, vector<int>, cmp> q;
        while (n--) {
            int num;
            scanf("%d", &num);
            q.push(num);
        }
        printf("%d", q.top());
        q.pop();
        while (!q.empty()) {
            printf(" %d", q.top());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}
