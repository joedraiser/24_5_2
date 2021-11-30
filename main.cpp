#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

struct person
{
    std::string name;
    std::tm birthdayDate;
};

std::tm getTodayDate()
{
    std::time_t t=std::time(nullptr);
    return *std::localtime(&t);
}

std::time_t getNearestBirthday(std::tm birthday)
{
    std::time_t t;
    birthday.tm_year=getTodayDate().tm_year;
    t=std::mktime(&birthday);

    if (std::difftime(t, std::time(nullptr)) < 0)
    {
        birthday.tm_year++;
        t = std::mktime(&birthday);
    }

    return t;
}

void arrangeByNearestBirthday(std::vector<person>& friends)
{
    person temp;

    for(int i=0;i<friends.size()-1;i++)
    {
        for(int j=0;j<friends.size()-i-1;j++)
        {
            if(getNearestBirthday(friends[j].birthdayDate)>getNearestBirthday(friends[j+1].birthdayDate))
            {
                temp = friends[j];
                friends[j]=friends[j+1];
                friends[j+1]=temp;
            }
        }
    }
}

int main()
{
    person man;
    std::vector<person> friends;

    man.birthdayDate=getTodayDate();

    do
    {
        std::cout << "Input name and date of birth: ";
        std::cin >> man.name;
        if(man.name=="end")
            break;
        std::cin >> std::get_time(&man.birthdayDate, "%d/%m/%Y");

        if(std::cin.fail())
            std::cin.clear();
        else
            friends.push_back(man);
    }
    while(true);

    arrangeByNearestBirthday(friends);

    for(int i=0;i<friends.size();i++)
    {
        std::cout << friends[i].name << " " << std::put_time(&(friends[i].birthdayDate), "%d/%m/%Y") << std::endl;
    }

    return 0;
}