#include <include/objects/Enter.hpp>

Enter::Enter(const Coordinates& coordinates)
    : IObject(ENTER_ID, coordinates, ENTER_CHAR, ENTER_COLOR) {}

Enter::Enter() : Enter(Coordinates(0, 0)) {}