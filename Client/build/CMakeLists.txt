cmake_minimum_required(VERSION 3.0)

set(PROJECT Chat_client)

project(${PROJECT})

set(HEADERS
        /home/alex/SkillFactory/Homework_20/Client/source/Chat.h
        /home/alex/SkillFactory/Homework_20/Client/source/Client.h)
set(SOURCES
        /home/alex/SkillFactory/Homework_20/Client/source/main.cpp
        /home/alex/SkillFactory/Homework_20/Client/source/Chat.cpp)

add_executable(${PROJECT} ${HEADERS} ${SOURCES})
