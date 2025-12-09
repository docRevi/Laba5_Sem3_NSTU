#include <iostream>
#include "utils.hpp"

using namespace std;

int main() {
    vector<string> commands;
    vector<vector<string>> args;

    cout << "Введите список команд:\n";

    readInputFromConsole(commands, args);

    processInput(commands, args);

    return 0;
}
