//============================Task===========================================
//Compute the number of strongly connected components of a given directed graph with 𝑛 vertices and
//𝑚 edges.
//============================Libraries and namespaces=======================
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <numeric>
#include <sstream>
#include <string>


using namespace std;


//==========================Macroes===========================================
/* SHORTCUT */
#define sp ' '
#define el '\n'
#define task ""
#define fi first
#define se second
#define pb push_back

/* LOOP */
#define fore(i,e) for(__typeof(e) i = 0; i <= e; ++i)
#define fores(i,e,s) for(__typeof(e) i = 0; i <= e; i+=s)
#define forbe(i,b,e) for(__typeof(e) i = b; i <= e; i++)
#define forbes(i,b,e,s) for(__typeof(e) i = b; i <= e; i+=s)
#define rforb(i,b) for(int i = b; i >= 0; --i)
#define rforbe(i, b, e) for(int i=b; i>=e; --i)

/* ARRAY */
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll) )
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin() )
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin() )
#define MEMS(x, val) memset(x, val, sizeof(x))

/* DEBUG*/ 
#define dbs(x) cerr<<#x<<" = "<<x<<endl
#define dbf(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl

/* FILE OPERATIONS */
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//=============================Consts======================================
/* CONST*/
const int MOD=1e9 + 7;

//==============================Typedefs===================================
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<ii> vii;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vlli> vvlli;
typedef vector<vii> vvii;

//=============================Auxilary functions==========================
void low_str(string& str){fore(i, str.length()) str[i]=tolower(str[i]);}
void up_str(string& str){fore(i, str.length()) str[i]=toupper(str[i]);}
template <typename T> string num_to_str(T num) {ostringstream ostr; ostr << num; return ostr.str();}
string rev_str(string str) {reverse(str.begin(), str.end()); return str;}


//============================Functions===================================
void dfsTopo(vector<vector<int>>& adj, int node, vector<bool>& visited, stack<int>& order) {
	visited[node] = true;	
	for(int i : adj[node])
		if (!visited[i])
			dfsTopo(adj, i, visited, order);

	order.push(node);
}


stack<int> toposort(vector<vector<int>>& adj) {
	vector<bool> visited(adj.size(), false);
	stack<int> order;

	for(int i = 0; i < adj.size(); ++i)
		if (!visited[i])
			dfsTopo(adj, i, visited, order);

	return order;
}


void dfsGraph(vector<vector<int>>& adj, int node, vector<bool>& visited) {
	visited[node] = true;

	for(int i : adj[node])
		if (!visited[i])
			dfsGraph(adj, i, visited);
}


void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n, vector<int>());
	vector<vector<int>> adj_rev(n, vector<int>());

	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;

		adj[x - 1].push_back(y - 1);
		adj_rev[y - 1].push_back(x - 1);
	}

	vector<bool> visited(adj.size(), false);
	stack<int> topoOrder = toposort(adj);

	int ans = 0;

	while (!topoOrder.empty()) {
		int node = topoOrder.top();
		topoOrder.pop();
		if (!visited[node]) {
			dfsGraph(adj_rev, node, visited);
			ans++;
		}
	}
	cout << ans << el;
}

//===========================Main=========================================
int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	bool multi_input = false;

	if (multi_input) {
	
		int t = 1;
		cin >> t;

		while(t--)
		{
			solve();
		}
	}
	else
		solve();


	cerr << "\nTime taken: " << (float) clock() / CLOCKS_PER_SEC << " seconds" << endl;
}

