//----------------------------------------------------Start of Scenario 2-----------------------------------------------------------------------------

float Ship_position = -105;
float Ship_speed = 0.18;
float Dew_position = -10;
float Dew_speed = 0.006;
float cloud_position = -10;
float cloud_speed = 0.01;
float train_position = -70;
float train_speed = 0.15;

void Sun()
{
    if (isDayScene == true)
    {
        // MIDPOINT ELLIPSE ALGORITHM: sun drawn as a slightly
        // flattened ellipse (wider than tall) in Scene 2.
        glPushMatrix();
        glScalef(7, 6, 1);
        glTranslatef(2, 4.9f, 0);
        drawMidpointEllipse(0.0f, 0.0f, 0.85f, 0.72f, 255, 187, 68);
        glPopMatrix();
    }
}

void Moon()
{
    if (isDayScene == false)
    {
        // MIDPOINT ELLIPSE ALGORITHM: moon drawn as a slightly
        // taller-than-wide ellipse (ry > rx) in Scene 2 night.
        glPushMatrix();
        glScalef(4, 4, 1);
        glTranslatef(-6, 6, 0);
        drawMidpointEllipse(0.0f, 0.0f, 0.72f, 0.85f, 255, 255, 255);
        glPopMatrix();
    }
}

void Dew()
{
    glBegin(GL_POLYGON); // Buildings
    set_color("DewC");   // Yellow
    glVertex2f(8.0f, -6.50f);
    glVertex2f(8.0f, -6.75f);
    glVertex2f(9.0f, -7.25f);
    glVertex2f(10.75f, -7.50f);
    glVertex2f(12.50f, -7.25f);
    glVertex2f(13.25f, -6.75f);
    glVertex2f(10.50f, -6.25f);
    glVertex2f(8.50f, -6.25f);
    glVertex2f(12.50f, -7.25f);
    glEnd();
}

