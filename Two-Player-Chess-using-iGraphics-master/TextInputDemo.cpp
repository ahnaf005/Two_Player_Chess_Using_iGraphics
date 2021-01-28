# include "iGraphics.h"
int x[8][8]={};
int y[8][8]={};
int mode;

void coordinates()
{
    int i,j;
    x[0][0]=100;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(j==0)
                x[i][j]=x[0][0];
            else
                x[i][j]=x[i][j-1]+75;

        }
    }
    y[0][0]=200;
    for(i=0;i<8;i++)
    {
        j=0;
        if(i!=0)
            y[i][j]=y[i-1][j]+75;
        for(j=0;j<8;j++)
        {
            if(j!=0)
                y[i][j]=y[i][j-1];

        }

    }
}

    /*
	function iDraw() is called again and again by the system.

	*/




void iDraw() {
	//place your drawing codes here
	iClear();
	int i,j;
	coordinates();
    iSetColor(130,100,250);
	iFilledRectangle(0,0,900,900);
	for(i=0;i<8;i++)
    {
        if(i%2==0){
            for(j=0;j<8;j++){
                if(j%2==0){
                    iSetColor(0,0,0);
                    iFilledRectangle(x[i][j],y[i][j],75,75);
                }
                else{
                iSetColor(255,255,255);
                iFilledRectangle(x[i][j],y[i][j],75,75);
                }
            }
        }
        if(i%2!=0)
        {
            for(j=0;j<8;j++)
            {
                if(j%2==1){
                    iSetColor(0,0,0);
                    iFilledRectangle(x[i][j],y[i][j],75,75);
                }
                else{
                iSetColor(255,255,255);
                iFilledRectangle(x[i][j],y[i][j],75,75);
                }

            }

        }

    }

    if(mode==1)
    {
        iSetColor(250,250,250);
        iFilledRectangle(100,200,75,75);
    }



	iSetColor(20, 200, 0);
	iText(40, 40, "Hi, I am iGraphics");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//place your codes here
	printf("%d %d ",mx,my);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
            if(mx >=100 && mx <=175 && my >=200 && my <=275 && mode==0)
            {
                mode=0;

            }
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}



int main() {
	//place your own initialization codes here.
	coordinates();
	mode=0;
	iInitialize( 900, 900, "demo");
	return 0;
}
