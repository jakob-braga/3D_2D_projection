class Vector3
{
    public:
        float x;
        float y;
        float z;

        Vector3(float xc, float yc, float zc);
        Vector3();
        void add(Vector3 vec2);
        void sub(Vector3 vec2);
        float dot(Vector3 vec2);
        void scale(float fac);
        float norm();
        void transform(Vector3 row1, Vector3 row2, Vector3 row3);
        void print();
};
