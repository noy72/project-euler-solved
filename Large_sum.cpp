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
		Number(int n = 100) : n(n), a(n, 0) { }
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
		void add(string& s){
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
};

int main(){
	Number a;
	rep(i,100){
		string s;
		cin >> s;
		a.add(s);

		//vector<int> tmp = a.get();
		//cout << tmp << endl;
	}

	vector<int> b = a.get();
	rep(i,10){
		cout << b[i];
	}
	cout << endl;
}
