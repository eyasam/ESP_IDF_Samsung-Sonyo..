# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/eyasa/esp/esp-idf/components/bootloader/subproject"
  "C:/Users/eyasa/OneDrive/Documents/ESP/3_AC_ESP_IDF-main/build/bootloader"
  "C:/Users/eyasa/OneDrive/Documents/ESP/3_AC_ESP_IDF-main/build/bootloader-prefix"
  "C:/Users/eyasa/OneDrive/Documents/ESP/3_AC_ESP_IDF-main/build/bootloader-prefix/tmp"
  "C:/Users/eyasa/OneDrive/Documents/ESP/3_AC_ESP_IDF-main/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/eyasa/OneDrive/Documents/ESP/3_AC_ESP_IDF-main/build/bootloader-prefix/src"
  "C:/Users/eyasa/OneDrive/Documents/ESP/3_AC_ESP_IDF-main/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/eyasa/OneDrive/Documents/ESP/3_AC_ESP_IDF-main/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
