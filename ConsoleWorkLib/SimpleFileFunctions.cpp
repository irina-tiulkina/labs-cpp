#include "pch.h"
#include "SimpleFileFunctions.h"


namespace GetTextInfosLib {
  void SimpleFileFunctions::SaveStringToFile(const std::string& text, const std::string& path)
  {
    std::ofstream out; // ����� ��� ������
    out.open(path); // �������� ���� ��� ������
    if (out.is_open())
    {
      out << text << std::endl;
    }
    else {
      throw "�� ���������� ��������� ����";
    }
    out.close();
  }

  std::string SimpleFileFunctions::GetStringFromFile(const std::string& path)
  {
    std::ifstream in(path); // �������� ���� ��� ������
    std::string str = "";
    if (in.is_open())
    {
      std::string line;
      while (std::getline(in, line))
      {
        //std::cout << line << std::endl;
        str += line + '\n';
      }
    }
    else {
      throw "�� ���������� ������� ����, ��������� ��� ���� ���������� ";
    }
    in.close();     // ��������� ����

    return str;
  }

  bool SimpleFileFunctions::FileExists(const std::string& path)
  {
    bool isExist = false;
    std::ifstream fin(path);

    if (fin.is_open())
      isExist = true;

    fin.close();
    return isExist;
  }

  // �������� �� �������� �����, ���� ���� ������� �� ������ ������������ 
  // �.�. ������ ������ � ������ ������ ���������� false, ����� true
  bool SimpleFileFunctions::IsReadOnlyFile(const std::string& path) {
    WIN32_FIND_DATAA findData;
    LPCSTR name = path.c_str();
    FindFirstFileA(name, &findData);
    if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
      return true;
    }
    else
      return false;
  }
}
