#include "barrel.h"
#include "main.h"
#include<math.h>
using namespace std;

Barrel::Barrel(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation1 = 20;
    this->rotation2 = 360*(rand()%2)-75;
    status=0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static GLfloat vertex_buffer_data1[3240];
    float angle=0.0;
    float r=1;
    float l=3;
    for(int vertin=0;vertin<360;vertin++)
     {
                vertex_buffer_data1[vertin*9]=0.0f;
                vertex_buffer_data1[vertin*9+1]=l/2;
                vertex_buffer_data1[vertin*9+2]=0.0;

                vertex_buffer_data1[vertin*9+3]=r*cos(angle);
                vertex_buffer_data1[vertin*9+4]=l/2;
                vertex_buffer_data1[vertin*9+5]=r*sin(angle);

                vertex_buffer_data1[vertin*9+6]=r*cos(angle+(M_PI/180.0));
                vertex_buffer_data1[vertin*9+7]=l/2;
                vertex_buffer_data1[vertin*9+8]=r*sin(angle+(M_PI/180.0));

                angle+=M_PI/180.0;
     };
    static GLfloat vertex_buffer_data2[3240];
    angle=0.0;
    for(int vertin=0;vertin<360;vertin++)
     {
                vertex_buffer_data2[vertin*9]=0.0f;
                vertex_buffer_data2[vertin*9+1]=-l/2;
                vertex_buffer_data2[vertin*9+2]=0.0;

                vertex_buffer_data2[vertin*9+3]=r*cos(angle);
                vertex_buffer_data2[vertin*9+4]=-l/2;
                vertex_buffer_data2[vertin*9+5]=r*sin(angle);

                vertex_buffer_data2[vertin*9+6]=r*cos(angle+(M_PI/180.0));
                vertex_buffer_data2[vertin*9+7]=-l/2;
                vertex_buffer_data2[vertin*9+8]=r*sin(angle+(M_PI/180.0));

                angle+=M_PI/180.0;
     };
    //360lines for curve
    static GLfloat vertex_buffer_data3[3*2*360*5];
    angle=0.0;
    for(int vertin=0;vertin<360*5;vertin++)
    {
        vertex_buffer_data3[vertin*6]=r*cos(angle);
        vertex_buffer_data3[vertin*6+1]=-l/2;
        vertex_buffer_data3[vertin*6+2]=r*sin(angle);

        vertex_buffer_data3[vertin*6+3]=r*cos(angle);
        vertex_buffer_data3[vertin*6+4]=l/2;
        vertex_buffer_data3[vertin*6+5]=r*sin(angle);
        angle+=M_PI/(180*5);
    };
    l=1.35*l;
    static const GLfloat vertex_buffer_data4[] = {
        -0.3f,-l/2-0.3f,-0.3f, // triangle 1 : begin
                -0.3f,-l/2-0.3f, 0.3f,
                -0.3f, -l/2+0.3f, 0.3f, // triangle 1 : end
                0.3f, -l/2+0.3f,-0.3f, // triangle 2 : begin
                -0.3f,-l/2-0.3f,-0.3f,
                -0.3f, -l/2+0.3f,-0.3f, // triangle 2 : end
                0.3f,-l/2-0.3f, 0.3f,
                -0.3f,-l/2-0.3f,-0.3f,
                0.3f,-l/2-0.3f,-0.3f,
                0.3f, -l/2+0.3f,-0.3f,
                0.3f,-l/2-0.3f,-0.3f,
                -0.3f,-l/2-0.3f,-0.3f,
                -0.3f,-l/2-0.3f,-0.3f,
                -0.3f, -l/2+0.3f, 0.3f,
                -0.3f, -l/2+0.3f,-0.3f,
                0.3f,-l/2-0.3f, 0.3f,
                -0.3f,-l/2-0.3f, 0.3f,
                -0.3f,-l/2-0.3f,-0.3f,
                -0.3f, -l/2+0.3f, 0.3f,
                -0.3f,-l/2-0.3f, 0.3f,
                0.3f,-l/2-0.3f, 0.3f,
                0.3f, -l/2+0.3f, 0.3f,
                0.3f,-l/2-0.3f,-0.3f,
                0.3f, -l/2+0.3f,-0.3f,
                0.3f,-l/2-0.3f,-0.3f,
                0.3f, -l/2+0.3f, 0.3f,
                0.3f,-l/2-0.3f, 0.3f,
                0.3f, -l/2+0.3f, 0.3f,
                0.3f, -l/2+0.3f,-0.3f,
                -0.3f, -l/2+0.3f,-0.3f,
                0.3f, -l/2+0.3f, 0.3f,
                -0.3f, -l/2+0.3f,-0.3f,
                -0.3f, -l/2+0.3f, 0.3f,
                0.3f, -l/2+0.3f, 0.3f,
                -0.3f, -l/2+0.3f, 0.3f,
        0.3f,-l/2-0.3f, 0.3f

    };
    l=l/1.35;
    this->objectdisk1 = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data1,COLOR_BASE , GL_FILL);
    this->objectdisk2 = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data2, COLOR_BASE, GL_FILL);
    this->objectcurve = create3DObject(GL_LINES, 360*2*5, vertex_buffer_data3, COLOR_BROWN, GL_FILL);
    this->objectgift = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data4, COLOR_RED, GL_FILL);
    //this->object = create3DObject(GL_TRIANGLES, 360*9, g_vertex_buffer_data, COLOR_BLACK, GL_FILL);
}

void Barrel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate1    = glm::rotate((float) (this->rotation1 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate2 * rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->objectdisk1);
    draw3DObject(this->objectdisk2);
    draw3DObject(this->objectcurve);
    if(status==0)
    {
        Matrices.model = glm::mat4(1.0f);
        translate = glm::translate (this->position);    // glTranslatef
        rotate1    = glm::rotate((float) (this->rotation1 * M_PI / 180.0f), glm::vec3(0, 0, 1));
        rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(1, 0, 0));
        glm::mat4 rotate3    = glm::rotate((float) (this->rotationgift * M_PI / 180.0f), glm::vec3(0, 1, 0));
        Matrices.model *= (translate * rotate2 * rotate1 * rotate3 );
        //Matrices.model *= (translate * rotate2 * rotate1);
        MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(this->objectgift);
    }
}

void Barrel::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Barrel::tick() {
    this->rotationgift+=5;
    //this->rotation += speed;
    //this->position.x -= speed;
    //this->position.y -= speed;
}
bounding_box_t Barrel::bounding_box(){
    bounding_box_t bbox={this->position.x,this->position.y,-3,2.0,2.0,1.5};
    return bbox;
        //bounding_box_t bbox = { x, y, 0.4, 0.4 };
}
