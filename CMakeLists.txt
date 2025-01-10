cmake_minimum_required(VERSION 3.10.0)
project(KalNet VERSION 0.1.0 LANGUAGES C CXX)

add_library(KalNet ClientSocket.cpp KalNet.cpp KalServer.cpp ServerSocket.cpp SocketHandler.cpp WSAinitializer.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
