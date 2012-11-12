#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
	char arr[] = {'S', 'H', 'E', 'L', 'L', 'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
	int N = sizeof(arr);
	int h = 1;

	while(h < N/3) {
		h = 3*h + 1;
	}

	while(h >= 1) {
		for(int i = h; i < N; i++) {
			for(int j = i; j >= h &&  (arr[j] < arr[j-h]); j -= h) {
				swap(arr[j], arr[j-h]);
			}
		}
		h = h/3;
	}

	for(int i = 0; i < N; i++) {
		cout << arr[i] << " -- ";
	}
	cout << endl;

	return 0;
}