#include "pch.h"
#include "LabTwo.h"
#include <ctime>

namespace LabTwoLib {
  double LabTwo::GetPositiveDoubleValue(std::string str, std::string strException) const
  {
    std::string dataStr = GetTextInfosLib::StringTransform::Replace(str, '.', ",");
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
    return value;
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
      std::string strEx = "В дате " + strData + " ошибка. Проверьте правильность ввода (гггг.мм.дд)";
      throw std::exception(strEx.c_str());
    }
    DataYearMonthDay dataFromStr;
    try {
      dataFromStr.Year = std::stoi(dateVector[0]);
      dataFromStr.Month = std::stoi(dateVector[1]);
      dataFromStr.Day = std::stoi(dateVector[2]);
    }
    catch (std::invalid_argument) {
      std::string strEx = "В дате " + strData + " ошибка. Проверьте правильность ввода (гггг.мм.дд)";
      throw std::exception(strEx.c_str());
    }
    catch (std::out_of_range) {
      std::string strEx = "В дате " + strData + " ошибка. Проверьте правильность ввода (гггг.мм.дд)";
      throw std::exception(strEx.c_str());
    }

    if (dataFromStr.Year < 1) {
      std::string strEx = "В дате " + strData + " ошибка. Год не может быть отрицательным";
      throw std::exception(strEx.c_str());
    }

    if (dataFromStr.Day < 1 || dataFromStr.Day > 31) {
      std::string strEx = "В дате " + strData + " ошибка. День должен быть в диапазоне от 1 до 31";
      throw std::exception(strEx.c_str());
    }

    if (dataFromStr.Month < 1 || dataFromStr.Month > 12) {
      std::string strEx = "В дате " + strData + " ошибка. Месяц должен быть в диапазоне от 1 до 12";
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
    struct tm a = { 0,0,0,leftDay.Day,leftDay.Month-1,leftDay.Year -1900}; /* June 24, 2004 */
    struct tm b = { 0,0,0,rightDay.Day,rightDay.Month-1,rightDay.Year -1900}; /* July 5, 2004 */
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);

    int difference = std::difftime(y, x) / (60 * 60 * 24);

