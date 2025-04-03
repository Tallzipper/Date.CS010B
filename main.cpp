#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned month, unsigned day, unsigned year);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &month, unsigned day, unsigned year);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned year) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned month, unsigned year) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned month) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &monthName) const;

   void Error(unsigned month, string &monthName, unsigned day, unsigned year);

};


// Implement the Date member functions here ------------------------------------------------------------------

Date::Date()
{

   day = 1;
   month = 1;
   monthName = "January";
   year = 2000;

}

Date::Date(unsigned month, unsigned day, unsigned year)
{

   bool error = false;
   this->month = month;
   this->monthName = name(this->month);
   this->day = day;
   this->year = year;

   if(this->month == 0)
   {

      this->month = 1;
      this->monthName = "January";

      error = true;

   }
   if(this->month > 12)
   {

      this->month = 12;
      this->monthName = "December";

      error = true;

   }
   if(day < 1)
   {

      this->day = 1;

      error = true;

   }
   if(day > daysPerMonth(this->month, year))
   {

      this->day = daysPerMonth(this->month, year);

      error = true;

   }
   
   if(error == true)
   {

      cout << "Invalid date values: Date corrected to ";
      printNumeric();
      cout << "." << endl; 

   }

}

Date::Date(const string &month, unsigned day, unsigned year)
{

   bool error = false;
   this->month = number(month);
   this->monthName = name(this->month);
   this->day = day;
   this->year = year;

   if(this->month < 1)
   {

      this->month = 1;
      this->day = 1;
      this->year = 2000;
      this->monthName = "January";

      cout << "Invalid month name: the Date was set to ";
      printNumeric();
      cout << "." << endl; 
      return;

   }
   if(day < 1)
   {

      this->day = 1;

      error = true;

   }
   if(day > daysPerMonth(this->month, year))
   {

      this->day = daysPerMonth(this->month, year);

      error = true;

   }
   
   if(error == true)
   {

      cout << "Invalid date values: Date corrected to ";
      printNumeric();
      cout << "." << endl; 

   }

}

void Date::printNumeric() const
{

   cout << month << "/" << day << "/" << year;

}

void Date::printAlpha() const
{

   cout << monthName << " " << day << ", " << year;

}

string Date::name(unsigned month) const
{

   string mon = "N/A";

   if(month == 1)
   {

      mon = "January";

   }
   else if(month == 2)
   {

      mon = "February";

   }
   else if(month == 3)
   {

      mon = "March";

   }
   else if(month == 4)
   {

      mon = "April";

   }
   else if(month == 5)
   {

      mon = "May";

   }
   else if(month == 6)
   {

      mon = "June";

   }
   else if(month == 7)
   {

      mon = "July";

   }
   else if(month == 8)
   {

      mon = "August";

   }
   else if(month == 9)
   {

      mon = "September";

   }
   else if(month == 10)
   {

      mon = "October";

   }
   else if(month == 11)
   {

      mon = "November";

   }
   else if(month == 12)
   {

      mon = "December";

   }

   return mon;
}

unsigned Date::number(const string &monthName) const
{

   /* 
   
   You have no idea how annoyed I am that C++ doesn't have the .equalsIgnoreCase like java does
   I'm just going to be lame because month is also a constant so I am unable to change it.

   */ 

   unsigned mon = 0; 
 
   if(monthName == "january" || monthName == "January" )
   {

      mon = 1;

   }
   else if(monthName == "february" || monthName == "February")
   {

      mon = 2;

   }
   else if(monthName == "march" || monthName == "March")
   {

      mon = 3;

   }
   else if(monthName == "april" || monthName == "April")
   {

      mon = 4;

   }
   else if(monthName == "may" || monthName == "May")
   {

      mon = 5;

   }
   else if(monthName == "june" || monthName == "June")
   {

      mon = 6;

   }
   else if(monthName == "july" || monthName == "July")
   {

      mon = 7;

   }
   else if(monthName == "august" || monthName == "August")
   {

      mon = 8;

   }
   else if(monthName == "september" || monthName == "September")
   {

      mon = 9;

   }
   else if(monthName == "october" || monthName == "October")
   {

      mon = 10;

   }
   else if(monthName == "november" || monthName == "November")
   {

      mon = 11;

   }
   else if(monthName == "december" || monthName == "December")
   {

      mon = 12;

   }

   return mon;

}
void Date::Error(unsigned month, string &monthName, unsigned day, unsigned year)
{

   if(month == 0)
   {

      month = 1;
      monthName = "January";
      day = 1;
      year = 2000;

      cout << "Invalid month name: the Date was set to ";
      printNumeric();

   }

}

unsigned Date::daysPerMonth(unsigned month, unsigned year) const
{

   int max;

   if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
   {

      max = 31;

   }
   else if(month == 4 || month == 6 || month == 9 || month == 11)
   {

      max = 30;

   }
   else
   {
      if(isLeap(year) == true)
      {

         max = 29;

      }
      else
      {

         max = 28;

      }
   }


   return max;

}

bool Date::isLeap(unsigned year) const
{

   bool leap = false;

   if(year % 4 == 0)
   {

      if(year % 100 == 0)
      {

         if(year % 400 == 0)
         {

            leap = true;

         }

      }
      else
      {

         leap = true;

      }

   }

   return leap;

}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
