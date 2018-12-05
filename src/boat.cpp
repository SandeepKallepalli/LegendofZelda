#include "boat.h"
#include "main.h"
using namespace std;

Boat::Boat(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->health=50;
    this->score=0;
    man=true;
    speedx=0;
    speedy=0;
    speedz=0;
    acc=0;
    wind1=0;
    wind2=0;
    floatcount=0;
    boostcount=300;
    float l=3;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        1.0f,l,-3.0f, // triangle 1 : begin
        1.0f,-l,-3.0f,
        2.0f, -l, -2.0f, // triangle 1 : end

        2.0f, -l, -2.0f,  // triangle 1 : begin
        1.0f,l,-3.0f,
        2.0f, l, -2.0f, // triangle 1 : end

        -1.0f,l,-3.0f, // triangle 1 : begin
        -1.0f,-l,-3.0f,
        -2.0f, -l, -2.0f, // triangle 1 : end

        -2.0f, -l, -2.0f,  // triangle 1 : begin
        -1.0f,l,-3.0f,
        -2.0f, l, -2.0f, // triangle 1 : end

        2.0f, l+1, -2.0f,
        2.0f, l, -2.0f,
        1.0f,l,-3.0f,

        -2.0f, l+1, -2.0f,
        -2.0f, l, -2.0f,
        -1.0f,l,-3.0f,

        2.0f, l+1, -2.0f,
        1.0f,l,-3.0f,
        -1.0f,l,-3.0f,

        2.0f, l+1, -2.0f,
        -2.0f,l+1,-2.0f,
        -1.0f,l,-3.0f,



//        1.0f,-2.0f,-3.0f,
//        2.0f, -2.0f, -2.0f,
//        1.0f,-3.0f, -1.0f,

//        -1.0f,-2.0f,-3.0f,
//        -2.0f, -2.0f, -2.0f,
//        -1.0f,-3.0f, -1.0f,

//        1.0f,2.0f,-3.0f,
//        2.0f, 2.0f, -2.0f,
//        1.0f,3.0f, -1.0f,

//        -1.0f,2.0f,-3.0f,
//        -2.0f, 2.0f, -2.0f,
//        -1.0f,3.0f, -1.0f,


    };
    static const GLfloat vertex_buffer_databf[] = {
        //back and front of the boat
        1.0f,-l,-3.0f,
        2.0f, -l, -2.0f,
        1.0f,-l-1.5, -1.0f,

        -1.0f,-l,-3.0f,
        -2.0f, -l, -2.0f,
        -1.0f,-l-1.5, -1.0f,

        -1.0f,-l-1.5, -1.0f,
        1.0f,-l-1.5, -1.0f,
        -1.0f,-l,-3.0f,

        1.0f,-l-1.5, -1.0f,
        -1.0f,-l,-3.0f,
        1.0f,-l,-3.0f,

//        1.0f,2.0f,-3.0f,
//        2.0f, 2.0f, -2.0f,
//        1.0f,3.5f, -1.0f,

//        -1.0f,2.0f,-3.0f,
//        -2.0f, 2.0f, -2.0f,
//        -1.0f,3.5f, -1.0f,

    };
    static const GLfloat vertex_buffer_datapole[] = {
        -0.1f,-0.1f,-2.8f, // triangle 1 : begin
        -0.1f,-0.1f, 2.0f,
        -0.1f, 0.1f, 2.0f, // triangle 1 : end



        -0.1f,-0.1f,-2.8f,
        -0.1f, 0.1f, 2.0f,
        -0.1f, 0.1f,-2.8f,



        0.1f,-0.1f,-2.8f, // triangle 1 : begin
        0.1f,-0.1f, 2.0f,
        0.1f, 0.1f, 2.0f, // triangle 1 : end



        0.1f,-0.1f,-2.8f,
        0.1f, 0.1f, 2.0f,
        0.1f, 0.1f,-2.8f,

        -0.1f,-0.1f,-2.8f, // triangle 1 : begin
        -0.1f,-0.1f, 2.0f,
        0.1f, -0.1f,-2.8f,

        0.1f, -0.1f, 2.0f,
        0.1f, -0.1f,-2.8f,
        -0.1f, -0.1f, 2.0f,

        -0.1f,0.1f,-2.8f, // triangle 1 : begin
        -0.1f,0.1f, 2.0f,
        0.1f, 0.1f,-2.8f,

        0.1f, 0.1f, 2.0f,
        0.1f, 0.1f,-2.8f,
        -0.1f,0.1f, 2.0f,


    };
    static const GLfloat vertex_buffer_database[] = {
        1.0f,-l,-2.999f,
        1.0f,l,-2.999f,
        -1.0f,l,-2.999f,

        1.0f,-l,-2.999f,
        -1.0f,-l,-2.999f,
        -1.0f,l,-2.999f,
    };
    float r=1;
    lc=3;
    static GLfloat vertex_buffer_datacannon[3*2*360*5];
    float angle=0.0;
    for(int vertin=0;vertin<360*5;vertin++)
    {
        vertex_buffer_datacannon[vertin*6]=r*cos(angle);
        vertex_buffer_datacannon[vertin*6+1]=-lc/2-4;
        vertex_buffer_datacannon[vertin*6+2]=r*sin(angle);

        vertex_buffer_datacannon[vertin*6+3]=r*cos(angle);
        vertex_buffer_datacannon[vertin*6+4]=lc/2-4;
        vertex_buffer_datacannon[vertin*6+5]=r*sin(angle);
        angle+=M_PI/(180*5);
    };

    this->object = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_data, color, GL_FILL);
    this->objectbf = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_databf, color, GL_FILL);
    this->objectpole = create3DObject(GL_TRIANGLES, 8*3, vertex_buffer_datapole, COLOR_GREEN, GL_FILL);
    this->objectbase = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_database, COLOR_BASE, GL_FILL);
    this->objectcannon = create3DObject(GL_LINES, 360*2*5, vertex_buffer_datacannon, COLOR_BLACK, GL_FILL);
}

