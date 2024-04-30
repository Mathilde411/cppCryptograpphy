file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${${PROJECT_NAME}_SOURCE_DIR}/include/crypto/*.hpp")
add_library(${PROJECT_NAME}
        SHARED
        ${HEADER_LIST}
        BigInt.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
target_link_libraries(${PROJECT_NAME} m)