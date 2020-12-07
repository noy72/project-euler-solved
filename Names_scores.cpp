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

long long get(string& s){
	long long res = 0;
	for(auto i : s){
		res += i - 'A' + 1;
	}
	return res;
}

int main(){
	string s;
	vector<string> v;
	long long sum = 0;
	while(cin >> s){
		v.emplace_back(s);
	}
	sort(all(v));
	rep(i,v.size()){
		sum += get(v[i]) * (i + 1);
	}
	cout << sum << endl;
}
