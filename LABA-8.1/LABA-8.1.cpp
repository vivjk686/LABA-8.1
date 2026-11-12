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

// 1. Окремі рекурсивні функції підрахунку для кожної літери зі слова "BASIC":

// 1.1. Підрахунок кількості літер 'B'
int CountB(const char* str, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == 'B')
            return 1 + CountB(str, i + 1);
        else
            return CountB(str, i + 1);
    }
    else
        return 0;
}

// 1.2. Підрахунок кількості літер 'A'
int CountA(const char* str, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == 'A')
            return 1 + CountA(str, i + 1);
        else
            return CountA(str, i + 1);
    }
    else
        return 0;
}

// 1.3. Підрахунок кількості літер 'S'
int CountS(const char* str, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == 'S')
            return 1 + CountS(str, i + 1);
        else
            return CountS(str, i + 1);
    }
    else
        return 0;
}

// 1.4. Підрахунок кількості літер 'I'
int CountI(const char* str, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == 'I')
            return 1 + CountI(str, i + 1);
        else
            return CountI(str, i + 1);
    }
    else
        return 0;
}

// 1.5. Підрахунок кількості літер 'C'
int CountC(const char* str, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == 'C')
            return 1 + CountC(str, i + 1);
        else
            return CountC(str, i + 1);
    }
    else
        return 0;
}

// 2. Рекурсивна функція заміни слова "BASIC" на "Delphi"
// Безпечна робота з пам'яттю за зразком методички (стор. 102):
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

    // 1. Окремий підрахунок для КОЖНОЇ літери зі слова "BASIC":
    int countB = CountB(str, 0);
    int countA = CountA(str, 0);
    int countS = CountS(str, 0);
    int countI = CountI(str, 0);
    int countC = CountC(str, 0);
    int total = countB + countA + countS + countI + countC;

    cout << "\n1. Occurrences of each character from 'BASIC':" << endl;
    cout << "   'B': " << countB << endl;
    cout << "   'A': " << countA << endl;
    cout << "   'S': " << countS << endl;
    cout << "   'I': " << countI << endl;
    cout << "   'C': " << countC << endl;
    cout << "   Total ('B','A','S','I','C'): " << total << endl;

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
