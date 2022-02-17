#include <iostream>

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

void ShakerSort(int* const A, const int n)
{
	int s, M = 0, C = 0, L = 0, R = n - 1, k = n;
	do {
		for (int j = R; j > L; j--) {
			if (A[j] < A[j - 1]) {
				s = A[j];
				A[j] = A[j - 1];
				A[j - 1] = s;
				k = j;
				M += 3;
			}
			C++;
		}

		L = k;

		for (int j = L; j < R; j++) {
			if (A[j] > A[j + 1]) {
				s = A[j];
				A[j] = A[j + 1];
				A[j + 1] = s;
				k = j;
				M += 3;
			}
			C++;
		}
		R = k;
	} while (L < R);

	cout << M + C;
}

void BubbleSort(int* const A, const int n)
{
	int s, M = 0, C = 0;
	for (int i = 0; i < (n - 1); i++) {
		for (int j = (n - 1); j > i; j--) {
			C++;
			if (A[j] < A[j - 1]) {
				s = A[j];
				A[j] = A[j - 1];
				A[j - 1] = s;
				M += 3;
			}
		}
	}
	cout << M + C;
}

void SelectSort(int* const A, const int n)
{
	int min, s, M = 0, C = 0;
	for (int i = 0; i < (n - 1); i++) {
		min = i + 1;

		for (int j = i + 1; j < n; j++) {
			C++;
			if (A[j] < A[min]) {
				min = j;
			}
		}

		M += 3;
		if (A[min] < A[i])
		{
			s = A[min];
			A[min] = A[i];
			A[i] = s;
		}
	}
	cout << M + C;
}

int main()
{
	int M, C, n;

	cout << "n       SelectSort    BubbleSort    ShakerSort    InsertSort" << endl;
	for (int i = 1; i <= 5; i++) {
		n = 100 * i;

		int* A = new int[n];
		FillRand(A, n);

		if (n == 100) {
			FillRand(A, n);
			cout << n << "     "; SelectSort(A, n); FillRand(A, n);
			cout << "          "; BubbleSort(A, n); FillRand(A, n);
			cout << "         "; ShakerSort(A, n);  FillRand(A, n);
			cout << "         ";  InsertSort(A, n);
			cout << endl;
		}

		if (n == 200) {
			FillRand(A, n);
			cout << n << "     "; SelectSort(A, n); FillRand(A, n);
			cout << "         "; BubbleSort(A, n); FillRand(A, n);
			cout << "         "; ShakerSort(A, n);  FillRand(A, n);
			cout << "         ";  InsertSort(A, n);
			cout << endl;
		}

		if (n == 300) {
			FillRand(A, n);
			cout << n << "     "; SelectSort(A, n); FillRand(A, n);
			cout << "         "; BubbleSort(A, n); FillRand(A, n);
			cout << "        "; ShakerSort(A, n);  FillRand(A, n);
			cout << "         ";  InsertSort(A, n);
			cout << endl;
		}

		if (n == 400) {
			FillRand(A, n);
			cout << n << "     "; SelectSort(A, n); FillRand(A, n);
			cout << "         "; BubbleSort(A, n); FillRand(A, n);
			cout << "        "; ShakerSort(A, n);  FillRand(A, n);
			cout << "        ";  InsertSort(A, n);
			cout << endl;
		}

		if (n == 500) {
			FillRand(A, n);
			cout << n << "     "; SelectSort(A, n); FillRand(A, n);
			cout << "        "; BubbleSort(A, n); FillRand(A, n);
			cout << "        "; ShakerSort(A, n);  FillRand(A, n);
			cout << "        ";  InsertSort(A, n);
			cout << endl;
		}
	}
}