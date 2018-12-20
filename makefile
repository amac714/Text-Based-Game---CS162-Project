#
#
#
#
#@file - Final Project makefile
#@author - Alan Macabuhay
#@description - builds Final Project
#
#
#


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g


SRCS = ChampRoom.cpp BlackRoom.cpp PurpleRoom.cpp OrangeRoom.cpp YellowRoom.cpp Door.cpp Game.cpp Room.cpp Player.cpp
SRCS += MainHall.cpp YellowTrainer.cpp YellowMaster.cpp OrangeTrainer.cpp OrangeMaster.cpp PurpleTrainer.cpp 
SRCS += Champion.cpp PurpleMaster.cpp BlackTrainer.cpp BlackMaster.cpp main.cpp Short.cpp

HEADERS = ChampRoom.hpp BlackRoom.hpp PurpleRoom.hpp OrangeRoom.hpp YellowRoom.hpp Door.hpp Game.hpp Room.hpp Player.hpp
HEADERS += MainHall.hpp YellowTrainer.hpp YellowMaster.hpp OrangeTrainer.hpp OrangeMaster.hpp PurpleTrainer.hpp
HEADERS += Champion.hpp PurpleMaster.hpp BlackTrainer.hpp BlackMaster.hpp Short.hpp

Final: ${OBJS} ${HEADERS} 
			${CXX} ${CXXFLAGS} ${SRCS} -o final

clean:
	rm -f final final.o
