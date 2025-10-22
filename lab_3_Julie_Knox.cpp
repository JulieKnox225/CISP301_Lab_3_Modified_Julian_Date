//Program:     Lab #3 Modified Julian Date
//Author:      Julie Knox
//Due Date:    9/25/25
//Description: A program that calculates the Modified Julian Date of a
//             user provided date. The input is broken up into month,
//             day, year, and will be converted into the M.J.D by
//             the course provided equations.

#include <iostream>
#include <iomanip>

//Promises
void input_data(int &month, int &day, int &year);
void output_results(int month, int day, int year, int mjd);
void perform_mjd_calculation(int month, int day, int year, int &mjd);

int main() {
    int month,
        day,
        year,
        mjd;
    
    input_data(month, day, year);
    perform_mjd_calculation(month, day, year, mjd);
    output_results(month, day, year, mjd);
    return 0;
}

// A program that neatly requests three integers to represent a date.
// It first requests the month number, a day number, and a year number
// to then save to the respective variables.
void input_data(int &month, int &day, int &year)
{
    std::cout << "Enter a month number (Jan=1, Feb=2, etc.): ";
    std::cin >> month;
    std::cout << "Enter a day number (1..31)" << std::setw(17) << ": ";
    std::cin >> day;
    std::cout << "Enter a year using four digits" << std::setw(13) << ": ";
    std::cin >> year;
    std::cout << std::endl;
}

// A program that neatly outputs the user provided date and the converted
// modified julian date for it.
void output_results(int month, int day, int year, int mjd)
{
    std::cout << "The MJD for "
              << month << "/" << day << "/" << year
              << " is " << mjd
    << std::endl;
}

// A program that calculates the modified julian date for the user
// provided date by utilizing the class provided equation
void perform_mjd_calculation(int month, int day, int year, int &mjd)
{
    int n1,
        n2,
        n3,
        n4;
    
    n1 = ( 14 - month ) / 12;
    n2 = ( month - 3 ) + ( 12 * n1 );
    n3 = year + 4800 - n1;
    n4 = ( n3 / 4 ) - ( n3 / 100 ) + ( n3 / 400) ;
    
    mjd = day + ( ( ( 153 * n2 ) + 2 ) / 5 ) + ( 365 * n3 ) + n4 - 2432046;
}