void adjust_dew()
{

    glPushMatrix();
    glScalef(5, 0.5, 0);
    glTranslatef(-5, -12, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(5, 0.5, 0);
    glTranslatef(-3, -25, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(5, 0.5, 0);
    glTranslatef(-17, -25, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(5, 0.5, 0);
    glTranslatef(-10, -29, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3, 0.3, 0);
    glTranslatef(-12, -8.6, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3, 0.3, 0);
    glTranslatef(-19, -8, 0);
    Dew();
    glPopMatrix();

    //
    glPushMatrix();
    glScalef(1, 0.3, 0);
    glTranslatef(-10, 10, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 0.3, 0);
    glTranslatef(-17, 8, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 0.3, 0);
    glTranslatef(-32, 9, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 0.3, 0);
    glTranslatef(0, 10, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 0.3, 0);
    glTranslatef(6, 8, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(2, 0.3, 0);
    glTranslatef(-2, -3, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(2, 0.3, 0);
    glTranslatef(6, -6, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3, 0.3, 0);
    glTranslatef(-28, -6, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3, 0.3, 0);
    glTranslatef(-35, -12, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(6, 0.5, 0);
    glTranslatef(-10, -16, 0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(6, 0.5, 0);
    glTranslatef(-15, -12, 0);
    Dew();
    glPopMatrix();
}

void Full_Dew()
{
    adjust_dew();
}

void Animation_dew()
{
    glPushMatrix();
    glTranslatef(Dew_position, 0, 0);
    Full_Dew();
    glPopMatrix();
}

void buildingwindow(float Sx, float Sy, float Tx, float Ty)
{
    glPushMatrix();
    glScalef(Sx, Sy, 1);
    glTranslatef(Tx, Ty, 0);
    glBegin(GL_QUADS);
    set_color("buildingglass");
    glVertex3f(-5.0f, 3.0f, 0.0f);
    glVertex3f(5.0f, 3.0f, 0.0f);
    glVertex3f(5.0f, 5.0f, 0.0f);
    glVertex3f(-5.0f, 5.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void stars()
{
    if (isDayScene == false)
    {
        glBegin(GL_POINTS);
        set_color("nightstars");
        glVertex2f(35.0f, 20.0f);
        glEnd();
    }
}

void adjust_stars()
{
    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(130, 90, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(90, 110, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(20, 115, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(37, 100, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(50, 85, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(70, 100, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(60, 60, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(110, 100, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(100, 70, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(140, 100, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(80, 82, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(10, 82, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(0, 95, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(160, 110, 0);
    stars();
    glPopMatrix();

    // Left stars
    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-30, 90, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-50, 120, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-45, 70, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-55, 95, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-90, 80, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-140, 95, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-110, 120, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-180, 115, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-130, 75, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-150, 125, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-170, 70, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-190, 85, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-210, 100, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-230, 110, 0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-225, 70, 0);
    stars();
    glPopMatrix();
}

void buildingwindowtwo(float Sx, float Sy, float Tx, float Ty)
{
    glPushMatrix();
    glScalef(Sx, Sy, 1);
    glTranslatef(Tx, Ty, 0);
    glBegin(GL_QUADS);
    set_color("buildingglass");
    glVertex3f(1.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, 4.0f, 0.0f);
    glVertex3f(1.0f, 4.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void twintowerwindow(float Sx, float Sy, float Tx, float Ty)
{
    glPushMatrix();
    glScalef(Sx, Sy, 1);
    glTranslatef(Tx, Ty, 0);
    glBegin(GL_QUADS);
    set_color("buildingglass");
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, 2.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void bridgeBrike(float Sx, float Sy, float Tx, float Ty)
{
    glPushMatrix();
    glScalef(Sx, Sy, 1);
    glTranslatef(Tx, Ty, 0);
    glBegin(GL_QUADS);
    set_color("brick");
    glVertex3f(1.0f, 0.50f, 0.0f);
    glVertex3f(2.0f, 0.50f, 0.0f);
    glVertex3f(2.0f, 0.75f, 0.0f);
    glVertex3f(1.0f, 0.75f, 0.0f);
    glEnd();
    glPopMatrix();
}

void bridgenut(float Sx, float Sy, float Tx, float Ty)
{
    glPushMatrix();
    glScalef(Sx, Sy, 1);
    glTranslatef(Tx, Ty, 0);
    glBegin(GL_QUADS);
    set_color("brick");
    glVertex3f(1.0f, 0.25f, 0.0f);
    glVertex3f(1.25f, 0.25f, 0.0f);
    glVertex3f(1.25f, 0.50f, 0.0f);
    glVertex3f(1.0f, 0.50f, 0.0f);
    glEnd();
    glPopMatrix();
}

void drawBuilding()
{
    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(40.0f, 3.0f);
    glVertex2f(40.0f, 11.0f);
    glVertex2f(36.0f, 11.0f);
    glVertex2f(36.0f, 3.0f);
    glEnd();

    buildingwindow(0.3, 0.2, 127, 50);
    buildingwindow(0.3, 0.2, 127, 45);
    buildingwindow(0.3, 0.2, 127, 40);
    buildingwindow(0.3, 0.2, 127, 35);
    buildingwindow(0.3, 0.2, 127, 30);
    buildingwindow(0.3, 0.2, 127, 25);
    buildingwindow(0.3, 0.2, 127, 20);

    glBegin(GL_POLYGON);        // Buildings
    set_color("frontBuilding"); // Yellow
    glVertex2f(34.0f, 3.0f);
    glVertex2f(34.0f, 14.0f);
    glVertex2f(29.0f, 14.0f);
    glVertex2f(29.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, 60, 10);
    buildingwindowtwo(0.5, 0.5, 62, 10);
    buildingwindowtwo(0.5, 0.5, 60, 14);
    buildingwindowtwo(0.5, 0.5, 62, 14);
    buildingwindowtwo(0.5, 0.5, 60, 18);
    buildingwindowtwo(0.5, 0.5, 62, 18);
    glBegin(GL_POLYGON);      // Buildings
    set_color("midBuilding"); // Yellow
    glVertex2f(36.0f, 3.0f);
    glVertex2f(36.0f, 8.0f);
    glVertex2f(32.0f, 8.0f);
    glVertex2f(32.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 114, 35);
    buildingwindow(0.3, 0.2, 114, 30);
    buildingwindow(0.3, 0.2, 114, 25);
    buildingwindow(0.3, 0.2, 114, 20);
    buildingwindow(0.3, 0.2, 114, 15);
    // Render now
    // upore sob right side ar building
    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(28.0f, 3.0f);
    glVertex2f(28.0f, 11.0f);
    glVertex2f(23.0f, 11.0f);
    glVertex2f(23.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 83, 45);
    buildingwindow(0.3, 0.2, 83, 40);
    buildingwindow(0.3, 0.2, 83, 35);
    buildingwindow(0.3, 0.2, 83, 30);
    buildingwindow(0.3, 0.2, 83, 25);
    buildingwindow(0.3, 0.2, 83, 20);
    buildingwindow(0.3, 0.2, 83, 15);
    glBegin(GL_POLYGON);      // Buildings
    set_color("midBuilding"); // Yellow
    glVertex2f(30.0f, 3.0f);
    glVertex2f(30.0f, 9.0f);
    glVertex2f(26.0f, 9.0f);
    glVertex2f(26.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 93, 35);
    buildingwindow(0.3, 0.2, 93, 30);
    buildingwindow(0.3, 0.2, 93, 25);
    buildingwindow(0.3, 0.2, 93, 20);
    buildingwindow(0.3, 0.2, 93, 15);
    // right 2nd
    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(23.0f, 3.0f);
    glVertex2f(23.0f, 10.0f);
    glVertex2f(18.0f, 10.0f);
    glVertex2f(18.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, 39, 10);
    buildingwindowtwo(0.5, 0.5, 41, 14);
    buildingwindowtwo(0.5, 0.5, 41, 6);
    glBegin(GL_POLYGON);        // Buildings
    set_color("frontBuilding"); // Yellow
    glVertex2f(19.0f, 3.0f);
    glVertex2f(19.0f, 9.0f);
    glVertex2f(14.0f, 9.0f);
    glVertex2f(14.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 55, 35);
    buildingwindow(0.3, 0.2, 55, 30);
    buildingwindow(0.3, 0.2, 55, 25);
    buildingwindow(0.3, 0.2, 55, 20);
    buildingwindow(0.3, 0.2, 55, 15);

    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(14.0f, 3.0f);
    glVertex2f(14.0f, 12.0f);
    glVertex2f(9.0f, 12.0f);
    glVertex2f(9.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 39, 45);
    buildingwindow(0.3, 0.2, 39, 40);
    buildingwindow(0.3, 0.2, 39, 35);
    buildingwindow(0.3, 0.2, 39, 30);
    buildingwindow(0.3, 0.2, 39, 25);
    buildingwindow(0.3, 0.2, 39, 20);
    buildingwindow(0.3, 0.2, 39, 15);
    glBegin(GL_POLYGON);        // Buildings
    set_color("frontBuilding"); // Yellow
    glVertex2f(10.0f, 3.0f);
    glVertex2f(10.0f, 11.0f);
    glVertex2f(5.0f, 11.0f);
    glVertex2f(5.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, 15, 10);
    buildingwindowtwo(0.5, 0.5, 15, 14);
    buildingwindowtwo(0.5, 0.5, 15, 6);
    buildingwindowtwo(0.5, 0.5, 13, 10);
    buildingwindowtwo(0.5, 0.5, 13, 14);
    buildingwindowtwo(0.5, 0.5, 13, 6);
    buildingwindowtwo(0.5, 0.5, 11, 10);
    buildingwindowtwo(0.5, 0.5, 11, 14);
    buildingwindowtwo(0.5, 0.5, 11, 6);

    // NEW BUILDINGS

    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(-40.0f, 3.0f);
    glVertex2f(-40.0f, 11.0f);
    glVertex2f(-36.0f, 11.0f);
    glVertex2f(-36.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -127, 50);
    buildingwindow(0.3, 0.2, -127, 45);
    buildingwindow(0.3, 0.2, -127, 40);
    buildingwindow(0.3, 0.2, -127, 35);
    buildingwindow(0.3, 0.2, -127, 30);
    buildingwindow(0.3, 0.2, -127, 25);
    buildingwindow(0.3, 0.2, -127, 20);

    glBegin(GL_POLYGON);        // Buildings
    set_color("frontBuilding"); // Yellow
    glVertex2f(-34.0f, 3.0f);
    glVertex2f(-34.0f, 13.0f);
    glVertex2f(-29.0f, 13.0f);
    glVertex2f(-29.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, -65, 10);
    buildingwindowtwo(0.5, 0.5, -62, 10);
    buildingwindowtwo(0.5, 0.5, -65, 14);
    buildingwindowtwo(0.5, 0.5, -62, 14);
    buildingwindowtwo(0.5, 0.5, -65, 18);
    buildingwindowtwo(0.5, 0.5, -62, 18);

    // left bildig 1st
    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(-36.0f, 3.0f);
    glVertex2f(-36.0f, 8.0f);
    glVertex2f(-32.0f, 8.0f);
    glVertex2f(-32.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -114, 35);
    buildingwindow(0.3, 0.2, -114, 30);
    buildingwindow(0.3, 0.2, -114, 25);
    buildingwindow(0.3, 0.2, -114, 20);
    buildingwindow(0.3, 0.2, -114, 15);

    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(-28.0f, 3.0f);
    glVertex2f(-28.0f, 11.0f);
    glVertex2f(-23.0f, 11.0f);
    glVertex2f(-23.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -83, 45);
    buildingwindow(0.3, 0.2, -83, 40);
    buildingwindow(0.3, 0.2, -83, 35);
    buildingwindow(0.3, 0.2, -83, 30);
    buildingwindow(0.3, 0.2, -83, 25);
    buildingwindow(0.3, 0.2, -83, 20);
    buildingwindow(0.3, 0.2, -83, 15);

    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(-30.0f, 3.0f);
    glVertex2f(-30.0f, 9.0f);
    glVertex2f(-26.0f, 9.0f);
    glVertex2f(-26.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -93, 35);
    buildingwindow(0.3, 0.2, -93, 30);
    buildingwindow(0.3, 0.2, -93, 25);
    buildingwindow(0.3, 0.2, -93, 20);
    buildingwindow(0.3, 0.2, -93, 15);

    glBegin(GL_POLYGON);      // Buildings
    set_color("midBuilding"); // Yellow
    glVertex2f(-23.0f, 3.0f);
    glVertex2f(-23.0f, 10.0f);
    glVertex2f(-18.0f, 10.0f);
    glVertex2f(-18.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, -43, 10);
    buildingwindowtwo(0.5, 0.5, -41, 14);
    buildingwindowtwo(0.5, 0.5, -41, 6);

    glBegin(GL_POLYGON);        // Buildings
    set_color("bulidingcolor"); // Yellow
    glVertex2f(-19.0f, 3.0f);
    glVertex2f(-19.0f, 9.0f);
    glVertex2f(-14.0f, 9.0f);
    glVertex2f(-14.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -55, 35);
    buildingwindow(0.3, 0.2, -55, 30);
    buildingwindow(0.3, 0.2, -55, 25);
    buildingwindow(0.3, 0.2, -55, 20);
    buildingwindow(0.3, 0.2, -55, 15);

    glBegin(GL_POLYGON);      // Buildings
    set_color("midBuilding"); // Yellow
    glVertex2f(-14.0f, 3.0f);
    glVertex2f(-14.0f, 12.0f);
    glVertex2f(-9.0f, 12.0f);
    glVertex2f(-9.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, -25, 10);
    buildingwindowtwo(0.5, 0.5, -25, 14);
    buildingwindowtwo(0.5, 0.5, -25, 6);
    buildingwindowtwo(0.5, 0.5, -23, 10);
    buildingwindowtwo(0.5, 0.5, -23, 14);
    buildingwindowtwo(0.5, 0.5, -23, 6);
    buildingwindowtwo(0.5, 0.5, -21, 10);
    buildingwindowtwo(0.5, 0.5, -21, 14);
    buildingwindowtwo(0.5, 0.5, -21, 6);
}

void drawBuildingL()
{
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(40.0f, 3.0f);
    glVertex2f(40.0f, 11.0f);
    glVertex2f(36.0f, 11.0f);
    glVertex2f(36.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 127, 50);
    buildingwindow(0.3, 0.2, 127, 45);
    buildingwindow(0.3, 0.2, 127, 40);
    buildingwindow(0.3, 0.2, 127, 35);
    buildingwindow(0.3, 0.2, 127, 30);
    buildingwindow(0.3, 0.2, 127, 25);
    buildingwindow(0.3, 0.2, 127, 20);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(34.0f, 3.0f);
    glVertex2f(34.0f, 14.0f);
    glVertex2f(29.0f, 14.0f);
    glVertex2f(29.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, 60, 10);
    buildingwindowtwo(0.5, 0.5, 62, 10);
    buildingwindowtwo(0.5, 0.5, 60, 14);
    buildingwindowtwo(0.5, 0.5, 62, 14);
    buildingwindowtwo(0.5, 0.5, 60, 18);
    buildingwindowtwo(0.5, 0.5, 62, 18);
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(36.0f, 3.0f);
    glVertex2f(36.0f, 8.0f);
    glVertex2f(32.0f, 8.0f);
    glVertex2f(32.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 114, 35);
    buildingwindow(0.3, 0.2, 114, 30);
    buildingwindow(0.3, 0.2, 114, 25);
    buildingwindow(0.3, 0.2, 114, 20);
    buildingwindow(0.3, 0.2, 114, 15);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(28.0f, 3.0f);
    glVertex2f(28.0f, 11.0f);
    glVertex2f(23.0f, 11.0f);
    glVertex2f(23.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 83, 45);
    buildingwindow(0.3, 0.2, 83, 40);
    buildingwindow(0.3, 0.2, 83, 35);
    buildingwindow(0.3, 0.2, 83, 30);
    buildingwindow(0.3, 0.2, 83, 25);
    buildingwindow(0.3, 0.2, 83, 20);
    buildingwindow(0.3, 0.2, 83, 15);
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(30.0f, 3.0f);
    glVertex2f(30.0f, 9.0f);
    glVertex2f(26.0f, 9.0f);
    glVertex2f(26.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 93, 35);
    buildingwindow(0.3, 0.2, 93, 30);
    buildingwindow(0.3, 0.2, 93, 25);
    buildingwindow(0.3, 0.2, 93, 20);
    buildingwindow(0.3, 0.2, 93, 15);
    // right 2nd
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(23.0f, 3.0f);
    glVertex2f(23.0f, 10.0f);
    glVertex2f(18.0f, 10.0f);
    glVertex2f(18.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, 39, 10);
    buildingwindowtwo(0.5, 0.5, 41, 14);
    buildingwindowtwo(0.5, 0.5, 41, 6);
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(19.0f, 3.0f);
    glVertex2f(19.0f, 9.0f);
    glVertex2f(14.0f, 9.0f);
    glVertex2f(14.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 55, 35);
    buildingwindow(0.3, 0.2, 55, 30);
    buildingwindow(0.3, 0.2, 55, 25);
    buildingwindow(0.3, 0.2, 55, 20);
    buildingwindow(0.3, 0.2, 55, 15);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(14.0f, 3.0f);
    glVertex2f(14.0f, 12.0f);
    glVertex2f(9.0f, 12.0f);
    glVertex2f(9.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 39, 45);
    buildingwindow(0.3, 0.2, 39, 40);
    buildingwindow(0.3, 0.2, 39, 35);
    buildingwindow(0.3, 0.2, 39, 30);
    buildingwindow(0.3, 0.2, 39, 25);
    buildingwindow(0.3, 0.2, 39, 20);
    buildingwindow(0.3, 0.2, 39, 15);
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(10.0f, 3.0f);
    glVertex2f(10.0f, 11.0f);
    glVertex2f(5.0f, 11.0f);
    glVertex2f(5.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, 15, 10);
    buildingwindowtwo(0.5, 0.5, 15, 14);
    buildingwindowtwo(0.5, 0.5, 15, 6);
    buildingwindowtwo(0.5, 0.5, 13, 10);
    buildingwindowtwo(0.5, 0.5, 13, 14);
    buildingwindowtwo(0.5, 0.5, 13, 6);
    buildingwindowtwo(0.5, 0.5, 11, 10);
    buildingwindowtwo(0.5, 0.5, 11, 14);
    buildingwindowtwo(0.5, 0.5, 11, 6);

    // NEW BUILDINGS
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-40.0f, 3.0f);
    glVertex2f(-40.0f, 11.0f);
    glVertex2f(-36.0f, 11.0f);
    glVertex2f(-36.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -127, 50);
    buildingwindow(0.3, 0.2, -127, 45);
    buildingwindow(0.3, 0.2, -127, 40);
    buildingwindow(0.3, 0.2, -127, 35);
    buildingwindow(0.3, 0.2, -127, 30);
    buildingwindow(0.3, 0.2, -127, 25);
    buildingwindow(0.3, 0.2, -127, 20);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-34.0f, 3.0f);
    glVertex2f(-34.0f, 13.0f);
    glVertex2f(-29.0f, 13.0f);
    glVertex2f(-29.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, -65, 10);
    buildingwindowtwo(0.5, 0.5, -62, 10);
    buildingwindowtwo(0.5, 0.5, -65, 14);
    buildingwindowtwo(0.5, 0.5, -62, 14);
    buildingwindowtwo(0.5, 0.5, -65, 18);
    buildingwindowtwo(0.5, 0.5, -62, 18);

    // left bildig 1st
    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-36.0f, 3.0f);
    glVertex2f(-36.0f, 8.0f);
    glVertex2f(-32.0f, 8.0f);
    glVertex2f(-32.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -114, 35);
    buildingwindow(0.3, 0.2, -114, 30);
    buildingwindow(0.3, 0.2, -114, 25);
    buildingwindow(0.3, 0.2, -114, 20);
    buildingwindow(0.3, 0.2, -114, 15);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-28.0f, 3.0f);
    glVertex2f(-28.0f, 11.0f);
    glVertex2f(-23.0f, 11.0f);
    glVertex2f(-23.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -83, 45);
    buildingwindow(0.3, 0.2, -83, 40);
    buildingwindow(0.3, 0.2, -83, 35);
    buildingwindow(0.3, 0.2, -83, 30);
    buildingwindow(0.3, 0.2, -83, 25);
    buildingwindow(0.3, 0.2, -83, 20);
    buildingwindow(0.3, 0.2, -83, 15);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-30.0f, 3.0f);
    glVertex2f(-30.0f, 9.0f);
    glVertex2f(-26.0f, 9.0f);
    glVertex2f(-26.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -93, 35);
    buildingwindow(0.3, 0.2, -93, 30);
    buildingwindow(0.3, 0.2, -93, 25);
    buildingwindow(0.3, 0.2, -93, 20);
    buildingwindow(0.3, 0.2, -93, 15);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-23.0f, 3.0f);
    glVertex2f(-23.0f, 10.0f);
    glVertex2f(-18.0f, 10.0f);
    glVertex2f(-18.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, -43, 10);
    buildingwindowtwo(0.5, 0.5, -41, 14);
    buildingwindowtwo(0.5, 0.5, -41, 6);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-19.0f, 3.0f);
    glVertex2f(-19.0f, 9.0f);
    glVertex2f(-14.0f, 9.0f);
    glVertex2f(-14.0f, 3.0f);
    glEnd();
    buildingwindow(0.3, 0.2, -55, 35);
    buildingwindow(0.3, 0.2, -55, 30);
    buildingwindow(0.3, 0.2, -55, 25);
    buildingwindow(0.3, 0.2, -55, 20);
    buildingwindow(0.3, 0.2, -55, 15);

    glBegin(GL_POLYGON);         // Buildings
    set_color("buildingShadow"); // Yellow
    glVertex2f(-14.0f, 3.0f);
    glVertex2f(-14.0f, 12.0f);
    glVertex2f(-9.0f, 12.0f);
    glVertex2f(-9.0f, 3.0f);
    glEnd();
    buildingwindowtwo(0.5, 0.5, -25, 10);
    buildingwindowtwo(0.5, 0.5, -25, 14);
    buildingwindowtwo(0.5, 0.5, -25, 6);
    buildingwindowtwo(0.5, 0.5, -23, 10);
    buildingwindowtwo(0.5, 0.5, -23, 14);
    buildingwindowtwo(0.5, 0.5, -23, 6);
    buildingwindowtwo(0.5, 0.5, -21, 10);
    buildingwindowtwo(0.5, 0.5, -21, 14);
    buildingwindowtwo(0.5, 0.5, -21, 6);
}

void drawWater()
{
    glBegin(GL_POLYGON);
    // set_color("waterCU")
    glColor3ub(18, 146, 173);
    glVertex2f(-41.0f, -8.0f);
    glVertex2f(41.0f, -8.0f);
    glVertex2f(41.0f, 3.0f);
    glVertex2f(-41.0f, 3.0f);
    glEnd();

    glBegin(GL_POLYGON);
    // set_color("waterCD")
    glColor3ub(89, 207, 230);
    glVertex2f(-41.0f, -25.0f);
    glVertex2f(41.0f, -25.0f);
    glColor3ub(18, 146, 173);
    glVertex2f(41.0f, 3.0f);
    glVertex2f(-41.0f, 3.0f);
    glEnd();
}

void drawWaterNight()
{
    if (isDayScene == false)
    {

        glBegin(GL_POLYGON);
        // set_color("waterCU")
        glColor3ub(89, 207, 230);
        glVertex2f(-41.0f, -8.0f);
        glVertex2f(41.0f, -8.0f);
        glVertex2f(41.0f, 3.0f);
        glVertex2f(-41.0f, 3.0f);
        glEnd();

        glBegin(GL_POLYGON);
        // set_color("waterCD")
        glColor3ub(18, 146, 173);
        glVertex2f(-41.0f, -25.0f);
        glVertex2f(41.0f, -25.0f);
        glColor3ub(18, 146, 173);
        glVertex2f(41.0f, 3.0f);
        glVertex2f(-41.0f, 3.0f);
        glEnd();
    }
}

void skybackground()
{
    glBegin(GL_POLYGON);
    set_color("skyCU");
    glVertex2f(-41.0, 0.0);
    glVertex2f(41.0, 0.0);
    set_color("skyCD");
    glVertex2f(41.0, 30);
    glVertex2f(-41.0, 30.0);
    glEnd();
}

void BridgeBox()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1, -5, 0);
    glColor3ub(142, 44, 33);
    glBegin(GL_QUADS);
    glVertex2f(4, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 5);
    glVertex2f(4, 5);
    glEnd();
    bridgeBrike(1, 1, 3, 0);
    bridgeBrike(1, 1, 3, 1.5);
    bridgeBrike(1, 1, 4, 1);
    bridgeBrike(1, 1, 4, 2);

    glBegin(GL_QUADS);
    glColor3ub(104, 104, 104);
    glVertex2f(4, 0);
    glColor3ub(47, 171, 196);
    glVertex2f(7, -4);
    glColor3ub(47, 171, 196);
    glVertex2f(9, -4);
    glColor3ub(104, 104, 104);
    glVertex2f(6, 0);
    glEnd();

    glColor3ub(66, 56, 54);
    glBegin(GL_QUADS);
    glVertex2f(3, 5);
    glVertex2f(7, 5);
    glVertex2f(7, 6);
    glVertex2f(3, 6);
    glEnd();
    glColor3ub(50, 40, 39);
    glBegin(GL_QUADS);
    glVertex2f(2, 6);
    glVertex2f(8, 6);
    glVertex2f(8, 7);
    glVertex2f(2, 7);
    glEnd();
    glPopMatrix();
}

void BridgeBoxNight()
{
    if (isDayScene == false)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(1, -5, 0);
        glColor3ub(142, 44, 33);
        glBegin(GL_QUADS);
        glVertex2f(4, 0);
        glVertex2f(6, 0);
        glVertex2f(6, 5);
        glVertex2f(4, 5);
        glEnd();
        bridgeBrike(1, 1, 3, 0);
        bridgeBrike(1, 1, 3, 1.5);
        bridgeBrike(1, 1, 4, 1);
        bridgeBrike(1, 1, 4, 2);

        glBegin(GL_QUADS);
        glColor3ub(104, 104, 104);
        glVertex2f(4, 0);
        glColor3ub(18, 146, 173);
        glVertex2f(7, -4);
        glColor3ub(18, 146, 173);
        glVertex2f(9, -4);
        glColor3ub(104, 104, 104);
        glVertex2f(6, 0);
        glEnd();

        glColor3ub(66, 56, 54);
        glBegin(GL_QUADS);
        glVertex2f(3, 5);
        glVertex2f(7, 5);
        glVertex2f(7, 6);
        glVertex2f(3, 6);
        glEnd();
        glColor3ub(50, 40, 39);
        glBegin(GL_QUADS);
        glVertex2f(2, 6);
        glVertex2f(8, 6);
        glVertex2f(8, 7);
        glVertex2f(2, 7);
        glEnd();
        glPopMatrix();
    }
}

void temp(int x)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, 0, 0);
    BridgeBox();
    BridgeBoxNight();
    glPopMatrix();
}

void bridge()
{
    temp(-40);
    temp(-20);
    temp(0);
    temp(20);
    temp(35);
}

void tempbuild()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1, 1.5, 0);
    drawBuildingL();
    glPopMatrix();
}

void twintower()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-7, 3, 0);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-2.50, 0.0f);
    glVertex2f(2.50, 0.0f);
    glVertex2f(2.50f, 10.0f);
    glVertex2f(-2.50f, 10.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1, 16);
    twintowerwindow(0.5, 0.5, -4, 16);
    twintowerwindow(0.5, 0.5, 1.75, 16);
    twintowerwindow(0.5, 0.5, -1, 14);
    twintowerwindow(0.5, 0.5, -4, 14);
    twintowerwindow(0.5, 0.5, 1.75, 14);
    twintowerwindow(0.5, 0.5, -1, 12);
    twintowerwindow(0.5, 0.5, -4, 12);
    twintowerwindow(0.5, 0.5, 1.75, 12);
    twintowerwindow(0.5, 0.5, -1, 10);
    twintowerwindow(0.5, 0.5, -4, 10);
    twintowerwindow(0.5, 0.5, 1.75, 10);
    twintowerwindow(0.5, 0.5, 1.75, 8);
    twintowerwindow(0.5, 0.5, -1, 8);
    twintowerwindow(0.5, 0.5, -4, 8);
    twintowerwindow(0.5, 0.5, 1.75, 6);
    twintowerwindow(0.5, 0.5, -1, 6);
    twintowerwindow(0.5, 0.5, -4, 6);
    twintowerwindow(0.5, 0.5, 1.75, 4);
    twintowerwindow(0.5, 0.5, -1, 4);
    twintowerwindow(0.5, 0.5, -4, 4);
    twintowerwindow(0.5, 0.5, 1.75, 2);
    twintowerwindow(0.5, 0.5, -1, 2);
    twintowerwindow(0.5, 0.5, -4, 2);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-2.00, 10.0f);
    glVertex2f(2.00, 10.0f);
    glVertex2f(2.00f, 16.0f);
    glVertex2f(-2.00f, 16.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1.50, 18);
    twintowerwindow(0.5, 0.5, -4, 18);
    twintowerwindow(0.5, 0.5, 1, 18);
    twintowerwindow(0.5, 0.5, -1.50, 20);
    twintowerwindow(0.5, 0.5, -4, 20);
    twintowerwindow(0.5, 0.5, 1, 20);
    twintowerwindow(0.5, 0.5, -1.50, 22);
    twintowerwindow(0.5, 0.5, -4, 22);
    twintowerwindow(0.5, 0.5, 1, 22);
    twintowerwindow(0.5, 0.5, -1.50, 24);
    twintowerwindow(0.5, 0.5, -4, 24);
    twintowerwindow(0.5, 0.5, 1, 24);
    twintowerwindow(0.5, 0.5, -1.50, 26);
    twintowerwindow(0.5, 0.5, -4, 26);
    twintowerwindow(0.5, 0.5, 1, 26);
    twintowerwindow(0.5, 0.5, -1.50, 28);
    twintowerwindow(0.5, 0.5, -4, 28);
    twintowerwindow(0.5, 0.5, 1, 28);
    twintowerwindow(0.5, 0.5, -1.50, 30);
    twintowerwindow(0.5, 0.5, -4, 30);
    twintowerwindow(0.5, 0.5, 1, 30);

    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-1.50, 16.0f);
    glVertex2f(1.50, 16.0f);
    glVertex2f(1.50f, 23.0f);
    glVertex2f(-1.50f, 23.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1.50, 32);
    twintowerwindow(0.5, 0.5, -4, 32);
    twintowerwindow(0.5, 0.5, -1.50, 34);
    twintowerwindow(0.5, 0.5, -4, 34);
    twintowerwindow(0.5, 0.5, -1.50, 36);
    twintowerwindow(0.5, 0.5, -4, 36);
    twintowerwindow(0.5, 0.5, -1.50, 38);
    twintowerwindow(0.5, 0.5, -4, 38);
    twintowerwindow(0.5, 0.5, -1.50, 40);
    twintowerwindow(0.5, 0.5, -4, 40);
    twintowerwindow(0.5, 0.5, -1.50, 42);
    twintowerwindow(0.5, 0.5, -4, 42);
    twintowerwindow(0.5, 0.5, -1.50, 44);
    twintowerwindow(0.5, 0.5, -4, 44);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-1.00, 23.0f);
    glVertex2f(1.00, 23.0f);
    glVertex2f(1.00f, 26.0f);
    glVertex2f(-1.00f, 26.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1.50, 46);
    twintowerwindow(0.5, 0.5, -1.50, 48);
    twintowerwindow(0.5, 0.5, -1.50, 50);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(2.50, 5.0f);
    glVertex2f(12.5f, 5.0f);
    glVertex2f(12.5f, 6.0f);
    glVertex2f(2.50, 6.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 16, 22);
    buildingwindow(0.3, 0.2, 16, 23);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(2.50, 6.0f);
    glVertex2f(12.5f, 6.0f);
    glVertex2f(12.5f, 8.0f);
    glVertex2f(2.50, 8.0f);
    glEnd();
    buildingwindow(0.3, 0.2, 16, 35);
    buildingwindow(0.3, 0.2, 16, 34);
    glPopMatrix();

    int x = 10;
    int y = 20;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-7, 3, 0);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-2.50 + x, 0.0f);
    glVertex2f(2.50 + x, 0.0f);
    glVertex2f(2.50f + x, 10.0f);
    glVertex2f(-2.50f + x, 10.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1.5 + y, 16);
    twintowerwindow(0.5, 0.5, -5 + y, 16);
    twintowerwindow(0.5, 0.5, 1.3 + y, 16);
    twintowerwindow(0.5, 0.5, -1.5 + y, 14);
    twintowerwindow(0.5, 0.5, -5 + y, 14);
    twintowerwindow(0.5, 0.5, 1.3 + y, 14);
    twintowerwindow(0.5, 0.5, -1.5 + y, 12);
    twintowerwindow(0.5, 0.5, -5 + y, 12);
    twintowerwindow(0.5, 0.5, 1.3 + y, 12);
    twintowerwindow(0.5, 0.5, -1.5 + y, 10);
    twintowerwindow(0.5, 0.5, -5 + y, 10);
    twintowerwindow(0.5, 0.5, 1.3 + y, 10);
    twintowerwindow(0.5, 0.5, 1.3 + y, 8);
    twintowerwindow(0.5, 0.5, -1.5 + y, 8);
    twintowerwindow(0.5, 0.5, -5 + y, 8);
    twintowerwindow(0.5, 0.5, 1.3 + y, 6);
    twintowerwindow(0.5, 0.5, -1.5 + y, 6);
    twintowerwindow(0.5, 0.5, -5 + y, 6);
    twintowerwindow(0.5, 0.5, 1.3 + y, 4);
    twintowerwindow(0.5, 0.5, -1.5 + y, 4);
    twintowerwindow(0.5, 0.5, -5 + y, 4);
    twintowerwindow(0.5, 0.5, 1.3 + y, 2);
    twintowerwindow(0.5, 0.5, -1.5 + y, 2);
    twintowerwindow(0.5, 0.5, -5 + y, 2);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-2.00 + x, 10.0f);
    glVertex2f(2.00 + x, 10.0f);
    glVertex2f(2.00f + x, 16.0f);
    glVertex2f(-2.00f + x, 16.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1.50 + y, 18);
    twintowerwindow(0.5, 0.5, -4 + y, 18);
    twintowerwindow(0.5, 0.5, 1 + y, 18);
    twintowerwindow(0.5, 0.5, -1.50 + y, 20);
    twintowerwindow(0.5, 0.5, -4 + y, 20);
    twintowerwindow(0.5, 0.5, 1 + y, 20);
    twintowerwindow(0.5, 0.5, -1.50 + y, 22);
    twintowerwindow(0.5, 0.5, -4 + y, 22);
    twintowerwindow(0.5, 0.5, 1 + y, 22);
    twintowerwindow(0.5, 0.5, -1.50 + y, 24);
    twintowerwindow(0.5, 0.5, -4 + y, 24);
    twintowerwindow(0.5, 0.5, 1 + y, 24);
    twintowerwindow(0.5, 0.5, -1.50 + y, 26);
    twintowerwindow(0.5, 0.5, -4 + y, 26);
    twintowerwindow(0.5, 0.5, 1 + y, 26);
    twintowerwindow(0.5, 0.5, -1.50 + y, 28);
    twintowerwindow(0.5, 0.5, -4 + y, 28);
    twintowerwindow(0.5, 0.5, 1 + y, 28);
    twintowerwindow(0.5, 0.5, -1.50 + y, 30);
    twintowerwindow(0.5, 0.5, -4 + y, 30);
    twintowerwindow(0.5, 0.5, 1 + y, 30);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-1.50 + x, 16.0f);
    glVertex2f(1.50 + x, 16.0f);
    glVertex2f(1.50f + x, 23.0f);
    glVertex2f(-1.50f + x, 23.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1.50 + y, 32);
    twintowerwindow(0.5, 0.5, -4 + y, 32);
    twintowerwindow(0.5, 0.5, -1.50 + y, 34);
    twintowerwindow(0.5, 0.5, -4 + y, 34);
    twintowerwindow(0.5, 0.5, -1.50 + y, 36);
    twintowerwindow(0.5, 0.5, -4 + y, 36);
    twintowerwindow(0.5, 0.5, -1.50 + y, 38);
    twintowerwindow(0.5, 0.5, -4 + y, 38);
    twintowerwindow(0.5, 0.5, -1.50 + y, 40);
    twintowerwindow(0.5, 0.5, -4 + y, 40);
    twintowerwindow(0.5, 0.5, -1.50 + y, 42);
    twintowerwindow(0.5, 0.5, -4 + y, 42);
    twintowerwindow(0.5, 0.5, -1.50 + y, 44);
    twintowerwindow(0.5, 0.5, -4 + y, 44);
    glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
    glVertex2f(-1.00 + x, 23.0f);
    glVertex2f(1.00 + x, 23.0f);
    glVertex2f(1.00f + x, 26.0f);
    glVertex2f(-1.00f + x, 26.0f);
    glEnd();
    twintowerwindow(0.5, 0.5, -1.50 + y, 46);
    twintowerwindow(0.5, 0.5, -1.50 + y, 48);
    twintowerwindow(0.5, 0.5, -1.50 + y, 50);
    glPopMatrix();
}

