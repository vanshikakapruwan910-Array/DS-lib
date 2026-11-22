# CMake generated Testfile for 
# Source directory: C:/Users/DELL/OneDrive/Desktop/pbl
# Build directory: C:/Users/DELL/OneDrive/Desktop/pbl/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(domain_smoke_test "C:/Users/DELL/OneDrive/Desktop/pbl/build/Debug/domain_smoke_test.exe")
  set_tests_properties(domain_smoke_test PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/Users/DELL/OneDrive/Desktop/pbl/build/Debug/domain_smoke_test.exe" _BACKTRACE_TRIPLES "C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;55;add_test;C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(domain_smoke_test "C:/Users/DELL/OneDrive/Desktop/pbl/build/Release/domain_smoke_test.exe")
  set_tests_properties(domain_smoke_test PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/Users/DELL/OneDrive/Desktop/pbl/build/Release/domain_smoke_test.exe" _BACKTRACE_TRIPLES "C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;55;add_test;C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(domain_smoke_test "C:/Users/DELL/OneDrive/Desktop/pbl/build/MinSizeRel/domain_smoke_test.exe")
  set_tests_properties(domain_smoke_test PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/Users/DELL/OneDrive/Desktop/pbl/build/MinSizeRel/domain_smoke_test.exe" _BACKTRACE_TRIPLES "C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;55;add_test;C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(domain_smoke_test "C:/Users/DELL/OneDrive/Desktop/pbl/build/RelWithDebInfo/domain_smoke_test.exe")
  set_tests_properties(domain_smoke_test PROPERTIES  _CMAKE_TEST_BUILD_DEPENDS "C:/Users/DELL/OneDrive/Desktop/pbl/build/RelWithDebInfo/domain_smoke_test.exe" _BACKTRACE_TRIPLES "C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;55;add_test;C:/Users/DELL/OneDrive/Desktop/pbl/CMakeLists.txt;0;")
else()
  add_test(domain_smoke_test NOT_AVAILABLE)
endif()
