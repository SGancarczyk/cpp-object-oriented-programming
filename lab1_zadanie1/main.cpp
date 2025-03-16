#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>


enum class Month {
   January = 1, February, March, April, May, June,
   July, August, September, October, November, December
};


class Date{
private:
   int day;
   Month month;
   int year;
   bool ValidateData(int d, Month m, int y){
      int month_lenght;
      switch (m){
         case Month::January: case Month::March: case Month::May: case Month::July:
         case Month::August: case Month::October: case Month::December:
            month_lenght = 31;
            break;
         case Month::April: case Month::June: case Month::September: case Month::November:
            month_lenght = 30;
            break;
         case Month::February:
            month_lenght = 28;
            break;
         default:
            return false;
      } return (d >= 1 && d <= month_lenght);
   }
public:
   Date(int d, Month m, int y){
      if (!ValidateData(d, m, y)){
         throw std::invalid_argument("Invalid Data Input");
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
      if (!(y>0 && y<3000)) {
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
      oss << std::setw(2) << std::setfill('0') << static_cast<int>(month); // static_cast is required due to enum usage
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


int main()
 {
   Date newdate(15, Month::March, 2024);
   std::cout << "Data: " << newdate.getDay() << '.';
   std::cout << newdate.getMonth() << '.';
   std::cout << newdate.getYear() << std::endl;
   std::cout << newdate.getDate() << std::endl;

   newdate.setDay(27);
   newdate.setMonth(Month::April);
   newdate.setYear(2023);

   std::cout << "Data: " << newdate.getDay() << '.';
   std::cout << newdate.getMonth() << '.';
   std::cout << newdate.getYear() << std::endl;
   std::cout << newdate.getDate() << std::endl;
   try {
      Date d1(15, Month::March, 2023);
      d1.setDay(32);
      d1.getDate();
   } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
   }
   try {
      Date d1(31, Month::March, 2023);
      d1.setMonth(Month::February); 
      d1.getDate();
   } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
   }
   try {
      Date d1(15, Month::March, 2023);
      d1.setYear(0);
      d1.getDate();
   } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
   }
 };