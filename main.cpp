#include <iostream>
#include <ctime>
#include<iomanip>
#include <map>

int main()
{
    std::map<std::time_t, std::string> friends;
    std::tm birthdayDate, todayDate;
    std::time_t t;

    t=std::time(nullptr);
    todayDate=*std::localtime(&t);
    birthdayDate=todayDate;
    std::string name;

    do
    {
        std::cout << "Input name and date of birth: ";
        std::cin >> name;
        if(name=="end")
            break;
        std::cin >> std::get_time(&birthdayDate, "%d/%m/%Y");
        birthdayDate.tm_year=todayDate.tm_year;

        t=std::mktime(&birthdayDate);
        if(std::difftime(t, std::time(nullptr))<0)
        {
            birthdayDate.tm_year++;
            t=std::mktime(&birthdayDate);
        }

        if(std::cin.fail())
            std::cin.clear();
        else
            friends[t]=name;
    }
    while(true);

    //for(auto it=friends.begin();it!=friends.end();it++)
    //{

    //}

    return 0;
}