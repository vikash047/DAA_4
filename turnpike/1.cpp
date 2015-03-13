			#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int maxd, N;
int dist[1000];
int arr[1000];

int findIndex(int d, vector<bool> used)
{
	for (int i = 0; i < maxd; i++) {
		if (!used[i] && dist[i] == d)
			return i;
	}

	return -1;
}

bool correct(vector<bool> &used, int index, vector<int> &indexs)
{
		
	vector<int> pos;

	for (int i = 0; i < indexs.size() - 1; i++) {
		
		int d = abs(arr[index] - arr[indexs[i]] );
			
		int x = findIndex( d, used );
		if (x != -1) {
			used[x] = true;
			pos.push_back(x);
		}
		else {
			for (int j = 0; j < pos.size(); j++) {

				used[pos[j] ] = false;
			}
			indexs.pop_back();
			return false;
		}
		
	}

	return true;
}

int getLast(vector<bool> &used)
{
	for (int i = used.size() -1; i >= 0; i--) {
			if (!used[i])
					return i;
	}

	return -1;
}

bool funct(vector<bool> used, int l, int u, int level, vector<int> &indexs)
{
	if (indexs.size() == N)
		return true;
	
	int d = getLast(used);	
	arr[u-1] = dist[d];
	indexs.push_back(u-1);
	
	bool flag = false;
	

		vector<bool> temp = used;	
	if (correct(used, u-1, indexs) )  {
		flag = funct(used, l, u-1, level + 1, indexs);	
		if (!flag) {
			indexs.pop_back();
			used = temp;

		}
	}

	if (!flag) {
		
		d = getLast(used);
		arr[l+1] = dist[maxd- 1] - dist[d];

		indexs.push_back(l+1);

		if (correct(used, l+1, indexs))
			flag = funct(used, l+1, u, level+ 1, indexs);
	}

	return flag;
}

int main()
{
	cin >> maxd;
	vector<int> indexs;

	for (int i = 0; i < maxd; i++) 
		cin >> dist[i];

	sort(dist,  dist + maxd);

	N = ( 1 + sqrt(1 + 8*maxd) ) / 2;
	
	vector<bool> used(maxd, false);
	used[maxd-1] = true;

	indexs.push_back(0);
	indexs.push_back(N-1);
	
	arr[N-1] = dist[maxd-1];

	funct(used, 0, N-1, 1, indexs);
	
	for (int i = 0 ; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
	
		
	return 0;
}
