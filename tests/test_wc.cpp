#include "../src/wc_utils.hpp"
#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("count_lines counts correctly") {
    SECTION("empty input returns 0") {
        std::istringstream empty_string_stream("");
        auto result = wc::count_lines(empty_string_stream);
        REQUIRE(result.has_value());
        REQUIRE(result.value() == 0);
    }
}
