# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\chuchelo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\chuchelo_autogen.dir\\ParseCache.txt"
  "chuchelo_autogen"
  )
endif()
