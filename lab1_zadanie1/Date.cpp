#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>

enum class Month {
   January = 1, February, March, April, May, June,
   July, August, September, October, November, December
};

class Date {
private:
   int day;
   Month month;
   int year;

   bool ValidateData(int d, Month m, int y) {
      int month_length;
      switch (m) {
         case Month::January: case Month::March: case Month::May: case Month::July:
         case Month::August: case Month::October: case Month::December:
            month_length = 31;
            break;
         case Month::April: case Month::June: case Month::September: case Month::November:
            month_length = 30;
            break;
         case Month::February:
            month_length = 28; // brak obsługi lat przestępnych
            break;
         default:
            return false;
      }
      return (d >= 1 && d <= month_length);
   }

public:
   Date(int d, Month m, int y) {
      if (!ValidateData(d, m, y)) {
         throw std::invalid_argument("Invalid Date Input");
      }
      day = d;
      month = m;
      year = y;
   }

   void setDay(int d) {
      if (!ValidateData(d, month, year)) {
          throw std::invalid_argument("Invalid day for this month!");
      }
      day = d;
   }

   void setMonth(Month m) {
      if (!ValidateData(day, m, year)) {
          throw std::invalid_argument("Invalid Month!");
      }
      month = m;
   }

   void setYear(int y) {
      if (!(y > 0 && y < 3000)) {
          throw std::invalid_argument("Invalid Year!");
      }
      year = y;
   }

   std::string getDay() const {
      std::ostringstream oss;
      oss << std::setw(2) << std::setfill('0') << day;
      return oss.str();
   }

   std::string getMonth() const {
      std::ostringstream oss;
      oss << std::setw(2) << std::setfill('0') << static_cast<int>(month);
      return oss.str();
   }

   std::string getDate() const {
      std::ostringstream oss;
      oss << getDay() << "." << getMonth() << "." << year;
      return oss.str();
   }

   int getYear() const {
      return year;
   }
};