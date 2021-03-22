# Escape Game
Игра-головоломка, задача которой выйти из комнаты, наполненной дверьми, порталами и бонусными сундуками.

## Диаграмма классов
![alt text](https://github.com/Khaymon/escape_game/blob/checkpoint_1/class_diagram.jpg)

## Сборка проекта
```
mkdir build  
cd build  
cmake .. && make
```
## Дерево проекта
```
$ tree
.
├── class_diagram.jpg
├── CMakeLists.txt
├── include
│   ├── ConcreteFactoryFake.hpp
│   ├── ConcreteFactoryNormal.hpp
│   ├── ConcreteFactoryTrap.hpp
│   ├── draw.h
│   ├── FakeChest.hpp
│   ├── FakeDoor.hpp
│   ├── FakePortal.hpp
│   ├── IAbstractFactory.hpp
│   ├── IChest.hpp
│   ├── IDoor.hpp
│   ├── IPortal.hpp
│   ├── NormalChest.hpp
│   ├── NormalDoor.hpp
│   ├── NormalPortal.hpp
│   ├── ObjectsData.hpp
│   ├── TrapChest.hpp
│   ├── TrapDoor.hpp
│   └── TrapPortal.hpp
├── lint.sh
├── README.md
├── src
│   └── main.cpp
└── tests
    ├── tests.cpp
    └── unit_tests.cpp
```
