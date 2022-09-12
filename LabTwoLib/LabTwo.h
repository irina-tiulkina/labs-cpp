#pragma once
#include <string>
#include "GasolineAverageValue.h"
#include <vector>
#include "../UserControlMainLib/UserInterfaceClaim.h"
#include "DataYearMonthDay.h"
#include "GasolineLogModel.h"
#include <map>
#include "../ConsoleWorkLib/StringTransform.h"

namespace LabTwoLib {

  class LabTwo final :
    public UserControlMainLib::UserInterfaceClaim
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
    std::vector<GasolineLogModel> QuickSortByMileage(std::vector<GasolineLogModel>& array) const;
    int GetCountDayBetweenGasStation(DataYearMonthDay leftDay, DataYearMonthDay rightDay) const;
  protected:

  public:
    GasolineAverageValueModel GetAverageVeluesByGlModels(std::vector<GasolineLogModel>& dlmodels) const;
    std::map<std::string, std::vector<GasolineAverageValueModel>>  GetAverageGlModelsByMarks(std::vector<GasolineLogModel>& dlmodels) const;
    std::vector<GasolineLogModel> ComputeExtensionParameters(std::vector<GasolineLogModel>& models) const;

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

    LabTwo() : UserControlMainLib::UserInterfaceClaim{ UserControlMainLib::TaskInfo("������������ ������ 2 (����� ��� ������������� ���.92)",
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
        "") } {};
    ~LabTwo() {};
  };
}

