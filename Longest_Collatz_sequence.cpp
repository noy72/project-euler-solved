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
	long long maxi = 0;
	long long num;
	for (int i = 1000000; i >= 1; i--) {
		long long t = i;
		long long cnt = 0;
		while(t != 1){
			cnt++;
			if(t % 2){
				t = t * 3 + 1;
			}else{
				t /= 2;
			}
		}
		if(maxi < cnt){
			maxi = cnt;
			num = i;
		}
	}
	cout << num << endl;
}
