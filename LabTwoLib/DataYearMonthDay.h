#pragma once

namespace LabTwoLib {
  class DataYearMonthDay {
  public:
    int Day;  // day of month from 1 to 31
    int Month;   // month of year from 1 to 12
    int Year;  // year since 1900

    DataYearMonthDay(int year, int month, int day) {
      Year = year;
      Month = month;
      Day = day;
    };

    DataYearMonthDay() {
      Day = 0;
      Month = 0;
      Year = 0;
    };
  };
}


