#include <iostream>
using namespace std;


bool conversion(char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

int calculation(char op, int num1, int num2) {
	switch (op) {
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '/':
		return num1 / num2;
	case '*':
		return num1 * num2;
	default:
		return 0;
	}
}
void Mistakes(char* arr, bool& examination)
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < arr[i] != 0; i++)
	{
		if ((arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') &&
			(arr[i + 1] == '+' || arr[i + 1] == '-' || arr[i + 1] == '*' || arr[i + 1] == '/'))
		{
			cout << "Неверное выражение" << endl;
			examination = 1;
			break;
		}
		else if (arr[i] >= 58 || arr[i] <= 39)
		{
			cout << "Неверное выражент" << endl;
			examination = 1;
			break;
		}
		else if ((arr[0] >= 57 || arr[0] <= 48) && arr[0] != 40)
		{
			cout << "Неверное выражент" << endl;
			examination = 1;
			break;
		}
		else examination = 0;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char arr[100];
	bool examination = 1;
	while (examination == 1)
	{
		cout << "Введите ваше выражение: ";
		cin.getline(arr, 100);
		Mistakes(arr, examination);
	}
	int numArr[100]{};
	char opArr[100]{};
	int null = 0;
	int tmp = 0;
	for (int i = 0; arr[i] != 0; i++)
	{
		if (conversion(arr[i]))
		{
			int num = arr[i] - '0';
			while (conversion(arr[i + 1]))
			{
				num = num * 10 + (arr[i + 1] - '0');
				i++;
			}
			numArr[null++] = num;
		}
		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
		{
			while (tmp > 0 && (opArr[tmp - 1] == '*' || opArr[tmp - 1] == '/'))
			{
				int b = numArr[--null];
				int a = numArr[--null];
				char op = opArr[--tmp];
				numArr[null++] = calculation(op, a, b);
			}
			opArr[tmp++] = arr[i];
		}
		else if (arr[i] == '(')
		{
			opArr[tmp++] = '(';
		}
		else if (arr[i] == ')')
		{
			while (tmp > 0 && opArr[tmp - 1] != '(')
			{
				int num1 = numArr[--null];
				int num2 = numArr[--null];
				char op = opArr[--tmp];
				numArr[null++] = calculation(op, num1, num2);
			}
			tmp--;
		}
	}
	while (tmp > 0)
	{
		int num1 = numArr[--null];
		int num2 = numArr[--null];
		char op = opArr[--tmp];
		numArr[null++] = calculation(op, num1, num2);
	}
	cout << "Ответ: " << numArr[0] << endl;
	return 0;
}


