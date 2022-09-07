#include <iostream>
#include <algorithm>

class rocketsLog
{
    int day;
    int hour;
    int minute;
    int id;
    char status;

public:
    void newEntry()
    {
        std::cin >> day >> hour >> minute >> id >> status;
    }

    int getDay()
    {
        return day;
    }

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getId()
    {
        return id;
    }

    char getStatus()
    {
        return status;
    }

    bool operator>(rocketsLog r)
    {
        if(id != r.id)
            return id > r.id;

        if(day != r.day)
            return day > r.day;

        if (hour != r.hour)
            return hour > r.hour;

        return minute > r.minute;                
    }
    
    bool operator<(rocketsLog r)
    {
        if (id != r.id)
            return id < r.id;

        if (day != r.day)
            return day < r.day;

        if (hour != r.hour)
            return hour < r.hour;

        return minute < r.minute;
    }

    int operator-(rocketsLog r)
    {
        int leftOperand = (day * 24 * 60) + (hour * 60) + minute;
        int rightOperand = (r.day * 24 * 60) + (r.hour * 60) + r.minute;

        int time = leftOperand - rightOperand;

        return time;
    }
};

int main()
{
    int logsNum, time = 0;
    std::cin >> logsNum;

    rocketsLog *rockets = new rocketsLog[logsNum];

    for (int i = 0; i < logsNum; i++)
        rockets[i].newEntry();

    std::sort(rockets, rockets + logsNum);
    
    for (int i = 1; i < logsNum; i++)
    {
        if(rockets[i].getStatus() != 'A')
            time += rockets[i] - rockets[i - 1];

        if (rockets[i].getId() != rockets[i - 1].getId())
        {
            std::cout << time << ' ';
            time = 0;
        }
    }

    std::cout << time << '\n';
    
    return 0;
}
