#include "pch.h"
#include "CppUnitTest.h"
#include "../LabTwoLib/LabTwo.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab1
{
	TEST_CLASS(UnitTestLab2)
	{
	public:

		TEST_METHOD(TestComputeExtensionParameters1)
		{
			// arrange
			LabTwoLib::GasolineLogModel input1;
			input1.Date = LabTwoLib::DataYearMonthDay(2020, 3, 10);
			input1.Mark = "Mark1";
			input1.MileageOnTheSensor = 20000;
			input1.PriceOfLiter = 10;
			input1.NumberOfLiters = 10;
			input1.TotalCost = 100;
			LabTwoLib::GasolineLogModel input2;
			input2.Date = LabTwoLib::DataYearMonthDay(2020, 3, 20);
			input2.Mark = "Mark2";
			input2.MileageOnTheSensor = 30000;
			input2.PriceOfLiter = 20;
			input2.NumberOfLiters = 10;
			input2.TotalCost = 200;
			LabTwoLib::GasolineLogModel input3;
			input3.Date = LabTwoLib::DataYearMonthDay(2020, 3, 25);
			input3.Mark = "Mark3";
			input3.MileageOnTheSensor = 40000;
			input3.PriceOfLiter = 30;
			input3.NumberOfLiters = 10;
			input3.TotalCost = 300;
			std::vector<LabTwoLib::GasolineLogModel> inputData = { input1 , input2, input3};

			LabTwoLib::GasolineLogModel ext1;
			ext1.Date = LabTwoLib::DataYearMonthDay(2020, 3, 10);
			ext1.Mark = "Mark1";
			ext1.MileageOnTheSensor = 20000;
			ext1.PriceOfLiter = 10;
			ext1.NumberOfLiters = 10;
			ext1.TotalCost = 100;
			ext1.MileageBetweenGasStations = 20000;
			ext1.MileagePerLiter = 2000;
			ext1.CostOfOneKmRun = 0.005;
			ext1.CostOneDay = -1;
			ext1.ConsumptionTimeOfOneLiter = -1;
			LabTwoLib::GasolineLogModel ext2;
			ext2.Date = LabTwoLib::DataYearMonthDay(2020, 3, 20);
			ext2.Mark = "Mark2";
			ext2.MileageOnTheSensor = 30000;
			ext2.PriceOfLiter = 20;
			ext2.NumberOfLiters = 10;
			ext2.TotalCost = 200;
			ext2.MileageBetweenGasStations = 10000;
			ext2.MileagePerLiter = 1000;
			ext2.CostOfOneKmRun = 0.02;
			ext2.CostOneDay = 20;
			ext2.ConsumptionTimeOfOneLiter = 1;
			LabTwoLib::GasolineLogModel ext3;
			ext3.Date = LabTwoLib::DataYearMonthDay(2020, 3, 25);
			ext3.Mark = "Mark3";
			ext3.MileageOnTheSensor = 40000;
			ext3.PriceOfLiter = 30;
			ext3.NumberOfLiters = 10;
			ext3.TotalCost = 300;
			ext3.MileageBetweenGasStations = 10000; // 40000-30000
			ext3.MileagePerLiter = 1000; // 10000/10
			ext3.CostOfOneKmRun = 0.03; // 300 / 10000
			ext3.CostOneDay = 60; // 300/5 
			ext3.ConsumptionTimeOfOneLiter = 0.5; // 5/10
			std::vector<LabTwoLib::GasolineLogModel> expectedExtParam = { ext1 , ext2 , ext3 };

			//act
			LabTwoLib::LabTwo lab2;
			auto actual = lab2.ComputeExtensionParameters(inputData);

			//asserts
			Assert::AreEqual(expectedExtParam.size(), actual.size());
			for (int i = 0; i < expectedExtParam.size(); i++) {
				Assert::AreEqual(expectedExtParam[i].MileageBetweenGasStations, actual[i].MileageBetweenGasStations);
				Assert::AreEqual(expectedExtParam[i].ConsumptionTimeOfOneLiter, actual[i].ConsumptionTimeOfOneLiter);
				Assert::AreEqual(expectedExtParam[i].CostOfOneKmRun, actual[i].CostOfOneKmRun);
				Assert::AreEqual(expectedExtParam[i].CostOneDay, actual[i].CostOneDay);
				Assert::AreEqual(expectedExtParam[i].MileagePerLiter, actual[i].MileagePerLiter);
			}
			
		}
	};
}
