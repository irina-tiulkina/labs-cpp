#include "pch.h"
#include "TaskInfo.h"
namespace UserControlMainLib {
  std::string TaskInfo::GetAboutTask() const
  {
    std::string target = TargetInfo;
    std::string author = "�����: " + AuthorInfo;
    std::string kurs = "������: " + GroupAuthorInfo + " ����: " + KursInfo;
    std::string taskAbout = "������: " + AboutTaskInfo;
    std::string result = ResultInfo;

    std::string aboutTask = target + '\n' + author + '\n' + kurs + '\n' + taskAbout + '\n' + result + '\n';
    return aboutTask;
  }
}
