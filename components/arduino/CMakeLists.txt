# Check ESP-IDF version and error out if it is not in the supported range.
#
# Note for arduino-esp32 developers: to bypass the version check locally,
# set ARDUINO_SKIP_IDF_VERSION_CHECK environment variable to 1. For example:
#   export ARDUINO_SKIP_IDF_VERSION_CHECK=1
#   idf.py build

set(min_supported_idf_version "4.4.0")
set(max_supported_idf_version "4.4.99")
set(idf_version "${IDF_VERSION_MAJOR}.${IDF_VERSION_MINOR}.${IDF_VERSION_PATCH}")

if ("${idf_version}" AND NOT "$ENV{ARDUINO_SKIP_IDF_VERSION_CHECK}")
  if (idf_version VERSION_LESS min_supported_idf_version)
    message(FATAL_ERROR "Arduino-esp32 can be used with ESP-IDF versions "
                        "between ${min_supported_idf_version} and ${max_supported_idf_version}, "
                        "but an older version is detected: ${idf_version}.")
  endif()
  if (idf_version VERSION_GREATER max_supported_idf_version)
    message(FATAL_ERROR "Arduino-esp32 can be used with ESP-IDF versions "
                        "between ${min_supported_idf_version} and ${max_supported_idf_version}, "
                        "but a newer version is detected: ${idf_version}.")
  endif()
endif()

set(CORE_SRCS
  cores/esp32/base64.cpp
  cores/esp32/cbuf.cpp
  cores/esp32/esp32-hal-adc.c
  cores/esp32/esp32-hal-bt.c
  cores/esp32/esp32-hal-cpu.c
  cores/esp32/esp32-hal-dac.c
  cores/esp32/esp32-hal-gpio.c
  cores/esp32/esp32-hal-i2c.c
  cores/esp32/esp32-hal-i2c-slave.c
  cores/esp32/esp32-hal-ledc.c
  cores/esp32/esp32-hal-matrix.c
  cores/esp32/esp32-hal-misc.c
  cores/esp32/esp32-hal-psram.c
  cores/esp32/esp32-hal-rgb-led.c
  cores/esp32/esp32-hal-sigmadelta.c
  cores/esp32/esp32-hal-spi.c
  cores/esp32/esp32-hal-time.c
  cores/esp32/esp32-hal-timer.c
  cores/esp32/esp32-hal-tinyusb.c
  cores/esp32/esp32-hal-touch.c
  cores/esp32/esp32-hal-uart.c
  cores/esp32/esp32-hal-rmt.c
  cores/esp32/Esp.cpp
  cores/esp32/FunctionalInterrupt.cpp
  cores/esp32/HardwareSerial.cpp
  cores/esp32/IPAddress.cpp
  cores/esp32/IPv6Address.cpp
  cores/esp32/libb64/cdecode.c
  cores/esp32/libb64/cencode.c
  cores/esp32/main.cpp
  cores/esp32/MD5Builder.cpp
  cores/esp32/Print.cpp
  cores/esp32/stdlib_noniso.c
  cores/esp32/Stream.cpp
  cores/esp32/StreamString.cpp
  cores/esp32/Tone.cpp
  cores/esp32/HWCDC.cpp
  cores/esp32/USB.cpp
  cores/esp32/USBCDC.cpp
  cores/esp32/USBMSC.cpp
  cores/esp32/FirmwareMSC.cpp
  cores/esp32/firmware_msc_fat.c
  cores/esp32/wiring_pulse.c
  cores/esp32/wiring_shift.c
  cores/esp32/WMath.cpp
  cores/esp32/WString.cpp
  )

