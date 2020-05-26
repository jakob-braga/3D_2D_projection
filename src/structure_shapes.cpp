# include "./../include/structure_shapes.h"

RectPrism::RectPrism(Vector3 pos, int wid, int dep, int hei)
{
    Vector3 p1 = pos;
    Vector3 p2(pos.x + wid, pos.y, pos.z);
    Vector3 p3(pos.x + wid, pos.y + dep, pos.z);
    Vector3 p4(pos.x, pos.y + dep, pos.z);
    Vector3 p5(pos.x, pos.y, pos.z + hei);
    Vector3 p6(pos.x + wid, pos.y, pos.z + hei);
    Vector3 p7(pos.x + wid, pos.y + dep, pos.z + hei);
    Vector3 p8(pos.x, pos.y + dep, pos.z + hei);

    faces.push_back(Face(p1, p2, p6, p5));
    faces.push_back(Face(p2, p3, p7, p6));
    faces.push_back(Face(p3, p4, p8, p7));
    faces.push_back(Face(p4, p1, p5, p8));
    faces.push_back(Face(p1, p2, p3, p4));
    faces.push_back(Face(p5, p6, p7, p8));
}