    return difference;
  }

  std::string LabTwo::ToStringFromDouble(double value, int countValAfterPoint = 3) const
  {
    std::ostringstream out;
    out.precision(3);
    out << std::fixed << value;
    return out.str();
  }

  GasolineAverageValueModel LabTwo::GetAverageValuesByGlModels(const std::vector<GasolineLogModel>& dlmodels) const
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

  std::map<std::string, GasolineAverageValueModel> LabTwo::GetAverageGlModelsByMarks(const std::vector<GasolineLogModel>& glmodels) const
  {
    std::map<std::string, std::vector<GasolineLogModel>> glmap;
    for (int i = 0; i < glmodels.size(); i++) {
      auto model = glmodels[i];
      glmap.emplace(model.Mark, std::vector<GasolineLogModel>());
      glmap[model.Mark].push_back(model);
    }

    std::map<std::string, GasolineAverageValueModel> averageMap;
    for (const auto& kv : glmap) {
      averageMap.insert_or_assign(kv.first, GetAverageValuesByGlModels(kv.second));
    }

    return averageMap;
  }

  std::vector<GasolineLogModel> LabTwo::ComputeExtensionParameters(const std::vector<GasolineLogModel>& models) const
  {
    // сортируем по пробегу
    std::vector<GasolineLogModel> purchasesModel = models;
    purchasesModel = QuickSortByMileage(purchasesModel);

    // расчет для каждой заправки
    purchasesModel[0].MileageBetweenGasStations = purchasesModel[0].MileageOnTheSensor;
    purchasesModel[0].MileagePerLiter = purchasesModel[0].MileageBetweenGasStations / purchasesModel[0].NumberOfLiters;
    purchasesModel[0].CostOfOneKmRun = (purchasesModel[0].NumberOfLiters / purchasesModel[0].MileageBetweenGasStations) * purchasesModel[0].PriceOfLiter;
    purchasesModel[0].CostOneDay = -1;
    purchasesModel[0].ConsumptionTimeOfOneLiter = -1;

    for (int i = 1; i < purchasesModel.size(); i++) {

      int countDayBetweenStation = GetCountDayBetweenGasStation(purchasesModel[i - 1].Date, purchasesModel[i].Date);

      purchasesModel[i].MileageBetweenGasStations = purchasesModel[i].MileageOnTheSensor - purchasesModel[i - 1].MileageOnTheSensor;

      if (purchasesModel[i].MileageBetweenGasStations <= 0) {
        throw "Ошибка в пробегах. Нельзя оплатить заправку, если пройдено 0 км. Проверьте указанные данные.";
      }
      // пройденные км / кол-во литров
      purchasesModel[i].MileagePerLiter = purchasesModel[i].MileageBetweenGasStations / purchasesModel[i].NumberOfLiters;
      // кол-во литров за км * стоимость литра | сумма / пройденные км
      purchasesModel[i].CostOfOneKmRun = (purchasesModel[i].NumberOfLiters / purchasesModel[i].MileageBetweenGasStations) * purchasesModel[i].PriceOfLiter;
      // кол-во литров за день * стоимость литра | сумма / кол-во дней
      purchasesModel[i].CostOneDay = purchasesModel[i].NumberOfLiters / countDayBetweenStation * purchasesModel[i].PriceOfLiter;
      // кол-во дней / кол-во литров
      purchasesModel[i].ConsumptionTimeOfOneLiter = countDayBetweenStation / purchasesModel[i].NumberOfLiters;
    }
    return purchasesModel;
  }

  std::string LabTwo::ProgrammFunction(const std::string& inputDataInString) const
  {
    // ------- Проверка входных данных и преобразование данных в объект --------
    std::vector<std::string> purchases = GetTextInfosLib::StringTransform::Split(inputDataInString, '\n');
    std::vector<GasolineLogModel> purchasesModel;
    for (int i = 0; i < purchases.size(); i++) {
      std::vector<std::string> purchase = GetTextInfosLib::StringTransform::Split(purchases[i], ' ');
      if (purchase.size() != _countInputParameters)
      {
        std::string exStr = "Количество параметров в строке " + std::to_string(i + 1) + " не равно " + std::to_string(_countInputParameters);
        throw std::exception(exStr.c_str());
      }

      GasolineLogModel gl;

      try {
        gl.Date = GetDate(purchase[0]);
        gl.Mark = purchase[1];
        gl.MileageOnTheSensor = GetPositiveDoubleValue(purchase[2], " Проверьте запись пробега");
        gl.PriceOfLiter = GetPositiveDoubleValue(purchase[3], " Проверьте запись цены галлона");
        gl.NumberOfLiters = GetPositiveDoubleValue(purchase[4], " Проверьте запись количества галлонов");
        gl.TotalCost = GetPositiveDoubleValue(purchase[5], " Проверьте запись суммы");
      }
      catch (std::exception ex) {
        std::string exStr = "В строке " + std::to_string(i+1) + " ошибка. " + ex.what();
        throw std::exception(exStr.c_str());
      }

      if (std::abs(gl.PriceOfLiter * gl.NumberOfLiters - gl.TotalCost) >= 0.3 ) {
        std::string strEx = "В строке " + std::to_string(i+1) + " ошибка. Указанная общая стоимость значительно отличается от рассчитанной.";
        throw std::exception(strEx.c_str());
      }
      purchasesModel.push_back(gl);
    }

    // ----- Вычисление статистики ------

    purchasesModel = ComputeExtensionParameters(purchasesModel);
    GasolineAverageValueModel averageValues = GetAverageValuesByGlModels(purchasesModel);
    std::map<std::string, GasolineAverageValueModel> averageByMarks = GetAverageGlModelsByMarks(purchasesModel);

    // ------- Формирование результатов в строковую переменную --------
    std::string result = "";
    int sizeCharItem = 15;
    std::vector<std::string> resultArray;
    std::vector<std::string> headerMainVector{ "Дата", "Марка бензина", "Пробег(км)", "Цена литра(руб)",
      "Кол-во литров", "Сумма", "ПробегФакт", "Пробег на литр", "Цена/км", "Цена/день", "Время на 1л" };
    
    resultArray.push_back(GetStrRowForTable(headerMainVector, sizeCharItem));

    for (int i = 0; i < purchasesModel.size(); i++) {
      GasolineLogModel model = purchasesModel[i];

      resultArray.push_back(GetStrRowForTable(GetStrVectorFromGasolineModel(model), sizeCharItem));
    }
    resultArray.push_back("\n*-1 ставится если недостаточно данных для расчета\n");

    std::vector<std::string> averageHeader = { "", "ПробегФакт", "Цена одного литра", "Пробег на литр", "Цена/км", "Цена/день", "Время на 1л" };
    resultArray.push_back("\nЗа все время наблюдений: \n");
    resultArray.push_back(GetStrRowForTable(averageHeader, sizeCharItem));
    resultArray.push_back(GetStrRowForTable(GetStrVectorFromGasolineAverageValueModel("Все марки", averageValues), sizeCharItem));

    for (const auto& kv : averageByMarks) {
      resultArray.push_back(GetStrRowForTable(GetStrVectorFromGasolineAverageValueModel(kv.first, kv.second), sizeCharItem));
    }

    for (int i = 0; i < resultArray.size(); i++) {
      result += resultArray[i];
    }

    return result;
  }

  std::vector<std::string> LabTwo::GetStrVectorFromGasolineAverageValueModel(const std::string &mark, GasolineAverageValueModel averageValues) const {
    std::string milFact = ToStringFromDouble(averageValues.MileageBetweenGasStations);
    std::string coastLiter = ToStringFromDouble(averageValues.PriceOfLiter);
    std::string milL = ToStringFromDouble(averageValues.MileagePerLiter);
    std::string costKm = ToStringFromDouble(averageValues.CostOfOneKmRun);
    std::string costDay = ToStringFromDouble(averageValues.CostOneDay);;
    std::string timeLiter = ToStringFromDouble(averageValues.ConsumptionTimeOfOneLiter);

    std::vector<std::string> rowVector = { mark, milFact , coastLiter , milL , costKm ,costDay , timeLiter };
    return rowVector;
  }

  std::vector<std::string> LabTwo::GetStrVectorFromGasolineModel(GasolineLogModel model) const {
    std::string date = std::to_string(model.Date.Year) + "." + std::to_string(model.Date.Month) + "." + std::to_string(model.Date.Day);
    std::string mark = model.Mark;
    std::string mileageSensor = ToStringFromDouble(model.MileageOnTheSensor);
    std::string coastLiter = ToStringFromDouble(model.PriceOfLiter);
    std::string conutliters = ToStringFromDouble(model.NumberOfLiters);
    std::string totalCost = ToStringFromDouble(model.TotalCost);
    std::string milFact = ToStringFromDouble(model.MileageBetweenGasStations);
    std::string milL = ToStringFromDouble(model.MileagePerLiter);
    std::string costKm = ToStringFromDouble(model.CostOfOneKmRun);
    std::string costDay = ToStringFromDouble(model.CostOneDay);;
    std::string timeLiter = ToStringFromDouble(model.ConsumptionTimeOfOneLiter);

    std::vector<std::string> rowVector = { date, mark,mileageSensor, coastLiter,conutliters,totalCost,
      milFact, milL, costKm, costDay, timeLiter };
    return rowVector;
  }

  std::string LabTwo::GetStrRowForTable(const std::vector<std::string>& items, int sizeItemHeader) const
  {
    std::string row = "";
    for (int i = 0; i < items.size(); i++) {
      std::string itemStr = items[i];
      itemStr.resize(sizeItemHeader, ' ');
      row += itemStr + "|";
    }
    row += "\n";
    return row;
  }

  void LabTwo::StartCycleProgramm() const
  {
    CycleProgramm
    (
      [&](std::string str) { return ProgrammFunction(str); },
      _infoForGetData,
      _infoForGetData + "\n!!!!(Текст считается законченным если в конце строки стоит $)!!!!\n"
    );
  };

}

