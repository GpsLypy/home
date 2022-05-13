# Install script for directory: /home/muduo/muduo/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/build/release-install-cpp11")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/build/release-cpp11/lib/libmuduo_base.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/base" TYPE FILE FILES
    "/home/muduo/muduo/base/AsyncLogging.h"
    "/home/muduo/muduo/base/Atomic.h"
    "/home/muduo/muduo/base/BlockingQueue.h"
    "/home/muduo/muduo/base/BoundedBlockingQueue.h"
    "/home/muduo/muduo/base/Condition.h"
    "/home/muduo/muduo/base/CountDownLatch.h"
    "/home/muduo/muduo/base/CurrentThread.h"
    "/home/muduo/muduo/base/Date.h"
    "/home/muduo/muduo/base/Exception.h"
    "/home/muduo/muduo/base/FileUtil.h"
    "/home/muduo/muduo/base/GzipFile.h"
    "/home/muduo/muduo/base/LogFile.h"
    "/home/muduo/muduo/base/LogStream.h"
    "/home/muduo/muduo/base/Logging.h"
    "/home/muduo/muduo/base/Mutex.h"
    "/home/muduo/muduo/base/ProcessInfo.h"
    "/home/muduo/muduo/base/Singleton.h"
    "/home/muduo/muduo/base/StringPiece.h"
    "/home/muduo/muduo/base/Thread.h"
    "/home/muduo/muduo/base/ThreadLocal.h"
    "/home/muduo/muduo/base/ThreadLocalSingleton.h"
    "/home/muduo/muduo/base/ThreadPool.h"
    "/home/muduo/muduo/base/TimeZone.h"
    "/home/muduo/muduo/base/Timestamp.h"
    "/home/muduo/muduo/base/Types.h"
    "/home/muduo/muduo/base/WeakCallback.h"
    "/home/muduo/muduo/base/copyable.h"
    "/home/muduo/muduo/base/noncopyable.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/build/release-cpp11/muduo/base/tests/cmake_install.cmake")

endif()

