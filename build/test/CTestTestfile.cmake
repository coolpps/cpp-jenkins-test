# CMake generated Testfile for 
# Source directory: /home/bxh/Downloads/cpp-jenkins-test/test
# Build directory: /home/bxh/Downloads/cpp-jenkins-test/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MathTest "/home/bxh/Downloads/cpp-jenkins-test/build/test/test_math")
set_tests_properties(MathTest PROPERTIES  _BACKTRACE_TRIPLES "/home/bxh/Downloads/cpp-jenkins-test/test/CMakeLists.txt;21;add_test;/home/bxh/Downloads/cpp-jenkins-test/test/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
