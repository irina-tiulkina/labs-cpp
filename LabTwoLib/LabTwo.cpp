#include "pch.h"
#include "LabTwo.h"

namespace LabTwoLib {
  double LabTwo::GetPositiveDoubleValue(std::string str, std::string strException) const
  {
    std::string dataStr = GetTextInfosLib::StringTransform::Replace(str, ',', ".");
    double value;
    try {
      value = std::stod(dataStr);
      if (value < 1) {
        throw std::exception();
      }
    }
    catch (...) {
      throw std::exception(strException.c_str());
    }
    return 0.0;
  }

  DataYearMonthDay LabTwo::GetDate(std::string strData) const
  {
    int countCharYear = 4;
    int countCharMD = 2;
    std::string dataStr = GetTextInfosLib::StringTransform::Replace(strData, ',', ".");
    dataStr = GetTextInfosLib::StringTransform::Replace(dataStr, '/', ".");
    dataStr = GetTextInfosLib::StringTransform::Replace(dataStr, '\\', ".");
    std::vector<std::string> dateVector = GetTextInfosLib::StringTransform::Split(dataStr, '.');
    if (
      dateVector.size() != _countDateParameters ||
      dateVector[0].size() != countCharYear ||
      dateVector[1].size() != countCharMD ||
      dateVector[2].size() != countCharMD
      )
    {
      std::string strEx = "� ���� " + strData + " ������. ��������� ������������ ����� (����.��.��)";
      throw std::exception(strEx.c_str());
    }
    DataYearMonthDay dataFromStr;
    try {
      dataFromStr.Year = std::stoi(dateVector[0]);
      dataFromStr.Month = std::stoi(dateVector[1]);
      dataFromStr.Day = std::stoi(dateVector[2]);
    }
    catch (std::invalid_argument) {
      std::string strEx = "� ���� " + strData + " ������. ��������� ������������ ����� (����.��.��)";
      throw std::exception(strEx.c_str());
    }
    catch (std::out_of_range) {
      std::string strEx = "� ���� " + strData + " ������. ��������� ������������ ����� (����.��.��)";
      throw std::exception(strEx.c_str());
    }

    if (dataFromStr.Year < 1) {
      std::string strEx = "� ���� " + strData + " ������. ��� �� ����� ���� �������������";
      throw std::exception(strEx.c_str());
    }

    if (dataFromStr.Day < 1 || dataFromStr.Day > 31) {
      std::string strEx = "� ���� " + strData + " ������. ���� ������ ���� � ��������� �� 1 �� 31";
      throw std::exception(strEx.c_str());
    }

    if (dataFromStr.Month < 1 || dataFromStr.Month > 12) {
      std::string strEx = "� ���� " + strData + " ������. ����� ������ ���� � ��������� �� 1 �� 12";
      throw std::exception(strEx.c_str());
    }
    return dataFromStr;
  }

  std::vector<GasolineLogModel> LabTwo::QuickSortByMileage(std::vector<GasolineLogModel>& array) const {
    if (array.size() < 2) {
      return array;
    }
    else {
      int pivotIndx = (array.size() - 1) / 2;
      double pivot = array[pivotIndx].MileageOnTheSensor;
      std::vector<GasolineLogModel> leftArray;
      std::vector<GasolineLogModel> rightArray;
      for (int i = 0; i < array.size(); i++) {
        if (i == pivotIndx)
          continue;
        if (array[i].MileageOnTheSensor > pivot) {
          rightArray.push_back(array[i]);
        }
        else {
          leftArray.push_back(array[i]);
        }
      }
      std::vector<GasolineLogModel> result = QuickSortByMileage(leftArray);
      std::vector<GasolineLogModel> resultRightArray = QuickSortByMileage(rightArray);
      result.push_back(array[pivotIndx]);
      for (int i = 0; i < resultRightArray.size(); i++) {
        result.push_back(resultRightArray[i]);
      }
      return result;
    }
  }

  int LabTwo::GetCountDayBetweenGasStation(DataYearMonthDay leftDay, DataYearMonthDay rightDay) const
  {
    struct tm a = { 0,0,0,leftDay.Day,leftDay.Month,leftDay.Year }; /* June 24, 2004 */
    struct tm b = { 0,0,0,rightDay.Day,rightDay.Month,rightDay.Year }; /* July 5, 2004 */
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);

