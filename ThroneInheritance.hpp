#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class ThroneInheritance {
private:
    string king;
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;

    void dfs(const string& name, vector<string>& order)
    {
        if (dead.find(name) == dead.end())
            order.push_back(name);

        for (const auto& child : children[name]) {
            dfs(child, order);
        }
    }

public:
    ThroneInheritance(const string& kingName)
    {
        king = kingName;
    }

    void birth(const string& parentName, const string& childName)
    {
        children[parentName].push_back(childName);
    }

    void death(const string& name)
    {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> order;
        dfs(king, order);
        return order;
    }
};

