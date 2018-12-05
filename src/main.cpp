#include "main.h"
#include "timer.h"
#include "ball.h"
#include "water.h"
#include "boat.h"
#include "rock.h"
#include "barrel.h"
#include "sail.h"
#include "monster.h"
#include "bullet.h"
#include "island.h"
#include "man.h"
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Man man;
Island island;
Ball ball1;
bool boss=false;
int nrocks=20;
Rock rock[20];
int nbarrels=10;
Barrel barrel[10];
int nmonsters=10;
Monster monster[15];
float nmonsterdead=0;
Boat boat;
Sail sail;
Water water;
Bullet bullet;
float screen_zoom = 0.15, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int nviews=3;
int cam=1;
float hangle1=0;
float hangle2=30;
float hradii=5;
float eyex;
float eyey;
float eyez;
float targetx;
float targety;
// 1 is for behind follow camera
// 2 is for boat view
// 3 is for top view
// still more views to add

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
//    glm::vec3 eye (  boat.position.x-7*sin(boat.rotation*M_PI/180.0),boat.position.y+7*cos(boat.rotation*M_PI/180.0),0);
//    //glm::vec3 eye (  5*sin(camera_rotation_angle*M_PI/180.0f) ,5*cos(camera_rotation_angle*M_PI/180.0f),0 );
//    //glm::vec3 eye (  boat.position.x ,boat.position.y,1 );
//    //glm::vec3 eye (  0,0,100);
//    // Target - Where is the camera looking at.  Don't change unless you are sure!!
//    //glm::vec3 target (boat.position.x+5*sin(boat.rotation*M_PI/180.0) ,boat.position.y-5*cos(boat.rotation*M_PI/180.0),1 );
//    glm::vec3 target (boat.position.x,boat.position.y,0);
//    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
//    glm::vec3 up (0, 0, 1);

    //behind follow
    if(cam==1)
    {
        if(boat.man){
        glm::vec3 eye (  boat.position.x-7*sin(boat.rotation*M_PI/180.0),boat.position.y+7*cos(boat.rotation*M_PI/180.0),0);
        glm::vec3 target (boat.position.x,boat.position.y,-3);
        glm::vec3 up (0, 0, 1);
        Matrices.view = glm::lookAt( eye, target, up );}
        else
        {
            glm::vec3 eye (  man.position.x+5,man.position.y,0);
            glm::vec3 target (man.position.x,man.position.y,-3);
            glm::vec3 up (0, 0, 1);
            Matrices.view = glm::lookAt( eye, target, up );
        }
    }

    //boat view
    if(cam==2)
    {
        glm::vec3 eye (  boat.position.x ,boat.position.y,0 );
        glm::vec3 target (boat.position.x+5*sin(boat.rotation*M_PI/180.0) ,boat.position.y-5*cos(boat.rotation*M_PI/180.0),1 );
        glm::vec3 up (0, 0, 1);
        Matrices.view = glm::lookAt( eye, target, up );
    }


    //top view
    if(cam==3)
    {
        glm::vec3 eye (  0,0,50);
        glm::vec3 target (0,0,0);
        glm::vec3 up (0, -1, 0);
        Matrices.view = glm::lookAt( eye, target, up );
    }


    //behind view
    if(cam==4)
    {
        //glm::vec3 eye (  5*sin(camera_rotation_angle*M_PI/180.0f) ,5*cos(camera_rotation_angle*M_PI/180.0f),5 );
        glm::vec3 eye (0,5,5);
        glm::vec3 target (boat.position.x,boat.position.y,boat.position.z);
        glm::vec3 up (0, 0, 1);
        Matrices.view = glm::lookAt( eye, target, up );
    }
    if(cam==5)
    {
        double xpos;
        double ypos;
        printf("hey\n");
        glfwGetCursorPos(window,&xpos,&ypos);
        printf("%lf %lf\n",xpos,ypos);
//        if(eyex-boat.position.x>=0)
//        {
//            if(sin(boat.rotation*M_PI/180)>=0)
//                eyex+=0.1*(xpos-300)/300;
//            else
//                eyey-=0.1*(ypos-300)/300;
//        }
//        else
//        {
//            if(sin(boat.rotation*M_PI/180)>=0)
//                eyex-=0.1*(xpos-300)/300;
//            else
//                eyey+=0.1*(ypos-300)/300;
//        }
//        if(eyey-boat.position.y>=0)
//        {
//            eyey-=0.1*(ypos-300)/300;
//        }
//        else
//        {
//            eyey+=0.1*(ypos-300)/300;
//        }
        if(xpos>400)
        {
            //right
            if(fabs(hangle1+0.5)!=90+boat.rotation)
                hangle1+=0.5;
        }
        else if(xpos<200)
        {
            if( fabs(hangle1-0.5)!=90-boat.rotation)
                hangle1-=0.5;
        }
        if(ypos>400)
        {
            //right
            if(fabs(hangle2-0.5)!=15 && fabs(hangle2-0.5)!=90)
                hangle2-=0.5;
        }
        else if(ypos<200)
        {
            if(fabs(hangle2+0.5)!=15 && fabs(hangle2+0.5)!=90){
                hangle2+=0.5;
                printf("%f\n",hangle2);
            }
        }
        if(hangle2!=90){
        eyex=boat.position.x - hradii*sin(hangle1*M_PI/180.0)*sin(hangle2*M_PI/180.0);
        eyey=boat.position.y + hradii*cos(hangle1*M_PI/180.0)*cos(hangle2*M_PI/180.0);}
        else
        {
            eyex=boat.position.x;
            eyey=boat.position.y;
        }
        eyez=boat.position.z + hradii*cos(hangle2*M_PI/180.0);

        //glm::vec3 eye (eyex*cos(boat.rotation*M_PI/180.0) + eyey*sin(boat.rotation*M_PI/180.0),eyex*sin(boat.rotation*M_PI/180.0) + eyey*cos(boat.rotation*M_PI/180.0),eyez);
        glm::vec3 eye (eyex,eyey,eyez);
        targetx=boat.position.x;
        targety=boat.position.y;

        glm::vec3 target (targetx,targety,boat.position.z);
        glm::vec3 up (0, 0, 1);
        Matrices.view = glm::lookAt( eye, target, up );
    }




    // Compute Camera matrix (view)
     // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    //ball1.draw(VP);
    for(int i=0;i<nbarrels;i++)
        barrel[i].draw(VP);
    water.draw(VP);
    for(int i=0;i<nrocks;i++)
        rock[i].draw(VP);
    boat.draw(VP);
    sail.draw(VP);
    for(int i=0;i<nmonsters;i++)
        if(monster[i].alive || monster[i].gift)
            monster[i].draw(VP);
    bullet.draw(VP);
    island.draw(VP);
    if(!boat.man)
        man.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int land = glfwGetKey(window,GLFW_KEY_L);
    int p = glfwGetKey(window,GLFW_KEY_P);
    int cam1 = glfwGetKey(window, GLFW_KEY_1);
    int cam2 = glfwGetKey(window, GLFW_KEY_2);
    int cam3 = glfwGetKey(window, GLFW_KEY_3);
    int cam4 = glfwGetKey(window, GLFW_KEY_4);
    int cam5 = glfwGetKey(window, GLFW_KEY_5);
    int chara = glfwGetKey(window, GLFW_KEY_A);
    int chard = glfwGetKey(window, GLFW_KEY_D);
    int charf = glfwGetKey(window, GLFW_KEY_F);
    int lmouse = glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT);
    if(land){
        boat.man=false;
        if(island.position.x>boat.position.x)
            man.position.x+=0.1;
        else
            man.position.x-=0.1;
        if(island.position.y>boat.position.y)
            man.position.y+=0.1;
        else
            man.position.y-=0.1;
        //man.position.z = island.position.z + sqrt(4 - (man.position.x*man.position.x + man.position.y*man.position.y)/10000.0);
        //printf("landed\n");
    }
    if(p)
        boat.man=true;
    if(charf)
    {
        //bullet fired
        system(" canberra-gtk-play -f  ./resources/cannon.wav --volume=\"1\"   &");
        bullet.set_position(boat.position.x-(-boat.lc/2-4)*sin(boat.rotation*M_PI/180.0),boat.position.y+(-boat.lc/2-4)*cos(boat.rotation*M_PI/180.0),boat.position.z);
        bullet.rotation = boat.rotation;
        bullet.speedy = 2.0;
        bullet.speedz = 0.5;
        bullet.acc = -1.0;
    }
    if(cam1)
    {
        cam=1;
    }
    if(cam2)
    {
        cam=2;
    }
    if(cam3)
    {
        cam=3;
    }
    if(cam4)
    {
        cam=4;
    }
    if(cam5)
    {
        cam=5;
        eyex=0;
        eyey=0;
        targetx=boat.position.x;
        targety=boat.position.y;

    }
    if(space){
        if(boat.man)
        {
            if(boat.position.z==0){
                system(" canberra-gtk-play -f  ./resources/jump.wav --volume=\"1\"   &");
                boat.speedz=0.5;
                boat.speedy=0.65;
                //boat.speedx=+0.3;
            }
        }
    }
    if(chara){
        camera_rotation_angle-=1;
    }
    if(chard){
        camera_rotation_angle+=1;
    }
    if (left) {
        // Do something
        //camera_rotation_angle-=1;
        if(boat.man)
            boat.rotation+=3;
        else
            man.position.x-=0.1;
    }
    if(right)
    {
        //camera_rotation_angle+=1;
        if(boat.man)
            boat.rotation-=3;
        else
            man.position.x+=0.1;
    }
    if(down)
    {
        //water.rotation+=1;
        //ball1.rotation+=1;
        if(boat.man){
            boat.position.y+=0.3*cos(boat.rotation*M_PI/180.0);
            boat.position.x-=0.3*sin(boat.rotation*M_PI/180.0);
        }
        else
        {
            man.position.y-=0.1;
            if(man.flag)
                man.rotation=45;
            else
                man.rotation=-45;
            man.flag=!man.flag;
        }
        //rock.rotation+=1;
    }
    if(up)
    {
        if(boat.man){
            boat.position.y-=0.3*cos(boat.rotation*M_PI/180.0);
            boat.position.x+=0.3*sin(boat.rotation*M_PI/180.0);
        }
        else
        {
            man.position.y+=0.1;
            if(man.flag)
                man.rotation=45;
            else
                man.rotation=-45;
            man.flag=!man.flag;
        }
    }
}

