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
	vector<vector<long long>> v;
	int i = 1;
	while(true){
		v.emplace_back();
		rep(j,i){
			int a;
			if(cin >> a){
				v[i - 1].emplace_back(a);
			}else{
				goto END;
			}
		}
		i++;
	}
END:;
	show(v.size())
	
	rep(i,v.size()) v[v.size() - 1].emplace_back(0);

	vector<vector<long long>> dp(v.size(), vector<long long>(v.size(), 0));
	dp[0][0] = v[0][0];
	rep(i,v.size() - 2){
		rep(j,i + 1){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + v[i + 1][j + 1]);
			//cout << v[i + 1][j] << ' ' << v[i + 1][ j + 1] << endl;
		}
	}
	///rep(i,v.size()){ rep(j,i + 1){ cout << dp[i][j] << ' '; } cout << endl; }
	cout << *max_element(all(dp[v.size() - 2])) << endl;
}
