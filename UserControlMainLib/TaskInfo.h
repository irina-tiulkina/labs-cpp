#pragma once
#include <string>
namespace UserControlMainLib {
  class TaskInfo
  {
  private:
    std::string TargetInfo = "������������ ������ 1";
    std::string AuthorInfo = "�������� ����� ��������";
    std::string AboutTaskInfo = "����� �����. ��������� ����� ����� �� ���� ��������� �� ��������:\n������ ����� ������ ������ ������� �� ��������� ���� ���� ���������\n������, ������ ����� �� ������������� ���� � ��� �����.";
    std::string GroupAuthorInfo = "494";
    std::string KursInfo = "4";
    std::string ResultInfo = "� ���������� ��������� �������� �����";
  public:
    TaskInfo();
    TaskInfo(std::string target, std::string author, std::string aboutTask, std::string group, std::string kurs, std::string result);

    TaskInfo(std::string target, std::string aboutTask, std::string result);
    std::string GetAboutTask() const;

    std::string GetTitleTask() const;
  };

}
