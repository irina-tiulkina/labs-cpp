#include "pch.h"
#include "TaskInfo.h"

std::string TaskInfo::GetAboutTask()
{
  std::string target = TargetInfo;
  std::string author = "�����: " + AuthorInfo;
  std::string kurs = "������: " + GroupAuthorInfo + " ����: " + KursInfo;
  std::string taskAbout = "������: " + AboutTaskInfo;
  std::string result = ResultInfo;

  std::string aboutTask = target + '\n' + author + '\n' + kurs + '\n' + taskAbout + '\n' + result + '\n';
  return aboutTask;
}
