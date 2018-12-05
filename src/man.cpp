#include "man.h"
#include "main.h"
using namespace std;

Man::Man(float x, float y, float z) {
    l=0.2;
    this->position = glm::vec3(x, y, z);
    this->positionhand1 = glm::vec3(x+2*l, y+0, z);
    this->positionhand2 = glm::vec3(x-2*l, y-0, z);
    this->positionleg1 = glm::vec3(x+l*1.5, y+0, z-l*3);
    this->positionleg2 = glm::vec3(x-l*1.5, y-0, z-l*3);
//    this->positionhand1 = glm::vec3(x+2*l, y+1.5*l*tan(this->rotation*M_PI/180.0), z);
//    this->positionhand2 = glm::vec3(x-2*l, y-1.5*l*tan(this->rotation*M_PI/180.0), z);
//    this->positionleg1 = glm::vec3(x-l*2, y+1.5*l*tan(this->rotation*M_PI/180.0), z-l*3);
//    this->positionleg2 = glm::vec3(x+l*2, y-1.5*l*tan(this->rotation*M_PI/180.0), z-l*3);
    this->rotation = 0;
    this->rotation2 = 0;
    flag=true;

    speedz=0;
    acc=0;

    static const GLfloat vertex_buffer_databody[] = {
        -l,-l,-3*l, // triangle 1 : begin
        -l,-l, 3*l,
        -l, l, 3*l, // triangle 1 : end



        -l,-l,-3*l,
        -l, l, 3*l,
        -l, l,-3*l,



        l,-l,-3*l, // triangle 1 : begin
        l,-l, 3*l,
        l, l, 3*l, // triangle 1 : end



        l,-l,-3*l,
        l, l, 3*l,
        l, l,-3*l,

        -l,-l,-3*l, // triangle 1 : begin
        -l,-l, 3*l,
        l, -l,-3*l,

        l, -l, 3*l,
        l, -l,-3*l,
        -l, -l, 3*l,

        -l,l,-3*l, // triangle 1 : begin
        -l,l, 3*l,
        l, l,-3*l,

        l, l, 3*l,
        l, l,-3*l,
        -l,l, 3*l,


    };
    static GLfloat vertex_buffer_data[3240*600];
    static GLfloat color_buffer_data[3240*600];
    int verin=0;
    for(int i=-300;i<300;i++){
    float z=i/300.0;
    z*=0.5;
    double r=fabs(sqrt(0.25-z*z));
    float angle=0.0;
    int vertin=verin;
    for(;vertin-verin<360;vertin++)
     {
                vertex_buffer_data[vertin*9]=0.0f;
                vertex_buffer_data[vertin*9+1]=0.0f;
                vertex_buffer_data[vertin*9+2]=z+1.5*l+0.7;

                vertex_buffer_data[vertin*9+3]=r*cos(angle);
                vertex_buffer_data[vertin*9+4]=r*sin(angle);
                vertex_buffer_data[vertin*9+5]=z+1.5*l+0.7;

                vertex_buffer_data[vertin*9+6]=r*cos(angle+(M_PI/180.0));
                vertex_buffer_data[vertin*9+7]=r*sin(angle+(M_PI/180.0));
                vertex_buffer_data[vertin*9+8]=z+1.5*l+0.7;

                if(z>0){
                    color_buffer_data[vertin*9]= COLOR_BLACK.r;  //0.0f;
                    color_buffer_data[vertin*9+1]= COLOR_BLACK.g;  //0.0f;
                    color_buffer_data[vertin*9+2]= COLOR_BLACK.b;  //z-3.5;

                    color_buffer_data[vertin*9+3]= COLOR_BLACK.r;  //r*cos(angle);
                    color_buffer_data[vertin*9+4]= COLOR_BLACK.g;  //r*sin(angle);
                    color_buffer_data[vertin*9+5]= COLOR_BLACK.b;  //z-3.5;

                    color_buffer_data[vertin*9+6]= COLOR_BLACK.r;  //r*cos(angle+(M_PI/180.0));
                    color_buffer_data[vertin*9+7]= COLOR_BLACK.g;  //r*sin(angle+(M_PI/180.0));
                    color_buffer_data[vertin*9+8]= COLOR_BLACK.b;  //z-3.5;
                }
                else
                {
                    color_buffer_data[vertin*9]= COLOR_BASE.r;  //0.0f;
                    color_buffer_data[vertin*9+1]= COLOR_BASE.g;  //0.0f;
                    color_buffer_data[vertin*9+2]= COLOR_BASE.b;  //z-3.5;

                    color_buffer_data[vertin*9+3]= COLOR_BASE.r;  //r*cos(angle);
                    color_buffer_data[vertin*9+4]= COLOR_BASE.g;  //r*sin(angle);
                    color_buffer_data[vertin*9+5]= COLOR_BASE.b;  //z-3.5;

                    color_buffer_data[vertin*9+6]= COLOR_BASE.r;  //r*cos(angle+(M_PI/180.0));
                    color_buffer_data[vertin*9+7]= COLOR_BASE.g;  //r*sin(angle+(M_PI/180.0));
                    color_buffer_data[vertin*9+8]= COLOR_BASE.b;  //z-3.5;
                }

                angle+=M_PI/180.0;
     };
    verin=vertin;
    };


    this->objecthead = create3DObject(GL_TRIANGLES, 360*3*600, vertex_buffer_data, color_buffer_data, GL_FILL);

    this->objectbody = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_databody, COLOR_BLACK, GL_FILL);
    this->objecthand1 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_databody, COLOR_GOLD, GL_FILL);
    this->objecthand2 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_databody, COLOR_GOLD, GL_FILL);
    this->objectleg1 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_databody, COLOR_BLUE, GL_FILL);
    this->objectleg2 = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_databody, COLOR_BLUE, GL_FILL);
