#pragma once
#include <string>
namespace UserControlMainLib {
  class TaskInfo
  {
  private:
    std::string TargetInfo = "Лабораторная работа 1";
    std::string AuthorInfo = "Тюлькина Ирина Павловна";
    std::string AboutTaskInfo = 
      R"S(Задан текст. Составить новый текст из букв заданного по принципу:
      первое слово нового текста состоит их последних букв слов заданного
      текста, второе слово из предпоследних букв и так далее.)S";
    std::string GroupAuthorInfo = "494";
    std::string KursInfo = "4";
    std::string ResultInfo = "";
  public:
    TaskInfo();
    TaskInfo(std::string target, std::string author, std::string aboutTask, std::string group, std::string kurs, std::string result);

    TaskInfo(std::string target, std::string aboutTask, std::string result);
    std::string GetAboutTask() const;

    std::string GetTitleTask() const;
  };

}
