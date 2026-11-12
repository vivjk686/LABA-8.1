// LABA-8.1.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 32 (Рекурсивний спосіб)

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring>

using namespace std;

// 1.1. Рекурсивна функція підрахунку кількості конкретного символу c
int Count(const char* str, const char c, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == c)
            return 1 + Count(str, c, i + 1);
        else
            return Count(str, c, i + 1);
    }
    else
        return 0;
}

// 1.2. Рекурсивна функція підрахунку сумарної кількості всіх символів зі слова "BASIC"
// Перевіряє входження кожної літери: 'B', 'A', 'S', 'I', 'C'
int Count(const char* str, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == 'B' || str[i] == 'A' || str[i] == 'S' || str[i] == 'I' || str[i] == 'C')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }
    else
        return 0;
}

// 2. Рекурсивна функція заміни слова "BASIC" на "Delphi"
// Безпечна робота з пам'яттю:
// Умова if (str[i + 4] != 0) гарантує, що індекси від i до i+4 існують
// і ми не виходимо за межі рядка.
char* Change(char* dest, const char* str, char* t, int i = 0)
{
    if (str[i + 4] != 0)
    {
        // Перевіряємо всі 5 літер слова "BASIC"
        if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' &&
            str[i + 3] == 'I' && str[i + 4] == 'C')
        {
            strcat(t, "Delphi");
            return Change(dest, str, t + 6, i + 5);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        // Якщо до кінця рядка залишилося менше ніж 5 символів,
        // слово "BASIC" поміститися вже не може.
        // Докопіюємо залишкові символи до кінця рядка ('\0').
        if (str[i] != '\0')
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
        else
        {
            *t = '\0';
            return dest;
        }
    }
}

// Зручна обгортка з виділенням пам'яті за формулою з методички (стор. 100):
// (int)(len * 6.0 / 5 + 1) + 1
// де 6.0 - довжина нового слова "Delphi", 5 - довжина старого слова "BASIC"
char* Change(const char* str)
{
    size_t len = strlen(str);
    char* dest = new char[(int)(len * 6.0 / 5 + 1) + 1];
    dest[0] = '\0';
    return Change(dest, str, dest, 0);
}

#ifndef UNIT_TESTING
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "\n--- Lab 8.1 (Recursive) Variant 32 ---" << endl;
    cout << "Initial string: " << str << endl;

    // 1. Підрахунок кількості кожного символу зі слова "BASIC"
    cout << "\n1. Occurrences of characters from 'BASIC':" << endl;
    cout << "   'B': " << Count(str, 'B', 0) << endl;
    cout << "   'A': " << Count(str, 'A', 0) << endl;
    cout << "   'S': " << Count(str, 'S', 0) << endl;
    cout << "   'I': " << Count(str, 'I', 0) << endl;
    cout << "   'C': " << Count(str, 'C', 0) << endl;
    cout << "   Total characters ('B','A','S','I','C'): " << Count(str, 0) << endl;

    // 2. Заміна "BASIC" на "Delphi"
    // Виділення динамічної пам'яті за формулою методички:
    // довжина "BASIC" = 5, довжина "Delphi" = 6 -> коефіцієнт 6.0 / 5
    size_t len = strlen(str);
    char* dest1 = new char[(int)(len * 6.0 / 5 + 1) + 1];
    dest1[0] = '\0';

    char* dest2 = Change(dest1, str, dest1, 0);

    cout << "\n2. Modified string (param) : " << dest1 << endl;
    cout << "   Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
#endif
