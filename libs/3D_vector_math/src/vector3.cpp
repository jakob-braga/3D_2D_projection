# include <iostream>
# include <cmath>
# include "./../include/vector3.h"

using namespace std;

Vector3::Vector3(float xc, float yc, float zc)
{
    x = xc;
    y = yc;
    z = zc;
}

Vector3::Vector3()
{}

void Vector3::add(Vector3 vec2)
{
    x += vec2.x;
    y += vec2.y;
    z += vec2.z;
}

void Vector3::sub(Vector3 vec2)
{
    x -= vec2.x;
    y -= vec2.y;
    z -= vec2.z;
}

float Vector3::dot(Vector3 vec2)
{
    return x*vec2.x + y*vec2.y + z*vec2.z;
}

void Vector3::scale(float fac)
{
    x *= fac;
    y *= fac;
    z *= fac;
}

float Vector3::norm()
{
    return float(sqrt(x*x + y*y + z*z));
}

void Vector3::transform(Vector3 row1, Vector3 row2, Vector3 row3)
{
    float oldx = x;
    float oldy = y;
    float oldz = z;
    x = row1.x*oldx + row1.y*oldy + row1.z*oldz;
    y = row2.x*oldx + row2.y*oldy + row2.z*oldz;
    z = row3.x*oldx + row3.y*oldy + row3.z*oldz;
}

void Vector3::print()
{
    cout << x << ", " << y << ", " << z << endl;
}