set(LIBRARY_SRCS
  libraries/ArduinoOTA/src/ArduinoOTA.cpp
  libraries/AsyncUDP/src/AsyncUDP.cpp
  libraries/BluetoothSerial/src/BluetoothSerial.cpp
  libraries/BluetoothSerial/src/BTAddress.cpp
  libraries/BluetoothSerial/src/BTAdvertisedDeviceSet.cpp
  libraries/BluetoothSerial/src/BTScanResultsSet.cpp
  libraries/DNSServer/src/DNSServer.cpp
  libraries/EEPROM/src/EEPROM.cpp
  libraries/ESPmDNS/src/ESPmDNS.cpp
  libraries/Ethernet/src/ETH.cpp
  libraries/FFat/src/FFat.cpp
  libraries/FS/src/FS.cpp
  libraries/ArduinoNvs/src/ArduinoNvs.cpp
  libraries/WiFiManager/WiFiManager.cpp

  libraries/ir_Toshiba/src/ir_Toshiba.cpp
  libraries/IRrecv/src/IRrecv.cpp
  libraries/IRsend/src/IRsend.cpp
  libraries/IRtext/src/IRtext.cpp
  libraries/IRtimer/src/IRtimer.cpp
  libraries/IRutils/src/IRutils.cpp
  libraries/ir_Whynter/src/ir_Whynter.cpp
  libraries/ir_Whirlpool/src/ir_Whirlpool.cpp
  libraries/ir_Voltas/src/ir_Voltas.cpp
  libraries/ir_Vestel/src/ir_Vestel.cpp
  libraries/ir_Truma/src/ir_Truma.cpp
  libraries/ir_Trotec/src/ir_Trotec.cpp
  libraries/ir_Transcold/src/ir_Transcold.cpp
  libraries/ir_Technibel/src/ir_Technibel.cpp
  libraries/ir_Tcl/src/ir_Tcl.cpp
  libraries/ir_Symphony/src/ir_Symphony.cpp
  libraries/ir_Sony/src/ir_Sony.cpp
  libraries/ir_Sharp/src/ir_Sharp.cpp
  libraries/ir_Sanyo/src/ir_Sanyo.cpp
  libraries/ir_Samsung/src/ir_Samsung.cpp
  libraries/ir_Rhoss/src/ir_Rhoss.cpp
  libraries/ir_RCMM/src/ir_RCMM.cpp
  libraries/ir_RC5_RC6/src/ir_RC5_RC6.cpp
  libraries/ir_Panasonic/src/ir_Panasonic.cpp
  libraries/ir_Nikai/src/ir_Nikai.cpp
  libraries/ir_Neoclima/src/ir_Neoclima.cpp
  libraries/ir_MitsubishiHeavy/src/ir_MitsubishiHeavy.cpp
  libraries/ir_NEC/src/ir_NEC.cpp
  libraries/ir_Mitsubishi/src/ir_Mitsubishi.cpp
  libraries/ir_LG/src/ir_LG.cpp
  libraries/ir_JVC/src/ir_JVC.cpp
  libraries/ir_Fujitsu/src/ir_Fujitsu.cpp
  libraries/ir_Aiwa/src/ir_Aiwa.cpp
  libraries/IRac/src/IRac.cpp
  libraries/ir_Teco/src/ir_Teco.cpp
  libraries/ir_Airton/src/ir_Airton.cpp
  libraries/ir_Airwell/src/ir_Airwell.cpp
  libraries/ir_Amcor/src/ir_Amcor.cpp
  libraries/ir_Argo/src/ir_Argo.cpp
  libraries/ir_Arris/src/ir_Arris.cpp
  libraries/ir_Bosch/src/ir_Bosch.cpp
  libraries/ir_Bose/src/ir_Bose.cpp
  libraries/ir_Carrier/src/ir_Carrier.cpp
  libraries/ir_ClimaButler/src/ir_ClimaButler.cpp
  libraries/ir_Coolix/src/ir_Coolix.cpp
  libraries/ir_Corona/src/ir_Corona.cpp
  libraries/ir_Daikin/src/ir_Daikin.cpp
  libraries/ir_Delonghi/src/ir_Delonghi.cpp
  libraries/ir_Denon/src/ir_Denon.cpp
  libraries/ir_Dish/src/ir_Dish.cpp
  libraries/ir_Doshisha/src/ir_Doshisha.cpp
  libraries/ir_Ecoclim/src/ir_Ecoclim.cpp
  libraries/ir_Electra/src/ir_Electra.cpp
  libraries/ir_EliteScreens/src/ir_EliteScreens.cpp
  libraries/ir_Epson/src/ir_Epson.cpp
  libraries/ir_GICable/src/ir_GICable.cpp
  libraries/ir_GlobalCache/src/ir_GlobalCache.cpp
  libraries/ir_Goodweather/src/ir_Goodweather.cpp
  libraries/ir_Gorenje/src/ir_Gorenje.cpp
  libraries/ir_Gree/src/ir_Gree.cpp
  libraries/ir_Haier/src/ir_Haier.cpp
  libraries/ir_Hitachi/src/ir_Hitachi.cpp
  libraries/ir_Inax/src/ir_Inax.cpp
  libraries/ir_Kelon/src/ir_Kelon.cpp
  libraries/ir_Kelvinator/src/ir_Kelvinator.cpp
  libraries/ir_Lasertag/src/ir_Lasertag.cpp
  libraries/ir_Lego/src/ir_Lego.cpp
  libraries/ir_Lutron/src/ir_Lutron.cpp
  libraries/ir_Magiquest/src/ir_Magiquest.cpp
  libraries/ir_Metz/src/ir_Metz.cpp
  libraries/ir_Midea/src/ir_Midea.cpp
  libraries/ir_MilesTag2/src/ir_MilesTag2.cpp
  libraries/ir_Mirage/src/ir_Mirage.cpp
  libraries/ir_Multibrackets/src/ir_Multibrackets.cpp
  libraries/ir_MWM/src/ir_MWM.cpp
  libraries/ir_Pioneer/src/ir_Pioneer.cpp
  libraries/ir_Pronto/src/ir_Pronto.cpp
  libraries/ir_Sherwood/src/ir_Sherwood.cpp
  libraries/ir_Teknopoint/src/ir_Teknopoint.cpp
  libraries/ir_Toto/src/ir_Toto.cpp
  libraries/ir_Wowwee/src/ir_Wowwee.cpp
  libraries/ir_Xmp/src/ir_Xmp.cpp
  libraries/ir_Zepeal/src/ir_Zepeal.cpp











  libraries/FS/src/vfs_api.cpp
  libraries/HTTPClient/src/HTTPClient.cpp
  libraries/HTTPUpdate/src/HTTPUpdate.cpp
  libraries/LittleFS/src/LittleFS.cpp
  libraries/Insights/src/Insights.cpp
  libraries/I2S/src/I2S.cpp
  libraries/NetBIOS/src/NetBIOS.cpp
  libraries/Preferences/src/Preferences.cpp
  libraries/RainMaker/src/RMaker.cpp
  libraries/RainMaker/src/RMakerNode.cpp
  libraries/RainMaker/src/RMakerParam.cpp
  libraries/RainMaker/src/RMakerDevice.cpp
  libraries/RainMaker/src/RMakerType.cpp
  libraries/RainMaker/src/RMakerQR.cpp
  libraries/RainMaker/src/RMakerUtils.cpp
  libraries/SD_MMC/src/SD_MMC.cpp
  libraries/SD/src/SD.cpp
  libraries/SD/src/sd_diskio.cpp
  libraries/SD/src/sd_diskio_crc.c
  libraries/SimpleBLE/src/SimpleBLE.cpp
  libraries/SPIFFS/src/SPIFFS.cpp
  libraries/SPI/src/SPI.cpp
  libraries/Ticker/src/Ticker.cpp
  libraries/Update/src/Updater.cpp
  libraries/Update/src/HttpsOTAUpdate.cpp
  libraries/USB/src/USBHID.cpp
  libraries/USB/src/USBHIDMouse.cpp
  libraries/USB/src/USBHIDKeyboard.cpp
  libraries/USB/src/USBHIDGamepad.cpp
  libraries/USB/src/USBHIDConsumerControl.cpp
  libraries/USB/src/USBHIDSystemControl.cpp
  libraries/USB/src/USBHIDVendor.cpp
  libraries/USB/src/USBVendor.cpp
  libraries/WebServer/src/WebServer.cpp
  libraries/WebServer/src/Parsing.cpp
  libraries/WebServer/src/detail/mimetable.cpp
  libraries/WiFiClientSecure/src/ssl_client.cpp
  libraries/WiFiClientSecure/src/esp_crt_bundle.c
  libraries/WiFiClientSecure/src/WiFiClientSecure.cpp
  libraries/WiFi/src/WiFiAP.cpp
  libraries/WiFi/src/WiFiClient.cpp
  libraries/WiFi/src/WiFi.cpp
  libraries/WiFi/src/WiFiGeneric.cpp
  libraries/WiFi/src/WiFiMulti.cpp
  libraries/WiFi/src/WiFiScan.cpp
  libraries/WiFi/src/WiFiServer.cpp
  libraries/WiFi/src/WiFiSTA.cpp
  libraries/WiFi/src/WiFiUdp.cpp
  libraries/WiFiProv/src/WiFiProv.cpp
  libraries/Wire/src/Wire.cpp
  )