    int difference = std::difftime(y, x) / (60 * 60 * 24);
    return difference;
  }

  GasolineAverageValueModel LabTwo::GetAverageVeluesByGlModels(std::vector<GasolineLogModel>& dlmodels) const
  {
    GasolineAverageValueModel average;
    average.ConsumptionTimeOfOneLiter = 0;
    average.CostOfOneKmRun = 0;
    average.CostOneDay = 0;
    average.MileageBetweenGasStations = 0;
    average.MileagePerLiter = 0;
    average.PriceOfLiter = 0;
    for (int i = 0; i < dlmodels.size(); i++) {
      average.MileageBetweenGasStations += dlmodels[i].MileageBetweenGasStations;
      average.CostOfOneKmRun += dlmodels[i].CostOfOneKmRun;
      average.MileagePerLiter += dlmodels[i].MileagePerLiter;
      average.PriceOfLiter += dlmodels[i].PriceOfLiter;

      if (i != 0) {
        average.ConsumptionTimeOfOneLiter += dlmodels[i].ConsumptionTimeOfOneLiter;
        average.CostOneDay += dlmodels[i].CostOneDay;
      }
    }

    average.MileageBetweenGasStations /= dlmodels.size();
    average.CostOfOneKmRun /= dlmodels.size();
    average.MileagePerLiter /= dlmodels.size();
    average.PriceOfLiter /= dlmodels.size();
    average.ConsumptionTimeOfOneLiter /= dlmodels.size() - 1;
    average.CostOneDay /= dlmodels.size() - 1;

    return average;
  }

  std::map<std::string, std::vector<GasolineAverageValueModel>> LabTwo::GetAverageGlModelsByMarks(std::vector<GasolineLogModel>& dlmodels) const
  {
    return std::map<std::string, std::vector<GasolineAverageValueModel>>();
  }

  std::vector<GasolineLogModel> LabTwo::ComputeExtensionParameters(std::vector<GasolineLogModel>& models) const
  {
    // ��������� �� �������
    std::vector<GasolineLogModel> purchasesModel = models;
    purchasesModel = QuickSortByMileage(purchasesModel);

    // ������ ��� ������ ��������
    purchasesModel[0].MileageBetweenGasStations = purchasesModel[0].MileageOnTheSensor;
    purchasesModel[0].MileagePerLiter = purchasesModel[0].MileageBetweenGasStations / purchasesModel[0].NumberOfLiters;
    purchasesModel[0].CostOfOneKmRun = (purchasesModel[0].NumberOfLiters / purchasesModel[0].MileageBetweenGasStations) * purchasesModel[0].PriceOfLiter;
    purchasesModel[0].CostOneDay = -1;
    purchasesModel[0].ConsumptionTimeOfOneLiter = -1;

    for (int i = 1; i < purchasesModel.size(); i++) {

      int countDayBetweenStation = GetCountDayBetweenGasStation(purchasesModel[i - 1].Date, purchasesModel[i].Date);

      purchasesModel[i].MileageBetweenGasStations = purchasesModel[i].MileageOnTheSensor - purchasesModel[i - 1].MileageOnTheSensor;
      // ���������� �� / ���-�� ������
      purchasesModel[i].MileagePerLiter = purchasesModel[i].MileageBetweenGasStations / purchasesModel[i].NumberOfLiters;
      // ���-�� ������ �� �� * ��������� ����� | ����� / ���������� ��
      purchasesModel[i].CostOfOneKmRun = (purchasesModel[i].NumberOfLiters / purchasesModel[i].MileageBetweenGasStations) * purchasesModel[i].PriceOfLiter;
      // ���-�� ������ �� ���� * ��������� ����� | ����� / ���-�� ����
      purchasesModel[i].CostOneDay = purchasesModel[i].NumberOfLiters / countDayBetweenStation * purchasesModel[i].PriceOfLiter;
      // ���-�� ���� / ���-�� ������
      purchasesModel[i].ConsumptionTimeOfOneLiter = countDayBetweenStation / purchasesModel[i].NumberOfLiters;
    }
    return purchasesModel;
  }

  std::string LabTwo::ProgrammFunction(const std::string& inputDataInString) const
  {
    // ------- �������� ������� ������ � �������������� ������ � ������ --------
    std::vector<std::string> purchases = GetTextInfosLib::StringTransform::Split(inputDataInString, '\n');
    std::vector<GasolineLogModel> purchasesModel;
    for (int i = 0; i < purchases.size(); i++) {
      std::vector<std::string> purchase = GetTextInfosLib::StringTransform::Split(purchases[i], ' ');
      if (purchase.size() != _countInputParameters)
      {
        std::string exStr = "���������� ���������� � ������ " + std::to_string(i + 1) + "�� �����" + std::to_string(_countInputParameters);
        throw std::exception(exStr.c_str());
      }

      GasolineLogModel gl;

      try {
        gl.Date = GetDate(purchase[0]);
        gl.Mark = purchase[1];
        gl.MileageOnTheSensor = GetPositiveDoubleValue(purchase[2], "��������� ������ �������");
        gl.PriceOfLiter = GetPositiveDoubleValue(purchase[3], "��������� ������ ���� �������");
        gl.NumberOfLiters = GetPositiveDoubleValue(purchase[4], "��������� ������ ���������� ��������");
        gl.TotalCost = GetPositiveDoubleValue(purchase[5], "��������� ������ �����");
      }
      catch (std::exception ex) {
        std::string exStr = "� ������" + std::to_string(i) + " ������. " + ex.what();
        throw std::exception(exStr.c_str());
      }
      purchasesModel.push_back(gl);
    }

    // ----- ���������� ���������� ------

    purchasesModel = ComputeExtensionParameters(purchasesModel);
    GasolineAverageValueModel averageValues = GetAverageVeluesByGlModels(purchasesModel);
    std::map<std::string, std::vector<GasolineAverageValueModel>> averageByMarks = GetAverageGlModelsByMarks(purchasesModel);

    // ------- ������������ ����������� � ��������� ���������� --------
    std::vector<std::string> resultArray;
    resultArray.push_back("����              | ");
    resultArray.push_back("����� �������     | ");
    resultArray.push_back("������(��)        | ");
    resultArray.push_back("���� �����(���)   | ");
    resultArray.push_back("���-�� ������     | ");
    resultArray.push_back("�����             | ");
    resultArray.push_back("����������        | ");
    resultArray.push_back("������ �� ����    | ");
    resultArray.push_back("����/��           | ");
    resultArray.push_back("����/����         | ");
    resultArray.push_back("������ ����� (���)| ");

    for (int i = 0; i < purchasesModel.size(); i++) {
      GasolineLogModel model = purchasesModel[i];

      std::string date = std::to_string(model.Date.Year) + "." + std::to_string(model.Date.Month) + "." + std::to_string(model.Date.Day);
      date.resize(10, ' ');
      resultArray[0] += date + "|";

      std::string mark = model.Mark;
      mark.resize(10, ' ');
      resultArray[1] += mark + "|";

      std::string mileageSensor = std::to_string(model.MileageOnTheSensor);
      mileageSensor.resize(10, ' ');
      resultArray[2] += mileageSensor + "|";

      std::string coastLiter = std::to_string(model.PriceOfLiter);
      coastLiter.resize(10, ' ');
      resultArray[3] += coastLiter + "|";

      std::string conutliters = std::to_string(model.NumberOfLiters);
      conutliters.resize(10, ' ');
      resultArray[4] += conutliters + "|";

      std::string totalCost = std::to_string(model.TotalCost);
      totalCost.resize(10, ' ');
      resultArray[5] += totalCost + "|";

      std::string milFact = std::to_string(model.MileageBetweenGasStations);
      milFact.resize(10, ' ');
      resultArray[6] += milFact + "|";

      std::string milL = std::to_string(model.MileagePerLiter);
      milL.resize(10, ' ');
      resultArray[7] += milL + "|";

      std::string costKm = std::to_string(model.CostOfOneKmRun);
      costKm.resize(10, ' ');
      resultArray[8] += costKm + "|";

      std::string costDay = std::to_string(model.CostOneDay);
      costDay.resize(10, ' ');
      resultArray[9] += costDay + "|";

      std::string timeLiter = std::to_string(model.ConsumptionTimeOfOneLiter);
      timeLiter.resize(10, ' ');
      resultArray[10] += timeLiter + "|";

      if (i == purchasesModel.size() - 1)
      {
        resultArray[0] += "\n";
        resultArray[1] += "\n";
        resultArray[2] += "\n";
        resultArray[3] += "\n";
        resultArray[4] += "\n";
        resultArray[5] += "\n";
        resultArray[6] += "\n";
        resultArray[7] += "\n";
        resultArray[8] += "\n";
        resultArray[9] += "\n";
        resultArray[10] += "\n";
      }
    }
    resultArray.push_back("\n*-1 �������� ���� ������������ ������ ��� �������\n");
    resultArray.push_back("\n�� ��� ����� ����������: \n");
    resultArray.push_back("����������        | " + std::to_string(averageValues.MileageBetweenGasStations) + " \n");
    resultArray.push_back("���� ������ ����� | " + std::to_string(averageValues.PriceOfLiter) + " \n");
    resultArray.push_back("������ �� ����    | " + std::to_string(averageValues.MileagePerLiter) + " \n");
    resultArray.push_back("����/��           | " + std::to_string(averageValues.CostOfOneKmRun) + " \n");
    resultArray.push_back("����/����         | " + std::to_string(averageValues.CostOneDay) + " \n");
    resultArray.push_back("������ ����� (���)| " + std::to_string(averageValues.ConsumptionTimeOfOneLiter) + " \n");

    std::string result = "";

    for (int i = 0; i < resultArray.size(); i++) {
      result += resultArray[i];
    }

    return result;
  }

  void LabTwo::StartCycleProgramm() const
  {
    CycleProgramm
    (
      [&](std::string str) { return ProgrammFunction(str); },
      _infoForGetData,
      _infoForGetData + "\n����� ��������� ����������� ���� � ����� ������ ����� $"
    );
  };

}

