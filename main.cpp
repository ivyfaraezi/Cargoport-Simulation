#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isRaining = false;
const int numDrops = 300;
float rainX[numDrops];
float rainY[numDrops];
float moveXh = 0.0f;
float moveY = 0.0f;
float movecY = 0.0f;
float movecX = 0.0f;
float moveShip = 0.0f;
float moveShip3 = -43.0f;
float shipSpeed = 0.02;
float speed = 0.05f;
float truckX = 0.0f;
float stringY = 0.0f;
float cloudX = 0.0f;
bool pick = false;
bool release = false;
bool ship_start = false;
bool ship_start2 = false;
bool ship_start3 = false;
bool train_start2 = false;
bool trainMovedOnce = false;
bool truckStart = false;
bool isDayScene = true;
bool trainSoundPlayed = false;
int currentDisplay = 1;
bool showRestartMessage = false;
float waveOffset = 0.0f;
struct Bird
{
    float x, y, wingPhase;
    float speed;
};
const int NUM_BIRDS = 6;
Bird birds[NUM_BIRDS];
bool birdsInitialized = false;

//Sky darkening / thunderstorm
float skyDarkness = 0.0f;
bool stormActive = true;
float lightningAlpha = 0.0f;
float lightningTimer = 0.0f;
float nextLightningAt = 2.5f;

//Cloud movement for Scenario 3
float s3CloudX1 = 2.0f;
float s3CloudX2 = 18.0f;
float s3CloudSpeed = 0.005f;

void set_color(string col)
{
    if (isDayScene == true)
    {
        // Scenario 1
        // Road
        if (col == "Emperor")
            glColor3ub(85, 74, 75);
        else if (col == "Scorpion")
            glColor3ub(110, 99, 100);
        else if (col == "Black")
            glColor3ub(0, 0, 0);
        else if (col == "Thunder")
            glColor3ub(23, 20, 21);

        // Warehouse
        else if (col == "Tango")
            glColor3ub(238, 126, 32);
        else if (col == "Hawaiian Tan")
            glColor3ub(165, 86, 20);
        else if (col == "warehouse1")
            glColor3ub(165, 86, 20);
        else if (col == "Hairy Heath")
            glColor3ub(103, 45, 19);
        else if (col == "Tango_Dark")
            glColor3ub(71, 38, 10);
        else if (col == "White")
            glColor3ub(255, 255, 255);
        else if (col == "Old Copper")
            glColor3ub(119, 63, 50);
        else if (col == "Firefly")
            glColor3ub(9, 22, 28);
        else if (col == "Maroon")
            glColor3ub(71, 13, 33);
        else if (col == "Jazzberry")
            glColor3ub(156, 15, 72);
        else if (col == "Neon")
            glColor3ub(174, 214, 241);
        else if (col == "LNeon")
            glColor3ub(214, 234, 248);

        // ocean
        else if (col == "1")
            glColor3ub(18, 153, 201);
        else if (col == "2")
            glColor3ub(49, 196, 218);
        else if (col == "3")
            glColor3ub(91, 244, 225);
        else if (col == "4")
            glColor3ub(100, 230, 230);

        // ship
        else if (col == "window")
            glColor3ub(255, 194, 113);
        else if (col == "ship_side")
            glColor3ub(0, 38, 84);
        else if (col == "ship_side1")
            glColor3ub(243, 156, 18);
        else if (col == "chimney")
            glColor3ub(125, 2, 30);
        else if (col == "ship_window")
            glColor3ub(0, 150, 136);
        else if (col == "Ship_Border")
            glColor3ub(169, 50, 38);
        else if (col == "Off white")
            glColor3ub(153, 163, 164);
        else if (col == "ship_body")
            glColor3ub(97, 106, 107);
        else if (col == "ship_body2")
            glColor3ub(178, 186, 187);
        else if (col == "Top_floor")
            glColor3ub(224, 224, 224);
        else if (col == "Railing")
            glColor3ub(214, 219, 223);

        // sky
        else if (col == "skyL")
            glColor3ub(128, 201, 242);
        else if (col == "skyM")
            glColor3ub(0, 172, 246);
        else if (col == "skyD")
            glColor3ub(0, 112, 214);

        // Crane Bg
        else if (col == "BcraneLeg")
            glColor3ub(31, 97, 141);
        else if (col == "Fuel Yellow")
            glColor3ub(232, 178, 37);
        else if (col == "BcraneRoom")
            glColor3ub(138, 18, 32);
        else if (col == "BcraneContainer")
            glColor3ub(194, 113, 74);

        // Cargo ship
        else if (col == "Cship_floor")
            glColor3ub(219, 99, 75);
        else if (col == "Cship_shadow")
            glColor3ub(201, 86, 66);
        else if (col == "Crail")
            glColor3ub(180, 71, 61);
        else if (col == "Japonica")
            glColor3ub(215, 116, 89);

        // Lights
        else if (col == "Red light")
            glColor3ub(44, 62, 80);
        else if (col == "cloud")
            glColor3ub(255, 255, 255);

        // Scenario 2
        else if (col == "sky")
            glColor3ub(176, 225, 255);
        else if (col == "skyCU")
            glColor3ub(13, 163, 222);
        else if (col == "skyCD")
            glColor3ub(0, 89, 191);
        else if (col == "waterCU")
            glColor3ub(18, 146, 173);
        else if (col == "waterCD")
            glColor3ub(75, 117, 232);
        else if (col == "buildingglass")
            glColor3ub(122, 194, 244);
        else if (col == "bulidingcolor")
            glColor3ub(120, 79, 87);
        else if (col == "buildingShadow")
            glColor3ub(166, 212, 246);
        else if (col == "twintower")
            glColor3ub(100, 136, 160);
        else if (col == "brick")
            glColor3ub(175, 44, 35);
        else if (col == "midBuilding")
            glColor3ub(251, 154, 127);
        else if (col == "frontBuilding")
            glColor3ub(116, 142, 161);
        else if (col == "trainGlass")
            glColor3ub(146, 168, 175);
        else if (col == "background")
            glColor3ub(215, 216, 215);
        else if (col == "trainwindow")
            glColor3ub(37, 150, 190);
        else if (col == "traindoor")
            glColor3ub(124, 57, 85);
        else if (col == "bridgerailc")
            glColor3ub(100, 96, 92);
        else if (col == "SunC")
            glColor3ub(255, 187, 68);
        else if (col == "DewC")
            glColor3ub(236, 247, 248);

        // Scenario 3 - Sky (teal at top fading to cyan)
        else if (col == "S3_sky4")
            glColor3ub(64, 210, 193);
        else if (col == "S3_sky3")
            glColor3ub(72, 209, 204);
        else if (col == "S3_sky2")
            glColor3ub(100, 220, 210);
        else if (col == "S3_sky1")
            glColor3ub(140, 230, 220);

        // Scenario 3 - Sea (dark navy at horizon to lighter blue at bottom)
        else if (col == "S3_sea7")
            glColor3ub(18, 40, 80);
        else if (col == "S3_sea6")
            glColor3ub(22, 55, 105);
        else if (col == "S3_sea5")
            glColor3ub(30, 80, 140);
        else if (col == "S3_sea4")
            glColor3ub(45, 110, 175);
        else if (col == "S3_sea3")
            glColor3ub(70, 145, 200);
        else if (col == "S3_sea2")
            glColor3ub(100, 170, 220);
        else if (col == "S3_sea1")
            glColor3ub(130, 195, 235);
    }
    else if (isDayScene == false)
    {

        // _________________________NIGHT______________________________________________________________________________________

        // Road
        if (col == "Emperor")
            glColor3ub(43, 37, 38);
        else if (col == "Scorpion")
            glColor3ub(51, 44, 45);
        else if (col == "Black")
            glColor3ub(0, 0, 0);
        else if (col == "Thunder")
            glColor3ub(33, 29, 30);

        // Warehouse
        else if (col == "Tango")
            glColor3ub(167, 88, 22);
        else if (col == "Hawaiian Tan")
            glColor3ub(132, 69, 16);
        else if (col == "warehouse1")
            glColor3ub(167, 88, 22);
        else if (col == "Hairy Heath")
            glColor3ub(72, 31, 13);
        else if (col == "Tango_Dark")
            glColor3ub(50, 27, 7);
        else if (col == "White")
            glColor3ub(229, 231, 233);
        else if (col == "Old Copper")
            glColor3ub(89, 57, 36);
        else if (col == "Firefly")
            glColor3ub(9, 22, 28);
        else if (col == "Maroon")
            glColor3ub(61, 12, 17);
        else if (col == "Jazzberry")
            glColor3ub(93, 6, 53);

        // neon
        else if (col == "Neon")
            glColor3ub(133, 146, 158);
        else if (col == "LNeon")
            glColor3ub(174, 182, 191);

        // ocean
        else if (col == "1")
            glColor3ub(14, 122, 161);
        else if (col == "2")
            glColor3ub(34, 137, 153);
        else if (col == "3")
            glColor3ub(64, 156, 158);
        else if (col == "4")
            glColor3ub(80, 184, 184);

        // ship
        else if (col == "window")
            glColor3ub(249, 231, 159);
        else if (col == "ship_side")
            glColor3ub(46, 64, 83);
        else if (col == "ship_side1")
            glColor3ub(185, 119, 14);
        else if (col == "chimney")
            glColor3ub(50, 1, 12);
        else if (col == "ship_window")
            glColor3ub(244, 208, 63);
        else if (col == "Ship_Border")
            glColor3ub(100, 30, 22);
        else if (col == "Off white")
            glColor3ub(112, 123, 124);
        else if (col == "ship_body")
            glColor3ub(66, 73, 73);
        else if (col == "ship_body2")
            glColor3ub(153, 163, 164);
        else if (col == "Top_floor")
            glColor3ub(215, 219, 221);
        else if (col == "Railing")
            glColor3ub(166, 172, 175);

        // sky
        else if (col == "skyL")
            glColor3ub(121, 135, 174);
        else if (col == "skyM")
            glColor3ub(8, 27, 68);
        else if (col == "skyD")
            glColor3ub(9, 16, 35);

        // Crane Bg
        else if (col == "BcraneLeg")
            glColor3ub(52, 73, 94);
        else if (col == "Fuel Yellow")
            glColor3ub(186, 143, 29);
        else if (col == "BcraneRoom")
            glColor3ub(125, 54, 49);
        else if (col == "BcraneContainer")
            glColor3ub(175, 102, 67);

        // Cargo ship
        else if (col == "Cship_floor")
            glColor3ub(131, 59, 45);
        else if (col == "Cship_shadow")
            glColor3ub(131, 59, 45);
        else if (col == "Crail")
            glColor3ub(144, 57, 49);
        else if (col == "Japonica")
            glColor3ub(172, 93, 71);

        // Lights
        else if (col == "Red light")
            glColor3ub(231, 76, 60);

        // Scenario 2
        else if (col == "night")
            glColor3ub(84, 85, 87);
        else if (col == "skyCU")
            glColor3ub(68, 97, 115);
        else if (col == "skyCD")
            glColor3ub(2, 24, 38);
        else if (col == "white")
            glColor3ub(91, 157, 169);
        else if (col == "bulidingcolor")
            glColor3ub(96, 63, 70);
        else if (col == "buildingglass")
            glColor3ub(255, 228, 9);
        else if (col == "buildingShadow")
            glColor3ub(116, 148, 172);
        else if (col == "twintower")
            glColor3ub(100, 136, 160);
        else if (col == "cloud")
            glColor3ub(79, 132, 150);
        else if (col == "lightBuilding")
            glColor3ub(116, 148, 172);
        else if (col == "midBuilding")
            glColor3ub(201, 123, 102);
        else if (col == "frontBuilding")
            glColor3ub(93, 114, 129);
        else if (col == "trainGlass")
            glColor3ub(65, 117, 139);
        else if (col == "traindoor")
            glColor3ub(112, 51, 77);
        else if (col == "trainwindow")
            glColor3ub(251, 232, 35);
        else if (col == "bridgerailc")
            glColor3ub(100, 96, 92);
        else if (col == "nightTwindow")
            glColor3ub(253, 242, 133);
        else if (col == "nightstars")
            glColor3ub(247, 248, 243);
        else if (col == "MoonD")
            glColor3ub(255, 255, 255);
        else if (col == "DewC")
            glColor3ub(236, 247, 248);

        // Scenario 3 Night - Sky (dark navy/indigo, matching screenshot)
        else if (col == "S3_sky4")
            glColor3ub(10, 14, 45);
        else if (col == "S3_sky3")
            glColor3ub(15, 22, 62);
        else if (col == "S3_sky2")
            glColor3ub(22, 35, 80);
        else if (col == "S3_sky1")
            glColor3ub(32, 50, 100);

        // Scenario 3 Night - Sea (dark steel-blue, matching screenshot)
        else if (col == "S3_sea7")
            glColor3ub(28, 45, 75);
        else if (col == "S3_sea6")
            glColor3ub(35, 55, 88);
        else if (col == "S3_sea5")
            glColor3ub(42, 68, 105);
        else if (col == "S3_sea4")
            glColor3ub(55, 85, 125);
        else if (col == "S3_sea3")
            glColor3ub(68, 105, 148);
        else if (col == "S3_sea2")
            glColor3ub(82, 125, 165);
        else if (col == "S3_sea1")
            glColor3ub(98, 145, 182); // bottom: lightest steel-blue
    }
}

// Common Design
void design1(float Sx, float Sy, float Tx, float Ty, float An, float Ax, float Ay, float Az, int R, int G, int B){
        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glRotatef(An,Ax,Ay,Az);


            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(R, G, B);
            glVertex2f(-0.120f, -0.476f);
            glVertex2f(-0.107f, -0.52f);
            glVertex2f(-0.062f, -0.468f);
            glVertex2f(-0.020f, -0.468f);
            glVertex2f(-0.036f, -0.5f);
            glVertex2f(-0.056f, -0.516f);
            glVertex2f(-0.071f, -0.575f);
            glVertex2f(-0.129f, -0.607f);
            glVertex2f(-0.076f, -0.626f);
            glVertex2f(-0.093f, -0.65f);
            glVertex2f(-0.213f, -0.725f);
            glVertex2f(-0.251f, -0.765f);
            glVertex2f(-0.273f, -0.792f);
            glVertex2f(-0.307f, -0.804f);
            glVertex2f(-0.353f, -0.785f);
            glVertex2f(-0.327f, -0.773f);
            glVertex2f(-0.293f, -0.773f);
            glVertex2f(-0.273f, -0.706f);
            glVertex2f(-0.282f, -0.646f);
            glVertex2f(-0.258f, -0.607f);
            glVertex2f(-0.282f, -0.397f);
            glVertex2f(-0.256f, -0.425f);
            glVertex2f(-0.258f, -0.468f);
            glVertex2f(-0.227f, -0.441f);
            glVertex2f(-0.242f, -0.342f);
            glVertex2f(-0.202f, -0.338f);
            glVertex2f(-0.238f, -0.18f);
            glVertex2f(-0.204f, -0.192f);
            glVertex2f(-0.169f, -0.089f);
            glVertex2f(-0.144f, -0.097f);
            glVertex2f(-0.098f, -0.049f);
            glVertex2f(-0.024f, 0.049f);
            glVertex2f(-0.031f, -0.006f);
            glVertex2f(-0.053f, -0.053f);
            glVertex2f(0.011f, -0.077f);
            glVertex2f(-0.033f, -0.144f);
            glVertex2f(-0.053f, -0.18f);
            glVertex2f(-0.038f, -0.247f);
            glVertex2f(-0.002f, -0.298f);
            glVertex2f(-0.047f, -0.338f);
            glVertex2f(-0.029f, -0.397f);
            glEnd();
            glPopMatrix();

}

