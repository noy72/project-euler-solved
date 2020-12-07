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

int main(){
	int f = 1,g = 1;
	range(i,10,100){
		range(j,i + 1,100){
			if(j % 10 == 0) continue;
			double a = i, b = j;

			double x = 0, y = 0;
			if(i % 10 == j / 10) x = static_cast<double>(i / 10) / static_cast<double>(j % 10);
			if(i / 10 == j % 10) y = static_cast<double>(i % 10) / static_cast<double>(j / 10);
			if(abs(a / b - x) < 1e-10 or abs(a / b - y) < 1e-10){
				cout << i << ' ' << j << endl;
				f *= i;
				g *= j;
			}
		}
	}

	while(gcd(f,g) != 1){
		cout << f << ' ' << g << endl;
		int t = gcd(f, g);
		f/=t; g/=t;
	}
	cout << g << endl;
}
