cmake_minimum_required (VERSION 2.6)
project (env-cgi)
add_executable(${PROJECT_NAME} main.c)
include_directories(/usr/include/Eclipse-Paho-MQTT-C-1.3.9-Linux/include)
target_link_libraries(${PROJECT_NAME} paho-mqtt3c)

find_library(wiringPi_LIB wiringPi)
target_link_libraries(${PROJECT_NAME} ${wiringPi_LIB})