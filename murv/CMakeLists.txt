cmake_minimum_required(VERSION 3.0)

project(Murv)
#version number
set(Murv_VERSION_MAJOR 1)
set(Murv_VERSION_MINOR 0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(
	Murv
	Murv.cxx
	Murv.hxx
	Map.h
	Map.cxx
	TextureManager.cxx
	TextureManager.h
	MurvCore.cxx
	MurvCore.hxx
)