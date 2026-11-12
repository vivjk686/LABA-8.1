#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../LABA-8.1/LABA-8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81
{
    TEST_CLASS(UnitTest81)
    {
    public:
        TEST_METHOD(TestCountEachLetter)
        {
            const char* str = "BASIC and BASIC";
            // Кожна окрема функція підраховує відповідну букву зі слова BASIC
            Assert::AreEqual(2, CountB(str, 0));
            Assert::AreEqual(2, CountA(str, 0));
            Assert::AreEqual(2, CountS(str, 0));
            Assert::AreEqual(2, CountI(str, 0));
            Assert::AreEqual(2, CountC(str, 0));
        }

        TEST_METHOD(TestCountZeroOccurrences)
        {
            const char* str = "HELLO WORLD 123";
            Assert::AreEqual(0, CountB(str, 0));
            Assert::AreEqual(0, CountA(str, 0));
            Assert::AreEqual(0, CountS(str, 0));
            Assert::AreEqual(0, CountI(str, 0));
            Assert::AreEqual(0, CountC(str, 0));
        }

        TEST_METHOD(TestChangeNormal)
        {
            char* res1 = Change("I like BASIC language");
            Assert::AreEqual("I like Delphi language", res1);
            delete[] res1;

            char* res2 = Change("BASIC and BASIC");
            Assert::AreEqual("Delphi and Delphi", res2);
            delete[] res2;

            char* res3 = Change("BASIC");
            Assert::AreEqual("Delphi", res3);
            delete[] res3;
        }

        TEST_METHOD(TestChangeShortStrings)
        {
            // Тести на рядки, коротші за 5 символів, щоб гарантувати відсутність виходу за межі пам'яті
            char* res1 = Change("BAS");
            Assert::AreEqual("BAS", res1);
            delete[] res1;

            char* res2 = Change("B");
            Assert::AreEqual("B", res2);
            delete[] res2;

            char* res3 = Change("");
            Assert::AreEqual("", res3);
            delete[] res3;

            char* res4 = Change("No words");
            Assert::AreEqual("No words", res4);
            delete[] res4;
        }
    };
}
