#include "monster.h"
#include "main.h"
#include<math.h>
using namespace std;

Monster::Monster(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 45;
    alive=true;
    gift=false;
    boss=false;
    speedx = 0;
    speedy = 0;
    speedz = 0;
    acc=0;
    float t=2;
    float m=1.5;
    static const GLfloat vertex_buffer_data1[]={
        0,0,t,
        0,m/sqrt(3),0,
        -m/2,-m/(2*sqrt(3)),0,

        0,0,t,
        0,m/sqrt(3),0,
        m/2,-m/(2*sqrt(3)),0,

        0,0,t,
        m/2,-m/(2*sqrt(3)),0,
        -m/2,-m/(2*sqrt(3)),0,

    };
    static GLfloat vertex_buffer_data[3240*600];
    static GLfloat color_buffer_data[3240*600];
    int verin=0;
    float c1=0.9,c2=0.25;
    for(int i=-300;i<300;i++){
    float z=i/300.0;
    double r=1.5*fabs(sqrt(1-z*z));
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
    float l=0.5;
    float r=1.0;
    static GLfloat vertex_buffer_data3[3*2*360*5];
    float angle=0.0;
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
    static GLfloat vertex_buffer_data4[3240];
    angle=0.0;
    for(int vertin=0;vertin<360;vertin++)
     {
                vertex_buffer_data4[vertin*9]=0.0f;
                vertex_buffer_data4[vertin*9+1]=l/2;
                vertex_buffer_data4[vertin*9+2]=0.0;

                vertex_buffer_data4[vertin*9+3]=r*cos(angle);
                vertex_buffer_data4[vertin*9+4]=l/2;
                vertex_buffer_data4[vertin*9+5]=r*sin(angle);

                vertex_buffer_data4[vertin*9+6]=r*cos(angle+(M_PI/180.0));
                vertex_buffer_data4[vertin*9+7]=l/2;
                vertex_buffer_data4[vertin*9+8]=r*sin(angle+(M_PI/180.0));

                angle+=M_PI/180.0;
     };


    this->object = create3DObject(GL_TRIANGLES, 360*3*600, vertex_buffer_data, color_buffer_data, GL_FILL);
    this->objecthorn1 = create3DObject(GL_TRIANGLES, 3*3, vertex_buffer_data1, COLOR_RED, GL_FILL);
    this->objecthorn2 = create3DObject(GL_TRIANGLES, 3*3, vertex_buffer_data1, COLOR_RED, GL_FILL);
    this->objectgiftcurve= create3DObject(GL_LINES, 360*2*5, vertex_buffer_data3, COLOR_DGOLD, GL_FILL);
    this->objectgiftdisk1 = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data2,COLOR_GOLD , GL_FILL);
    this->objectgiftdisk2 = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data4, COLOR_GOLD, GL_FILL);
    this->giftcurve= create3DObject(GL_LINES, 360*2*5, vertex_buffer_data3, COLOR_DGOLD, GL_FILL);
    this->giftdisk1 = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data2,COLOR_GOLD , GL_FILL);
    this->giftdisk2 = create3DObject(GL_TRIANGLES, 360*3, vertex_buffer_data4, COLOR_GOLD, GL_FILL);
    //this->object = create3DObject(GL_TRIANGLES, 360*9*1, g_vertex_buffer_data, color, GL_FILL);
}

void Monster::draw(glm::mat4 VP) {
    if(this->alive)
    {
        Matrices.model = glm::mat4(1.0f);
        glm::mat4 translate = glm::translate (this->position);    // glTranslatef
        glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(0, 1, 0));
        glm::mat4 rotate1    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
        glm::mat4 rotate2    = glm::rotate((float) (-1*this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
        // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
        // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
        glm::mat4 MVP = VP * Matrices.model * (translate * rotate);
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(this->object);
        MVP = VP * Matrices.model * (translate * rotate1 );
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(this->objecthorn1);
        MVP = VP * Matrices.model * (translate * rotate2 );
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(this->objecthorn2);
    }
    if(this->gift && !this->alive)
    {
        //only if coin is not taken and monster in dead

        Matrices.model = glm::mat4(1.0f);
        glm::mat4 translate = glm::translate (this->position);    // glTranslatef
        glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
        glm::mat4 MVP = VP * Matrices.model * (translate * rotate);
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        if(this->boss){
        draw3DObject(this->giftdisk1);
        draw3DObject(this->giftdisk2);
        draw3DObject(this->giftcurve);
        }
        else
        {
            draw3DObject(this->objectgiftdisk1);
            draw3DObject(this->objectgiftdisk2);
            draw3DObject(this->objectgiftcurve);
        }
    }
}

void Monster::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Monster::tick() {
    //this->rotation += speed;
    //this->position.x -= speed;
    //this->position.y -= speed;
    if(this->boss)
        printf("boss tick\n");
    if(this->gift && !this->alive)
        this->rotation+=2;
    if(/*this->alive && */this->boss)
    {
        printf("boss\n");
        this->acc=-0.005;
        this->speedz+=this->acc;
        if(this->position.z<-4)
        {
            this->speedz=0.5;
        }
        if(this->alive)
        {
            this->position.x+=this->speedx;
            this->position.y+=this->speedy;
        }
        this->position.z+=this->speedz;
    }
}

bounding_box_t Monster::bounding_box(){
    if(this->alive)
    {
        bounding_box_t bbox={this->position.x,this->position.y,this->position.z,3.0,3.0,4.0};
        return bbox;
    }
    if(this->gift)
    {
        bounding_box_t bbox={this->position.x,this->position.y,this->position.z,2.0,2.0,2.0};
        return bbox;
    }
}
