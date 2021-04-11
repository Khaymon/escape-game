# Escape Game
Минималистичная игра-головоломка. Задача игрока -- выйти из комнаты, наполненной дверьми, порталами и бонусными сундуками.  
Карта представляет собой прямоугольник определенного размера. Игрок выигрывает, если оказывается на одной из границ карты. Внутри карты расставлены двери, сундуки и порталы. Двери позволяют пройти через стену, около которой она стоит. Портал может перенести игрока к одному из других порталов. Сундук содержит монеты, из которых складываются очки игрока.  
Также, каждый из объектов разделен на класссы "Обычный", "Обманка", "Ловушка". "Обычный" предмет позволяет взаимодействовать с собой без каких-либо дополнительных эффектов на игрока. При взаимодействии с объектами типа "Обманка" ничего не происходит. "Ловушка" - отнимает некоторое количество очков здоровья у игрока, а далее поведение аналогично типу "Обычный".

## Нынешний геймплей
На нынешнем этапе разработки игрок может перемещаться по карте с помощью кнопок A, D, W, S. Символ "^" на карте обозначает сундук, "]" - дверь, "0" - портал.  
![alt text](https://github.com/Khaymon/escape_game/blob/checkpoint_2/gameplay.gif)


## Диаграмма классов
Объекты карты создаются с помощью абстрактной фабрики. Также, реализован паттерн "Адаптер" (класс CoordinatesAdapter).
![alt text](https://github.com/Khaymon/escape_game/blob/checkpoint_2/class_diagram.jpg)

## Сборка проекта
```
mkdir build  
cd build  
cmake .. -DCMAKE_INSTALL_PREFIX=/install/path && make
```
## Установка
```
make install
```
## Дерево проекта
```
$ tree
.
├── bin
│   ├── room_escape
│   └── Tests
├── class_diagram.jpg
├── CMakeLists.txt
├── configure.h.in
├── gameplay.gif
├── include
│   ├── configure.h
│   ├── CoordinatesAdapter.hpp
│   ├── Coordinates.hpp
│   ├── Drawer.hpp
│   ├── draw.h
│   ├── factory
│   │   ├── ConcreteFactoryFake.hpp
│   │   ├── ConcreteFactoryNormal.hpp
│   │   ├── ConcreteFactoryTrap.hpp
│   │   └── IAbstractFactory.hpp
│   ├── Game.hpp
│   ├── Level.hpp
│   ├── objects
│   │   ├── FakeChest.hpp
│   │   ├── FakeDoor.hpp
│   │   ├── FakePortal.hpp
│   │   ├── IChest.hpp
│   │   ├── IDoor.hpp
│   │   ├── IObject.hpp
│   │   ├── IPortal.hpp
│   │   ├── NormalChest.hpp
│   │   ├── NormalDoor.hpp
│   │   ├── NormalPortal.hpp
│   │   ├── ObjectsData.hpp
│   │   ├── PlayerCharacter.hpp
│   │   ├── TrapChest.hpp
│   │   ├── TrapDoor.hpp
│   │   ├── TrapPortal.hpp
│   │   └── Wall.hpp
│   ├── Player.hpp
│   └── Tester.hpp
├── levels
│   ├── all.json
│   ├── intro.json
│   └── template.json
├── lib
│   └── liblibs.so
├── lint.sh
├── main.cpp
├── README.md
├── src
│   ├── CMakeLists.txt
│   ├── Coordinates.cpp
│   ├── factory
│   │   ├── ConcreteFactoryFake.cpp
│   │   ├── ConcreteFactoryNormal.cpp
│   │   └── ConcreteFactoryTrap.cpp
│   ├── Game.cpp
│   ├── Level.cpp
│   ├── objects
│   │   ├── FakeChest.cpp
│   │   ├── FakeDoor.cpp
│   │   ├── FakePortal.cpp
│   │   ├── IChest.cpp
│   │   ├── IDoor.cpp
│   │   ├── IObject.cpp
│   │   ├── IPortal.cpp
│   │   ├── NormalChest.cpp
│   │   ├── NormalDoor.cpp
│   │   ├── NormalPortal.cpp
│   │   ├── PlayerCharacter.cpp
│   │   ├── TrapChest.cpp
│   │   ├── TrapDoor.cpp
│   │   ├── TrapPortal.cpp
│   │   └── Wall.cpp
│   └── Player.cpp
├── tests
│   ├── factory
│   │   └── factory_tests.cpp
│   ├── levels
│   │   └── levels_tests.cpp
│   └── tests.cpp
└── third_party
    └── CMakeLists.txt
```
## Зависимости
* [Google Test](https://github.com/google/googletest/) - тесты
* [JSON for modern C++](https://github.com/google/googletest/) - парсер json
