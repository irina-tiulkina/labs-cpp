#pragma once
class GasolineAverageValueModel
{
public:
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

  GasolineAverageValueModel() {
    MileageBetweenGasStations = 0;
    PriceOfLiter = 0;
    MileagePerLiter = 0;
    CostOfOneKmRun = 0;
    CostOneDay = 0;
    ConsumptionTimeOfOneLiter = 0;
  }
};

