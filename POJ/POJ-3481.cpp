#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 1e5 + 5;

struct SplayTree {
    // Root:Splay Tree根节点
    int Root, Tot;
    // Son[i][0]:i节点的左孩子，Son[i][0]:i节点的右孩子
    int Son[maxn][2];
    // Pre[i]:i节点的父节点
    int Pre[maxn];
    int Id[maxn];
    // Val[i]:i节点的权值
    int Val[maxn];
    // Size[i]:以i节点为根的Splay Tree的节点数(包含自身)
    int Size[maxn];
    // Cnt[i]:节点i的权值的出现次数
    int Cnt[maxn];

    void PushUp(int X) {
        Size[X] = Size[Son[X][0]] + Size[Son[X][1]] + Cnt[X];
    }

    // 判断X节点是其父节点的左孩子还是右孩子
    bool Self(int X) {
        return X == Son[Pre[X]][1];
    }

    void Clear(int X) {
        Son[X][0] = Son[X][1] = Pre[X] = Val[X] = Size[X] = Cnt[X] = 0;
    }

    // 旋转
    void Rotate(int X) {
        int Fa = Pre[X], FaFa = Pre[Fa], XJ = Self(X);
        Son[Fa][XJ] = Son[X][XJ ^ 1];
        Pre[Son[Fa][XJ]] = Pre[X];
        Son[X][XJ ^ 1] = Pre[X];
        Pre[Fa] = X;
        Pre[X] = FaFa;
        if (FaFa) {
            Son[FaFa][Fa == Son[FaFa][1]] = X;
        }
        PushUp(Fa);
        PushUp(X);
    }

    // 旋转X节点到根节点
    void Splay(int X) {
        for (int i = Pre[X]; i = Pre[X]; Rotate(X)) {
            if (Pre[i]) {
                Rotate(Self(X) == Self(i) ? i : X);
            }
        }
        Root = X;
    }

    // 插入数X
    void Insert(int P, int X) {
        if (!Root) {
            Val[++Tot] = X;
            Id[Tot] = P;
            Cnt[Tot]++;
            Root = Tot;
            PushUp(Root);
            return;
        }
        int Cur = Root, F = 0;
        while (true) {
            if (Val[Cur] == X) {
                Cnt[Cur]++;
                PushUp(Cur);
                PushUp(F);
                Splay(Cur);
                break;
            }
            F = Cur;
            Cur = Son[Cur][Val[Cur] < X];
            if (!Cur) {
                Val[++Tot] = X;
                Id[Tot] = P;
                Cnt[Tot]++;
                Pre[Tot] = F;
                Son[F][Val[F] < X] = Tot;
                PushUp(Tot);
                PushUp(F);
                Splay(Tot);
                break;
            }
        }
    }

    // 查询X的排名
    int Rank(int X) {
        int Ans = 0, Cur = Root;
        while (true) {
            if (X < Val[Cur]) {
                Cur = Son[Cur][0];
            }
            else {
                Ans += Size[Son[Cur][0]];
                if (X == Val[Cur]) {
                    Splay(Cur);
                    return Ans + 1;
                }
                Ans += Cnt[Cur];
                Cur = Son[Cur][1];
            }
        }
    }

    // 查询排名为X的数
    int Kth(int X) {
        int Cur = Root;
        while (true) {
            if (Son[Cur][0] && X <= Size[Son[Cur][0]]) {
                Cur = Son[Cur][0];
            }
            else {
                X -= Cnt[Cur] + Size[Son[Cur][0]];
                if (X <= 0) {
                    return Val[Cur];
                }
                Cur = Son[Cur][1];
            }
        }
    }

    int GetMax() {
        int Cur = Root;
        while (Son[Cur][1]) {
            Cur = Son[Cur][1];
        }
        return Cur;
    }

    int GetMin() {
        int Cur = Root;
        while (Son[Cur][0]) {
            Cur = Son[Cur][0];
        }
        return Cur;
    }

    /*
     * 在Insert操作时X已经Splay到根了
     * 所以X的前驱就是X的左子树的最右边的节点
     * 后继就是X的右子树的最左边的节点
     */

    // 求前驱
    int Path() {
        int Cur = Son[Root][0];
        while (Son[Cur][1]) {
            Cur = Son[Cur][1];
        }
        return Cur;
    }

    // 求后继
    int Next() {
        int Cur = Son[Root][1];
        while (Son[Cur][0]) {
            Cur = Son[Cur][0];
        }
        return Cur;
    }

    // 删除节点X
    void Delete(int X) {
        // 将X旋转到根
        Rank(X);
        if (Cnt[Root] > 1) {
            Cnt[Root]--;
            PushUp(Root);
            return;
        }
        if (!Son[Root][0] && !Son[Root][1]) {
            Clear(Root);
            Root = 0;
            return;
        }
        if (!Son[Root][0]) {
            int Temp = Root;
            Root = Son[Root][1];
            Pre[Root] = 0;
            Clear(Temp);
            return;
        }
        if (!Son[Root][1]) {
            int Temp = Root;
            Root = Son[Root][0];
            Pre[Root] = 0;
            Clear(Temp);
            return;
        }
        int Temp = Path(), Old = Root;
        Splay(Temp);
        Pre[Son[Old][1]] = Temp;
        Son[Temp][1] = Son[Old][1];
        Clear(Old);
        PushUp(Root);
    }
};

int main(int argc, char *argv[]) {
    int Op;
    SplayTree Tree;
    while (~scanf("%d", &Op) && Op) {
        if (Op == 1) {
            int K, P;
            scanf("%d%d", &K, &P);
            Tree.Insert(K, P);
        }
        else if (Op == 2) {
            printf("%d\n", Tree.Id[Tree.GetMax()]);
            Tree.Delete(Tree.Val[Tree.GetMax()]);
        }
        else if (Op == 3) {
            printf("%d\n", Tree.Id[Tree.GetMin()]);
            Tree.Delete(Tree.Val[Tree.GetMin()]);
        }
    }
    return 0;
}
