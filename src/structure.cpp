# include "./../include/structure.h"

Structure::Structure(RectPrism rp)
{
    faces = rp.faces;
}

Structure::Structure(Face f)
{
    faces.push_back(f);
}