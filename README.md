# Competitive Programming

My personal collection of competitive programming code, templates, tools...

## Content 


#### Graphs
- [Dijkstra's shortest path algorithm](Graphs/dijkstra.cpp)
- [Bellman ford's shortest path algorithm](Graphs/bellman_ford.cpp)
- [Floyd warshall's shortest path algorithm + negative cycle detection](Graphs/floyd_warshall.cpp)
- [Kruskal's minimum spanning tree algorithm](Graphs/kruskal.cpp)
- [Dinic's max flow algorithm](Graphs/dinic.cpp)

#### Geometry
- [Basic Geometry](Geometry/basic.cpp)
- [Convex Hull](Geometry/convex_hull.cpp)

#### Maths
- [Binary exponentiation and modulo inverse](Math/binary_exp.cpp)
- [Matrix exponontiation](Math/matrix.cpp)
- [Sieve of eratosthenes](Math/sieve.cpp)
- [Linear Sieve](Math/linear_sieve.cpp)
- [Fermat Primality test](Math/primality_test.cpp)
- [GCD, Extended GCD, LCM](Math/gcd.cpp)
- [Euler's totient function](Math/totient.cpp)

#### Data structures
- [Segment tree](DS/segtree.cpp)
- [Disjoint set](DS/dsu.cpp)
- [Sparse table](DS/sparse_table.cpp)

#### Strings 
- [String hashing + Rabin-Karp pattern matching algorithm](Strings/hashing.cpp)
- [Z-function](Strings/z_function.cpp)


## Note

using the above code alone won't compile, make sure the add the template above below the code

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
```