#include "main.h"

#ifndef Monster_H
#define Monster_H


class Monster {
public:
    Monster() {}
    Monster(float x, float y,float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    bounding_box_t bounding_box();
    double speedx;
    double speedy;
    double speedz;
    double acc;
    bool alive;
    bool gift;
    bool boss;
private:
    VAO *object;
    VAO *objecthorn1;
    VAO *objecthorn2;
    VAO *objectgiftcurve;
    VAO *objectgiftdisk1;
    VAO *objectgiftdisk2;
    VAO *giftcurve;
    VAO *giftdisk1;
    VAO *giftdisk2;
};

#endif // Monster_H
