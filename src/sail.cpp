#include "sail.h"
#include "main.h"
using namespace std;

Sail::Sail(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->health=6;
    speedx=0;
    speedy=0;
    speedz=0;
    acc=0;
    wind=0;
    float l=3;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float lensail=3.0f;
    static const GLfloat vertex_buffer_datasail[] = {
        //rod highest point is z=2.000 with x and y 0,0
        0.0f,0.0f,2.0f,
        0.0f,0.0f,2.0-lensail,
        0.0f,lensail,2.0-lensail/2.0,
    };
    GLfloat sail_color_data[] = {
            //float(COLOR_RED.r)/255.0f, float(COLOR_RED.g)/255.0f, float(COLOR_RED.b)/255.0f,
            1.0,222.0/255.0,173.0/255.0,
            1.0,222.0/255.0,173.0/255.0,
            1.0,1.0,1.0,
            //float(COLOR_BASE.r)/255.0f, float(COLOR_BASE.g)/255.0f, float(COLOR_BASE.b)/255.0f,
            //float(COLOR_GREEN.r)/255.0f, float(COLOR_GREEN.g)/255.0f, float(COLOR_GREEN.b)/255.0f,
    };
//rgb(255,222,173)
    this->object = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_datasail, sail_color_data, GL_FILL);
}

void Sail::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Sail::set_position(float x, float y , float z) {
    this->position = glm::vec3(x, y, z);
}

void Sail::tick() {
    //this->rotation=this->rotation-int(this->rotation)+int(this->rotation)%180;
    //this->rotation += speed;
    //cout << this->position.x <<" "<< this->position.y <<" "<< this->position.z <<" " << "\n";
    this->position.x -= speedx;
    this->position.y -= speedy;
    this->position.z += speedz;
    if(this->speedz>0){
        this->acc=-0.05;
    }
    this->speedz+=this->acc;
    if(this->position.z<0){
        this->position.z=0;
        this->acc=0;
        this->speedz=0;
        this->speedy=0;
        this->speedx=0;
    }
}

void Sail::detect_collision(Rock rock){

}