set(BLE_SRCS
  libraries/BLE/src/BLE2902.cpp
  libraries/BLE/src/BLE2904.cpp
  libraries/BLE/src/BLEAddress.cpp
  libraries/BLE/src/BLEAdvertisedDevice.cpp
  libraries/BLE/src/BLEAdvertising.cpp
  libraries/BLE/src/BLEBeacon.cpp
  libraries/BLE/src/BLECharacteristic.cpp
  libraries/BLE/src/BLECharacteristicMap.cpp
  libraries/BLE/src/BLEClient.cpp
  libraries/BLE/src/BLEDescriptor.cpp
  libraries/BLE/src/BLEDescriptorMap.cpp
  libraries/BLE/src/BLEDevice.cpp
  libraries/BLE/src/BLEEddystoneTLM.cpp
  libraries/BLE/src/BLEEddystoneURL.cpp
  libraries/BLE/src/BLEExceptions.cpp
  libraries/BLE/src/BLEHIDDevice.cpp
  libraries/BLE/src/BLERemoteCharacteristic.cpp
  libraries/BLE/src/BLERemoteDescriptor.cpp
  libraries/BLE/src/BLERemoteService.cpp
  libraries/BLE/src/BLEScan.cpp
  libraries/BLE/src/BLESecurity.cpp
  libraries/BLE/src/BLEServer.cpp
  libraries/BLE/src/BLEService.cpp
  libraries/BLE/src/BLEServiceMap.cpp
  libraries/BLE/src/BLEUtils.cpp
  libraries/BLE/src/BLEUUID.cpp
  libraries/BLE/src/BLEValue.cpp
  libraries/BLE/src/FreeRTOS.cpp
  libraries/BLE/src/GeneralUtils.cpp
  )

