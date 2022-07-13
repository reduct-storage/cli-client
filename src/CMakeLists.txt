set(SRC_FILES
        reduct_cli/app.cc)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

configure_file(config.h.in ${CMAKE_BINARY_DIR}/reduct_cli/config.h @ONLY)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SRC_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME}_lib ${CONAN_LIBS} reduct_cpp)

message(STATUS ${CONAN_LIBS})
add_executable(reduct-cli main.cc)
target_link_libraries(reduct-cli PRIVATE ${CMAKE_PROJECT_NAME}_lib)