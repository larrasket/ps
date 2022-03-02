cmake_minimum_required(VERSION 3.22)
project(Lists)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lists
        ArrayList.h
        Link.h
        LinkedList.h
        List.h
        Lists.cpp DoubleLink.h DoublyLinkedList.h)
