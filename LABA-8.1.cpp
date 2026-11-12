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
#include <iomanip>

using namespace std;

// 1. Допоміжна рекурсивна функція: перевіряє, чи належить символ c слову "BASIC"
bool IsInBasic(char c, const char* basic = "BASIC", int j = 0)
{
    if (basic[j] == '\0')
        return false;
    if (c == basic[j])
        return true;
    return IsInBasic(c, basic, j + 1);
}

// 2. Рекурсивна функція: підраховує кількість входжень конкретного символу c у рядок str
int CountChar(const char* str, char c, int i = 0)
{
    if (str[i] == '\0')
        return 0;
    if (str[i] == c)
        return 1 + CountChar(str, c, i + 1);
    else
        return CountChar(str, c, i + 1);
}

// 3. Рекурсивна функція: підраховує сумарну кількість входжень будь-якого символу з "BASIC"
int CountBasicChars(const char* str, int i = 0)
{
    if (str[i] == '\0')
        return 0;
    if (IsInBasic(str[i], "BASIC", 0))
        return 1 + CountBasicChars(str, i + 1);
    else
        return CountBasicChars(str, i + 1);
}

// 4. Допоміжна рекурсивна функція: перевіряє, чи збігаються 5 символів, починаючи з str[i], зі словом "BASIC"
bool IsBasicWord(const char* str, int i, int j = 0)
{
    if (j == 5)
        return true;
    if (str[i + j] == '\0')
        return false;
    if (str[i + j] != "BASIC"[j])
        return false;
    return IsBasicWord(str, i, j + 1);
}

// 5. Основна рекурсивна функція заміни: замінює "BASIC" на "Delphi"
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != '\0')
    {
        if (IsBasicWord(str, i, 0))
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
        *t = '\0';
        return dest;
    }
}

// 6. Обгортка для зручного виклику та виділення динамічної пам'яті
char* Change(const char* str)
{
    size_t len = strlen(str);
    // Виділяємо достатньо пам'яті (слово Delphi довше за BASIC на 1 символ)
    char* dest = new char[len * 2 + 1];
    dest[0] = '\0';
    return Change(dest, str, dest, 0);
}

#ifndef UNIT_TESTING
int main()
{
    char str[201];
    cout << "Enter string:" << endl;
    cin.getline(str, 200);

    cout << "\n--- Recursive String Processing (Variant 32) ---" << endl;
    cout << "Initial string: " << str << endl << endl;

    // Пункт 1: Підрахунок входжень символів з "BASIC"
    cout << "1. Occurrences of characters from 'BASIC':" << endl;
    cout << "   'B': " << CountChar(str, 'B', 0) << endl;
    cout << "   'A': " << CountChar(str, 'A', 0) << endl;
    cout << "   'S': " << CountChar(str, 'S', 0) << endl;
    cout << "   'I': " << CountChar(str, 'I', 0) << endl;
    cout << "   'C': " << CountChar(str, 'C', 0) << endl;
    cout << "   Total 'BASIC' characters: " << CountBasicChars(str, 0) << endl << endl;

    // Пункт 2: Заміна "BASIC" на "Delphi"
    char* modified = Change(str);
    cout << "2. String after replacing 'BASIC' with 'Delphi':" << endl;
    cout << "   " << modified << endl;

    delete[] modified;
    return 0;
}
#endif
