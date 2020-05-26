# include "./../include/face.h"

Face::Face(Vector3 v1, Vector3 v2, Vector3 v3)
{
    verts.push_back(v1);
    verts.push_back(v2);
    verts.push_back(v3);
}

Face::Face(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4)
{
    verts.push_back(v1);
    verts.push_back(v2);
    verts.push_back(v3);
    verts.push_back(v4);
}