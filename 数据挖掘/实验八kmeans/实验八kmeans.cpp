#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    double x, y;
    int cluster;
};

double euclidean(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    // 数据点 P1 ~ P13
    vector<Point> points = {
        {1,2}, {2,1}, {2,4}, {4,3}, {5,8}, {6,7}, {6,9}, {7,9}, {9,5},
        {1,12}, {3,12}, {5,12}, {3,3}
    };
    int n = points.size();
    int k = 3;

    // 初始化聚类中心（取前3个点）
    vector<Point> centers(k);
    for (int i = 0; i < k; ++i) {
        centers[i] = points[i];
        centers[i].cluster = i;
    }

    srand(time(0));
    bool changed = true;
    int iter = 0;
    while (changed && iter < 100) {
        changed = false;
        iter++;

        // 分配点到最近中心
        for (auto& p : points) {
            double min_dist = numeric_limits<double>::max();
            int best_cluster = 0;
            for (int i = 0; i < k; ++i) {
                double d = euclidean(p, centers[i]);
                if (d < min_dist) {
                    min_dist = d;
                    best_cluster = i;
                }
            }
            if (p.cluster != best_cluster) {
                p.cluster = best_cluster;
                changed = true;
            }
        }

        // 更新中心
        vector<int> count(k, 0);
        vector<Point> new_centers(k, { 0, 0 });
        for (const auto& p : points) {
            int c = p.cluster;
            new_centers[c].x += p.x;
            new_centers[c].y += p.y;
            count[c]++;
        }
        for (int i = 0; i < k; ++i) {
            if (count[i] > 0) {
                centers[i].x = new_centers[i].x / count[i];
                centers[i].y = new_centers[i].y / count[i];
            }
        }
    }

    cout << "K-means 聚类结果 (k=3):\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << (i + 1) << " -> Cluster " << points[i].cluster << endl;
    }

    return 0;
}