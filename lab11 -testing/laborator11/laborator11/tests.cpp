#include "catch.hpp"
#include "CircularQueue.h"

TEST_CASE("Testing the circular buffer", "[classic]") {
    SECTION("Test the size of vector") {
        CircularQueue<std::string> queue(4);
        queue.push("ana");
        queue.push("casiana");
        REQUIRE(queue.size() == 2);
    }

    SECTION("Test the push, pop, front, and back methods") {
        CircularQueue<unsigned> queue(4);
        queue.push(3);
        queue.pop();
        REQUIRE(queue.empty());
        REQUIRE_THROWS_AS(queue.front(), std::out_of_range);
        REQUIRE_THROWS_AS(queue.back(), std::out_of_range);

        queue.push(0);
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        REQUIRE(queue.back() == 4);
    }

    SECTION("Test with 1000 elements") {
        CircularQueue<int> queue(4);
        for (int i = 1; i <= 1000; i++)
            queue.push(i);

        REQUIRE(queue.front() == 997);
        queue.pop();
        REQUIRE(queue.front() == 998);
        queue.pop();
        REQUIRE(queue.front() == 999);
        queue.pop();
        REQUIRE(queue.front() == 1000);
        queue.pop();

        // tests added by me
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        queue.pop();
        REQUIRE(queue.size() == 3);
        queue.push(4);
        queue.push(5);
        REQUIRE(queue.front() == 3);
        REQUIRE(queue.back() == 5);
    }
}