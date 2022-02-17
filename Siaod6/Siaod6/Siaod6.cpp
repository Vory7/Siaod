#include <iostream>
#include <cmath>

using namespace std;

void FillRand(int* const A, const int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) A[i] = rand() % n + 1;
}

void InsertSort(int* const A, const int n) {
	int M = 0, C = 0, t;
	for (int i = 1; i < n; i++) {
		M++;
		t = A[i]; int j = i - 1;
		while ((j >= 0) && (t < A[j])) {
			M++;
			C++;
			A[j + 1] = A[j];
			j--;
		}
		M++;
		A[j + 1] = t;
	}
	cout << M + C;
}

int func(int m) {
	int k = 0;
	if (m > 1) {
		k = 2 * func(m - 1) + 1;
	}
	if (m == 1) {
		k = 1;
	}
	return k;
}

void ShellSort(int* const A, const int n)
{
	int M = 0, C = 0, t, m;
	m = int(trunc(float(log(n) / log(2)))) - 1;
	for (int k = func(m); k >= 1; k = func(m)) {
		for (int i = k; i < n; i++) {
			M++;
			t = A[i]; int j = i - k;
			while ((j >= 0) && (t < A[j])) {
				M++;
				C++;
				A[j + k] = A[j];
				j -= k;
			}
			M++;
			A[j + k] = t;
		}
		m--;
	}
	cout << M + C;
}

int main()
{
	int M, C, n, m;

	cout << "n       k     InsertSort   ShellSort" << endl;
	for (int i = 1; i <= 5; i++) {
		n = 100 * i;
		m = int(trunc(float(log(n) / log(2)))) - 1;

		int* A = new int[n];
		FillRand(A, n);
		if (n == 100) {
			FillRand(A, n);
			cout << n << "     "<< m << "     "; InsertSort(A, n);  FillRand(A, n);
			cout << "         ";  ShellSort(A, n);
			cout << endl;
		}

		if (n == 200) {

			FillRand(A, n);
			cout << n << "     " << m << "     "; InsertSort(A, n);  FillRand(A, n);
			cout << "        ";  ShellSort(A, n);
			cout << endl;
		}

		if (n == 300) {
			FillRand(A, n);
			cout << n << "     " << m << "     "; InsertSort(A, n);  FillRand(A, n);
			cout << "        ";  ShellSort(A, n);
			cout << endl;
		}

		if (n == 400) {
			FillRand(A, n);
			cout << n << "     " << m << "     "; InsertSort(A, n);  FillRand(A, n);
			cout << "        ";  ShellSort(A, n);
			cout << endl;
		}

		if (n == 500) {
			FillRand(A, n);
			cout << n << "     " << m << "     "; InsertSort(A, n);  FillRand(A, n);
			cout << "       ";  ShellSort(A, n);
			cout << endl;
		}
	}
}