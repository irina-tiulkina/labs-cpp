#pragma once

namespace LabTwoLib {
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

    GasolineAverageValueModel();
  };

}

