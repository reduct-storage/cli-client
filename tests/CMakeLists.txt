
enable_testing()
include(CTest)
include(Catch)

add_executable(
        unit_tests
        test.cc
        reduct_cli/controller_test.cc
)

target_link_libraries(unit_tests PRIVATE ${PROJECT_NAME}_lib)



# Discover tests
catch_discover_tests(unit_tests)
