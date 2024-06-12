#include <iostream>
#include <list>

class CommandHistory {
    std::list<std::string> commandList;
public:
    void command() {
        std::string command;
        while (1) {
            command.clear();
            std::cin >> command;
            if (command == "exit") return;
            else if (command == "history") {
                commandList.push_back(command);
                showHistory();
            }
            else if (command == "delete") {
                std::cout << "---Enter index to delete --- : ";
                int ind;
                std::cin >> ind;
                if (ind >= 0 && ind < commandList.size()) {
                    auto iter = commandList.begin();
                    std::advance(iter, ind);
                    commandList.erase(iter);
                    commandList.push_back(command);
                }
                else std::cout << "---Out of range.---";
            }
            else commandList.push_back(command);
        }
    }

    void showHistory() {
        std::cout << "------------ Command History : ------------" << std::endl;
        for (std::string& command : commandList) {
            std::cout << command << std::endl;
        }
        std::cout << "------------- History end. ----------------" << std::endl;
    }
};

int main()
{
    CommandHistory ch;
    ch.command();
}
