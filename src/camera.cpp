# include "./../include/camera.h"
# include <cmath>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

Camera::Camera()
{}

void Camera::init()
{
    pos = Vector3(2.0, -600.0, 100.0);
    h_vec = Vector3(1.0, 0.0, 0.0);
    v_vec = Vector3(0.0, 0.0, 1.0);
    FOV = 0.1;
    total_dv = 0.0;
    total_dh = 0;
    dv_max = float(M_PI)*3.0/8.0; //restict rotation all the way around vertically
}

void Camera::rotate_h(float a)
{
    total_dh += a;
    if (total_dh >= float(M_PI)*2.f)
    {
        total_dh -= 2.f*float(M_PI);
    }

    // above needed for rotation matrix on vertical

    h_vec.transform(
        Vector3(float(cos(a)), float(sin(a)), 0),
        Vector3(-float(sin(a)), float(cos(a)), 0),
        Vector3(0, 0, 1.0)
    );
    v_vec.transform(
        Vector3(float(cos(a)), float(sin(a)), 0),
        Vector3(-float(sin(a)), float(cos(a)), 0),
        Vector3(0, 0, 1.0)
    );
}

void Camera::rotate_v(float a)
{
    // check to make sure that you havnt over rotated, if you have just ignore it
    total_dv += a;
    if (total_dv >= dv_max)
    {
        total_dv = dv_max;
    }
    else if (total_dv <= -dv_max)
    {
        total_dv = -dv_max;
    }

    // check if your actually doing the rotation
    if (abs(total_dv) < dv_max)
    {
        float b = total_dh;  // xy plane angle
        float ca = cos(a);
        float cb = cos(b);
        float sa = sin(a);
        float sb = sin(b);

        v_vec.transform(
            Vector3(cb*cb + ca*sb*sb, -cb*sb + cb*sb*ca, sa*sb),
            Vector3(-sb*cb + sb*cb*ca, sb*sb + ca*cb*cb, cb*sa),
            Vector3(-sb*sa, -sa*cb, ca)
        );

        h_vec.transform(
            Vector3(cb*cb + ca*sb*sb, -cb*sb + cb*sb*ca, sa*sb),
            Vector3(-sb*cb + sb*cb*ca, sb*sb + ca*cb*cb, cb*sa),
            Vector3(-sb*sa, -sa*cb, ca)
        );
    }
}

void Camera::move_laterally(int dir)
{
    pos.add(scaleV3(h_vec, dir*4));
}

void Camera::move_longitudinally(int dir)
{
    Vector3 n = get_n();
    pos.add(scaleV3(Vector3(n.x, n.y, 0), dir*4));
}

Vector3 Camera::get_n()
{
    return crossV3(v_vec, h_vec);
}

Vector3 Camera::convert_to_draw(Vector3 v)
{
    Vector3 n = get_n();
    Vector3 d = subV3(v, pos);  // vector from p to vert
    Vector3 u = subV3(d, scaleV3(n, n.dot(d)));  // projection onto view plane (but at view point)
    u.add(scaleV3(d, FOV));  // get the matrix off of view point to actual view plan
    float dist_fac = d.norm()/1000.f;
    Vector3 new_vec = matrixReduceRowsV3(h_vec, n, v_vec, u);  // gives solution vector
    new_vec.scale(1.f/dist_fac);
    return new_vec;
}