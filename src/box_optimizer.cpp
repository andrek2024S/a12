#include "box_optimizer.hpp"

std::pair<int, int> findItemsForBox(const std::vector<int>& item_weights, int box_capacity)
{
    std::unordered_map<int, int> u;
    for (int i = 0; i < item_weights.size(); i++)
    {
        int remaining = box_capacity - item_weights[i];
        if (u.contains(remaining))
        {
            std::pair<int, int> out (u.at(remaining), i);
            return out;
        }
        else
        {
            u.insert({item_weights[i], i});
        }
    }
    std::pair<int, int> out (-1, -1);
    return out;
}