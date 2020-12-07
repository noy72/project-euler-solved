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

class Number{
	int n;
	public:
	vector<int> a;
	Number(int n) : n(n), a(n, 0) { }
	void add(vector<int>& b){
		reverse(all(b));
		rep(i,b.size()){
			a[i + 1] += (a[i] + b[i]) / 10;
			a[i] = (a[i] + b[i]) % 10;
		}
		rep(i,n - 1){
			a[i + 1] += a[i] / 10;
			a[i] = a[i] % 10;
		}
	}
	void add(string s){
		vector<int> b(s.size());
		rep(i,s.size()) b[i] = s[i] - '0';
		add(b);
	}
	vector<int> get(){
		vector<int> res = a;
		while(res.back() == 0 and not res.empty()) res.pop_back();
		reverse(all(res));
		return res;
	}
	void out(){
		vector<int> res = get();
		for(auto i : res) cout << i;
		cout << endl;
	}
};

int main(){
	Number a(2000);
	a.add("1");
	vector<int> pre = {1};
	rep(i,10000){
		vector<int> tmp = a.get();
		a.add(pre);
		pre = tmp;
		if(a.get().size() >= 1000) {
			cout << i + 3 << endl;
			return 0;
		}
	}
}
