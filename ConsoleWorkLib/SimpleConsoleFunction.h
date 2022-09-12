#pragma once
#include <string>
#include <iostream>
#include <windows.h>   // WinApi header
namespace GetTextInfosLib {
  enum ConsoleColor
  {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
  };

  class SimpleConsoleFunction
  {
  private:
    /// <summary>
    /// �������� ���� ������ � ����
    /// </summary>
    /// <param name="text">���� ������</param>
    /// <param name="background">���� ����</param>
    static void SetColor(ConsoleColor text, ConsoleColor background);
  public:

    /// <summary>
    /// ������� ���������� ���� string � �������
    /// </summary>
    /// <param name="text">���������� ���� string</param>
    static void StringToConsole(const std::string& text);

    /// <summary>
    /// �������� ���������� ���� string �� �������
    /// </summary>
    /// <returns></returns>
    static std::string StringFromConsoleByLine();

    /// <summary>
    /// ������� ������ � �������
    /// </summary>
    /// <param name="text">����� ������</param>
    static void ErrorTextToConsole(const std::string& text);

    /// <summary>
    /// ������� ����������� � �������
    /// </summary>
    /// <param name="text">����� �����������</param>
    static void InfoTextToConsole(const std::string& text);

    /// <summary>
    /// ������� ������� ����� � �������
    /// </summary>
    /// <param name="text"></param>
    /// <param name="colorText"></param>
    static void ColorTextToConsole(const std::string& text, ConsoleColor colorText);

    static void SetStandartColor();
  };
}
