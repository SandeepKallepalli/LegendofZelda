#include "main.h"
#include "rock.h"

#ifndef Boat_H
#define Boat_H


class Boat {
public:
    Boat() {}
    Boat(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    void detect_collision(Rock rock);
    bounding_box_t bounding_box();
    float lc;//length of cannon
    double windx;
    double windy;
    double speedx;
    double speedy;
    double speedz;
    int floatcount;
    int boostcount;
    float wind1;
    float wind2;
    double acc;
    double health;
    double score;
    bool man;
private:
    VAO *object;
    VAO *objectbf;
    VAO *objectbase;
    VAO *objectpole;
    VAO *objectcannon;
};

#endif // Boat_H
