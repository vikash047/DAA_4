#include<iostream>
#include<string>

using namespace std;
int print(int m[][1001], int kw, int n, int w[]);

void knap(int w[], int p[], int n, int kw)
{
	int m[1001][1001];
	//cout << " 333 " << endl;
	for(int i = 0; i <= n; i++) {
		m[0][i] = 0;
	}
	for(int i = 0; i <= kw; i++) {
		m[i][0] = 0;
	}
	//cout << "333" << endl;
	for(int i = 1; i <= n; i++) {
		for(int u = 0; u <= kw; u++) {
			if(w[i] <= u) {
				//cout << " 11 " << endl;
				if(p[i] + m[i - 1][u - w[i]] > m[i - 1][u]) {
					m[i][u] = p[i] + m[i - 1][u - w[i]];
				}else {
					m[i][u] = m[i - 1][u];
				}
			}else {
				//cout << " 0000 " << endl;
				m[i][u] = m[i - 1][u];
			}
		}
	}
	/*for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= kw; j++) {
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}*/
	cout << " 222222" << endl;
	int c = print(m, kw, n, w);
	cout << c << endl;
}
	
int print(int m[][1001], int kw, int n, int w[])	
{
	int k1  = kw;
	int l = n;
	int k = m[n][kw];
	int sum = 0;
	while(k1 > 0 && l > 0) {
		if(m[l][k1] != m[l - 1][k1]) {
			cout << w[l] << "  ";
			k1  = k1 - w[l];
			sum += w[l];
		}
		l = l - 1;
	}
	return sum;
}
			
int main()
{
	int n;
	int w[101];
	int p[101];
	int kw;
	cin >> kw >> n;
	cout << kw << "  " << n << endl;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> p[i];
	}
	knap(w, p, n, kw);
	cout << " 333 " << endl;
	return 0;
}
