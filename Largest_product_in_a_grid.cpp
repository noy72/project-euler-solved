#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const int dy[16] = { 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0, 1, 1,-1,-1, 2, 0,-2, 0};
int a[20][20];

long long dfs(int i, int j, int d, int c){
	if(c == 0) return 1;
	if(i >= 20 or j >= 20 or i < 0) return 0;
	long long res = a[i][j];
	res *= dfs(i + dy[d], j + dx[d], d, c - 1);
	return res;
}

int main(){
	rep(i,20) rep(j,20) cin >> a[i][j];

	long long maxi = 0;
	rep(i,20){
		rep(j,20){
			rep(d,4){
				maxi = max(maxi, dfs(i, j, d, 4));
			}
		}
	}
	cout << maxi << endl;
}
