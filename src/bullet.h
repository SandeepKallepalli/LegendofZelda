#include "main.h"

#ifndef Bullet_H
#define Bullet_H


class Bullet {
public:
    Bullet() {}
    Bullet(float x, float y,float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speedx;
    double speedy;
    double speedz;
    double acc;
    int status;
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // Bullet_H
