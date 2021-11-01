cmake_minimum_required(VERSION 3.15)
project(camera_calibration LANGUAGES C CXX)

set(CMAKE_MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELWITHDEBINFO RELEASE)

find_package(OpenCV REQUIRED CONFIG)

set_property(GLOBAL PROPERTY USE_FOLDER ON)

add_executable(${PROJECT_NAME} calibration.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER apps
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    DEBUG_POSTFIX _d
    RELWITHDEBINFO_POSTFIX _rd
)

set(APP_NAME calib_images_from_video)
add_executable(${APP_NAME} calib_images_from_video.cpp)
target_link_libraries(${APP_NAME} PRIVATE ${OpenCV_LIBRARIES})
set_target_properties(${APP_NAME} PROPERTIES
    FOLDER apps
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    DEBUG_POSTFIX _d
    RELWITHDEBINFO_POSTFIX _rd
)
