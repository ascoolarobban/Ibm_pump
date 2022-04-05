# !!! WARNING !!! AUTO-GENERATED FILE, PLEASE DO NOT MODIFY IT AND USE
# https://docs.platformio.org/page/projectconf/section_env_build.html#build-flags
#
# If you need to override existing CMake configuration or add extra,
# please create `CMakeListsUser.txt` in the root of project.
# The `CMakeListsUser.txt` will not be overwritten by PlatformIO.

cmake_minimum_required(VERSION 3.13)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project("Arduino_Cpp" C CXX)

include(CMakeListsPrivate.txt)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsUser.txt)
include(CMakeListsUser.txt)
endif()

add_custom_target(
    Production ALL
    COMMAND platformio -c clion run "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    Debug ALL
    COMMAND platformio -c clion debug "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Z_DUMMY_TARGET ${SRC_LIST} src/declare.h src/pumpControl.cpp src/pumpControl.h src/breatheButton.cpp src/breatheButton.h src/buttonIsTriggered.cpp src/buttonIsTriggered.h src/commandHandler.cpp src/commandHandler.h src/sendJson.cpp src/sendJson.h src/runTime.cpp src/runTime.h src/sensors.cpp src/sensors.h src/debounce.cpp src/debounce.h src/readButtons.cpp src/readButtons.h src/setPWM.cpp src/setPWM.h src/pumpSerialCommand.cpp src/pumpSerialCommand.h src/welcomeBlink.cpp src/welcomeBlink.h src/readPotentiometers.cpp src/readPotentiometers.h src/detect_change.cpp src/detect_change.h src/readSensors.cpp src/readSensors.h src/convertToLitres.cpp src/convertToLitres.h)
