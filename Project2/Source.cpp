// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "math.h"

using namespace std;
double F(double x, double* arrс, int NCoeff)
{
  double FS = 0;
  for (int i = 0; i < NCoeff; i++)
    FS += arrс[i] * pow(x, i);
  return FS;
}
bool IsNumeric(char str[]) {
  const char symb[] = "0123456789,-"; bool flag = false;
  for (int i = 0; i < strlen(str); i++) {
    flag = false;
    for (int j = 0; j < strlen(symb); j++)
      if (symb[j] == str[i]) flag = true;
    if (flag == false) return false;
  }
  return true;
}

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "RUSSIAN");
  if (argc < 6) {
    cout << "Число параметров не соответствует ожидаемому и должно быть, как минимум 5!" << endl; system("pause"); return 0;
  }
  double S = 0, x = 0, a = 0, b = 0, h = 0, N = 0;
  int Nmet = 0, NCoeff = argc - 5;
  double* coeff = new double[NCoeff];
  bool err = false;
  //argc = 7;
  //argv[1] = "0"; argv[2] = "3"; argv[3] = "0,00001"; argv[4] = "2"; 
  argv[5] = "1"; argv[6] = "1";
  if (IsNumeric(argv[1])) a = atof(argv[1]); else {
    cout << "Левая граница диапазона не является числом!" << endl; err = true;
  }
  if (IsNumeric(argv[2])) b = atof(argv[2]); else {
    cout << "Правая граница диапазона не является числом!" << endl; err = true;
  }
  if (IsNumeric(argv[3])) h = atof(argv[3]); else h = 0;
  if (IsNumeric(argv[4])) Nmet = atoi(argv[4]); else Nmet = 0;
  if (a >= b) {
    cout << "Левая граница диапазона должна быть < правой границы диапазона!" << endl; err = true;
  }
  if (h < 0.000001 || h > 0.5) {
    cout << "Шаг интегрирования должен быть в пределах[0.000001; 0.5]" << endl; err = true;
  }
  if (Nmet <= 0 || Nmet > 3) {
    cout << "Четвертый параметр определяет метод интегрирования и должен быть в пределах[1; 3]" << endl; err
      = true;
  }
  for (int i = 0; i < NCoeff; i++)
    coeff[i] = atof(argv[i + 5]);
  //for (int i = 0; i < NCoeff; i++)
  // cout << coeff[i] << endl;
  if (!err) {
    switch (Nmet) {
    case 1:
      //PARABOL -----------------------------
      x = a + h;
      while (x < b)
      {
        S = S + 4 * F(x, coeff, NCoeff);
        x += h;
        if (x >= b) break;
        S = S + 2 * F(x, coeff, NCoeff);
        x += h;
      }
      S = (h / 3) * (S + F(a, coeff, NCoeff) + F(b, coeff, NCoeff));
      break;
      //PARABOL -----------------------------
    case 2:
      //TRAPEZIA -----------------------------
      N = floor((b - a) / h);
      S = (F(b, coeff, NCoeff) - F(a, coeff, NCoeff)) / 2;
      x = a + h;
      for (int i = 1; i < N; i++) {
        S += F(x, coeff, NCoeff);
        x = x + h;
      }
      S = S * h;
      break;
      //TRAPEZIA -----------------------------
    case 3:
      //MONTE CARLO
      srand((unsigned)time(NULL));
      N = floor((b - a) / h);
      for (int i = 0; i < N; i++)
        S += F(a + ((double)rand() / RAND_MAX * (b - a)),
          coeff, NCoeff);
      S = S / (double)N * (b - a);
      break;
      //MONTE CARLO -----------------------------
    }
    cout << "S = " << S << endl;
  }
  system("pause");
  return 0;
}
