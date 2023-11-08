cmake_minimum_required(VERSION 3.10)

# Proje adını ve dilini belirtin
project(myproject CXX)
# Derleme seçeneklerini ayarla (C++11 veya daha sonrası)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# car.cpp dosyasını içeren bir kütüphane oluşturun
add_library(ArrayLecture src/array_lecture.cpp)
add_library(MoveConstructor src/move_constructor_lecture.cpp)
add_library(OperatorOverloading src/operator_overloading_lecture.cpp)
#add_library(BMWLibrary src/bmw.cpp)
#add_library(ItemLibrary src/item.cpp)

# test.cpp dosyasını oluşturun ve CarLibrary kütüphanesini kullanarak derleyin
add_executable(main main.cpp)

# Bu komutla include dizinini derleyiciye bildirin (car.hpp içindir)
#target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# MyTestProgram, CarLibrary kütüphanesine bağlıdır
target_link_libraries(main PRIVATE ArrayLecture MoveConstructor OperatorOverloading)