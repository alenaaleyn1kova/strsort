#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>

using namespace std;

string Input_Inf_Str(int &str) // метод ввода неопределенного количества строк
{
	string s, result; // s - буферная строка, в нее читаем информацию с клавиатуры
	//result - итоговая строка, скомпилированная из всех полученных строк в S
	cout << "Для прекращения ввода символов необходимо нажать CTRL + Z или 2 раза на клавишу Enter" << '\n';
	while ((getline(cin, s)) && (s.length()) > 0) // считываем символы
	{
		result += s + '\n';
		str++; // счетчик строк
	}
	return result; // возвращается скомпилированная строка
}

string Get_Str(string s, int N) // метод получения строки по номеру строки
{
	int i = 0; // количество разделителей
	string buffer; // строка, вытаскиваемая по своему номеру
	const char *result = (s.c_str()); // Указатель на начало строки s
	while (i != N) // пока не встретится разделитель указанное число раз
	{
		while (*result != '\n') // ищется разделитель
		{
			if (i == N - 1) // если последующая итерация - последняя
				buffer += *result; // собирается строка, взятая по номеру
			*result++; // Переход к следующему символу
		}
		*result++; // Переход к следующему символу
		i++; // Увеличивается счетчик разделителей
	}
	return buffer; // возвращается выбранная строка
}

void Sort_Strok(string *s, int N) // метод сортировки строк
{
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (strcmp(s[i].c_str(), s[j].c_str()) > 0) // strcmp() осуществляет лексикографическую проверку двух строк, оканчивающихся нулевыми символами
			// c_str() возвращает указатель на const char для того, что она может вернуть указатель на копию строки
				swap(s[i], s[j]); // swap() обменивает значения своих аргументов
		}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int str = 0;
	string Current_Str = Input_Inf_Str(str);
	cout << "Ввод данных закончен\n\n";
	string *s = new string[str];
	for (int i = 0; i < str; i++)
	{
		s[i] = Get_Str(Current_Str, i + 1); // заполняется массив строками
	}
	Sort_Strok(s, str); // сортируется массив
	for (int i = 0; i < str; i++)
	{
		cout << s[i] << "\n";
	}
	cin.ignore();
	delete[]s;
	return 0;
}

// Если прога не работает с русскими символами, то в свойствах консоли надо поменять шрифт на 
// Lucida Console