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

map<int, int> primeFactor(int n){
	map<int, int> res;
	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			++res[i];
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res;
}

int main(){
	set<map<int,int>> s;
	range(a,2,101){
		map<int,int> t = primeFactor(a);
		map<int,int> sum = t;
		range(b,2,101){
			for(auto i : t) sum[i.first] += i.second;
			s.emplace(sum);
		}
	}
	cout << s.size() << endl;
}
