#pragma once
#include <string>

struct DataYearMonthDay {
  int Day;  // day of month from 1 to 31
  int Month;   // month of year from 1 to 12
  int Year;  // year since 1900

  DataYearMonthDay(int year, int month, int day) {
    Year = year;
    Month = month;
    Day = day;
  }

  DataYearMonthDay() {

  }
};

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
};

typedef GasolineLogModel glmodel;
