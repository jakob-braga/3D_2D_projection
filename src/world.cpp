#include "./../include/world.h"

World::World()
{
    structures.push_back(Structure(RectPrism(Vector3(0, 0, 0), 50, 50, 50)));
    structures.push_back(Structure(Face(Vector3(-300, -300, 0), Vector3(-300, 300, 0), Vector3(300, 300, 0), Vector3(300, -300, 0))));
}