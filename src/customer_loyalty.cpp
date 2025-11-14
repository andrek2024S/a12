#include "customer_loyalty.hpp"

std::map<int, std::string> createLoyaltyTiers()
{
    std::map<int, std::string> out {{0, "Bronze"}, {500, "Silver"}, {1000, "Gold"}, {2000, "Platinum"}};
    return out;
}

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score)
{
    auto it = tiers.lower_bound(score);
    if (it == tiers.begin())
    {
        return it->second;
    }
    if (it == tiers.end())
    {
        return std::prev(tiers.end())->second;
    }
    else
    {
        if (it->first != score)
        {
            it--;
        }
        return it->second;
    }
}