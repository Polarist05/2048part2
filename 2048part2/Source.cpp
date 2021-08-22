#include<iostream>
#include<string>
#include<vector>
using namespace std;
enum enumDirection
{
	Up,Down,Left,Right
};
int si = 4, a;
void Move(int count, vector<vector<int>>& v, vector<vector<int>>& v2) {
	vector<vector<int>> v1(5, vector<int>());
	for (int j = 0; j < si; j++) {
		int k,vbegin;
		if (count == 1) {
			k = count;
			vbegin = 0;
		}
		else {
			k = v[j].size() - 1 + count;
			vbegin = si-1;
		}
		for (; k < (signed int)v[j].size() && k >= 0; k += count) {
			int pos = vbegin + count * v1[j].size();
			if (v[j][k] == v[j][k - count]) {
				v2[pos].push_back(v[j][k - count]*2);
				v1[j].push_back(v[j][k - count] * 2);
				k += count;
			}
			else {
				v2[pos].push_back(v[j][k - count]);
				v1[j].push_back(v[j][k - count]);
			}
		}
		if (k == v[j].size() || k == -1) {
			int pos = vbegin + count * v1[j].size();
			v2[pos].push_back(v[j][k - count]);
			v1[j].push_back(v[j][k - count]);
		}
		if (count==-1)
			reverse(v1[j].begin(), v1[j].end());
	}
	v = v1;
}
int main() {
vector<vector<int>> ans1(5, vector<int>()), ans2(5, vector<int>());
	string s;
	for (int i = 0; i < si; i++) {
		for (int j = 0; j < si; j++) {
			scanf_s("%d", &a);
			if (a != 0){
				ans1[i].push_back(a);
				ans2[j].push_back(a);
			}
		}
	}
	cin >> s;
	for (int i = 0; i < (signed int)s.size(); i++) {
		switch (s[i])
		{
		case('U'):
			ans1 = vector<vector<int> >(5, vector<int>());
			Move(1, ans2, ans1);
			break;
		case('D'):
			ans1 = vector<vector<int> >(5, vector<int>());
			Move(-1, ans2, ans1);
			break;
		case('L'):
			ans2 = vector<vector<int> >(5, vector<int>());
			Move(1, ans1, ans2);
			break;
		case('R'):
			ans2 = vector<vector<int> >(5, vector<int>());
			Move(-1, ans1, ans2);
			break;
		}	
	}
	if (s[s.size() - 1] == 'L') {
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < si; j++) {
				if (j < ans1[i].size())
					printf("%d ", ans1[i][j]);
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
	if (s[s.size() - 1] == 'R') {
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < si; j++) {
				if (j >= si - ans1[i].size())
					printf("%d ", ans1[i][j - si + ans1[i].size()]);
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
	if (s[s.size() - 1] == 'U') {
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < si; j++) {
				if (i < ans2[j].size())
					printf("%d ", ans2[j][i]);
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
	if (s[s.size() - 1] == 'D') {
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < si; j++) {
				if (i >= si - ans2[j].size())
					printf("%d ", ans2[j][i - si + ans2[j].size()]);
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
}