set(includedirs
  variants/${CONFIG_ARDUINO_VARIANT}/
  cores/esp32/
  libraries/ArduinoOTA/src
  libraries/AsyncUDP/src
  libraries/BLE/src
  libraries/BluetoothSerial/src
  libraries/DNSServer/src
  libraries/EEPROM/src
  libraries/ESP32/src
  libraries/ESPmDNS/src
  libraries/Ethernet/src
  libraries/FFat/src
  libraries/FS/src
  libraries/HTTPClient/src
  libraries/HTTPUpdate/src
  libraries/LittleFS/src
  libraries/Insights/src
  libraries/I2S/src
libraries/ArduinoNvs/src
libraries/WiFiManager

  libraries/ir_Toshiba/src
  libraries/IRrecv/src
  libraries/IRsend/src
  libraries/IRtext/src
  libraries/IRtimer/src
  libraries/IRutils/src
  libraries/IRremoteESP8266/src
  libraries/ir_Whynter/src
  libraries/ir_Whirlpool/src
  libraries/ir_Voltas/src
  libraries/ir_Vestel/src
  libraries/ir_Truma/src
  libraries/ir_Trotec/src
  libraries/ir_Transcold/src
  libraries/ir_Technibel/src
  libraries/ir_Tcl/src
  libraries/ir_Symphony/src
  libraries/ir_Sony/src
  libraries/ir_Sharp/src
  libraries/ir_Sanyo/src
  libraries/ir_Samsung/src
  libraries/ir_Rhoss/src
  libraries/ir_RCMM/src
  libraries/ir_RC5_RC6/src
  libraries/ir_Panasonic/src
  libraries/ir_Nikai/src
  libraries/ir_Neoclima/src
  libraries/ir_MitsubishiHeavy/src
  libraries/ir_NEC/src
  libraries/ir_Mitsubishi/src
  libraries/ir_LG/src
  libraries/ir_JVC/src
  libraries/ir_Fujitsu/src
  libraries/ir_Aiwa/src
  libraries/IRac/src
  libraries/ir_Teco/src
  libraries/ir_Airton/src
  libraries/ir_Airwell/src
  libraries/ir_Amcor/src
  libraries/ir_Argo/src
  libraries/ir_Arris/src
  libraries/ir_Bosch/src
  libraries/ir_Bose/src
  libraries/ir_Carrier/src
  libraries/ir_ClimaButler/src
  libraries/ir_Coolix/src
  libraries/ir_Corona/src
  libraries/ir_Daikin/src
  libraries/ir_Delonghi/src
  libraries/ir_Denon/src
  libraries/ir_Dish/src
  libraries/ir_Doshisha/src
  libraries/ir_Ecoclim/src
  libraries/ir_Electra/src
  libraries/ir_EliteScreens/src
  libraries/ir_Epson/src
  libraries/ir_GICable/src
  libraries/ir_GlobalCache/src
  libraries/ir_Goodweather/src
  libraries/ir_Gorenje/src
  libraries/ir_Gree/src
  libraries/ir_Haier/src
  libraries/ir_Hitachi/src
  libraries/ir_Inax/src
  libraries/ir_Kelon/src
  libraries/ir_Kelvinator/src
  libraries/ir_Lasertag/src
  libraries/ir_Lego/src
  libraries/ir_Lutron/src
  libraries/ir_Magiquest/src
  libraries/ir_Metz/src
  libraries/ir_Midea/src
  libraries/ir_MilesTag2/src
  libraries/ir_Mirage/src
  libraries/ir_Multibrackets/src
  libraries/ir_MWM/src
  libraries/ir_Pioneer/src
  libraries/ir_Pronto/src
  libraries/ir_Sherwood/src
  libraries/ir_Teknopoint/src
  libraries/ir_Toto/src
  libraries/ir_Wowwee/src
  libraries/ir_Xmp/src
  libraries/ir_Zepeal/src



  libraries/NetBIOS/src
  libraries/Preferences/src
  libraries/RainMaker/src
  libraries/SD_MMC/src
  libraries/SD/src
  libraries/SimpleBLE/src
  libraries/SPIFFS/src
  libraries/SPI/src
  libraries/Ticker/src
  libraries/Update/src
  libraries/USB/src
  libraries/WebServer/src
  libraries/WiFiClientSecure/src
  libraries/WiFi/src
  libraries/WiFiProv/src
  libraries/Wire/src
  )