void design2(float Sx, float Sy, float Tx, float Ty, float An, float Ax, float Ay, float Az, int R, int G, int B){

        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glRotatef(An,Ax,Ay,Az);

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(R, G, B);
            glVertex2f(-0.611f, 0.125f);
            glVertex2f(-0.529f, 0.14f);
            glVertex2f(-0.464f, 0.283f);
            glVertex2f(-0.262f, 0.374f);
            glVertex2f(-0.291f, 0.211f);
            glVertex2f(-0.467f, 0.117f);
            glVertex2f(-0.451f, -0.101f);
            glVertex2f(-0.676f, -0.342f);
            glVertex2f(-0.629f, -0.543f);
            glVertex2f(-0.469f, -0.417f);
            glVertex2f(-0.562f, -0.662f);
            glVertex2f(-0.704f, -0.962f);
            glVertex2f(-0.951f, -0.982f);
            glVertex2f(-0.978f, -0.978f);
            glVertex2f(-0.958f, -0.785f);
            glVertex2f(-0.898f, -0.694f);
            glVertex2f(-0.909f, -0.457f);
            glVertex2f(-0.873f, -0.381f);
            glVertex2f(-0.849f, -0.057f);
            glVertex2f(-0.853f, 0.196f);
            glVertex2f(-0.807f, 0.377f);
            glVertex2f(-0.667f, 0.749f);
            glVertex2f(-0.593f, 0.848f);
            glVertex2f(-0.431f, 0.836f);
            glVertex2f(-0.251f, 0.927f);
            glVertex2f(-0.087f, 0.907f);
            glVertex2f(-0.169f, 0.86f);
            glVertex2f(-0.302f, 0.828f);
            glVertex2f(-0.393f, 0.662f);
            glVertex2f(-0.469f, 0.587f);
            glVertex2f(-0.473f, 0.437f);
            glVertex2f(-0.580f, 0.302f);
            glEnd();

            glPopMatrix();

}

void design3(float Sx, float Sy, float Tx, float Ty, float An, float Ax, float Ay, float Az, int R, int G, int B){

        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glRotatef(An,Ax,Ay,Az);

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(R, G, B);
            glVertex2f(-0.182f, -0.026f);
            glVertex2f(-0.182f, -0.156f);
            glVertex2f(-0.173f, -0.468f);
            glVertex2f(-0.156f, -0.757f);
            glVertex2f(-0.144f, -0.883f);
            glVertex2f(-0.138f, -0.856f);
            glVertex2f(-0.122f, -0.804f);
            glVertex2f(-0.104f, -0.654f);
            glVertex2f(-0.096f, -0.583f);
            glVertex2f(-0.080f, -0.508f);
            glVertex2f(-0.058f, -0.358f);
            glVertex2f(-0.053f, -0.231f);
            glVertex2f(-0.051f, -0.113f);
            glVertex2f(-0.053f, 0.144f);
            glVertex2f(-0.053f, 0.196f);
            glVertex2f(-0.062f, 0.334f);
            glVertex2f(-0.087f, 0.52f);
            glVertex2f(-0.093f, 0.638f);
            glVertex2f(-0.093f, 0.733f);
            glVertex2f(-0.087f, 0.792f);
            glVertex2f(-0.100f, 0.757f);
            glVertex2f(-0.084f, 0.792f);
            glVertex2f(-0.131f, 0.654f);
            glVertex2f(-0.149f, 0.484f);
            glVertex2f(-0.176f, 0.255f);
            glEnd();

            glPopMatrix();
}

void design4(float Sx, float Sy, float Tx, float Ty, float An, float Ax, float Ay, float Az, int R, int G, int B){
        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glRotatef(An,Ax,Ay,Az);
            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(R,G,B);
            glVertex2f(-0.462f, -0.061f);
            glVertex2f(-0.458f, -0.081f);
            glVertex2f(-0.464f, -0.239f);
            glVertex2f(-0.438f, -0.275f);
            glVertex2f(-0.420f, -0.291f);
            glVertex2f(-0.398f, -0.338f);
            glVertex2f(-0.409f, -0.464f);
            glVertex2f(-0.409f, -0.524f);
            glVertex2f(-0.384f, -0.567f);
            glVertex2f(-0.353f, -0.634f);
            glVertex2f(-0.258f, -0.646f);
            glVertex2f(-0.196f, -0.674f);
            glVertex2f(-0.220f, -0.674f);
            glVertex2f(-0.280f, -0.698f);
            glVertex2f(-0.296f, -0.698f);
            glVertex2f(-0.333f, -0.702f);
            glVertex2f(-0.442f, -0.702f);
            glVertex2f(-0.538f, -0.709f);
            glVertex2f(-0.620f, -0.682f);
            glVertex2f(-0.691f, -0.646f);
            glVertex2f(-0.693f, -0.642f);
            glVertex2f(-0.700f, -0.638f);
            glVertex2f(-0.700f, -0.607f);
            glVertex2f(-0.702f, -0.658f);
            glVertex2f(-0.702f, -0.658f);
            glVertex2f(-0.700f, -0.626f);
            glVertex2f(-0.696f, -0.057f);
            glVertex2f(-0.684f, 0.132f);
            glVertex2f(-0.689f, 0.302f);
            glVertex2f(-0.687f, 0.54f);
            glVertex2f(-0.684f, 0.808f);
            glVertex2f(-0.680f, 0.749f);
            glVertex2f(-0.667f, 0.642f);
            glVertex2f(-0.653f, 0.615f);
            glVertex2f(-0.636f, 0.587f);
            glVertex2f(-0.624f, 0.571f);
            glVertex2f(-0.622f, 0.571f);
            glVertex2f(-0.604f, 0.536f);
            glVertex2f(-0.593f, 0.516f);
            glVertex2f(-0.593f, 0.48f);
            glVertex2f(-0.593f, 0.437f);
            glVertex2f(-0.600f, 0.37f);
            glVertex2f(-0.598f, 0.318f);
            glVertex2f(-0.593f, 0.318f);
            glVertex2f(-0.580f, 0.287f);
            glVertex2f(-0.538f, 0.227f);
            glVertex2f(-0.498f, 0.176f);
            glVertex2f(-0.476f, 0.14f);
            glVertex2f(-0.476f, 0.14f);
            glVertex2f(-0.440f, 0.038f);
            glEnd();
            glPopMatrix();
}


void designSeaLine(float Sx, float Sy, float Tx, float Ty, int R, int G, int B){
        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(R,G,B);

            glVertex2f(-0.011f, 0.259f);
            glVertex2f(-0.164f, 0.283f);
            glVertex2f(-0.273f, 0.291f);
            glVertex2f(-0.373f, 0.31f);
            glVertex2f(-0.491f, 0.294f);
            glVertex2f(-0.538f, 0.283f);
            glVertex2f(-0.556f, 0.279f);
            glVertex2f(-0.598f, 0.267f);
            glVertex2f(-0.642f, 0.215f);
            glVertex2f(-0.642f, 0.164f);
            glVertex2f(-0.542f, 0.144f);
            glVertex2f(-0.260f, 0.148f);
            glVertex2f(-0.044f, 0.164f);
            glVertex2f(0.147f, 0.18f);
            glVertex2f(0.298f, 0.227f);
            glVertex2f(0.522f, 0.2f);
            glVertex2f(0.680f, 0.196f);
            glVertex2f(0.907f, 0.263f);
            glVertex2f(0.789f, 0.243f);
            glVertex2f(0.676f, 0.239f);
            glVertex2f(0.560f, 0.243f);
            glVertex2f(0.458f, 0.255f);
            glVertex2f(0.336f, 0.267f);
            glVertex2f(0.244f, 0.287f);
            glVertex2f(0.167f, 0.283f);
            glEnd();
            glPopMatrix();
}

void designSeaLine2(float Sx, float Sy, float Tx, float Ty, int R, int G, int B){
        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(R,G,B);
            glVertex2f(-0.042f, -0.148f);
            glVertex2f(0.098f, -0.156f);
            glVertex2f(0.196f, -0.172f);
            glVertex2f(0.340f, -0.188f);
            glVertex2f(0.467f, -0.188f);
            glVertex2f(0.740f, -0.223f);
            glVertex2f(0.829f, -0.231f);
            glVertex2f(0.791f, -0.267f);
            glVertex2f(0.722f, -0.294f);
            glVertex2f(0.584f, -0.314f);
            glVertex2f(0.484f, -0.31f);
            glVertex2f(0.347f, -0.35f);
            glVertex2f(0.204f, -0.35f);
            glVertex2f(0.031f, -0.401f);
            glVertex2f(-0.104f, -0.381f);
            glVertex2f(-0.300f, -0.362f);
            glVertex2f(-0.502f, -0.35f);
            glVertex2f(-0.678f, -0.338f);
            glVertex2f(-0.827f, -0.291f);
            glVertex2f(-0.909f, -0.271f);
            glVertex2f(-0.784f, -0.259f);
            glVertex2f(-0.749f, -0.251f);
            glVertex2f(-0.627f, -0.227f);
            glVertex2f(-0.529f, -0.2f);
            glVertex2f(-0.393f, -0.176f);
            glVertex2f(-0.320f, -0.164f);
            glVertex2f(-0.220f, -0.164f);
            glVertex2f(-0.158f, -0.164f);
            glEnd();
            glPopMatrix();
}


void designShipLine(float Sx, float Sy, float Tx, float Ty, int R, int G, int B){
        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(R,G,B);
            glVertex2f(-0.818f, -0.713f);
            glVertex2f(-0.800f, -0.713f);
            glVertex2f(-0.982f, -0.943f);
            glVertex2f(-0.996f, -0.939f);
            glEnd();
        glPopMatrix();
}


void designTriangle(float Sx, float Sy, float Tx, float Ty, int R, int G, int B){


        glPushMatrix();
        glScalef(Sx, Sy,1);
        glTranslatef(Tx,Ty,0);
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(R,G,B);

            glVertex2f(-0.284f, -0.208f);
            glVertex2f(-0.169f, -0.267f);
            glVertex2f(-0.107f, -0.306f);
            glVertex2f(-0.042f, -0.334f);
            glVertex2f(0.022f, -0.389f);
            glVertex2f(0.064f, -0.441f);
            glVertex2f(0.064f, -0.468f);
            glVertex2f(0.044f, -0.516f);
            glVertex2f(0.016f, -0.551f);
            glVertex2f(-0.031f, -0.603f);
            glVertex2f(-0.098f, -0.638f);
            glVertex2f(-0.138f, -0.654f);
            glVertex2f(-0.202f, -0.674f);
            glVertex2f(-0.233f, -0.674f);
            glVertex2f(-0.356f, -0.642f);
            glVertex2f(-0.387f, -0.642f);
            glVertex2f(-0.396f, -0.666f);
            glVertex2f(-0.362f, -0.698f);
            glVertex2f(-0.400f, -0.698f);
            glVertex2f(-0.433f, -0.706f);
            glVertex2f(-0.498f, -0.702f);
            glVertex2f(-0.598f, -0.709f);
            glVertex2f(-0.647f, -0.717f);
            glVertex2f(-0.664f, 0.105f);
            glVertex2f(-0.656f, 0.148f);
            glVertex2f(-0.644f, 0.156f);
            glVertex2f(-0.624f, 0.144f);
            glVertex2f(-0.567f, 0.081f);
            glVertex2f(-0.491f, 0.002f);
            glVertex2f(-0.456f, -0.038f);
            glVertex2f(-0.436f, -0.069f);
            glVertex2f(-0.429f, -0.097f);
            glVertex2f(-0.407f, -0.164f);
            glVertex2f(-0.387f, -0.18f);
            glVertex2f(-0.364f, -0.192f);
            glVertex2f(-0.347f, -0.192f);

            glVertex2f(0.169f, -0.381f);
            glVertex2f(0.222f, -0.397f);
            glVertex2f(0.300f, -0.409f);
            glVertex2f(0.391f, -0.421f);
            glVertex2f(0.456f, -0.441f);
            glVertex2f(0.456f, -0.476f);
            glVertex2f(0.447f, -0.492f);
            glVertex2f(0.411f, -0.567f);
            glVertex2f(0.249f, -0.662f);
            glVertex2f(0.089f, -0.694f);
            glVertex2f(-0.256f, -0.706f);
            glVertex2f(-0.391f, -0.65f);
            glVertex2f(-0.391f, -0.65f);
            glVertex2f(-0.053f, -0.326f);
            glVertex2f(0.038f, -0.362f);
            glEnd();
}

void circle(float radius, float cX, float cY, int rC, int gC, int bC)
{
    glColor3ub(rC, gC, bC);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cX, cY);

    int r = (int)(radius * 100);
    int x = 0, y = r;
    int d = 1 - r;
    float s = 1.0f / 100.0f;
    while (x <= y)
    {
        (void)d;
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    x = 0;
    y = r;
    d = 1 - r;
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX + y * s, cY + x * s);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    x = (int)(r * 0.7072f);
    y = (int)(r * 0.7072f);
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX + x * s, cY + y * s); // oct 0 (45..90°) — descending x
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    // Mirror for remaining 6 octants
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX - x * s, cY + y * s);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX - y * s, cY + x * s);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX - y * s, cY - x * s);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX - x * s, cY - y * s);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX + x * s, cY - y * s);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    x = 0;
    y = r;
    d = 1 - r;
    while (x <= y)
    {
        glVertex2f(cX + y * s, cY - x * s);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    // close fan back to start
    glVertex2f(cX + r * s, cY);
    glEnd();
}

