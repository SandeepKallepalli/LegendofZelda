#include "main.h"
#include "rock.h"

#ifndef Man_H
#define Man_H


class Man {
public:
    Man() {}
    Man(float x, float y,float z);
    glm::vec3 position;
    glm::vec3 positionhand1;
    glm::vec3 positionhand2;
    glm::vec3 positionleg1;
    glm::vec3 positionleg2;
    float l;
    float rotation;
    float rotation2;
    bool flag;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    void detect_collision(Rock rock);
    bounding_box_t bounding_box();
    double speedz;
    double acc;
private:
    VAO *objecthead;
    VAO *objectbody;
    VAO *objecthand1;
    VAO *objecthand2;
    VAO *objectleg1;
    VAO *objectleg2;
};

#endif // Man_H
