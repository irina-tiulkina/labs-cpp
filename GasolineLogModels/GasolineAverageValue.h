#pragma once
#include <string>
class GasolineAverageValueModel
{
public:
  std::string Mark = "";
  /// <summary>
  /// ������ ����� ����������
  /// </summary>
  double MileageBetweenGasStations;
  /// <summary>
  /// ���� ����� (� ������)
  /// </summary>
  double PriceOfLiter;
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
};
typedef GasolineAverageValueModel glAverage;