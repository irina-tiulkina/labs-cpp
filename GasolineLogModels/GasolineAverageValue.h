#pragma once
#include <string>
class GasolineAverageValueModel
{
public:
  std::string Mark = "";
  /// <summary>
  /// Пробег между заправками
  /// </summary>
  double MileageBetweenGasStations;
  /// <summary>
  /// Цена литра (в рублях)
  /// </summary>
  double PriceOfLiter;
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
typedef GasolineAverageValueModel glAverage;