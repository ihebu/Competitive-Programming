struct point
{
    ll x, y;
    point() {}
    point(ll x, ll y) : x(x), y(y) {}
    point& operator-=(const point& p)
    {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    point& operator+=(const point& p)
    {
        x += p.x;
        y += p.y;
        return *this;
    }
    point& operator*=(ll r)
    {
        x *= r;
        y *= r;
        return *this;
    }
    point& operator/=(ll r)
    {
        x /= r;
        y /= r;
        return *this;
    }
    point operator+(const point& p) { return point(*this) += p; }
    point operator-(const point& p) { return point(*this) -= p; }
    point operator*(ll r) { return point(*this) *= r; }
    point operator/(ll r) { return point(*this) /= r; }
    // cros product
    ll operator^(const point& p) { return x * p.y - y * p.x; }
    // dot product
    ll operator*(const point& p) { return x * p.x + y * p.y; }
    ll norm() { return *this * *this; }
    bool operator<(point p) { return y < p.y || (y == p.y && x < p.x); }
};

struct cmp
{
    point src;
    cmp(point p) { src = p; }
    bool operator()(point p1, point p2)
    {
        p1 = p1 - src;
        p2 = p2 - src;
        ll c = p1 ^ p2;
        ll d = p1.x;
        if (c == 0)
        {
            // change this if the problem doesnt allow colinear points
            // return p2.norm() > p1.norm()
            if (d > 0) return p1.norm() < p2.norm();
            return p2.norm() < p1.norm();
        }
        return c > 0;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        if (points[i] < points[0]) swap(points[i], points[0]);
    }
    sort(points.begin() + 1, points.end(), cmp(points[0]));
    vector<point> hull = {points[0], points[1]};
    for (int i = 2; i < n; i++)
    {
        while (hull.size() >= 2)
        {
            point c = points[i];
            point b = hull.end()[-1];
            point a = hull.end()[-2];
            if (((b - a) ^ (c - a)) >= 0) break;
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    cout << hull.size() << "\n";
    for (auto p : hull) cout << p.x << " " << p.y << "\n";
}
