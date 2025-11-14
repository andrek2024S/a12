#pragma once

#include <map>
#include <vector>
#include <string>

std::map<int, std::string> createLoyaltyTiers();

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score);