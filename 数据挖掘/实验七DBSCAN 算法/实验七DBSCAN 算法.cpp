#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

const int UNVISITED = -2;
const int NOISE = -1;

struct Point {
    double x, y;
    int cluster = UNVISITED;
};

double manhattan(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void dbscan(vector<Point>& points, double eps, int minPts) {
    int cluster_id = 0;
    int n = points.size();

    for (int i = 0; i < n; ++i) {
        if (points[i].cluster != UNVISITED) continue;

        // 找 ε-邻域
        vector<int> neighbors;
        for (int j = 0; j < n; ++j) {
            if (manhattan(points[i], points[j]) <= eps) {
                neighbors.push_back(j);
            }
        }

        if (neighbors.size() < minPts) {
            points[i].cluster = NOISE;
            continue;
        }

        // 新簇
        queue<int> q;
        points[i].cluster = cluster_id;
        for (int idx : neighbors) {
            if (points[idx].cluster == UNVISITED) {
                q.push(idx);
                points[idx].cluster = cluster_id;
            }
        }

        while (!q.empty()) {
            int current = q.front(); q.pop();
            vector<int> current_neighbors;
            for (int j = 0; j < n; ++j) {
                if (manhattan(points[current], points[j]) <= eps) {
                    current_neighbors.push_back(j);
                }
            }

            if (current_neighbors.size() >= minPts) {
                for (int idx : current_neighbors) {
                    if (points[idx].cluster == UNVISITED) {
                        points[idx].cluster = cluster_id;
                        q.push(idx);
                    }
                }
            }
        }
        cluster_id++;
    }
}

int main() {
    vector<Point> points = {
        {20,45},{34,23},{53,67},{54,85},{67,4},{33,67},{24,78},{37,90},{67,34},{34,56},
        {89,78},{65,23},{45,45},{67,67},{84,6},{23,78},{13,7},{45,70},{67,76},{4,54},
        {68,60},{20,45},{34,23},{53,67},{54,85},{67,4},{33,67},{24,78},{37,90},{67,34},
        {78,32},{23,33},{45,34},{67,35},{67,76},{4,54},{68,60},{7,38},{70,39},{76,40},
        {45,70},{67,76},{6,36},{78,37},{7,38},{70,39},{6,36},{45,45},{67,67},{84,6},
        {23,78},{13,7},{45,70},{67,76},{4,54},{68,60},{45,45},{34,67},{35,67},{36,4},
        {37,68},{38,45},{20,34}
    };

    double eps = 2.0;
    int minPts = 3;

    dbscan(points, eps, minPts);

    // 输出结果（仅显示前10个点）
    cout << "Cluster labels (first 10 points): ";
    for (int i = 0; i < 10; ++i) {
        cout << points[i].cluster << " ";
    }
    cout << "\n(-1 表示噪声)" << endl;

    return 0;
}