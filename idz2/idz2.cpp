#include <iostream>
#include <iomanip>
#include <random>
using namespace std;



int CheckRow(int* row, size_t length) {
	for (int i = 0; i < length - 1; i++)
		if (row[i] < row[i + 1])
			return 0;
	return 1;
}

void InitMatrix(int* M, size_t size) {
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<int> random_element(0, 9);

	for (int i = 0; i < size; i++) {
		M[i] = random_element(mersenne);
	}
}

void PrintMatrix(int* M, size_t rows, size_t cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(3) << M[i * rows + j];
		}
		cout << endl;
	}
}

int main()
{
	int s1, s2;
	cout<<"input n"<<endl;
	cin>>s1;
	cout<<"input m"<<endl;
	cin>>s2;
	size_t n = s1;
	size_t m = s2;
	int* M = new int[m * n];
	int* B = new int[n];
	int* row = M;


	InitMatrix(M, m * n);


	for (size_t i = 0; i < n; i++) {
		B[i] = CheckRow(row, m);
		row = row + m;
	}


	cout << "Matrix: " << endl;
	PrintMatrix(M, n, m);
	cout << endl << "Vector:";
	PrintMatrix(B, 1, n);
	return 0;
}