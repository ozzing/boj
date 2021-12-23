#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 25
int** map;
int *affected;
int n;
int num;
vector <int> vec;

int xval[4] = { -1,1,0,0 };
int yval[4] = { 0,0,-1,1 };

void dfs(int i, int j) {
	num++;
	affected[i * n + j] = 1;

	for (int k = 0; k < 4; k++) {
		int newi = i + xval[k];
		int newj = j + yval[k];
		if (newi >= 0 && newi < n && newj >= 0 && newj < n) {
			if (affected[newi * n + newj] == 0 && map[newi][newj] == 1) {
				dfs(newi, newj);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	affected = (int*)malloc(sizeof(int) * (MAX*MAX));
	map = (int**)malloc(sizeof(int*) *MAX);
	for (int i = 0; i < n; i++) {
		*(map + i) = (int*)malloc(sizeof(int) * MAX);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
			affected[i * n + j] = 0;
	    }
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (affected[i * n + j] == 0 && map[i][j] == 1) {
    			num = 0;	
				dfs(i, j);
				vec.push_back(num);
			}
		}
    }

	sort(vec.begin(), vec.end());

	printf("%d\n", vec.size());

	for (int i = 0; i < vec.size(); i++) {
		printf("%d\n", vec[i]);
	}

	return 0;
}