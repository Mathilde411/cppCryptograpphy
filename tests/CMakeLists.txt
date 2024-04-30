add_executable(${PROJECT_NAME}_TEST
        bigIntTests.cpp
)
target_link_libraries(${PROJECT_NAME}_TEST PUBLIC ${PROJECT_NAME} Catch2::Catch2WithMain)
add_test(NAME ${PROJECT_NAME}_TEST COMMAND ${PROJECT_NAME})
set_tests_properties(${PROJECT_NAME}_TEST PROPERTIES ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${${PROJECT_NAME}_OUTPUT}")