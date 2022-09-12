#pragma once
class GasolineAverageValueModel
{
public:
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

  GasolineAverageValueModel() {
    MileageBetweenGasStations = 0;
    PriceOfLiter = 0;
    MileagePerLiter = 0;
    CostOfOneKmRun = 0;
    CostOneDay = 0;
    ConsumptionTimeOfOneLiter = 0;
  }
};

