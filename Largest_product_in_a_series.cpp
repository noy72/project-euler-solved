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
	string s;
	cin >> s;

	long long maxi = 0;
	rep(i,s.size() - 13){
		string t = s.substr(i,13);

		long long pro = 1;
		rep(i,t.size()) pro *= t[i] - '0';
		maxi = max(maxi, pro);
	}
	cout << maxi << endl;
}
