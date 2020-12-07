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

int divisor(int n){
	int res = 0;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			res += i;
			if(i != n / i) res += n / i;
		}
	}
	return res;
}

int main(){
	set<pair<int, int>> s;
	range(a,2,10001){
		int b = divisor(a) - a;
		if(a == divisor(b) - b and a != b){
			cout << a << ' ' << b << endl;
			if(a > b) s.emplace(b,a);
			else s.emplace(a,b);
		}
	}

	int sum = 0;
	for(auto i : s) {
		sum += i.first + i.second;
	}
	cout << sum << endl;
}
