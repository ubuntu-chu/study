# Install script for directory: /home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/ibus-googlepinyin/main.py")
FILE(INSTALL DESTINATION "/usr/share/ibus-googlepinyin" TYPE PROGRAM FILES "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/main.py")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/ibus-googlepinyin/engine.py;/usr/share/ibus-googlepinyin/factory.py;/usr/share/ibus-googlepinyin/libopencc.py;/usr/share/ibus-googlepinyin/googlepinyin.py")
FILE(INSTALL DESTINATION "/usr/share/ibus-googlepinyin" TYPE FILE FILES
    "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/engine.py"
    "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/factory.py"
    "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/libopencc.py"
    "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/googlepinyin.py"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/ibus/component/googlepinyin.xml")
FILE(INSTALL DESTINATION "/usr/share/ibus/component" TYPE FILE FILES "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/build/googlepinyin.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/ibus-googlepinyin/icons/")
FILE(INSTALL DESTINATION "/usr/share/ibus-googlepinyin/icons" TYPE DIRECTORY FILES "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/icons/")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/barnard/repository_study/boost/shared_ptr/shared_from_this/ibus-googlepinyin/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
