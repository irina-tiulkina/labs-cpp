#pragma once
#include "DataYearMonthDay.h"
#include <string>
class GasolineLogModel
{
public:
  /// <summary>
  /// ����
  /// </summary>
  DataYearMonthDay Date;
  /// <summary>
  /// ����� �������
  /// </summary>
  std::string Mark;
  /// <summary>
  /// ������ (� �����)
  /// </summary>
  double MileageOnTheSensor;
  /// <summary>
  /// ���� ����� (� ������)
  /// </summary>
  double PriceOfLiter;
  /// <summary>
  /// ���������� ������
  /// </summary>
  double NumberOfLiters;
  /// <summary>
  /// ����� ���������
  /// </summary>
  double TotalCost;

  /// <summary>
  /// ������ ����� ����������
  /// </summary>
  double MileageBetweenGasStations;
  /// <summary>
  /// ������ �� ���� ����
  /// </summary>
  double MileagePerLiter;
  /// <summary>
  /// ��������� ������� � ���� ��
  /// </summary>
  double CostOfOneKmRun;
  /// <summary>
  /// ��������� ������ ���
  /// </summary>
  double CostOneDay;
  /// <summary>
  /// ����� ������������ ������ ������� (� ����)
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

