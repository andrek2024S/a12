#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "api_monitor.hpp"
#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"
#include "iostream"

TEST_CASE("box found", "[box_optimizer]")
{
    std::vector<int> input;
    input.push_back(10);
    input.push_back(20);
    input.push_back(30);

    std::pair<int, int> output = findItemsForBox(input, 30);
    REQUIRE(output.first == 0);
    REQUIRE(output.second == 1);
}

TEST_CASE("box not found", "[box_optimizer]")
{
    std::vector<int> input;
    input.push_back(10);
    input.push_back(20);
    input.push_back(30);

    std::pair<int, int> output = findItemsForBox(input, 60);
    REQUIRE(output.first == -1);
    REQUIRE(output.second == -1);
}

TEST_CASE("common items", "[cart_analysis]")
{
    std::vector<std::vector<std::string>> carts = {
        {"apples", "bananas", "grapes"},
        {"apples", "bananas", "blueberries"},
        {"apples", "bananas"}
    };

    std::vector<std::string> common = commonProductsAcrossCarts(carts);
    REQUIRE(common[0] == "apples");
    REQUIRE(common[1] == "bananas");
}

TEST_CASE("no common items", "[cart_analysis]")
{
    std::vector<std::vector<std::string>> carts = {
        {"apples", "bananas", "grapes"},
        {"apples", "bananas", "blueberries"},
        {"grapes", "blueberries"}
    };

    std::vector<std::string> common = commonProductsAcrossCarts(carts);
    REQUIRE(common.size() == 0);
}

TEST_CASE("various tiers", "[customer_loyalty]")
{
    auto tiers = createLoyaltyTiers();

    int bronze = 250;
    int silver = 750;
    int gold = 1500;
    int platinum = 2500;

    REQUIRE(getLoyaltyTier(tiers, bronze) == "Bronze");
    REQUIRE(getLoyaltyTier(tiers, silver) == "Silver");
    REQUIRE(getLoyaltyTier(tiers, gold) == "Gold");
    REQUIRE(getLoyaltyTier(tiers, platinum) == "Platinum");
}

TEST_CASE("multiple points", "[api_monitor]")
{
    std::vector<std::string> logs = {"/api/cart", "/api/checkout", "/api/login", "/api/cart", "/api/login"};

    std::pair<std::vector<std::string>, int> out = find_most_frequent_endpoints(logs);
    REQUIRE(out.first[0] == "/api/cart");
    REQUIRE(out.first[1] == "/api/login");
    REQUIRE(out.second == 2);
}