void trainLine()
{
    glBegin(GL_POLYGON);
    glColor3ub(82, 71, 67); // Yellow
    glVertex2f(-41.0f, 0.0f);
    glVertex2f(41.0f, 0.0f);
    glVertex2f(41.0f, -1.00f);
    glVertex2f(-41.0f, -1.0f);
    glEnd();
}

void tempTrainLine()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0, 3, 0);
    trainLine();
    glPopMatrix();
}

void BridgeRaling()
{
    glBegin(GL_POLYGON);
    glColor3ub(2, 42, 50); // Yellow
    glVertex2f(-4.0f, 7.0f);
    glVertex2f(-7.0f, 7.0f);
    glVertex2f(-7.0f, 8.0f);
    glVertex2f(-4.0f, 8.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(2, 42, 50); // Yellow
    glVertex2f(-5.0f, 0.0f);
    glVertex2f(-5.0f, 7.0f);
    glVertex2f(-6.0f, 7.0f);
    glVertex2f(-6.0f, 0.0f);
    glEnd();

    int x = 4;
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(127, 18, 18);
    glVertex2f(-5.0f, 7.0f);
    glVertex2f(0.0f + x, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(127, 18, 18);
    glVertex2f(-5.0f, 5.0f);
    glVertex2f(-1.0f + x, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-5.0f, 4.0f);
    glVertex2f(-1.50f + x, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-5.0f, 2.0f);
    glVertex2f(-2.0f + x, 0.0f);
    glEnd();
    int y = -4;
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 7.0f);
    glVertex2f(-10.0f + y, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 5.0f);
    glVertex2f(-9.50f + y, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 4.0f);
    glVertex2f(-9.0f + y, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 2.0f);
    glVertex2f(-8.0f + y, 0.0f);
    glEnd();
}

void tempRail(int x)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, 2, 0);
    BridgeRaling();
    glPopMatrix();
}

