add_library(stacklstt INTERFACE stacklstt.hpp)
set_property(TARGET stacklst PROPERTY CXX_STANDARD 20)
target_include_directories(stacklstt INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
