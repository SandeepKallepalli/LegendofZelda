#include "main.h"

#ifndef Barrel_H
#define Barrel_H


class Barrel {
public:
    Barrel() {}
    Barrel(float x, float y,float z, color_t color);
    glm::vec3 position;
    float rotation1;
    float rotation2;
    float rotationgift;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    int status;
    bounding_box_t bounding_box();
private:
    VAO *objectdisk1;
    VAO *objectdisk2;
    VAO *objectcurve;
    VAO *objectgift;
};

#endif // Barrel_H