void tempRailing()
{
    tempRail(40);
    tempRail(20);
    tempRail(0);
    tempRail(-20);
    tempRail(-40);
}

void drawTrainrail()
{
    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 52); // Yellow
    glVertex2f(-41.0f, 2.0f);
    glVertex2f(41.0f, 2.0f);
    glVertex2f(41.0f, 4.50f);
    glVertex2f(-41.0f, 4.50f);
    glEnd();
}

void traindoor()
{
    glBegin(GL_POLYGON);
    set_color("traindoor");
    glVertex2f(3.0f, 4.0f);
    glVertex2f(5.0f, 4.0f);
    glVertex2f(5.0f, 6.0f);
    glVertex2f(3.0f, 6.0f);
    glEnd();
}

void adjustdoor()
{
    // middle door
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 1.4, 1);
    glTranslatef(11.50, -2, 0);
    traindoor();
    glPopMatrix();

    // front door
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 1.4, 1);
    glTranslatef(25.50, -2, 0);
    traindoor();
    glPopMatrix();

    // back door
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 1.4, 1);
    glTranslatef(-3.50, -2, 0);
    traindoor();
    glPopMatrix();
}

void windowstrain()
{
    glBegin(GL_POLYGON);
    set_color("trainwindow");
    glVertex2f(3.0f, 4.0f);
    glVertex2f(5.0f, 4.0f);
    glVertex2f(5.0f, 6.0f);
    glVertex2f(3.0f, 6.0f);
    glEnd();
}

