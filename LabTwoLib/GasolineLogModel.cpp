#include "pch.h"
#include "GasolineLogModel.h"

LabTwoLib::GasolineLogModel::GasolineLogModel()
{
  Date = DataYearMonthDay();
  Mark = "";
  MileageOnTheSensor = 0;
  PriceOfLiter = 0;
  NumberOfLiters = 0;
  TotalCost = 0;
  MileageBetweenGasStations = 0;
  MileagePerLiter = 0;
  CostOfOneKmRun = 0;
  CostOneDay = 0;
  ConsumptionTimeOfOneLiter = 0;
};