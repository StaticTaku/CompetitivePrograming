#include <bits/stdc++.h>
using namespace std;

struct Point { int x, y; };


bool comp(const Point &a, const Point &b)
{
    return b.x < a.x;
}

double dist(Point a, Point b)
{
    return sqrt((double)(a.x - b.x) * (a.x - b.x)
                      + (a.y - b.y) * (a.y - b.y));
}

int main()
{    
    int C;
    cin >> C;
    while (C--)
    {
        int N;
        cin >> N;
        vector<Point> points;
        for (int i = 1; i <= N; ++i)
        {
            Point point;
            cin >> point.x >> point.y;
            points.push_back(point);
        }

        sort(points.begin(), points.end(), comp);

        int MaxY = 0;
        double length = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i].y > MaxY)
            {
                length += dist(points[i], points[i - 1])*(points[i].y - MaxY) / (points[i].y - points[i - 1].y); 
                MaxY = points[i].y;
            }
        }

        cout << setprecision(2) << setiosflags(ios::fixed) << length << endl;
    }
    return 0;
}