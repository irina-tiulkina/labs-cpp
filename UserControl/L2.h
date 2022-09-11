#pragma once
#include "UserInterfaceClaim.h"
#include <vector>
#include <vector>
#include "../GasolineLogModels/GasolineAverageValue.h"
#include <ctime>

class L2 final:
  public UserInterfaceClaim
{
private:
  const std::string _infoForGetData = "� ����� ����� ����� ���� ��������� �����. ���� ������ ������������� ����� ������ � ������� �������.\
      ������ ������ ��������� ������ � ����� �������:\n\
      ���� (����.��.��), ����� �������, ������ (� ��), ���� �� ���� (� ������), ���������� ������, ����� ���������\n\
      ��������: 2020.03.10 Texaco 24370 37.20 13.5 502.2\n\
      ����� ������ ��������� ������ ������ - ��� ��������";
  const size_t _countInputParameters = 6;
  const size_t _countDateParameters = 3;
  double GetPositiveDoubleValue(std::string str, std::string strException) const;
  DataYearMonthDay GetDate(std::string strData) const;
  std::vector<glmodel> QuickSortByMileage(std::vector<glmodel> array) const;
  int GetCountDayBetweenGasStation(DataYearMonthDay leftDay, DataYearMonthDay rightDay) const;
protected:

public:
  glAverage GetAverageVeluesByGlModels(const std::vector<glmodel> &dlmodels) const;
  std::vector<glAverage> GetAverageGlModelsByMarks(const std::vector<glmodel>& dlmodels) const;
  std::vector<glmodel> ComputeExtensionParameters(const std::vector<glmodel> &models) const;

  /// <summary>
  ///  ��� ������� ������������ ������
  /// </summary>
  /// <param name="inputDataInString">������� ������ ���������� �� �����/�������</param>
  /// <returns>���������� ��������� ������ ���������, �������� ������������ ������, � ���� ������ ��� ������ � �������/����</returns>
  std::string ProgrammFunction(const std::string& inputDataInString) const;
  void StartCycleProgramm() const override
  {
    CycleProgramm
    (
      [&](std::string str) { return ProgrammFunction(str); }, 
      _infoForGetData,
      _infoForGetData + "\n����� ��������� ����������� ���� � ����� ������ ����� $"
    );
  };

  L2() : UserInterfaceClaim{ TaskInfo("������������ ������ 2 (����� ��� ������������� ���.92)", 
    R"S(�� ������, ��������� � ������� ������� �������, �����������
        ������������� ����������� ����������, ������������ ��������, ��
        ��� ��������� ������������ ����������.�������� ������ � ������
        ������� � ��� ����, ����� �������, ��������� �������� �����������
        ����, ���� ������ �����, ������� ������ ������� � ����� ���������.
        ��������� ���������� ������ ��������� �������� �, ����� ����,
        �������� � ���� ����� ����������, ��� ������ ����� ����������, ������
        �� ���� ����, ��������� ������� � ���� ��������, ��������� ������
        �������, ��������� ������ ���, ����� ������������ ������ �������.���
        ��������� ���������� ������� �������� ��� ������ �������� � ���������
        ����� ��������� : �� ��������� ���� � �� ��� ����� ����������.�����
        ����, �������� ������ �� ������ ����� ������� � �����������
        ��������������� ������� ��������.�� ������������� ����� ���������
        �����(�. 92).)S", 
        "")} {};
  ~L2() {};
};

