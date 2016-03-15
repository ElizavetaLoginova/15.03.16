#include <iostream>

using namespace std;

char** ObtainWords(char*, int&);
int NumberOfEqualwords(char**, char*, int, int);
void DisplayWords(char**, int);
void Swap(char* &, char* &);
void FreeHeap(char**, int);
bool IsTheSameWords(char**, int, char*);
void SortingWords(char** str, char** words, int n, int);

int main()
{
	const int LENGTH = 256;
	char str[LENGTH];
	cout << "Enter the string: ";
	cin.getline(str, LENGTH, '\n');
	system("cls");

	char words[LENGTH];
	cout << "Enter words: ";
	cin.getline(words, LENGTH, '\n');
	system("cls");

	cout << endl << "\tSTRING IS:" << endl;
	cout << str;
	cout << endl << "\tWORDS ARE:" << endl;
	cout << words;

	int n = 0, k = 0;
	char** arrayWordsStr = ObtainWords(str, n);
	char** arrayWords = ObtainWords(words, k);

	cout << endl << "\tARRAY OF WORDS OF THE STRING" << endl;
	DisplayWords(arrayWordsStr, n);


	SortingWords(arrayWordsStr, arrayWords, n, k);
	cout << endl << "\tNEW ARRAY OF WORDS" << endl;
	DisplayWords(arrayWords, k);
	FreeHeap(arrayWords, k);
	system("pause");
	return 0;
}

void DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
		cout << (i + 1) << ". " << words[i] << endl;
}

int NumberOfEqualwords(char**str, char*word, int len)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	for (int j = len - 1; j > i; j--)
	if (IsTheSameWords(str, len, word))
		k++;
	return k;
}

bool IsTheSameWords(char** words, int n, char* word)
{
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(words[i], word)) return true;
	}
	return false;
}

void Swap(char* &x, char* &y)
{
	char* temp = x;
	x = y;
	y = temp;
}

void FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
		delete[] words[i];
	delete[] words;
}

char** ObtainWords(char* str, int &k)
{
	char* s = new char[strlen(str) + 1];
	strcpy(s, str);
	char** words = new char*[strlen(str) / 2];
	k = 0;
	char* symbols = "	1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* pword = strtok(s, symbols);
	words[k] = new char[strlen(pword) + 1];
	strcpy(words[k], pword);
	k++;
	while (pword)
	{
		pword = strtok('\0', symbols);
		if (pword)
		{
			words[k] = new char[strlen(pword) + 1];
			strcpy(words[k], pword);
			k++;
		}
	}
	delete[] s;
	return words;
}

void SortingWords(char** str, char** words, int n, int k)
{
	for (int i = 0; i < k; i++)
	for (int j = k - 1; j > i; j--)
	if (NumberOfEqualwords(str, words[j], n) > NumberOfEqualwords(str, words[j - 1], n))
		Swap(words[j], words[j - 1]);
}
