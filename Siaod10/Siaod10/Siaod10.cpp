#include <iostream>

using namespace std;

void PrintMas(int* const A, const int n)
{
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << "\n";
}

void FillInc(int* const A, const int n)
{
	for (int i = 0; i < n; i++) A[i] = i + 1;
}

void FillDec(int* const A, const int n)
{
	for (int i = n; i > 0; i--) A[n - i] = i;
}

void FillRand(int* const A, const int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) A[i] = rand() % n + 1;
}

int QuickSort(int* const A, const int n, int L, int R)
{
	int x = A[L], i = L, j = R, CM = 0;
	while (L < R) {
		while (A[i] < x) ++i;
		while (A[j] > x) --j;
		if (i <= j) {
			swap(A[i], A[j]);
			CM += 3;
			++i;
			--j;
		}
		if (j - L < R - i) {
			CM += QuickSort(A, n, i, R);
			R = j;
		}
		else {
			CM += QuickSort(A, n, L, j);
			L = i;
		}
	}
	return CM;
}



int main()
{
	int M, C, n;
	float Ct, Mt;
	cout << "n      M+C(t)    Dec(M+C)    Inc(M+C)    Rand(M+C)" << endl;
	for (int i = 1; i <= 5; i++) {
		n = 100 * i;

		int* A = new int[n];

		Ct = (pow(n, 2) + (5 * n) + 4) / 2;
		Mt = 3 * (n - 1);


		if (n == 100) {
			cout << n << "    " << Mt + Ct << "      "; FillDec(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "        "; FillInc(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "         "; FillRand(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << endl;
		}

		if (n == 200) {
			cout << n << "    " << Mt + Ct << "     "; FillDec(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "       "; FillInc(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "         "; FillRand(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << endl;
		}

		if (n == 300) {
			cout << n << "    " << Mt + Ct << "     "; FillDec(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "       "; FillInc(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "         "; FillRand(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << endl;
		}

		if (n == 400) {
			cout << n << "    " << Mt + Ct << "     "; FillDec(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "      "; FillInc(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "        "; FillRand(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << endl;
		}

		if (n == 500) {
			cout << n << "    " << Mt + Ct << "    "; FillDec(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "      "; FillInc(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << "        "; FillRand(A, n); cout << QuickSort(A, n, 0, n - 1);
			cout << endl;
		}
	}
}