cmake_minimum_required(VERSION 3.16)
project(Parcial2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Parcial2 main.cpp Lista.h Nodo.h Scheduler.h Scheduler.cpp Clock.cpp Clock.h Event.cpp Event.h ScheList.cpp ScheList.h ScheHS.h ScheHS.cpp ScheBH.cpp ScheBH.h BinomialHeap.h)