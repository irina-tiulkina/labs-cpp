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
};

typedef GasolineLogModel glmodel;
