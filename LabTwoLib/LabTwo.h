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
    const std::string _infoForGetData = 
      R"S(
      � ����� ����� ����� ���� ��������� �����. ���� ������ ������������� ����� ������ � ������� �������.
      ������ ������ ��������� ������ � ����� �������:
      ���� (����.��.��), ����� �������, ������ (� ��), ���� �� ���� (� ������), ���������� ������, ����� ���������
      ��������: 2020.03.10 Texaco 24370 37.20 13.5 502.2
      ����� ������ ��������� ������ ������ - ��� ��������)S";
    const size_t _countInputParameters = 6;
    const size_t _countDateParameters = 3;
    double GetPositiveDoubleValue(std::string str, std::string strException) const;
    DataYearMonthDay GetDate(std::string strData) const;
    std::vector<GasolineLogModel> QuickSortByMileage(std::vector<GasolineLogModel>& array) const;
    int GetCountDayBetweenGasStation(DataYearMonthDay leftDay, DataYearMonthDay rightDay) const;
    std::string ToStringFromDouble(double value, int countValAfterPoint) const;
    std::string GetStrRowForTable(const std::vector<std::string>& items, int sizeItemHeader) const;
    std::vector<std::string> GetStrVectorFromGasolineModel(GasolineLogModel model) const;
    std::vector<std::string> GetStrVectorFromGasolineAverageValueModel(const std::string &mark, GasolineAverageValueModel averageValues) const;
  protected:

  public:
    GasolineAverageValueModel GetAverageValuesByGlModels(const std::vector<GasolineLogModel>& dlmodels) const;
    std::map<std::string, GasolineAverageValueModel>  GetAverageGlModelsByMarks(const std::vector<GasolineLogModel>& dlmodels) const;
    std::vector<GasolineLogModel> ComputeExtensionParameters(const std::vector<GasolineLogModel>& models) const;

    /// <summary>
    ///  ��� ������� ������������ ������
    /// </summary>
    /// <param name="inputDataInString">������� ������ ���������� �� �����/�������</param>
    /// <returns>���������� ��������� ������ ���������, �������� ������������ ������, � ���� ������ ��� ������ � �������/����</returns>
    std::string ProgrammFunction(const std::string& inputDataInString) const;
    void StartCycleProgramm() const override;

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
  };
}