void Boat::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->objectpole);
    draw3DObject(this->objectbase);
    draw3DObject(this->objectbf);
    draw3DObject(this->objectcannon);
}

void Boat::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Boat::tick() {
    //this->rotation=this->rotation-int(this->rotation)+int(this->rotation)%180;
    //this->rotation += speed;
    //cout << this->position.x <<" "<< this->position.y <<" "<< this->position.z <<" " << "\n";
    //this->wind=rand()%3 - 1 ;
    if(this->boostcount<300){
        if(this->boostcount==0)
        {
            this->speedy=0.75;
        }
        this->boostcount+=1;
        if(this->boostcount==300){
            this->speedy=0;
        }
    }
    this->floatcount+=1;
    if(this->floatcount==600)
    {
        this->floatcount=0;
        this->wind1=rand()%3 - 1 ;
        this->wind2=rand()%3 - 1 ;
        if(this->wind1!=0||this->wind2!=0)
            system(" canberra-gtk-play -f  ./resources/ocean.wav --volume=\"1\"   &");
    }
    this->windx=0.05*this->wind1;
    this->windy=0.01*this->wind2;
    this->position.x -= speedx*cos(this->rotation*M_PI/180.0)-speedy*sin(this->rotation*M_PI/180.0);
    this->position.y -= speedy*cos(this->rotation*M_PI/180.0)+speedx*sin(this->rotation*M_PI/180.0);
    this->position.x -= windx;//*cos(this->rotation*M_PI/180.0)-windy*sin(this->rotation*M_PI/180.0);
    this->position.y -= windy;//*cos(this->rotation*M_PI/180.0)+windx*sin(this->rotation*M_PI/180.0);
    this->position.z += speedz;
    if(this->speedz>0){
        this->acc=-0.05;
    }
    this->speedz+=this->acc;
    if(this->position.z<0){
        printf("entered\n");
        this->position.z=0;
        this->acc=0;
        this->speedz=0;
        this->speedy=0;
        this->speedx=0;
    }
}


bounding_box_t Boat::bounding_box(){
    if(fabs(tan(this->rotation*M_PI/180.0))<1)
    {
        bounding_box_t bbox = {this->position.x,this->position.y,this->position.z-3.0,4.0,9.0,0};
        return bbox;
    }
    bounding_box_t bbox = {this->position.x,this->position.y,this->position.z-3.0,9.0,4.0,0.0};
    return bbox;
}
