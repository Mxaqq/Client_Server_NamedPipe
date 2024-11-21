# Создать цель client
add_executable(ClientApp main.cpp)

# Подключить библиотеку
target_link_libraries(ClientApp NamedPipeLibrary)

# Указать путь к заголовочным файлам
target_include_directories(ClientApp PRIVATE ${PROJECT_SOURCE_DIR}/NamedPipeLibrary/include)