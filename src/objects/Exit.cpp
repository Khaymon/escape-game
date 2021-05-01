#include <include/objects/Exit.hpp>

Exit::Exit(const Coordinates& coordinates)
    : IObject(EXIT_ID, coordinates, EXIT_CHAR, EXIT_COLOR) {}

Exit::Exit() : Exit(Coordinates(0, 0)) {}