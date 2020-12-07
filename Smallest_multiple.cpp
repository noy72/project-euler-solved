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

int gcd(int x, int y) {
	int r;
	if(x < y) swap(x, y);

	while(y > 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int lcm( int m, int n ) {
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) ) return 0;
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

int main(){
	long long cur = 1;
	range(i,1,21){
		cur = lcm(cur, i);
		show(cur)
	}
	cout << cur << endl;

	cur = 1;
	range(i,1,21){
		cur *= i;
		range(j,1,21) if(cur % (j * j) == 0) cur /= j;
	}
	cout << cur << endl;
}
