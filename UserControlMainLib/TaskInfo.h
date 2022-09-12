#pragma once
#include <string>
namespace UserControlMainLib {
  class TaskInfo
  {
  private:
    std::string TargetInfo = "Лабораторная работа 1";
    std::string AuthorInfo = "Тюлькина Ирина Павловна";
    std::string AboutTaskInfo = "Задан текст. Составить новый текст из букв заданного по принципу:\nпервое слово нового текста состоит их последних букв слов заданного\nтекста, второе слово из предпоследних букв и так далее.";
    std::string GroupAuthorInfo = "494";
    std::string KursInfo = "4";
    std::string ResultInfo = "В результате программы получаем текст";
  public:
    TaskInfo();
    TaskInfo(std::string target, std::string author, std::string aboutTask, std::string group, std::string kurs, std::string result);

    TaskInfo(std::string target, std::string aboutTask, std::string result);
    std::string GetAboutTask() const;

    std::string GetTitleTask() const;
  };

}
