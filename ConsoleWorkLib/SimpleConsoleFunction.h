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
    /// Изменить цвет текста и фона
    /// </summary>
    /// <param name="text">цвет текста</param>
    /// <param name="background">цвет фона</param>
    static void SetColor(ConsoleColor text, ConsoleColor background);
  public:

    /// <summary>
    /// Вывести переменную типа string в консоль
    /// </summary>
    /// <param name="text">переменная типа string</param>
    static void StringToConsole(const std::string& text);

    /// <summary>
    /// Получить переменную типа string из консоли
    /// </summary>
    /// <returns></returns>
    static std::string StringFromConsoleByLine();

    /// <summary>
    /// Вывести ошибку в консоль
    /// </summary>
    /// <param name="text">текст ошибки</param>
    static void ErrorTextToConsole(const std::string& text);

    /// <summary>
    /// Вывести уведомление в консоль
    /// </summary>
    /// <param name="text">текст уведомления</param>
    static void InfoTextToConsole(const std::string& text);

    /// <summary>
    /// Вывести цветной текст в консоль
    /// </summary>
    /// <param name="text"></param>
    /// <param name="colorText"></param>
    static void ColorTextToConsole(const std::string& text, ConsoleColor colorText);

    static void SetStandartColor();
  };
}
