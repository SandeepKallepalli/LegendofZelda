#include "rock.h"
#include "main.h"
#include<math.h>
using namespace std;

Rock::Rock(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
//    int n=1;
//    static GLfloat g_vertex_buffer_data[360*3*3*1];
//    int verin=0;
//    for(int i=0;i<1;i++){
//        double z=i/double(n);
//        double r=sqrt(1.0-z*z);
//        cout << z << " "<< r << "\n";
//        float angle=0;
//        int vertin=verin;
//        for(;vertin-verin<360;vertin++)
//        {
//            g_vertex_buffer_data[vertin*9]=0.0f;
//            g_vertex_buffer_data[vertin*9+1]=0.0f;
//            g_vertex_buffer_data[vertin*9+2]=-3;

//            g_vertex_buffer_data[vertin*9+3]=r*cos(angle);
//            g_vertex_buffer_data[vertin*9+4]=r*sin(angle);
//            g_vertex_buffer_data[vertin*9+5]=-3;

//            g_vertex_buffer_data[vertin*9+6]=r*cos(angle+(M_PI/360.00));
//            g_vertex_buffer_data[vertin*9+7]=r*sin(angle+(M_PI/360.00));
//            g_vertex_buffer_data[vertin*9+8]=-3;

//            angle+=M_PI/360.00;
//        };
//        verin=vertin;
//    };
//    this->object = create3DObject(GL_TRIANGLES, 360*3, g_vertex_buffer_data, COLOR_BLACK, GL_FILL);
//    static GLfloat g_vertex_buffer_data[3240];
//    float angle=0;
//    for(int vertin=0;vertin<360;vertin++)
//    {
//        g_vertex_buffer_data[vertin*9]=0.0f;
//        g_vertex_buffer_data[vertin*9+1]=0.0f;
//        g_vertex_buffer_data[vertin*9+2]=0.0f;

//        g_vertex_buffer_data[vertin*9+3]=0.5*cos(angle);
//        g_vertex_buffer_data[vertin*9+4]=0.5*sin(angle);
//        g_vertex_buffer_data[vertin*9+5]=0.0f;

//        g_vertex_buffer_data[vertin*9+6]=0.5*cos(angle+(M_PI/180.0));
//        g_vertex_buffer_data[vertin*9+7]=0.5*sin(angle+(M_PI/180.0));
//        g_vertex_buffer_data[vertin*9+8]=0.0f;

//        angle+=M_PI/180.0;


//    };
    static GLfloat vertex_buffer_data[3240*300];
    static GLfloat color_buffer_data[3240*300];
    int verin=0;
    float c1=0.9,c2=0.25;
    for(int i=0;i<300;i++){
    double r=1.5*fabs(sqrt(1.0-i*i/90000.0));
//    cout << z << "\n";
    float angle=0.0;
    float z=i/300.0;
    int vertin=verin;
    for(;vertin-verin<360;vertin++)
     {
                vertex_buffer_data[vertin*9]=0.0f;
                vertex_buffer_data[vertin*9+1]=0.0f;
                vertex_buffer_data[vertin*9+2]=z-3.5;

                vertex_buffer_data[vertin*9+3]=r*cos(angle);
                vertex_buffer_data[vertin*9+4]=r*sin(angle);
                vertex_buffer_data[vertin*9+5]=z-3.5;

                vertex_buffer_data[vertin*9+6]=r*cos(angle+(M_PI/180.0));
                vertex_buffer_data[vertin*9+7]=r*sin(angle+(M_PI/180.0));
                vertex_buffer_data[vertin*9+8]=z-3.5;

                color_buffer_data[vertin*9]= (c2-c1)*z+c1;  //0.0f;
                color_buffer_data[vertin*9+1]= (c2-c1)*z+c1;  //0.0f;
                color_buffer_data[vertin*9+2]= (c2-c1)*z+c1;  //z-3.5;

                color_buffer_data[vertin*9+3]= (c2-c1)*z+c1;  //r*cos(angle);
                color_buffer_data[vertin*9+4]= (c2-c1)*z+c1;  //r*sin(angle);
                color_buffer_data[vertin*9+5]= (c2-c1)*z+c1;  //z-3.5;

                color_buffer_data[vertin*9+6]= (c2-c1)*z+c1;  //r*cos(angle+(M_PI/180.0));
                color_buffer_data[vertin*9+7]= (c2-c1)*z+c1;  //r*sin(angle+(M_PI/180.0));
                color_buffer_data[vertin*9+8]= (c2-c1)*z+c1;  //z-3.5;


                angle+=M_PI/180.0;
     };
    verin=vertin;
    };

//    static GLfloat vertex_buffer_data[3240*300];
//    int verin=0;
//    for(int i=0;i<300;i++){
//    double r=fabs(sqrt(1.0-i*i/90000.0));
//    float angle=0.0;
//    for(int vertin=0;vertin<360;vertin++)
//     {
//                vertex_buffer_data[vertin*9]=0.0f;
//                vertex_buffer_data[vertin*9+1]=0.0f;
//                vertex_buffer_data[vertin*9+2]=z-3;

//                vertex_buffer_data[vertin*9+3]=r*cos(angle);
//                vertex_buffer_data[vertin*9+4]=r*sin(angle);
//                vertex_buffer_data[vertin*9+5]=z-3;

//                vertex_buffer_data[vertin*9+6]=r*cos(angle+(M_PI/180.0));
//                vertex_buffer_data[vertin*9+7]=r*sin(angle+(M_PI/180.0));
//                vertex_buffer_data[vertin*9+8]=z-3;

//                angle+=M_PI/180.0;
//     };
//    };
    this->object = create3DObject(GL_TRIANGLES, 360*3*300, vertex_buffer_data, color_buffer_data, GL_FILL);
    //this->object = create3DObject(GL_TRIANGLES, 360*9*1, g_vertex_buffer_data, color, GL_FILL);
}

void Rock::draw(glm::mat4 VP) {
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

void Rock::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Rock::tick() {
    //this->rotation += speed;
    //this->position.x -= speed;
    //this->position.y -= speed;
}

bounding_box_t Rock::bounding_box(){
    bounding_box_t bbox={this->position.x,this->position.y,-2.5,2*sqrt(2),2*sqrt(2),1};
    return bbox;
}
