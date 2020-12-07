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
			if(i != n / i) res += (n / i);
		}
	}
	return res - n;
}

bool check(int s, vector<bool>& use){
	range(i,2,s){
		if(use[s - i] && use[i]) return true;
	}
	return false;
}

int main(){
	vector<bool> use(28124, 0);
	range(i,2,28124){
		int sum = divisor(i);
		if(i < sum) use[i] = true;
	}

	long long ans = 1;
	range(i,2,28124){
		if(not check(i, use)) ans += i;
	}
	cout << ans << endl;
}
