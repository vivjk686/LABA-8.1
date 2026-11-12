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
        TEST_METHOD(TestCountChar)
        {
            const char* str = "BASIC and BASIC";
            Assert::AreEqual(2, Count(str, 'B', 0));
            Assert::AreEqual(2, Count(str, 'A', 0));
            Assert::AreEqual(2, Count(str, 'S', 0));
            Assert::AreEqual(2, Count(str, 'I', 0));
            Assert::AreEqual(2, Count(str, 'C', 0));
            Assert::AreEqual(0, Count(str, 'Z', 0));
        }

        TEST_METHOD(TestCountWord)
        {
            Assert::AreEqual(1, Count("Learn BASIC now", 0));
            Assert::AreEqual(2, Count("BASIC and BASIC", 0));
            Assert::AreEqual(0, Count("No keywords here", 0));
            Assert::AreEqual(0, Count("BAS", 0));
        }

        TEST_METHOD(TestChangeDirectWithMinimalMemory)
        {
            const char* str = "BASIC and BASIC";
            int count = Count(str, 0);
            size_t minSize = strlen(str) + count * 1 + 1;
            char* dest1 = new char[minSize];
            dest1[0] = '\0';
            char* dest2 = Change(dest1, str, dest1, 0);

            Assert::AreEqual("Delphi and Delphi", dest1);
            Assert::AreEqual("Delphi and Delphi", dest2);
            delete[] dest1;
        }

        TEST_METHOD(TestChangeWrapper)
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
