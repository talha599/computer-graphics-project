#include <windows.h>
#include <GL/glut.h>
#include <math.h>
float _car1PosXt = 0.0f;
float _car2PosXt = 0.0f;
float _car3PosXt = 0.0f;
float _car1Speedt = 0.01f;
float _car2Speedt = 0.02f;
float _car3Speedt = 0.023f;
float _cloud2PosXt = -1.5f;
float _cloudSpeedt = 0.004f;
float trainPosXt = -1.0f;   // starting X position
float trainSpeed = 0.01f;   // speed of train
float baloonPosYt = -0.0f;


bool carMovingt = false;

void circle(float radius, float xc, float yc, float r, float g, float b){
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}
void skyt (){
// sky
    glBegin(GL_QUADS);
	glColor3f(0.679f, 0.958f, 1.000f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.2f);
	glVertex2f(-1.0f, 0.2f);
	glEnd();
}
void cloud1t(){
// Cloud 1 (Right) overlaps Cloud 2 (Center)
circle(0.07, -0.65, 0.80, 1.0f, 1.0f, 1.0f);
circle(0.06, -0.60, 0.82, 1.0f, 1.0f, 1.0f);
circle(0.08, -0.55, 0.78, 1.0f, 1.0f, 1.0f);
circle(0.06, -0.50, 0.80, 1.0f, 1.0f, 1.0f);
circle(0.05, -0.58, 0.76, 1.0f, 1.0f, 1.0f);
circle(0.05, -0.62, 0.76, 1.0f, 1.0f, 1.0f);
}
void sunt (){
circle(0.1, -0.07, 0.77, 1,1,0);
}
void cloud2t(){
        glPushMatrix();
    glTranslatef(_cloud2PosXt, 0.0f, 0.0f);
// Cloud 2 (Center) overlaps Cloud 3 (Left)
circle(0.08, -0.02, 0.83, 1.0f, 1.0f, 1.0f);
circle(0.07, 0.05, 0.81, 1.0f, 1.0f, 1.0f);
circle(0.09, 0.09, 0.81, 1.0f, 1.0f, 1.0f);
circle(0.06, 0.16, 0.80, 1.0f, 1.0f, 1.0f);
circle(0.06, 0.22, 0.80, 1.0f, 1.0f, 1.0f);
circle(0.05, 0.12, 0.78, 1.0f, 1.0f, 1.0f);
 glPopMatrix();
}
void updateCloud2t(int value) {
    _cloud2PosXt += _cloudSpeedt; // move cloud right

    if (_cloud2PosXt > 1.5f) { // reset to left after going off-screen
        _cloud2PosXt = -1.5f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateCloud2t, 0); // ~60 FPS
}
void cloud3t(){
// Cloud 3 (Left) overlaps Cloud 2 (Center)
circle(0.07, 0.55, 0.82, 1.0f, 1.0f, 1.0f);
circle(0.06, 0.62, 0.80, 1.0f, 1.0f, 1.0f);
circle(0.08, 0.68, 0.80, 1.0f, 1.0f, 1.0f);
circle(0.06, 0.74, 0.82, 1.0f, 1.0f, 1.0f);
circle(0.05, 0.70, 0.78, 1.0f, 1.0f, 1.0f);
circle(0.05, 0.68, 0.76, 1.0f, 1.0f, 1.0f);
}
void bridget(){
	//bridge
	    glBegin(GL_QUADS);
	glColor3f(0.471f, 0.502f, 0.478f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(1.0f, 0.03f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f,  0.0f);
	glEnd();


//piller
    glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.82f, -0.05f);
    glVertex2f(-0.78f, -0.05f);
    glVertex2f(-0.78f, -0.16f);
	glVertex2f(-0.82f, -0.16f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.78f, -0.16f);
    glVertex2f(-0.82f, -0.16f);
    glVertex2f(-0.83f, -0.17f);
	glVertex2f(-0.77f, -0.17f);
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.47f, -0.05f);
    glVertex2f(-0.43f, -0.05f);
    glVertex2f(-0.43f, -0.16f);
    glVertex2f(-0.47f, -0.16f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.43f, -0.16f);
    glVertex2f(-0.47f, -0.16f);
    glVertex2f(-0.48f, -0.17f);
    glVertex2f(-0.42f, -0.17f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.12f, -0.05f);
    glVertex2f(-0.08f, -0.05f);
    glVertex2f(-0.08f, -0.16f);
	glVertex2f(-0.12f, -0.16f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.08f, -0.16f);
    glVertex2f(-0.12f, -0.16f);
    glVertex2f(-0.13f, -0.17f);
	glVertex2f(-0.07f, -0.17f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.23f, -0.05f);
    glVertex2f(0.27f, -0.05f);
    glVertex2f(0.27f, -0.16f);
    glVertex2f(0.23f, -0.16f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.27f, -0.16f);
    glVertex2f(0.23f, -0.16f);
    glVertex2f(0.22f, -0.17f);
    glVertex2f(0.28f, -0.17f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.58f, -0.05f);
    glVertex2f(0.62f, -0.05f);
    glVertex2f(0.62f, -0.16f);
	glVertex2f(0.58f, -0.16f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.62f, -0.16f);
    glVertex2f(0.58f, -0.16f);
    glVertex2f(0.57f, -0.17f);
	glVertex2f(0.63f, -0.17f);
	glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.93f, -0.05f);
    glVertex2f(0.97f, -0.05f);
    glVertex2f(0.97f, -0.16f);
    glVertex2f(0.93f, -0.16f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.97f, -0.16f);
    glVertex2f(0.93f, -0.16f);
    glVertex2f(0.92f, -0.17f);
    glVertex2f(0.98f, -0.17f);
    glEnd();


    //main bridge frame
        glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
	glVertex2f(-1.0f, 0.35f);
	glVertex2f(-1.0f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(1.0f, 0.35f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-1.0f, -0.0f);
    glVertex2f(-1.0f, -0.05f);
    glVertex2f(1.0f, -0.05f);
	glVertex2f(1.0f, -0.0f);
	glEnd();
}
void innergrilt (){


	//inner bridge`
    glLineWidth(10);
    glBegin(GL_LINES);
	glColor3f(0.7f, 0.75f, 0.71f);
	glVertex2f(-1.0f, -0.0f);
    glVertex2f(-0.7f, 0.35f);
    glVertex2f(-0.9f, 0.0f);
    glVertex2f(-0.60f, 0.35f);

	glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(-0.6f, 0.35f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.5f, 0.35f);

	glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(-0.1f, 0.0f);

	glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.3f, 0.35f);
    glVertex2f(0.6f, 0.0f);

	glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.9f, 0.35f);
    glVertex2f(1.0f, 0.35f);
    glVertex2f(0.7f, 0.0f);
	glEnd();

	glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.9f, 0.35f);
    glVertex2f(1.0f, 0.35f);
    glVertex2f(0.7f, 0.0f);
	glEnd();


	//inner gril
    glLineWidth(5);
    glBegin(GL_LINES);
	glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(-0.9f, 0.0f);
    glVertex2f(-0.899318190096f, 0.1167462111554f);
    glVertex2f(-0.899318190096f, 0.1167462111554f);
    glVertex2f(-0.79926813244f, 0.1167526177881f);
    glVertex2f(-0.79926813244f, 0.1167526177881f);
    glVertex2f(-0.8001724173802f, 0.2331321797231f);
    glVertex2f(-0.8001724173802f, 0.2331321797231f);
    glVertex2f(-0.7003797310516f, 0.2328903137732f);
    glVertex2f(-0.7003797310516f, 0.2328903137732f);
    glVertex2f(-0.7f, 0.35f);

	glVertex2f(-0.5f, 0.35f);
    glVertex2f(-0.5003116165801f, 0.2334863632595f);
    glVertex2f(-0.5003116165801f, 0.2334863632595f);
    glVertex2f(-0.399811552519f, 0.2331134779388f);
    glVertex2f(-0.399811552519f, 0.2331134779388f);
    glVertex2f(-0.3997421859975f, 0.1163658836638f);
    glVertex2f(-0.3997421859975f, 0.1163658836638f);
    glVertex2f(-0.299070137148f, 0.1155820369061f);
    glVertex2f(-0.299070137148f, 0.1155820369061f);
    glVertex2f(-0.3f, 0.0f);

    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.0998456364494f, 0.1168467574757f);
    glVertex2f(-0.0998456364494f, 0.1168467574757f);
    glVertex2f(-0.0001854447774f, 0.11614818144264f);
    glVertex2f(-0.0001854447774f, 0.11614818144264f);
    glVertex2f(-0.0000478448835f, 0.2332775143026f);
    glVertex2f(-0.0000478448835f, 0.2332775143026f);
    glVertex2f(0.0999862474037f, 0.2333172854876f);
    glVertex2f(0.0999862474037f, 0.2333172854876f);
    glVertex2f(0.1f, 0.35f);

    glVertex2f(0.3f, 0.35f);
    glVertex2f(0.3000100650404f, 0.2333215960362f);
    glVertex2f(0.3000100650404f, 0.2333215960362f);
    glVertex2f(0.4004150856341f, 0.2333117863301f);
    glVertex2f(0.4004150856341f, 0.2333117863301f);
    glVertex2f(0.399415046171f, 0.1173491146134f);
    glVertex2f(0.399415046171f, 0.1173491146134f);
    glVertex2f(0.499860489473f, 0.1168294289482f);
    glVertex2f(0.499860489473f, 0.1168294289482f);
    glVertex2f(0.5f, 0.0f);

    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.7003341862299f, 0.1170655606016f);
    glVertex2f(0.7003341862299f, 0.1170655606016f);
    glVertex2f(0.8001768215301f, 0.1168729854517f);
    glVertex2f(0.8001768215301f, 0.1168729854517f);
    glVertex2f(0.800166746021f, 0.2332572803579f);
    glVertex2f(0.800166746021f, 0.2332572803579f);
    glVertex2f(0.900209944064f, 0.2335782680747f);
    glVertex2f(0.900209944064f, 0.2335782680747f);
    glVertex2f(0.9f, 0.35f);
    glEnd();
}
void lamppost1t(){
// lamppost 1
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(-0.94f, 0.4f);
    glVertex2f(-0.93f, 0.4f);
    glVertex2f(-0.93f, 0.42f);
    glVertex2f(-0.94f, 0.42f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.939f, 0.42f);
    glVertex2f(-0.931f, 0.42f);
    glVertex2f(-0.931f, 0.53f);
    glVertex2f(-0.939f, 0.53f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.939f, 0.53f);
    glVertex2f(-0.8889308563922f, 0.5406335216017f);
    glVertex2f(-0.8888170823541f, 0.5335942552175f);
    glVertex2f(-0.939f, 0.5230563028512f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.8888170823541f, 0.5335942552175f);
    glVertex2f(-0.8920734805918755f, 0.5260943275658215f);
    glVertex2f(-0.9030233554466816f, 0.5239624935233086f);
    glVertex2f(-0.9096961481997f, 0.5292098429183f);
    glEnd();
   }
