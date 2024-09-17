# The name of the binary to be created.
TARGET = PSXDemo
# The type of the binary to be created - ps-exe is most common.
TYPE = ps-exe

# The list of sources files to compile within the binary.
SRCS = \
main.cpp \
GameApp.cpp \
SplashScene.cpp \
TitleScene.cpp \
TileMap.cpp \
TileMapScene.cpp \
Camera2D.cpp \
Demo3DScene.cpp \
Render3D.cpp \
Camera3D.cpp \
Sound.cpp \
System/SimpleCDAudio.cpp

# Setting the minimum version of the C++. C++-20 is the minimum required version by PSYQo.
CXXFLAGS = -std=c++20

# This will activate the PSYQo library and the rest of the toolchain.
include third_party/nugget/psyqo/psyqo.mk
