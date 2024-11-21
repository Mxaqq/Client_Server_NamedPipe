# Создать цель server
add_executable(ServerApp main.cpp)

# Подключить библиотеку
target_link_libraries(ServerApp NamedPipeLibrary)

# Указать путь к заголовочным файлам
target_include_directories(ServerApp PRIVATE ${PROJECT_SOURCE_DIR}/NamedPipeLibrary/include)