# include "./face.h"

class RectPrism
{
    public:

    std::vector<Face> faces;

    // pos is most negative corner, w->x, d->y, h->z
    RectPrism(Vector3 pos, int wid, int dep, int hei);

};