void adjustwindow()
{
    // middle boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(2, 3, 0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(5, 3, 0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(8, 3, 0);
    windowstrain();
    glPopMatrix();

    // front boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(16.50, 3, 0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(19.50, 3, 0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(22.50, 3, 0);
    windowstrain();
    glPopMatrix();

    // back boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(-7, 3, 0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(-10, 3, 0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6, 0.6, 1);
    glTranslatef(-13, 3, 0);
    windowstrain();
    glPopMatrix();
}

void reflect_windowstrain()
{
    if (isDayScene == false)
    {
        glBegin(GL_POLYGON);
        set_color("nightTwindow");
        glVertex2f(3.0f, 4.0f);
        glVertex2f(5.0f, 4.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(3.0f, 6.0f);
        glEnd();
    }
}

void reflectwindow_night()
{
    if (isDayScene == false)
    {
        // middle boggy
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(2, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(5, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(8, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        // front boggy
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(16.50, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(19.50, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(22.50, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        // back boggy
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(-7, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(-10, -15, 0);
        reflect_windowstrain();
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(-13, -15, 0);
        reflect_windowstrain();
        glPopMatrix();
    }
}

void drawTrain()
{
    glBegin(GL_POLYGON);
    glColor3ub(227, 223, 209); // Yellow
    glVertex2f(2.0f, 0.75f + 2);
    glVertex2f(10.50f, 0.75f + 2);
    glVertex2f(11.0f, 4.0f + 2);
    glVertex2f(10.50f, 4.50f + 2);
    glVertex2f(2.50f, 4.50f + 2);
    glVertex2f(2.0f, 4.0f + 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(191, 171, 151); // Yellow
    glVertex2f(2.0f - 9, 0.75f + 2);
    glVertex2f(11.0f - 9, 0.75f + 2);
    glVertex2f(11.0f - 9, 4.0f + 2);
    glVertex2f(10.50f - 9, 4.50f + 2);
    glVertex2f(2.50f - 9, 4.50f + 2);
    glVertex2f(2.0f - 9, 4.0f + 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(214, 214, 222); // Yellow
    glVertex2f(10.50f, 0.75f + 2);
    glVertex2f(22.50f, 0.75f + 2);
    glVertex2f(21.0f, 3.50f + 2);
    glVertex2f(19.0f, 4.50f + 2);
    glVertex2f(11.50f, 4.50f + 2);
    glVertex2f(11.0f, 4.0f + 2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(199, 129, 104); // Yellow
    glVertex2f(-7.0f, 2.75f);
    glVertex2f(21.25f, 2.75f);
    glVertex2f(21.0f, 3.60f);
    glVertex2f(-7.0f, 3.60f);
    glEnd();

    // windows
    glBegin(GL_POLYGON);
    glColor3ub(46, 68, 86); // Yellow
    glVertex2f(19.0f, 4.0f);
    glVertex2f(20.25f, 4.0f);
    glVertex2f(20.25f, 5.0f);
    glVertex2f(20.0f, 5.50f);
    glVertex2f(19.0f, 6.0f);
    glEnd();

    adjustwindow();
    adjustdoor();
}

void railline2()
{
    glBegin(GL_POLYGON);
    glColor3ub(142, 141, 140); // Yellow
    glVertex2f(-41.0f, 2.0f);
    glVertex2f(41.0f, 2.0f);
    glVertex2f(41.0f, 2.75f);
    glVertex2f(-41.0f, 2.75f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(142, 141, 140); // Yellow
    glVertex2f(-41.0f, 2.0f + 2);
    glVertex2f(41.0f, 2.0f + 2);
    glVertex2f(41.0f, 2.75f + 2);
    glVertex2f(-41.0f, 2.75f + 2);
    glEnd();
}

void bridgerail()
{
    glBegin(GL_POLYGON);
    set_color("bridgerailc");
    glVertex2f(-6.0f, -5.0f);
    glVertex2f(-4.25f, -2.50f);
    glVertex2f(-5.0f, -2.0f);
    glVertex2f(-7.0f, -5.0f);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("bridgerailc");
    glVertex2f(-4.25f, -2.50f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-5.0f, -2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("bridgerailc");
    glVertex2f(0.0f, -1.0f);
    glVertex2f(4.25f, -2.50f);
    glVertex2f(5.0f, -2.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("bridgerailc");
    glVertex2f(4.25f, -2.50f);
    glVertex2f(6.0f, -5.0f);
    glVertex2f(7.0f, -5.0f);
    glVertex2f(5.0f, -2.0f);
    glEnd();
}

void adjustbridge()
{
    // middle
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499, 0.8, 1);
    glTranslatef(-2.7, 0, 0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499, 0.8, 1);
    glTranslatef(-16.0, 0, 0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499, 0.8, 1);
    glTranslatef(-29.3, 0, 0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499, 0.8, 1);
    glTranslatef(10.7, 0, 0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499, 0.8, 1);
    glTranslatef(23.9, 0, 0);
    bridgerail();
    glPopMatrix();
}

void container6()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3, 3, 1);
    glTranslatef(4, -10.25, 0);
    containerModel_1();
    glPopMatrix();
}

void ship()
{
    container6();
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

void AdjustShip()
{
    glPushMatrix();
    glScalef(0.70, 0.90, 1);
    glTranslatef(Ship_position, -20, 0);
    ship();
    glPopMatrix();
}

void drawCircle(float radius, float cX, float cY)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(194, 214, 246);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 400;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + cX, y + cY);
    }
    glEnd();
}

void cloud()
{
    drawCircle(4, 20, 25);
    drawCircle(4, 15, 25);
    drawCircle(4, 11, 25);
    drawCircle(4, -20, 20);
    drawCircle(4, -15, 20);
    drawCircle(4, -11, 20);

    //
    drawCircle(4, 70, 30);
    drawCircle(4, 65, 30);
    drawCircle(4, 61, 30);
    drawCircle(4, 90, 22);
    drawCircle(4, 85, 22);
    drawCircle(4, 81, 22);

    //
    drawCircle(4, -60, 25);
    drawCircle(4, -55, 25);
    drawCircle(4, -51, 25);
    drawCircle(4, -80, 20);
    drawCircle(4, -75, 20);
    drawCircle(4, -71, 20);

    //
    drawCircle(4, -110, 30);
    drawCircle(4, -105, 30);
    drawCircle(4, -101, 30);
    drawCircle(4, -130, 27);
    drawCircle(4, -125, 27);
    drawCircle(4, -121, 27);
}

void adjust_cloud()
{
    glPushMatrix();
    glScalef(0.50, 0.60, 1);
    glTranslatef(-40, 12, 0);
    cloud();
    glPopMatrix();
}

void Full_cloud()
{
    adjust_cloud();
}

void Animation_cloud()
{
    glPushMatrix();
    glTranslatef(cloud_position, 0, 0);
    Full_cloud();
    glPopMatrix();
}

void Full_train()
{
    traindoor();
    adjustdoor();
    windowstrain();
    adjustwindow();
    reflectwindow_night();
    reflect_windowstrain();
    drawTrain();
}

void Animation_train()
{
    glPushMatrix();
    glTranslatef(train_position, 0, 0);
    Full_train();
    glPopMatrix();
}

void update(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);

    if (cloud_position >= +80)
        cloud_position = -70;
    cloud_position += cloud_speed;

    if (Dew_position >= +80)
        Dew_position = -90;
    Dew_position += Dew_speed;
}

void shipAnimation2(int value)
{

    if (ship_start2 == true)
    {
        Ship_position += Ship_speed;
        if (Ship_position > 74)
        {
            Ship_position = 74;
            ship_start3 = true;
            currentDisplay = 3;
        }
    }
    else
    {
        // ship2 not started, position unchanged
    }
    if (train_start2 == true && !trainMovedOnce)
    {
        train_position += train_speed;
        if (train_position > 50)
        {
            train_position = -70;
            train_start2 = false;
            trainMovedOnce = true;
            showRestartMessage = true;
        }
    }
    else
    {
        // train not moving, position unchanged
    }
    glutPostRedisplay();
    glutTimerFunc(20, shipAnimation2, 0);
}

void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    skybackground();
    drawWater();
    drawWaterNight();
    twintower();
    tempbuild();
    drawBuilding();
    adjust_stars();
    Animation_dew();
    adjustbridge();
    bridge();
    drawTrainrail();
    railline2();
    Animation_train();
    tempTrainLine();
    tempRailing();
    AdjustShip();
    Moon();
    Sun();
    Animation_cloud();
    drawBirds2();
    drawRain();
    glFlush();
    glutSwapBuffers();
}

//----------------------------------------------------------End of Scenario 2 ------------------------------------------------------------------


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
void playTrainSound()
{
    string cmd = "open \"" + getMusicPath("Train.wav") + "\" type waveaudio alias train";
    mciSendString("close train", NULL, 0, NULL);
    mciSendString(cmd.c_str(), NULL, 0, NULL);
    mciSendString("play train", NULL, 0, NULL);
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
    else if (currentDisplay == 2)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-41, 41, -25, 30);
        display2();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutSwapBuffers();

        if (!trainSoundPlayed)
        {
            playTrainSound();
            trainSoundPlayed = true;
        }
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
