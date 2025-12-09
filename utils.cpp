#include "utils.hpp"
#include <iostream>
#include <sstream>

using namespace std;

static string trim(const string& s) {
    string r;
    for (char c : s) {
        if (c != ' ' && c != '"' )
            r.push_back(c);
    }
    return r;
}

static vector<string> parseCommands(const string& line) {
    vector<string> result;
    string s;

    for (int i = 0; i < line.size(); i++) {
        char c = line[i];
        if (c == '"') {
            s.clear();
            i++;
            while (i < line.size() && line[i] != '"') {
                s.push_back(line[i]);
                i++;
            }
            result.push_back(s);
        }
    }
    return result;
}

static vector<vector<string>> parseArgs(const string& line) {
    vector<vector<string>> result;
    vector<string> cur;
    string s;

    bool inString = false;
    for (int i = 0; i < line.size(); i++) {
        char c = line[i];

        if (c == '"') {
            inString = true;
            s.clear();
            i++;
            while (i < line.size() && line[i] != '"') {
                s.push_back(line[i]);
                i++;
            }
            cur.push_back(s);
            inString = false;
        }
        else if (c == ']') {
            if (!cur.empty()) {
                result.push_back(cur);
                cur.clear();
            } else {
                result.push_back({});
            }
        }
    }

    return result;
}

void readInputFromConsole(
    vector<string>& commands,
    vector<vector<string>>& args
) {
    string line1, line2;

    getline(cin, line1); 
    getline(cin, line2); 
    commands = parseCommands(line1);
    args     = parseArgs(line2);
}

void processInput(
    const vector<string>& commands,
    const vector<vector<string>>& args
) {
    ThroneInheritance* t = nullptr;

    for (size_t i = 0; i < commands.size(); i++) {
        const string& cmd = commands[i];

        if (cmd == "ThroneInheritance") {
            t = new ThroneInheritance(args[i][0]);
            cout << "null\n";
        }
        else if (cmd == "birth") {
            t->birth(args[i][0], args[i][1]);
            cout << "null\n";
        }
        else if (cmd == "death") {
            t->death(args[i][0]);
            cout << "null\n";
        }
        else if (cmd == "getInheritanceOrder") {
            auto order = t->getInheritanceOrder();
            cout << "[";
            for (int j = 0; j < order.size(); j++) {
                cout << order[j];
                if (j + 1 < order.size()) cout << ", ";
            }
            cout << "]\n";
        }
    }

    delete t;
}
