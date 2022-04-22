cmake_minimum_required(VERSION 3.22)
set(PROJECT_NAME main)			# Установка переменной со списком исходников
project(${PROJECT_NAME})				# Название проекта
set(SOURCE_EXE main.cpp 
        headers/mics/Books.hpp sourse/mics/Books.cpp 
        headers/mics/FileTXT.hpp sourse/mics/FileTXT.cpp
        headers/mics/exception.hpp sourse/mics/exception.cpp 
        headers/mics/virtualClass.hpp sourse/mics/virtualClass.cpp
        headers/gui/windows/window.hpp sourse/gui/windows/window.cpp
        headers/gui/mics/rectCorner.hpp sourse/gui/mics/rectCorner.cpp
        headers/mics/BitmapHelper.hpp sourse/mics/BitmapHelper.cpp
        headers/gui/buttons.hpp sourse/gui/buttons.cpp
        headers/mics/helper.hpp sourse/mics/helper.cpp
)	
set (GDI_HEADERS "C:/MinGW/include/gdiplus")
set (GDI_LIBS "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x86")
set(LIBRARIES gdiplus)
#C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um
add_executable(${PROJECT_NAME}  ${SOURCE_EXE})	# Создает исполняемый файл с именем main
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

