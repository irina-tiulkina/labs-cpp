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
}
