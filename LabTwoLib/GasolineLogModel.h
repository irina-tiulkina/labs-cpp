#pragma once
#include "DataYearMonthDay.h"
#include <string>

namespace LabTwoLib {
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

    GasolineLogModel();
  };

}

