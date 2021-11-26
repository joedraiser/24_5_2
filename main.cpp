#include <iostream>
#include <ctime>
#include<iomanip>
#include <map>

int main()
{
    std::map<std::time_t, std::string> friends;
    std::tm current;
    std::time_t t;
    std::string name;

    do
    {
        t=std::time(nullptr);
        current=*std::localtime(&t);
        std::cout << "Input name and date of birth: ";
        std::cin >> name;
        if(name=="end")
            break;
        std::cin >> std::get_time(&current, "%d/%m/%Y");
        t=std::mktime(&current);

        if(std::cin.fail())
            std::cin.clear();
        else
            friends[t]=name;
    }
    while(true);

    for(auto it=friend.begin();it!=friend.end();it++)
    {
        
    }

    return 0;
}