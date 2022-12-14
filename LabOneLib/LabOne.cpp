#include "pch.h"
#include "LabOne.h"

namespace LabOneLib {
  std::string LabOne::GetStrWithoutSimbols(const std::string& s, const char& c) const
  {
    std::string str = "";
    for (int i = 0; i < s.size(); i++) {
      if ((s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= 'A' && s[i] <= 'Z') ||
        s[i] == c ||
        (s[i] >= '?' && s[i] <= '?') ||
        (s[i] >= '?' && s[i] <= '?')) {
        str += s[i];
      }
      else {
        str += " ";
        continue;
      }
    }
    return str;
  }

  std::string LabOne::ProgrammFunction(const std::string& inputDataInString) const {
    std::string replacedText = GetTextInfosLib::StringTransform::Replace(inputDataInString, '\n', " ");
    replacedText = GetStrWithoutSimbols(replacedText, ' ');
    std::vector<std::string> delimText = GetTextInfosLib::StringTransform::Split(replacedText, ' ');

    std::vector<std::string> words;

    for (size_t i = 0; i < delimText.size(); i++) {

      std::string wordDelim = delimText[i];

      if (wordDelim.size() > words.size()) {
        size_t addSize = wordDelim.size() - words.size();
        for (int k = 0; k < addSize; k++) {
          words.push_back("");
        }
      }

      for (int j = wordDelim.size() - 1; j >= 0; j--) {
        size_t indexWord = (wordDelim.size() - 1) - j;
        words[indexWord] += wordDelim[j];
      }
    }

    std::string newText = "";

    for (size_t i = 0; i < words.size(); i++) {
      newText += (i == words.size() - 1) ? words[i] : words[i] + ' ';
    }

    return newText;
  }

  void LabOne::StartCycleProgramm() const
  {
    CycleProgramm([&](std::string str) { return ProgrammFunction(str); }, "", "????? ????????? ??????????? ???? ? ????? ?????? ????? $");
  }

}
