#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.4/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			map<int, Perekazy> perekazI;
			perekazI[0].r_platnyka = "00002";
			perekazI[0].r_oderzhyvacha = "03034";
			perekazI[0].pererah_sum = 900;
			string s = "00002", n = "03034";
			double sum = 900;
			Assert::AreEqual(perekazI[0].r_platnyka, s);
			Assert::AreEqual(perekazI[0].r_oderzhyvacha, n);
			Assert::AreEqual(perekazI[0].pererah_sum, sum);

			Assert::IsTrue(display(perekazI, s));
		}		
	};
}
