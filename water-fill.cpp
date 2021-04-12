#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double arr[10][10];
int i, j;

void fill(float water,int row,int rowp) {
	arr[row][rowp] += water;
	if (arr[row][rowp] > 1) {
		float ewater = arr[row][rowp] - 1;
		arr[row][rowp] = 1;
		fill(ewater / 2, row + 1, rowp);
		fill(ewater / 2, row + 1, rowp + 1);
	}
}

double find(float water, int i, int j) {
	i -= 1;
	j -= 1;
	fill(water, 0, 0);
	arr[i][j] *= 100;
	arr[i][j] = floor(arr[i][j]);
	arr[i][j] /= 100;
	cout << setprecision(2);
	cout << fixed;
	return arr[i][j];
}


int main() {
	double water;
	int i;
	int j;
	cin >> water;
	cin >> i >> j;
	cout << find(water, i, j);
}