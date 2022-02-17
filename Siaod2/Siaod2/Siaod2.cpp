#include <iostream>

const int n = 10;

void FillRand(int A[n]);
void FillInc(int A[n]);
void FillDec(int A[n]);
void SelectSort(int A[n]);
void PrintMas(int A[n]);
int CheckSum(int A[n]);
int RunNumber(int A[n]);

using namespace std;

int main()
{
	int A[n], M, C, Mt;
	float Ct;

	Mt = 3 * (n - 1);
	Ct = float(pow(n, 2) - n) / 2;

	cout << "Mt = " << Mt << endl;
	cout << "Ct = " << Ct << endl;

	FillRand(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl;

	SelectSort(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl << endl << endl;

	FillInc(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl;

	SelectSort(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl << endl << endl;

	FillDec(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl;

	SelectSort(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  " << endl << endl << endl << endl;

}

void FillRand(int A[n])
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) A[i] = rand() % n + 1;
}

void SelectSort(int A[n]) 
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
	cout << "M = " << M << endl;
	cout << "C = " << C << endl;
}

int CheckSum(int A[n])
{
	int sum = 0;
	for (int i = 0; i < n; i++) sum += A[i];
	return sum;
}

int RunNumber(int A[n])
{
	int num = 1;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] > A[i + 1]) num++;
	}
	return num;
}

void PrintMas(int A[n])
{
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << "\n";
}

void FillInc(int A[n])
{
	for (int i = 0; i < n; i++) A[i] = i + 1;
}

void FillDec(int A[n])
{
	for (int i = n; i > 0; i--) A[n - i] = i;
}