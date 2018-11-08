#include <bits/stdc++.h>

const double eps = "Edit";

int Sgn(double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    if (X < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

// 点
struct Point {
    // X:横坐标，Y:纵坐标
    double X, Y;

    void input() {
        scanf("%lf%lf", &X, &Y);
    }

    // 减法
    Point operator - (const Point &B) const {
        return Point (X - B.X, Y - B.Y);
    }

	// 点积
	double operator * (const Point &B) const {
		return X * B.X + Y * B.Y;
	}

    // 叉积
    double operator ^ (const Point &B) const {
        return X * B.Y - Y * B.X;
    }
};

// 两点间距离
double Distance(Point A, Point B) {
	return sqrt((B - A) * (B - A));
}

// 线段
struct Segment {
	Point S, T;

	void Input() {
		S.Input();
		T.Input();
	}

	// 向量叉积
	double operator ^ (const Segment &B) const {
		return (T - S) ^ (B.T - B.S);
	}
};

// 判断线段A、B是否相交
bool IsIntersect(Segment A, Segment B) {
    return
        max(A.S.X, A.T.X) >= min(B.S.X, B.T.X) &&
        max(B.S.X, B.T.X) >= min(A.S.X, A.T.X) &&
        max(A.S.Y, A.T.Y) >= min(B.S.Y, B.T.Y) &&
        max(B.S.Y, B.T.Y) >= min(A.S.Y, A.T.Y) &&
        Sgn((B.S - A.T) ^ (A.S - A.T)) * Sgn((B.T - A.T) ^ (A.S - A.T)) <= 0 &&
        Sgn((A.S - B.T) ^ (B.S - B.T)) * Sgn((A.T - B.T) ^ (B.S - B.T)) <= 0;
}

// 判断线段A所在直线与线段B是否相交
bool IsIntersect(Segment A, Segment B) {
    return Sgn((B.S - A.T) ^ (A.S - A.T)) * Sgn((B.T - A.T) ^ (A.S - A.T)) <= 0;
}

// 判断线段(直线)A、B是否平行
bool Parallel(Segment A, Segment B) {
    return Sgn((A.S - A.T) ^ (B.S - B.T)) == 0;
}

// 判断直线A、B是否相交
bool IsIntersect(Segment A, Segment B) {
    return !Parallel(A, B) || (Parallel(A, B) && !(Sgn((A.S - B.S) ^ (B.T - B.S)) == 0));
}

// 求直线A、B交点
Point IntersectionPoint(Segment A, Segment B) {
	double X = (B.T - B.S) ^ (A.S - B.S), Y = (B.T - B.S) ^ (A.T - B.S);
	return Point {(A.S.X * Y - A.T.X * X) / (Y - X), (A.S.Y * Y - A.T.Y * X) / (Y - X)};
}

// 判断N个点(下标1~N-1)能否组成凸包
bool IsConvexHull(Point points[], int N) {
    points[N] = points[0];
    points[N + 1] = points[1];
    for (int i = 2; i <= N + 1; ++i) {
        if (Sgn((points[i - 1] - points[i - 2]) ^ (points[i] - points[i - 2])) <= 0) {
            return false;
        }
    }
    return true;
}

// 凸包，points:所有点，返回凸包总长度
double ConvexHull(std::vector<Point> points) {
    int N = int(points.size());
    // 特判点数小于等于2的情况
    if (N == 1) {
        return 0;
    }
    else if (N == 2) {
        return Distance(points[0], points[1]);
    }
    // 查找最左下角的基准点
    int Basic = 0;
    for (int i = 0; i < N; ++i) {
        if (points[i].Y > points[Basic].Y || 
            (points[i].Y == points[Basic].Y && points[i].X < points[Basic].X)) {
                Basic = i;
        }
    }
    std::swap(points[0], points[Basic]);
    // 对其它点进行极角排序
    std::sort(points.begin() + 1, points.end(), [&] (const Point &A, const Point &B) {
        double Temp = (A - points[0]) ^ (B - points[0]);
        if (Temp > 0) {
            return true;
        }
        else if (!Temp && Distance(A, points[0]) < Distance(B, points[0])) {
            return true;
        }
        return false;
    });
    // 凸包选点
    std::vector<Point> Stack;
    Stack.push_back(points[0]);
    for (int i = 2; i < N; ++i) {
        while (Stack.size() >= 2 && ((Stack.back() - Stack[int(Stack.size()) - 2]) ^ (points[i] - Stack[int(Stack.size()) - 2])) <= 0) {
            Stack.pop_back();
        }
    }
    Stack.push_back(points[0]);
    // 计算总长
    double Ans = 0;
    for (int i = 1; i < int(Stack.size()); ++i) {
        Ans += Distance(Stack[i], Stack[i - 1]);
    }
    // 返回结果
    return Ans;
}