void lamppost2t(){
// lamppost 2
glBegin(GL_QUADS);
    glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(-0.54f, 0.4f);
    glVertex2f(-0.53f, 0.4f);
    glVertex2f(-0.53f, 0.42f);
    glVertex2f(-0.54f, 0.42f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.539f, 0.42f);
    glVertex2f(-0.531f, 0.42f);
    glVertex2f(-0.531f, 0.53f);
    glVertex2f(-0.539f, 0.53f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.539f, 0.53f);
    glVertex2f(-0.4889308563922f, 0.5406335216017f);
    glVertex2f(-0.4888170823541f, 0.5335942552175f);
    glVertex2f(-0.539f, 0.5230563028512f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.4888170823541f, 0.5335942552175f);
    glVertex2f(-0.4920734805918755f, 0.5260943275658215f);
    glVertex2f(-0.5030233554466816f, 0.5239624935233086f);
    glVertex2f(-0.5096961481997f, 0.5292098429183f);
glEnd();
}
void lamppost3t(){
// lamppost 3
glBegin(GL_QUADS);
    glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(-0.14f, 0.4f);
    glVertex2f(-0.13f, 0.4f);
    glVertex2f(-0.13f, 0.42f);
    glVertex2f(-0.14f, 0.42f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.139f, 0.42f);
    glVertex2f(-0.131f, 0.42f);
    glVertex2f(-0.131f, 0.53f);
    glVertex2f(-0.139f, 0.53f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(-0.139f, 0.53f);
    glVertex2f(-0.0889308563922f, 0.5406335216017f);
    glVertex2f(-0.0888170823541f, 0.5335942552175f);
    glVertex2f(-0.139f, 0.5230563028512f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.0888170823541f, 0.5335942552175f);
    glVertex2f(-0.0920734805918755f, 0.5260943275658215f);
    glVertex2f(-0.1030233554466816f, 0.5239624935233086f);
    glVertex2f(-0.1096961481997f, 0.5292098429183f);
glEnd();
}
void lamppost4t(){
// lamppost 4
glBegin(GL_QUADS);
    glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(0.26f, 0.4f);
    glVertex2f(0.27f, 0.4f);
    glVertex2f(0.27f, 0.42f);
    glVertex2f(0.26f, 0.42f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.261f, 0.42f);
    glVertex2f(0.269f, 0.42f);
    glVertex2f(0.269f, 0.53f);
    glVertex2f(0.261f, 0.53f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.261f, 0.53f);
    glVertex2f(0.3110691436078f, 0.5406335216017f);
    glVertex2f(0.3111829176459f, 0.5335942552175f);
    glVertex2f(0.261f, 0.5230563028512f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.3111829176459f, 0.5335942552175f);
    glVertex2f(0.3079265194081245f, 0.5260943275658215f);
    glVertex2f(0.2969766445533184f, 0.5239624935233086f);
    glVertex2f(0.2903038518003f, 0.5292098429183f);
glEnd();
}
void lamppost5t(){
// lamppost 5
glBegin(GL_QUADS);
    glColor3f(0.7f, 0.75f, 0.71f);
    glVertex2f(0.66f, 0.4f);
    glVertex2f(0.67f, 0.4f);
    glVertex2f(0.67f, 0.42f);
    glVertex2f(0.66f, 0.42f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.661f, 0.42f);
    glVertex2f(0.669f, 0.42f);
    glVertex2f(0.669f, 0.53f);
    glVertex2f(0.661f, 0.53f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0.314f, 0.314f, 0.314f);
    glVertex2f(0.661f, 0.53f);
    glVertex2f(0.7110691436078f, 0.5406335216017f);
    glVertex2f(0.7111829176459f, 0.5335942552175f);
    glVertex2f(0.661f, 0.5230563028512f);
glEnd();
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.7111829176459f, 0.5335942552175f);
    glVertex2f(0.7079265194081245f, 0.5260943275658215f);
    glVertex2f(0.6969766445533184f, 0.5239624935233086f);
    glVertex2f(0.6903038518003f, 0.5292098429183f);
glEnd();
}
void tree1t (){
//tree


 circle(0.14, 0.88, -0.44, 0.000f, 0.392f, 0.000f);
 circle(0.12, 0.88, -0.32, 0.000, 0.502, 0.000);
 circle(0.10, 0.88, -0.24, 0.133, 0.545, 0.133);
 circle(0.08, 0.88, -0.18, 0.000, 0.600, 0.000);
 circle(0.06, 0.88, -0.12, 0.000, 0.800, 0.000);
 circle(0.04, 0.88, -0.06, 0.400, 0.804, 0.400);


    glBegin(GL_POLYGON);
    glColor3f(0.56f, 0.40f, 0.08f);
    glVertex2f(0.86f, -0.9f);
	glVertex2f(0.9f, -0.9f);
    glVertex2f(0.9f, -0.5f);
	glVertex2f(0.86f, -0.5f);
	glEnd();
}
void tree2t (){
//tree shop
 circle(0.06, -0.95, -0.76, 0.000, 0.502, 0.000);
 circle(0.05, -0.95, -0.7, 0.133, 0.545, 0.133);
 circle(0.04, -0.95, -0.65, 0.000, 0.600, 0.000);
 circle(0.03, -0.95, -0.61, 0.000, 0.800, 0.000);
 circle(0.02, -0.95, -0.58, 0.400, 0.804, 0.400);
 circle(0.01, -0.95, -0.56, 0.400, 0.804, 0.400);
    glBegin(GL_POLYGON);
    glColor3f(0.56f, 0.40f, 0.08f);
    glVertex2f(-0.945f, -0.8f);
	glVertex2f(-0.955f, -0.8f);
    glVertex2f(-0.955f, -0.9f);
	glVertex2f(-0.945f, -0.9f);
	glEnd();
}
void tree3t (){
	//tree shop
 circle(0.06, -0.45, -0.76, 0.000, 0.502, 0.000);
 circle(0.05, -0.45, -0.7, 0.133, 0.545, 0.133);
 circle(0.04, -0.45, -0.65, 0.000, 0.600, 0.000);
 circle(0.03, -0.45, -0.61, 0.000, 0.800, 0.000);
 circle(0.02, -0.45, -0.58, 0.400, 0.804, 0.400);
 circle(0.01, -0.45, -0.56, 0.400, 0.804, 0.400);
    glBegin(GL_POLYGON);
    glColor3f(0.56f, 0.40f, 0.08f);
    glVertex2f(-0.455f, -0.9f);
	glVertex2f(-0.445f, -0.9f);
    glVertex2f(-0.445f, -0.8f);
	glVertex2f(-0.455f, -0.8f);
	glEnd();
}
void tree4t (){
//tree shop

// Leaves (circles shifted)
circle(0.06, -0.15, -0.56, 0.000, 0.502, 0.000);
circle(0.05, -0.15, -0.5, 0.133, 0.545, 0.133);
circle(0.04, -0.15, -0.45, 0.000, 0.600, 0.000);
circle(0.03, -0.15, -0.41, 0.000, 0.800, 0.000);
circle(0.02, -0.15, -0.38, 0.400, 0.804, 0.400);
circle(0.01, -0.15, -0.36, 0.400, 0.804, 0.400);

// Trunk (polygon shifted)
glBegin(GL_POLYGON);
glColor3f(0.56, 0.40, 0.08);
glVertex2f(-0.155, -0.7);
glVertex2f(-0.145, -0.7);
glVertex2f(-0.145, -0.6);
glVertex2f(-0.155, -0.6);
glEnd();
}
void tree5t (){
// Leaves (X + 0.15)
circle(0.06, 0.00, -0.56, 0.000, 0.502, 0.000);
circle(0.05, 0.00, -0.50, 0.133, 0.545, 0.133);
circle(0.04, 0.00, -0.45, 0.000, 0.600, 0.000);
circle(0.03, 0.00, -0.41, 0.000, 0.800, 0.000);
circle(0.02, 0.00, -0.38, 0.400, 0.804, 0.400);
circle(0.01, 0.00, -0.36, 0.400, 0.804, 0.400);

// Trunk (X + 0.15)
glBegin(GL_POLYGON);
glColor3f(0.56, 0.40, 0.08);
glVertex2f(-0.005, -0.7);
glVertex2f(0.005,  -0.7);
glVertex2f(0.005,  -0.6);
glVertex2f(-0.005, -0.6);
glEnd();
}
void tree6t (){
// Moved circles 0.15 units on X-axis
circle(0.06, 0.15, -0.56, 0.000, 0.502, 0.000);
circle(0.05, 0.15, -0.50, 0.133, 0.545, 0.133);
circle(0.04, 0.15, -0.45, 0.000, 0.600, 0.000);
circle(0.03, 0.15, -0.41, 0.000, 0.800, 0.000);
circle(0.02, 0.15, -0.38, 0.400, 0.804, 0.400);
circle(0.01, 0.15, -0.36, 0.400, 0.804, 0.400);

// Moved trunk rectangle 0.15 units on X-axis
glBegin(GL_POLYGON);
glColor3f(0.56, 0.40, 0.08);
glVertex2f(-0.005 + 0.15, -0.7);
glVertex2f(0.005 + 0.15,  -0.7);
glVertex2f(0.005 + 0.15,  -0.6);
glVertex2f(-0.005 + 0.15, -0.6);
glEnd();
}
void tree7t (){
// Moved circles another 0.15 units on X-axis
circle(0.06, 0.30, -0.56, 0.000, 0.502, 0.000);
circle(0.05, 0.30, -0.50, 0.133, 0.545, 0.133);
circle(0.04, 0.30, -0.45, 0.000, 0.600, 0.000);
circle(0.03, 0.30, -0.41, 0.000, 0.800, 0.000);
circle(0.02, 0.30, -0.38, 0.400, 0.804, 0.400);
circle(0.01, 0.30, -0.36, 0.400, 0.804, 0.400);

// Moved trunk rectangle another 0.15 units on X-axis
glBegin(GL_POLYGON);
glColor3f(0.56, 0.40, 0.08);
glVertex2f(-0.005 + 0.30, -0.7);
glVertex2f(0.005 + 0.30,  -0.7);
glVertex2f(0.005 + 0.30,  -0.6);
glVertex2f(-0.005 + 0.30, -0.6);
glEnd();
}
void shopt(){
//shop
    glBegin(GL_QUADS);
	glColor3f(0.549f, 0.392f, 0.549f);
    glVertex2f(-0.92f, -0.5f);
    glVertex2f(-0.48f, -0.5f);
    glVertex2f(-0.5f, -0.58f);
    glVertex2f(-0.9f, -0.58f);
    glEnd();
    glBegin(GL_QUADS);
	glColor3f(0.667f, 0.471f, 0.667f);
    glVertex2f(-0.5f, -0.58f);
    glVertex2f(-0.9f, -0.58f);
    glVertex2f(-0.9f, -0.9f);
    glVertex2f(-0.5f, -0.9f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.7f, 0.75f, 0.91f);
    glVertex2f(-0.89f, -0.6f);
    glVertex2f(-0.8f, -0.6f);
    glVertex2f(-0.8f, -0.88f);
    glVertex2f(-0.89f, -0.88f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.7f, 0.75f, 0.91f);
    glVertex2f(-0.77f, -0.6f);
    glVertex2f(-0.605f, -0.6f);
    glVertex2f(-0.605f, -0.88f);
    glVertex2f(-0.77f, -0.88f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3f(0.7f, 0.75f, 0.91f);
    glVertex2f(-0.58f, -0.6f);
    glVertex2f(-0.51f, -0.6f);
    glVertex2f(-0.51f, -0.88f);
    glVertex2f(-0.58f, -0.88f);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.89f, -0.64f);
    glVertex2f(-0.8f, -0.64f);
    glVertex2f(-0.77f, -0.64f);
    glVertex2f(-0.605f, -0.64f);
    glVertex2f(-0.58f, -0.64f);
    glVertex2f(-0.51f, -0.64f);
    glVertex2f(-0.69f, -0.64f);
    glVertex2f(-0.69f, -0.88f);
    glEnd();
circle(0.007, -0.675, -0.77, 0,0,0);
circle(0.007, -0.705, -0.77, 0,0,0);
}
void rivert(){
//river
    glBegin(GL_QUADS);
	glColor3f(0.529f, 0.808f, 0.922f);
	glVertex2f(-1.0f, 0.2f);
	glVertex2f(1.0f, 0.2f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(-1.0f, -0.6f);
	glEnd();
}
void groundt (){
//sand
    glBegin(GL_QUADS);
	glColor3f(0.761f, 0.698f, 0.502f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, -1.0f);
	glVertex2f(-1.0f, -1.0f);
	glEnd();
}
void backscenet (){
// back scene
    glBegin(GL_QUADS);
    glColor3f(0.467f, 0.533f, 0.600f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.95f, 0.3f);
    glVertex2f(-0.91f, 0.3f);
    glVertex2f(-0.91f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(-0.91f, 0.2f);
    glVertex2f(-0.91f, 0.28f);
    glVertex2f(-0.88f, 0.28f);
    glVertex2f(-0.88f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.600f, 0.600f, 0.600f);
    glVertex2f(-0.88f, 0.2f);
    glVertex2f(-0.88f, 0.32f);
    glVertex2f(-0.84f, 0.32f);
    glVertex2f(-0.84f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.663f, 0.663f);
    glVertex2f(-0.84f, 0.2f);
    glVertex2f(-0.84f, 0.28f);
    glVertex2f(-0.82f, 0.28f);
    glVertex2f(-0.82f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.690f, 0.769f, 0.871f);
    glVertex2f(-0.82f, 0.2f);
    glVertex2f(-0.82f, 0.26f);
    glVertex2f(-0.8f, 0.26f);
    glVertex2f(-0.8f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.420f, 0.557f, 0.740f);
    glVertex2f(-0.70f, 0.2f);
    glVertex2f(-0.70f, 0.3f);
    glVertex2f(-0.66f, 0.3f);
    glVertex2f(-0.66f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.561f, 0.737f, 0.561f);
    glVertex2f(-0.66f, 0.2f);
    glVertex2f(-0.66f, 0.28f);
    glVertex2f(-0.63f, 0.28f);
    glVertex2f(-0.63f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.600f, 0.702f);
    glVertex2f(-0.63f, 0.2f);
    glVertex2f(-0.63f, 0.32f);
    glVertex2f(-0.59f, 0.32f);
    glVertex2f(-0.59f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.561f, 0.737f, 0.561f);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.59f, 0.28f);
    glVertex2f(-0.57f, 0.28f);
    glVertex2f(-0.57f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.412f, 0.412f, 0.412f);
    glVertex2f(-0.57f, 0.2f);
    glVertex2f(-0.57f, 0.26f);
    glVertex2f(-0.55f, 0.26f);
    glVertex2f(-0.55f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.600f, 0.702f);
    glVertex2f(-0.55f, 0.2f);
    glVertex2f(-0.55f, 0.3f);
    glVertex2f(-0.53f, 0.3f);
    glVertex2f(-0.53f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.663f, 0.663f);
    glVertex2f(-0.42f, 0.2f);
    glVertex2f(-0.42f, 0.32f);
    glVertex2f(-0.40f, 0.32f);
    glVertex2f(-0.40f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.600f, 0.600f, 0.600f);
    glVertex2f(-0.40f, 0.2f);
    glVertex2f(-0.40f, 0.3f);
    glVertex2f(-0.36f, 0.3f);
    glVertex2f(-0.36f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.412f, 0.412f, 0.412f);
    glVertex2f(-0.36f, 0.2f);
    glVertex2f(-0.36f, 0.28f);
    glVertex2f(-0.33f, 0.28f);
    glVertex2f(-0.33f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.600f, 0.702f);
    glVertex2f(-0.33f, 0.2f);
    glVertex2f(-0.33f, 0.32f);
    glVertex2f(-0.29f, 0.32f);
    glVertex2f(-0.29f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.561f, 0.737f, 0.561f);
    glVertex2f(-0.29f, 0.2f);
    glVertex2f(-0.29f, 0.28f);
    glVertex2f(-0.27f, 0.28f);
    glVertex2f(-0.27f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.600f, 0.600f, 0.600f);
    glVertex2f(-0.27f, 0.2f);
    glVertex2f(-0.27f, 0.26f);
    glVertex2f(-0.25f, 0.26f);
    glVertex2f(-0.25f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.690f, 0.769f, 0.871f);
    glVertex2f(0.05f, 0.2f);
    glVertex2f(0.05f, 0.3f);
    glVertex2f(0.09f, 0.3f);
    glVertex2f(0.09f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.467f, 0.533f, 0.600f);
    glVertex2f(0.09f, 0.2f);
    glVertex2f(0.09f, 0.28f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.12f, 0.2f);
    glEnd();


    glBegin(GL_QUADS);
glColor3f(0.741f, 0.843f, 0.933f);
glVertex2f(0.12f, 0.2f);
glVertex2f(0.12f, 0.32f);
glVertex2f(0.16f, 0.32f);
glVertex2f(0.16f, 0.2f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.690f, 0.769f, 0.871f);
glVertex2f(0.16f, 0.2f);
glVertex2f(0.16f, 0.28f);
glVertex2f(0.18f, 0.28f);
glVertex2f(0.18f, 0.2f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.600f, 0.600f, 0.600f);
glVertex2f(0.18f, 0.2f);
glVertex2f(0.18f, 0.26f);
glVertex2f(0.20f, 0.26f);
glVertex2f(0.20f, 0.2f);
glEnd();



glBegin(GL_QUADS);
glColor3f(0.467f, 0.533f, 0.600f);
glVertex2f(0.28f, 0.2f);
glVertex2f(0.28f, 0.32f);
glVertex2f(0.30f, 0.32f);
glVertex2f(0.30f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.502f, 0.502f, 0.502f);
glVertex2f(0.30f, 0.2f);
glVertex2f(0.30f, 0.3f);
glVertex2f(0.34f, 0.3f);
glVertex2f(0.34f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.678f, 0.847f, 0.999f);
glVertex2f(0.34f, 0.2f);
glVertex2f(0.34f, 0.28f);
glVertex2f(0.37f, 0.28f);
glVertex2f(0.37f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.420f, 0.557f, 0.740f);
glVertex2f(0.37f, 0.2f);
glVertex2f(0.37f, 0.32f);
glVertex2f(0.41f, 0.32f);
glVertex2f(0.41f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.678f, 0.822f, 0.999f);
glVertex2f(0.41f, 0.2f);
glVertex2f(0.41f, 0.28f);
glVertex2f(0.43f, 0.28f);
glVertex2f(0.43f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.376f, 0.490f, 0.545f);
glVertex2f(0.43f, 0.2f);
glVertex2f(0.43f, 0.26f);
glVertex2f(0.45f, 0.26f);
glVertex2f(0.45f, 0.2f);
glEnd();




glBegin(GL_QUADS);
glColor3f (0.420f, 0.557f, 0.740f);
glVertex2f(0.74f, 0.2f);
glVertex2f(0.74f, 0.28f);
glVertex2f(0.77f, 0.28f);
glVertex2f(0.77f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.502f, 0.600f, 0.702f);
glVertex2f(0.77f, 0.2f);
glVertex2f(0.77f, 0.32f);
glVertex2f(0.81f, 0.32f);
glVertex2f(0.81f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.561f, 0.737f, 0.561f);
glVertex2f(0.81f, 0.2f);
glVertex2f(0.81f, 0.28f);
glVertex2f(0.83f, 0.28f);
glVertex2f(0.83f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.663f, 0.663f, 0.663f);
glVertex2f(0.83f, 0.2f);
glVertex2f(0.83f, 0.26f);
glVertex2f(0.85f, 0.26f);
glVertex2f(0.85f, 0.2f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.690f, 0.769f, 0.871f);
glVertex2f(0.85f, 0.2f);
glVertex2f(0.85f, 0.3f);
glVertex2f(0.87f, 0.3f);
glVertex2f(0.87f, 0.2f);
glEnd();

 circle(0.1, -0.922, 0.13, 0.0, 0.39, 0.0);
 circle(0.1, -0.811, 0.15, 0.0, 0.39, 0.0);
 circle(0.1, -0.722, 0.13, 0.0, 0.39, 0.0);
 circle(0.09, -0.611, 0.15, 0.0, 0.39, 0.0);
 circle(0.1, -0.522, 0.13, 0.0, 0.39, 0.0);
 circle(0.1, -0.411, 0.15, 0.0, 0.39, 0.0);
 circle(0.1, -0.322, 0.13, 0.0, 0.39, 0.0);
 circle(0.1, -0.211, 0.15, 0.0, 0.39, 0.0);
 circle(0.1, -0.123, 0.14, 0.0, 0.39, 0.0);
 circle(0.1, -0.011, 0.16, 0.0, 0.39, 0.0);
 circle(0.1, 0.014, 0.14, 0.0, 0.39, 0.0);
 circle(0.1, 0.115, 0.15, 0.0, 0.39, 0.0);
 circle(0.1, 0.213, 0.15, 0.0, 0.39, 0.0);
 circle(0.09, 0.314, 0.14, 0.0, 0.39, 0.0);
 circle(0.1, 0.416, 0.15, 0.0, 0.39, 0.0);
 circle(0.1, 0.511, 0.15, 0.0, 0.39, 0.0);
 circle(0.09, 0.613, 0.14, 0.0, 0.39, 0.0);
 circle(0.1, 0.717, 0.15, 0.0, 0.39, 0.0);
 circle(0.09, 0.811, 0.15, 0.0, 0.39, 0.0);
 circle(0.1, 0.913, 0.15, 0.0, 0.39, 0.0);
}
void car1t () {
//car

 glPushMatrix();
    glTranslatef(_car1PosXt, 0.0f, 0.0f);
glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(0.4f, -0.68f + 1.04f);
glVertex2f(0.4f, -0.62f + 1.04f);
glVertex2f(0.52f, -0.62f + 1.04f);
glVertex2f(0.52f, -0.68f + 1.04f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(0.42f, -0.62f + 1.04f);
glVertex2f(0.52f, -0.62f + 1.04f);
glVertex2f(0.505f, -0.59f + 1.04f);
glVertex2f(0.44f, -0.59f + 1.04f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.4f, -0.62f + 1.04f);
glVertex2f(0.52f, -0.62f + 1.04f);
glEnd();

  glPopMatrix();
}
void car2t (){
glPushMatrix();
glTranslatef(_car2PosXt, 0.0f, 0.0f);
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex2f(-0.3f, 0.43f);
glVertex2f(-0.18f, 0.43f);
glVertex2f(-0.18f, 0.37f);
glVertex2f(-0.3f, 0.37f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex2f(-0.2f, 0.43f);
glVertex2f(-0.22f, 0.46f);
glVertex2f(-0.285f, 0.46f);
glVertex2f(-0.3f, 0.43f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.3f, 0.43f);
glVertex2f(-0.2f, 0.43f);
glEnd();
   glPopMatrix();
}
void car3t () {
//car
 glPushMatrix();
    glTranslatef(_car3PosXt, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f(0.7f, 0.36f);
glVertex2f(0.7f, 0.42f);
glVertex2f(0.82f, 0.42f);
glVertex2f(0.82f, 0.36f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f(0.72f, 0.42f);
glVertex2f(0.82f, 0.42f);
glVertex2f(0.805f, 0.45f);
glVertex2f(0.74f, 0.45f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.7f, 0.42f);
glVertex2f(0.82f, 0.42f);
glEnd();

  glPopMatrix();
}
void updatet(int value) {
    if (carMovingt) { // Only move when flag is true
        // Move car1 left
        _car1PosXt -= _car1Speedt;
        if (_car1PosXt < -1.5f) _car1PosXt = 1.2f;
        _car3PosXt -= _car3Speedt;
        if (_car3PosXt < -1.9f) _car3PosXt = 1.2f;
        // Move car2 right
        _car2PosXt += _car2Speedt;
        if (_car2PosXt > 1.5f) _car2PosXt = -1.5f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatet, 0); // ~60 FPS
}
  // Keyboard handler
void handleKeypresst(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') {
        carMovingt = !carMovingt; // Toggle car movement
    }


}
void traint (){
    //train
    glPushMatrix();
    glTranslatef(trainPosXt, 0.0f, 0.0f);
glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.95, 0);
    glVertex2f(-0.95, 0.15);
    glVertex2f(-0.75, 0.15);
    glVertex2f(-0.75f, 0.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.72, 0.0);
    glVertex2f(-0.72, 0.15);
    glVertex2f(-0.52, 0.15);
    glVertex2f(-0.52f, 0.0f);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.49, 0.0);
    glVertex2f(-0.49, 0.15);
    glVertex2f(-0.29, 0.15);
    glVertex2f(-0.29f, 0.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.49, 0.15);
    glVertex2f(-0.4, 0.15);
    glVertex2f(-0.4, 0.27);
    glVertex2f(-0.49, 0.27);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.36, 0.15);
    glVertex2f(-0.36, 0.18);
    glVertex2f(-0.33, 0.18);
    glVertex2f(-0.33, 0.15);
glEnd();

//window

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.9, 0.12);
    glVertex2f(-0.94, 0.12);
    glVertex2f(-0.94, 0.08);
    glVertex2f(-0.9, 0.08);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.9, 0.12);
    glVertex2f(-0.94, 0.12);
    glVertex2f(-0.94, 0.08);
    glVertex2f(-0.9, 0.08);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.88, 0.08) ;
    glVertex2f(-0.88, 0.12);
    glVertex2f(-0.84, 0.12);
    glVertex2f(-0.84, 0.08);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.82, 0.12) ;
    glVertex2f(-0.78, 0.12) ;
    glVertex2f(-0.78, 0.08) ;
    glVertex2f(-0.82, 0.08) ;
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.9, 0.12);
    glVertex2f(-0.94, 0.12);
    glVertex2f(-0.94, 0.08);
    glVertex2f(-0.9, 0.08);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.7, 0.08);
    glVertex2f(-0.7, 0.12);
    glVertex2f(-0.66, 0.12);
    glVertex2f(-0.66, 0.08);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.64, 0.08) ;
    glVertex2f(-0.64, 0.12);
    glVertex2f(-0.6, 0.12);
    glVertex2f(-0.6, 0.08) ;
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.58, 0.08);
    glVertex2f(-0.58, 0.12);
    glVertex2f(-0.54, 0.12);
    glVertex2f(-0.54, 0.08) ;
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.44, 0.08);
    glVertex2f(-0.44, 0.16);
    glVertex2f(-0.48, 0.16);
    glVertex2f(-0.48, 0.08);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.42, 0.08);
    glVertex2f(-0.42, 0.12);
    glVertex2f(-0.38, 0.12);
    glVertex2f(-0.38, 0.08);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.36, 0.08);
    glVertex2f(-0.36, 0.12);
    glVertex2f(-0.32, 0.12);
    glVertex2f(-0.32, 0.08);
