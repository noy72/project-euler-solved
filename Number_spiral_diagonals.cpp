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

class UlamSpiral{
	private:
		const static int MAX_N = 1005;
		const static int kN = 1;
		void primeNumber(bool prime[kN]){
			rep(i,kN) prime[i] = 1;
			prime[0] = prime[1] = 0;
			rep(i,kN){
				if(prime[i]){
					for(int j = i + i; j < kN; j+=i){
						prime[j] = 0;
					}
				}
			}
		}

	public:
		int spiral[MAX_N][MAX_N] = {{0}};
		int CENTER;
		bool p[kN] = {0};
		const int dy[4] = { 0,-1, 0, 1}; //反時計回り
		const int dx[4] = { 1, 0,-1, 0};
		UlamSpiral(int n){ //自然数の数
			CENTER = MAX_N / 2;;

			primeNumber(p);

			int x = CENTER, y = CENTER;
			int dir = 0; //右向き
			rep(i,n){
				spiral[y][x] = i + 1;
				x += dx[dir % 4];
				y += dy[dir % 4];

				int nx = x + dx[(dir + 1) % 4];
				int ny = y + dy[(dir + 1) % 4];
				if(spiral[ny][nx] == 0){
					dir++;
				}
			}
		}

		pair<int, int> getPoint(int n){ //数値nがある座標
			rep(i,MAX_N){
				rep(j,MAX_N){
					if(spiral[i][j] == n){
						return make_pair(i,j);
					}
				}
			}
			assert(false);
			return make_pair(-1,-1);
		}

		bool isPrime(int n){
			return p[n];
		}
		bool isPrime(int y, int x){
			if(spiral[y][x] == -1) return 0;
			return p[spiral[y][x]];
		}

		void out(){
			show(CENTER)
				for(int i = CENTER - 11; i < CENTER + 11; i++){
					for(int j = CENTER - 11; j < CENTER + 11; j++){
						//printf("%02d ", spiral[i][j]);
						if(p[spiral[i][j]]){
							printf("%02d ", spiral[i][j]);
						}else{
							cout << "__ ";
						}
					}
					cout << endl;

				}
		}
};

const int dy[16] = {  1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = {  1, 1,-1,-1, 2, 0,-2, 0};

long long dfs(int y, int x, int d, int c, int g[1005][1005]){
	if(c == 0) return 0;
	return g[y][x] + dfs(y + dy[d], x + dx[d], d, c - 1, g);
}

int main(){
	UlamSpiral ulam(1001 * 1001);

	pair<int, int> c = ulam.getPoint(1);
	long long ans = 1;
	rep(i,4){
		ans += dfs(c.first + dy[i], c.second + dx[i], i, 1001 / 2, ulam.spiral);
	}
	cout << ans << endl;
}
