#include "api_monitor.hpp"

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data)
{
    std::unordered_map<std::string, int> u;
    for (int i = 0; i < log_data.size(); i++)
    {
        if (u.contains(log_data[i]))
        {
            u[log_data[i]]++;
        }
        else
        {
            u.insert({log_data[i], 1});
        }
    }
    
    std::vector<std::pair<std::string, int>> pairs;
    for (auto it = u.begin(); it != u.end(); it++)
    {
        std::pair<std::string, int> data (it->first, it->second);
        pairs.push_back(data);
    }
    
    int highest = 0;
    for (auto it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second > highest)
        {
            highest = it->second;
        }
    }

    std::vector<std::string> outVector;
    for (auto it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second == highest)
        {
            outVector.push_back(it->first);
        }
    }
    std::sort(outVector.begin(), outVector.end());
    std::pair<std::vector<std::string>, int> out (outVector, highest);
    return out;
} 