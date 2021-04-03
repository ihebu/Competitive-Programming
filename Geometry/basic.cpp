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
};
