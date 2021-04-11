# Escape Game
Минималистичная игра-головоломка. Задача игрока -- выйти из комнаты, наполненной дверьми, порталами и бонусными сундуками.  
Карта представляет собой прямоугольник определенного размера. Игрок выигрывает, если оказывается на одной из границ карты. Внутри карты расставлены двери, сундуки и порталы. Двери позволяют пройти через стену, около которой она стоит. Портал может перенести игрока к одному из других порталов. Сундук содержит монеты, из которых складываются очки игрока.  
Также, каждый из объектов разделен на класссы "Обычный", "Обманка", "Ловушка". "Обычный" предмет позволяет взаимодействовать с собой без каких-либо дополнительных эффектов на игрока. При взаимодействии с объектами типа "Обманка" ничего не происходит. "Ловушка" - отнимает некоторое количество очков здоровья у игрока, а далее поведение аналогично типу "Обычный".

## Нынешний геймплэй
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