glEnd();

 glPopMatrix();
}
void updatetraint(int value) {
    trainPosXt += trainSpeed;
    if (trainPosXt > 1.2f) {
        trainPosXt = -1.2f; // reset position
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatetraint, 0); // ~60 fps
}

void handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            trainSpeed += 0.005f; // increase speed
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            trainSpeed -= 0.005f;
            if (trainSpeed < 0) trainSpeed = 0;
        }
    }
}
void baloont (){
    glPushMatrix();
    glTranslatef(0.0f, baloonPosYt, 0.0f);
glBegin(GL_POLYGON);
    glColor3f(1.000f, 0.890f, 0.008f);
    glVertex2f(0.58, -0.76);
    glVertex2f(0.64, -0.76);
    glVertex2f(0.64, -0.82);
    glVertex2f(0.58, -0.82);
glEnd();

glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.58, -0.76);
    glVertex2f(0.51, -0.54);
    glVertex2f(0.64, -0.76);
    glVertex2f(0.71, -0.54);

    glVertex2f(0.59, -0.76);
    glVertex2f(0.57, -0.63);
    glVertex2f(0.63, -0.76);
    glVertex2f(0.65, -0.63);


glEnd();

circle(0.1, 0.61, -0.54, 1.000f, 0.000f, 0.000f);
circle(0.09, 0.61, -0.55, 1.000f, 0.412f, 0.706f);
circle(0.08, 0.61, -0.56, 0.000f, 0.000f, 1.000f);
circle(0.07, 0.61, -0.57, 0.000f, 1.000f, 0.000f);
circle(0.06, 0.61, -0.58, 1.000f, 1.000f, 0.000f);
circle(0.05, 0.61, -0.59, 1.000f, 0.647f, 0.000f);
circle(0.04, 0.61, -0.60, 0.627f, 0.125f, 0.941f);
    glPopMatrix();
}
void updatebaloont(int value) {
    baloonPosYt += 0.003f;  // Speed of balloon rising

    if (baloonPosYt > 1.7f) {  // Reset when off top
        baloonPosYt = -0.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updatebaloont, 0); // ~60 FPS
}
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);



skyt ();
cloud1t ();
sunt ();
cloud2t ();
cloud3t ();
car1t ();
car2t ();
car3t ();
backscenet ();
rivert ();
bridget ();
traint ();
innergrilt ();
lamppost1t ();
lamppost2t ();
lamppost3t ();
lamppost4t ();
lamppost5t ();
groundt ();
tree1t ();
tree2t ();
tree3t ();
tree4t ();
tree5t ();
tree6t ();
tree7t ();
shopt  ();
baloont ();

	glFlush();  // Render now
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitWindowSize(2000, 800);   // Set the window's initial width & height
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutTimerFunc(16, updatet, 0);
    glutKeyboardFunc(handleKeypresst);
    glutTimerFunc(0, updateCloud2t, 0);
    glutTimerFunc(16, updatetraint, 0);
    glutMouseFunc(handleMouse);
    glutTimerFunc(16, updatebaloont, 0);
	glutMainLoop();
	return 0;
}
