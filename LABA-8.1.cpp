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

// ============================================================================
// 1. Рекурсивна функція: підраховує кількість входжень конкретного символу c у рядок str
// (Методичка В.Г. Григоровича, стор. 61: int Count(const char* s, const char c, int i))
// ============================================================================
int Count(const char* str, char c, int i = 0)
{
    if (str[i] != '\0')
    {
        if (str[i] == c)
            return 1 + Count(str, c, i + 1);
        else
            return Count(str, c, i + 1);
    }
    return 0;
}

// ============================================================================
// 2. Рекурсивна функція: підраховує кількість входжень слова "BASIC" у рядок str
// (Методичка В.Г. Григоровича, стор. 101: int Count(char* str, int i))
// Визначає точну кількість груп для виділення мінімально необхідного обсягу пам'яті
// ============================================================================
int Count(const char* str, int i = 0)
{
    if (strlen(str) < 5)
        return 0;

    if (str[i + 4] != '\0')
    {
        if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' &&
            str[i + 3] == 'I' && str[i + 4] == 'C')
            return 1 + Count(str, i + 5);
        else
            return Count(str, i + 1);
    }
    return 0;
}

// ============================================================================
// 3. Рекурсивна функція заміни: замінює кожне слово "BASIC" на "Delphi"
// (Методичка В.Г. Григоровича, стор. 102: char* Change(char* dest, const char* str, char* t, int i))
// ============================================================================
char* Change(char* dest, const char* str, char* t, int i = 0)
{
    if (str[i] != '\0')
    {
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
        *t = '\0';
        return dest;
    }
}

// ============================================================================
// 4. Функція-обгортка для автоматизованого тестування та зручного виклику
// Виділяє ЩОНАЙМЕНШЕ пам'яті: точна довжина результату + 1 байт на '\0'
// ============================================================================
char* Change(const char* str)
{
    size_t len = strlen(str);
    int count = Count(str, 0);

    // Кожне слово "BASIC" (5 симв.) замінюється на "Delphi" (6 симв.) -> +1 байт на кожне входження
    // Виділяємо рівно стільки пам'яті, скільки потрібно для результату:
    char* dest = new char[len + count * 1 + 1];
    dest[0] = '\0';
    return Change(dest, str, dest, 0);
}

#ifndef UNIT_TESTING
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "\n--- Recursive String Processing (Variant 32) ---" << endl;
    cout << "Initial string: " << str << endl << endl;

    // Пункт 1: Підрахунок входжень кожного символу зі слова "BASIC"
    cout << "1. Occurrences of characters from 'BASIC':" << endl;
    cout << "   'B': " << Count(str, 'B', 0) << endl;
    cout << "   'A': " << Count(str, 'A', 0) << endl;
    cout << "   'S': " << Count(str, 'S', 0) << endl;
    cout << "   'I': " << Count(str, 'I', 0) << endl;
    cout << "   'C': " << Count(str, 'C', 0) << endl << endl;

    // Підрахунок груп "BASIC"
    int basicCount = Count(str, 0);
    cout << "String contained " << basicCount << " groups of 'BASIC'" << endl << endl;

    // Пункт 2: Заміна "BASIC" на "Delphi" (за методичкою, стор. 102)
    // Виділяємо ЩОНАЙМЕНШЕ пам'яті (теоретичний мінімум без надлишку):
    // Початкова довжина: strlen(str)
    // Кожне слово "BASIC" (5) замінюється на "Delphi" (6) -> +1 символ на кожне входження
    // Додаємо 1 байт для завершального нуль-термінатора '\0'
    size_t minMemory = strlen(str) + basicCount * 1 + 1;
    char* dest1 = new char[minMemory];
    dest1[0] = '\0';

    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
#endif
