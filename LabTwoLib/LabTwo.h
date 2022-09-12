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
    const std::string _infoForGetData = "В одном файле может быть несколько строк. Одна строка соответствует одной записи о покупке бензина.\
      Строка должна содержать данные в таком формате:\n\
      дата (гггг.мм.дд), марка бензина, пробег (в км), цена за литр (в рублях), количество литров, общая стоимость\n\
      Например: 2020.03.10 Texaco 24370 37.20 13.5 502.2\n\
      Текст должен содержать только данные - без описаний";
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
    ///  Для решения поставленной задачи
    /// </summary>
    /// <param name="inputDataInString">входные данные полученные из файла/консоли</param>
    /// <returns>Возвращает результат работы программы, решающей поставленную задачу, в виде строки для записи в консоль/файл</returns>
    std::string ProgrammFunction(const std::string& inputDataInString) const;
    void StartCycleProgramm() const override
    {
      CycleProgramm
      (
        [&](std::string str) { return ProgrammFunction(str); },
        _infoForGetData,
        _infoForGetData + "\nТекст считается законченным если в конце строки стоит $"
      );
    };

    LabTwo() : UserControlMainLib::UserInterfaceClaim{ UserControlMainLib::TaskInfo("Лабораторная работа 2 (Этюды для программистов стр.92)",
      R"S(По данным, имеющимся в журнале покупок бензина, напечатайте
        разнообразную контрольную статистику, показывающую водителю, во
        что обходится эксплуатация автомобиля.Исходные данные о каждой
        покупке — это дата, марка бензина, показание счетчика пройденного
        пути, цена одного литра, сколько литров куплено и общая стоимость.
        Выводимая информация должна повторять исходную и, кроме того,
        включать в себя такие показатели, как пробег между заправками, пробег
        на один литр, стоимость пробега в один километр, стоимость одного
        галлона, стоимость одного дня, время расходования одного галлона.Все
        указанные показатели следует получать для каждой заправки и усреднять
        двумя способами : за небольшой срок и за все время наблюдений.Кроме
        того, соберите данные по каждой марке бензина и напечатайте
        соответствующие средние значения.Не ограничивайте число различных
        марок(с. 92).)S",
        "") } {};
    ~LabTwo() {};
  };
}

