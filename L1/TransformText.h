#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

class TransformText
{
private:
  static std::string Replace(const std::string& text, char oldVal, const std::string& newVal);
  static std::vector<std::string> Split(const std::string& s, char delim);
  static std::string GetWorgdWithoutSimbols(const std::string& s);
public:
  /// <summary>
  ///  ����� �����. ��������� ����� ����� �� ���� ��������� �� ��������: 
  /// ������ ����� ������ ������ ������� �� ��������� ���� ���� ���������
  /// ������, ������ ����� �� ������������� ���� � ��� �����.
  /// </summary>
  /// <param name="text">�������� �����</param>
  /// <returns></returns>
  static std::string GetTransformedText(const std::string& text, bool isIgnoreSimbols);
};

