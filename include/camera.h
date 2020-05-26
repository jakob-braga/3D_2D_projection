# include "./world.h"

class Camera
{
    public:
    Vector3 pos;
    Vector3 v_vec;
    Vector3 h_vec;
    float FOV;
    float total_dv;
    float total_dh;
    float dv_max;
    
    Camera();
    void init();

    void rotate_h(float a);
    void rotate_v(float a);

    void move_laterally(int dir);
    void move_longitudinally(int dir);

    Vector3 get_n();

    Vector3 convert_to_draw(Vector3 v);
};