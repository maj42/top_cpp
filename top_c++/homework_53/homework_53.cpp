#include <iostream>
#include <queue>
#include <thread>

class BankSimulator {
    std::queue<int> clientsIDQueue;

public:
    BankSimulator& push(int ID) {
        clientsIDQueue.push(ID);
        return *this;
    }

    BankSimulator& serveCustomers() {
        while (!clientsIDQueue.empty()) {
            std::cout << "Served client ID: " << clientsIDQueue.front() << std::endl;
            clientsIDQueue.pop();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        return *this;
    }
};

int main()
{
    BankSimulator bank;
    bank.push(101010);
    bank.push(202020);
    bank.push(303030);
    bank.serveCustomers();
}