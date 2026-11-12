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
        TEST_METHOD(TestCountIndividualChars)
        {
            const char* str = "BASIC and BASIC";
            Assert::AreEqual(2, Count(str, 'B', 0));
            Assert::AreEqual(2, Count(str, 'A', 0));
            Assert::AreEqual(2, Count(str, 'S', 0));
            Assert::AreEqual(2, Count(str, 'I', 0));
            Assert::AreEqual(2, Count(str, 'C', 0));
            Assert::AreEqual(0, Count(str, 'Z', 0));
        }

        TEST_METHOD(TestCountTotalBasicChars)
        {
            const char* str1 = "BASIC";
            Assert::AreEqual(5, Count(str1, 0));

            const char* str2 = "xyz 123";
            Assert::AreEqual(0, Count(str2, 0));

            const char* str3 = "BASIC-BASIC!";
            Assert::AreEqual(10, Count(str3, 0));
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
            // Тести на короткі рядки (менші за 5 символів), щоб гарантувати відсутність виходу за межі пам'яті
            char* res1 = Change("BAS");
            Assert::AreEqual("BAS", res1);
            delete[] res1;

            char* res2 = Change("B");
            Assert::AreEqual("B", res2);
            delete[] res2;

            char* res3 = Change("");
            Assert::AreEqual("", res3);
            delete[] res3;

            char* res4 = Change("No words here");
            Assert::AreEqual("No words here", res4);
            delete[] res4;
        }
    };
}
