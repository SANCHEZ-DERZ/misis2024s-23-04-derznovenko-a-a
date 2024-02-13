#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarr/stackarr.hpp"

TEST_CASE("stack IsEmpty") {
	StackArr st;
	Complex a;
	CHECK_EQ(st.IsEmpty(), true);
	st.Push(a);
	CHECK_EQ(st.IsEmpty(), false);
}