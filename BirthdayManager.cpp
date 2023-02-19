#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>

struct profile
{
    std::string name = "";
    std::time_t t = std::time(nullptr);
    std::tm date = *std::localtime(&t);
};

int main()
{
    std::vector<profile> list;
    std::string input = "";
   
    std::cout << "Birthday Manger." << std::endl;
    while (input != "end")
    {
        std::cout << "Enter the name: ";
        std::cin >> input;
        if (input == "end")
        {
            
        }
        else
        {
            std::cout << "Enter the date of birth: ";
            profile in;
            std::cin >> std::get_time(&in.date, "%d/%m/%y");
            //std::cout << input << std::put_time (&in.date,"%d/%m/%y");
            list.push_back(in);

        }
    }
    std::time_t t = std::time(nullptr);
    std::tm currentDate = *std::localtime(&t);
    profile find;
    std::cout << input << std::put_time(&currentDate, "%d/%m/%y");
    for (int i = 0; i < list.size(); ++i)
    {
        if (list[i].date.tm_year == currentDate.tm_year)
        {
            find.name = list[i].name;
            find.date = list[i].date;
            
        }
    }
}

