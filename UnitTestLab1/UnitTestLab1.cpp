#include "pch.h"
#include "CppUnitTest.h"
#include "../LabOneLib/LabOne.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab1
{
	TEST_CLASS(UnitTestLab1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// arrange
			std::string inputData = "aaaa bbb ccc";
			std::string expected = "abc abc abc a";
			
			//act
			LabOne lab1;
			std::string actual = lab1.ProgrammFunction(inputData);

			//asserts
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod2)
		{
			// arrange
			std::string inputData = "aaaa";
			std::string expected = "a a a a";

			//act
			LabOne lab1;
			std::string actual = lab1.ProgrammFunction(inputData);

			//asserts
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod3)
		{
			// arrange
			std::string inputData = "a";
			std::string expected = "a";

			//act
			LabOne lab1;
			std::string actual = lab1.ProgrammFunction(inputData);

			//asserts
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod4)
		{
			// arrange
			std::string inputData = "aaaaaaaaaaaaaaaaaa a";
			std::string expected = "aa a a a a a a a a a a a a a a a a a";

			//act
			LabOne lab1;
			std::string actual = lab1.ProgrammFunction(inputData);

			//asserts
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestMethod5)
		{
			// arrange
			std::string inputData = "aaa aaaa aa a";
			std::string expected = "aaaa aaa aa a";

			//act
			LabOne lab1;
			std::string actual = lab1.ProgrammFunction(inputData);

			//asserts
			Assert::AreEqual(expected, actual);
		}
	};
}
