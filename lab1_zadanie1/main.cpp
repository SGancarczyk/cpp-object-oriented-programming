#include <iostream>

using namespace std;


class Date
{
private:
   int day;
   int month;
   int year;
public:
   Date(int d, int m, int y){
      day = d;
      month = m;
      year = y;
   }
   void setDay(int newday){
      if (month == 2){
         if (newday > 0 and newday < 29){
            day = newday;
         }
      } else if (month%2 == 1){
         if (newday > 0 and newday < 32){
            day = newday;
         }
      }  else{
         if (newday > 0 and newday <31){
            day = newday;
         }
      }
   }

   void setMonth(int newmonth){
      if (newmonth > 0 and newmonth < 13){
         month = newmonth;
      }
   }

   void setYear(int newyear){
      if (newyear > 0 and newyear < 2026){
         year = newyear;
      }
   }

   int getDay() const {
      return day;
   }

   int getMonth() const {
      return month;
   }

   int getYear() const {
      return year;
   }
};


int main()
 {
   Date newdate(11, 02, 2024);
   cout << "Data " << newdate.getDay() << '.';
   cout << newdate.getMonth() << '.';
   cout << newdate.getYear() << endl;

   newdate.setDay(27);
   newdate.setMonth(12);
   newdate.setYear(2023);

   cout << "Data " << newdate.getDay() << '.';
   cout << newdate.getMonth() << '.';
   cout << newdate.getYear() << endl;
 };