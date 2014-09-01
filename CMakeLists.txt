# ------------------------------------------------------------------------------
# Copyright by Uwe Arzt mailto:mail@uwe-arzt.de, https://uwe-arzt.de
# under BSD License, see https://uwe-arzt.de/bsd-license/
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# set the arm toolchain
set(CMAKE_TOOLCHAIN_FILE mbed-cmake/arm_toolchain.cmake)

cmake_minimum_required(VERSION 3.0.1)

project (BlinkLed C CXX ASM)

# ------------------------------------------------------------------------------
# set the target processor and include settings for cmake

set(MBED_TARGET LPC1768)
#set(MBED_TARGET LPC11U24)
#set(MBED_TARGET RBLAB_NRF51822)

# ------------------------------------------------------------------------------
# will add the include dirs and link the lib
#set(USE_RTOS true)
#set(USE_NET true)
#set(USE_USB true)
#set(USE_DSP true)

# ------------------------------------------------------------------------------
# for installing an serial console
set(MBEDMOUNT /Volumes/MBED)
set(SERCON /dev/tty.usbmodem1442)


# ------------------------------------------------------------------------------
# build the executable
set(BLINKLED_SRC
  example/BlinkLed.cpp
)

set(BIN
  BlinkLed
)

include(mbed-cmake/arm_mbed.cmake)

# ------------------------------------------------------------------------------
# build the executable
add_executable(${BIN} ${BLINKLED_SRC} ${MBED_OBJECTS})
target_link_libraries(${BIN} ${MBED_LIBS})
