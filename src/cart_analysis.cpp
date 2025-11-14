#include "cart_analysis.hpp"

std::vector<std::string> commonProductsAcrossCarts(const std::vector<std::vector<std::string>>& carts)
{
    std::unordered_map<std::string, int> u;
    for (int i = 0; i < carts.size(); i ++)
    {
        for (int j = 0; j < carts[i].size(); j++)
        {
            if (u.contains(carts[i][j]))
            {
                u[carts[i][j]]++;
            }
            else
            {
                u.insert({carts[i][j], 1});
            }
        }
    }
    
    std::vector<std::string> out;
    for (auto it = u.begin(); it != u.end(); it++)
    {
        if (it->second == carts.size())
        {
            out.push_back(it->first);
        }
    }

    std::sort(out.begin(), out.end());
    return out;
}