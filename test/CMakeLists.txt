include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)

FetchContent_MakeAvailable(googletest)


add_executable(est-cpp-jenkins test-cpp-jenkins.cpp)
target_link_libraries(est-cpp-jenkins
  gtest
  gtest_main
)

include(CTest)
enable_testing()

add_test(NAME MathTest COMMAND est-cpp-jenkins)