#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

char** ObtainWords(char*, int&);
void DisplayWords(char**, int);
char* ToTurnTheWord(char* a, int n);
bool IsTheSameWords(char**, int, char*);
void FreeHeap(char**, int);

int main()
{
	const int LENGTH = 256;
	char str[LENGTH];
	cout << "Enter the string: ";
	cin.getline(str, LENGTH, '\n');
	system("cls");

	cout << endl << "\tSTRING IS:" << endl;
	cout << str;
	
	int n = 0;
	char** arrayWordsStr = ObtainWords(str, n);
	
	cout << endl << "\tARRAY OF WORDS OF THE STRING" << endl;
	DisplayWords(arrayWordsStr, n);

	cout << endl << "\tNEW ARRAY OF WORDS" << endl;
	for (int i = 0; i < n; i++)
	for (int j = n - 1; j > i; j--)
	if (IsTheSameWords(arrayWordsStr, n, ToTurnTheWord(arrayWordsStr[j], strlen(arrayWordsStr[j]))))
		cout << arrayWordsStr[j] << " - " << ToTurnTheWord(arrayWordsStr[j], strlen(arrayWordsStr[j])) << endl;
	
	FreeHeap(arrayWordsStr, n);
	system("pause");
	return 0;
}

void DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
		cout << (i + 1) << ". " << words[i] << endl;
}

bool IsTheSameWords(char** words, int n, char* word)
{
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(words[i], word)) return true;
	}
	return false;
}

char* ToTurnTheWord(char* a, int n)
{
	char *b = new char[n + 1];
	b[n] = '\0';
	for (int i = n-1; i >= 0; i--)
		b[i] = a[n - 1 - i];
	return b;
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
