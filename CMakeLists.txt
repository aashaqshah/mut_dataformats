cmake_minimum_required(VERSION 2.8)
project(mut_dataformats)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_CXX_FLAGS "-O2 -std=c++1y -Wall")
set(CMAKE_SHARED_LINKER_FLAGS "")
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(ROOT REQUIRED)
include_directories("${ROOT_INCLUDE_DIR}")
link_directories("${ROOT_LIBRARY_DIR}")

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/interface")

ROOT_GENERATE_DICTIONARY(
  mut_dataformats_dict
  interface/EventInfo.h
  interface/Candidate.h
  interface/Lepton.h
  interface/Jet.h
  interface/MET.h
  LINKDEF interface/LinkDef.h
  )

file(GLOB mut_dataformat_src
    "src/*.cpp"
  )

add_library(
  mut_dataformats SHARED
  ${mut_dataformats_src}
  mut_dataformats_dict
  )

file(COPY "mut_dataformats_dict_rdict.pcm" DESTINATION "${CMAKE_SOURCE_DIR}/lib")

install(DIRECTORY interface DESTINATION "${CMAKE_INSTALL_PREFIX}/include")
install(TARGETS mut_dataformats DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES "mut_dataformats_dict_rdict.pcm" DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")


