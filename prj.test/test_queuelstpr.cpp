#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuelstpr/queuelstpr.hpp"

TEST_CASE("Testing QueueLstPr") {
    QueueLstPr queue;

    SUBCASE("Testing IsEmpty() on an empty queue") {
        CHECK(queue.IsEmpty());
    }

    SUBCASE("Testing Push() and Top() on a non-empty queue") {
        queue.Push(5.0f);
        queue.Push(3.0f);
        queue.Push(7.0f);

        CHECK_FALSE(queue.IsEmpty());
        CHECK_EQ(queue.Top(), 3.0f);
    }

    SUBCASE("Testing Pop() on a non-empty queue") {
        queue.Push(5.0f);
        queue.Push(3.0f);
        queue.Push(7.0f);

        queue.Pop();
        CHECK_EQ(queue.Top(), 5.0f);

        queue.Pop();
        CHECK_EQ(queue.Top(), 7.0f);
    }

    SUBCASE("Testing Clear() on a non-empty queue") {
        queue.Push(5.0f);
        queue.Push(3.0f);
        queue.Push(7.0f);

        queue.Clear();
        CHECK(queue.IsEmpty());
    }
}
