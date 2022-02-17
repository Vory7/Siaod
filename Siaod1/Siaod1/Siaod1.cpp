#include <iostream>
#include <cstdlib>

using namespace std;

const int n = 20;

void FillInc(int A[n]);
void PrintMas(int A[n]);
void FillDec(int A[n]);
void FillRand(int A[n]);
int CheckSum(int A[n]);
int RunNumber(int A[n]);
float FivePluse(int A[n]);

int main()
{
	int A[n], sum = 0, num = 0;
	FillInc(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  ";
	cout << "midnum = " << FivePluse(A) << "\n\n";

	FillDec(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  ";
	cout << "midnum = " << FivePluse(A) << "\n\n";

	FillRand(A);
	PrintMas(A);
	cout << "sum = " << CheckSum(A) << ";  ";
	cout << "num = " << RunNumber(A) << ";  ";
	cout << "midnum = " << FivePluse(A) << "\n\n";
	
	for (int i = 0; i < 500; i++) {
		FillRand(A);
		PrintMas(A);
		sum += CheckSum(A);
		num += RunNumber(A);
		cout << "\n";
	}
	float five = float(n*500)/float(num);
	cout << "sum = " << sum << ";  ";
	cout << "num = " << num << ";  ";
	cout << "midnum = " << five << "\n\n";
	

}

void FillInc(int A[n])
{
	for (int i = 0; i < n; i++) A[i] = i + 1;
}

void PrintMas(int A[n])
{
	for (int i = 0; i < n; i++) cout << A[i] <<  " ";
	cout << "\n";
}

void FillDec(int A[n])
{
	for (int i = n; i > 0; i--) A[n - i] = i;
}

void FillRand(int A[n])
{
	for (int i = 0; i < n; i++) A[i] = rand() % n + 1;
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

float FivePluse(int A[n])
{
	int num = 1;
	float midnum;
	midnum = float(n*500) / float(num);
	return midnum;
}
