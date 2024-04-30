add_executable(${PROJECT_NAME}Test
        bigIntTests.cpp
)
target_link_libraries(${PROJECT_NAME}Test PUBLIC ${PROJECT_NAME} Catch2::Catch2WithMain)
add_test(NAME ${PROJECT_NAME}Test COMMAND ${PROJECT_NAME}Test)
set_tests_properties(${PROJECT_NAME}Test PROPERTIES ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${${PROJECT_NAME}_OUTPUT}")