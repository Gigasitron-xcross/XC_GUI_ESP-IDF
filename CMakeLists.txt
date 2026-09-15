idf_component_register(
    INCLUDE_DIRS "include"
    REQUIRES
        esp_driver_spi
        esp_driver_gpio
        freertos
)

set(XC_GUI_LIB
    "${CMAKE_CURRENT_LIST_DIR}/lib/${IDF_TARGET}/libxc_gui.a"
)

if(NOT EXISTS "${XC_GUI_LIB}")
    message(FATAL_ERROR
        "XC_GUI does not support target ${IDF_TARGET}"
    )
endif()

add_prebuilt_library(
    xc_gui_prebuilt
    "${XC_GUI_LIB}"
    REQUIRES
        esp_driver_spi
        esp_driver_gpio
        freertos
)

target_link_libraries(
    ${COMPONENT_LIB}
    INTERFACE
    xc_gui_prebuilt
)