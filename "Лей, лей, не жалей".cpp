#include <iostream>

class Order
{
    int start;
    int end;
    int cost;
public:
    void setOrder()
    {
        std::cin >> start >> end >> cost;
    }

    int getStart()
    {
        return start;
    }

    int getEnd()
    {
        return end;
    }

    int getCost()
    {
        return cost;
    }

    int getTime()
    {
        return end - start;
    }
};

class Request
{
    int start, end, type;
public:
    void setRequest()
    {
        std::cin >> start >> end >> type;
    }
    int getStart()
    {
        return start;
    }

    int getEnd()
    {
        return end;
    }

    int getType()
    {
        return type;
    }
};

int main()
{
    int orderCount, requestCount;
    std::cin >> orderCount;

    Order *orders = new Order[orderCount];
    for (int i = 0; i < orderCount; i++)
        orders[i].setOrder();

    std::cin >> requestCount;

    Request request;

    int* costSum  = new int[requestCount];
    int* timeSum = new int[requestCount];

    int i = 0;
    while (i < requestCount)
    {
        costSum[i] = 0;
        timeSum[i] = 0;
        request.setRequest();

        if (request.getType() == 1)
            for (int j = 0; j < orderCount; j++)
                if (request.getStart() <= orders[j].getStart() && orders[j].getStart() <= request.getEnd())
                    costSum[i] += orders[j].getCost();
        
        if (request.getType() == 2)
            for (int j = 0; j < orderCount; j++)
                if (request.getStart() <= orders[j].getEnd() && orders[j].getEnd() <= request.getEnd())
                    timeSum[i] += orders[j].getTime();
        i++;
    }

    for (int j = 0; j < requestCount; j++)
    {
        if (costSum[j] == 0 && timeSum[j] == 0)
            std::cout << 0 << ' ';

        if (costSum[j] > timeSum[j])
            std::cout << costSum[j] << ' ';

        if (timeSum[j] > costSum[j])
            std::cout << timeSum[j] << ' ';
    }

    return 0;
}
