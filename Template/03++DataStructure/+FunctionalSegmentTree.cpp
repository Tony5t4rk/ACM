const int maxn = "Edit";

class FuncSegTree {
  public:
    int tot;
    int rt[maxn];
    int lson[maxn << 5], rson[maxn << 5];
    int cnt[maxn << 5];

    int Build(int l, int r) {
      int t = ++tot;
      int m = (l + r) >> 1;
      if (l != r) {
        lson[t] = Build(l, m);
        rson[t] = Build(m + 1, r);
      }
      return t;
    }

    int Modify(int prev, int l, int r, int v) {
      int t = ++tot;
      lson[t] = lson[prev]; rson[t] = rson[prev];
      cnt[t] = cnt[prev] + 1;
      int m = (l + r) >> 1;
      if (l != r) {
        if (v <= m) lson[t] = Modify(lson[t], l, m, v);
        else rson[t] = Modify(rson[t], m + 1, r, v);
      }
      return t;
    }

    // 区间[u+1,v]静态第k小
    int Query(int u, int v, int l, int r, int k) {
      if (l == r) return l;
      int m = (l + r) >> 1;
      int num = cnt[lson[v]] - cnt[lson[u]];
      if (num >= k) return Query(lson[u], lson[v], l, m, k);
      return Query(rson[u], rson[v], m + 1, r, k - num);
    }

    // 区间[u+1,v]内[s,t]数字数量
    int Query(int u, int v, int s, int t, int l, int r) {
      if (s <= l && t >= r) return cnt[v] - cnt[u];
      int m = (l + r) >> 1;
      int ret = 0;
      if (s <= m) ret += Query(lson[u], lson[v], s, t, l, m);
      if (t > m) ret += Query(rson[u], rson[v], s, t, m + 1, r);
      return ret;
    }
};


