// UnitTest_TransferCalc.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include "DimParam.h"



TEST(DimParam, noUnitsSet)
{
	try
	{
		Dimensions::DimFloat testFloat;
		FAIL() << "Expected error : no units set";
	}
	catch (Dimensions::WrongUnitsException const & error)
	{
		EXPECT_EQ(error.getType(), Dimensions::NoUnits);
	}
}

TEST(DimParam, UnitsMismatch)
{
	try
	{
		Dimensions::DimFloat testFloat(Dimensions::kg);
		testFloat = Dimensions::DimFloat(10.5, Dimensions::sec);
		FAIL() << "Expected error : Units mismatch";
	}
	catch (Dimensions::WrongUnitsException const & error)
	{
		EXPECT_EQ(error.getType(), Dimensions::NoMatchingUnits);
	}
}

TEST(DimParam, Addition)
{

	Dimensions::DimFloat testFloat(10, Dimensions::kg);
	Dimensions::DimFloat testFloat2(10, Dimensions::kg);
	auto testFloat3 = testFloat + testFloat2;
	EXPECT_TRUE(testFloat3 == float(20));

	try
	{
		Dimensions::DimFloat testFloat(10, Dimensions::kg);
		Dimensions::DimFloat testFloat2(10, Dimensions::sec);
		auto testFloat3 = testFloat + testFloat2;
		FAIL() << "Expected error : Units mismatch";
	}
	catch (Dimensions::WrongUnitsException const & error)
	{
		EXPECT_EQ(error.getType(), Dimensions::NoMatchingUnits);
	}
}

TEST(DimParam, Substraction)
{

	Dimensions::DimFloat testFloat(10, Dimensions::kg);
	Dimensions::DimFloat testFloat2(10, Dimensions::kg);
	auto testFloat3 = testFloat - testFloat2;
	EXPECT_TRUE(testFloat3 == float(0));

	try
	{
		Dimensions::DimFloat testFloat(10, Dimensions::kg);
		Dimensions::DimFloat testFloat2(10, Dimensions::sec);
		auto testFloat3 = testFloat - testFloat2;
		FAIL() << "Expected error : Units mismatch";
	}
	catch (Dimensions::WrongUnitsException const & error)
	{
		EXPECT_EQ(error.getType(), Dimensions::NoMatchingUnits);
	}
}


TEST(DimParam, Multiplication)
{

	Dimensions::DimFloat testFloat(10, Dimensions::kg);
	Dimensions::DimFloat testFloat2(10, Dimensions::sec);
	auto testFloat3 = testFloat * testFloat2;

	EXPECT_EQ(testFloat3.getUnits(), Dimensions::rational);
	EXPECT_TRUE(testFloat3 == float(100));

	testFloat3.setUnits(Dimensions::kg);
	EXPECT_EQ(testFloat3.getUnits(), Dimensions::kg);
}

TEST(DimParam, Division)
{

	Dimensions::DimFloat testFloat(10, Dimensions::kg);
	Dimensions::DimFloat testFloat2(10, Dimensions::sec);
	auto testFloat3 = testFloat / testFloat2;

	EXPECT_EQ(testFloat3.getUnits(), Dimensions::rational);
	EXPECT_TRUE(testFloat3 == float(1));

	testFloat3.setUnits(Dimensions::kg);
	EXPECT_EQ(testFloat3.getUnits(), Dimensions::kg);

	try
	{
		auto testFloat4 = testFloat / 0;
	}
	catch (Dimensions::WrongUnitsException const & error)
	{
		EXPECT_EQ(error.getType(), Dimensions::divisionBy0);
	}
}