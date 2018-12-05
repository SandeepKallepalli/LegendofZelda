#include "main.h"
#include "rock.h"

#ifndef Sail_H
#define Sail_H


class Sail {
public:
    Sail() {}
    Sail(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y ,float z);
    void tick();
    void detect_collision(Rock rock);
    double speedx;
    double speedy;
    double speedz;
    float wind;
    double acc;
    double health;
private:
    VAO *object;
};

#endif // Sail_H
