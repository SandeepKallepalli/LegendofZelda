#include "island.h"
#include "main.h"
#include<math.h>
using namespace std;

Island::Island(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);

    static GLfloat vertex_buffer_data[3240*600];
    static GLfloat color_buffer_data[3240*600];
    int verin=0;
    float c1=0.9,c2=0.25;
    for(int i=-300;i<300;i++){
    float z=i/150.0;
    double r=100*fabs(sqrt(4-z*z));
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


    this->object = create3DObject(GL_TRIANGLES, 360*3*600, vertex_buffer_data, color, GL_FILL);
}

void Island::draw(glm::mat4 VP) {

        Matrices.model = glm::mat4(1.0f);
        glm::mat4 translate = glm::translate (this->position);    // glTranslatef
        glm::mat4 MVP = VP * Matrices.model * (translate);
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(this->object);
}

void Island::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Island::tick() {
}

bounding_box_t Island::bounding_box(){
        bounding_box_t bbox={this->position.x,this->position.y,this->position.z,200.0,200.0,4.0};
        return bbox;
}
