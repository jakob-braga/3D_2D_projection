# include <iostream>
# include <cmath>
# include "./../include/3D_vector_math.h"

using namespace std;


Vector3 addV3(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3 subV3(Vector3 v1, Vector3 v2)
{
    return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3 scaleV3(Vector3 v, float fac)
{
    
    return Vector3(v.x*fac, v.y*fac, v.z*fac);
}

Vector3 crossV3(Vector3 v1, Vector3 v2)
{
    return Vector3(
        v1.y*v2.z - v1.z*v2.y,
        v2.x*v1.z - v2.z*v1.x,
        v1.x*v2.y - v1.y*v2.x
    );
}

Vector3 matrixReduceRowsV3(Vector3 mv1, Vector3 mv2, Vector3 mv3, Vector3 c)
{

    float m[3][4] = {
        {mv1.x, mv2.x, mv3.x, c.x},
        {mv1.y, mv2.y, mv3.y, c.y},
        {mv1.z, mv2.z, mv3.z, c.z}
    };

    int cols = 4;
    int rows = 3;

    float fac;

    for (int pivot = 0; pivot < rows; pivot++)
    {
        fac = m[pivot][pivot];
        for (int i = 0; i < cols; i++)
        {
            m[pivot][i] /= fac;
        }
        for (int row = 0; row < rows; row++)
        {
            if (row != pivot)
            {
                fac = m[row][pivot];
                for (int j = 0; j < cols; j++)
                {
                    m[row][j] -= fac*m[pivot][j];
                }
            }
        }
    }
    
    return Vector3(m[0][3], m[1][3], m[2][3]);
}