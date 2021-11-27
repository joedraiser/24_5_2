#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>

struct person
{
    std::string name;
    std::tm birthdayDate;
};

int main()
{
    person man;
    std::map<std::time_t, person> friends;
    std::tm nextBirthday, todayDate;
    std::time_t t;

    t=std::time(nullptr);
    todayDate=*std::localtime(&t);
    man.birthdayDate=todayDate;

    do
    {
        std::cout << "Input name and date of birth: ";
        std::cin >> man.name;
        if(man.name=="end")
            break;
        std::cin >> std::get_time(&man.birthdayDate, "%d/%m/%Y");
        nextBirthday=man.birthdayDate;
        nextBirthday.tm_year=todayDate.tm_year;

        t=std::mktime(&nextBirthday);
        if(std::difftime(t, std::time(nullptr))<0)
        {
            nextBirthday.tm_year++;
            t=std::mktime(&nextBirthday);
        }

        if(std::cin.fail())
            std::cin.clear();
        else
            friends[t]=man;
    }
    while(true);

    for(auto it=friends.begin();it!=friends.end();it++)
    {
        std::cout << it->second.name << " " << std::put_time(&(it->second.birthdayDate), "%d/%m/%Y") << std::endl;
    }

    return 0;
}