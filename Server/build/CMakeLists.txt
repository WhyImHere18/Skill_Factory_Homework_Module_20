cmake_minimum_required(VERSION 3.0)

set(PROJECT Chat_server)

project(${PROJECT})

set(HEADERS
        /home/alex/SkillFactory/Homework_20/Server/source/Chat.h
        /home/alex/SkillFactory/Homework_20/Server/source/Server.h)
set(SOURCES
        /home/alex/SkillFactory/Homework_20/Server/source/main.cpp
        /home/alex/SkillFactory/Homework_20/Server/source/Chat.cpp)

add_executable(${PROJECT} ${HEADERS} ${SOURCES})
