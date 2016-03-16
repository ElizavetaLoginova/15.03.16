#include <iostream>

using namespace std;

void Swap(int* &, int* &);
void FreeHeap(int**, int);
int** AllocMemory(int, int);
int FindMax(int*, int);
int* RandomArray(int *a, int n);
void DisplayMatrix(int** a, int n, int m);
void SortExchange(int** a, int n);
int* RandomMatrix(int **a, int n, int m);

int main()
{
	while (true)
	{
		int n, m;
		while (true)
		{
			cout << "Enter n - number of lines: " << endl;
			cin >> n;
			cout << "Enter m - number of columns:" << endl;
			cin >> m;
			if (n > 0 && n <= 258 && m <= 258 && m > 0);
			{
				break;
			}
			cout << "Error! Try again...";
		}

		int **a = AllocMemory(n, m);

		RandomMatrix(a, n, m);

		DisplayMatrix(a, n, m);
		SortExchange(a, n);

		cout << endl << "NEW"<< endl;
		DisplayMatrix(a, n, m);

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
		system("cls");
	}

	system("pause");
	return 0;
}

int FindMax(int*a, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if(a[i] >= a[max])
			max = i;
	}
	return a[max];
}

void Swap(int* &x, int* &y)
{
	int* temp = x;
	x = y;
	y = temp;
}

void FreeHeap(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}

int** AllocMemory(int n, int m)
{
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	return a;
}

int* RandomArray(int *a, int n)
{
	for (int* p = a; p < a + n; p++)
		*p = rand() % 200 - 100;
	return a;
}

int* RandomMatrix(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
		a[i] = RandomArray (a[i], m);
	return a[m];
}
void DisplayMatrix(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void SortExchange(int** a, int n)
{
	
	{
		int max = 0;
		if (FindMax(a[i], n) > FindMax(a[i + 1], n))
		{
			max = i;
			Swap(a[i], a[i+1]);
		}
	}
}
