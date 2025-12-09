#pragma once

#include <vector>
#include <string>
#include "ThroneInheritance.hpp"

using namespace std;

void processInput(
    const vector<string>& commands,
    const vector<vector<string>>& args
);

void readInputFromConsole(
    vector<string>& commands,
    vector<vector<string>>& args
);


