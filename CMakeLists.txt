cmake_minimum_required(VERSION 3.16)
project(ff)

add_executable(ff main.c)

# Stuff only for WIN32
if (WIN32 OR WIN64)
    target_sources(ff
        PRIVATE recSearchWin.c
        PUBLIC recSearch.h
    )
else()
target_sources(ff
        PRIVATE recSearchLinux.c
        PUBLIC recSearch.h
    )
endif()


set_target_properties(ff PROPERTIES OUTPUT_NAME "ff")
