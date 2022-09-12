#pragma once
#include "DataYearMonthDay.h"
#include <string>
class GasolineLogModel
{
public:
  /// <summary>
  /// Дата
  /// </summary>
  DataYearMonthDay Date;
  /// <summary>
  /// Марка бензина
  /// </summary>
  std::string Mark;
  /// <summary>
  /// Пробег (в милях)
  /// </summary>
  double MileageOnTheSensor;
  /// <summary>
  /// Цена литра (в рублях)
  /// </summary>
  double PriceOfLiter;
  /// <summary>
  /// Количество литров
  /// </summary>
  double NumberOfLiters;
  /// <summary>
  /// Общая стоимость
  /// </summary>
  double TotalCost;

  /// <summary>
  /// Пробег между заправками
  /// </summary>
  double MileageBetweenGasStations;
  /// <summary>
  /// Пробег на один литр
  /// </summary>
  double MileagePerLiter;
  /// <summary>
  /// стоимость пробега в один км
  /// </summary>
  double CostOfOneKmRun;
  /// <summary>
  /// Стоимость одного дня
  /// </summary>
  double CostOneDay;
  /// <summary>
  /// Время расходования одного галлона (в днях)
  /// </summary>
  double ConsumptionTimeOfOneLiter;

  GasolineLogModel() {
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
};

