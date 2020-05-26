# include  "./../libs/3D_vector_math/include/3D_vector_math.h"
# include <vector>

class Face
{
    public:

    std::vector<Vector3> verts;

    Face(Vector3 v1, Vector3 v2, Vector3 v3);
    Face(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4);
};