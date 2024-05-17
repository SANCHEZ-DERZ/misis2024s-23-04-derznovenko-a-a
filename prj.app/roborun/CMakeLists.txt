add_library(roborun roborun.cpp roborun.hpp)
set_property(TARGET roborun PROPERTY CXX_STANDARD 20)
target_include_directories(roborun PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)