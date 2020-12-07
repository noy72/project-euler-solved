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

int main(){
	long long dp[30][30] = {0};
	dp[0][0] = 1;
	rep(i,21){
		rep(j,21){
			dp[i + 1][j] += dp[i][j];
			dp[i][j + 1] += dp[i][j];
		}
	}
	cout << dp[20][20] << endl;
}