void drawMidpointEllipse(float cx, float cy, float rx, float ry,
                         int rC, int gC, int bC)
{
    int a = (int)(rx * 100);
    int b = (int)(ry * 100);
    float s = 1.0f / 100.0f;

    glColor3ub(rC, gC, bC);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // centre

    int x = 0, y = b;
    float d1 = (float)(b * b) - (float)(a * a * b) + 0.25f * (float)(a * a);
    float dx = 2.0f * b * b * x;
    float dy = 2.0f * a * a * y;

    while (dx < dy)
    {
        glVertex2f(cx + x * s, cy + y * s);
        if (d1 < 0)
        {
            x++;
            dx += 2.0f * b * b;
            d1 += dx + b * b;
        }
        else
        {
            x++;
            y--;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d1 += dx - dy + b * b;
        }
    }

    float d2 = (float)(b * b) * ((x + 0.5f) * (x + 0.5f)) + (float)(a * a) * ((y - 1.0f) * (y - 1.0f)) - (float)(a * a * b * b);

    while (y >= 0)
    {
        glVertex2f(cx + x * s, cy + y * s);
        if (d2 > 0)
        {
            y--;
            dy -= 2.0f * a * a;
            d2 += a * a - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d2 += dx - dy + a * a;
        }
    }

    x = 0;
    y = b;
    d1 = (float)(b * b) - (float)(a * a * b) + 0.25f * (float)(a * a);
    dx = 2.0f * b * b * x;
    dy = 2.0f * a * a * y;
    while (dx < dy)
    {
        glVertex2f(cx - x * s, cy + y * s);
        if (d1 < 0)
        {
            x++;
            dx += 2.0f * b * b;
            d1 += dx + b * b;
        }
        else
        {
            x++;
            y--;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d1 += dx - dy + b * b;
        }
    }
    d2 = (float)(b * b) * ((x + 0.5f) * (x + 0.5f)) + (float)(a * a) * ((y - 1.0f) * (y - 1.0f)) - (float)(a * a * b * b);
    while (y >= 0)
    {
        glVertex2f(cx - x * s, cy + y * s);
        if (d2 > 0)
        {
            y--;
            dy -= 2.0f * a * a;
            d2 += a * a - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d2 += dx - dy + a * a;
        }
    }

    x = 0;
    y = b;
    d1 = (float)(b * b) - (float)(a * a * b) + 0.25f * (float)(a * a);
    dx = 2.0f * b * b * x;
    dy = 2.0f * a * a * y;
    while (dx < dy)
    {
        glVertex2f(cx - x * s, cy - y * s);
        if (d1 < 0)
        {
            x++;
            dx += 2.0f * b * b;
            d1 += dx + b * b;
        }
        else
        {
            x++;
            y--;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d1 += dx - dy + b * b;
        }
    }
    d2 = (float)(b * b) * ((x + 0.5f) * (x + 0.5f)) + (float)(a * a) * ((y - 1.0f) * (y - 1.0f)) - (float)(a * a * b * b);
    while (y >= 0)
    {
        glVertex2f(cx - x * s, cy - y * s);
        if (d2 > 0)
        {
            y--;
            dy -= 2.0f * a * a;
            d2 += a * a - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d2 += dx - dy + a * a;
        }
    }

    // lower-right
    x = 0;
    y = b;
    d1 = (float)(b * b) - (float)(a * a * b) + 0.25f * (float)(a * a);
    dx = 2.0f * b * b * x;
    dy = 2.0f * a * a * y;
    while (dx < dy)
    {
        glVertex2f(cx + x * s, cy - y * s);
        if (d1 < 0)
        {
            x++;
            dx += 2.0f * b * b;
            d1 += dx + b * b;
        }
        else
        {
            x++;
            y--;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d1 += dx - dy + b * b;
        }
    }
    d2 = (float)(b * b) * ((x + 0.5f) * (x + 0.5f)) + (float)(a * a) * ((y - 1.0f) * (y - 1.0f)) - (float)(a * a * b * b);
    while (y >= 0)
    {
        glVertex2f(cx + x * s, cy - y * s);
        if (d2 > 0)
        {
            y--;
            dy -= 2.0f * a * a;
            d2 += a * a - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2.0f * b * b;
            dy -= 2.0f * a * a;
            d2 += dx - dy + a * a;
        }
    }

    glVertex2f(cx + rx, cy); // close fan
    glEnd();
}

void drawDDA_Line(float x1, float y1, float x2, float y2,
                  int rC, int gC, int bC)
{
    glColor3ub(rC, gC, bC);
    glBegin(GL_POINTS);

    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = (fabsf(dx) > fabsf(dy)) ? fabsf(dx) : fabsf(dy);
    steps = steps / 0.02f;

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1, y = y1;
    for (int i = 0; i <= (int)steps; i++)
    {
        glVertex2f(x, y);
        x += xInc;
        y += yInc;
    }
    glEnd();
}

void drawDDA_RoadDashes()
{
    float dashLen = 1.0f;
    float gapLen = 0.8f;
    float yLine = 2.6f;
    float xStart = 8.0f;
    float xEnd = 31.5f;

    float x = xStart;
    bool drawing = true;
    while (x < xEnd)
    {
        float xNext = x + (drawing ? dashLen : gapLen);
        if (xNext > xEnd)
            xNext = xEnd;
        if (drawing)
            drawDDA_Line(x, yLine, xNext, yLine, 255, 255, 255);
        x = xNext;
        drawing = !drawing;
    }
    yLine = 1.5f;
    x = xStart;
    drawing = true;
    while (x < xEnd)
    {
        float xNext = x + (drawing ? dashLen : gapLen);
        if (xNext > xEnd)
            xNext = xEnd;
        if (drawing)
            drawDDA_Line(x, yLine, xNext, yLine, 220, 220, 220);
        x = xNext;
        drawing = !drawing;
    }
}

void streetlight()
{

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.25, 11.25);
    glVertex2f(0.25, 10.75);
    glVertex2f(0.5, 10.75);
    glVertex2f(0.5, 11.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Red light");
    glVertex2f(0.25, 11.5);
    glVertex2f(0.25, 11.25);
    glVertex2f(0.5, 11.25);
    glVertex2f(0.5, 11.5);
    glEnd();
}

