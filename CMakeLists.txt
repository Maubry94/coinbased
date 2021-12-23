cmake_minimum_required(VERSION 3.12)
project(test C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall")
include_directories("C:/wamp64/bin/mariadb/mariadb10.6.5/include")
link_directories("C:/wamp64/bin/mariadb/mariadb10.6.5/lib")
link_libraries(libmariadb)
add_executable(test main.c)
target_link_libraries(test libmariadb)

# les fichiers libmariadb.dll et libmariadb.lib sont copiés de
# C:\wamp64\bin\mariadb\mariadb10.6.5\lib
# dans le dossier de compilation
# C:\Users\fredguy\CLionProjects\test\cmake-build-debug\