//    this->objectbf = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_databf, color, GL_FILL);
//    this->objectpole = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_datapole, COLOR_GREEN, GL_FILL);
//    this->objectbase = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_database, COLOR_BASE, GL_FILL);
//    this->objectcannon = create3DObject(GL_LINES, 360*2*5, vertex_buffer_datacannon, COLOR_BLACK, GL_FILL);
}

void Man::draw(glm::mat4 VP) {

    this->positionhand1 = glm::vec3(this->position.x+2*this->l, this->position.y+0, this->position.z);
    this->positionhand2 = glm::vec3(this->position.x - 2*this->l, this->position.y-0, this->position.z);
    this->positionleg1 = glm::vec3(this->position.x+this->l*3, this->position.y+0, this->position.z-this->l*6);
    this->positionleg2 = glm::vec3(this->position.x-this->l*3, this->position.y-0, this->position.z-this->l*6);


    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    //glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate*rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->objectbody);
    draw3DObject(this->objecthead);
    Matrices.model = glm::mat4(1.0f);
    translate = glm::translate (this->positionhand1);    // glTranslatef
    rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 1.5*this->l));
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(this->position.x, this->position.y, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate2 * rotate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->objecthand1);

    Matrices.model = glm::mat4(1.0f);
    translate = glm::translate (this->positionhand2);    // glTranslatef
    rotate    = glm::rotate((float) (-1*this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 1.5*this->l));
    rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(this->position.x, this->position.y, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate2 * rotate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->objecthand2);

    Matrices.model = glm::mat4(1.0f);
    translate = glm::translate (this->positionleg1);    // glTranslatef
    rotate    = glm::rotate((float) (-1*this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(this->position.x, this->position.y, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * rotate2);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->objectleg1);

    Matrices.model = glm::mat4(1.0f);
    translate = glm::translate (this->positionleg2);    // glTranslatef
    rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(this->position.x, this->position.y, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * rotate2);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->objectleg2);
//    draw3DObject(this->objectpole);
//    draw3DObject(this->objectbase);
//    draw3DObject(this->objectbf);
//    draw3DObject(this->objectcannon);
}

void Man::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
    this->positionhand1 = glm::vec3(x+2*this->l, y+0, z);
    this->positionhand2 = glm::vec3(x-2*this->l, y-0, z);
    this->positionleg1 = glm::vec3(x+this->l*1.5, y+0, z-this->l*3);
    this->positionleg2 = glm::vec3(x-this->l*1.5, y-0, z-this->l*3);
}

void Man::tick() {

//    if(this->speedz>0){
//        this->acc=-0.05;
//    }
//    this->speedz+=this->acc;
//    if(this->position.z<0){
//        printf("entered\n");
//        this->position.z=0;
//        this->acc=0;
//        this->speedz=0;
//        this->speedy=0;
//        this->speedx=0;
//    }
}


bounding_box_t Man::bounding_box(){
    if(fabs(tan(this->rotation*M_PI/180.0))<1)
    {
        bounding_box_t bbox = {this->position.x,this->position.y,this->position.z-3.0,4.0,9.0,0};
        return bbox;
    }
    bounding_box_t bbox = {this->position.x,this->position.y,this->position.z-3.0,9.0,4.0,0.0};
    return bbox;
}