void More_StreetLight()
{

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(0, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(5, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(10, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(15, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(20, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(25, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(30, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(35, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(40, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(45, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(50, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(55, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(60, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(65, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(70, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(75, 16.1, 0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 1);
    glTranslatef(80, 16.1, 0);
    streetlight();
    glPopMatrix();
}

void rainUpdate(int value)
{
    if (isRaining)
    {
        for (int i = 0; i < numDrops; ++i)
        {
            rainY[i] -= 0.5f;
            if (rainY[i] < -25)
            {
                rainY[i] = 30;
                rainX[i] = (rand() % 82) - 41;
            }
        }
        glutPostRedisplay();
    }
    glutTimerFunc(30, rainUpdate, 0);
}

void drawRain()
{
    if (!isRaining)
        return;

    glColor3ub(173, 216, 230);
    glBegin(GL_LINES);
    for (int i = 0; i < numDrops; ++i)
    {
        glVertex2f(rainX[i], rainY[i]);
        glVertex2f(rainX[i], rainY[i] - 1.5f);
    }
    glEnd();
}

void drawRain3()
{
    if (!isRaining)
        return;

    glColor3ub(173, 216, 230);
    glBegin(GL_LINES);
    for (int i = 0; i < numDrops; ++i)
    {
        float rx = (rainX[i] + 41.0f) * (32.0f / 82.0f);
        float ry = (rainY[i] + 25.0f) * (18.0f / 55.0f);
        glVertex2f(rx, ry);
        glVertex2f(rx, ry - 0.5f);
    }
    glEnd();
}

// Scene 1: ortho 0..32 x 0..18
// Particles live in scene-2 space (-41..41 x -25..30).
// Remap them proportionally so the rain looks identical to scene 2:
//   - same density  (same particles, remapped x/y)
//   - same drop length proportional to screen height
//   - same colour
void drawRain1()
{
    if (!isRaining)
        return;

    // scene-2 ranges: x width=82, y height=55
    // scene-1 ranges: x width=32, y height=18
    const float sx        = 32.0f / 82.0f;
    const float sy        = 18.0f / 55.0f;
    const float dropLen   = 1.5f * sy;   // proportional drop length

    glColor3ub(173, 216, 230);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < numDrops; ++i)
    {
        float rx = (rainX[i] + 41.0f) * sx;
        float ry = (rainY[i] + 25.0f) * sy;
        glVertex2f(rx, ry);
        glVertex2f(rx, ry - dropLen);
    }
    glEnd();
}

void sky_1()
{

    glBegin(GL_POLYGON);

    set_color("skyL");
    glVertex2f(0, 0);
    glVertex2f(32, 0);
    set_color("skyM");
    glVertex2f(32, 15);
    glVertex2f(0, 15);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("skyM");
    glVertex2f(0, 15);
    glVertex2f(32, 15);
    set_color("skyD");
    glVertex2f(32, 18);
    glVertex2f(0, 18);
    glEnd();
}

void Window_wh_1()
{

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(23.50, 5.75);
    glVertex2f(23.50, 5.25);
    glVertex2f(24, 5.25);
    glVertex2f(24, 5.75);
    glEnd();
}

void Adjust_Window()
{

    // Big red building
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-16.5, 20.51, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-14.5, 20.51, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-12.5, 20.51, 0);
    Window_wh_1();
    glPopMatrix();

    // small building
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-21, 18, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-19, 18, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-17, 18, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-15, 18, 0);
    Window_wh_1();
    glPopMatrix();

    // 2nd row
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-21, 16.75, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-19, 16.75, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-17, 16.75, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(-15, 16.75, 0);
    Window_wh_1();
    glPopMatrix();

    // Right building small

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(29.5, 17.70, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(31.5, 17.70, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(33.5, 17.70, 0);
    Window_wh_1();
    glPopMatrix();

    // 2nd row
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(29.5, 16.5, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(31.5, 16.5, 0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(33.5, 16.5, 0);
    Window_wh_1();
    glPopMatrix();
}

void Building_1()
{
    // Back
    glBegin(GL_POLYGON);
    set_color("Jazzberry");
    glVertex2f(3, 13.5);
    glVertex2f(3, 10.75);
    glVertex2f(6.25, 10.75);
    glVertex2f(6.25, 13.5);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Maroon");
    glVertex2f(6.25, 13.5);
    glVertex2f(6.25, 10.75);
    glVertex2f(7, 10.75);
    glVertex2f(7, 13.5);
    glEnd();

    // Front
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(1, 12.25);
    glVertex2f(1, 10.75);
    glVertex2f(4.75, 10.75);
    glVertex2f(4.75, 12.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Hairy Heath");
    glVertex2f(4.75, 12.25);
    glVertex2f(4.75, 10.75);
    glVertex2f(6, 10.75);
    glVertex2f(6, 12.25);

    glEnd();
}

void CraneBg_1()
{
    // Leg Left
    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(-1.50, -2.00);
    glVertex2f(-1.50, -1.50);
    glVertex2f(-0.25, 0.50);
    glVertex2f(-0.25, -0.50);
    glVertex2f(-1.00, -1.50);
    glVertex2f(-1.00, -2.00);
    glVertex2f(-1.50, -2.00);
    glEnd();

    // Right Leg
    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(2.00, -2.00);
    glVertex2f(2.00, -1.50);
    glVertex2f(0.75, 0.50);
    glVertex2f(0.75, -0.50);
    glVertex2f(1.50, -1.50);
    glVertex2f(1.50, -2.00);
    glVertex2f(2.00, -2.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81, 90, 90);
    // glColor3ub(0,0,0 );
    glVertex2f(1.50, -2.00);
    glVertex2f(2.50, -2.00);
    glVertex2f(2.50, -2.25);
    glVertex2f(1.50, -2.25);
    glVertex2f(1.50, -2.00);
    glEnd();

    // Body line
    glBegin(GL_LINES);
    set_color("BcraneLeg");
    glVertex2f(-0.25, -0.50);
    glVertex2f(0.75, -0.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(-0.25, 0.39);
    glVertex2f(-0.25, 0.50);
    glVertex2f(0.75, 0.50);
    glVertex2f(0.75, 0.39);
    glVertex2f(-0.25, 0.39);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(-0.82, -1.25);
    glVertex2f(1.32, -1.25);
    glVertex2f(1.50, -1.50);
    glVertex2f(-1.00, -1.50);
    glVertex2f(-0.82, -1.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
    glVertex2f(-1.75, 0.50);
    glVertex2f(-1.75, 0.75);
    glVertex2f(-0.75, 0.75);
    glVertex2f(0.75, 0.50);
    glVertex2f(-1.75, 0.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
    glVertex2f(-0.75, 0.50);
    glVertex2f(-0.75, 0.75);
    glVertex2f(1.25, 0.75);
    glVertex2f(1.25, 0.50);
    glVertex2f(-0.75, 0.50);
    glEnd();

    glBegin(GL_POLYGON);
    //  glColor3ub(238, 226, 34  );//Y
    set_color("Fuel Yellow");
    glVertex2f(0.0, 0.75);
    glVertex2f(0.25, 0.75);
    glVertex2f(0.25, 1.50);
    glVertex2f(0.0, 1.66);
    glVertex2f(0.0, 0.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("BcraneRoom");
    glVertex2f(-1.75, 0.75);
    glVertex2f(-1.75, 1.75);
    glVertex2f(0.0, 1.75);
    glVertex2f(0.0, 0.75);
    glVertex2f(-1.75, 0.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(-1.50, 1.00);
    glVertex2f(-1.50, 1.50);
    glVertex2f(-1.00, 1.50);
    glVertex2f(-1.00, 1.00);
    glVertex2f(-1.50, 1.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
    glVertex2f(-1.00, 1.75);
    glVertex2f(-1.25, 2.00);
    glVertex2f(-1.25, 2.50);
    glVertex2f(-0.16, 1.75);
    glVertex2f(1.00, 1.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107); // J-1
    glVertex2f(-1.75, 2.00);
    glVertex2f(-1.75, 2.50);
    glVertex2f(-1.25, 2.50);
    glVertex2f(-1.25, 2.00);
    glVertex2f(-1.75, 2.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107); // J-2
    glVertex2f(-1.75, 2.50);
    glVertex2f(-1.75, 3.00);
    glVertex2f(-1.25, 3.00);
    glVertex2f(-1.25, 2.50);
    glVertex2f(-1.75, 2.50);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(44, 62, 80);
    glVertex2f(-1.75, 2.50);
    glVertex2f(-1.25, 2.50);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(251, 236, 1 );//Pull-1 //236, 223, 27
    set_color("Fuel Yellow");
    glVertex2f(-1.25, 2.25);
    glVertex2f(-1.25, 2.50);
    glVertex2f(1.25, 4.00);
    glVertex2f(1.25, 3.75);
    glVertex2f(-1.25, 2.25);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(251, 236, 1 );//Pull-2-Y
    set_color("Fuel Yellow");
    glVertex2f(1.25, 4.00);
    glVertex2f(3.25, 2.00);
    glVertex2f(3.25, 1.75);
    glVertex2f(1.25, 3.75);
    glVertex2f(1.25, 4.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
    // glColor3ub(251, 236, 1 );//Pull-3-Y
    glVertex2f(0.00, 3.25);
    glVertex2f(3.25, 2.00);
    glVertex2f(3.25, 1.75);
    glVertex2f(0.00, 3.00);
    glVertex2f(0.00, 3.25);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(251, 236, 1 );//Pull-4-Y
    set_color("Fuel Yellow");
    glVertex2f(0.25, 0.75);
    glVertex2f(1.75, 2.50);
    glVertex2f(1.75, 2.25);
    glVertex2f(0.50, 0.75);
    glVertex2f(0.25, 0.75);
    glEnd();

    // Rope
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.02, 1.75);
    glVertex2f(3.02, 0.50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.49, 1.75);
    glVertex2f(3.49, 0.50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.00, 0.50);
    glVertex2f(3.25, -0.25);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.50, 0.50);
    glVertex2f(3.25, -0.25);
    glEnd();

    //
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25, -0.25);
    glVertex2f(2.25, -0.75);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25, -0.25);
    glVertex2f(2.75, -0.75);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25, -0.25);
    glVertex2f(4.00, -0.75);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25, -0.25);
    glVertex2f(4.50, -0.75);
    glEnd();

    // Container
    glBegin(GL_POLYGON);
    set_color("BcraneContainer");
    glVertex2f(2.25, -0.75);
    glVertex2f(4.50, -0.75);
    glVertex2f(4.50, -1.50);
    glVertex2f(2.25, -1.50);
    glVertex2f(2.25, -0.75);
    glEnd();

    circle(0.232, 3.25, 1.75, 151, 149, 128);
    circle(0.232, 3.25, 0.50, 151, 149, 128);
}

void Adjust_craneBg()
{
    // CraneBg_1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5, .5, 1);
    glTranslatef(48, 23.51, 0);
    CraneBg_1();
    glPopMatrix();
}

void WareHouse_1()
{
    glBegin(GL_POLYGON);
    set_color("Jazzberry");
    glVertex2f(26, 12.5);
    glVertex2f(26, 11.25);
    glVertex2f(29, 11.25);
    glVertex2f(29, 12.5);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Maroon");
    glVertex2f(29, 12.5);
    glVertex2f(29, 11.25);
    glVertex2f(30.5, 11.25);
    glVertex2f(30.5, 12.5);
    glEnd();
}

void Adjust_WareHouse1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(0, -.5, 0);
    WareHouse_1();
    glPopMatrix();
}

void Houses_1()
{
    glBegin(GL_POLYGON);
    set_color("Neon");
    glVertex2f(28, 13);
    glVertex2f(28, 10.75);
    glVertex2f(32, 10.75);
    glVertex2f(32, 13);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("LNeon");
    glVertex2f(30.5, 14.75);
    glVertex2f(30.5, 13);
    glVertex2f(32.5, 13);
    glVertex2f(32.5, 14.75);
    glEnd();
}

void Houses_2(string color)
{
    glBegin(GL_POLYGON);
    set_color(color);
    glVertex2f(1, 12.25);
    glVertex2f(1, 10.75);
    glVertex2f(4.75, 10.75);
    glVertex2f(4.75, 12.25);
    glEnd();
}

void Adjust_Houses_2()
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.3, 1.3, 1);
    glTranslatef(-1, -2.47, 0);
    Houses_2("Neon");
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.5, .8, 1);
    glTranslatef(2, 2.47, 0);
    Houses_2("LNeon");
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.3, 1.3, 1);
    glTranslatef(10.5, -2.47, 0);
    Houses_2("LNeon");
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(12, 0, 0);
    Houses_2("Neon");
    glPopMatrix();
}

void Sea_border_1()
{
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(0, 10);
    glVertex2f(32, 10);
    glVertex2f(32, 10.35);
    glVertex2f(0, 10.35);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Scorpion");
    glVertex2f(0, 10.35);
    glVertex2f(32, 10.35);
    glVertex2f(32, 10.75);
    glVertex2f(0, 10.75);
    glEnd();
}

void Sea_1()
{
    //  top to bottom
    // 1
    glBegin(GL_POLYGON);
    set_color("1");
    glVertex2f(0, 10);
    glVertex2f(0, 5);
    glVertex2f(32, 5);
    glVertex2f(32, 10);
    glEnd();

    // 2
    glBegin(GL_POLYGON);
    set_color("2");
    glVertex2f(0, 9);
    glVertex2f(0, 5);
    glVertex2f(32, 5);
    glVertex2f(32, 7.5);
    glVertex2f(27, 8);
    glVertex2f(19.25, 8.50);
    glVertex2f(12.50, 7.75);
    glVertex2f(5, 8);
    glEnd();

    // 3
    glBegin(GL_POLYGON);
    set_color("3");
    glVertex2f(0, 7);
    glVertex2f(0, 5);
    glVertex2f(32, 5);
    glVertex2f(32, 6.25);
    glVertex2f(20, 7.0);
    glEnd();

    // 4
    glBegin(GL_POLYGON);
    set_color("4");
    glVertex2f(0, 5);
    glVertex2f(0, 0);
    glVertex2f(2, 0);
    glVertex2f(7, 5);
    glEnd();

    // light color
    int r = 235, g = 245, b = 251;
    designSeaLine(6, 2, 3.59, 3.59, r, g, b);
    designSeaLine(6, 2, 2.59, 3.10, r, g, b);
    designSeaLine(6, 2, 5.20, 4.2, r, g, b);
    designSeaLine2(3, 1, 1, 5.12, r, g, b);
    designSeaLine2(3, 1, 6.8, 9.7, r, g, b);
    designSeaLine2(5, 0.8, 0.6, 12.12, r, g, b);
}

void Cloud(float radius, float cX, float cY)
{

    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++)
    {
        set_color("cloud");
        float pi = 3.1416;
        float A = (i * 2 * pi) / 400;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + cX, y + cY);
    }
    glEnd();
}

void CloudSet()
{
    float spacing = 45.0f;

    for (int i = 0; i < 2; ++i)
    {
        float offset = cloudX + i * spacing;

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 1, 12, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 12, 14, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 24, 10, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 36, 12, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();
    }
}

void background_1()
{
    sky_1();
    Adjust_Houses_2();
    Adjust_craneBg();
    Houses_1();
    Sea_1();
    Sea_border_1();
    Adjust_WareHouse1();
    Building_1();
    Adjust_Window();
    CloudSet();
    More_StreetLight();
}

void road_design()
{
    // 1
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(30.0, 2);
    glVertex2f(30.0, 0);
    glVertex2f(32.0, 0);
    glVertex2f(32.0, 3.5);
    glEnd();

    // 2
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(26, 2);
    glVertex2f(26.0, 0);
    glVertex2f(30.0, 0);
    glVertex2f(30.0, 2);
    glEnd();

    // 3
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(24, 1.25);
    glVertex2f(24.0, 0);
    glVertex2f(26.0, 0);
    glVertex2f(26.0, 2);
    glEnd();

    // 4
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(20.25, 1);
    glVertex2f(20.25, 0);
    glVertex2f(24, 0);
    glVertex2f(24, 1.25);
    glEnd();

    // 5
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(16, 1.75);
    glVertex2f(16, 0);
    glVertex2f(20.25, 0);
    glVertex2f(20.25, 1);
    glEnd();

    // 6
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(14, 1.75);
    glVertex2f(14, 0);
    glVertex2f(16, 0);
    glVertex2f(16, 1.75);
    glEnd();

    // 7
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(10, 1.25);
    glVertex2f(10, 0);
    glVertex2f(14, 0);
    glVertex2f(14, 1.75);
    glEnd();

    // 8
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(7, 2.25);
    glVertex2f(7, 0);
    glVertex2f(10, 0);
    glVertex2f(10, 1.25);
    glEnd();

    // 9
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(6.25, 3.25);
    glVertex2f(6.25, 0);
    glVertex2f(7, 0);
    glVertex2f(7, 2.25);
    glEnd();

    // 10
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(6.25, 3.25);
    glVertex2f(4.25, 0);
    glVertex2f(6.25, 0);
    glEnd();

    // 11
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(7, 4.75);
    glVertex2f(2.50, 0);
    glVertex2f(4.5, 0);
    glEnd();
}

void Road_1()
{
    glBegin(GL_POLYGON);
    set_color("Scorpion");
    glVertex2f(2.0, 0);
    glVertex2f(32.0, 0);
    glVertex2f(32.0, 5.0);
    glVertex2f(7.0, 5.0);
    glEnd();

    // border side
    glBegin(GL_POLYGON);
    set_color("Thunder");
    glVertex2f(2.0, 0);
    glVertex2f(2.5, 0.0);
    glVertex2f(2.5, 0.0);
    glVertex2f(7.25, 5.0);
    glVertex2f(7.0, 5.0);
    glEnd();

    // bordertop
    glBegin(GL_POLYGON);
    set_color("Thunder");
    glVertex2f(7.0, 5.0);
    glVertex2f(32.0, 5.0);
    glVertex2f(32.0, 5.25);
    glVertex2f(7.0, 5.25);
    glEnd();

    road_design();
    drawDDA_RoadDashes();
}

void containerModel_1()
{
    // container 1
    glBegin(GL_POLYGON);
    glColor3ub(245, 176, 65);
    glVertex2f(1, 11);
    glVertex2f(4, 11);
    glVertex2f(4, 12);
    glVertex2f(1, 12);
    glEnd();

    // top 1
    glBegin(GL_POLYGON);
    glColor3ub(250, 215, 160);
    glVertex2f(1, 12);
    glVertex2f(1.25, 12);
    glVertex2f(1.25, 12.25);
    glEnd();

    // container 2
    glBegin(GL_POLYGON);
    glColor3ub(46, 134, 193);
    glVertex2f(4, 11);
    glVertex2f(6, 11);
    glVertex2f(6, 12);
    glVertex2f(4, 12);
    glEnd();

    // container 3
    glBegin(GL_POLYGON);
    glColor3ub(25, 111, 61);
    glVertex2f(6, 11);
    glVertex2f(7, 11);
    glVertex2f(7, 12);
    glVertex2f(6, 12);
    glEnd();

    // side 3
    glBegin(GL_POLYGON);
    glColor3ub(30, 132, 73);
    glVertex2f(7, 12);
    glVertex2f(7, 11);
    glVertex2f(7.25, 11.25);
    glVertex2f(7.25, 12.25);
    glEnd();

    // top 3
    glBegin(GL_POLYGON);
    glColor3ub(34, 153, 84);
    glVertex2f(6.25, 12);
    glVertex2f(7.0, 12);
    glVertex2f(7.25, 12.25);
    glVertex2f(6.50, 12.25);
    glEnd();

    // container 4
    glBegin(GL_POLYGON);
    glColor3ub(231, 76, 60);
    glVertex2f(1.25, 12);
    glVertex2f(3, 12);
    glVertex2f(3, 13);
    glVertex2f(1.25, 13);
    glEnd();

    // top 4
    glBegin(GL_POLYGON);
    glColor3ub(236, 112, 99);
    glVertex2f(1.25, 13);
    glVertex2f(3, 13);
    glVertex2f(3.25, 13.25);
    glVertex2f(1.50, 13.25);
    glEnd();

    // container 5
    glBegin(GL_POLYGON);
    glColor3ub(212, 172, 13);
    glVertex2f(3, 12);
    glVertex2f(5, 12);
    glVertex2f(5, 13);
    glVertex2f(3, 13);
    glEnd();

    // top 5
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(3, 13);
    glVertex2f(5, 13);
    glVertex2f(5.25, 13.25);
    glVertex2f(3.25, 13.25);
    glEnd();

    // container 6
    glBegin(GL_POLYGON);
    glColor3ub(36, 113, 163);
    glVertex2f(5, 12);
    glVertex2f(6.25, 12);
    glVertex2f(6.25, 13);
    glVertex2f(5, 13);
    glEnd();

    // 3d side 6
    glBegin(GL_POLYGON);
    glColor3ub(41, 128, 185);
    glVertex2f(6.25, 12);
    glVertex2f(6.5, 12.25);
    glVertex2f(6.5, 13.25);
    glVertex2f(6.25, 13);
    glEnd();

    // 3d top 6
    glBegin(GL_POLYGON);
    glColor3ub(84, 153, 199);
    glVertex2f(5, 13);
    glVertex2f(6.25, 13);
    glVertex2f(6.50, 13.25);
    glVertex2f(5.25, 13.25);
    glEnd();

    // container 1
    designSeaLine2(1.65, 0.8, 1.6, 15, 248, 196, 113);
    designSeaLine2(1, 0.3, 1.8, 38, 243, 156, 18);
    designSeaLine2(1, 0.3, 2.6, 37.5, 156, 100, 12);
    designSeaLine2(1, 0.3, 2.9, 38.7, 156, 100, 12);

    design3(0.3, 0.5, 4.52, 23.13, 0, 0, 0, 0, 156, 100, 12);
    design3(0.3, 0.5, 6.52, 23.13, 0, 0, 0, 0, 156, 100, 12);
    design3(0.3, 0.5, 9.52, 23.13, 0, 0, 0, 0, 156, 100, 12);
    design3(0.3, 0.5, 11.52, 23.13, 0, 0, 0, 0, 156, 100, 12);

    // container 2
    design3(0.3, 0.5, 14.52, 23.0, 0, 0, 0, 0, 174, 214, 241);
    design3(0.3, 0.5, 15.52, 23.0, 0, 0, 0, 0, 133, 193, 233);
    design3(0.3, 0.5, 16.52, 23.0, 0, 0, 0, 0, 36, 113, 163);
    design3(0.3, 0.5, 17.52, 23.0, 0, 0, 0, 0, 31, 97, 141);
    design3(0.3, 0.5, 18.52, 23.0, 0, 0, 0, 0, 26, 82, 118);

    designSeaLine2(1, 0.3, 4.9, 37.2, 0, 0, 0);
    designSeaLine2(1, 0.3, 4.9, 38.7, 52, 152, 219);
    designSeaLine2(1, 0.3, 4.9, 40, 21, 67, 96);

    // container 3
    design3(0.3, 0.5, 22.52, 23.0, 0, 0, 0, 0, 40, 180, 99);
    design3(0.3, 0.5, 22.52, 23.0, 0, 0, 0, 0, 40, 180, 99);
    design3(0.3, 0.5, 23.52, 23.0, 0, 0, 0, 0, 11, 83, 69);
    design3(0.3, 0.5, 24.0, 23.18, 0, 0, 0, 0, 46, 204, 113);

    // container 4
    design3(0.3, 0.5, 4.52, 25.13, 0, 0, 0, 0, 245, 183, 177);
    design3(0.3, 0.5, 5.32, 25.13, 0, 0, 0, 0, 203, 67, 53);
    design3(0.3, 0.5, 6.32, 25.13, 0, 0, 0, 0, 176, 58, 46);
    design3(0.3, 0.5, 7.32, 25.13, 0, 0, 0, 0, 148, 49, 38);
    design3(0.3, 0.5, 8.32, 25.13, 0, 0, 0, 0, 148, 49, 38);
    design3(0.3, 0.5, 9.32, 25.13, 0, 0, 0, 0, 148, 49, 38);
    designSeaLine2(1, 0.3, 2.2, 40.7, 169, 50, 38);
    designSeaLine2(1, 0.3, 2.2, 42.7, 169, 50, 38);
    designSeaLine2(1, 0.3, 2.3, 43.96, 100, 30, 22);

    // Contain 5
    designSeaLine2(1, 0.3, 3.9, 41.6, 244, 208, 63);
    designSeaLine2(1, 0.3, 3.9, 42.6, 183, 149, 11);
    designSeaLine2(1, 0.3, 4.0, 43.96, 249, 231, 159);

    design3(0.3, 0.5, 11.32, 25.13, 0, 0, 0, 0, 247, 220, 111);
    design3(0.3, 0.5, 12.32, 25.13, 0, 0, 0, 0, 183, 149, 11);
    design3(0.3, 0.5, 14.32, 25.13, 0, 0, 0, 0, 154, 125, 10);

    // container 6
    designSeaLine2(0.6, 0.3, 9.5, 42.6, 21, 67, 96);
    designSeaLine2(0.6, 0.3, 9.5, 41.6, 21, 67, 96);
    designSeaLine2(0.6, 0.3, 9.5, 42.3, 26, 82, 118);
    designSeaLine2(0.6, 0.3, 9.5, 41.3, 26, 82, 118);
    designSeaLine2(0.6, 0.3, 9.65, 44.1, 26, 82, 118);
}

void container_shadow()
{

    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(7.25, 5);
    glVertex2f(7.25, 3.5);
    glVertex2f(9.50, 3.50);
    glVertex2f(9.50, 3.75);
    glVertex2f(10.25, 3.75);
    glVertex2f(10.25, 4);
    glVertex2f(10.75, 4);
    glVertex2f(10.75, 5);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(11.5, 5);
    glVertex2f(11.5, 3.5);
    glVertex2f(15.25, 3.75);
    glVertex2f(15.25, 4.25);
    glVertex2f(17.75, 4.25);
    glVertex2f(17.75, 5);
    glEnd();

    // arm shadow right
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(11.75, 3);
    glVertex2f(11.5, 2.75);
    glVertex2f(16, 2.25);
    glVertex2f(16, 2.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(12.75, 3.75);
    glVertex2f(12.5, 3.5);
    glVertex2f(15.5, 3);
    glVertex2f(15.5, 3.5);

    glEnd();
}

void Container_2()
{
    container_shadow(); // Right  to left
    glPushMatrix();
    glScalef(0.8, 0.8, 1);
    glTranslatef(14, -5, 0);
    containerModel_1();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1);
    glTranslatef(14, -5, 0);
    containerModel_1();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1);
    glTranslatef(9.5, -4, 0);
    containerModel_1();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 1);
    glTranslatef(13, -3, 0);
    containerModel_1();
    glPopMatrix();
}

void Container_3()
{
    // Front side
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.8, 0.8, 1);
    glTranslatef(14, -10, 0);
    containerModel_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1, 1, 1);
    glTranslatef(12.5, -11.5, 0);
    containerModel_1();
    glPopMatrix();
}

void Container_4()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movecX, movecY, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(23, 107, 135);
    glVertex2f(1.50f, 2.00f);
    glVertex2f(3.00f, 2.00f);
    glVertex2f(3.00f, 3.00f);
    glVertex2f(1.50f, 3.00f);
    glEnd();

    //TOP FACE
    glBegin(GL_POLYGON);
    glColor3ub(100, 204, 197);
    glVertex2f(1.50f, 3.00f);
    glVertex2f(3.00f, 3.00f);
    glVertex2f(3.25f, 3.25f);
    glVertex2f(1.75f, 3.25f);
    glEnd();

    //RIGHT SIDE FACE
    glBegin(GL_POLYGON);
    glColor3ub(4, 54, 74);
    glVertex2f(3.00f, 2.00f);
    glVertex2f(3.25f, 2.25f);
    glVertex2f(3.25f, 3.25f);
    glVertex2f(3.00f, 3.00f);
    glEnd();

    // === STRUCTURAL VERTICAL RIBS on front face
    glColor3ub(15, 80, 105);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glVertex2f(1.875f, 2.00f);  glVertex2f(1.875f, 3.00f);
    glVertex2f(2.25f,  2.00f);  glVertex2f(2.25f,  3.00f);
    glVertex2f(2.625f, 2.00f);  glVertex2f(2.625f, 3.00f);
    glEnd();

    // === DOOR PANEL outline on front face
    glColor3ub(10, 70, 90);
    glLineWidth(0.8f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.60f, 2.05f);
    glVertex2f(2.90f, 2.05f);
    glVertex2f(2.90f, 2.90f);
    glVertex2f(1.60f, 2.90f);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(2.25f, 2.05f);
    glVertex2f(2.25f, 2.90f);
    glEnd();
    glLineWidth(1.0f);

    //HORIZONTAL BOTTOM RAIL STRIP (front)
    glBegin(GL_POLYGON);
    glColor3ub(10, 60, 80);
    glVertex2f(1.50f, 2.00f);
    glVertex2f(3.00f, 2.00f);
    glVertex2f(3.00f, 2.12f);
    glVertex2f(1.50f, 2.12f);
    glEnd();

    //HORIZONTAL TOP RAIL STRIP (front)
    glBegin(GL_POLYGON);
    glColor3ub(10, 60, 80);
    glVertex2f(1.50f, 2.88f);
    glVertex2f(3.00f, 2.88f);
    glVertex2f(3.00f, 3.00f);
    glVertex2f(1.50f, 3.00f);
    glEnd();

    //LEFT EDGE SHADOW (gives thickness to front-left corner)
    glBegin(GL_POLYGON);
    glColor3ub(66, 125, 157);
    glVertex2f(1.50f, 3.00f);
    glVertex2f(1.50f, 2.00f);
    glVertex2f(1.65f, 2.10f);
    glVertex2f(1.65f, 2.90f);
    glEnd();

    glPopMatrix();
}

void container5()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3, 3, 1);
    glTranslatef(4, -10.25, 0);
    containerModel_1();
    glPopMatrix();
}

void ship_shades()
{
    // left shade
    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(0, 1.15);
    glVertex2f(0, 0);
    glVertex2f(1.50, 2);
    glVertex2f(3.50, 3.15);
    glVertex2f(3, 3.15);
    glEnd();

    // right shade
    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(0.75, 0);
    glVertex2f(1.50, 0);
    glVertex2f(4.25, 2.75);
    glEnd();

    // head design shaded
    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(5.25, 4.0);
    glVertex2f(4.75, 5.0);
    glVertex2f(4.25, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(4.25, 5.0);
    glVertex2f(3.25, 4.0);
    glVertex2f(4.75, 5.0);
    glEnd();
}

void Ship_1()
{

    // ship floor
    glBegin(GL_POLYGON);
    set_color("Cship_floor");
    glVertex2f(0.0, 0.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(5.0, 3.0);
    glVertex2f(3.0, 3.25);
    glVertex2f(0.0, 1.25);
    glEnd();

    // right side
    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(5.0, 3.0);
    glVertex2f(5.25, 4.0);
    glVertex2f(4.75, 3.50);
    glVertex2f(4.75, 2.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(4.50, 2.50);
    glVertex2f(4.75, 2.75);
    glVertex2f(4.75, 3.25);
    glEnd();

    // ship head
    glBegin(GL_POLYGON);
    set_color("Cship_floor");
    glVertex2f(5.25, 4.0);
    glVertex2f(4.75, 5.0);
    glVertex2f(4.25, 5.0);
    glVertex2f(3.25, 4.0);
    glEnd();

    // stairs like top
    glBegin(GL_POLYGON);
    set_color("Crail");
    glVertex2f(3.25, 4.0);
    glVertex2f(3.25, 3.75);
    glVertex2f(5.0, 3.75);
    glVertex2f(5.25, 4.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Japonica");
    glVertex2f(3.25, 3.75);
    glVertex2f(3.0, 3.50);
    glVertex2f(4.75, 3.50);
    glVertex2f(5.0, 3.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Crail");
    glVertex2f(3.0, 3.50);
    glVertex2f(3.0, 3.25);
    glVertex2f(4.75, 3.25);
    glVertex2f(4.75, 3.50);
    glEnd();

    // gap fill up
    glBegin(GL_POLYGON);
    set_color("Cship_floor");
    glVertex2f(3.0, 3.25);
    glVertex2f(4.50, 2.50);
    glVertex2f(4.75, 3.25);
    glEnd();

    // left side wall
    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(0.0, 2.00);
    glVertex2f(0.0, 1.25);
    glVertex2f(3.0, 3.25);
    glVertex2f(3.0, 3.50);
    glVertex2f(3.25, 3.75);
    glVertex2f(3.25, 4.00);
    glEnd();

    // right side wall
    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(1.50, 0);
    glVertex2f(2.0, 0);
    glVertex2f(4.50, 2.50);
    glVertex2f(4.50, 3.00);
    glEnd();

    // border right side
    glBegin(GL_POLYGON);
    set_color("Ship_Border");
    glVertex2f(1.85, 0);
    glVertex2f(2.0, 0);
    glVertex2f(4.50, 2.50);
    glVertex2f(4.50, 2.65);
    glEnd();

    ship_shades();
}

void Light_1()
{

    glBegin(GL_POLYGON);
    set_color("Red light");
    glVertex2f(1, 3);
    glVertex2f(1, 1);
    glVertex2f(2, 1);
    glVertex2f(2, 3);
    glEnd();
}

void Adjust_light()
{
    // top
    glPushMatrix();
    glScalef(.1, .1, 0);
    glTranslatef(53, 160.25, 0);
    Light_1();
    glPopMatrix();

    // roof
    glPushMatrix();
    glScalef(.1, .1, 0);
    glTranslatef(65, 145.35, 0);
    Light_1();
    glPopMatrix();
}

void Ship_2()
{
    container5();
    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(-12.0, 7.0);
    glVertex2f(-1.0, 7.0);
    glVertex2f(1.50, 3.25);
    glVertex2f(3.00, 3.25);
    glVertex2f(3.0, -1.0);
    glVertex2f(-12.0, -1.0);
    glVertex2f(-12.0, 7.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(3.0, 3.25);
    glVertex2f(36.75, 3.25);
    glVertex2f(36.75, -1.0);
    glVertex2f(3.0, -1.0);
    glVertex2f(3.0, 3.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(36.75, 3.25);
    glVertex2f(38.0, 6.0);
    glVertex2f(44.0, 6.0);
    glVertex2f(40.0, -1.00);
    glVertex2f(36.75, -1.00);
    glVertex2f(36.75, 3.25);
    glEnd();

    // bottom border
    glBegin(GL_POLYGON);
    set_color("Ship_Border");
    glVertex2f(-12.0, -1.0);
    glVertex2f(40.0, -1.0);
    glVertex2f(39.0, -2.00);
    glVertex2f(-11.0, -2.0);
    glVertex2f(-12.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1"); // yellow
    glVertex2f(-12.0, 6.0);
    glVertex2f(-2.50, 6.0);
    glVertex2f(-2.50, 5.50);
    glVertex2f(-12.0, 5.50);
    glVertex2f(-12.0, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1"); // yellow
    glVertex2f(-2.50, 6.0);
    glVertex2f(-2.00, 6.0);
    glVertex2f(0.50, 2.50);
    glVertex2f(0.25, 2.00);
    glVertex2f(-2.25, 5.50);
    glVertex2f(-2.50, 5.50);
    glVertex2f(-2.50, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1"); // yellow
    glVertex2f(0.50, 2.50);
    glVertex2f(3.00, 2.50);
    glVertex2f(3.0, 2.0);
    glVertex2f(0.25, 2.00);
    glVertex2f(0.5, 2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1"); // yellow
    glVertex2f(0.50, 2.50);
    glVertex2f(37.50, 2.50);
    glVertex2f(38.0, 2.0);
    glVertex2f(0.25, 2.00);
    glVertex2f(0.5, 2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1"); // yellow
    glVertex2f(37.50, 2.50);
    glVertex2f(38.75, 5.50);
    glVertex2f(39.25, 5.0);
    glVertex2f(38.0, 2.00);
    glVertex2f(37.50, 2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1"); // yellow
    glVertex2f(38.75, 5.50);
    glVertex2f(43.75, 5.50);
    glVertex2f(43.45, 4.99);
    glVertex2f(39.25, 5.00);
    glVertex2f(38.75, 5.50);
    glEnd();

    glBegin(GL_POLYGON); // white
    set_color("Firefly");
    glVertex2f(-11.50, 7.00);
    glVertex2f(-11.50, 8.75);
    glVertex2f(-6.75, 8.75);
    glVertex2f(-6.75, 7.00);
    glVertex2f(-11.50, 7.00);
    glEnd();
    glBegin(GL_POLYGON); // white
    set_color("chimney");
    glVertex2f(-11.00, 8.75);
    glVertex2f(-9.25, 16.25);
    glVertex2f(-6.75, 16.25);
    glVertex2f(-6.75, 8.75);
    glVertex2f(-11.00, 8.75);
    glEnd();
    glBegin(GL_POLYGON);
    // glColor3ub(5, 156, 65); //green
    set_color("Firefly");
    glVertex2f(-9.50, 15.25);
    glVertex2f(-6.75, 15.25);
    glVertex2f(-6.75, 15.00);
    glVertex2f(-9.55, 15.00);
    glVertex2f(-9.50, 15.25);
    glEnd();
    glBegin(GL_POLYGON);
    // glColor3ub(5, 156, 65); //green
    set_color("Firefly");
    glVertex2f(-9.96, 13.25);
    glVertex2f(-6.75, 13.25);
    glVertex2f(-6.75, 13.00);
    glVertex2f(-10.00, 13.00);
    glVertex2f(-9.96, 13.25);
    glEnd();
    glBegin(GL_POLYGON);
    // glColor3ub(232, 239, 16); //yellow
    set_color("White");
    glVertex2f(-9.55, 15.00);
    glVertex2f(-6.75, 15.00);
    glVertex2f(-6.75, 13.25);
    glVertex2f(-9.96, 13.25);
    glVertex2f(-9.55, 15.00);
    glEnd();

    glBegin(GL_POLYGON); // ash chimney duck 1
    glColor3ub(97, 106, 107);
    glVertex2f(-8.00, 16.25);
    glVertex2f(-8.00, 17.25);
    glVertex2f(-8.50, 17.75);
    glVertex2f(-8.25, 18.25);
    glVertex2f(-7.50, 17.50);
    glVertex2f(-7.25, 17.00);
    glVertex2f(-7.00, 16.75);
    glVertex2f(-7.00, 16.25);
    glVertex2f(-8.00, 16.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body"); // off-white
    glVertex2f(-6.00, 7.00);
    glVertex2f(-6.00, 13.00);
    glVertex2f(-1.00, 13.00);
    glVertex2f(-1.00, 7.00);
    glVertex2f(-6.00, 7.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Off white"); // off-white
    glVertex2f(-1.00, 11.75);
    glVertex2f(4.00, 11.75);
    glVertex2f(4.00, 3.25);
    glVertex2f(1.50, 3.25);
    glVertex2f(-1.00, 7.00);
    glVertex2f(-1.00, 11.75);
    glEnd();

    // Minor details
    glBegin(GL_POLYGON);
    glColor3ub(229, 232, 232);
    glVertex2f(-1.00, 13.00);
    glVertex2f(3.00, 13.00);
    glVertex2f(3.00, 11.75);
    glVertex2f(-1.00, 11.75);
    glVertex2f(-1.00, 13.00);
    glEnd();

    // T
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(3.00, 11.75);
    glVertex2f(3.00, 13.00);
    glVertex2f(4.00, 13.00);
    glVertex2f(4.00, 11.75);
    glVertex2f(3.00, 11.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00, 10.75);
    glVertex2f(4.00, 13.00);
    glVertex2f(9.50, 13.00);
    glVertex2f(9.50, 10.75);
    glVertex2f(4.00, 10.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(9.50, 11.50);
    glVertex2f(9.50, 13.00);
    glVertex2f(11.50, 13.00);
    glVertex2f(11.50, 11.50);
    glVertex2f(9.50, 11.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00, 9.00);
    glVertex2f(4.00, 10.75);
    glVertex2f(9.50, 10.75);
    glVertex2f(9.50, 9.00);
    glVertex2f(4.00, 9.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00, 3.25);
    glVertex2f(4.00, 9.00);
    glVertex2f(9.50, 9.00);
    glVertex2f(9.50, 3.25);
    glVertex2f(4.00, 3.25);
    glEnd();

    // Railing
    glBegin(GL_POLYGON);
    set_color("Railing");
    glVertex2f(-5.75, 13.00);
    glVertex2f(-5.75, 14.50);
    glVertex2f(12.50, 14.50);
    glVertex2f(11.50, 13.00);
    glVertex2f(-5.75, 13.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("chimney"); // chimney 2
    glVertex2f(-5.50, 14.50);
    glVertex2f(-3.50, 14.50);
    glVertex2f(-3.50, 15.25);
    glVertex2f(-5.25, 15.25);
    glVertex2f(-5.50, 14.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("chimney"); // chimney 2
    glVertex2f(-5.22, 15.50);
    glVertex2f(-5.00, 16.25);
    glVertex2f(-3.50, 16.25);
    glVertex2f(-3.50, 15.50);
    glVertex2f(-5.22, 15.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Firefly"); // yellow // chimney 2
    glVertex2f(-5.22, 15.50);
    glVertex2f(-3.50, 15.50);
    glVertex2f(-3.50, 15.25);
    glVertex2f(-5.29, 15.25);
    glVertex2f(-5.22, 15.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81, 90, 90); // chimney duck 2
    glVertex2f(-4.50, 16.25);
    glVertex2f(-4.50, 17.00);
    glVertex2f(-5.00, 17.50);
    glVertex2f(-4.75, 18.00);
    glVertex2f(-4.00, 17.25);
    glVertex2f(-3.75, 16.75);
    glVertex2f(-3.75, 16.25);
    glVertex2f(-4.50, 16.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Top_floor"); // building
    glVertex2f(-3.00, 14.50);
    glVertex2f(-3.00, 16.00);
    glVertex2f(10.85, 15.99);
    glVertex2f(10.00, 14.50);
    glVertex2f(-3.00, 14.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(93, 64, 55);
    glVertex2f(-3.00, 16.00);
    glVertex2f(-3.00, 16.25);
    glVertex2f(11.00, 16.25);
    glVertex2f(10.85, 15.99);
    glVertex2f(-3.00, 16.00);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-Cw-1
    set_color("ship_window");
    glVertex2f(-2.50, 15.50);
    glVertex2f(-0.50, 15.50);
    glVertex2f(-0.50, 15.00);
    glVertex2f(-2.50, 15.00);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-CW-2
    set_color("ship_window");
    glVertex2f(0.50, 15.00);
    glVertex2f(0.50, 15.50);
    glVertex2f(2.00, 15.50);
    glVertex2f(2.00, 15.00);
    glVertex2f(0.50, 15.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-CW-3
    glVertex2f(4.00, 15.25);
    glVertex2f(3.75, 15.75);
    glVertex2f(4.75, 15.75);
    glVertex2f(4.75, 15.25);
    glVertex2f(4.00, 15.25);
    glEnd();

    glBegin(GL_POLYGON); // green-CW-4
    set_color("ship_window");
    glVertex2f(5.50, 15.25);
    glVertex2f(5.50, 15.75);
    glVertex2f(6.75, 15.75);
    glVertex2f(6.75, 15.25);
    glVertex2f(5.50, 15.25);
    glEnd();
    glBegin(GL_POLYGON);

    set_color("ship_window"); // green-CW-5
    glVertex2f(7.50, 15.25);
    glVertex2f(7.50, 15.75);
    glVertex2f(9.00, 15.75);
    glVertex2f(9.00, 15.25);
    glVertex2f(7.50, 15.25);
    glEnd();
    glBegin(GL_POLYGON);

    // green-CW-6'
    set_color("ship_window");
    glVertex2f(9.50, 15.25);
    glVertex2f(9.50, 15.75);
    glVertex2f(10.50, 15.75);
    glVertex2f(10.00, 15.25);
    glVertex2f(9.50, 15.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); // stand-W
    glVertex2f(3.50, 16.25);
    glVertex2f(3.50, 18.50);
    glVertex2f(4.50, 18.50);
    glVertex2f(4.50, 16.25);
    glVertex2f(3.50, 16.25);
    glEnd();
    glBegin(GL_POLYGON); // Gray
    glColor3ub(158, 158, 158);
    glVertex2f(3.50, 18.50);
    glVertex2f(3.50, 18.75);
    glVertex2f(5.50, 18.75);
    glVertex2f(5.50, 18.50);
    glVertex2f(3.50, 18.50);
    glEnd();

    glBegin(GL_POLYGON); // W
    glColor3ub(189, 189, 189);
    glVertex2f(3.75, 18.75);
    glVertex2f(3.75, 21.25);
    glVertex2f(4.50, 21.25);
    glVertex2f(4.50, 18.75);
    glVertex2f(3.75, 18.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158); // Gray
    glVertex2f(3.25, 21.25);
    glVertex2f(3.25, 21.75);
    glVertex2f(6.25, 21.75);
    glVertex2f(6.25, 21.25);
    glVertex2f(3.25, 21.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189); // W
    glVertex2f(3.75, 21.75);
    glVertex2f(3.75, 26.00);
    glVertex2f(4.50, 26.00);
    glVertex2f(4.50, 21.75);
    glVertex2f(3.75, 21.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158); // Gray-CM TOP

    glVertex2f(3.75, 26.00);
    glVertex2f(3.25, 26.50);
    glVertex2f(5.00, 26.50);
    glVertex2f(4.50, 26.00);
    glVertex2f(3.75, 26.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158); // Gray-CM
    glVertex2f(3.75, 26.50);
    glVertex2f(3.25, 27.00);
    glVertex2f(5.00, 27.00);
    glVertex2f(4.50, 26.50);
    glVertex2f(3.75, 26.50);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(247, 8, 8 );//Flag-Red
    set_color("Maroon");
    glVertex2f(3.75, 24.50);
    glVertex2f(1.75, 24.50);
    glVertex2f(1.75, 25.50);
    glVertex2f(3.75, 25.50);
    glVertex2f(3.75, 24.50);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-W-1
    set_color("ship_window");
    glVertex2f(-5.50, 11.75);
    glVertex2f(-5.00, 11.75);
    glVertex2f(-5.00, 12.25);
    glVertex2f(-5.50, 12.25);
    glVertex2f(-5.50, 11.75);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-W-2
    set_color("ship_window");
    glVertex2f(-2.75, 11.75);
    glVertex2f(-2.25, 11.75);
    glVertex2f(-2.25, 12.25);
    glVertex2f(-2.75, 12.25);
    glVertex2f(-2.75, 11.75);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-W-3
    set_color("ship_window");
    glVertex2f(-4.75, 9.50);
    glVertex2f(-4.25, 9.50);
    glVertex2f(-4.25, 10.00);
    glVertex2f(-4.75, 10.00);
    glVertex2f(-4.75, 9.50);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-W-4
    set_color("ship_window");
    glVertex2f(-1.75, 9.50);
    glVertex2f(-1.25, 9.50);
    glVertex2f(-1.25, 10.00);
    glVertex2f(-1.75, 10.00);
    glVertex2f(-1.75, 9.50);
    glEnd();

    glBegin(GL_POLYGON);
    //  glColor3ub(0, 150, 136 );//green-W-5
    set_color("ship_window");
    glVertex2f(-5.50, 7.25);
    glVertex2f(-5.00, 7.25);
    glVertex2f(-5.00, 7.75);
    glVertex2f(-5.50, 7.75);
    glVertex2f(-5.50, 7.25);
    glEnd();

    glBegin(GL_POLYGON);
    //  glColor3ub(0, 150, 136 );//green-W-6
    set_color("ship_window");
    glVertex2f(-3.50, 7.25);
    glVertex2f(-3.00, 7.25);
    glVertex2f(-3.00, 7.75);
    glVertex2f(-3.50, 7.75);
    glVertex2f(-3.50, 7.25);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-W-7
    set_color("ship_window");
    glVertex2f(-1.75, 7.25);
    glVertex2f(-1.25, 7.25);
    glVertex2f(-1.25, 7.75);
    glVertex2f(-1.75, 7.75);
    glVertex2f(-1.75, 7.25);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(0, 150, 136 );//green-W-8
    set_color("ship_window");
    glVertex2f(0.50, 9.50);
    glVertex2f(1.25, 9.50);
    glVertex2f(1.25, 10.00);
    glVertex2f(0.50, 10.00);
    glVertex2f(0.50, 9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");
    glVertex2f(2.75, 9.50);
    glVertex2f(3.25, 9.50);
    glVertex2f(3.25, 10.00);
    glVertex2f(2.75, 10.00);
    glVertex2f(2.75, 9.50);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-10
    glVertex2f(0.75, 7.25);
    glVertex2f(1.25, 7.25);
    glVertex2f(1.25, 7.75);
    glVertex2f(0.75, 7.75);
    glVertex2f(0.75, 7.25);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-11
    glVertex2f(2.75, 7.25);
    glVertex2f(3.25, 7.25);
    glVertex2f(3.25, 7.75);
    glVertex2f(2.75, 7.75);
    glVertex2f(2.75, 7.25);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-12
    glVertex2f(4.25, 12.00);
    glVertex2f(4.75, 12.00);
    glVertex2f(4.75, 12.50);
    glVertex2f(4.25, 12.50);
    glVertex2f(4.25, 12.00);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-13
    glVertex2f(5.75, 12.00);
    glVertex2f(7.25, 12.00);
    glVertex2f(7.25, 12.50);
    glVertex2f(5.75, 12.50);
    glVertex2f(7.75, 12.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-14
    glVertex2f(8.25, 12.00);
    glVertex2f(8.75, 12.00);
    glVertex2f(8.75, 12.50);
    glVertex2f(8.25, 12.50);
    glVertex2f(8.25, 12.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-15
    glVertex2f(4.50, 9.50);
    glVertex2f(5.50, 9.50);
    glVertex2f(5.50, 10.00);
    glVertex2f(4.50, 10.00);
    glVertex2f(4.50, 9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-16
    glVertex2f(6.75, 9.50);
    glVertex2f(8.00, 9.50);
    glVertex2f(8.00, 10.00);
    glVertex2f(6.75, 10.00);
    glVertex2f(6.75, 9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-17
    glVertex2f(8.50, 9.50);
    glVertex2f(9.25, 9.50);
    glVertex2f(9.25, 10.00);
    glVertex2f(8.50, 10.00);
    glVertex2f(8.50, 9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-18
    glVertex2f(5.25, 7.25);
    glVertex2f(5.75, 7.25);
    glVertex2f(5.75, 7.75);
    glVertex2f(5.25, 7.75);
    glVertex2f(5.25, 7.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-19
    glVertex2f(6.50, 7.25);
    glVertex2f(7.00, 7.25);
    glVertex2f(7.00, 7.75);
    glVertex2f(6.50, 7.75);
    glVertex2f(6.50, 7.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window"); // green-W-20
    glVertex2f(7.75, 7.25);
    glVertex2f(8.25, 7.25);
    glVertex2f(8.25, 7.75);
    glVertex2f(7.75, 7.75);
    glVertex2f(7.75, 7.25);
    glEnd();

    // floor lines
    glBegin(GL_POLYGON);
    glColor3ub(208, 211, 212);
    glVertex2f(-6.00, 10.75);
    glVertex2f(-6.00, 11.00);
    glVertex2f(9.50, 11.00);
    glVertex2f(9.50, 10.75);
    glVertex2f(-6.00, 10.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(208, 211, 212);
    glVertex2f(-6.00, 8.75);
    glVertex2f(-6.00, 9.00);
    glVertex2f(9.50, 9.00);
    glVertex2f(9.50, 8.75);
    glVertex2f(-6.00, 8.75);
    glEnd();
}

void Adjust_ship()
{
    glPushMatrix();
    glScalef(0.26, 0.27, 1);
    glTranslatef(15, 38, 0);
    Ship_2();
    glPopMatrix();
    Adjust_light();
}

void Magnet()
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(moveXh, moveY, 0.0f);

    circle(0.25, 2, 6, 241, 196, 15);
    circle(0.15, 2, 6, 255, 255, 255);
    circle(0.25, 2.75, 6, 241, 196, 15);
    circle(0.15, 2.75, 6, 255, 255, 255);

    // Lines inside circle:
    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3ub(123, 36, 28);
    glVertex2f(1.75, 6);
    glVertex2f(2.25, 6);

    glVertex2f(2.0, 6.25);
    glVertex2f(2.0, 5.75);

    glVertex2f(2.5, 6);
    glVertex2f(3.0, 6);

    glVertex2f(2.75, 6.25);
    glVertex2f(2.75, 5.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(1.50, 5.75);
    glVertex2f(1.50, 5.50);
    glVertex2f(3.25, 5.50);
    glVertex2f(3.25, 5.75);
    glEnd();

    // design
    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2f(1.50, 5.75);
    glVertex2f(1.50, 5.50);
    glVertex2f(1.55, 5.54);
    glVertex2f(2.93, 5.63);
    glVertex2f(1.57, 5.68);
    glEnd();

    glPopMatrix();
}

void LineString()
{
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glLineWidth(5);
    glVertex2f(2.50, 7.0);
    glVertex2f(2.0, 6.25 + stringY);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glLineWidth(5);
    glVertex2f(2.50, 7.0);
    glVertex2f(2.75, 6.25 + stringY);
    glEnd();
}

void hook()
{
    circle(.5, 2.5, 7, 128, 139, 150);
    circle(.25, 2.5, 7, 171, 178, 185);
    LineString();

    // 1
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(1.75, 7.75);
    glVertex2f(1.75, 6.75);
    glVertex2f(2.0, 6.50);
    glVertex2f(2.0, 7.75);
    glEnd();

    // 2
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(2.75, 8.50);
    glVertex2f(2.75, 7.25);
    glVertex2f(3.0, 7.25);
    glVertex2f(3.0, 8.50);
    glEnd();

    // 3
    glBegin(GL_POLYGON);
    glColor3ub(212, 172, 13);
    glVertex2f(2, 7.25);
    glVertex2f(2, 6.50);
    glVertex2f(3.0, 7.25);
    glVertex2f(3.0, 7.75);
    glEnd();

    // 4
    glBegin(GL_POLYGON);
    glColor3ub(244, 208, 63);
    glVertex2f(2, 7.25);
    glVertex2f(3.0, 7.75);
    glVertex2f(2.75, 7.75);
    glVertex2f(2.0, 7.40);
    glEnd();

    // 5
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(2.75, 8.50);
    glVertex2f(2.75, 8.25);
    glVertex2f(3.0, 8.25);
    glVertex2f(3.0, 8.50);
    glEnd();

    design1(0.9, 0.9, 3.1, 8.4, 30, 0, 0, 0, 246, 221, 204);
    design1(0.5, 0.9, 3.84, 8.47, 30, 0, 0, 0, 252, 243, 207);
}

void Crane1Design()
{
    design2(0.7, 1, 16.32, 3.73, 00, 0, 0, 0, 192, 57, 43);
    design3(1, 1, 11.32, 6.73, 00, 0, 0, 0, 236, 112, 99);
    design3(1.1, 2.3, 5.32, 2.3, 00, 0, 0, 0, 241, 148, 138);
}

void Crane1()
{

    // arm 1
    glBegin(GL_POLYGON);
    glColor3ub(169, 50, 38);
    glVertex2f(5.5, 2.75);
    glVertex2f(6.25, 2.75);
    glVertex2f(6.25, 8.25);
    glVertex2f(5.5, 8.25);
    glEnd();

    // 3d like effect
    glBegin(GL_POLYGON);
    glColor3ub(123, 36, 28);
    glVertex2f(6.25, 2.75);
    glVertex2f(6.50, 3.0);
    glVertex2f(6.50, 8.0);
    glVertex2f(6.25, 8.0);
    glEnd();

    // arm 2
    glBegin(GL_POLYGON);
    glColor3ub(169, 50, 38);
    glVertex2f(10.75, 2.75);
    glVertex2f(11.5, 2.75);
    glVertex2f(11.5, 8.25);
    glVertex2f(10.75, 8.25);
    glEnd();

    // 3d like effect
    glBegin(GL_POLYGON);
    glColor3ub(123, 36, 28);
    glVertex2f(11.5, 2.75);
    glVertex2f(11.75, 3.0);
    glVertex2f(11.75, 8.0);
    glVertex2f(11.5, 8.0);
    glEnd();

    // Bar
    glBegin(GL_POLYGON);
    glColor3ub(214, 137, 16);
    glVertex2f(1.5, 8.0);
    glVertex2f(15.0, 8.0);
    glVertex2f(15.50, 8.25);
    glVertex2f(2.0, 8.25);
    glEnd();

    // 3d effect width bar
    glBegin(GL_POLYGON);
    glColor3ub(185, 119, 14);
    glVertex2f(1.5, 7.75);
    glVertex2f(15.0, 7.75);
    glVertex2f(15.0, 8.0);
    glVertex2f(1.50, 8.0);
    glEnd();

    // 3d effect side bar
    glBegin(GL_POLYGON);
    glColor3ub(185, 119, 14);
    glVertex2f(15.0, 7.75);
    glVertex2f(15.50, 8.0);
    glVertex2f(15.50, 8.25);
    glVertex2f(15.0, 8.0);
    glEnd();
}

void Crane2()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.0, 0.75, 0);
    Crane1();
    glPopMatrix();
}

void Wh_door()
{
    glBegin(GL_POLYGON);
    set_color("Hawaiian Tan");
    glVertex2f(21, 3.25);
    glVertex2f(21, 2.5);
    glVertex2f(22.50, 2.5);
    glVertex2f(22.50, 3.25);
    glEnd();

    // shadow
    glBegin(GL_POLYGON);
    set_color("Hairy Heath");
    glVertex2f(21, 3.25);
    glVertex2f(21, 2.5);
    glVertex2f(22.50, 2.5);
    glVertex2f(21.50, 2.75);
    glEnd();

    // window
    // float a = 0.50;
    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(21.50, 5.75);
    glVertex2f(21.50, 5.25);
    glVertex2f(22, 5.25);
    glVertex2f(22, 5.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(22.50, 5.75);
    glVertex2f(22.50, 5.25);
    glVertex2f(23, 5.25);
    glVertex2f(23, 5.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(23.50, 5.75);
    glVertex2f(23.50, 5.25);
    glVertex2f(24, 5.25);
    glVertex2f(24, 5.75);
    glEnd();
}

void Warehouse_shadow()
{
    glBegin(GL_LINES);
    glLineWidth(4);
    set_color("Hairy Heathy");
    glVertex2f(26.0, 6.75);
    glVertex2f(26.0, 4.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("warehouse1");
    glVertex2f(26.0, 4.0);
    glVertex2f(29.0, 4.0);
    glVertex2f(29.0, 5.25);
    glVertex2f(27.25, 5.25);
    glVertex2f(27.25, 6.75);
    glVertex2f(26.0, 6.75);
    glEnd();
}

void Warehouse_2()
{
    // 1
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(20.25, 4);
    glVertex2f(20.25, 2.25);
    glVertex2f(23.25, 2.25);
    glVertex2f(23.25, 4.0);
    glEnd();

    // border top 1
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(20, 4);
    glVertex2f(23.25, 4.0);
    glVertex2f(23.25, 4.25);
    glVertex2f(20.0, 4.25);
    glEnd();

    // border bottom 1
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(20.25, 2.50);
    glVertex2f(20.25, 2.25);
    glVertex2f(23.25, 2.25);
    glVertex2f(23.25, 2.50);
    glEnd();

    // 2
    glBegin(GL_POLYGON);
    set_color("Hawaiian Tan");
    glVertex2f(23.25, 4.0);
    glVertex2f(23.25, 2.25);
    glVertex2f(24.50, 3.0);
    glVertex2f(24.50, 4.75);
    glEnd();

    // border top 2
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(23.25, 4.25);
    glVertex2f(23.25, 4.0);
    glVertex2f(24.50, 4.75);
    glVertex2f(24.50, 5.0);
    glEnd();

    // 3
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(21.25, 6.0);
    glVertex2f(21.25, 5.0);
    glVertex2f(24.50, 5.0);
    glVertex2f(24.50, 6.0);
    glEnd();

    // 3d side
    glBegin(GL_POLYGON);
    set_color("Hawaiian Tan");
    glVertex2f(24.50, 6.25);
    glVertex2f(24.50, 3.0);
    glVertex2f(26, 3.75);
    glVertex2f(26, 7);
    glEnd();

    // border top
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(20.75, 6.25);
    glVertex2f(20.75, 6.00);
    glVertex2f(24.50, 6.0);
    glVertex2f(24.50, 6.25);
    glEnd();

    // top side border
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(24.50, 6.25);
    glVertex2f(24.50, 6.0);
    glVertex2f(26, 6.75);
    glVertex2f(26, 7);
    glEnd();

    // new 4
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(26, 7);
    glVertex2f(26, 3.75);
    glVertex2f(30.50, 3.75);
    glVertex2f(30.50, 7);
    glEnd();

    // border bottom
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(26, 4);
    glVertex2f(26, 3.75);
    glVertex2f(30.50, 3.75);
    glVertex2f(30.50, 4);
    glEnd();

    // top
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(26, 7);
    glVertex2f(26, 6.75);
    glVertex2f(30.50, 6.75);
    glVertex2f(30.50, 7);
    glEnd();

    // border bottom 2 & 3
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(23.25, 2.50);
    glVertex2f(23.25, 2.25);
    glVertex2f(26, 3.75);
    glVertex2f(26, 4);
    glEnd();

    // new 4 3d effect side
    glBegin(GL_POLYGON);
    set_color("Hairy Heath");
    glVertex2f(30.50, 7);
    glVertex2f(30.50, 3.75);
    glVertex2f(31, 4);
    glVertex2f(31, 6.75);
    glEnd();

    // bottom border
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(30.50, 4);
    glVertex2f(30.50, 3.75);
    glVertex2f(31, 4);
    glVertex2f(31, 4.25);
    glEnd();

    // top border
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(30.50, 7);
    glVertex2f(30.50, 6.75);
    glVertex2f(31, 6.50);
    glVertex2f(31, 6.75);
    glEnd();

    // yard
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(23.25, 2.25);
    glVertex2f(30.50, 3.75);
    glVertex2f(26, 3.75);
    glEnd();

    // roof 1
    glBegin(GL_POLYGON);
    glColor3ub(20, 90, 50);
    glVertex2f(21.25, 5.0);
    glVertex2f(20.0, 4.25);
    glColor3ub(25, 111, 61);
    glVertex2f(23.25, 4.25);
    glColor3ub(30, 132, 73);
    glVertex2f(24.50, 5.0);
    glEnd();

    // roof 2
    glBegin(GL_POLYGON);
    glColor3ub(20, 90, 50);
    glVertex2f(20.75, 6.25);
    glColor3ub(25, 111, 61);
    glVertex2f(24.50, 6.25);
    glColor3ub(30, 132, 73);
    glVertex2f(26.0, 7.0);
    glColor3ub(34, 153, 84);
    glVertex2f(22.0, 7.0);
    glEnd();

    Wh_door();
    Warehouse_shadow();

    // dark to light
    // glColor3ub(20, 90, 50);
    // glColor3ub(25, 111, 61);
    // glColor3ub(30, 132, 73);
    // glColor3ub(34, 153, 84);
}

void Truck_1()
{

    // Object: Truck
    //  Back site of the truck
    glBegin(GL_POLYGON);
    glColor3ub(46, 134, 193);
    // glColor3ub(33, 97, 140);
    glVertex2f(-9.75, -3.75);
    glVertex2f(-9.75, -0.50);
    glVertex2f(-4.00, -0.50);
    glVertex2f(-4.00, -3.75);
    glVertex2f(-9.75, -3.75);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(20, 148, 242 );
    glColor3ub(0, 125, 218);
    glVertex2f(-9.50, -1.50);
    glVertex2f(-9.50, -0.75);
    glVertex2f(-4.25, -0.75);
    glVertex2f(-4.25, -1.50);
    glVertex2f(-9.50, -1.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(48, 183, 229);
    glColor3ub(3, 168, 224);
    glVertex2f(-9.50, -2.50);
    glVertex2f(-9.50, -1.50);
    glVertex2f(-4.25, -1.50);
    glVertex2f(-4.25, -2.50);
    glVertex2f(-9.50, -2.50);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(38, 176, 183);
    glColor3ub(0, 125, 218);
    glVertex2f(-9.50, -2.50);
    glVertex2f(-9.50, -2.50);
    glVertex2f(-4.25, -2.50);
    glVertex2f(-4.25, -3.50);
    glVertex2f(-9.50, -3.50);
    glEnd();

    // Front side of the Truck
    glBegin(GL_POLYGON);
    glColor3ub(27, 38, 49);
    glVertex2f(-4.00, -1.75);
    glVertex2f(-3.75, -1.75);
    glVertex2f(-3.75, -4.25);
    glVertex2f(-4.00, -4.25);
    glVertex2f(-4.00, -1.75);
    glEnd();

    glBegin(GL_POLYGON);
    //  glColor3ub( 241, 196, 15);// Yellow-1
    glColor3ub(0, 92, 188);
    glVertex2f(-3.75, -3.00);
    glVertex2f(-3.75, -1.50);
    glVertex2f(-1.75, -1.50);
    glVertex2f(-1.00, -2.75);
    glVertex2f(-1.00, -3.00);
    glVertex2f(-3.75, -3.00);
    glEnd();
    glBegin(GL_POLYGON);
    //  glColor3ub( 241, 196, 15);// Yellow-2
    glColor3ub(0, 92, 188);
    glVertex2f(-3.75, -4.25);
    glVertex2f(-3.75, -3.00);
    glVertex2f(-2.75, -3.00);
    glVertex2f(-2.75, -3.25);
    glVertex2f(-3.25, -3.50);
    glVertex2f(-3.50, -3.75);
    glVertex2f(-3.50, -4.25);
    glVertex2f(-3.75, -4.25);
    glEnd();
    glBegin(GL_POLYGON);
    // glColor3ub( 241, 196, 15);// Yellow-3
    glColor3ub(0, 92, 188);
    glVertex2f(-2.75, -3.00);
    glVertex2f(-1.00, -3.00);
    glVertex2f(-1.00, -4.00);
    glVertex2f(-2.00, -4.00);
    glVertex2f(-2.00, -3.75);
    glVertex2f(-2.25, -3.50);
    glVertex2f(-2.75, -3.25);
    glVertex2f(-2.75, -3.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 38, 49);
    glVertex2f(-2.00, -4.25);
    glVertex2f(-2.00, -4.00);
    glVertex2f(-1.00, -4.00);
    glVertex2f(-1.00, -4.25);
    glVertex2f(-2.00, -4.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(234, 236, 238); // Light
    glVertex2f(-1.25, -3.50);
    glVertex2f(-1.25, -3.25);
    glVertex2f(-1.00, -3.25);
    glVertex2f(-1.00, -3.50);
    glVertex2f(-1.25, -3.50);
    glEnd();

    // Under container
    glBegin(GL_POLYGON);
    glColor3ub(93, 109, 126);
    glVertex2f(-4.75, -4.00);
    glVertex2f(-4.75, -3.75);
    glVertex2f(-4.00, -3.75);
    glVertex2f(-4.00, -4.00);
    glVertex2f(-4.75, -4.00);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(-7.50, -3.75);
    glVertex2f(-4.75, -3.75);
    glVertex2f(-4.75, -4.25);
    glVertex2f(-7.25, -4.25);
    glVertex2f(-7.25, -4.00);
    glVertex2f(-7.50, -3.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187); // 1
    glVertex2f(-7.00, -3.75);
    glVertex2f(-6.50, -3.75);
    glVertex2f(-6.50, -4.00);
    glVertex2f(-7.00, -4.00);
    glVertex2f(-7.00, -3.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187); // 2
    glVertex2f(-6.25, -4.00);
    glVertex2f(-6.25, -3.75);
    glVertex2f(-5.00, -3.75);
    glVertex2f(-5.00, -4.00);
    glVertex2f(-6.25, -4.00);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(229, 35, 29); // red
    glVertex2f(-9.50, -4.25);
    glVertex2f(-9.50, -3.75);
    glVertex2f(-9.25, -3.75);
    glVertex2f(-9.25, -4.25);
    glVertex2f(-9.50, -4.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(93, 109, 126);
    glVertex2f(-9.25, -4.25);
    glVertex2f(-9.25, -3.75);
    glVertex2f(-8.75, -3.75);
    glVertex2f(-8.75, -4.25);
    glVertex2f(-9.25, -4.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(-8.75, -4.00);
    glVertex2f(-8.75, -3.75);
    glVertex2f(-8.50, -3.75);
    glVertex2f(-8.75, -4.00);
    glEnd();

    // Truck window
    glBegin(GL_POLYGON);
    glColor3ub(213, 216, 220);
    glVertex2f(-3.25, -2.50);
    glVertex2f(-3.25, -1.75);
    glVertex2f(-2.00, -1.75);
    glVertex2f(-1.25, -2.75);
    glVertex2f(-3.25, -2.50);
    glEnd();

    circle(0.59, -2.75, -4.00, 28, 40, 51);    // front big
    circle(0.33, -2.75, -4.00, 128, 139, 150); // front small
    circle(0.59, -8.00, -4.00, 28, 40, 51);    // back big
    circle(0.33, -8.00, -4.00, 128, 139, 150); // back small
}

void Adjust_Truck()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5, 0.5, 1);
    glTranslatef(50 + truckX, 5, 0);
    Truck_1();
    glPopMatrix();
}

void background_2()
{

    Road_1();
    Warehouse_2();
    Ship_1();
    Container_2();
    Crane2();
    Container_4();
    Container_3();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(moveXh, 0.0f, 0.0f);
    hook();
    glPopMatrix();

    Magnet();
    Crane1();
    Crane1Design();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(moveShip, 0.0f, 0.0f);
    Adjust_ship();
    glPopMatrix();

    Adjust_Truck();
}

void drawSingleBirdGlobal(float x, float y, float wingPhase)
{
    float flap = 0.12f * sinf(wingPhase);
    glColor3ub(20, 20, 20);
    glLineWidth(1.5f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x - 0.35f, y + flap);
    glVertex2f(x - 0.17f, y + flap + 0.12f);
    glVertex2f(x,         y);
    glVertex2f(x + 0.17f, y + flap + 0.12f);
    glVertex2f(x + 0.35f, y + flap);
    glEnd();
    glLineWidth(1.0f);
}

void drawBirds1()
{
    if (!isDayScene || isRaining) return;
    for (int i = 0; i < NUM_BIRDS; i++)
    {
        if (birds[i].x > 0.0f && birds[i].x < 32.0f)
            drawSingleBirdGlobal(birds[i].x, birds[i].y, birds[i].wingPhase);
    }
}

void drawBirds2()
{
    if (!isDayScene || isRaining) return;
    for (int i = 0; i < NUM_BIRDS; i++)
    {
        float bx = (birds[i].x / 32.0f) * 82.0f - 41.0f;
        float t  = (birds[i].y - 14.8f) / (17.0f - 14.8f);
        float by = 18.0f + t * 8.0f;
        if (bx > -41.0f && bx < 41.0f)
            drawSingleBirdGlobal(bx, by, birds[i].wingPhase);
    }
}

void display1()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    background_1();
    background_2();
    drawBirds1();
    drawRain1();
    glutSwapBuffers();
    glFlush();
}

void Cranekeyboard(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        if (moveY <= 0)
        {
            moveY += speed;
            stringY += speed;
            if (pick == true)
            {
                if (movecY <= 2.5)
                {
                    movecY += speed;
                }
            }
        }
        break;

    case GLUT_KEY_DOWN:
        if (moveY >= -2.5)
        {
            moveY -= speed;
            stringY -= speed;

            if (movecY > 0 && pick == true)
            {
                movecY -= speed;
            }
        }
        break;

    case GLUT_KEY_LEFT:
        if (moveY >= 0 && moveXh >= 0)
        {

            moveXh -= speed;
            if (pick == true)
            {
                movecX -= speed;
            }
        }
        break;

    case GLUT_KEY_RIGHT:
        if (moveY >= 0 && moveXh <= 12.5)
        {
            moveXh += speed;
            if (pick == true)
            {
                movecX += speed;
            }
        }
        break;
    }
    glutPostRedisplay();
}

void shipAnimation(int value)
{

    if (ship_start == true)
    {
        moveShip += shipSpeed;
        if (moveShip > 31.5f)
        {
            moveShip = 31.5;
            ship_start2 = true;
            train_start2 = true;
            currentDisplay = 2;
        }
    }
    else
    {
        // ship not started, position unchanged
    }
    glutPostRedisplay();
    glutTimerFunc(20, shipAnimation, 0);
}

void CloudMovement(int value)
{
    cloudX -= 0.02;
    // Reset when one full set has passed
    if (cloudX <= -45.0f)
    {
        cloudX = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, CloudMovement, 0);
}

void truckMovement(int value)
{
    if (truckStart == true)
    {
        truckX += 0.05;
        if (truckX >= 35)
        {
            truckX = 50;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, truckMovement, 0);
}
//----------------------------------------------------End of Scenario 1-----------------------------------------------------------------------------


string getMusicPath(const string &filename)
{
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);
    string dir(exePath);
    for (int i = 0; i < 3; i++)
    {
        size_t pos = dir.find_last_of("\\/");
        if (pos != string::npos)
            dir = dir.substr(0, pos);
    }
    return dir + "\\music\\" + filename;
}

void playShipSound()
{
    string cmd = "open \"" + getMusicPath("Ship.wav") + "\" type waveaudio alias ship";
    mciSendString("close ship", NULL, 0, NULL);
    mciSendString(cmd.c_str(), NULL, 0, NULL);
    mciSendString("play ship", NULL, 0, NULL);
}
void playTruckSound()
{
    string cmd = "open \"" + getMusicPath("Truck.wav") + "\" type waveaudio alias truck";
    mciSendString("close truck", NULL, 0, NULL);
    mciSendString(cmd.c_str(), NULL, 0, NULL);
    mciSendString("play truck", NULL, 0, NULL);
}

void playRainSound()
{
    string cmd = "open \"" + getMusicPath("Rain.wav") + "\" type waveaudio alias rain";
    mciSendString("close rain", NULL, 0, NULL);
    mciSendString(cmd.c_str(), NULL, 0, NULL);
    mciSendString("play rain", NULL, 0, NULL);
}
void stopRainSound()
{
    mciSendString("stop rain", NULL, 0, NULL);
    mciSendString("close rain", NULL, 0, NULL);
}

void playWaterSound()
{
    string cmd = "open \"" + getMusicPath("Water.wav") + "\" type waveaudio alias water3";
    mciSendString("close water3", NULL, 0, NULL);
    mciSendString(cmd.c_str(), NULL, 0, NULL);
    mciSendString("play water3 repeat", NULL, 0, NULL);
}
void stopWaterSound()
{
    mciSendString("stop water3", NULL, 0, NULL);
    mciSendString("close water3", NULL, 0, NULL);
}

void keyboard_raf(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'm':
    case 'M':
        isDayScene = true;
        break;
    case 'n':
    case 'N':
        isDayScene = false;
        break;
    case 'p':
    case 'P':
        if (moveY <= -2.5)
        {
            if (moveXh == movecX)
            {
                pick = true;
            }
        }
        break;
    case 'b':
    case 'B':
        isRaining = !isRaining;
        if (isRaining)
        {
            playRainSound();
        }
        else
        {
            stopRainSound();
        }
        break;

    case 'r':
        if (movecY <= 0.5)
        {
            pick = false;
        }
        break;
    case 'w':
    case 'W':
        ship_start = true;
        playShipSound();
        break;

    case 'q':
    case 'Q':
        ship_start = false;
        PlaySound(NULL, 0, 0);
        break;
    case 't':
    case 'T':
        truckStart = true;
        playTruckSound();
        break;

    case 'y':
    case 'Y':
        truckStart = false;
        PlaySound(NULL, 0, 0);
        break;
    case 32: // SPACE key
        // Reset scene
        currentDisplay = 1;
        // Reset positions
        moveXh = 0.0f;
        moveY = 0.0f;
        movecY = 0.0f;
        movecX = 0.0f;
        moveShip = 0.0f;
        moveShip3 = -43.0f;
        truckX = 0.0f;
        stringY = 0.0f;
        cloudX = 0.0f;
        Ship_position = -70.0f;
        train_position = -70.0f;
        shipSpeed = 0.02f;
        speed = 0.05f;
        // Reset state flags
        pick = false;
        release = false;
        ship_start = false;
        ship_start2 = false;
        ship_start3 = false;
        train_start2 = false;
        truckStart = false;
        trainSoundPlayed = false;
        waterSoundPlayed = false;
        stopWaterSound();
        trainMovedOnce = false;
        showRestartMessage = false;
        isRaining = false;
        // Reset Scenario 3 animations
        waveOffset = 0.0f;
        birdsInitialized = false;
        skyDarkness = 0.0f;
        stormActive = true;
        lightningAlpha = 0.0f;
        lightningTimer = 0.0f;
        nextLightningAt = 2.5f;
        s3CloudX1 = 2.0f;
        s3CloudX2 = 18.0f;
        PlaySound(NULL, 0, 0);
        mciSendString("stop truck", NULL, 0, NULL);
        mciSendString("close truck", NULL, 0, NULL);
        mciSendString("stop ship", NULL, 0, NULL);
        mciSendString("close ship", NULL, 0, NULL);
        mciSendString("stop rain", NULL, 0, NULL);
        mciSendString("close rain", NULL, 0, NULL);
        mciSendString("stop train", NULL, 0, NULL);
        mciSendString("close train", NULL, 0, NULL);
        mciSendString("stop water3", NULL, 0, NULL);
        mciSendString("close water3", NULL, 0, NULL);
        break;
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void display()
{
    if (currentDisplay == 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 32, 0, 18);
        display1();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutSwapBuffers();
    }
    
}

void showInfoScreen()
{
    SetConsoleOutputCP(CP_UTF8);
    // Credits
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                  All Rights Reserved by                     ║\n");
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "NAME", "ID", "CONTRIBUTION");
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "Nusrat Faraezi Ivy", "22-48608-3", "Scenario 1 & 3");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "Nusrat Jahan Raina", "23-50416-1", "Scenario 2 & 3");
    printf("╚═════════════════════════════════════════════════════════════╝\n\n");
    // User Control Guide
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                    USER CONTROL GUIDE                       ║\n");
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ w : Start the ship in scenario 1                            ║\n");
    printf("║ q : Stop the ship in scenario 1                             ║\n");
    printf("║ t : Start the truck in scenario 1                           ║\n");
    printf("║ y : Stop the truck in scenario 1                            ║\n");
    printf("║ ↑ : Move up    (crane hook block)                           ║\n");
    printf("║ ↓ : Move down  (crane hook block)                           ║\n");
    printf("║ → : Move right (crane hook block)                           ║\n");
    printf("║ ← : Move left  (crane hook block)                           ║\n");
    printf("║ p : Pick container when hook is above it                    ║\n");
    printf("║ r : Release container at ground                             ║\n");
    printf("║ n : Switch to day scenario                                  ║\n");
    printf("║ m : Switch to night scenario                                ║\n");
    printf("║ b : Toggle rain effect                                      ║\n");
    printf("║ SpaceBar : Reset the simulation                             ║\n");
    printf("║ ESC : Exit the simulation                                   ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n");
}

int main(int argc, char **argv)
{
    showInfoScreen();
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Cargoport Simulation");
    glutFullScreen();
    CloudMovement(0);
    glutDisplayFunc(display);
    glutSpecialFunc(Cranekeyboard);
    glutTimerFunc(20, shipAnimation, 0);
    glutTimerFunc(20, CloudMovement, 0);
    glutTimerFunc(20, truckMovement, 0);
    glutTimerFunc(20, shipAnimation2, 0);
    glutTimerFunc(20, shipAnimation3, 0);
    glutTimerFunc(16, updateScene3Anims, 0);
    initBirds();
    glutTimerFunc(0, update, 0);
    glutKeyboardFunc(keyboard_raf);
    srand(time(0));
    for (int i = 0; i < numDrops; ++i)
    {
        rainX[i] = (rand() % 82) - 41;
        rainY[i] = (rand() % 55) - 25;
    }
    glutTimerFunc(10, rainUpdate, 0);
    glutMainLoop();
    return 0;
}
