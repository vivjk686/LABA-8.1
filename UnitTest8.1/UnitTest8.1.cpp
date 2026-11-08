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
        TEST_METHOD(TestIsInBasic)
        {
            Assert::IsTrue(IsInBasic('B'));
            Assert::IsTrue(IsInBasic('A'));
            Assert::IsTrue(IsInBasic('S'));
            Assert::IsTrue(IsInBasic('I'));
            Assert::IsTrue(IsInBasic('C'));

            Assert::IsFalse(IsInBasic('b'));
            Assert::IsFalse(IsInBasic('x'));
            Assert::IsFalse(IsInBasic(' '));
            Assert::IsFalse(IsInBasic('1'));
        }

        TEST_METHOD(TestCountChar)
        {
            const char* str = "BASIC and BASIC";
            Assert::AreEqual(2, CountChar(str, 'B', 0));
            Assert::AreEqual(2, CountChar(str, 'A', 0));
            Assert::AreEqual(2, CountChar(str, 'S', 0));
            Assert::AreEqual(2, CountChar(str, 'I', 0));
            Assert::AreEqual(2, CountChar(str, 'C', 0));
            Assert::AreEqual(0, CountChar(str, 'Z', 0));
        }

        TEST_METHOD(TestCountBasicChars)
        {
            const char* str1 = "BASIC";
            Assert::AreEqual(5, CountBasicChars(str1, 0));

            const char* str2 = "xyz 123";
            Assert::AreEqual(0, CountBasicChars(str2, 0));

            const char* str3 = "BASIC-BASIC!";
            Assert::AreEqual(10, CountBasicChars(str3, 0));
        }

        TEST_METHOD(TestIsBasicWord)
        {
            const char* str = "Learn BASIC now";
            Assert::IsTrue(IsBasicWord(str, 6, 0));
            Assert::IsFalse(IsBasicWord(str, 0, 0));
            Assert::IsFalse(IsBasicWord("BASIS", 0, 0));
        }

        TEST_METHOD(TestChange)
        {
            char* res1 = Change("I like BASIC language");
            Assert::AreEqual("I like Delphi language", res1);
            delete[] res1;

            char* res2 = Change("BASIC and BASIC");
            Assert::AreEqual("Delphi and Delphi", res2);
            delete[] res2;

            char* res3 = Change("No keywords here");
            Assert::AreEqual("No keywords here", res3);
            delete[] res3;

            char* res4 = Change("BASIC");
            Assert::AreEqual("Delphi", res4);
            delete[] res4;
        }
    };
}
