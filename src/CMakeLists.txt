include_directories(${libreplaygain_SOURCE_DIR}/include)

add_library(replaygain-static STATIC gain_analysis)
set_target_properties(replaygain-static PROPERTIES OUTPUT_NAME replaygain CLEAN_DIRECT_OUTPUT 1)

add_library(replaygain-shared SHARED gain_analysis)
set_target_properties(replaygain-shared PROPERTIES OUTPUT_NAME replaygain CLEAN_DIRECT_OUTPUT 1 VERSION 1.0.0 SOVERSION 1)

install(TARGETS replaygain-static replaygain-shared LIBRARY DESTINATION "lib${LIB_SUFFIX}" ARCHIVE DESTINATION "lib${LIB_SUFFIX}" COMPONENT libraries)

install(FILES ${libreplaygain_SOURCE_DIR}/include/replaygain/gain_analysis.h DESTINATION include/replaygain COMPONENT headers)
