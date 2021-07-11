cmake_minimum_required( VERSION "3.20.0" )

project( HelloCPP20 VERSION 1.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED TRUE )

set( Boost_USE_RELEASAE_LIBS ON )
set( Boost_USE_MULTITHREADED ON )
set( Boost_USE_STATIC_LIBS ON )
set( Boost_USE_RUNTIME ON )

find_package( Boost REQUIRED COMPONENTS program_options system filesystem )
find_package( fmt CONFIG REQUIRED )
find_package( date REQUIRED )

set( EXECUTABLE_OUT_NAME main.out )

add_executable( ${EXECUTABLE_OUT_NAME} 
    main.cpp
)

target_include_directories( ${EXECUTABLE_OUT_NAME} 
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)

target_link_libraries( ${EXECUTABLE_OUT_NAME}
    PRIVATE
    Boost::filesystem
    Boost::program_options
    date::date
    fmt::fmt 
)

if ( UNIX )
    set_target_properties( ${EXECUTABLE_NAME} PROPERTIES LINK_FLAGS "-no-pie" )
endif()
