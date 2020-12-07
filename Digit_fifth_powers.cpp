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

int p(int a){
	return a * a * a * a * a;
}

int main(){
	int ans = 0;
	range(i,2,1000000){
		int c = i;
		int sum = 0;
		while(c != 0){
			sum += p(c % 10);
			c /= 10;
		}
		if(sum == i) ans += i;
	}
	cout << ans << endl;
}
