cmake_minimum_required(VERSION 3.14)
project(spi-testing)


set(CMAKE_CXX_STANDARD 14)
add_compile_definitions(DEVICE_SERIAL=1 DEVICE_SERIAL_ASYNCH=1 DEVICE_SERIAL_FC=1 DEVICE_SPI=1 DEVICE_SPISLAVE=1 TARGET_STM32F746 DEVICE_PWMOUT)
add_compile_definitions(DEVICE_INTERRUPTIN=1 TARGET_NUCLEO_F746ZG DEVICE_USBDEVICE DEVICE_ANALOGIN MBED_CONF_RTOS_PRESENT DEVICE_I2C DEVICE_CAN FDCAN1 DEVICE_PORTINOUT)
add_compile_definitions(MBED_CONF_RTOS_API_PRESENT MBED_CONF_EVENTS_PRESENT MBED_CONF_FILESYSTEM_PRESENT COMPONENT_SPIF COMPONENT_)
add_compile_definitions(STM32F767xx)
include_directories()

set(RDIR "${CMAKE_CURRENT_SOURCE_DIR}")



include_directories(base)
include_directories(BUILD)
include_directories(drivers/peripherals/Expansion_Modules/4kV_Expansion_2.0)
include_directories(drivers/power_supply)
include_directories(drivers/power_supply/power-supply-control)
include_directories(drivers/power_supply/power-supply-control)
include_directories(drivers/power_supply/power-supply-control/analog_front_end)
include_directories(drivers/power_supply/power-supply-control/analog_front_end/ADC_Drivers)
include_directories(drivers/power_supply/power-supply-control/analog_front_end/PGA_Drivers)
include_directories(drivers/power_supply/power-supply-control/dacxx6xt_driver)
include_directories(drivers/pulse_channel/pulse_channel_base_class)
include_directories(mbed-os)
include_directories(mbed-os/rtos)
include_directories(mbed-os/rtos/include)
include_directories(mbed-os/rtos/include/rtos)
include_directories(mbed-os/rtos/include/rtos/internal)
include_directories(mbed-os/rtos/source)
include_directories(mbed-os/events/include/events)
include_directories(mbed-os/events/include/events/internal)
include_directories(mbed-os/events)
include_directories(mbed-os/events/include)
include_directories(mbed-os/storage/filesystem/include)
include_directories(mbed-os/storage/blockdevice/include)
include_directories(mbed-os/storage/blockdevice/COMPONENT_SPIF/include/SPIF)
include_directories(mbed-os/storage/kvstore/include)
include_directories(mbed-os/storage/kvstore/tdbstore/include)
include_directories(mbed-os/drivers/include/drivers)
include_directories(mbed-os/drivers/include)
include_directories(mbed-os/drivers/include/drivers/interfaces)
include_directories(mbed-os/hal/include/hal)
include_directories(mbed-os/hal/include)
include_directories(mbed-os/targets/TARGET_STM)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/STM32Cube_FW)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/STM32Cube_FW/CMSIS)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/STM32Cube_FW/STM32F7xx_HAL_Driver)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/STM32Cube_FW/STM32F7xx_HAL_Driver/Legacy)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F746xG)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F746xG/TARGET_DISCO_F746NG)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F746xG/TARGET_NUCLEO_F746ZG)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F756xG)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F756xG/TARGET_NUCLEO_F756ZG)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/TARGET_NUCLEO_F767ZI)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/TARGET_UHURU_RAVEN)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F769xI)
include_directories(mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F769xI/TARGET_DISCO_F769NI)
include_directories(mbed-os/platform/include)
include_directories(mbed-os/platform/include/platform)
include_directories(mbed-os/platform/include/platform/internal)
include_directories(mbed-os/cmsis)
include_directories(mbed-os/cmsis/CMSIS_5/CMSIS/RTOS2/Include)
include_directories(mbed-os/cmsis/CMSIS_5/CMSIS/RTOS2)
include_directories(mbed-os/cmsis/CMSIS_5/CMSIS/RTOS2/RTX)
include_directories(mbed-os/cmsis/CMSIS_5/CMSIS/RTOS2/RTX/Include)
include_directories(mbed-os/cmsis/CMSIS_5/CMSIS/RTOS2/RTX/Include1)
include_directories(mbed-os/cmsis/CMSIS_5/CMSIS/TARGET_CORTEX_M/Include)
include_directories(BUILD)
include_directories(mbed-os/cmsis/device/rtos/include)
include_directories(mbed-os/drivers/usb/include/usb)
include_directories(targets/TARGET_BASE_MOBO_2_0)
include_directories(targets/TARGET_BASE_MOBO_Example)
include_directories(targets/TARGET_TLP_11PW_XIAOMI)
include_directories(targets)


get_directory_property(_inc_dirs INCLUDE_DIRECTORIES)
#message("_inc_dirs: ${_inc_dirs}")
file(GLOB_RECURSE sourcelist
        "base/*.h"
        "base/*.cpp"
        "targets/*.cpp"
        "targets/*.h"
        "mbed-os/drivers/*.h"
        "mbed-os/drivers/*.cpp"
        "mbed-os/platform/*.cpp"
        "mbed-os/platform/*.h"
        "mbed-os/rtos/*.h"
        "mbed-os/rtos/*.cpp"
        "mbed-os/storage/*.cpp"
        "mbed-os/storage/*.h"
        "mbed-os/events/*.h"
        "mbed-os/events/*.cpp"
        "mbed-os/cmsis/*.h"
        "mbed-os/cmsis/*.cpp"
        "mbed-os/events/*.h"
        "mbed-os/events/*.cpp"
        "mbed-os/hal/*.h"
        "mbed-os/hal/*.cpp"
        "drivers/*.h"
        "drivers/*.cpp"
        "drivers/*.hpp"
        )

file(GLOB small_list
        "*.cpp"
        "mbed-os/targets/TARGET_STM/*.h"
        "mbed-os/targets/TARGET_STM/*.cpp"
        "mbed-os/targets/TARGET_STM/*.c"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/*.cpp"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/*.c"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/*.h"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/*.cpp"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/*.c"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/*.h"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/STM32Cube_FW/STM32F7xx_HAL_Driver/*.cpp"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/STM32Cube_FW/STM32F7xx_HAL_Driver/*.h"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/STM32Cube_FW/STM32F7xx_HAL_Driver/*.c"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/TARGET_NUCLEO_F767ZI/*.cpp"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/TARGET_NUCLEO_F767ZI/*.c"
        "mbed-os/targets/TARGET_STM/TARGET_STM32F7/TARGET_STM32F767xI/TARGET_NUCLEO_F767ZI/*.h")

#message(STATUS "small list\n ${small_list}")



string(REGEX REPLACE "${RDIR}/" "" relative_sources "${sourcelist}")
#message(STATUS  " RELATIVE SOURCES \n ${relative_sources}")

string(REPLACE ";" "\n" sources_string "${relative_sources}")
#message(STATUS  " RELATIVE SOURCES WITH NEWLINE \n${sources_string}")
set(sources_string "set(sources\n${sources_string})")
#file(WRITE sources.cmake "${sources_string}")
#file(WRITE sources.cmake ${helloworld_SRC})

add_executable(pulser_firmware ${sourcelist} ${small_list} mbed-os/mbed.h )