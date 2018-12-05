#include "bullet.h"
#include "main.h"
#include<math.h>
using namespace std;

Bullet::Bullet(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    status=0;
    speedx=0;
    speedy=0;
    speedz=0;
    acc=0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static GLfloat vertex_buffer_data[3240*600];
    static GLfloat color_buffer_data[3240*600];
    int verin=0;
    float c1=0.9,c2=0.25;
    for(int i=-300;i<300;i++){
    float z=i/300.0;
    double r=fabs(sqrt(1-z*z));
    float angle=0.0;
    int vertin=verin;
    for(;vertin-verin<360;vertin++)
     {
                vertex_buffer_data[vertin*9]=0.0f;
                vertex_buffer_data[vertin*9+1]=0.0f;
                vertex_buffer_data[vertin*9+2]=z;

                vertex_buffer_data[vertin*9+3]=r*cos(angle);
                vertex_buffer_data[vertin*9+4]=r*sin(angle);
                vertex_buffer_data[vertin*9+5]=z;

                vertex_buffer_data[vertin*9+6]=r*cos(angle+(M_PI/180.0));
                vertex_buffer_data[vertin*9+7]=r*sin(angle+(M_PI/180.0));
                vertex_buffer_data[vertin*9+8]=z;

                color_buffer_data[vertin*9]= (c2-c1)*fabs(z)+c1;  //0.0f;
                color_buffer_data[vertin*9+1]= (c2-c1)*fabs(z)+c1;  //0.0f;
                color_buffer_data[vertin*9+2]= (c2-c1)*fabs(z)+c1;  //z-3.5;

                color_buffer_data[vertin*9+3]= (c2-c1)*fabs(z)+c1;  //r*cos(angle);
                color_buffer_data[vertin*9+4]= (c2-c1)*fabs(z)+c1;  //r*sin(angle);
                color_buffer_data[vertin*9+5]= (c2-c1)*fabs(z)+c1;  //z-3.5;

                color_buffer_data[vertin*9+6]= (c2-c1)*fabs(z)+c1;  //r*cos(angle+(M_PI/180.0));
                color_buffer_data[vertin*9+7]= (c2-c1)*fabs(z)+c1;  //r*sin(angle+(M_PI/180.0));
                color_buffer_data[vertin*9+8]= (c2-c1)*fabs(z)+c1;  //z-3.5;


                angle+=M_PI/180.0;
     };
    verin=vertin;
    };
    this->object = create3DObject(GL_TRIANGLES, 360*3*600, vertex_buffer_data, color_buffer_data, GL_FILL);
    //this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_RED, GL_FILL);
    //this->object = create3DObject(GL_TRIANGLES, 360*9, g_vertex_buffer_data, COLOR_BLACK, GL_FILL);
}

void Bullet::draw(glm::mat4 VP) {
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

void Bullet::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Bullet::tick() {
    //this->rotation += speed;
    //this->position.x -= speed;
    //this->position.y -= speed;

    this->position.x -= speedx*cos(this->rotation*M_PI/180.0)-speedy*sin(this->rotation*M_PI/180.0);
    this->position.y -= speedy*cos(this->rotation*M_PI/180.0)+speedx*sin(this->rotation*M_PI/180.0);
    this->position.z += speedz;
    if(this->speedz>0){
        this->acc=-0.05;
    }
    this->speedz+=this->acc;
    if(this->position.z<0){
        //printf("entered\n");
        this->position.z=-10;
        this->acc=0;
        this->speedz=0;
        this->speedy=0;
        this->speedx=0;
    }
}
bounding_box_t Bullet::bounding_box(){
    bounding_box_t bbox={this->position.x,this->position.y,this->position.z,2,2,2};
    return bbox;
        //bounding_box_t bbox = { x, y, 0.4, 0.4 };
}
