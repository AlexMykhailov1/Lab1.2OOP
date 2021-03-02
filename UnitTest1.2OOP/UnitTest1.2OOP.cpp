#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1.2OOP/BigInt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12OOP
{
	TEST_CLASS(UnitTest12OOP)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			BigInt num;
			num.SetSize(1);
			Assert::AreEqual(1,num.GetSize());
		}
	};
}