void tick_elements() {
    //cout<<cam<<"\n";
    if(boat.health<0)//if health is over
        quit(window);
    ball1.tick();
    if(boat.man)
        boat.tick();
    if(boat.man)
        man.position=boat.position;
    //man.rotation2=boat.rotation;
    //man.positionhand1.x
    if(!boat.man)
        man.tick();
    bullet.tick();
    for(int i=0;i<nbarrels;i++)
        barrel[i].tick();
    for(int i=0;i<nmonsters;i++)
    {
        if(!monster[i].boss && monster[i].alive && boss)
        {
            monster[i].boss=true;
            monster[i].speedz=0.4;
            monster[i].speedx=-0.1*(monster[i].position.x-boat.position.x)/fabs(monster[i].position.x-boat.position.x);
            monster[i].speedy=-0.1*(monster[i].position.y-boat.position.y)/fabs(monster[i].position.y-boat.position.y);
            boss=false;
        }
        if(/*monster[i].alive && */monster[i].boss)
        {
            if(monster[i].position.z<-4)
            {
                monster[i].speedx=-0.1*(monster[i].position.x-boat.position.x)/fabs(monster[i].position.x-boat.position.x);
                monster[i].speedy=-0.1*(monster[i].position.y-boat.position.y)/fabs(monster[i].position.y-boat.position.y);
                monster[i].speedz=0.5;
            }
        }
        monster[i].tick();
    }
    sail.set_position(boat.position.x,boat.position.y,boat.position.z);
    if(cos(boat.rotation)>=0)
        sail.rotation=boat.rotation+boat.wind1*30;
    else
        sail.rotation=boat.rotation-boat.wind1*30;
    for(int i=0;i<nrocks;i++)
        if(detect_collision(rock[i].bounding_box(),boat.bounding_box()))
        {
            if(rock[i].bounding_box().x>boat.bounding_box().x)
                boat.set_position(boat.position.x-1,boat.position.y);
            else
                boat.set_position(boat.position.x+1,boat.position.y);
            if(rock[i].bounding_box().y>boat.bounding_box().y)
                boat.set_position(boat.position.x,boat.position.y-1);
            else
                boat.set_position(boat.position.x,boat.position.y+1);
            boat.health-=2;
        }
    for(int i=0;i<nbarrels;i++)
        if(detect_collision(barrel[i].bounding_box(),boat.bounding_box()))
        {
            //printf("collide123456!!!!\n");
            if(! (boat.position.z>0.5))
            {
                //printf("collide!!!!\n");
                if(barrel[i].bounding_box().x>boat.bounding_box().x)
                    boat.set_position(boat.position.x-1,boat.position.y);
                else
                    boat.set_position(boat.position.x+1,boat.position.y);
                if(barrel[i].bounding_box().y>boat.bounding_box().y)
                    boat.set_position(boat.position.x,boat.position.y-1);
                else
                    boat.set_position(boat.position.x,boat.position.y+1);
                boat.health-=1;
            }
            else
            {
                barrel[i].status=1;
                //increase boats score
                boat.score+=2+rand()%5;
                system(" canberra-gtk-play -f  ./resources/gift.wav --volume=\"1\"   &");
            }
        }
    for(int i=0;i<nmonsters;i++){
        if(monster[i].alive && detect_collision(monster[i].bounding_box(),bullet.bounding_box()))
        {
            //printf("bullet collided\n");
            //bullet collided with monster
            //increase score
            //get bonus
            if(monster[i].boss){
                boat.score+=20;
                system(" canberra-gtk-play -f  ./resources/boss.wav --volume=\"1\"   &");
            }
            else
            {
                nmonsterdead+=1;
                boat.score+=10;
                if(nmonsterdead/3.0==floor(nmonsterdead/3.0))
                {
                    boss=true;
                    system(" canberra-gtk-play -f  ./resources/boss.wav --volume=\"1\"   &");
                }
            }
            monster[i].alive=false;
            monster[i].gift=true;

        }
        if(monster[i].alive && detect_collision(boat.bounding_box(),monster[i].bounding_box()))
        {
            boat.health-=5;
            if(monster[i].bounding_box().x>boat.bounding_box().x)
                boat.set_position(boat.position.x-2,boat.position.y);
            else
                boat.set_position(boat.position.x+2,boat.position.y);
            if(monster[i].bounding_box().y>boat.bounding_box().y)
                boat.set_position(boat.position.x,boat.position.y-2);
            else
                boat.set_position(boat.position.x,boat.position.y+2);
        }
        if(!monster[i].alive && monster[i].gift && detect_collision(boat.bounding_box(),monster[i].bounding_box()))
        {
            monster[i].gift=false;
            system(" canberra-gtk-play -f  ./resources/gift.wav --volume=\"1\"   &");
            //increase score
            if(monster[i].boss)
            {
                //gets boost and score
                //intialize boost count
                boat.boostcount=0;
                boat.score+=20;
            }
            else
            {
                boat.score+=10;
            }
        }
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    man         = Man(boat.position.x,boat.position.y,-1);
    island      = Island(100,-500,-3,COLOR_BASE);
    ball1       = Ball(0, 0, COLOR_RED);
    water       = Water(0,0,COLOR_WATER);
    boat        = Boat(0,0,COLOR_BROWN);
    sail        = Sail(boat.position.x,boat.position.y,boat.position.z);
    //monster     = Monster(2,2,-2,COLOR_RED);
    bullet      = Bullet(100,100,100,COLOR_RED);
    for(int i=0;i<nbarrels;i++)
    {
        barrel[i]      =    Barrel(2*(2*(rand()%2)-1)*(rand()%30),2*(2*(rand()%2)-1)*(rand()%30),-3.5,COLOR_BASE);
        while(detect_collision(barrel[i].bounding_box(),boat.bounding_box()))
            barrel[i]      =    Barrel(2*(2*(rand()%2)-1)*(rand()%30),2*(2*(rand()%2)-1)*(rand()%30),-3.5,COLOR_BASE);
    }


    for(int i=0;i<nrocks;i++)
    {
        rock[i]        = Rock(2*(2*(rand()%2)-1)*(rand()%30),2*(2*(rand()%2)-1)*(rand()%30),COLOR_ROCK);
        while(detect_collision(rock[i].bounding_box(),boat.bounding_box()))
        {
            rock[i]        = Rock(2*(2*(rand()%2)-1)*(rand()%30),2*(2*(rand()%2)-1)*(rand()%30),COLOR_ROCK);
        }
    }

    for(int i=0;i<nmonsters;i++)
    {
        monster[i]      =    Monster(2*(2*(rand()%2)-1)*(rand()%30),2*(2*(rand()%2)-1)*(rand()%30),-2,COLOR_BASE);
        while(detect_collision(monster[i].bounding_box(),boat.bounding_box()))
            monster[i]      =    Monster(2*(2*(rand()%2)-1)*(rand()%30),2*(2*(rand()%2)-1)*(rand()%30),-2,COLOR_BASE);
    }

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            string player_score,player_level;
            stringstream Score,Levels;
            Score << boat.score;
            player_score = Score.str();

                        const char *score_string = "Score ";
                        const char *score_value = player_score.c_str();
                        const char *Level = "   Health ";
                        Levels << boat.health;

                        player_level = Levels.str();
                        const char *level_value = player_level.c_str();
                        string total( string(score_string) + score_value + string(Level) + level_value);
                        glfwSetWindowTitle(window, total.c_str());
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    float ap=0.3;
    return (fabs(a.x - b.x) * 2 < (a.widthx + b.widthx)+ap) &&
           (fabs(a.y - b.y) * 2 < (a.widthy + b.widthy)+ap) &&
           (fabs(a.z - b.z) * 2 < (a.height + b.height)+ap);
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
//    if(cam==3)
    //Matrices.projection = glm::ortho(left, right, bottom, top, 5.0f, 500.0f);
//    else
        Matrices.projection = glm::infinitePerspective(glm::radians(90.0f), 2.0f,1.0f);
}
