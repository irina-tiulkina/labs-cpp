#include "pch.h"
#include "TaskInfo.h"
namespace UserControlMainLib {
  std::string TaskInfo::GetAboutTask() const
  {
    std::string target = TargetInfo;
    std::string author = "Автор: " + AuthorInfo;
    std::string kurs = "Группа: " + GroupAuthorInfo + " Курс: " + KursInfo;
    std::string taskAbout = "Задача: " + AboutTaskInfo;
    std::string result = ResultInfo;

    std::string aboutTask = target + '\n' + author + '\n' + kurs + '\n' + taskAbout + '\n' + result + '\n';
    return aboutTask;
  }
  TaskInfo::TaskInfo() {};
  TaskInfo::TaskInfo(std::string target, std::string author, std::string aboutTask, std::string group, std::string kurs, std::string result) {
    TargetInfo = target;
    AuthorInfo = author;
    AboutTaskInfo = aboutTask;
    GroupAuthorInfo = group;
    KursInfo = kurs;
    ResultInfo = result;
  }

  TaskInfo::TaskInfo(std::string target, std::string aboutTask, std::string result) {
    TargetInfo = target;
    AboutTaskInfo = aboutTask;
    ResultInfo = result;
  }

  std::string TaskInfo::GetTitleTask() const { return TargetInfo; }
}
