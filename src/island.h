#include "main.h"

#ifndef Island_H
#define Island_H


class Island {
public:
    Island() {}
    Island(float x, float y,float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // Island_H
