#include "pch.h"
#include "L2.h"
#include "../GasolineLogModels/GasolineLogModel.h"

double L2::GetPositiveDoubleValue(std::string str, std::string strException) const
{
  std::string dataStr = st_t::Replace(str, ',', ".");
  double value;
  try {
    value = std::stod(dataStr);
    if(value < 1){
      throw std::exception();
    }
  }
  catch(...){
    throw std::exception(strException.c_str());
  }
  return 0.0;
}

DataYearMonthDay L2::GetDate(std::string strData) const
{
  int countCharYear = 4;
  int countCharMD = 2;
  std::string dataStr = st_t::Replace(strData, ',', ".");
  dataStr = st_t::Replace(dataStr, '/', ".");
  dataStr = st_t::Replace(dataStr, '\\', ".");
  std::vector<std::string> dateVector = st_t::Split(dataStr, '.');
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
  catch(std::invalid_argument) {
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

std::vector<glmodel> L2::QuickSortByMileage(std::vector<glmodel> array) const {
  if (array.size() < 2) {
    return array;
  }
  else{
    int pivotIndx = array.size() - 1 / 2;
    double pivot = array[pivotIndx].MileageOnTheSensor;
    std::vector<glmodel> leftArray;
    std::vector<glmodel> rightArray;
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
    std::vector<glmodel> result = QuickSortByMileage(leftArray);
    std::vector<glmodel> resultRightArray = QuickSortByMileage(rightArray);
    result.push_back(array[pivotIndx]);
    for (int i = 0; i < resultRightArray.size(); i++) {
        result.push_back(resultRightArray[i]);
    }
    return result;
  }
}

int L2::GetCountDayBetweenGasStation(DataYearMonthDay leftDay, DataYearMonthDay rightDay) const
{
  struct std::DataYearMonthDay a = { 0,0,0,leftDay.Day,leftDay.Month,leftDay.Year }; /* June 24, 2004 */
  struct std::DataYearMonthDay b = { 0,0,0,rightDay.Day,rightDay.Month,rightDay.Year }; /* July 5, 2004 */
  std::time_t x = std::mktime(&a);
  std::time_t y = std::mktime(&b);

  int difference = std::difftime(y, x) / (60 * 60 * 24);
  return difference;
}

glAverage L2::GetAverageVeluesByGlModels(const std::vector<glmodel> &dlmodels) const
{
  glAverage average;
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
  average.ConsumptionTimeOfOneLiter /= dlmodels.size() -1;
  average.CostOneDay /= dlmodels.size() -1;

  return average;
}

std::vector<glAverage> L2::GetAverageGlModelsByMarks(const std::vector<glmodel>& dlmodels) const
{
  return std::vector<glAverage>();
}

std::vector<glmodel> L2::ComputeExtensionParameters(const std::vector<glmodel> &models) const
{
  // сортируем по пробегу
  std::vector<glmodel> purchasesModel = models;
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

std::string L2::ProgrammFunction(const std::string& inputDataInString) const
{
  // ------- Проверка входных данных и преобразование данных в объект --------
  std::vector<std::string> purchases = st_t::Split(inputDataInString, '\n');
  std::vector<glmodel> purchasesModel;
  for (int i = 0; i < purchases.size(); i++) {
    std::vector<std::string> purchase = st_t::Split(purchases[i], ' ');
    if (purchase.size() != _countInputParameters)
    {
      std::string exStr = "Количество параметров в строке " + std::to_string(i + 1) + "не равно" + std::to_string(_countInputParameters);
      throw std::exception(exStr.c_str());
    }

    glmodel gl;
    
    try {
      gl.Date = GetDate(purchase[0]);
      gl.Mark = purchase[1];
      gl.MileageOnTheSensor = GetPositiveDoubleValue(purchase[2], "Проверьте запись пробега");
      gl.PriceOfLiter = GetPositiveDoubleValue(purchase[3], "Проверьте запись цены галлона");
      gl.NumberOfLiters = GetPositiveDoubleValue(purchase[4], "Проверьте запись количества галлонов");
      gl.TotalCost = GetPositiveDoubleValue(purchase[5], "Проверьте запись суммы");
    }
    catch(std::exception ex) {
      std::string exStr = "В строке" + std::to_string(i) + " ошибка. " + ex.what();
      throw std::exception(exStr.c_str());
    }
    purchasesModel.push_back(gl);
  }

  // ----- Вычисление статистики ------
   
  purchasesModel = ComputeExtensionParameters(purchasesModel);
  glAverage averageValues = GetAverageVeluesByGlModels(purchasesModel);
  std::vector<glAverage> averageByMarks = GetAverageGlModelsByMarks(purchasesModel);

  // ------- Формирование результатов в строковую переменную --------
  std::vector<std::string> resultArray;
  resultArray.push_back("Дата              | ");
  resultArray.push_back("Марка бензина     | ");
  resultArray.push_back("Пробег(км)        | ");
  resultArray.push_back("Цена литра(руб)   | ");
  resultArray.push_back("Кол-во литров     | ");
  resultArray.push_back("Сумма             | ");
  resultArray.push_back("ПробегФакт        | ");
  resultArray.push_back("Пробег на литр    | ");
  resultArray.push_back("Цена/км           | ");
  resultArray.push_back("Цена/день         | ");
  resultArray.push_back("Расход литра (дни)| ");

  for (int i = 0; i < purchasesModel.size(); i++) {
    glmodel model = purchasesModel[i];

    std::string date = std::to_string(model.Date.Year) + "." + std::to_string(model.Date.Month) + "." + std::to_string(model.Date.Day);
    date.resize(20, ' ');
    resultArray[0] += date + "|";

    std::string mark = model.Mark;
    mark.resize(20, ' ');
    resultArray[1] += mark + "|";

    std::string mileageSensor = std::to_string(model.MileageOnTheSensor);
    mileageSensor.resize(20, ' ');
    resultArray[2] += mileageSensor + "|";

    std::string coastLiter = std::to_string(model.PriceOfLiter);
    coastLiter.resize(20, ' ');
    resultArray[3] += coastLiter + "|";

    std::string conutliters = std::to_string(model.NumberOfLiters);
    conutliters.resize(20, ' ');
    resultArray[4] += conutliters + "|";

    std::string totalCost = std::to_string(model.TotalCost);
    totalCost.resize(20, ' ');
    resultArray[5] += totalCost + "|";

    std::string milFact = std::to_string(model.MileageBetweenGasStations);
    milFact.resize(20, ' ');
    resultArray[6] += milFact + "|";

    std::string milL = std::to_string(model.MileagePerLiter);
    milL.resize(20, ' ');
    resultArray[7] += milL + "|";

    std::string costKm = std::to_string(model.CostOfOneKmRun);
    costKm.resize(20, ' ');
    resultArray[8] += costKm + "|";

    std::string costDay = std::to_string(model.CostOneDay);
    costDay.resize(20, ' ');
    resultArray[9] += costDay + "|";

    std::string timeLiter = std::to_string(model.ConsumptionTimeOfOneLiter);
    timeLiter.resize(20, ' ');
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
  resultArray.push_back("\n*-1 ставится если недостаточно данных для расчета\n");
  resultArray.push_back("\nЗа все время наблюдений: \n");
  resultArray.push_back("ПробегФакт        | " + std::to_string(averageValues.MileageBetweenGasStations) +" \n");
  resultArray.push_back("Цена одного литра | " + std::to_string(averageValues.PriceOfLiter) + " \n");
  resultArray.push_back("Пробег на литр    | " + std::to_string(averageValues.MileagePerLiter) + " \n");
  resultArray.push_back("Цена/км           | " + std::to_string(averageValues.CostOfOneKmRun) + " \n");
  resultArray.push_back("Цена/день         | " + std::to_string(averageValues.CostOneDay) + " \n");
  resultArray.push_back("Расход литра (дни)| " + std::to_string(averageValues.ConsumptionTimeOfOneLiter) + " \n");

  std::string result = "";

  for (int i = 0; i < resultArray.size(); i++) {
    result += resultArray[i];
  }

  return result;
}
