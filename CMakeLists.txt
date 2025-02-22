cmake_minimum_required(VERSION 3.10)
project(TodoC)

set(CMAKE_CXX_STANDARD 17)

# Locate SQLite
find_package(SQLite3 REQUIRED)

# Add executable
add_executable(todo-c src/main.cpp)
target_link_libraries(todo-c PRIVATE SQLite::SQLite3)

# Define install directories
install(TARGETS todo-c DESTINATION bin)
install(FILES database/database.db DESTINATION database)

# Windows: Include SQLite DLL in installer
if(WIN32)
    install(FILES ${CMAKE_SOURCE_DIR}/bin/sqlite3.dll DESTINATION bin)
endif()

# Linux: Auto-install SQLite if missing
# if(UNIX)
#     install(CODE "
#         if(EXISTS /etc/arch-release)
#             execute_process(COMMAND sudo pacman -S --noconfirm sqlite)
#         elseif(EXISTS /etc/debian_version)
#             execute_process(COMMAND sudo apt-get install -y sqlite3)
#         endif()
#     ")
# endif()

# CPack Configuration
set(CPACK_PACKAGE_NAME "TodoC")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_VENDOR "GiorgiSoft")
set(CPACK_GENERATOR "NSIS;ZIP")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Todo with C++")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "TodoC")

# Windows NSIS Installer settings
if(WIN32)
    set(CPACK_NSIS_DISPLAY_NAME "TodoC Installer")
    set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
    set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/icon.ico")
endif()

include(CPack)
