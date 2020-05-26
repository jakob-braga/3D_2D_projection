# include "structure_shapes.h"

class Structure
{
    public:

    std::vector<Face> faces;

    Structure();
    Structure(RectPrism rp);
    Structure(Face f);

};