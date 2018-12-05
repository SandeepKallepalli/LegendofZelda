#include "main.h"

#ifndef Rock_H
#define Rock_H


class Rock {
public:
    Rock() {}
    Rock(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    bounding_box_t bounding_box();
    double speed;
private:
    VAO *object;
};

#endif // Rock_H
