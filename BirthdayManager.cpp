#include <iostream>
#include <ctime>
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
            std::cout << "Enter the date of birth (dd/mm): ";
            profile in;
            in.name = input;
            std::cin >> std::get_time(&in.date, "%d/%m");
            //std::cout << input << std::put_time (&in.date,"%d/%m/%y");
            list.push_back(in);

        }
    }
    std::time_t d = std::time(nullptr);
    std::tm currentDate = *std::localtime(&d);
    profile find;
    find.date = *std::localtime(&d);
    find.date.tm_mon = 11;
    find.date.tm_mday = 31;
    /*find.date.tm_yday = 365;
    std::cout << std::put_time(&find.date, "%d/%m/%y") << std::endl;
    std::cout << std::put_time(&currentDate, "%d/%m/%y") << std::endl;*/
    for (int i = 0; i < list.size(); ++i)
    {
        
        if (list[i].date.tm_mon == currentDate.tm_mon && list[i].date.tm_mday == currentDate.tm_mday)
        {
            /*std::cout << std::put_time(&list[i].date, "%d/%m/%y") << std::endl;
            std::cout << list[i].date.tm_yday << std::endl;
            std::cout << std::put_time(&currentDate, "%d/%m/%y") << std::endl;
            std::cout << currentDate.tm_yday << std::endl;*/
            std::cout << "Today (" << std::put_time(&list[i].date, "%d/%m/%y") << ") is " << list[i].name << "'s Birth Day!" << std::endl;
            return 0;
            
        }
        else if ((list[i].date.tm_mon >= currentDate.tm_mon && list[i].date.tm_mday > currentDate.tm_mday) 
            && (list[i].date.tm_mon <= find.date.tm_mon && list[i].date.tm_mday < find.date.tm_mday))
        {
            
            find.name = list[i].name;
            find.date.tm_mon = list[i].date.tm_mon;
            find.date.tm_mday = list[i].date.tm_mday;
            
        }
    }
    std::cout << "Nearest is " << find.name <<"'s Birth Day (" << std::put_time(&find.date, "%d/%m/%y") << ")" << std::endl;
}