set(srcs ${CORE_SRCS} ${LIBRARY_SRCS} ${BLE_SRCS})
set(priv_includes cores/esp32/libb64)
set(requires spi_flash mbedtls mdns esp_adc_cal wifi_provisioning nghttp wpa_supplicant)
set(priv_requires fatfs nvs_flash app_update spiffs bootloader_support openssl bt esp_ipc esp_hid)

idf_component_register(INCLUDE_DIRS ${includedirs} PRIV_INCLUDE_DIRS ${priv_includes} SRCS ${srcs} REQUIRES ${requires} PRIV_REQUIRES ${priv_requires})

if(NOT CONFIG_FREERTOS_HZ EQUAL 100 AND NOT "$ENV{ARDUINO_SKIP_TICK_CHECK}")
    # See delay() in cores/esp32/esp32-hal-misc.c.
    message(FATAL_ERROR "esp32-arduino requires CONFIG_FREERTOS_HZ=100 "
                        "(currently ${CONFIG_FREERTOS_HZ})")
endif()

string(TOUPPER ${CONFIG_ARDUINO_VARIANT} idf_target_caps)
string(REPLACE "-" "_" idf_target_for_macro "${idf_target_caps}")
target_compile_options(${COMPONENT_TARGET} PUBLIC
    -DARDUINO=10812
    -DARDUINO_${idf_target_for_macro}_DEV
    -DARDUINO_ARCH_ESP32
    -DARDUINO_BOARD="${idf_target_caps}_DEV"
    -DARDUINO_VARIANT="${CONFIG_ARDUINO_VARIANT}"
    -DESP32)

if(CONFIG_AUTOSTART_ARDUINO)
    # in autostart mode, arduino-esp32 contains app_main() function and needs to
    # reference setup() and loop() in the main component. If we add main
    # component to priv_requires then we create a large circular dependency
    # (arduino-esp32 -> main -> arduino-esp32) and can get linker errors, so
    # instead we add setup() and loop() to the undefined symbols list so the
    # linker will always include them.
    #
    # (As they are C++ symbol, we need to add the C++ mangled names.)
    target_link_libraries(${COMPONENT_LIB} INTERFACE "-u _Z5setupv -u _Z4loopv")
endif()

# This function adds a dependency on the given component if the component is included into the build.
function(maybe_add_component component_name)
    idf_build_get_property(components BUILD_COMPONENTS)
    if (${component_name} IN_LIST components)
        idf_component_get_property(lib_name ${component_name} COMPONENT_LIB)
        target_link_libraries(${COMPONENT_LIB} PUBLIC ${lib_name})
    endif()
endfunction()

maybe_add_component(esp-dsp)

if(CONFIG_ESP_RMAKER_WORK_QUEUE_TASK_STACK)
    maybe_add_component(esp_rainmaker)
    maybe_add_component(qrcode)
endif()
if(IDF_TARGET MATCHES "esp32s2|esp32s3" AND CONFIG_TINYUSB_ENABLED)
    maybe_add_component(arduino_tinyusb)
endif()
if(NOT CONFIG_ARDUINO_SELECTIVE_COMPILATION OR CONFIG_ARDUINO_SELECTIVE_ArduinoOTA)
    maybe_add_component(esp_https_ota)
endif()
if(NOT CONFIG_ARDUINO_SELECTIVE_COMPILATION OR CONFIG_ARDUINO_SELECTIVE_LITTLEFS)
    maybe_add_component(esp_littlefs)
endif()
