# include "iGraphics2.h"
int x[8][8]= {};
int y[8][8]= {};
int instr1,instr2;
int mode,checkphoto;
int checki=0,checko=0;
char str[100], str1[100];
int len1,len2;
int open0,open1,open2,open3;
int openi[5]= {};
int openo[5]= {};
int mxs,mys;
int ki=0,ko=0,kis,kos;
char str3[40];
char str4[40];
int ci=0,co=0;
int m3,m4;
int resume=1;
int checkmate1=0,checkmate2=0,stalemate1=0,stalemate2=0;
int sp1[16]= {},sp2[16]= {};
int mode1,mode2;//mode1=0 means player 1 turn,mode2=0 means player 2 turn
int flag1[16]= {};
int flag2[16]= {};
int alive1[16]= {};
int alive2[16]= {};
int a1[16],b1[16],a2[16],b2[16];
int castling=1,castling2=1;

texture whitepawn1texture;
texture whitepawn2texture;
texture blackpawn1texture;
texture blackpawn2texture;
texture whiteknight1texture;
texture whiteknight2texture;
texture blackknight1texture;
texture blackknight2texture;
texture whitecastle1texture;
texture whitecastle2texture;
texture blackcastle1texture;
texture blackcastle2texture;
texture whiteelephant1texture;
texture whiteelephant2texture;
texture blackelephant1texture;
texture blackelephant2texture;
texture whitequeen1texture;
texture whitequeen2texture;
texture blackqueen1texture;
texture blackqueen2texture;
texture whiteking1texture;
texture whiteking2texture;
texture blackking1texture;
texture blackking2texture;
texture whitepawn3texture;
texture whitepawn4texture;
texture blackpawn3texture;
texture blackpawn4texture;
texture chessbehindtexture;
texture headertexture;
texture covertexture;
texture inputcovertexture;
texture instruction1texture;
texture instruction2texture;
texture credits1texture;
texture checkmate1texture;
texture checkmate2texture;
texture drawtexture;
texture stalematetexture;

void iTextureInit()
{
    whitepawn1texture.Create("white pawn2.bmp",1,128,0,128,255,255,255);
    whitepawn2texture.Create("white pawn2.bmp",1,128,0,128,0,0,0);
    blackpawn1texture.Create("black pawn2.bmp",1,128,0,128,255,255,255);
    blackpawn2texture.Create("black pawn2.bmp",1,128,0,128,0,0,0);
    whiteknight1texture.Create("white knight2.bmp",1,128,0,128,255,255,255);
    whiteknight2texture.Create("white knight2.bmp",1,128,0,128,0,0,0);
    blackknight1texture.Create("black knight2.bmp",1,128,0,128,255,255,255);
    blackknight2texture.Create("black knight2.bmp",1,128,0,128,0,0,0);
    whitecastle1texture.Create("white castle2.bmp",1,128,0,128,255,255,255);
    whitecastle2texture.Create("white castle2.bmp",1,128,0,128,0,0,0);
    blackcastle1texture.Create("black castle2.bmp",1,128,0,128,255,255,255);
    blackcastle2texture.Create("black castle2.bmp",1,128,0,128,0,0,0);
    whiteelephant1texture.Create("white elephant2.bmp",1,128,0,128,255,255,255);
    whiteelephant2texture.Create("white elephant2.bmp",1,128,0,128,0,0,0);
    blackelephant1texture.Create("black elephant2.bmp",1,128,0,128,255,255,255);
    blackelephant2texture.Create("black elephant2.bmp",1,128,0,128,0,0,0);
    whitequeen1texture.Create("white queen2.bmp",1,128,0,128,255,255,255);
    whitequeen2texture.Create("white queen2.bmp",1,128,0,128,0,0,0);
    blackqueen1texture.Create("black queen2.bmp",1,128,0,128,255,255,255);
    blackqueen2texture.Create("black queen2.bmp",1,128,0,128,0,0,0);
    whiteking1texture.Create("white king2.bmp",1,128,0,128,255,255,255);
    whiteking2texture.Create("white king2.bmp",1,128,0,128,0,0,0);
    blackking1texture.Create("black king2.bmp",1,128,0,128,255,255,255);
    blackking2texture.Create("black king2.bmp",1,128,0,128,0,0,0);
    whitepawn4texture.Create("white pawn3.bmp",1,128,0,128,255,255,255);
    whitepawn3texture.Create("white pawn3.bmp",1,128,0,128,0,0,0);
    blackpawn4texture.Create("black pawn3.bmp",1,128,0,128,255,255,255);
    blackpawn3texture.Create("black pawn3.bmp",1,128,0,128,0,0,0);
    chessbehindtexture.Create("chessbehind.bmp");
    headertexture.Create("header3.bmp");
    covertexture.Create("cover.bmp");
    inputcovertexture.Create("inputcover.bmp");
    instruction1texture.Create("instruction1.bmp");
    instruction2texture.Create("instruction2.bmp");
    credits1texture.Create("credits1.bmp");
    checkmate1texture.Create("checkmate1.bmp");
    checkmate2texture.Create("checkmate2.bmp");
    drawtexture.Create("draw.bmp");
    stalematetexture.Create("stalemate.bmp");
}
void save()
{
    int i,j;
    FILE * fp;
    fp=fopen("f1.txt","w");
    fprintf(fp,"%d %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d ",checki,checko,mxs,mys,mode1,mode2,castling,castling2,str3,str4,ci,co,ki,ko,kis,kos,len1,len2);
    for(i=0; i<16; i++)
    {
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d ",flag1[i],flag2[i],alive1[i],alive2[i],a1[i],b1[i],a2[i],b2[i],sp1[i],sp2[i]);
    }
    fclose(fp);
    fp=fopen("f2","wb");
    fwrite(str,sizeof(str),1,fp);
    fclose(fp);
    fp=fopen("f3","wb");
    fwrite(str1,sizeof(str1),1,fp);
    fclose(fp);

}
void savecheck()
{
    FILE*fp;
    fp=fopen("f4.txt","w");
    fprintf(fp,"%d %d %d %d %d %d ",checkmate1,checkmate2,stalemate1,stalemate2,m3,m4);
    fclose(fp);

}
void loadcheck()
{
    FILE*fp;
    fp=fopen("f4.txt","r");
    fscanf(fp,"%d %d %d %d %d %d ",&checkmate1,&checkmate2,&stalemate1,&stalemate2,&m3,&m4);
    fclose(fp);

}
void load()
{
    int i,j;
    FILE * fp;
    fp=fopen("f1.txt","r");
    fscanf(fp,"%d %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d ",&checki,&checko,&mxs,&mys,&mode1,&mode2,&castling,&castling2,str3,str4,&ci,&co,&ki,&ko,&kis,&kos,&len1,&len2);
    for(i=0; i<16; i++)
    {
        fscanf(fp,"%d %d %d %d %d %d %d %d %d %d",&flag1[i],&flag2[i],&alive1[i],&alive2[i],&a1[i],&b1[i],&a2[i],&b2[i],&sp1[i],&sp2[i]);
    }
    fclose(fp);
    fp=fopen("f2","rb");
    fread(str,sizeof(str),1,fp);
    fclose(fp);
    fp=fopen("f3","rb");
    fread(str1,sizeof(str1),1,fp);
    fclose(fp);

}

void openi3(int a,int b)
{
    if(a>=700 && a<=900 && b>=40 && b<=80 && openi[3]==1)
    {
        openi[3]=0;
        open1=1;
    }
}

void backmain(int a,int b)
{
    if(a>=700 && a<=900 && b>=40 && b<=80)
    {
        open1=1;
        open3=0;
        checkphoto=0;
    }
}

void secondPage()
{
    drawTexture(0,0,inputcovertexture);
    iSetColor(57, 240, 31);
    iRectangle(440,495,200,30);
    iRectangle(440,395,200,30);
    iRectangle(440,295,200,30);
    iRectangle(440,195,200,30);
    iRectangle(440,95,200,30);
    iSetColor(170,24,201);
    iText(450,505,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450, 405,str,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,370,"CLICK TO EDIT",GLUT_BITMAP_HELVETICA_10);
    iText(450,305,str1,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,270,"CLICK TO EDIT",GLUT_BITMAP_HELVETICA_10);
    iText(450,205,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,105,"EXIT GAME",GLUT_BITMAP_TIMES_ROMAN_24);

    if(openo[1]==1)
    {
        iSetColor(120,250,250);
        iRectangle(440,395,200,30);
    }
    if(openo[2]==1)
    {
        iSetColor(120,250,250);
        iRectangle(440,295,200,30);
    }
}

void frontPage()
{
    drawTexture(0,-200,headertexture);
    iSetColor(57, 240, 31);
    if(resume==1)
    {
        iRectangle(440,495,200,30);
    }
    iRectangle(440,395,200,30);
    iRectangle(440,295,200,30);
    iRectangle(440,195,200,30);
    iRectangle(440,95,200,30);
    iSetColor(170,24,201);
    if(resume==1)
    {
        iText(450,505,"RESUME GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iText(450, 405, "NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,305,"INSTRUCTIONS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,205,"CREDITS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,105,"EXIT GAME",GLUT_BITMAP_TIMES_ROMAN_24);
}

void frontpageopener(int a,int b)
{
    int i;
    if(a >=440 && a <=640  && b >= 495 && b <= 525 && open1== 1 && resume==1)
    {
        open1 = 0;
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
        openi[0]=1;
        load();
        open3=1;
    }
    if(a >=440 && a <=640  && b >= 395 && b <= 425 && open1== 1)
    {
        open1 = 0;
        open2=1;
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
    }
    if(a >=440 && a <=640  && b >= 295 && b <= 325 && open1== 1)
    {
        open1 = 0;
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
        openi[2]=1;
        instr1=1;
    }
    if(a >=440 && a <=640  && b >= 195 && b <= 225 && open1== 1)
    {
        open1 = 0;
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
        openi[3]=1;
    }
    if(a >=440 && a <=640  && b >= 95 && b <= 125 && open1== 1)
    {
        exit(0);
    }
}

void secondpageopener(int a,int b)
{
    int i,j,k;
    if(a >=440 && a <=640  && b >= 495 && b <= 525 && open2== 1)
    {
        open2 = 0;
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
        checki=0;
        checko=0;
        mxs=0;
        mys=0;
        mode1=0;
        mode2=1;
        castling=1;
        castling2=1;
        ci=0;
        co=0;
        for(i=0; i<16; i++)
        {
            flag1[i]=0;
            flag2[i]=0;
            alive1[i]=0;
            alive2[i]=0;
        }
        i=0;
        for(j=0; j<=7; j++)
        {
            a1[j]=x[i][j];
            b1[j]=y[i][j];
        }
        i=1;
        for(j=0,k=8; j<=7,k<=15; j++,k++)
        {
            a1[k]=x[i][j];
            b1[k]=y[i][j];
        }
        i=7;
        for(j=0; j<=7; j++)
        {
            a2[j]=x[i][j];
            b2[j]=y[i][j];
        }
        i=6;
        for(j=0,k=8; j<=7,k<=15; j++,k++)
        {
            a2[k]=x[i][j];
            b2[k]=y[i][j];
        }
        open3=1;
    }
    if(a >=440 && a <=640  && b >= 395 && b <= 425 && open2== 1)
    {
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
        openo[1]=!openo[1];
    }
    if(a >=440 && a <=640  && b >= 295 && b <= 325 && open2== 1)
    {
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
        openo[2]=1;
    }
    if(a >=440 && a <=640  && b >= 195 && b <= 225 && open2== 1)
    {
        open2 = 0;
        for(i=0; i<5; i++)
        {
            openi[i]=0;
            openo[i]=0;
        }
        open1=1;
        openo[1]=1;
    }
    if(a >=440 && a <=640  && b >= 95 && b <= 125 && open2== 1)
    {
        exit(0);
    }
}

void instrt1open(int a,int b)
{
    if(a>=650 && a<=750 && b>=590 && b<=630 && instr1==1)
    {
        instr1=0;
        instr2=1;
    }
    else if(a>=650 && a<=750 && b>=590 && b<=630 && instr2==1)
    {
        instr1=1;
        instr2=0;
    }
    if(a>=150 && a<=350 && b>=590 && b<=630 && (instr1==1 || instr2==1))
    {
        openi[2]=0;
        open1=1;
    }
}

int colouring(int a,int b)
{
    int i,j,ti,tj;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(x[i][j]==a && y[i][j]==b)
            {
                ti=i;
                tj=j;
                break;
            }
        }
    }
    if((ti%2==0  && tj%2==0)||(ti%2==1  &&  tj%2==1))
        return 1;
    return 0;
}

int ifpositionnull1(int a,int b)
{
    int l;
    for(l=0; l<16; l++)
    {
        if(a2[l]==a && b2[l]==b)
            return 0;
    }
    return 1;
}

int ifpositionnull2(int a,int b)
{
    int l;
    for(l=0; l<16; l++)
    {
        if(a1[l]==a && b1[l]==b)
            return 0;
    }
    return 1;
}

int ifpositionnull1n(int a,int b)
{
    int l;
    for(l=0; l<16; l++)
    {
        if(l==3)
            continue;
        if(a2[l]==a && b2[l]==b)
            return 0;
    }
    return 1;
}

int ifpositionnull2n(int a,int b)
{
    int l;
    for(l=0; l<16; l++)
    {
        if(l==3)
            continue;
        if(a1[l]==a && b1[l]==b)
            return 0;
    }
    return 1;
}
int checkavailable1(int a,int b)
{
    int f=1;
    if((a+128==a2[1] && b+64==b2[1])||(a+128==a2[1] && b-64==b2[1])||(a-128==a2[1] && b+64==b2[1])||(a-128==a2[1] && b-64==b2[1])||(a+64==a2[1] && b+128==b2[1])||(a+64==a2[1] && b-128==b2[1])||(a-64==a2[1] && b+128==b2[1])||(a-64==a2[1] && b-128==b2[1]))
        f=0;
    if((a+128==a2[6] && b+64==b2[6])||(a+128==a2[6] && b-64==b2[6])||(a-128==a2[6] && b+64==b2[6])||(a-128==a2[6] && b-64==b2[6])||(a+64==a2[6] && b+128==b2[6])||(a+64==a2[6] && b-128==b2[6])||(a-64==a2[6] && b+128==b2[6])||(a-64==a2[6] && b-128==b2[6]))
        f=0;
    if(f==1)
        return 1;
    return 0;
}
int checkavailable2(int a,int b)
{
    int f=1;
    if((a+128==a1[1] && b+64==b1[1])||(a+128==a1[1] && b-64==b1[1])||(a-128==a1[1] && b+64==b1[1])||(a-128==a1[1] && b-64==b1[1])||(a+64==a1[1] && b+128==b1[1])||(a+64==a1[1] && b-128==b1[1])||(a-64==a1[1] && b+128==b1[1])||(a-64==a1[1] && b-128==b1[1]))
        f=0;
    if((a+128==a1[6] && b+64==b1[6])||(a+128==a1[6] && b-64==b1[6])||(a-128==a1[6] && b+64==b1[6])||(a-128==a1[6] && b-64==b1[6])||(a+64==a1[6] && b+128==b1[6])||(a+64==a1[6] && b-128==b1[6])||(a-64==a1[6] && b+128==b1[6])||(a-64==a1[6] && b-128==b1[6]))
        f=0;
    if(f==1)
        return 1;
    return 0;
}
int checkavailablepawn1(int a,int b)
{
    int k;
    for(k=8; k<=15; k++)
    {
        if((a+64==a2[k] && b+64==b2[k]) || (a-64==a2[k] && b+64==b2[k]))
            return 0;
    }
    return 1;
}

int checkavailablepawn2(int a,int b)
{
    int k;
    for(k=8; k<=15; k++)
    {
        if((a-64==a1[k] && b-64==b1[k]) || (a+64==a1[k] && b-64==b1[k]))
            return 0;
    }
    return 1;
}
int checkavailablestraight1(int a,int b)
{
    int f=1,k,f1=1,f2=1,f3=1,f4=1;
    int cnt=64;
    while(b+cnt<=478)
    {
        if(!ifpositionnull2n(a,b+cnt))
            break;
        if(!ifpositionnull1(a,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a==a2[0] && b+cnt==b2[0])||(a==a2[7] && b+cnt==b2[7])||(a==a2[4] && b+cnt==b2[4])||(a==a2[k] && b+cnt==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f1=0;
            }
        }
        if(f1==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(b-cnt>=30)
    {
        if(!ifpositionnull2n(a,b-cnt))
            break;
        if(!ifpositionnull1(a,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a==a2[0] && b-cnt==b2[0])||(a==a2[7] && b-cnt==b2[7])||(a==a2[4] && b-cnt==b2[4])||(a==a2[k] && b-cnt==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f2=0;
            }
        }
        if(f2==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a+cnt<=548)
    {
        if(!ifpositionnull2n(a+cnt,b))
            break;
        if(!ifpositionnull1(a+cnt,b))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a2[0] && b==b2[0])||(a+cnt==a2[7] && b==b2[7])||(a+cnt==a2[4] && b==b2[4])||(a+cnt==a2[k] && b==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f3=0;
            }
        }
        if(f3==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a-cnt>=100)
    {
        if(!ifpositionnull2n(a-cnt,b))
            break;
        if(!ifpositionnull1(a-cnt,b))
        {
            for(k=0; k<16; k++)
            {
                if((a-cnt==a2[0] && b==b2[0])||(a-cnt==a2[7] && b==b2[7])||(a-cnt==a2[4] && b==b2[4])||(a-cnt==a2[k] && b==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f4=0;
            }
        }
        if(f4==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 1;
    return 0;
}

int checkavailablestraight2(int a,int b)
{
    int f=1,k,f1=1,f2=1,f3=1,f4=1;
    int cnt=64;
    while(b+cnt<=478)
    {
        if(!ifpositionnull1n(a,b+cnt))
            break;
        if(!ifpositionnull2(a,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a==a1[0] && b+cnt==b1[0])||(a==a1[7] && b+cnt==b1[7])||(a==a1[4] && b+cnt==b1[4])||(a==a1[k] && b+cnt==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f1=0;
            }
        }
        if(f1==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(b-cnt>=30)
    {
        if(!ifpositionnull1n(a,b-cnt))
            break;
        if(!ifpositionnull2(a,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a==a1[0] && b-cnt==b1[0])||(a==a1[7] && b-cnt==b1[7])||(a==a1[4] && b-cnt==b1[4])||(a==a1[k] && b-cnt==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f2=0;
            }
        }
        if(f2==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a+cnt<=548)
    {
        if(!ifpositionnull1n(a+cnt,b))
            break;
        if(!ifpositionnull2(a+cnt,b))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a1[0] && b==b1[0])||(a+cnt==a1[7] && b==b1[7])||(a+cnt==a1[4] && b==b1[4])||(a+cnt==a1[k] && b==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f3=0;
            }
        }
        if(f3==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a-cnt>=100)
    {
        if(!ifpositionnull1n(a-cnt,b))
            break;
        if(!ifpositionnull2(a-cnt,b))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a1[0] && b==b1[0])||(a-cnt==a1[7] && b==b1[7])||(a-cnt==a1[4] && b==b1[4])||(a-cnt==a1[k] && b==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f4=0;
            }
        }
        if(f4==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 1;
    return 0;
}

int checkavailablediagonal1(int a,int b)
{
    int f=1,k,f1=1,f2=1,f3=1,f4=1;
    int cnt=64;
    while(a+cnt<=548 && b+cnt<=478)
    {
        if(!ifpositionnull2n(a+cnt,b+cnt))
            break;
        if(!ifpositionnull1(a+cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a2[2] && b+cnt==b2[2])||(a+cnt==a2[5] && b+cnt==b2[5])||(a+cnt==a2[4] && b+cnt==b2[4])||(a+cnt==a2[k] && b+cnt==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f1=0;
            }
        }
        if(f1==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a+cnt<=548 && b-cnt>=30)
    {
        if(!ifpositionnull2n(a+cnt,b-cnt))
            break;
        if(!ifpositionnull1(a+cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a2[2] && b-cnt==b2[2])||(a+cnt==a2[5] && b-cnt==b2[5])||(a+cnt==a2[4] && b-cnt==b2[4])||(a+cnt==a2[k] && b-cnt==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f2=0;
            }
        }
        if(f2==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a-cnt>=100 && b+cnt<=478)
    {
        if(!ifpositionnull2n(a-cnt,b+cnt))
            break;
        if(!ifpositionnull1(a-cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a2[2] && b+cnt==b2[2])||(a-cnt==a2[5] && b+cnt==b2[5])||(a-cnt==a2[4] && b+cnt==b2[4])||(a-cnt==a2[k] && b+cnt==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f3=0;
            }
        }
        if(f3==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a-cnt>=100 && b-cnt>=30)
    {
        if(!ifpositionnull2n(a-cnt,b-cnt))
            break;
        if(!ifpositionnull1(a-cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a2[2] && b-cnt==b2[2])||(a-cnt==a2[5] && b-cnt==b2[5])||(a-cnt==a2[4] && b-cnt==b2[4])||(a-cnt==a2[k] && b-cnt==b2[k] && sp2[k]==1))
                    f=0;
                else
                    f4=0;
            }
        }
        if(f4==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 1;
    return 0;
}

int checkavailablediagonal2(int a,int b)
{
    int f=1,k,f1=1,f2=1,f3=1,f4=1;
    int cnt=64;
    while(a+cnt<=548 && b+cnt<=478)
    {
        if(!ifpositionnull1n(a+cnt,b+cnt))
            break;
        if(!ifpositionnull2(a+cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a1[2] && b+cnt==b1[2])||(a+cnt==a1[5] && b+cnt==b1[5])||(a+cnt==a1[4] && b+cnt==b1[4])||(a+cnt==a1[k] && b+cnt==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f1=0;
            }
        }
        if(f1==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a+cnt<=548 && b-cnt>=30)
    {
        if(!ifpositionnull1n(a+cnt,b-cnt))
            break;
        if(!ifpositionnull2(a+cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a1[2] && b-cnt==b1[2])||(a+cnt==a1[5] && b-cnt==b1[5])||(a+cnt==a1[4] && b-cnt==b1[4])||(a+cnt==a1[k] && b-cnt==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f2=0;
            }
        }
        if(f2==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a-cnt>=100 && b+cnt<=478)
    {
        if(!ifpositionnull1n(a-cnt,b+cnt))
            break;
        if(!ifpositionnull2(a-cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a1[2] && b+cnt==b1[2])||(a-cnt==a1[5] && b+cnt==b1[5])||(a-cnt==a1[4] && b+cnt==b1[4])||(a-cnt==a1[k] && b+cnt==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f3=0;
            }
        }
        if(f3==0)
            break;
        cnt=cnt+64;
    }
    cnt=64;
    while(a-cnt>=100 && b-cnt>=30)
    {
        if(!ifpositionnull1n(a-cnt,b-cnt))
            break;
        if(!ifpositionnull2(a-cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a1[2] && b-cnt==b1[2])||(a-cnt==a1[5] && b-cnt==b1[5])||(a-cnt==a1[4] && b-cnt==b1[4])||(a-cnt==a1[k] && b-cnt==b1[k] && sp1[k]==1))
                    f=0;
                else
                    f4=0;
            }
        }
        if(f4==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 1;
    return 0;
}

int checkavailableking1(int a,int b)
{
    if((a-64==a2[3] && b==b2[3])||(a+64==a2[3] && b==b2[3])||(a==a2[3] && b+64==b2[3])||(a==a2[3] && b-64==b2[3])||(a-64==a2[3] && b-64==b2[3])||(a-64==a2[3] && b+64==b2[3])||(a+64==a2[3] && b-64==b2[3])||(a+64==a2[3] && b+64==b2[3]))
        return 0;
    return 1;
}

int checkavailableking2(int a,int b)
{
    if((a-64==a1[3] && b==b1[3])||(a+64==a1[3] && b==b1[3])||(a==a1[3] && b+64==b1[3])||(a==a1[3] && b-64==b1[3])||(a-64==a1[3] && b-64==b1[3])||(a-64==a1[3] && b+64==b1[3])||(a+64==a1[3] && b-64==b1[3])||(a+64==a1[3] && b+64==b1[3]))
        return 0;
    return 1;
}

int check1(int a,int b)
{
    if(!checkavailable1(a,b) || !checkavailablediagonal1(a,b) || !checkavailableking1(a,b) || !checkavailablestraight1(a,b) || !checkavailablepawn1(a,b))
        return 1;
    return 0;
}

int check2(int a,int b)
{
    if(!checkavailable2(a,b) || !checkavailablediagonal2(a,b) || !checkavailableking2(a,b) || !checkavailablestraight2(a,b) || !checkavailablepawn2(a,b))
        return 1;
    return 0;
}

int us1(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(b+cnt<=478)
    {
        if(!ifpositionnull2n(a,b+cnt))
            break;
        if(!ifpositionnull1(a,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if(a==a2[k] && b+cnt==b2[k] && sp2[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a==a2[0] && b+cnt==b2[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a==a2[7] && b+cnt==b2[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a==a2[4] && b+cnt==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int ds1(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(b-cnt>=30)
    {
        if(!ifpositionnull2n(a,b-cnt))
            break;
        if(!ifpositionnull1(a,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if(a==a2[k] && b-cnt==b2[k] && sp2[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a==a2[0] && b-cnt==b2[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a==a2[7] && b-cnt==b2[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a==a2[4] && b-cnt==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int rs1(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(a+cnt<=548)
    {
        if(!ifpositionnull2n(a+cnt,b))
            break;
        if(!ifpositionnull1(a+cnt,b))
        {
            for(k=8; k<16; k++)
            {
                if(a+cnt==a2[k] && b==b2[k] && sp2[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a+cnt==a2[0] && b==b2[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a+cnt==a2[7] && b==b2[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a+cnt==a2[4] && b==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int ls1(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(a-cnt>=100)
    {
        if(!ifpositionnull2n(a-cnt,b))
            break;
        if(!ifpositionnull1(a-cnt,b))
        {
            for(k=8; k<16; k++)
            {
                if(a-cnt==a2[k] && b==b2[k] && sp2[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a-cnt==a2[0] && b==b2[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a-cnt==a2[7] && b==b2[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a-cnt==a2[4] && b==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int urd1(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a+cnt<=548 && b+cnt<=478)
    {
        if(!ifpositionnull2n(a+cnt,b+cnt))
            break;
        if(!ifpositionnull1(a+cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a2[k] && b+cnt==b2[k] && sp2[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a+cnt==a2[2] && b+cnt==b2[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a+cnt==a2[5] && b+cnt==b2[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a+cnt==a2[4] && b+cnt==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int drd1(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a+cnt<=548 && b-cnt>=30)
    {
        if(!ifpositionnull2n(a+cnt,b-cnt))
            break;
        if(!ifpositionnull1(a+cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a2[k] && b-cnt==b2[k] && sp2[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a+cnt==a2[2] && b-cnt==b2[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a+cnt==a2[5] && b-cnt==b2[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a+cnt==a2[4] && b-cnt==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int dld1(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a-cnt>=100 && b-cnt>=30)
    {
        if(!ifpositionnull2n(a-cnt,b-cnt))
            break;
        if(!ifpositionnull1(a-cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a2[k] && b-cnt==b2[k] && sp2[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a-cnt==a2[2] && b-cnt==b2[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a-cnt==a2[5] && b-cnt==b2[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a-cnt==a2[4] && b-cnt==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int uld1(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a-cnt>=30 && b+cnt<=478)
    {
        if(!ifpositionnull2n(a-cnt,b+cnt))
            break;
        if(!ifpositionnull1(a-cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a2[k] && b+cnt==b2[k] && sp2[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a-cnt==a2[2] && b+cnt==b2[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a-cnt==a2[5] && b+cnt==b2[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a-cnt==a2[4] && b+cnt==b2[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int us2(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(b+cnt<=478)
    {
        if(!ifpositionnull1n(a,b+cnt))
            break;
        if(!ifpositionnull2(a,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if(a==a1[k] && b+cnt==b1[k] && sp1[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a==a1[0] && b+cnt==b1[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a==a1[7] && b+cnt==b1[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a==a1[4] && b+cnt==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }

        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int ds2(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(b-cnt>=30)
    {
        if(!ifpositionnull1n(a,b-cnt))
            break;
        if(!ifpositionnull2(a,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if(a==a1[k] && b-cnt==b1[k] && sp1[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a==a1[0] && b-cnt==b1[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a==a1[7] && b-cnt==b1[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a==a1[4] && b-cnt==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int rs2(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(a+cnt<=548)
    {
        if(!ifpositionnull1n(a+cnt,b))
            break;
        if(!ifpositionnull2(a+cnt,b))
        {
            for(k=8; k<16; k++)
            {
                if(a+cnt==a1[k] && b==b1[k] && sp1[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a+cnt==a1[0] && b==b1[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a+cnt==a1[7] && b==b1[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a+cnt==a1[4] && b==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int ls2(int a,int b)
{
    int f=1,f1=1,r,k;
    int cnt=64;
    while(a-cnt>=100)
    {
        if(!ifpositionnull1n(a-cnt,b))
            break;
        if(!ifpositionnull2(a-cnt,b))
        {
            for(k=8; k<16; k++)
            {
                if(a-cnt==a1[k] && b==b1[k] && sp1[k]==1)
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a-cnt==a1[0] && b==b1[0])
                {
                    f=0;
                    r=0;
                    break;
                }
                else if(a-cnt==a1[7] && b==b1[7])
                {
                    f=0;
                    r=7;
                    break;
                }
                else if(a-cnt==a1[4] && b==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return -1;
    return r;
}

int urd2(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a+cnt<=548 && b+cnt<=478)
    {
        if(!ifpositionnull1n(a+cnt,b+cnt))
            break;
        if(!ifpositionnull2(a+cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a1[k] && b+cnt==b1[k] && sp1[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a+cnt==a1[2] && b+cnt==b1[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a+cnt==a1[5] && b+cnt==b1[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a+cnt==a1[4] && b+cnt==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int drd2(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a+cnt<=548 && b-cnt>=30)
    {
        if(!ifpositionnull1n(a+cnt,b-cnt))
            break;
        if(!ifpositionnull2(a+cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a+cnt==a1[k] && b-cnt==b1[k] && sp1[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a+cnt==a1[2] && b-cnt==b1[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a+cnt==a1[5] && b-cnt==b1[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a+cnt==a1[4] && b-cnt==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int dld2(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a-cnt>=100 && b-cnt>=30)
    {
        if(!ifpositionnull1n(a-cnt,b-cnt))
            break;
        if(!ifpositionnull2(a-cnt,b-cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a1[k] && b-cnt==b1[k] && sp1[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a-cnt==a1[2] && b-cnt==b1[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a-cnt==a1[5] && b-cnt==b1[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a-cnt==a1[4] && b-cnt==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int uld2(int a,int b)
{
    int f=1,k,r,f1=1;
    int cnt=64;
    while(a-cnt>=30 && b+cnt<=478)
    {
        if(!ifpositionnull1n(a-cnt,b+cnt))
            break;
        if(!ifpositionnull2(a-cnt,b+cnt))
        {
            for(k=8; k<16; k++)
            {
                if((a-cnt==a1[k] && b+cnt==b1[k] && sp1[k]==1))
                {
                    f=0;
                    r=k;
                    break;
                }
                else if(a-cnt==a1[2] && b+cnt==b1[2])
                {
                    f=0;
                    r=2;
                    break;
                }
                else if(a-cnt==a1[5] && b+cnt==b1[5])
                {
                    f=0;
                    r=5;
                    break;
                }
                else if(a-cnt==a1[4] && b+cnt==b1[4])
                {
                    f=0;
                    r=4;
                    break;
                }
                else
                    f1=0;
            }
        }
        if(f1==0 || f==0)
            break;
        cnt=cnt+64;
    }
    if(f==1)
        return 0;
    return r;
}

int checkall1(int a,int b)
{
    if(checkavailable1(a,b) && checkavailablediagonal1(a,b) && checkavailablepawn1(a,b) && checkavailablestraight1(a,b))
        return 1;
    return 0;
}

int checkall2(int a,int b)
{
    if(checkavailable2(a,b) && checkavailablediagonal2(a,b) && checkavailablepawn2(a,b) && checkavailablestraight2(a,b))
        return 1;
    return 0;
}

int cpi1(int a,int b)
{
    int k;
    for(k=8; k<=15; k++)
    {
        if((a+64==a2[k] && b+64==b2[k]) || (a-64==a2[k] && b+64==b2[k]))
            return k;
    }
    return 0;

}
int cknighti(int a,int b)
{
    int f=1,r;
    if((a+128==a2[1] && b+64==b2[1])||(a+128==a2[1] && b-64==b2[1])||(a-128==a2[1] && b+64==b2[1])||(a-128==a2[1] && b-64==b2[1])||(a+64==a2[1] && b+128==b2[1])||(a+64==a2[1] && b-128==b2[1])||(a-64==a2[1] && b+128==b2[1])||(a-64==a2[1] && b-128==b2[1]))
    {
        f=0;
        r=1;
    }
    if((a+128==a2[6] && b+64==b2[6])||(a+128==a2[6] && b-64==b2[6])||(a-128==a2[6] && b+64==b2[6])||(a-128==a2[6] && b-64==b2[6])||(a+64==a2[6] && b+128==b2[6])||(a+64==a2[6] && b-128==b2[6])||(a-64==a2[6] && b+128==b2[6])||(a-64==a2[6] && b-128==b2[6]))
    {
        f=0;
        r=6;
    }
    if(f==1)
        return 0;
    return r;
}
int cpi2(int a,int b)
{
    int k;
    for(k=8; k<=15; k++)
    {
        if((a+64==a1[k] && b+64==b1[k]) || (a-64==a1[k] && b+64==b1[k]))
            return k;
    }
    return 0;
}

int cknighto(int a,int b)
{
    int f=1,r;
    if((a+128==a1[1] && b+64==b1[1])||(a+128==a1[1] && b-64==b1[1])||(a-128==a1[1] && b+64==b1[1])||(a-128==a1[1] && b-64==b1[1])||(a+64==a1[1] && b+128==b1[1])||(a+64==a1[1] && b-128==b1[1])||(a-64==a1[1] && b+128==b1[1])||(a-64==a1[1] && b-128==b1[1]))
    {
        f=0;
        r=1;
    }
    if((a+128==a1[6] && b+64==b1[6])||(a+128==a1[6] && b-64==b1[6])||(a-128==a1[6] && b+64==b1[6])||(a-128==a1[6] && b-64==b1[6])||(a+64==a1[6] && b+128==b1[6])||(a+64==a1[6] && b-128==b1[6])||(a-64==a1[6] && b+128==b1[6])||(a-64==a1[6] && b-128==b1[6]))
    {
        f=0;
        r=6;
    }
    if(f==1)
        return 0;
    return r;
}

void checkmatei()
{
    int cnt=0,a,b,c=64,p,q,f=0,f1=0,i,m=1;
    a=a1[3];
    b=b1[3];
    if((!ifpositionnull2(a+64,b) || !checkall1(a+64,b) || a+64>548?1:0) && (!ifpositionnull2(a-64,b) || !checkall1(a-64,b) || a-64<100?1:0) && (!ifpositionnull2(a,b+64) || !checkall1(a,b+64) || b+64>478?1:0)  && (!ifpositionnull2(a,b-64) || !checkall1(a,b-64) || b-64<30?1:0) && (!ifpositionnull2(a+64,b+64) || !checkall1(a+64,b+64) || a+64>548?1:0 || b+64>478?1:0) && (!ifpositionnull2(a-64,b+64) || !checkall1(a-64,b+64) || a-64<100?1:0 || b+64>478?1:0) && (!ifpositionnull2(a-64,b-64) || !checkall1(a-64,b-64) || a-64<100?1:0 || b-64<30?1:0) && (!ifpositionnull2(a+64,b-64) || !checkall1(a+64,b-64) || a+64>548?1:0 || b-64<30?1:0))
    {
        if(us1(a,b)!=-1 && checkavailable1(a,b) && checkavailablediagonal1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[us1(a,b)];
            q=b2[us1(a,b)];
            while(b+c!=q)
            {
                if(checkall2(a,b+c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(ds1(a,b)!=-1 && checkavailable1(a,b) && checkavailablediagonal1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[ds1(a,b)];
            q=b2[ds1(a,b)];
            while(b-c!=q)
            {
                if(checkall2(a,b-c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(ls1(a,b)!=-1 && checkavailable1(a,b) && checkavailablediagonal1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[ls1(a,b)];
            q=b2[ls1(a,b)];
            while(a-c!=p)
            {
                if(checkall2(a-c,b))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(rs1(a,b)!=-1 && checkavailable1(a,b) && checkavailablediagonal1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[rs1(a,b)];
            q=b2[rs1(a,b)];
            while(a+c!=p)
            {
                if(checkall2(a+c,b))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(urd1(a,b) && checkavailable1(a,b) && checkavailablestraight1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[urd1(a,b)];
            q=b2[urd1(a,b)];
            while(a+c!=p && b+c!=q)
            {
                if(checkall2(a+c,b+c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(uld1(a,b) && checkavailable1(a,b) && checkavailablestraight1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[uld1(a,b)];
            q=b2[uld1(a,b)];
            while(a-c!=p && b+c!=q)
            {
                if(checkall2(a-c,b+c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(drd1(a,b) && checkavailable1(a,b) && checkavailablestraight1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[drd1(a,b)];
            q=b2[drd1(a,b)];
            while(a+c!=p && b-c!=q)
            {
                if(checkall2(a+c,b-c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(dld1(a,b) && checkavailable1(a,b) && checkavailablestraight1(a,b) && checkavailableking1(a,b) && checkavailablepawn1(a,b))
        {
            f1=1;
            p=a2[dld1(a,b)];
            q=b2[dld1(a,b)];
            while(a-c!=p && b-c!=q)
            {
                if(checkall2(a-c,b-c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(cpi1(a,b) && checkavailable1(a,b) && checkavailablestraight1(a,b) && checkavailableking1(a,b) && checkavailablediagonal1(a,b))
        {
            f1=1;
            p=a2[cpi1(a,b)];
            q=a2[cpi1(a,b)];
            if(checkall2(p,q))
                f=1;
            cnt++;
        }
        if(cknighti(a,b) && checkavailablepawn1(a,b) && checkavailablestraight1(a,b) && checkavailableking1(a,b) && checkavailablediagonal1(a,b))
        {
            f1=1;
            //printf("HELLO WORLD");
            p=a2[cknighti(a,b)];
            q=a2[cknighti(a,b)];
            if(checkall2(p,q))
                f=1;
            cnt++;
        }
        if(cnt>1 || (f==0 && f1!=0)){
            checkmate1=1;
            //printf("cnt:%d\n f:%d\n f1:%d\n",cnt,f,f1);
        }
        else if(cnt==0)
        {
            for(i=0; i<16; i++)
            {
                if(i!=3 && alive1[i]==0)
                {
                    m=0;
                    break;
                }
            }
            if(m==1)
                stalemate1=1;
        }
    }
}

void checkmateo()
{
    int cnt=0,a,b,c=64,p,q,f=0,f1=0,i,m=1;
    a=a2[3];
    b=b2[3];
    if((!ifpositionnull1(a+64,b) || !checkall2(a+64,b) || a+64>548?1:0) && (!ifpositionnull1(a-64,b) || !checkall2(a-64,b) || a-64<100?1:0) && (!ifpositionnull1(a,b+64) || !checkall2(a,b+64) || b+64>478?1:0)  && (!ifpositionnull1(a,b-64) || !checkall2(a,b-64) || b-64<30?1:0) && (!ifpositionnull1(a+64,b+64) || !checkall2(a+64,b+64) || a+64>548?1:0 || b+64>478?1:0) && (!ifpositionnull1(a-64,b+64) || !checkall2(a-64,b+64) || a-64<100?1:0 || b+64>478?1:0) && (!ifpositionnull1(a-64,b-64) || !checkall2(a-64,b-64) || a-64<100?1:0 || b-64<30?1:0) && (!ifpositionnull1(a+64,b-64) || !checkall2(a+64,b-64) || a+64>548?1:0 || b-64<30?1:0))
    {
        if(us2(a,b)!=-1 && checkavailable2(a,b) && checkavailablediagonal2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[us2(a,b)];
            q=b1[us2(a,b)];
            while(b+c!=q)
            {
                if(checkall1(a,b+c))
                {
                    f=1;
                    break;
                }
                c++;

            }
            cnt++;
        }
        c=64;
        if(ds2(a,b)!=-1 && checkavailable2(a,b) && checkavailablediagonal2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[ds2(a,b)];
            q=b1[ds2(a,b)];
            while(b-c!=q)
            {
                if(checkall1(a,b-c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(ls2(a,b)!=-1 && checkavailable2(a,b) && checkavailablediagonal2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[ls2(a,b)];
            q=b1[ls2(a,b)];
            while(a-c!=p)
            {
                if(checkall1(a-c,b))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(rs2(a,b)!=-1 && checkavailable2(a,b) && checkavailablediagonal2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[rs2(a,b)];
            q=b1[rs2(a,b)];
            while(a+c!=p)
            {
                if(checkall1(a+c,b))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(urd2(a,b) && checkavailable2(a,b) && checkavailablestraight2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[urd2(a,b)];
            q=b1[urd2(a,b)];
            while(a+c!=p && b+c!=q)
            {
                if(checkall1(a+c,b+c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(uld2(a,b) && checkavailable2(a,b) && checkavailablestraight2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[uld2(a,b)];
            q=b1[uld2(a,b)];
            while(a-c!=p && b+c!=q)
            {
                if(checkall1(a-c,b+c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(drd2(a,b) && checkavailable2(a,b) && checkavailablestraight2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[drd2(a,b)];
            q=b1[drd2(a,b)];
            while(a+c!=p && b-c!=q)
            {
                if(checkall1(a+c,b-c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(dld2(a,b) && checkavailable2(a,b) && checkavailablestraight2(a,b) && checkavailableking2(a,b) && checkavailablepawn2(a,b))
        {
            f1=1;
            p=a1[dld2(a,b)];
            q=b1[dld2(a,b)];
            while(a-c!=p && b-c!=q)
            {
                if(checkall1(a-c,b-c))
                {
                    f=1;
                    break;
                }
                c++;
            }
            cnt++;
        }
        c=64;
        if(cpi2(a,b) && checkavailable2(a,b) && checkavailablestraight2(a,b) && checkavailableking2(a,b) && checkavailablediagonal2(a,b))
        {
            f1=1;
            p=a1[cpi2(a,b)];
            q=a1[cpi2(a,b)];
            if(checkall1(p,q))
                f=1;
            cnt++;
        }
        if(cknighto(a,b) && checkavailablepawn2(a,b) && checkavailablestraight2(a,b) && checkavailableking2(a,b) && checkavailablediagonal2(a,b))
        {
            f1=1;
            p=a1[cknighto(a,b)];
            q=a1[cknighto(a,b)];
            if(checkall1(p,q))
                f=1;
            cnt++;
        }
        if(cnt>1 || (f==0 && f1!=0))
            checkmate2=1;
        else if(cnt==0)
        {
            for(i=0; i<16; i++)
            {
                if(i!=3 && alive2[i]==0)
                {
                    m=0;
                    break;
                }
            }
            if(m==1)
                stalemate2=1;
        }
    }
}

void kingi(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode1==0)
    {
        if(a>=a1[3] && a<=a1[3]+64 && b>=b1[3] && b<=b1[3]+64)
        {
            flag1[3]=1;
            f=1;
        }
    }
    if(flag1[3]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[3]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[3]=3;
    }
    if(f==1)
        mode1=2;
}

void drawkingi()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1;
    if(flag1[3]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[3],b1[3],64,64);
        if(b1[3]+64<=478 && ifpositionnull2(a1[3],b1[3]+64) && checkavailable1(a1[3],b1[3]+64) && checkavailablepawn1(a1[3],b1[3]+64) && checkavailablestraight1(a1[3],b1[3]+64) && checkavailablediagonal1(a1[3],b1[3]+64) && checkavailableking1(a1[3],b1[3]+64))
            iRectangle(a1[3],b1[3]+64,64,64);
        if(b1[3]-64>=30 && ifpositionnull2(a1[3],b1[3]-64) && checkavailable1(a1[3],b1[3]-64) && checkavailablepawn1(a1[3],b1[3]-64) && checkavailablestraight1(a1[3],b1[3]-64) && checkavailablediagonal1(a1[3],b1[3]-64) && checkavailableking1(a1[3],b1[3]-64))
            iRectangle(a1[3],b1[3]-64,64,64);
        if(a1[3]+64<=548 && b1[3]-64>=30 && ifpositionnull2(a1[3]+64,b1[3]-64) && checkavailable1(a1[3]+64,b1[3]-64) && checkavailablepawn1(a1[3]+64,b1[3]-64) && checkavailablestraight1(a1[3]+64,b1[3]-64) && checkavailablediagonal1(a1[3]+64,b1[3]-64) && checkavailableking1(a1[3]+64,b1[3]-64))
            iRectangle(a1[3]+64,b1[3]-64,64,64);
        if(a1[3]+64<=548 && b1[3]+64<=478 && ifpositionnull2(a1[3]+64,b1[3]+64) && checkavailable1(a1[3]+64,b1[3]+64) && checkavailablepawn1(a1[3]+64,b1[3]+64) && checkavailablestraight1(a1[3]+64,b1[3]+64) && checkavailablediagonal1(a1[3]+64,b1[3]+64) && checkavailableking1(a1[3]+64,b1[3]+64))
            iRectangle(a1[3]+64,b1[3]+64,64,64);
        if(a1[3]-64>=100 && b1[3]+64<=478 && ifpositionnull2(a1[3]-64,b1[3]+64) && checkavailable1(a1[3]-64,b1[3]+64) && checkavailablepawn1(a1[3]-64,b1[3]+64) && checkavailablestraight1(a1[3]-64,b1[3]+64) && checkavailablediagonal1(a1[3]-64,b1[3]+64) && checkavailableking1(a1[3]-64,b1[3]+64))
            iRectangle(a1[3]-64,b1[3]+64,64,64);
        if(a1[3]-64>=100 && b1[3]-64>=30 && ifpositionnull2(a1[3]-64,b1[3]-64) && checkavailable1(a1[3]-64,b1[3]-64) && checkavailablepawn1(a1[3]-64,b1[3]-64) && checkavailablestraight1(a1[3]-64,b1[3]-64) && checkavailablediagonal1(a1[3]-64,b1[3]-64) && checkavailableking1(a1[3]-64,b1[3]-64))
            iRectangle(a1[3]-64,b1[3]-64,64,64);
        if(a1[3]-64>=100 && ifpositionnull2(a1[3]-64,b1[3]) && checkavailable1(a1[3]-64,b1[3]) && checkavailablepawn1(a1[3]-64,b1[3]) && checkavailablestraight1(a1[3]-64,b1[3]) && checkavailablediagonal1(a1[3]-64,b1[3]) && checkavailableking1(a1[3]-64,b1[3]))
            iRectangle(a1[3]-64,b1[3],64,64);
        if(a1[3]+64<=548 && ifpositionnull2(a1[3]+64,b1[3]) && checkavailable1(a1[3]+64,b1[3]) && checkavailablepawn1(a1[3]+64,b1[3]) && checkavailablestraight1(a1[3]+64,b1[3]) && checkavailablediagonal1(a1[3]+64,b1[3]) && checkavailableking1(a1[3]+64,b1[3]))
            iRectangle(a1[3]+64,b1[3],64,64);
        if((a1[3]==292 && b1[3]==30)&&(a1[0]==100 && b1[0]==30))
        {
            if(ifpositionnull2(a1[3]-64,30) && ifpositionnull2(a1[3]-128,30) && ifpositionnull1(a1[3]-64,30) && ifpositionnull1(a1[3]-128,30))
            {
                if(checkavailable1(a1[3]-128,30) && checkavailablepawn1(a1[3]-128,30) && checkavailablestraight1(a1[3]-128,30) && checkavailablediagonal1(a1[3]-128,30) && checkavailableking1(a1[3]-128,30) && castling==1)
                {
                    iRectangle(a1[0],b1[0],64,64);
                }
            }
        }
        if((a1[3]==292 && b1[3]==30)&&(a1[7]==548 && b1[7]==30))
        {
            if(ifpositionnull2(a1[3]+64,30) && ifpositionnull2(a1[3]+128,30) && ifpositionnull2(a1[3]+192,30) && ifpositionnull1(a1[3]+64,30) && ifpositionnull1(a1[3]+128,30) && ifpositionnull1(a1[3]+192,30))
            {
                if(checkavailable1(a1[3]+128,30) && checkavailablepawn1(a1[3]+128,30) && checkavailablestraight1(a1[3]+128,30) && checkavailablediagonal1(a1[3]+128,30) && checkavailableking1(a1[3]+128,30) && castling==1)
                {
                    iRectangle(a1[7],b1[7],64,64);
                }
            }
        }
    }
    else if(flag1[3]==2)
    {
        if(mxs==a1[3] &&  mys==b1[3]+64)
        {
            if(b1[3]+64<=478 && ifpositionnull2(mxs,mys) && checkavailable1(mxs,mys) && checkavailablepawn1(mxs,mys) && checkavailablestraight1(mxs,mys) && checkavailablediagonal1(mxs,mys) && checkavailableking1(mxs,mys))
            {
                if(ifpositionnull1(a1[3],b1[3]+64))
                {
                    b1[3]=b1[3]+64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3],b1[3]+64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3] && b2[l]==b1[3]+64)
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            b1[3]=b1[3]+64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[3] &&  mys==b1[3]-64)
        {
            if(b1[3]-64>=30 && ifpositionnull2(a1[3],b1[3]-64) && checkavailable1(a1[3],b1[3]-64) && checkavailablepawn1(a1[3],b1[3]-64) && checkavailablestraight1(a1[3],b1[3]-64) && checkavailablediagonal1(a1[3],b1[3]-64) && checkavailableking1(a1[3],b1[3]-64))
            {
                if(ifpositionnull1(a1[3],b1[3]-64))
                {
                    b1[3]=b1[3]-64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3],b1[3]-64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3] && b2[l]==b1[3]-64)
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            b1[3]=b1[3]-64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[3]-64 &&  mys==b1[3])
        {
            if(a1[3]-64>=100 && ifpositionnull2(a1[3]-64,b1[3]) && checkavailable1(a1[3]-64,b1[3]) && checkavailablepawn1(a1[3]-64,b1[3]) && checkavailablestraight1(a1[3]-64,b1[3]) && checkavailablediagonal1(a1[3]-64,b1[3]) && checkavailableking1(a1[3]-64,b1[3]))
            {
                if(ifpositionnull1(a1[3]-64,b1[3]))
                {
                    a1[3]=a1[3]-64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3]-64,b1[3]))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3]-64 && b2[l]==b1[3])
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            a1[3]=a1[3]-64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[3]+64 && mys==b1[3])
        {
            if(a1[3]+64<=548 && ifpositionnull2(a1[3]+64,b1[3]) && checkavailable1(a1[3]+64,b1[3]) && checkavailablepawn1(a1[3]+64,b1[3]) && checkavailablestraight1(a1[3]+64,b1[3]) && checkavailablediagonal1(a1[3]+64,b1[3]) && checkavailableking1(a1[3]+64,b1[3]))
            {
                if(ifpositionnull1(a1[3]+64,b1[3]))
                {
                    a1[3]=a1[3]+64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3]+64,b1[3]))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3]+64 && b2[l]==b1[3])
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            a1[3]=a1[3]+64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[3]+64 && mys==b1[3]+64)
        {
            if(a1[3]+64<=548 && b1[3]+64<=478 && ifpositionnull2(a1[3]+64,b1[3]+64) && checkavailable1(a1[3]+64,b1[3]+64) && checkavailablepawn1(a1[3]+64,b1[3]+64) && checkavailablestraight1(a1[3]+64,b1[3]+64) && checkavailablediagonal1(a1[3]+64,b1[3]+64) && checkavailableking1(a1[3]+64,b1[3]+64))
            {
                if(ifpositionnull1(a1[3]+64,b1[3]+64))
                {
                    a1[3]=a1[3]+64;
                    b1[3]=b1[3]+64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3]+64,b1[3]+64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3]+64 && b2[l]==b1[3]+64)
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            a1[3]=a1[3]+64;
                            b1[3]=b1[3]+64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[3]-64 && mys==b1[3]+64)
        {
            if(a1[3]-64>=100 && b1[3]+64<=478 && ifpositionnull2(a1[3]-64,b1[3]+64) && checkavailable1(a1[3]-64,b1[3]+64) && checkavailablepawn1(a1[3]-64,b1[3]+64) && checkavailablestraight1(a1[3]-64,b1[3]+64) && checkavailablediagonal1(a1[3]-64,b1[3]+64) && checkavailableking1(a1[3]-64,b1[3]+64))
            {
                if(ifpositionnull1(a1[3]-64,b1[3]+64))
                {
                    a1[3]=a1[3]-64;
                    b1[3]=b1[3]+64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3]-64,b1[3]+64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3]-64 && b2[l]==b1[3]+64)
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            a1[3]=a1[3]-64;
                            b1[3]=b1[3]+64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[3]-64 && mys==b1[3]-64)
        {
            if(a1[3]-64>=100 && b1[3]-64>=30 && ifpositionnull2(a1[3]-64,b1[3]-64) && checkavailable1(a1[3]-64,b1[3]-64) && checkavailablepawn1(a1[3]-64,b1[3]-64) && checkavailablestraight1(a1[3]-64,b1[3]-64) && checkavailablediagonal1(a1[3]-64,b1[3]-64) && checkavailableking1(a1[3]-64,b1[3]-64))
            {
                if(ifpositionnull1(a1[3]-64,b1[3]-64))
                {
                    a1[3]=a1[3]-64;
                    b1[3]=b1[3]-64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3]-64,b1[3]-64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3]-64 && b2[l]==b1[3]-64)
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            a1[3]=a1[3]-64;
                            b1[3]=b1[3]-64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[3]+64  && mys==b1[3]-64)
        {
            if(a1[3]+64<=548 && b1[3]-64>=30 && ifpositionnull2(a1[3]+64,b1[3]-64) && checkavailable1(a1[3]+64,b1[3]-64) && checkavailablepawn1(a1[3]+64,b1[3]-64) && checkavailablestraight1(a1[3]+64,b1[3]-64) && checkavailablediagonal1(a1[3]+64,b1[3]-64) && checkavailableking1(a1[3]+64,b1[3]-64))
            {
                if(ifpositionnull1(a1[3]+64,b1[3]-64))
                {
                    a1[3]=a1[3]+64;
                    b1[3]=b1[3]-64;
                    castling=0;
                    k=1;
                }
                else if(!ifpositionnull1(a1[3]+64,b1[3]-64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a2[l]==a1[3]+64 && b2[l]==b1[3]-64)
                        {
                            alive2[l]=1;
                            a2[l]=0;
                            b2[l]=0;
                            a1[3]=a1[3]+64;
                            b1[3]=b1[3]-64;
                            castling=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if((a1[3]==292 && b1[3]==30)&&(a1[0]==100 && b1[0]==30))
        {
            if(ifpositionnull2(a1[3]-64,mys) && ifpositionnull2(a1[3]-128,mys) && ifpositionnull1(a1[3]-64,mys) && ifpositionnull1(a1[3]-128,mys))
            {
                if(checkavailable1(a1[3]-128,mys) && checkavailablepawn1(a1[3]-128,mys) && checkavailablestraight1(a1[3]-128,mys) && checkavailablediagonal1(a1[3]-128,mys) && checkavailableking1(a1[3]-128,mys))
                {
                    if(mxs==a1[0] && mys==b1[0] && castling==1)
                    {
                        a1[3]=a1[3]-128;
                        a1[0]=a1[0]+128;
                        castling=0;
                        k=1;
                    }
                }
            }
        }
        if((a1[3]==292 && b1[3]==30)&&(a1[7]==548 && b1[7]==30))
        {
            if(ifpositionnull2(a1[3]+64,mys) && ifpositionnull2(a1[3]+128,mys) && ifpositionnull2(a1[3]+192,mys) && ifpositionnull1(a1[3]+64,mys) && ifpositionnull1(a1[3]+128,mys) && ifpositionnull1(a1[3]+192,mys))
            {
                if(checkavailable1(a1[3]+128,mys) && checkavailablepawn1(a1[3]+128,mys) && checkavailablestraight1(a1[3]+128,mys) && checkavailablediagonal1(a1[3]+128,mys) && checkavailableking1(a1[3]+128,mys))
                {
                    if(mxs==a1[7] && mys==b1[7] && castling==1)
                    {
                        a1[3]=a1[3]+128;
                        a1[7]=a1[7]-192;
                        castling=0;
                        k=1;
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[3]=0;
        }
        if(k==1)
        {
            mode1=1;
            mode2=0;
            flag1[3]=0;
            checki=0;
            co++;
            ci++;
        }
        else if(k==2)
        {
            mode1=1;
            mode2=0;
            flag1[3]=0;
            checki=0;
            co=0;
            ci++;
        }
    }
    if(flag1[3]==3)
    {
        mode1=0;
        flag1[3]=0;
    }
}

void kingo(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode2==0)
    {
        if(a>=a2[3] && a<=a2[3]+64 && b>=b2[3] && b<=b2[3]+64)
        {
            flag2[3]=1;
            f=1;
        }
    }
    if(flag2[3]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[3]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag2[3]=3;
    }
    if(f==1)
        mode2=2;
}

void drawkingo()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1;
    if(flag2[3]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[3],b2[3],64,64);
        if(b2[3]+64<=478 && ifpositionnull1(a2[3],b2[3]+64) && checkavailable2(a2[3],b2[3]+64) && checkavailablepawn2(a2[3],b2[3]+64) && checkavailablestraight2(a2[3],b2[3]+64) && checkavailablediagonal2(a2[3],b2[3]+64) && checkavailableking2(a2[3],b2[3]+64))
            iRectangle(a2[3],b2[3]+64,64,64);
        if(b2[3]-64>=30 && ifpositionnull1(a2[3],b2[3]-64) && checkavailable2(a2[3],b2[3]-64) && checkavailablepawn2(a2[3],b2[3]-64) && checkavailablestraight2(a2[3],b2[3]-64) && checkavailablediagonal2(a2[3],b2[3]-64) && checkavailableking2(a2[3],b2[3]-64))
            iRectangle(a2[3],b2[3]-64,64,64);
        if(a2[3]+64<=548 && b2[3]-64>=30 && ifpositionnull1(a2[3]+64,b2[3]-64) && checkavailable2(a2[3]+64,b2[3]-64) && checkavailablepawn2(a2[3]+64,b2[3]-64) && checkavailablestraight2(a2[3]+64,b2[3]-64) && checkavailablediagonal2(a2[3]+64,b2[3]-64) && checkavailableking2(a2[3]+64,b2[3]-64))
            iRectangle(a2[3]+64,b2[3]-64,64,64);
        if(a2[3]+64<=548 && b2[3]+64<=478 && ifpositionnull1(a2[3]+64,b2[3]+64) && checkavailable2(a2[3]+64,b2[3]+64) && checkavailablepawn2(a2[3]+64,b2[3]+64) && checkavailablestraight2(a2[3]+64,b2[3]+64) && checkavailablediagonal2(a2[3]+64,b2[3]+64) && checkavailableking2(a2[3]+64,b2[3]+64))
            iRectangle(a2[3]+64,b2[3]+64,64,64);
        if(a2[3]-64>=100 && b2[3]+64<=478 && ifpositionnull1(a2[3]-64,b2[3]+64) && checkavailable2(a2[3]-64,b2[3]+64) && checkavailablepawn2(a2[3]-64,b2[3]+64) && checkavailablestraight2(a2[3]-64,b2[3]+64) && checkavailablediagonal2(a2[3]-64,b2[3]+64) && checkavailableking2(a2[3]-64,b2[3]+64))
            iRectangle(a2[3]-64,b2[3]+64,64,64);
        if(a2[3]-64>=100 && b2[3]-64>=30 && ifpositionnull1(a2[3]-64,b2[3]-64) && checkavailable2(a2[3]-64,b2[3]-64) && checkavailablepawn2(a2[3]-64,b2[3]-64) && checkavailablestraight2(a2[3]-64,b2[3]-64) && checkavailablediagonal2(a2[3]-64,b2[3]-64) && checkavailableking2(a2[3]-64,b2[3]-64))
            iRectangle(a2[3]-64,b2[3]-64,64,64);
        if(a2[3]-64>=100 && ifpositionnull1(a2[3]-64,b2[3]) && checkavailable2(a2[3]-64,b2[3]) && checkavailablepawn2(a2[3]-64,b2[3]) && checkavailablestraight2(a2[3]-64,b2[3]) && checkavailablediagonal2(a2[3]-64,b2[3]) && checkavailableking2(a2[3]-64,b2[3]))
            iRectangle(a2[3]-64,b2[3],64,64);
        if(a2[3]+64<=548 && ifpositionnull1(a2[3]+64,b2[3]) && checkavailable2(a2[3]+64,b2[3]) && checkavailablepawn2(a2[3]+64,b2[3]) && checkavailablestraight2(a2[3]+64,b2[3]) && checkavailablediagonal2(a2[3]+64,b2[3]) && checkavailableking2(a2[3]+64,b2[3]))
            iRectangle(a2[3]+64,b2[3],64,64);
        if((a2[3]==292 && b2[3]==478)&&(a2[0]==100 && b2[0]==478))
        {
            if(ifpositionnull1(a2[3]-64,478) && ifpositionnull1(a2[3]-128,478) && ifpositionnull2(a2[3]-64,478) && ifpositionnull2(a2[3]-128,478))
            {
                if(checkavailable2(a2[3]-128,478) && checkavailablepawn2(a2[3]-128,478) && checkavailablestraight2(a2[3]-128,478) && checkavailablediagonal2(a2[3]-128,478) && checkavailableking2(a2[3]-128,478) && castling2==1)
                {
                    iRectangle(a2[0],b2[0],64,64);
                }
            }
        }
        if((a2[3]==292 && b2[3]==478)&&(a2[7]==548 && b2[7]==478))
        {
            if(ifpositionnull1(a2[3]+64,478) && ifpositionnull1(a2[3]+128,478) && ifpositionnull1(a2[3]+192,478) && ifpositionnull2(a2[3]+64,478) && ifpositionnull2(a2[3]+128,478) && ifpositionnull2(a2[3]+192,478))
            {
                if(checkavailable2(a2[3]+128,478) && checkavailablepawn2(a2[3]+128,478) && checkavailablestraight2(a2[3]+128,478) && checkavailablediagonal2(a2[3]+128,478) && checkavailableking2(a2[3]+128,478) && castling2==1)
                {
                    iRectangle(a2[7],b2[7],64,64);
                }
            }
        }
    }
    else if(flag2[3]==2)
    {
        if(mxs==a2[3] &&  mys==b2[3]+64)
        {
            if(b2[3]+64<=478 && ifpositionnull1(mxs,mys) && checkavailable2(mxs,mys) && checkavailablepawn2(mxs,mys) && checkavailablestraight2(mxs,mys) && checkavailablediagonal2(mxs,mys) && checkavailableking2(mxs,mys))

            {
                if(ifpositionnull2(a2[3],b2[3]+64))
                {
                    b2[3]=b2[3]+64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3],b2[3]+64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3] && b1[l]==b2[3]+64)
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            b2[3]=b2[3]+64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[3] &&  mys==b2[3]-64)
        {
            if(b2[3]-64>=30 && ifpositionnull1(a2[3],b2[3]-64) && checkavailable2(a2[3],b2[3]-64) && checkavailablepawn2(a2[3],b2[3]-64) && checkavailablestraight2(a2[3],b2[3]-64) && checkavailablediagonal2(a2[3],b2[3]-64) && checkavailableking2(a2[3],b2[3]-64))
            {
                if(ifpositionnull2(a2[3],b2[3]-64))
                {
                    b2[3]=b2[3]-64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3],b2[3]-64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3] && b1[l]==b2[3]-64)
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            b2[3]=b2[3]-64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[3]-64 &&  mys==b2[3])
        {
            if(a2[3]-64>=100 && ifpositionnull1(a2[3]-64,b2[3]) && checkavailable2(a2[3]-64,b2[3]) && checkavailablepawn2(a2[3]-64,b2[3]) && checkavailablestraight2(a2[3]-64,b2[3]) && checkavailablediagonal2(a2[3]-64,b2[3]) && checkavailableking2(a2[3]-64,b2[3]))

            {
                if(ifpositionnull2(a2[3]-64,b2[3]))
                {
                    a2[3]=a2[3]-64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3]-64,b2[3]))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3]-64 && b1[l]==b2[3])
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            a2[3]=a2[3]-64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[3]+64 && mys==b2[3])
        {
            if(a2[3]+64<=548 && ifpositionnull1(a2[3]+64,b2[3]) && checkavailable2(a2[3]+64,b2[3]) && checkavailablepawn2(a2[3]+64,b2[3]) && checkavailablestraight2(a2[3]+64,b2[3]) && checkavailablediagonal2(a2[3]+64,b2[3]) && checkavailableking2(a2[3]+64,b2[3]))
            {
                if(ifpositionnull2(a2[3]+64,b2[3]))
                {
                    a2[3]=a2[3]+64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3]+64,b2[3]))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3]+64 && b1[l]==b2[3])
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            a2[3]=a2[3]+64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[3]+64 && mys==b2[3]+64)
        {
            if(a2[3]+64<=548 && b2[3]+64<=478 && ifpositionnull1(a2[3]+64,b2[3]+64) && checkavailable2(a2[3]+64,b2[3]+64) && checkavailablepawn2(a2[3]+64,b2[3]+64) && checkavailablestraight2(a2[3]+64,b2[3]+64) && checkavailablediagonal2(a2[3]+64,b2[3]+64) && checkavailableking2(a2[3]+64,b2[3]+64))

            {
                if(ifpositionnull2(a2[3]+64,b2[3]+64))
                {
                    a2[3]=a2[3]+64;
                    b2[3]=b2[3]+64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3]+64,b2[3]+64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3]+64 && b1[l]==b2[3]+64)
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            a2[3]=a2[3]+64;
                            b2[3]=b2[3]+64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[3]-64 && mys==b2[3]+64)
        {
            if(a2[3]-64>=100 && b2[3]+64<=478 && ifpositionnull1(a2[3]-64,b2[3]+64) && checkavailable2(a2[3]-64,b2[3]+64) && checkavailablepawn2(a2[3]-64,b2[3]+64) && checkavailablestraight2(a2[3]-64,b2[3]+64) && checkavailablediagonal2(a2[3]-64,b2[3]+64) && checkavailableking2(a2[3]-64,b2[3]+64))
            {
                if(ifpositionnull2(a2[3]-64,b2[3]+64))
                {
                    a2[3]=a2[3]-64;
                    b2[3]=b2[3]+64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3]-64,b2[3]+64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3]-64 && b1[l]==b2[3]+64)
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            a2[3]=a2[3]-64;
                            b2[3]=b2[3]+64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[3]-64 && mys==b2[3]-64)
        {
            if(a2[3]-64>=100 && b2[3]-64>=30 && ifpositionnull1(a2[3]-64,b2[3]-64) && checkavailable2(a2[3]-64,b2[3]-64) && checkavailablepawn2(a2[3]-64,b2[3]-64) && checkavailablestraight2(a2[3]-64,b2[3]-64) && checkavailablediagonal2(a2[3]-64,b2[3]-64) && checkavailableking2(a2[3]-64,b2[3]-64))
            {
                if(ifpositionnull2(a2[3]-64,b2[3]-64))
                {
                    a2[3]=a2[3]-64;
                    b2[3]=b2[3]-64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3]-64,b2[3]-64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3]-64 && b1[l]==b2[3]-64)
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            a2[3]=a2[3]-64;
                            b2[3]=b2[3]-64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[3]+64  && mys==b2[3]-64)
        {
            if(a2[3]+64<=548 && b2[3]-64>=30 && ifpositionnull1(a2[3]+64,b2[3]-64) && checkavailable2(a2[3]+64,b2[3]-64) && checkavailablepawn2(a2[3]+64,b2[3]-64) && checkavailablestraight2(a2[3]+64,b2[3]-64) && checkavailablediagonal2(a2[3]+64,b2[3]-64) && checkavailableking2(a2[3]+64,b2[3]-64))
            {
                if(ifpositionnull2(a2[3]+64,b2[3]-64))
                {
                    a2[3]=a2[3]+64;
                    b2[3]=b2[3]-64;
                    castling2=0;
                    k=1;
                }
                else if(!ifpositionnull2(a2[3]+64,b2[3]-64))
                {
                    for(l=0; l<16; l++)
                    {
                        if(a1[l]==a2[3]+64 && b1[l]==b2[3]-64)
                        {
                            alive1[l]=1;
                            a1[l]=0;
                            b1[l]=0;
                            a2[3]=a2[3]+64;
                            b2[3]=b2[3]-64;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if((a2[3]==292 && b2[3]==478)&&(a2[0]==100 && b2[0]==478))
        {
            if(ifpositionnull1(a2[3]-64,mys) && ifpositionnull1(a2[3]-128,mys) && ifpositionnull2(a2[3]-64,mys) && ifpositionnull2(a2[3]-128,mys))
            {
                if(checkavailable2(a2[3]-128,mys) && checkavailablepawn2(a2[3]-128,mys) && checkavailablestraight2(a2[3]-128,mys) && checkavailablediagonal2(a2[3]-128,mys) && checkavailableking2(a2[3]-128,mys))
                {
                    if(mxs==a2[0] && mys==b2[0] && castling2==1)
                    {
                        a2[3]=a2[3]-128;
                        a2[0]=a2[0]+128;
                        castling2=0;
                        k=1;
                    }
                }
            }
        }
        if((a2[3]==292 && b2[3]==478)&&(a2[7]==548 && b2[7]==478))
        {
            if(ifpositionnull1(a2[3]+64,mys) && ifpositionnull1(a2[3]+128,mys) && ifpositionnull1(a2[3]+192,mys) && ifpositionnull2(a2[3]+64,mys) && ifpositionnull2(a2[3]+128,mys) && ifpositionnull2(a2[3]+192,mys))
            {
                if(checkavailable2(a2[3]+128,mys) && checkavailablepawn2(a2[3]+128,mys) && checkavailablestraight2(a2[3]+128,mys) && checkavailablediagonal2(a2[3]+128,mys) && checkavailableking1(a2[3]+128,mys))
                {
                    if(mxs==a2[7] && mys==b2[7] && castling2==1)
                    {
                        a2[3]=a2[3]+128;
                        a2[7]=a2[7]-192;
                        castling2=0;
                        k=1;
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[3]=0;
        }
        if(k==1)
        {
            flag2[3]=0;
            mode1=0;
            mode2=1;
            checko=0;
            co++;
            ci++;
        }
        else if(k==2)
        {
            flag2[3]=0;
            mode1=0;
            mode2=1;
            checko=0;
            co=0;
            ci++;
        }
    }
    if(flag2[3]==3)
    {
        mode2=0;
        flag2[3]=0;
    }
}

void queeni(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode1==0)
    {
        if(a>=a1[4] && a<=a1[4]+64 && b>=b1[4] && b<=b1[4]+64)
        {
            flag1[4]=1;
            f=1;
        }
    }
    if(flag1[4]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[4]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[4]=3;
    }
    if(f==1)
        mode1=2;
}

void drawqueeni()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a1[4];
    idx2=b1[4];
    if(flag1[4]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[4],b1[4],64,64);
        while(a1[4]+cnt<=548 && b1[4]+cnt<=478)
        {
            if(ifpositionnull2(a1[4]+cnt,b1[4]+cnt))
            {
                iRectangle(a1[4]+cnt,b1[4]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]+cnt,b1[4]+cnt)))
                break;
            if(!(ifpositionnull1(a1[4]+cnt,b1[4]+cnt)))
            {
                iRectangle(a1[4]+cnt,b1[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]-cnt>=100 && b1[4]+cnt<=478)
        {
            if(ifpositionnull2(a1[4]-cnt,b1[4]+cnt))
            {
                iRectangle(a1[4]-cnt,b1[4]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]-cnt,b1[4]+cnt)))
                break;
            if(!(ifpositionnull1(a1[4]-cnt,b1[4]+cnt)))
            {
                iRectangle(a1[4]-cnt,b1[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]-cnt>=100 && b1[4]-cnt>=30)
        {
            if(ifpositionnull2(a1[4]-cnt,b1[4]-cnt))
            {
                iRectangle(a1[4]-cnt,b1[4]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]-cnt,b1[4]-cnt)))
                break;
            if(!(ifpositionnull1(a1[4]-cnt,b1[4]-cnt)))
            {
                iRectangle(a1[4]-cnt,b1[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]+cnt<=548 && b1[4]-cnt>=30)
        {
            if(ifpositionnull2(a1[4]+cnt,b1[4]-cnt))
            {
                iRectangle(a1[4]+cnt,b1[4]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]+cnt,b1[4]-cnt)))
                break;
            if(!(ifpositionnull1(a1[4]+cnt,b1[4]-cnt)))
            {
                iRectangle(a1[4]+cnt,b1[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[4]+cnt<=478)
        {
            if(ifpositionnull2(a1[4],b1[4]+cnt))
            {
                iRectangle(a1[4],b1[4]+cnt,64,64);
            }
            if(!((ifpositionnull2(a1[4],b1[4]+cnt)))) break;
            if(!(ifpositionnull1(a1[4],b1[4]+cnt)))
            {
                iRectangle(a1[4],b1[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[4]-cnt>=30)
        {
            if(ifpositionnull2(a1[4],b1[4]-cnt))
            {
                iRectangle(a1[4],b1[4]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4],b1[4]-cnt))) break;
            if(!(ifpositionnull1(a1[4],b1[4]-cnt)))
            {
                iRectangle(a1[4],b1[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]+cnt<=548)
        {
            if(ifpositionnull2(a1[4]+cnt,b1[4]))
            {
                iRectangle(a1[4]+cnt,b1[4],64,64);
            }
            if(!(ifpositionnull2(a1[4]+cnt,b1[4]))) break;
            if(!(ifpositionnull1(a1[4]+cnt,b1[4])))
            {
                iRectangle(a1[4]+cnt,b1[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]-cnt>=100)
        {
            if(ifpositionnull2(a1[4]-cnt,b1[4]))
            {
                iRectangle(a1[4]-cnt,b1[4],64,64);
            }
            if(!(ifpositionnull2(a1[4]-cnt,b1[4]))) break;
            if(!(ifpositionnull1(a1[4]-cnt,b1[4])))
            {
                iRectangle(a1[4]-cnt,b1[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag1[4]==2)
    {
        cnt=64;
        if(colouring(a1[4],b1[4]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[4],b1[4],64,64);
        while(a1[4]+cnt<=548 && b1[4]+cnt<=478)
        {
            if(ifpositionnull2(a1[4]+cnt,b1[4]+cnt))
            {
                if(colouring(a1[4]+cnt,b1[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[4]+cnt,b1[4]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]+cnt,b1[4]+cnt)))
                break;
            if(!(ifpositionnull1(a1[4]+cnt,b1[4]+cnt)))
            {
                if(colouring(a1[4]+cnt,b1[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[4]+cnt,b1[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]-cnt>=100 && b1[4]+cnt<=478)
        {
            if(ifpositionnull2(a1[4]-cnt,b1[4]+cnt))
            {
                if(colouring(a1[4]-cnt,b1[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[4]-cnt,b1[4]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]-cnt,b1[4]+cnt)))
                break;
            if(!(ifpositionnull1(a1[4]-cnt,b1[4]+cnt)))
            {
                if(colouring(a1[4]-cnt,b1[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[4]-cnt,b1[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]-cnt>=100 && b1[4]-cnt>=30)
        {
            if(ifpositionnull2(a1[4]-cnt,b1[4]-cnt))
            {
                if(colouring(a1[4]-cnt,b1[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[4]-cnt,b1[4]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]-cnt,b1[4]-cnt)))
                break;
            if(!(ifpositionnull1(a1[4]-cnt,b1[4]-cnt)))
            {
                if(colouring(a1[4]-cnt,b1[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]+cnt<=548 && b1[4]-cnt>=30)
        {
            if(ifpositionnull2(a1[4]+cnt,b1[4]-cnt))
            {
                if(colouring(a1[4]+cnt,b1[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[4]+cnt,b1[4]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4]+cnt,b1[4]-cnt)))
                break;
            if(!(ifpositionnull1(a1[4]+cnt,b1[4]-cnt)))
            {
                if(colouring(a1[4]+cnt,b1[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[4]+cnt,b1[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[4]+cnt<=478)
        {
            if(ifpositionnull2(a1[4],b1[4]+cnt))
            {
                if(colouring(a1[4],b1[4]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4],b1[4]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4],b1[4]+cnt))) break;
            if(!(ifpositionnull1(a1[4],b1[4]+cnt)))
            {
                if(colouring(a1[4],b1[4]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4],b1[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[4]-cnt>=30)
        {
            if(ifpositionnull2(a1[4],b1[4]-cnt))
            {
                if(colouring(a1[4],b1[4]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4],b1[4]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[4],b1[4]-cnt))) break;
            if(!(ifpositionnull1(a1[4],b1[4]-cnt)))
            {
                if(colouring(a1[4],b1[4]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4],b1[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]+cnt<=548)
        {
            if(ifpositionnull2(a1[4]+cnt,b1[4]))
            {
                if(colouring(a1[4]+cnt,b1[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4]+cnt,b1[4],64,64);
            }
            if(!(ifpositionnull2(a1[4]+cnt,b1[4]))) break;
            if(!(ifpositionnull1(a1[4]+cnt,b1[4])))
            {
                if(colouring(a1[4]+cnt,b1[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4]+cnt,b1[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[4]-cnt>=100)
        {
            if(ifpositionnull2(a1[4]-cnt,b1[4]))
            {
                if(colouring(a1[4]-cnt,b1[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4]-cnt,b1[4],64,64);
            }
            if(!(ifpositionnull2(a1[4]-cnt,b1[4]))) break;
            if(!(ifpositionnull1(a1[4]-cnt,b1[4])))
            {
                if(colouring(a1[4]-cnt,b1[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[4]-cnt,b1[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b1[4];
        c2=mxs-a1[4];
        cnt=64;
        if(mxs==a1[4] && c1>0 && c1%64==0)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[4]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[4],b1[4]+cnt) || !ifpositionnull2(a1[4],b1[4]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[4]=b1[4]+c1;
                    k=1;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[4]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[4],b1[4]+cnt) || !ifpositionnull2(a1[4],b1[4]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[4]=b1[4]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[4] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[4]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[4],b1[4]-cnt) || !ifpositionnull2(a1[4],b1[4]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        b1[4]=b1[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[4]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[4],b1[4]-cnt) || !ifpositionnull2(a1[4],b1[4]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[4]=b1[4]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[4] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[4]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[4]+cnt,b1[4]) || !ifpositionnull2(a1[4]+cnt,b1[4]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[4]=a1[4]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[4]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[4]+cnt,b1[4]) || !ifpositionnull2(a1[4]+cnt,b1[4]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[4]=a1[4]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[4] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[4]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[4]-cnt,b1[4]) || !ifpositionnull2(a1[4]-cnt,b1[4]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[4]=a1[4]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[4]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[4]-cnt,b1[4]) || !ifpositionnull2(a1[4]-cnt,b1[4]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[4]=a1[4]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[4]+cnt!=mxs) && (b1[4]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[4]+cnt,b1[4]+cnt) || !ifpositionnull2(a1[4]+cnt,b1[4]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[4]=b1[4]+c1;
                    a1[4]=a1[4]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((b1[4]+cnt!=mys) && (a1[4]+cnt!=mxs))
                {
                    if(!ifpositionnull1(a1[4]+cnt,b1[4]+cnt) || !ifpositionnull2(a1[4]+cnt,b1[4]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a1[4]=a1[4]+c2;
                            b1[4]=b1[4]+c1;
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && c1==-c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[4]-cnt!=mxs) && (b1[4]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[4]-cnt,b1[4]+cnt) || !ifpositionnull2(a1[4]-cnt,b1[4]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[4]=a1[4]+c2;
                        b1[4]=b1[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[4]-cnt !=mxs) && (b1[4]+cnt !=mys))
                {
                    if(!ifpositionnull1(a1[4]-cnt,b1[4]+cnt) || !ifpositionnull2(a1[4]-cnt,b1[4]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[4]=a1[4]+c2;
                            b1[4]=b1[4]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[4]-cnt!=mxs) && (b1[4]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[4]-cnt,b1[4]-cnt) || !ifpositionnull2(a1[4]-cnt,b1[4]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[4]=a1[4]+c2;
                        b1[4]=b1[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[4]-cnt !=mxs) && (b1[4]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[4]-cnt,b1[4]-cnt) || !ifpositionnull2(a1[4]-cnt,b1[4]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[4]=a1[4]+c2;
                            b1[4]=b1[4]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[4]+cnt!=mxs) && (b1[4]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[4]+cnt,b1[4]-cnt) || !ifpositionnull2(a1[4]+cnt,b1[4]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[4]=a1[4]+c2;
                        b1[4]=b1[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                while((a1[4]+cnt !=mxs) && (b1[4]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[4]+cnt,b1[4]-cnt) || !ifpositionnull2(a1[4]+cnt,b1[4]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[4]=a1[4]+c2;
                            b1[4]=b1[4]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[4]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[4]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[4]=idx1;
            b1[4]=idx2;
            flag1[4]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[4]=idx1;
            b1[4]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[4]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[4]==3)
    {
        mode1=0;
        flag1[4]=0;
    }
}

void queeno(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode2==0)
    {
        if(a>=a2[4] && a<=a2[4]+64 && b>=b2[4] && b<=b2[4]+64)
        {
            flag2[4]=1;
            f=1;
        }
    }
    if(flag2[4]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[4]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag2[4]=3;
    }
    if(f==1)
        mode2=2;

}

void drawqueeno()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a2[4];
    idx2=b2[4];
    if(flag2[4]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[4],b2[4],64,64);
        while(a2[4]+cnt<=548 && b2[4]+cnt<=478)
        {
            if(ifpositionnull1(a2[4]+cnt,b2[4]+cnt))
            {
                iRectangle(a2[4]+cnt,b2[4]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]+cnt,b2[4]+cnt)))
                break;
            if(!(ifpositionnull2(a2[4]+cnt,b2[4]+cnt)))
            {
                iRectangle(a2[4]+cnt,b2[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]-cnt>=100 && b2[4]+cnt<=478)
        {
            if(ifpositionnull1(a2[4]-cnt,b2[4]+cnt))
            {
                iRectangle(a2[4]-cnt,b2[4]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]-cnt,b2[4]+cnt)))
                break;
            if(!(ifpositionnull2(a2[4]-cnt,b2[4]+cnt)))
            {
                iRectangle(a2[4]-cnt,b2[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]-cnt>=100 && b2[4]-cnt>=30)
        {
            if(ifpositionnull1(a2[4]-cnt,b2[4]-cnt))
            {
                iRectangle(a2[4]-cnt,b2[4]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]-cnt,b2[4]-cnt)))
                break;
            if(!(ifpositionnull2(a2[4]-cnt,b2[4]-cnt)))
            {
                iRectangle(a2[4]-cnt,b2[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]+cnt<=548 && b2[4]-cnt>=30)
        {
            if(ifpositionnull1(a2[4]+cnt,b2[4]-cnt))
            {
                iRectangle(a2[4]+cnt,b2[4]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]+cnt,b2[4]-cnt)))
                break;
            if(!(ifpositionnull2(a2[4]+cnt,b2[4]-cnt)))
            {
                iRectangle(a2[4]+cnt,b2[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[4]+cnt<=478)
        {
            if(ifpositionnull1(a2[4],b2[4]+cnt))
            {
                iRectangle(a2[4],b2[4]+cnt,64,64);
            }
            if(!((ifpositionnull1(a2[4],b2[4]+cnt)))) break;
            if(!(ifpositionnull2(a2[4],b2[4]+cnt)))
            {
                iRectangle(a2[4],b2[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[4]-cnt>=30)
        {
            if(ifpositionnull1(a2[4],b2[4]-cnt))
            {
                iRectangle(a2[4],b2[4]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4],b2[4]-cnt))) break;
            if(!(ifpositionnull2(a2[4],b2[4]-cnt)))
            {
                iRectangle(a2[4],b2[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]+cnt<=548)
        {
            if(ifpositionnull1(a2[4]+cnt,b2[4]))
            {
                iRectangle(a2[4]+cnt,b2[4],64,64);
            }
            if(!(ifpositionnull1(a2[4]+cnt,b2[4]))) break;
            if(!(ifpositionnull2(a2[4]+cnt,b2[4])))
            {
                iRectangle(a2[4]+cnt,b2[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]-cnt>=100)
        {
            if(ifpositionnull1(a2[4]-cnt,b2[4]))
            {
                iRectangle(a2[4]-cnt,b2[4],64,64);
            }
            if(!(ifpositionnull1(a2[4]-cnt,b2[4]))) break;
            if(!(ifpositionnull2(a2[4]-cnt,b2[4])))
            {
                iRectangle(a2[4]-cnt,b2[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag2[4]==2)
    {
        cnt=64;
        if(colouring(a2[4],b2[4]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[4],b2[4],64,64);
        while(a2[4]+cnt<=548 && b2[4]+cnt<=478)
        {
            if(ifpositionnull1(a2[4]+cnt,b2[4]+cnt))
            {
                if(colouring(a2[4]+cnt,b2[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[4]+cnt,b2[4]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]+cnt,b2[4]+cnt)))
                break;
            if(!(ifpositionnull2(a2[4]+cnt,b2[4]+cnt)))
            {
                if(colouring(a2[4]+cnt,b2[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[4]+cnt,b2[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]-cnt>=100 && b2[4]+cnt<=478)
        {
            if(ifpositionnull1(a2[4]-cnt,b2[4]+cnt))
            {
                if(colouring(a2[4]-cnt,b2[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[4]-cnt,b2[4]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]-cnt,b2[4]+cnt)))
                break;
            if(!(ifpositionnull2(a2[4]-cnt,b2[4]+cnt)))
            {
                if(colouring(a2[4]-cnt,b2[4]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[4]-cnt,b2[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]-cnt>=100 && b2[4]-cnt>=30)
        {
            if(ifpositionnull1(a2[4]-cnt,b2[4]-cnt))
            {
                if(colouring(a2[4]-cnt,b2[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[4]-cnt,b2[4]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]-cnt,b2[4]-cnt)))
                break;
            if(!(ifpositionnull2(a2[4]-cnt,b2[4]-cnt)))
            {
                if(colouring(a2[4]-cnt,b2[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]+cnt<=548 && b2[4]-cnt>=30)
        {
            if(ifpositionnull1(a2[4]+cnt,b2[4]-cnt))
            {
                if(colouring(a2[4]+cnt,b2[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[4]+cnt,b2[4]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4]+cnt,b2[4]-cnt)))
                break;
            if(!(ifpositionnull2(a2[4]+cnt,b2[4]-cnt)))
            {
                if(colouring(a2[4]+cnt,b2[4]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[4]+cnt,b2[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[4]+cnt<=478)
        {
            if(ifpositionnull1(a2[4],b2[4]+cnt))
            {
                if(colouring(a2[4],b2[4]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4],b2[4]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4],b2[4]+cnt))) break;
            if(!(ifpositionnull2(a2[4],b2[4]+cnt)))
            {
                if(colouring(a2[4],b2[4]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4],b2[4]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[4]-cnt>=30)
        {
            if(ifpositionnull1(a2[4],b2[4]-cnt))
            {
                if(colouring(a2[4],b2[4]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4],b2[4]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[4],b2[4]-cnt))) break;
            if(!(ifpositionnull2(a2[4],b2[4]-cnt)))
            {
                if(colouring(a2[4],b2[4]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4],b2[4]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]+cnt<=548)
        {
            if(ifpositionnull1(a2[4]+cnt,b2[4]))
            {
                if(colouring(a2[4]+cnt,b2[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4]+cnt,b2[4],64,64);
            }
            if(!(ifpositionnull1(a2[4]+cnt,b2[4]))) break;
            if(!(ifpositionnull2(a2[4]+cnt,b2[4])))
            {
                if(colouring(a2[4]+cnt,b2[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4]+cnt,b2[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[4]-cnt>=100)
        {
            if(ifpositionnull1(a2[4]-cnt,b2[4]))
            {
                if(colouring(a2[4]-cnt,b2[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4]-cnt,b2[4],64,64);
            }
            if(!(ifpositionnull1(a2[4]-cnt,b2[4]))) break;
            if(!(ifpositionnull2(a2[4]-cnt,b2[4])))
            {
                if(colouring(a2[4]-cnt,b2[4])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[4]-cnt,b2[4],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b2[4];
        c2=mxs-a2[4];
        cnt=64;
        if(mxs==a2[4] && c1>0 && c1%64==0)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[4]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[4],b2[4]+cnt) || !ifpositionnull1(a2[4],b2[4]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[4]=b2[4]+c1;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[4]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[4],b2[4]+cnt) || !ifpositionnull1(a2[4],b2[4]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            b2[4]=b2[4]+c1;
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[4] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[4]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[4],b2[4]-cnt) || !ifpositionnull1(a2[4],b2[4]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        b2[4]=b2[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[4]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[4],b2[4]-cnt) || !ifpositionnull1(a2[4],b2[4]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            b2[4]=b2[4]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[4] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[4]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[4]+cnt,b2[4]) || !ifpositionnull1(a2[4]+cnt,b2[4]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[4]=a2[4]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[4]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[4]+cnt,b2[4]) || !ifpositionnull1(a2[4]+cnt,b2[4]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[4]=a2[4]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[4] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[4]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[4]-cnt,b2[4]) || !ifpositionnull1(a2[4]-cnt,b2[4]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[4]=a2[4]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[4]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[4]-cnt,b2[4]) || !ifpositionnull1(a2[4]-cnt,b2[4]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[4]=a2[4]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[4]+cnt!=mxs) && (b2[4]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[4]+cnt,b2[4]+cnt) || !ifpositionnull1(a2[4]+cnt,b2[4]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[4]=b2[4]+c1;
                    a2[4]=a2[4]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((b2[4]+cnt!=mys) && (a2[4]+cnt!=mxs))
                {
                    if(!ifpositionnull2(a2[4]+cnt,b2[4]+cnt) || !ifpositionnull1(a2[4]+cnt,b2[4]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a2[4]=a2[4]+c2;
                            b2[4]=b2[4]+c1;
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && c1==-c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[4]-cnt!=mxs) && (b2[4]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[4]-cnt,b2[4]+cnt) || !ifpositionnull1(a2[4]-cnt,b2[4]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[4]=a2[4]+c2;
                        b2[4]=b2[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                while((a2[4]-cnt !=mxs) && (b2[4]+cnt !=mys))
                {
                    if(!ifpositionnull2(a2[4]-cnt,b2[4]+cnt) || !ifpositionnull1(a2[4]-cnt,b2[4]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }

                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[4]=a2[4]+c2;
                            b2[4]=b2[4]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[4]-cnt!=mxs) && (b2[4]-cnt!=mys))
                {
                    if(!ifpositionnull2(a2[4]-cnt,b2[4]-cnt) || !ifpositionnull1(a2[4]-cnt,b2[4]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[4]=a2[4]+c2;
                        b2[4]=b2[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                while((a2[4]-cnt !=mxs) && (b2[4]-cnt !=mys))
                {
                    if(!ifpositionnull2(a2[4]-cnt,b2[4]-cnt) || !ifpositionnull1(a2[4]-cnt,b2[4]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[4]=a2[4]+c2;
                            b2[4]=b2[4]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[4]+cnt!=mxs) && (b2[4]-cnt!=mys))
                {
                    if(!ifpositionnull2(a2[4]+cnt,b2[4]-cnt) || !ifpositionnull1(a2[4]+cnt,b2[4]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[4]=a2[4]+c2;
                        b2[4]=b2[4]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                while((a2[4]+cnt !=mxs) && (b2[4]-cnt !=mys))
                {
                    if(!ifpositionnull2(a2[4]+cnt,b2[4]-cnt) || !ifpositionnull1(a2[4]+cnt,b2[4]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[4]=a2[4]+c2;
                            b2[4]=b2[4]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[4]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[4]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[4]=idx1;
            b2[4]=idx2;
            flag2[4]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[4]=idx1;
            b2[4]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[4]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[4]==3)
    {
        mode2=0;
        flag2[4]=0;
    }

}

void elephanti1(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode1==0)
    {
        if(a>=a1[2] && a<=a1[2]+64 && b>=b1[2] && b<=b1[2]+64)
        {
            flag1[2]=1;
            f=1;
        }
    }
    if(flag1[2]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[2]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[2]=3;
    }
    if(f==1)
        mode1=2;
}

void drawelephanti1()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a1[2];
    idx2=b1[2];
    if(flag1[2]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[2],b1[2],64,64);
        while(a1[2]+cnt<=548 && b1[2]+cnt<=478)
        {
            if(ifpositionnull2(a1[2]+cnt,b1[2]+cnt))
            {
                iRectangle(a1[2]+cnt,b1[2]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]+cnt,b1[2]+cnt)))
                break;
            if(!(ifpositionnull1(a1[2]+cnt,b1[2]+cnt)))
            {
                iRectangle(a1[2]+cnt,b1[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[2]-cnt>=100 && b1[2]+cnt<=478)
        {
            if(ifpositionnull2(a1[2]-cnt,b1[2]+cnt))
            {
                iRectangle(a1[2]-cnt,b1[2]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]-cnt,b1[2]+cnt)))
                break;
            if(!(ifpositionnull1(a1[2]-cnt,b1[2]+cnt)))
            {
                iRectangle(a1[2]-cnt,b1[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[2]-cnt>=100 && b1[2]-cnt>=30)
        {
            if(ifpositionnull2(a1[2]-cnt,b1[2]-cnt))
            {
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]-cnt,b1[2]-cnt)))
                break;
            if(!(ifpositionnull1(a1[2]-cnt,b1[2]-cnt)))
            {
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[2]+cnt<=548 && b1[2]-cnt>=30)
        {
            if(ifpositionnull2(a1[2]+cnt,b1[2]-cnt))
            {
                iRectangle(a1[2]+cnt,b1[2]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]+cnt,b1[2]-cnt)))
                break;
            if(!(ifpositionnull1(a1[2]+cnt,b1[2]-cnt)))
            {
                iRectangle(a1[2]+cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag1[2]==2)
    {
        cnt=64;
        if(colouring(a1[2],b1[2]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[2],b1[2],64,64);
        while(a1[2]+cnt<=548 && b1[2]+cnt<=478)
        {
            if(ifpositionnull2(a1[2]+cnt,b1[2]+cnt))
            {
                if(colouring(a1[2]+cnt,b1[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]+cnt,b1[2]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]+cnt,b1[2]+cnt)))
                break;
            if(!(ifpositionnull1(a1[2]+cnt,b1[2]+cnt)))
            {
                if(colouring(a1[2]+cnt,b1[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]+cnt,b1[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[2]-cnt>=100 && b1[2]+cnt<=478)
        {
            if(ifpositionnull2(a1[2]-cnt,b1[2]+cnt))
            {
                if(colouring(a1[2]-cnt,b1[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]-cnt,b1[2]+cnt)))
                break;
            if(!(ifpositionnull1(a1[2]-cnt,b1[2]+cnt)))
            {
                if(colouring(a1[2]-cnt,b1[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[2]-cnt>=100 && b1[2]-cnt>=30)
        {
            if(ifpositionnull2(a1[2]-cnt,b1[2]-cnt))
            {
                if(colouring(a1[2]-cnt,b1[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]-cnt,b1[2]-cnt)))
                break;
            if(!(ifpositionnull1(a1[2]-cnt,b1[2]-cnt)))
            {
                if(colouring(a1[2]-cnt,b1[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[2]+cnt<=548 && b1[2]-cnt>=30)
        {
            if(ifpositionnull2(a1[2]+cnt,b1[2]-cnt))
            {
                if(colouring(a1[2]+cnt,b1[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]+cnt,b1[2]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[2]+cnt,b1[2]-cnt)))
                break;
            if(!(ifpositionnull1(a1[2]+cnt,b1[2]-cnt)))
            {
                if(colouring(a1[2]+cnt,b1[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]+cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b1[2];
        c2=mxs-a1[2];
        cnt=64;
        if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[2]+cnt!=mxs) && (b1[2]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[2]+cnt,b1[2]+cnt) || !ifpositionnull2(a1[2]+cnt,b1[2]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[2]=b1[2]+c1;
                    a1[2]=a1[2]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((b1[2]+cnt!=mys) && (a1[2]+cnt!=mxs))
                {
                    if(!ifpositionnull1(a1[2]+cnt,b1[2]+cnt) || !ifpositionnull2(a1[2]+cnt,b1[2]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            a1[2]=a1[2]+c2;
                            b1[2]=b1[2]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && c1==-c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[2]-cnt!=mxs) && (b1[2]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[2]-cnt,b1[2]+cnt) || !ifpositionnull2(a1[2]-cnt,b1[2]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[2]=a1[2]+c2;
                        b1[2]=b1[2]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[2]-cnt !=mxs) && (b1[2]+cnt !=mys))
                {
                    if(!ifpositionnull1(a1[2]-cnt,b1[2]+cnt) || !ifpositionnull2(a1[2]-cnt,b1[2]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[2]=a1[2]+c2;
                            b1[2]=b1[2]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[2]-cnt!=mxs) && (b1[2]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[2]-cnt,b1[2]-cnt) || !ifpositionnull2(a1[2]-cnt,b1[2]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[2]=a1[2]+c2;
                        b1[2]=b1[2]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                while((a1[2]-cnt !=mxs) && (b1[2]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[2]-cnt,b1[2]-cnt) || !ifpositionnull2(a1[2]-cnt,b1[2]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[2]=a1[2]+c2;
                            b1[2]=b1[2]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[2]+cnt!=mxs) && (b1[2]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[2]+cnt,b1[2]-cnt) || !ifpositionnull2(a1[2]+cnt,b1[2]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[2]=a1[2]+c2;
                        b1[2]=b1[2]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                while((a1[2]+cnt !=mxs) && (b1[2]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[2]+cnt,b1[2]-cnt) || !ifpositionnull2(a1[2]+cnt,b1[2]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[2]=a1[2]+c2;
                            b1[2]=b1[2]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[2]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[2]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[2]=idx1;
            b1[2]=idx2;
            flag1[2]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[2]=idx1;
            b1[2]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[2]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[2]==3)
    {
        mode1=0;
        flag1[2]=0;
    }
}

void elephanti2(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode1==0)
    {
        if(a>=a1[5] && a<=a1[5]+64 && b>=b1[5] && b<=b1[5]+64)
        {
            flag1[5]=1;
            f=1;
        }
    }
    if(flag1[5]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[5]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[5]=3;
    }
    if(f==1)
        mode1=2;
}

void drawelephanti2()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a1[5];
    idx2=b1[5];
    if(flag1[5]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[5],b1[5],64,64);
        while(a1[5]+cnt<=548 && b1[5]+cnt<=478)
        {
            if(ifpositionnull2(a1[5]+cnt,b1[5]+cnt))
            {
                iRectangle(a1[5]+cnt,b1[5]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]+cnt,b1[5]+cnt)))
                break;
            if(!(ifpositionnull1(a1[5]+cnt,b1[5]+cnt)))
            {
                iRectangle(a1[5]+cnt,b1[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[5]-cnt>=100 && b1[5]+cnt<=478)
        {
            if(ifpositionnull2(a1[5]-cnt,b1[5]+cnt))
            {
                iRectangle(a1[5]-cnt,b1[5]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]-cnt,b1[5]+cnt)))
                break;
            if(!(ifpositionnull1(a1[5]-cnt,b1[5]+cnt)))
            {
                iRectangle(a1[5]-cnt,b1[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[5]-cnt>=100 && b1[5]-cnt>=30)
        {
            if(ifpositionnull2(a1[5]-cnt,b1[5]-cnt))
            {
                iRectangle(a1[5]-cnt,b1[5]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]-cnt,b1[5]-cnt)))
                break;
            if(!(ifpositionnull1(a1[5]-cnt,b1[5]-cnt)))
            {
                iRectangle(a1[5]-cnt,b1[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[5]+cnt<=548 && b1[5]-cnt>=30)
        {
            if(ifpositionnull2(a1[5]+cnt,b1[5]-cnt))
            {
                iRectangle(a1[5]+cnt,b1[5]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]+cnt,b1[5]-cnt)))
                break;
            if(!(ifpositionnull1(a1[5]+cnt,b1[5]-cnt)))
            {
                iRectangle(a1[5]+cnt,b1[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag1[5]==2)
    {
        cnt=64;
        if(colouring(a1[5],b1[5]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[5],b1[5],64,64);
        while(a1[5]+cnt<=548 && b1[5]+cnt<=478)
        {
            if(ifpositionnull2(a1[5]+cnt,b1[5]+cnt))
            {
                if(colouring(a1[5]+cnt,b1[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]+cnt,b1[5]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]+cnt,b1[5]+cnt)))
                break;
            if(!(ifpositionnull1(a1[5]+cnt,b1[5]+cnt)))
            {
                if(colouring(a1[5]+cnt,b1[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]+cnt,b1[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[5]-cnt>=100 && b1[5]+cnt<=478)
        {
            if(ifpositionnull2(a1[5]-cnt,b1[5]+cnt))
            {
                if(colouring(a1[5]-cnt,b1[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]-cnt,b1[5]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]-cnt,b1[5]+cnt)))
                break;
            if(!(ifpositionnull1(a1[5]-cnt,b1[5]+cnt)))
            {
                if(colouring(a1[5]-cnt,b1[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]-cnt,b1[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[5]-cnt>=100 && b1[5]-cnt>=30)
        {
            if(ifpositionnull2(a1[5]-cnt,b1[5]-cnt))
            {
                if(colouring(a1[5]-cnt,b1[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]-cnt,b1[5]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]-cnt,b1[5]-cnt)))
                break;
            if(!(ifpositionnull1(a1[5]-cnt,b1[5]-cnt)))
            {
                if(colouring(a1[5]-cnt,b1[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]-cnt,b1[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[5]+cnt<=548 && b1[5]-cnt>=30)
        {
            if(ifpositionnull2(a1[5]+cnt,b1[5]-cnt))
            {
                if(colouring(a1[5]+cnt,b1[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]+cnt,b1[5]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[5]+cnt,b1[5]-cnt)))
                break;
            if(!(ifpositionnull1(a1[5]+cnt,b1[5]-cnt)))
            {
                if(colouring(a1[5]+cnt,b1[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[5]+cnt,b1[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b1[5];
        c2=mxs-a1[5];
        cnt=64;
        if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[5]+cnt!=mxs) && (b1[5]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[5]+cnt,b1[5]+cnt) || !ifpositionnull2(a1[5]+cnt,b1[5]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[5]=b1[5]+c1;
                    a1[5]=a1[5]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((b1[5]+cnt!=mys) && (a1[5]+cnt!=mxs))
                {
                    if(!ifpositionnull1(a1[5]+cnt,b1[5]+cnt) || !ifpositionnull2(a1[5]+cnt,b1[5]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a1[5]=a1[5]+c2;
                            b1[5]=b1[5]+c1;
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[5]-cnt!=mxs) && (b1[5]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[5]-cnt,b1[5]+cnt) || !ifpositionnull2(a1[5]-cnt,b1[5]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[5]=a1[5]+c2;
                        b1[5]=b1[5]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[5]-cnt !=mxs) && (b1[5]+cnt !=mys))
                {
                    if(!ifpositionnull1(a1[5]-cnt,b1[5]+cnt) || !ifpositionnull2(a1[5]-cnt,b1[5]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[5]=a1[5]+c2;
                            b1[5]=b1[5]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[5]-cnt!=mxs) && (b1[5]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[5]-cnt,b1[5]-cnt) || !ifpositionnull2(a1[5]-cnt,b1[5]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[5]=a1[5]+c2;
                        b1[5]=b1[5]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[5]-cnt !=mxs) && (b1[5]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[5]-cnt,b1[5]-cnt) || !ifpositionnull2(a1[5]-cnt,b1[5]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[5]=a1[5]+c2;
                            b1[5]=b1[5]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[5]+cnt!=mxs) && (b1[5]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[5]+cnt,b1[5]-cnt) || !ifpositionnull2(a1[5]+cnt,b1[5]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[5]=a1[5]+c2;
                        b1[5]=b1[5]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[5]+cnt !=mxs) && (b1[5]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[5]+cnt,b1[5]-cnt) || !ifpositionnull2(a1[5]+cnt,b1[5]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[5]=a1[5]+c2;
                            b1[5]=b1[5]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[5]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[5]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[5]=idx1;
            b1[5]=idx2;
            flag1[5]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[5]=idx1;
            b1[5]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[5]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[5]==3)
    {
        mode1=0;
        flag1[5]=0;
    }
}

void elephanto1(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode2==0)
    {
        if(a>=a2[2] && a<=a2[2]+64 && b>=b2[2] && b<=b2[2]+64)
        {
            flag2[2]=1;
            f=1;
        }
    }
    if(flag2[2]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[2]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag2[2]=3;
    }
    if(f==1)
        mode2=2;
}

void drawelephanto1()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a2[2];
    idx2=b2[2];
    if(flag2[2]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[2],b2[2],64,64);
        while(a2[2]+cnt<=548 && b2[2]+cnt<=478)
        {
            if(ifpositionnull1(a2[2]+cnt,b2[2]+cnt))
            {
                iRectangle(a2[2]+cnt,b2[2]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]+cnt,b2[2]+cnt)))
                break;
            if(!(ifpositionnull2(a2[2]+cnt,b2[2]+cnt)))
            {
                iRectangle(a2[2]+cnt,b2[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[2]-cnt>=100 && b2[2]+cnt<=478)
        {
            if(ifpositionnull1(a2[2]-cnt,b2[2]+cnt))
            {
                iRectangle(a2[2]-cnt,b2[2]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]-cnt,b2[2]+cnt)))
                break;
            if(!(ifpositionnull2(a2[2]-cnt,b2[2]+cnt)))
            {
                iRectangle(a2[2]-cnt,b2[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[2]-cnt>=100 && b2[2]-cnt>=30)
        {
            if(ifpositionnull1(a2[2]-cnt,b2[2]-cnt))
            {
                iRectangle(a2[2]-cnt,b2[2]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]-cnt,b2[2]-cnt)))
                break;
            if(!(ifpositionnull2(a2[2]-cnt,b2[2]-cnt)))
            {
                iRectangle(a2[2]-cnt,b2[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[2]+cnt<=548 && b2[2]-cnt>=30)
        {
            if(ifpositionnull1(a2[2]+cnt,b2[2]-cnt))
            {
                iRectangle(a2[2]+cnt,b2[2]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]+cnt,b2[2]-cnt)))
                break;
            if(!(ifpositionnull2(a2[2]+cnt,b2[2]-cnt)))
            {
                iRectangle(a2[2]+cnt,b2[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag2[2]==2)
    {
        cnt=64;
        if(colouring(a2[2],b2[2]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[2],b2[2],64,64);
        while(a2[2]+cnt<=548 && b2[2]+cnt<=478)
        {
            if(ifpositionnull1(a2[2]+cnt,b2[2]+cnt))
            {
                if(colouring(a2[2]+cnt,b2[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]+cnt,b2[2]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]+cnt,b2[2]+cnt)))
                break;
            if(!(ifpositionnull2(a2[2]+cnt,b2[2]+cnt)))
            {
                if(colouring(a2[2]+cnt,b2[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]+cnt,b2[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[2]-cnt>=100 && b2[2]+cnt<=478)
        {
            if(ifpositionnull1(a2[2]-cnt,b2[2]+cnt))
            {
                if(colouring(a2[2]-cnt,b2[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]-cnt,b2[2]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]-cnt,b2[2]+cnt)))
                break;
            if(!(ifpositionnull2(a2[2]-cnt,b2[2]+cnt)))
            {
                if(colouring(a2[2]-cnt,b2[2]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]-cnt,b2[2]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[2]-cnt>=100 && b2[2]-cnt>=30)
        {
            if(ifpositionnull1(a2[2]-cnt,b2[2]-cnt))
            {
                if(colouring(a2[2]-cnt,b2[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]-cnt,b2[2]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]-cnt,b2[2]-cnt)))
                break;
            if(!(ifpositionnull2(a2[2]-cnt,b2[2]-cnt)))
            {
                if(colouring(a2[2]-cnt,b2[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]-cnt,b2[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[2]+cnt<=548 && b2[2]-cnt>=30)
        {
            if(ifpositionnull1(a2[2]+cnt,b2[2]-cnt))
            {
                if(colouring(a2[2]+cnt,b2[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]+cnt,b2[2]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[2]+cnt,b2[2]-cnt)))
                break;
            if(!(ifpositionnull2(a2[2]+cnt,b2[2]-cnt)))
            {
                if(colouring(a2[2]+cnt,b2[2]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[2]+cnt,b2[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b2[2];
        c2=mxs-a2[2];
        cnt=64;
        if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[2]+cnt!=mxs) && (b2[2]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[2]+cnt,b2[2]+cnt) || !ifpositionnull1(a2[2]+cnt,b2[2]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[2]=b2[2]+c1;
                    a2[2]=a2[2]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((b2[2]+cnt!=mys) && (a2[2]+cnt!=mxs))
                {
                    if(!ifpositionnull1(a2[2]+cnt,b2[2]+cnt) || !ifpositionnull2(a2[2]+cnt,b2[2]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a2[2]=a2[2]+c2;
                            b2[2]=b2[2]+c1;
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && c1==-c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[2]-cnt!=mxs) && (b2[2]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[2]-cnt,b2[2]+cnt) || !ifpositionnull1(a2[2]-cnt,b2[2]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[2]=a2[2]+c2;
                        b2[2]=b2[2]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[2]-cnt !=mxs) && (b2[2]+cnt !=mys))
                {
                    if(!ifpositionnull2(a2[2]-cnt,b2[2]+cnt) || !ifpositionnull1(a2[2]-cnt,b2[2]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[2]=a2[2]+c2;
                            b2[2]=b2[2]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[2]-cnt!=mxs) && (b2[2]-cnt!=mys))
                {
                    if(!ifpositionnull1(a2[2]-cnt,b2[2]-cnt) || !ifpositionnull2(a2[2]-cnt,b2[2]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[2]=a2[2]+c2;
                        b2[2]=b2[2]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[2]-cnt !=mxs) && (b2[2]-cnt !=mys))
                {
                    if(!ifpositionnull1(a2[2]-cnt,b2[2]-cnt) || !ifpositionnull2(a2[2]-cnt,b2[2]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[2]=a2[2]+c2;
                            b2[2]=b2[2]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[2]+cnt!=mxs) && (b2[2]-cnt!=mys))
                {
                    if(!ifpositionnull2(a2[2]+cnt,b2[2]-cnt) || !ifpositionnull1(a2[2]+cnt,b2[2]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[2]=a2[2]+c2;
                        b2[2]=b2[2]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[2]+cnt !=mxs) && (b2[2]-cnt !=mys))
                {
                    if(!ifpositionnull2(a2[2]+cnt,b2[2]-cnt) || !ifpositionnull1(a2[2]+cnt,b2[2]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[2]=a2[2]+c2;
                            b2[2]=b2[2]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[2]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[2]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[2]=idx1;
            b2[2]=idx2;
            flag2[2]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[2]=idx1;
            b2[2]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[2]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[2]==3)
    {
        mode2=0;
        flag2[2]=0;
    }
}

void elephanto2(int a,int b)
{
    int i,j,f=0,k=0,l;
    if(mode2==0)
    {
        if(a>=a2[5] && a<=a2[5]+64 && b>=b2[5] && b<=b2[5]+64)
        {
            flag2[5]=1;
            f=1;
        }
    }
    if(flag2[5]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[5]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag2[5]=3;
    }
    if(f==1)
        mode2=2;
}

void drawelephanto2()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a2[5];
    idx2=b2[5];
    if(flag2[5]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[5],b2[5],64,64);
        while(a2[5]+cnt<=548 && b2[5]+cnt<=478)
        {
            if(ifpositionnull1(a2[5]+cnt,b2[5]+cnt))
            {
                iRectangle(a2[5]+cnt,b2[5]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]+cnt,b2[5]+cnt)))
                break;
            if(!(ifpositionnull2(a2[5]+cnt,b2[5]+cnt)))
            {
                iRectangle(a2[5]+cnt,b2[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[5]-cnt>=100 && b2[5]+cnt<=478)
        {
            if(ifpositionnull1(a2[5]-cnt,b2[5]+cnt))
            {
                iRectangle(a2[5]-cnt,b2[5]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]-cnt,b2[5]+cnt)))
                break;
            if(!(ifpositionnull2(a2[5]-cnt,b2[5]+cnt)))
            {
                iRectangle(a2[5]-cnt,b2[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[5]-cnt>=100 && b2[5]-cnt>=30)
        {
            if(ifpositionnull1(a2[5]-cnt,b2[5]-cnt))
            {
                iRectangle(a2[5]-cnt,b2[5]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]-cnt,b2[5]-cnt)))
                break;
            if(!(ifpositionnull2(a2[5]-cnt,b2[5]-cnt)))
            {
                iRectangle(a2[5]-cnt,b2[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[5]+cnt<=548 && b2[5]-cnt>=30)
        {
            if(ifpositionnull1(a2[5]+cnt,b2[5]-cnt))
            {
                iRectangle(a2[5]+cnt,b2[5]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]+cnt,b2[5]-cnt)))
                break;
            if(!(ifpositionnull2(a2[5]+cnt,b2[5]-cnt)))
            {
                iRectangle(a2[5]+cnt,b2[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag2[5]==2)
    {
        cnt=64;
        if(colouring(a2[5],b2[5]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[5],b2[5],64,64);
        while(a2[5]+cnt<=548 && b2[5]+cnt<=478)
        {
            if(ifpositionnull1(a2[5]+cnt,b2[5]+cnt))
            {
                if(colouring(a2[5]+cnt,b2[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]+cnt,b2[5]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]+cnt,b2[5]+cnt)))
                break;
            if(!(ifpositionnull2(a2[5]+cnt,b2[5]+cnt)))
            {
                if(colouring(a2[5]+cnt,b2[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]+cnt,b2[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[5]-cnt>=100 && b2[5]+cnt<=478)
        {
            if(ifpositionnull1(a2[5]-cnt,b2[5]+cnt))
            {
                if(colouring(a2[5]-cnt,b2[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]-cnt,b2[5]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]-cnt,b2[5]+cnt)))
                break;
            if(!(ifpositionnull2(a2[5]-cnt,b2[5]+cnt)))
            {
                if(colouring(a2[5]-cnt,b2[5]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]-cnt,b2[5]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[5]-cnt>=100 && b2[5]-cnt>=30)
        {
            if(ifpositionnull1(a2[5]-cnt,b2[5]-cnt))
            {
                if(colouring(a2[5]-cnt,b2[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]-cnt,b2[5]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]-cnt,b2[5]-cnt)))
                break;
            if(!(ifpositionnull2(a2[5]-cnt,b2[5]-cnt)))
            {
                if(colouring(a2[5]-cnt,b2[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]-cnt,b2[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[5]+cnt<=548 && b2[5]-cnt>=30)
        {
            if(ifpositionnull1(a2[5]+cnt,b2[5]-cnt))
            {
                if(colouring(a2[5]+cnt,b2[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]+cnt,b2[5]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[5]+cnt,b2[5]-cnt)))
                break;
            if(!(ifpositionnull2(a2[5]+cnt,b2[5]-cnt)))
            {
                if(colouring(a2[5]+cnt,b2[5]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[5]+cnt,b2[5]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b2[5];
        c2=mxs-a2[5];
        cnt=64;
        if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[5]+cnt!=mxs) && (b2[5]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[5]+cnt,b2[5]+cnt) || !ifpositionnull1(a2[5]+cnt,b2[5]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[5]=b2[5]+c1;
                    a2[5]=a2[5]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((b2[5]+cnt!=mys) && (a2[5]+cnt!=mxs))
                {
                    if(!ifpositionnull2(a2[5]+cnt,b2[5]+cnt) || !ifpositionnull2(a2[5]+cnt,b2[5]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            a2[5]=a2[5]+c2;
                            b2[5]=b2[5]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && c1==-c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[5]-cnt!=mxs) && (b2[5]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[5]-cnt,b2[5]+cnt) || !ifpositionnull1(a2[5]-cnt,b2[5]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[5]=a2[5]+c2;
                        b2[5]=b2[5]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[5]-cnt !=mxs) && (b2[5]+cnt !=mys))
                {
                    if(!ifpositionnull2(a2[5]-cnt,b2[5]+cnt) || !ifpositionnull1(a2[5]-cnt,b2[5]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }

                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[5]=a2[5]+c2;
                            b2[5]=b2[5]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[5]-cnt!=mxs) && (b2[5]-cnt!=mys))
                {
                    if(!ifpositionnull1(a2[5]-cnt,b2[5]-cnt) || !ifpositionnull2(a2[5]-cnt,b2[5]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[5]=a2[5]+c2;
                        b2[5]=b2[5]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[5]-cnt !=mxs) && (b2[5]-cnt !=mys))
                {
                    if(!ifpositionnull1(a2[5]-cnt,b2[5]-cnt) || !ifpositionnull2(a2[5]-cnt,b2[5]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }

                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[5]=a2[5]+c2;
                            b2[5]=b2[5]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[5]+cnt!=mxs) && (b2[5]-cnt!=mys))
                {
                    if(!ifpositionnull2(a2[5]+cnt,b2[5]-cnt) || !ifpositionnull1(a2[5]+cnt,b2[5]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[5]=a2[5]+c2;
                        b2[5]=b2[5]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[5]+cnt !=mxs) && (b2[5]-cnt !=mys))
                {
                    if(!ifpositionnull2(a2[5]+cnt,b2[5]-cnt) || !ifpositionnull1(a2[5]+cnt,b2[5]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[5]=a2[5]+c2;
                            b2[5]=b2[5]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[5]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[5]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[5]=idx1;
            b2[5]=idx2;
            flag2[5]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[5]=idx1;
            b2[5]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[5]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[5]==3)
    {
        mode2=0;
        flag2[5]=0;
    }
}

void knighti1(int a,int b)
{
    int i,j,xi,yi,f=0,k=0,l,pi;
    if(mode1==0)
    {
        if(a>=a1[1] && a<=a1[1]+64 && b>=b1[1] && b<=b1[1]+64)
        {
            flag1[1]=1;
            f=1;
        }
    }
    if(flag1[1]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[1]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[1]=3;
    }
    if(f==1)
        mode1=2;
}

void drawknighti1()
{
    int i,j,k=0,l,c1,c2,idx1,idx2,idx3,idx4;
    idx1=a1[1];
    idx2=b1[1];
    if(flag1[1]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[1],b1[1],64,64);
        if(a1[1]+64<=548 && b1[1]+128<=478)
        {
            if(ifpositionnull2(a1[1]+64,b1[1]+128))
                iRectangle(a1[1]+64,b1[1]+128,64,64);
            if(!(ifpositionnull1(a1[1]+64,b1[1]+128)))
                iRectangle(a1[1]+64,b1[1]+128,64,64);
        }
        if(a1[1]-64>=100 && b1[1]+128<=478)
        {
            if(ifpositionnull2(a1[1]-64,b1[1]+128))
                iRectangle(a1[1]-64,b1[1]+128,64,64);
            if(!(ifpositionnull1(a1[1]-64,b1[1]+128)))
                iRectangle(a1[1]-64,b1[1]+128,64,64);
        }
        if(a1[1]-64>=100 && b1[1]-128>=30)
        {
            if(ifpositionnull2(a1[1]-64,b1[1]-128))
                iRectangle(a1[1]-64,b1[1]-128,64,64);
            if(!(ifpositionnull1(a1[1]-64,b1[1]-128)))
                iRectangle(a1[1]-64,b1[1]-128,64,64);
        }
        if(a1[1]+64<=548 && b1[1]-128>=30)
        {
            if(ifpositionnull2(a1[1]+64,b1[1]-128))
                iRectangle(a1[1]+64,b1[1]-128,64,64);
            if(!(ifpositionnull1(a1[1]+64,b1[1]-128)))
                iRectangle(a1[1]+64,b1[1]-128,64,64);
        }
        if(a1[1]+128<=548 && b1[1]-64>=30)
        {
            if(ifpositionnull2(a1[1]+128,b1[1]-64))
                iRectangle(a1[1]+128,b1[1]-64,64,64);
            if(!(ifpositionnull1(a1[1]+128,b1[1]-64)))
                iRectangle(a1[1]+128,b1[1]-64,64,64);
        }
        if(a1[1]+128<=548 && b1[1]+64<=478)
        {
            if(ifpositionnull2(a1[1]+128,b1[1]+64))
                iRectangle(a1[1]+128,b1[1]+64,64,64);
            if(!(ifpositionnull1(a1[1]+128,b1[1]+64)))
                iRectangle(a1[1]+128,b1[1]+64,64,64);
        }
        if(a1[1]-128>=100 && b1[1]-64>=30)
        {
            if(ifpositionnull2(a1[1]-128,b1[1]-64))
                iRectangle(a1[1]-128,b1[1]-64,64,64);
            if(!(ifpositionnull1(a1[1]-128,b1[1]-64)))
                iRectangle(a1[1]-128,b1[1]-64,64,64);
        }
        if(a1[1]-128>=100 && b1[1]+64<=478)
        {
            if(ifpositionnull2(a1[1]-128,b1[1]+64))
                iRectangle(a1[1]-128,b1[1]+64,64,64);
            if(!(ifpositionnull1(a1[1]-128,b1[1]+64)))
                iRectangle(a1[1]-128,b1[1]+64,64,64);
        }
    }
    else if(flag1[1]==2)
    {
        if(colouring(a1[1],b1[1]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[1],b1[1],64,64);
        if(a1[1]+64<=548 && b1[1]+128<=478)
        {
            if(colouring(a1[1]+64,b1[1]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]+64,b1[1]+128))
                iRectangle(a1[1]+64,b1[1]+128,64,64);
            if(!(ifpositionnull1(a1[1]+64,b1[1]+128)))
                iRectangle(a1[1]+64,b1[1]+128,64,64);
        }
        if(a1[1]-64>=100 && b1[1]+128<=478)
        {
            if(colouring(a1[1]-64,b1[1]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]-64,b1[1]+128))
                iRectangle(a1[1]-64,b1[1]+128,64,64);
            if(!(ifpositionnull1(a1[1]-64,b1[1]+128)))
                iRectangle(a1[1]-64,b1[1]+128,64,64);
        }
        if(a1[1]-64>=100 && b1[1]-128>=30)
        {
            if(colouring(a1[1]-64,b1[1]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]-64,b1[1]-128))
                iRectangle(a1[1]-64,b1[1]-128,64,64);
            if(!(ifpositionnull1(a1[1]-64,b1[1]-128)))
                iRectangle(a1[1]-64,b1[1]-128,64,64);
        }
        if(a1[1]+64<=548 && b1[1]-128>=30)
        {
            if(colouring(a1[1]-64,b1[1]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]+64,b1[1]-128))
                iRectangle(a1[1]+64,b1[1]-128,64,64);
            if(!(ifpositionnull1(a1[1]+64,b1[1]-128)))
                iRectangle(a1[1]+64,b1[1]-128,64,64);
        }
        if(a1[1]+128<=548 && b1[1]-64>=30)
        {
            if(colouring(a1[1]+128,b1[1]-64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]+128,b1[1]-64))
                iRectangle(a1[1]+128,b1[1]-64,64,64);
            if(!(ifpositionnull1(a1[1]+128,b1[1]-64)))
                iRectangle(a1[1]+128,b1[1]-64,64,64);
        }
        if(a1[1]+128<=548 && b1[1]+64<=478)
        {
            if(colouring(a1[1]+128,b1[1]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]+128,b1[1]+64))
                iRectangle(a1[1]+128,b1[1]+64,64,64);
            if(!(ifpositionnull1(a1[1]+128,b1[1]+64)))
                iRectangle(a1[1]+128,b1[1]+64,64,64);
        }
        if(a1[1]-128>=100 && b1[1]-64>=30)
        {
            if(colouring(a1[1]-128,b1[1]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]-128,b1[1]-64))
                iRectangle(a1[1]-128,b1[1]-64,64,64);
            if(!(ifpositionnull1(a1[1]-128,b1[1]-64)))
                iRectangle(a1[1]-128,b1[1]-64,64,64);
        }
        if(a1[1]-128>=100 && b1[1]+64<=478)
        {
            if(colouring(a1[1]-128,b1[1]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[1]-128,b1[1]+64))
                iRectangle(a1[1]-128,b1[1]+64,64,64);
            if(!(ifpositionnull1(a1[1]-128,b1[1]+64)))
                iRectangle(a1[1]-128,b1[1]+64,64,64);
        }
        if(mxs==a1[1]+64 && mys==b1[1]+128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]+64;
                b1[1]=b1[1]+128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        idx3=a2[l];
                        idx4=b2[l];
                        a1[1]=a1[1]+64;
                        b1[1]=b1[1]+128;
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[1]-64 && mys==b1[1]+128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]-64;
                b1[1]=b1[1]+128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[1]=a1[1]-64;
                        b1[1]=b1[1]+128;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[1]+64 && mys==b1[1]-128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]+64;
                b1[1]=b1[1]-128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        idx3=a2[l];
                        idx4=b2[l];
                        a1[1]=a1[1]+64;
                        b1[1]=b1[1]-128;
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[1]-64 && mys==b1[1]-128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]-64;
                b1[1]=b1[1]-128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        idx3=a2[l];
                        idx4=b2[l];
                        a1[1]=a1[1]-64;
                        b1[1]=b1[1]-128;
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[1]+128 && mys==b1[1]+64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]+128;
                b1[1]=b1[1]+64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[1]=a1[1]+128;
                        b1[1]=b1[1]+64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[1]+128 && mys==b1[1]-64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]+128;
                b1[1]=b1[1]-64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[1]=a1[1]+128;
                        b1[1]=b1[1]-64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[1]-128 && mys==b1[1]+64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]-128;
                b1[1]=b1[1]+64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[1]=a1[1]-128;
                        b1[1]=b1[1]+64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[1]-128 && mys==b1[1]-64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[1]=a1[1]-128;
                b1[1]=b1[1]-64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[1]=a1[1]-128;
                        b1[1]=b1[1]-64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[1]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[1]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[1]=idx1;
            b1[1]=idx2;
            flag1[1]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[1]=idx1;
            b1[1]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[1]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[1]==3)
    {
        mode1=0;
        flag1[1]=0;
    }
}

void knighto1(int a,int b)
{
    int i,j,f=0,k=0,l,pi;
    if(mode2==0)
    {
        if(a>=a2[1] && a<=a2[1]+64 && b>=b2[1] && b<=b2[1]+64)
        {
            flag2[1]=1;
            f=1;
        }
    }
    if(flag2[1]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[1]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag2[1]=3;
    }
    if(f==1)
        mode2=2;
}

void drawknighto1()
{
    int i,j,k=0,l,c1,c2,idx1,idx2,idx3,idx4;
    idx1=a2[1];
    idx2=b2[1];
    if(flag2[1]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[1],b2[1],64,64);
        if(a2[1]+64<=548 && b2[1]+128<=478)
        {
            if(ifpositionnull1(a2[1]+64,b2[1]+128))
                iRectangle(a2[1]+64,b2[1]+128,64,64);
            if(!(ifpositionnull2(a2[1]+64,b2[1]+128)))
                iRectangle(a2[1]+64,b2[1]+128,64,64);
        }
        if(a2[1]-64>=100 && b2[1]+128<=478)
        {
            if(ifpositionnull1(a2[1]-64,b2[1]+128))
                iRectangle(a2[1]-64,b2[1]+128,64,64);
            if(!(ifpositionnull2(a2[1]-64,b2[1]+128)))
                iRectangle(a2[1]-64,b2[1]+128,64,64);

        }
        if(a2[1]-64>=100 && b2[1]-128>=30)
        {
            if(ifpositionnull1(a2[1]-64,b2[1]-128))
                iRectangle(a2[1]-64,b2[1]-128,64,64);
            if(!(ifpositionnull2(a2[1]-64,b2[1]-128)))
                iRectangle(a2[1]-64,b2[1]-128,64,64);
        }
        if(a2[1]+64<=548 && b2[1]-128>=30)
        {
            if(ifpositionnull1(a2[1]+64,b2[1]-128))
                iRectangle(a2[1]+64,b2[1]-128,64,64);
            if(!(ifpositionnull2(a2[1]+64,b2[1]-128)))
                iRectangle(a2[1]+64,b2[1]-128,64,64);
        }
        if(a2[1]+128<=548 && b2[1]-64>=30)
        {
            if(ifpositionnull1(a2[1]+128,b2[1]-64))
                iRectangle(a2[1]+128,b2[1]-64,64,64);
            if(!(ifpositionnull2(a2[1]+128,b2[1]-64)))
                iRectangle(a2[1]+128,b2[1]-64,64,64);
        }
        if(a2[1]+128<=548 && b2[1]+64<=478)
        {
            if(ifpositionnull1(a2[1]+128,b2[1]+64))
                iRectangle(a2[1]+128,b2[1]+64,64,64);
            if(!(ifpositionnull2(a2[1]+128,b2[1]+64)))
                iRectangle(a2[1]+128,b2[1]+64,64,64);
        }
        if(a2[1]-128>=100 && b2[1]-64>=30)
        {
            if(ifpositionnull1(a2[1]-128,b2[1]-64))
                iRectangle(a2[1]-128,b2[1]-64,64,64);
            if(!(ifpositionnull2(a2[1]-128,b2[1]-64)))
                iRectangle(a2[1]-128,b2[1]-64,64,64);
        }
        if(a2[1]-128>=100 && b2[1]+64<=478)
        {
            if(ifpositionnull1(a2[1]-128,b2[1]+64))
                iRectangle(a2[1]-128,b2[1]+64,64,64);
            if(!(ifpositionnull2(a2[1]-128,b2[1]+64)))
                iRectangle(a2[1]-128,b2[1]+64,64,64);
        }
    }
    else if(flag2[1]==2)
    {
        if(colouring(a2[1],b2[1]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[1],b2[1],64,64);
        if(a2[1]+64<=548 && b2[1]+128<=478)
        {
            if(colouring(a2[1]+64,b2[1]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]+64,b2[1]+128))
                iRectangle(a2[1]+64,b2[1]+128,64,64);
            if(!(ifpositionnull2(a2[1]+64,b2[1]+128)))
                iRectangle(a2[1]+64,b2[1]+128,64,64);
        }
        if(a2[1]-64>=100 && b2[1]+128<=478)
        {
            if(colouring(a2[1]-64,b2[1]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]-64,b2[1]+128))
                iRectangle(a2[1]-64,b2[1]+128,64,64);
            if(!(ifpositionnull2(a2[1]-64,b2[1]+128)))
                iRectangle(a2[1]-64,b2[1]+128,64,64);

        }
        if(a2[1]-64>=100 && b2[1]-128>=30)
        {
            if(colouring(a2[1]-64,b2[1]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]-64,b2[1]-128))
                iRectangle(a2[1]-64,b2[1]-128,64,64);
            if(!(ifpositionnull2(a2[1]-64,b2[1]-128)))
                iRectangle(a2[1]-64,b2[1]-128,64,64);
        }
        if(a2[1]+64<=548 && b2[1]-128>=30)
        {
            if(colouring(a2[1]-64,b2[1]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]+64,b2[1]-128))
                iRectangle(a2[1]+64,b2[1]-128,64,64);
            if(!(ifpositionnull2(a2[1]+64,b2[1]-128)))
                iRectangle(a2[1]+64,b2[1]-128,64,64);
        }
        if(a2[1]+128<=548 && b2[1]-64>=30)
        {
            if(colouring(a2[1]+128,b2[1]-64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]+128,b2[1]-64))
                iRectangle(a2[1]+128,b2[1]-64,64,64);
            if(!(ifpositionnull2(a2[1]+128,b2[1]-64)))
                iRectangle(a2[1]+128,b2[1]-64,64,64);
        }
        if(a2[1]+128<=548 && b2[1]+64<=478)
        {
            if(colouring(a2[1]+128,b2[1]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]+128,b2[1]+64))
                iRectangle(a2[1]+128,b2[1]+64,64,64);
            if(!(ifpositionnull2(a2[1]+128,b2[1]+64)))
                iRectangle(a2[1]+128,b2[1]+64,64,64);
        }
        if(a2[1]-128>=100 && b2[1]-64>=30)
        {
            if(colouring(a2[1]-128,b2[1]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]-128,b2[1]-64))
                iRectangle(a2[1]-128,b2[1]-64,64,64);
            if(!(ifpositionnull2(a2[1]-128,b2[1]-64)))
                iRectangle(a2[1]-128,b2[1]-64,64,64);
        }
        if(a2[1]-128>=100 && b2[1]+64<=478)
        {
            if(colouring(a2[1]-128,b2[1]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[1]-128,b2[1]+64))
                iRectangle(a2[1]-128,b2[1]+64,64,64);
            if(!(ifpositionnull2(a2[1]-128,b2[1]+64)))
                iRectangle(a2[1]-128,b2[1]+64,64,64);

        }
        if(mxs==a2[1]+64 && mys==b2[1]+128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]+64;
                b2[1]=b2[1]+128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]+64;
                        b2[1]=b2[1]+128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[1]-64 && mys==b2[1]+128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]-64;
                b2[1]=b2[1]+128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]-64;
                        b2[1]=b2[1]+128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[1]+64 && mys==b2[1]-128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]+64;
                b2[1]=b2[1]-128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]+64;
                        b2[1]=b2[1]-128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[1]-64 && mys==b2[1]-128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]-64;
                b2[1]=b2[1]-128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]-64;
                        b2[1]=b2[1]-128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[1]+128 && mys==b2[1]+64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]+128;
                b2[1]=b2[1]+64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]+128;
                        b2[1]=b2[1]+64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[1]+128 && mys==b2[1]-64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]+128;
                b2[1]=b2[1]-64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]+128;
                        b2[1]=b2[1]-64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[1]-128 && mys==b2[1]+64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]-128;
                b2[1]=b2[1]+64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]-128;
                        b2[1]=b2[1]+64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[1]-128 && mys==b2[1]-64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[1]=a2[1]-128;
                b2[1]=b2[1]-64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[1]=a2[1]-128;
                        b2[1]=b2[1]-64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[1]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[1]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[1]=idx1;
            b2[1]=idx2;
            flag2[1]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[1]=idx1;
            b2[1]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[1]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[1]==3)
    {
        mode2=0;
        flag2[1]=0;
    }
}

void knighti2(int a,int b)
{
    int i,j,f=0,k=0,l,pi;
    if(mode1==0)
    {
        if(a>=a1[6] && a<=a1[6]+64 && b>=b1[6] && b<=b1[6]+64)
        {
            flag1[6]=1;
            f=1;
        }
    }
    if(flag1[6]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[6]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[6]=3;
    }
    if(f==1)
        mode1=2;
}

void drawknighti2()
{
    int i,j,k=0,l,c1,c2,idx1,idx2,idx3,idx4;
    idx1=a1[6];
    idx2=b1[6];
    if(flag1[6]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[6],b1[6],64,64);
        if(a1[6]+64<=548 && b1[6]+128<=478)
        {
            if(ifpositionnull2(a1[6]+64,b1[6]+128))
                iRectangle(a1[6]+64,b1[6]+128,64,64);
            if(!(ifpositionnull1(a1[1]+64,b1[1]+128)))
                iRectangle(a1[6]+64,b1[6]+128,64,64);
        }
        if(a1[6]-64>=100 && b1[6]+128<=478)
        {
            if(ifpositionnull2(a1[6]-64,b1[6]+128))
                iRectangle(a1[6]-64,b1[6]+128,64,64);
            if(!(ifpositionnull1(a1[6]-64,b1[6]+128)))
                iRectangle(a1[6]-64,b1[6]+128,64,64);

        }
        if(a1[6]-64>=100 && b1[6]-128>=30)
        {
            if(ifpositionnull2(a1[6]-64,b1[6]-128))
                iRectangle(a1[6]-64,b1[6]-128,64,64);
            if(!(ifpositionnull1(a1[6]-64,b1[6]-128)))
                iRectangle(a1[6]-64,b1[6]-128,64,64);
        }
        if(a1[6]+64<=548 && b1[6]-128>=30)
        {
            if(ifpositionnull2(a1[6]+64,b1[6]-128))
                iRectangle(a1[6]+64,b1[6]-128,64,64);
            if(!(ifpositionnull1(a1[6]+64,b1[6]-128)))
                iRectangle(a1[6]+64,b1[6]-128,64,64);
        }
        if(a1[6]+128<=548 && b1[6]-64>=30)
        {
            if(ifpositionnull2(a1[6]+128,b1[6]-64))
                iRectangle(a1[6]+128,b1[6]-64,64,64);
            if(!(ifpositionnull1(a1[6]+128,b1[6]-64)))
                iRectangle(a1[6]+128,b1[6]-64,64,64);
        }
        if(a1[6]+128<=548 && b1[6]+64<=478)
        {
            if(ifpositionnull2(a1[6]+128,b1[6]+64))
                iRectangle(a1[6]+128,b1[6]+64,64,64);
            if(!(ifpositionnull1(a1[6]+128,b1[6]+64)))
                iRectangle(a1[6]+128,b1[6]+64,64,64);
        }
        if(a1[6]-128>=100 && b1[6]-64>=30)
        {
            if(ifpositionnull2(a1[6]-128,b1[6]-64))
                iRectangle(a1[6]-128,b1[6]-64,64,64);
            if(!(ifpositionnull1(a1[6]-128,b1[6]-64)))
                iRectangle(a1[6]-128,b1[6]-64,64,64);
        }
        if(a1[6]-128>=100 && b1[6]+64<=478)
        {
            if(ifpositionnull2(a1[6]-128,b1[6]+64))
                iRectangle(a1[6]-128,b1[6]+64,64,64);
            if(!(ifpositionnull1(a1[6]-128,b1[6]+64)))
                iRectangle(a1[6]-128,b1[6]+64,64,64);
        }
    }
    else if(flag1[6]==2)
    {
        if(colouring(a1[6],b1[6]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[6],b1[6],64,64);
        if(a1[6]+64<=548 && b1[6]+128<=478)
        {
            if(colouring(a1[6]+64,b1[6]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]+64,b1[6]+128))
                iRectangle(a1[6]+64,b1[6]+128,64,64);
            if(!(ifpositionnull1(a1[6]+64,b1[6]+128)))
                iRectangle(a1[6]+64,b1[6]+128,64,64);
        }
        if(a1[6]-64>=100 && b1[6]+128<=478)
        {
            if(colouring(a1[6]-64,b1[6]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]-64,b1[6]+128))
                iRectangle(a1[6]-64,b1[6]+128,64,64);
            if(!(ifpositionnull1(a1[6]-64,b1[6]+128)))
                iRectangle(a1[6]-64,b1[6]+128,64,64);
        }
        if(a1[6]-64>=100 && b1[6]-128>=30)
        {
            if(colouring(a1[6]-64,b1[6]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]-64,b1[6]-128))
                iRectangle(a1[6]-64,b1[6]-128,64,64);
            if(!(ifpositionnull1(a1[6]-64,b1[6]-128)))
                iRectangle(a1[6]-64,b1[6]-128,64,64);
        }
        if(a1[6]+64<=548 && b1[6]-128>=30)
        {
            if(colouring(a1[6]-64,b1[6]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]+64,b1[6]-128))
                iRectangle(a1[6]+64,b1[6]-128,64,64);
            if(!(ifpositionnull1(a1[6]+64,b1[6]-128)))
                iRectangle(a1[6]+64,b1[6]-128,64,64);
        }
        if(a1[6]+128<=548 && b1[6]-64>=30)
        {
            if(colouring(a1[6]+128,b1[6]-64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]+128,b1[6]-64))
                iRectangle(a1[6]+128,b1[6]-64,64,64);
            if(!(ifpositionnull1(a1[6]+128,b1[6]-64)))
                iRectangle(a1[6]+128,b1[6]-64,64,64);
        }
        if(a1[6]+128<=548 && b1[6]+64<=478)
        {
            if(colouring(a1[6]+128,b1[6]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]+128,b1[6]+64))
                iRectangle(a1[6]+128,b1[6]+64,64,64);
            if(!(ifpositionnull1(a1[6]+128,b1[6]+64)))
                iRectangle(a1[6]+128,b1[6]+64,64,64);
        }
        if(a1[6]-128>=100 && b1[6]-64>=30)
        {
            if(colouring(a1[6]-128,b1[6]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]-128,b1[6]-64))
                iRectangle(a1[6]-128,b1[6]-64,64,64);
            if(!(ifpositionnull1(a1[6]-128,b1[6]-64)))
                iRectangle(a1[6]-128,b1[6]-64,64,64);
        }
        if(a1[6]-128>=100 && b1[6]+64<=478)
        {
            if(colouring(a1[6]-128,b1[6]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull2(a1[6]-128,b1[6]+64))
                iRectangle(a1[6]-128,b1[6]+64,64,64);
            if(!(ifpositionnull1(a1[6]-128,b1[6]+64)))
                iRectangle(a1[6]-128,b1[6]+64,64,64);
        }
        if(mxs==a1[6]+64 && mys==b1[6]+128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]+64;
                b1[6]=b1[6]+128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]+64;
                        b1[6]=b1[6]+128;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[6]-64 && mys==b1[6]+128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]-64;
                b1[6]=b1[6]+128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]-64;
                        b1[6]=b1[6]+128;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[6]+64 && mys==b1[6]-128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]+64;
                b1[6]=b1[6]-128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]+64;
                        b1[6]=b1[6]-128;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[6]-64 && mys==b1[6]-128)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]-64;
                b1[6]=b1[6]-128;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]-64;
                        b1[6]=b1[6]-128;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[6]+128 && mys==b1[6]+64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]+128;
                b1[6]=b1[6]+64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]+128;
                        b1[6]=b1[6]+64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[6]+128 && mys==b1[6]-64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]+128;
                b1[6]=b1[6]-64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]+128;
                        b1[6]=b1[6]-64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[6]-128 && mys==b1[6]+64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]-128;
                b1[6]=b1[6]+64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]-128;
                        b1[6]=b1[6]+64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[6]-128 && mys==b1[6]-64)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                a1[6]=a1[6]-128;
                b1[6]=b1[6]-64;
                k=1;
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a2[l] && mys==b2[l])
                    {
                        alive2[l]=1;
                        a1[6]=a1[6]-128;
                        b1[6]=b1[6]-64;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[6]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[6]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[6]=idx1;
            b1[6]=idx2;
            flag1[6]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[6]=idx1;
            b1[6]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[6]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[6]==3)
    {
        mode1=0;
        flag1[6]=0;
    }
}

void knighto2(int a,int b)
{
    int i,j,f=0,k=0,l,pi;
    if(mode2==0)
    {
        if(a>=a2[6] && a<=a2[6]+64 && b>=b2[6] && b<=b2[6]+64)
        {
            flag2[6]=1;
            f=1;
        }
    }
    if(flag2[6]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[6]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag2[6]=3;
    }
    if(f==1)
        mode2=2;
}

void drawknighto2()
{
    int i,j,k=0,l,c1,c2,idx1,idx2,idx3,idx4;
    idx1=a2[6];
    idx2=b2[6];
    if(flag2[6]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[6],b2[6],64,64);
        if(a2[6]+64<=548 && b2[6]+128<=478)
        {
            if(ifpositionnull1(a2[6]+64,b2[6]+128))
                iRectangle(a2[6]+64,b2[6]+128,64,64);
            if(!(ifpositionnull2(a2[6]+64,b2[6]+128)))
                iRectangle(a2[6]+64,b2[6]+128,64,64);
        }
        if(a2[6]-64>=100 && b2[6]+128<=478)
        {
            if(ifpositionnull1(a2[6]-64,b2[6]+128))
                iRectangle(a2[6]-64,b2[6]+128,64,64);
            if(!(ifpositionnull2(a2[6]-64,b2[6]+128)))
                iRectangle(a2[6]-64,b2[6]+128,64,64);
        }
        if(a2[6]-64>=100 && b2[6]-128>=30)
        {
            if(ifpositionnull1(a2[6]-64,b2[6]-128))
                iRectangle(a2[6]-64,b2[6]-128,64,64);
            if(!(ifpositionnull2(a2[6]-64,b2[6]-128)))
                iRectangle(a2[6]-64,b2[6]-128,64,64);
        }
        if(a2[6]+64<=548 && b2[6]-128>=30)
        {
            if(ifpositionnull1(a2[6]+64,b2[6]-128))
                iRectangle(a2[6]+64,b2[6]-128,64,64);
            if(!(ifpositionnull2(a2[6]+64,b2[6]-128)))
                iRectangle(a2[6]+64,b2[6]-128,64,64);
        }
        if(a2[6]+128<=548 && b2[6]-64>=30)
        {
            if(ifpositionnull1(a2[6]+128,b2[6]-64))
                iRectangle(a2[6]+128,b2[6]-64,64,64);
            if(!(ifpositionnull2(a2[6]+128,b2[6]-64)))
                iRectangle(a2[6]+128,b2[6]-64,64,64);
        }
        if(a2[6]+128<=548 && b2[6]+64<=478)
        {
            if(ifpositionnull1(a2[6]+128,b2[6]+64))
                iRectangle(a2[6]+128,b2[6]+64,64,64);
            if(!(ifpositionnull2(a2[6]+128,b2[6]+64)))
                iRectangle(a2[6]+128,b2[6]+64,64,64);
        }
        if(a2[6]-128>=100 && b2[6]-64>=30)
        {
            if(ifpositionnull1(a2[6]-128,b2[6]-64))
                iRectangle(a2[6]-128,b2[6]-64,64,64);
            if(!(ifpositionnull2(a2[6]-128,b2[6]-64)))
                iRectangle(a2[6]-128,b2[6]-64,64,64);
        }
        if(a2[6]-128>=100 && b2[6]+64<=478)
        {
            if(ifpositionnull1(a2[6]-128,b2[6]+64))
                iRectangle(a2[6]-128,b2[6]+64,64,64);
            if(!(ifpositionnull2(a2[6]-128,b2[6]+64)))
                iRectangle(a2[6]-128,b2[6]+64,64,64);
        }
    }
    else if(flag2[6]==2)
    {
        if(colouring(a2[6],b2[6]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[6],b2[6],64,64);
        if(a2[6]+64<=548 && b2[6]+128<=478)
        {
            if(colouring(a2[6]+64,b2[6]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]+64,b2[6]+128))
                iRectangle(a2[6]+64,b2[6]+128,64,64);
            if(!(ifpositionnull2(a2[6]+64,b2[6]+128)))
                iRectangle(a2[6]+64,b2[6]+128,64,64);
        }
        if(a2[6]-64>=100 && b2[6]+128<=478)
        {
            if(colouring(a2[6]-64,b2[6]+128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]-64,b2[6]+128))
                iRectangle(a2[6]-64,b2[6]+128,64,64);
            if(!(ifpositionnull2(a2[6]-64,b2[6]+128)))
                iRectangle(a2[6]-64,b2[6]+128,64,64);
        }
        if(a2[6]-64>=100 && b2[6]-128>=30)
        {
            if(colouring(a2[6]-64,b2[6]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]-64,b2[6]-128))
                iRectangle(a2[6]-64,b2[6]-128,64,64);
            if(!(ifpositionnull2(a2[6]-64,b2[6]-128)))
                iRectangle(a2[6]-64,b2[6]-128,64,64);
        }
        if(a2[6]+64<=548 && b2[6]-128>=30)
        {
            if(colouring(a2[6]-64,b2[6]-128))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]+64,b2[6]-128))
                iRectangle(a2[6]+64,b2[6]-128,64,64);
            if(!(ifpositionnull2(a2[6]+64,b2[6]-128)))
                iRectangle(a2[6]+64,b2[6]-128,64,64);
        }
        if(a2[6]+128<=548 && b2[6]-64>=30)
        {
            if(colouring(a2[6]+128,b2[6]-64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]+128,b2[6]-64))
                iRectangle(a2[6]+128,b2[6]-64,64,64);
            if(!(ifpositionnull2(a2[6]+128,b2[6]-64)))
                iRectangle(a2[6]+128,b2[6]-64,64,64);
        }
        if(a2[6]+128<=548 && b2[6]+64<=478)
        {
            if(colouring(a2[6]+128,b2[6]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]+128,b2[6]+64))
                iRectangle(a2[6]+128,b2[6]+64,64,64);
            if(!(ifpositionnull2(a2[6]+128,b2[6]+64)))
                iRectangle(a2[6]+128,b2[6]+64,64,64);
        }
        if(a2[6]-128>=100 && b2[6]-64>=30)
        {
            if(colouring(a2[6]-128,b2[6]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]-128,b2[6]-64))
                iRectangle(a2[6]-128,b2[6]-64,64,64);
            if(!(ifpositionnull2(a2[6]-128,b2[6]-64)))
                iRectangle(a2[6]-128,b2[6]-64,64,64);
        }
        if(a2[6]-128>=100 && b2[6]+64<=478)
        {
            if(colouring(a2[6]-128,b2[6]+64))
                iSetColor(0,0,0);
            else
                iSetColor(255,255,255);
            if(ifpositionnull1(a2[6]-128,b2[6]+64))
                iRectangle(a2[6]-128,b2[6]+64,64,64);
            if(!(ifpositionnull2(a2[6]-128,b2[6]+64)))
                iRectangle(a2[6]-128,b2[6]+64,64,64);
        }
        if(mxs==a2[6]+64 && mys==b2[6]+128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]+64;
                b2[6]=b2[6]+128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]+64;
                        b2[6]=b2[6]+128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[6]-64 && mys==b2[6]+128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]-64;
                b2[6]=b2[6]+128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]-64;
                        b2[6]=b2[6]+128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[6]+64 && mys==b2[6]-128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]+64;
                b2[6]=b2[6]-128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]+64;
                        b2[6]=b2[6]-128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[6]-64 && mys==b2[6]-128)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]-64;
                b2[6]=b2[6]-128;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]-64;
                        b2[6]=b2[6]-128;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[6]+128 && mys==b2[6]+64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]+128;
                b2[6]=b2[6]+64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]+128;
                        b2[6]=b2[6]+64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[6]+128 && mys==b2[6]-64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]+128;
                b2[6]=b2[6]-64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]+128;
                        b2[6]=b2[6]-64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[6]-128 && mys==b2[6]+64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]-128;
                b2[6]=b2[6]+64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]-128;
                        b2[6]=b2[6]+64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[6]-128 && mys==b2[6]-64)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                a2[6]=a2[6]-128;
                b2[6]=b2[6]-64;
                k=1;
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                for(l=0; l<16; l++)
                {
                    if(mxs==a1[l] && mys==b1[l])
                    {
                        alive1[l]=1;
                        a2[6]=a2[6]-128;
                        b2[6]=b2[6]-64;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        k=2;
                        break;
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[6]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[6]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[6]=idx1;
            b2[6]=idx2;
            flag2[6]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[6]=idx1;
            b2[6]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[6]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[6]==3)
    {
        mode2=0;
        flag2[6]=0;
    }
}

void castlei1(int a,int b)
{
    int i,j,xi,yi,f=0,k=0,l,pi;
    if(mode1==0)
    {
        if(a>=a1[0] && a<=a1[0]+64 && b>=b1[0] && b<=b1[0]+64)
        {
            flag1[0]=1;
            f=1;
        }
    }
    if(flag1[0]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[0]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[0]=3;
    }
    if(f==1)
        mode1=2;
}

void drawcastlei1()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a1[0];
    idx2=b1[0];
    if(flag1[0]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[0],b1[0],64,64);
        while(b1[0]+cnt<=478)
        {
            if(ifpositionnull2(a1[0],b1[0]+cnt))
            {
                iRectangle(a1[0],b1[0]+cnt,64,64);
            }
            if(!((ifpositionnull2(a1[0],b1[0]+cnt)))) break;
            if(!(ifpositionnull1(a1[0],b1[0]+cnt)))
            {
                iRectangle(a1[0],b1[0]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[0]-cnt>=30)
        {
            if(ifpositionnull2(a1[0],b1[0]-cnt))
            {
                iRectangle(a1[0],b1[0]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[0],b1[0]-cnt))) break;
            if(!(ifpositionnull1(a1[0],b1[0]-cnt)))
            {
                iRectangle(a1[0],b1[0]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[0]+cnt<=548)
        {
            if(ifpositionnull2(a1[0]+cnt,b1[0]))
            {
                iRectangle(a1[0]+cnt,b1[0],64,64);
            }
            if(!(ifpositionnull2(a1[0]+cnt,b1[0]))) break;
            if(!(ifpositionnull1(a1[0]+cnt,b1[0])))
            {
                iRectangle(a1[0]+cnt,b1[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[0]-cnt>=100)
        {
            if(ifpositionnull2(a1[0]-cnt,b1[0]))
            {
                iRectangle(a1[0]-cnt,b1[0],64,64);
            }
            if(!(ifpositionnull2(a1[0]-cnt,b1[0]))) break;
            if(!(ifpositionnull1(a1[0]-cnt,b1[0])))
            {
                iRectangle(a1[0]-cnt,b1[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag1[0]==2)
    {
        cnt=64;
        if(colouring(a1[0],b1[0]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[0],b1[0],64,64);
        while(b1[0]+cnt<=478)
        {
            if(ifpositionnull2(a1[0],b1[0]+cnt))
            {
                if(colouring(a1[0],b1[0]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0],b1[0]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[0],b1[0]+cnt))) break;
            if(!(ifpositionnull1(a1[0],b1[0]+cnt)))
            {
                if(colouring(a1[0],b1[0]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0],b1[0]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[0]-cnt>=30)
        {
            if(ifpositionnull2(a1[0],b1[0]-cnt))
            {
                if(colouring(a1[0],b1[0]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0],b1[0]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[0],b1[0]-cnt))) break;
            if(!(ifpositionnull1(a1[0],b1[0]-cnt)))
            {
                if(colouring(a1[0],b1[0]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0],b1[0]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[0]+cnt<=548)
        {
            if(ifpositionnull2(a1[0]+cnt,b1[0]))
            {
                if(colouring(a1[0]+cnt,b1[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0]+cnt,b1[0],64,64);
            }
            if(!(ifpositionnull2(a1[0]+cnt,b1[0]))) break;
            if(!(ifpositionnull1(a1[0]+cnt,b1[0])))
            {
                if(colouring(a1[0]+cnt,b1[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0]+cnt,b1[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[0]-cnt>=100)
        {
            if(ifpositionnull2(a1[0]-cnt,b1[0]))
            {
                if(colouring(a1[0]-cnt,b1[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0]-cnt,b1[0],64,64);
            }
            if(!(ifpositionnull2(a1[0]-cnt,b1[0]))) break;
            if(!(ifpositionnull1(a1[0]-cnt,b1[0])))
            {
                if(colouring(a1[0]-cnt,b1[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[0]-cnt,b1[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b1[0];
        c2=mxs-a1[0];
        cnt=64;
        if(mxs==a1[0] && c1>0 && c1%64==0)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[0]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[0],b1[0]+cnt) || !ifpositionnull2(a1[0],b1[0]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[0]=b1[0]+c1;
                    castling=0;
                    k=1;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[0]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[0],b1[0]+cnt) || !ifpositionnull2(a1[0],b1[0]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[0]=b1[0]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[0] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[0]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[0],b1[0]-cnt) || !ifpositionnull2(a1[0],b1[0]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        b1[0]=b1[0]+c1;
                        castling=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[0]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[0],b1[0]-cnt) || !ifpositionnull2(a1[0],b1[0]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[0]=b1[0]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[0] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[0]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[0]+cnt,b1[0]) || !ifpositionnull2(a1[0]+cnt,b1[0]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[0]=a1[0]+c2;
                        castling=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[0]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[0]+cnt,b1[0]) || !ifpositionnull2(a1[0]+cnt,b1[0]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[0]=a1[0]+c2;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[0] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[0]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[0]-cnt,b1[0]) || !ifpositionnull2(a1[0]-cnt,b1[0]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[0]=a1[0]+c2;
                        castling=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[0]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[0]-cnt,b1[0]) || !ifpositionnull2(a1[0]-cnt,b1[0]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[0]=a1[0]+c2;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[0]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[0]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[0]=idx1;
            b1[0]=idx2;
            flag1[0]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[0]=idx1;
            b1[0]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[0]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[0]==3)
    {
        mode1=0;
        flag1[0]=0;
    }
}

void castlei2(int a,int b)
{
    int i,j,xi,yi,f=0,k=0,l,pi;
    if(mode1==0)
    {
        if(a>=a1[7] && a<=a1[7]+64 && b>=b1[7] && b<=b1[7]+64)
        {
            flag1[7]=1;
            f=1;
        }
    }
    if(flag1[7]==1 && mode1==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[7]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag1[7]=3;
    }
    if(f==1)
        mode1=2;
}

void drawcastlei2()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a1[7];
    idx2=b1[7];
    if(flag1[7]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[7],b1[7],64,64);
        while(b1[7]+cnt<=478)
        {
            if(ifpositionnull2(a1[7],b1[7]+cnt))
            {
                iRectangle(a1[7],b1[7]+cnt,64,64);
            }
            if(!((ifpositionnull2(a1[7],b1[7]+cnt)))) break;
            if(!(ifpositionnull1(a1[7],b1[7]+cnt)))
            {
                iRectangle(a1[7],b1[7]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[7]-cnt>=30)
        {
            if(ifpositionnull2(a1[7],b1[7]-cnt))
            {
                iRectangle(a1[7],b1[7]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[7],b1[7]-cnt))) break;
            if(!(ifpositionnull1(a1[7],b1[7]-cnt)))
            {
                iRectangle(a1[7],b1[7]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[7]+cnt<=548)
        {
            if(ifpositionnull2(a1[7]+cnt,b1[7]))
            {
                iRectangle(a1[7]+cnt,b1[7],64,64);
            }
            if(!(ifpositionnull2(a1[7]+cnt,b1[7]))) break;
            if(!(ifpositionnull1(a1[7]+cnt,b1[7])))
            {
                iRectangle(a1[7]+cnt,b1[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[7]-cnt>=100)
        {
            if(ifpositionnull2(a1[7]-cnt,b1[7]))
            {
                iRectangle(a1[7]-cnt,b1[7],64,64);
            }
            if(!(ifpositionnull2(a1[7]-cnt,b1[7]))) break;
            if(!(ifpositionnull1(a1[7]-cnt,b1[7])))
            {
                iRectangle(a1[7]-cnt,b1[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag1[7]==2)
    {
        cnt=64;
        if(colouring(a1[7],b1[7]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[7],b1[7],64,64);
        while(b1[7]+cnt<=478)
        {
            if(ifpositionnull2(a1[7],b1[7]+cnt))
            {
                if(colouring(a1[7],b1[7]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7],b1[7]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[7],b1[7]+cnt))) break;
            if(!(ifpositionnull1(a1[7],b1[7]+cnt)))
            {
                if(colouring(a1[7],b1[7]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7],b1[7]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[7]-cnt>=30)
        {
            if(ifpositionnull2(a1[7],b1[7]-cnt))
            {
                if(colouring(a1[7],b1[7]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7],b1[7]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[7],b1[7]-cnt))) break;
            if(!(ifpositionnull1(a1[7],b1[7]-cnt)))
            {
                if(colouring(a1[7],b1[7]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7],b1[7]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[7]+cnt<=548)
        {
            if(ifpositionnull2(a1[7]+cnt,b1[7]))
            {
                if(colouring(a1[7]+cnt,b1[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7]+cnt,b1[7],64,64);
            }
            if(!(ifpositionnull2(a1[7]+cnt,b1[7]))) break;
            if(!(ifpositionnull1(a1[7]+cnt,b1[7])))
            {
                if(colouring(a1[7]+cnt,b1[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7]+cnt,b1[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[7]-cnt>=100)
        {
            if(ifpositionnull2(a1[7]-cnt,b1[7]))
            {
                if(colouring(a1[7]-cnt,b1[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7]-cnt,b1[7],64,64);
            }
            if(!(ifpositionnull2(a1[7]-cnt,b1[7]))) break;
            if(!(ifpositionnull1(a1[7]-cnt,b1[7])))
            {
                if(colouring(a1[7]-cnt,b1[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[7]-cnt,b1[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b1[7];
        c2=mxs-a1[7];
        cnt=64;
        if(mxs==a1[7] && c1>0 && c1%64==0)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[7]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[7],b1[7]+cnt) || !ifpositionnull2(a1[7],b1[7]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[7]=b1[7]+c1;
                    k=1;
                    castling=0;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[7]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[7],b1[7]+cnt) || !ifpositionnull2(a1[7],b1[7]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[7]=b1[7]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[7] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[7]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[7],b1[7]-cnt) || !ifpositionnull2(a1[7],b1[7]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        b1[7]=b1[7]+c1;
                        castling=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[7]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[7],b1[7]-cnt) || !ifpositionnull2(a1[7],b1[7]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[7]=b1[7]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[7] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[7]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[7]+cnt,b1[7]) || !ifpositionnull2(a1[7]+cnt,b1[7]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[7]=a1[7]+c2;
                        castling=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[7]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[7]+cnt,b1[7]) || !ifpositionnull2(a1[7]+cnt,b1[7]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[7]=a1[7]+c2;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[7] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[7]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[7]-cnt,b1[7]) || !ifpositionnull2(a1[7]-cnt,b1[7]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[7]=a1[7]+c2;
                        castling=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[7]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[7]-cnt,b1[7]) || !ifpositionnull2(a1[7]-cnt,b1[7]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[7]=a1[7]+c2;
                            k=2;
                            castling=0;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode1=0;
            flag1[7]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[7]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[7]=idx1;
            b1[7]=idx2;
            flag1[7]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[7]=idx1;
            b1[7]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[7]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[7]==3)
    {
        mode1=0;
        flag1[7]=0;
    }
}

void castleo1(int a,int b)
{
    int i,j,f=0,k=0,l,pi;
    if(mode2==0)
    {
        if(a>=a2[0] && a<=a2[0]+64 && b>=b2[0] && b<=b2[0]+64)
        {
            flag2[0]=1;
            f=1;
        }
    }
    if(flag2[0]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[0]=2;
                    k=1;
                    break;
                }
            }
        }
        if(k==0)
            flag2[0]=3;
    }
    if(f==1)
        mode2=2;
}

void drawcastleo1()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a2[0];
    idx2=b2[0];
    if(flag2[0]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[0],b2[0],64,64);
        while(b2[0]+cnt<=478)
        {
            if(ifpositionnull1(a2[0],b2[0]+cnt))
            {
                iRectangle(a2[0],b2[0]+cnt,64,64);
            }
            if(!((ifpositionnull1(a2[0],b2[0]+cnt))))
                break;
            if(!(ifpositionnull2(a2[0],b2[0]+cnt)))
            {
                iRectangle(a2[0],b2[0]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[0]-cnt>=30)
        {
            if(ifpositionnull1(a2[0],b2[0]-cnt))
            {
                iRectangle(a2[0],b2[0]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[0],b2[0]-cnt))) break;
            if(!(ifpositionnull2(a2[0],b2[0]-cnt)))
            {
                iRectangle(a2[0],b2[0]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[0]+cnt<=548)
        {
            if(ifpositionnull1(a2[0]+cnt,b2[0]))
            {
                iRectangle(a2[0]+cnt,b2[0],64,64);
            }
            if(!(ifpositionnull1(a2[0]+cnt,b2[0]))) break;
            if(!(ifpositionnull2(a2[0]+cnt,b2[0])))
            {
                iRectangle(a2[0]+cnt,b2[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[0]-cnt>=100)
        {
            if(ifpositionnull1(a2[0]-cnt,b2[0]))
            {
                iRectangle(a2[0]-cnt,b2[0],64,64);
            }
            if(!(ifpositionnull1(a2[0]-cnt,b2[0]))) break;
            if(!(ifpositionnull2(a2[0]-cnt,b2[0])))
            {
                iRectangle(a2[0]-cnt,b2[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag2[0]==2)
    {
        cnt=64;
        if(colouring(a2[0],b2[0]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[0],b2[0],64,64);
        while(b2[0]+cnt<=478)
        {
            if(ifpositionnull1(a2[0],b2[0]+cnt))
            {
                if(colouring(a2[0],b2[0]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0],b2[0]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[0],b2[0]+cnt))) break;
            if(!(ifpositionnull2(a2[0],b2[0]+cnt)))
            {
                if(colouring(a2[0],b2[0]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0],b2[0]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[0]-cnt>=30)
        {
            if(ifpositionnull1(a2[0],b2[0]-cnt))
            {
                if(colouring(a2[0],b2[0]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0],b2[0]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[0],b2[0]-cnt))) break;
            if(!(ifpositionnull2(a2[0],b2[0]-cnt)))
            {
                if(colouring(a2[0],b2[0]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0],b2[0]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[0]+cnt<=548)
        {
            if(ifpositionnull1(a2[0]+cnt,b2[0]))
            {
                if(colouring(a2[0]+cnt,b2[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0]+cnt,b2[0],64,64);
            }
            if(!(ifpositionnull1(a2[0]+cnt,b2[0]))) break;
            if(!(ifpositionnull2(a2[0]+cnt,b2[0])))
            {
                if(colouring(a2[0]+cnt,b2[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0]+cnt,b2[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[0]-cnt>=100)
        {
            if(ifpositionnull1(a2[0]-cnt,b2[0]))
            {
                if(colouring(a2[0]-cnt,b2[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0]-cnt,b2[0],64,64);
            }
            if(!(ifpositionnull1(a2[0]-cnt,b2[0]))) break;
            if(!(ifpositionnull2(a2[0]-cnt,b2[0])))
            {
                if(colouring(a2[0]-cnt,b2[0])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[0]-cnt,b2[0],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b2[0];
        c2=mxs-a2[0];
        cnt=64;
        if(mxs==a2[0] && c1>0 && c1%64==0)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[0]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[0],b2[0]+cnt) || !ifpositionnull1(a2[0],b2[0]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[0]=b2[0]+c1;
                    castling2=0;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[0]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[0],b2[0]+cnt) || !ifpositionnull1(a2[0],b2[0]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            b2[0]=b2[0]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            castling2=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[0] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[0]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[0],b2[0]-cnt) || !ifpositionnull1(a2[0],b2[0]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        b2[0]=b2[0]+c1;
                        castling2=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[0]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[0],b2[0]-cnt) || !ifpositionnull1(a2[0],b2[0]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            b2[0]=b2[0]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            castling2=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[0] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[0]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[0]+cnt,b2[0]) || !ifpositionnull1(a2[0]+cnt,b2[0]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[0]=a2[0]+c2;
                        castling2=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[0]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[0]+cnt,b2[0]) || !ifpositionnull1(a2[0]+cnt,b2[0]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[0]=a2[0]+c2;
                            k=2;
                            castling2=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[0] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[0]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[0]-cnt,b2[0]) || !ifpositionnull1(a2[0]-cnt,b2[0]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[0]=a2[0]+c2;
                        castling2=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[0]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[0]-cnt,b2[0]) || !ifpositionnull1(a2[0]-cnt,b2[0]))
                    {

                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[0]=a2[0]+c2;
                            k=2;
                            castling2=0;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[0]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[0]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[0]=idx1;
            b2[0]=idx2;
            flag2[0]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[0]=idx1;
            b2[0]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[0]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[0]==3)
    {
        mode2=0;
        flag2[0]=0;
    }
}

void castleo2(int a,int b)
{
    int i,j,xi,yi,f=0,k=0,l,pi;
    if(mode2==0)
    {
        if(a>=a2[7] && a<=a2[7]+64 && b>=b2[7] && b<=b2[7]+64)
        {
            flag2[7]=1;
            f=1;
        }
    }
    if(flag2[7]==1 && mode2==2)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[7]=2;
                    k=1;
                    break;

                }
            }
        }
        if(k==0)
            flag2[7]=3;
    }
    if(f==1)
        mode2=2;
}

void drawcastleo2()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    idx1=a2[7];
    idx2=b2[7];
    if(flag2[7]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[7],b2[7],64,64);
        while(b2[7]+cnt<=478)
        {
            if(ifpositionnull1(a2[7],b2[7]+cnt))
            {
                iRectangle(a2[7],b2[7]+cnt,64,64);
            }
            if(!((ifpositionnull1(a2[7],b2[7]+cnt))))
                break;
            if(!(ifpositionnull2(a2[7],b2[7]+cnt)))
            {
                iRectangle(a2[7],b2[7]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[7]-cnt>=30)
        {
            if(ifpositionnull1(a2[7],b2[7]-cnt))
            {
                iRectangle(a2[7],b2[7]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[7],b2[7]-cnt))) break;
            if(!(ifpositionnull2(a2[7],b2[7]-cnt)))
            {
                iRectangle(a2[7],b2[7]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[7]+cnt<=548)
        {
            if(ifpositionnull1(a2[7]+cnt,b2[7]))
            {
                iRectangle(a2[7]+cnt,b2[7],64,64);
            }
            if(!(ifpositionnull1(a2[7]+cnt,b2[7]))) break;
            if(!(ifpositionnull2(a2[7]+cnt,b2[7])))
            {
                iRectangle(a2[7]+cnt,b2[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[7]-cnt>=100)
        {
            if(ifpositionnull1(a2[7]-cnt,b2[7]))
            {
                iRectangle(a2[7]-cnt,b2[7],64,64);
            }
            if(!(ifpositionnull1(a2[7]-cnt,b2[7]))) break;
            if(!(ifpositionnull2(a2[7]-cnt,b2[7])))
            {
                iRectangle(a2[7]-cnt,b2[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag2[7]==2)
    {
        cnt=64;
        if(colouring(a2[7],b2[7]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[7],b2[7],64,64);
        while(b2[7]+cnt<=478)
        {
            if(ifpositionnull1(a2[7],b2[7]+cnt))
            {
                if(colouring(a2[7],b2[7]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7],b2[7]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[7],b2[7]+cnt))) break;
            if(!(ifpositionnull2(a2[7],b2[7]+cnt)))
            {
                if(colouring(a2[7],b2[7]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7],b2[7]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[7]-cnt>=30)
        {
            if(ifpositionnull1(a2[7],b2[7]-cnt))
            {
                if(colouring(a2[7],b2[7]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7],b2[7]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[7],b2[7]-cnt))) break;
            if(!(ifpositionnull2(a2[7],b2[7]-cnt)))
            {
                if(colouring(a2[7],b2[7]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7],b2[7]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[7]+cnt<=548)
        {
            if(ifpositionnull1(a2[7]+cnt,b2[7]))
            {
                if(colouring(a2[7]+cnt,b2[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7]+cnt,b2[7],64,64);
            }
            if(!(ifpositionnull1(a2[7]+cnt,b2[7]))) break;
            if(!(ifpositionnull2(a2[7]+cnt,b2[7])))
            {
                if(colouring(a2[7]+cnt,b2[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7]+cnt,b2[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[7]-cnt>=100)
        {
            if(ifpositionnull1(a2[7]-cnt,b2[7]))
            {
                if(colouring(a2[7]-cnt,b2[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7]-cnt,b2[7],64,64);
            }
            if(!(ifpositionnull1(a2[7]-cnt,b2[7]))) break;
            if(!(ifpositionnull2(a2[7]-cnt,b2[7])))
            {
                if(colouring(a2[7]-cnt,b2[7])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[7]-cnt,b2[7],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b2[7];
        c2=mxs-a2[7];
        cnt=64;
        if(mxs==a2[7] && c1>0 && c1%64==0)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[7]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[7],b2[7]+cnt) || !ifpositionnull1(a2[7],b2[7]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[7]=b2[7]+c1;
                    castling2=0;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[7]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[7],b2[7]+cnt) || !ifpositionnull1(a2[7],b2[7]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            b2[7]=b2[7]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            castling2=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[7] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[7]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[7],b2[7]-cnt) || !ifpositionnull1(a2[7],b2[7]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        b2[7]=b2[7]+c1;
                        castling2=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[7]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[7],b2[7]-cnt) || !ifpositionnull1(a2[7],b2[7]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            b2[7]=b2[7]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            castling2=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[7] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[7]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[7]+cnt,b2[7]) || !ifpositionnull1(a2[7]+cnt,b2[7]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[7]=a2[7]+c2;
                        castling2=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[7]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[7]+cnt,b2[7]) || !ifpositionnull1(a2[7]+cnt,b2[7]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[7]=a2[7]+c2;
                            k=2;
                            castling2=0;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[7] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[7]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[7]-cnt,b2[7]) || !ifpositionnull1(a2[7]-cnt,b2[7]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[7]=a2[7]+c2;
                        castling2=0;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[7]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[7]-cnt,b2[7]) || !ifpositionnull1(a2[7]-cnt,b2[7]))
                    {

                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[7]=a2[7]+c2;
                            castling2=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[7]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[7]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[7]=idx1;
            b2[7]=idx2;
            flag2[7]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[7]=idx1;
            b2[7]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[7]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[7]==3)
    {
        mode2=0;
        flag2[7]=0;
    }
}

void pawni(int a,int b)
{
    int idx,i,j,f=0,k=0,l,kn=0;
    if(mode1==0)
    {
        for(idx=8; idx<16; idx++)
        {
            {
                if(sp1[idx]==1)
                    continue;
                if(a>=a1[idx] && a<=a1[idx]+64 && b>=b1[idx] && b<=b1[idx]+64)
                {
                    flag1[idx]=1;
                    f=1;
                    ki=idx;
                    break;
                }

            }
        }
    }
    if(flag1[ki]==1 && mode1==2 && sp1[ki]!=1)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[ki]=2;
                    kn=1;
                    break;
                }
            }
        }
        if(kn==0)
            flag1[ki]=3;
    }
    if(f==1)
        mode1=2;
}

void pawnidraw()
{
    int k,l,f=0,idx1,idx2,idx3,idx4;
    idx1=a1[ki];
    idx2=b1[ki];
    if(flag1[ki]==1 && sp1[ki]!=1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[ki],b1[ki],64,64);
        if(ifpositionnull2(a1[ki],b1[ki]+64) && ifpositionnull1(a1[ki],b1[ki]+64))
        {
            iSetColor(250,130,130);
            iRectangle(a1[ki],b1[ki]+64,64,64);
        }
        if(b1[ki]==94 && ifpositionnull2(a1[ki],b1[ki]+64) && ifpositionnull1(a1[ki],b1[ki]+64) && ifpositionnull2(a1[ki],b1[ki]+128) && ifpositionnull1(a1[ki],b1[ki]+128))
        {
            iSetColor(250,130,130);
            iRectangle(a1[ki],b1[ki]+128,64,64);
        }
        if(!ifpositionnull1(a1[ki]+64,b1[ki]+64))
        {
            iSetColor(250,130,130);
            iRectangle(a1[ki]+64,b1[ki]+64,64,64);
        }
        if(!ifpositionnull1(a1[ki]-64,b1[ki]+64))
        {
            iSetColor(250,130,130);
            iRectangle(a1[ki]-64,b1[ki]+64,64,64);
        }
    }
    if(flag1[ki]==2 && sp1[ki]!=1)
    {
        if(mxs==a1[ki] && mys==b1[ki]+64)
        {
            if(ifpositionnull2(a1[ki],b1[ki]+64) && ifpositionnull1(a1[ki],b1[ki]+64))
            {
                b1[ki]=b1[ki]+64;
                flag1[ki]=0;
                mode2=0;
                mode1=1;
                f=1;
            }
        }
        else if(mxs==a1[ki] && mys==b1[ki]+128)
        {
            if(b1[ki]==94 && ifpositionnull2(a1[ki],b1[ki]+64) && ifpositionnull1(a1[ki],b1[ki]+64) && ifpositionnull2(a1[ki],b1[ki]+128) && ifpositionnull1(a1[ki],b1[ki]+128))
            {
                b1[ki]=b1[ki]+128;
                flag1[ki]=0;
                mode1=1;
                mode2=0;
                f=1;
            }
        }
        else if(mxs==a1[ki]+64 && mys==b1[ki]+64)
        {
            if(!ifpositionnull1(a1[ki]+64,b1[ki]+64))
            {
                for(l=0; l<16; l++)
                {
                    if(a1[ki]+64==a2[l] && b1[ki]+64==b2[l])
                    {
                        alive2[l]=1;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        a1[ki]=a1[ki]+64;
                        b1[ki]=b1[ki]+64;
                        mode2=0;
                        mode1=1;
                        flag1[ki]=0;
                        f=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a1[ki]-64 && mys==b1[ki]+64)
        {
            if(!ifpositionnull1(a1[ki]-64,b1[ki]+64))
            {
                for(l=0; l<16; l++)
                {
                    if(a1[ki]-64==a2[l] && b1[ki]+64==b2[l])
                    {
                        alive2[l]=1;
                        idx3=a2[l];
                        idx4=b2[l];
                        a2[l]=0;
                        b2[l]=0;
                        a1[ki]=a1[ki]-64;
                        b1[ki]=b1[ki]+64;
                        mode2=0;
                        mode1=1;
                        flag1[ki]=0;
                        f=2;
                        break;
                    }
                }
            }
        }
        if(f==0)
        {
            mode1=0;
            flag1[ki]=0;
        }
        if(f==1 && check1(a1[3],b1[3]))
        {
            a1[ki]=idx1;
            b1[ki]=idx2;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(f==2 && check1(a1[3],b1[3]))
        {
            a1[ki]=idx1;
            b1[ki]=idx2;
            mode1=0;
            mode2=1;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            checki=1;
        }
        else if((f==1 || f==2) && !check1(a1[3],b1[3]))
        {
            checki=0;
            ci++;
            co=0;
        }
    }
    if(flag1[ki]==3 && sp1[ki]!=1)
    {
        mode1=0;
        flag1[ki]=0;
    }
}

void pawno(int a,int b)
{
    int idx,i,j,f=0,k=0,l,kn=0;
    if(mode2==0)
    {
        for(idx=8; idx<16; idx++)
        {
            {
                if(sp2[idx]==1)
                    continue;
                if(a>=a2[idx] && a<=a2[idx]+64 && b>=b2[idx] && b<=b2[idx]+64)
                {
                    flag2[idx]=1;
                    f=1;
                    ko=idx;
                    break;
                }
            }
        }
    }
    if(flag2[ko]==1 && mode2==2 && sp2[ko]!=1)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[ko]=2;
                    kn=1;
                    break;
                }
            }
        }
        if(kn==0)
            flag2[ko]=3;
    }
    if(f==1)
        mode2=2;
}

void pawnodraw()
{
    int k,l,f=0,idx1,idx2,idx3,idx4;
    idx1=a2[ko];
    idx2=b2[ko];
    if(flag2[ko]==1 && sp2[ko]!=1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[ko],b2[ko],64,64);
        if(ifpositionnull2(a2[ko],b2[ko]-64) && ifpositionnull1(a2[ko],b2[ko]-64))
        {
            iSetColor(250,130,130);
            iRectangle(a2[ko],b2[ko]-64,64,64);
        }
        if(b2[ko]==414 && ifpositionnull2(a2[ko],b2[ko]-64) && ifpositionnull1(a2[ko],b2[ko]-64) && ifpositionnull2(a2[ko],b2[ko]-128) && ifpositionnull1(a2[ko],b2[ko]-128))
        {
            iSetColor(250,130,130);
            iRectangle(a2[ko],b2[ko]-128,64,64);
        }
        if(!ifpositionnull2(a2[ko]-64,b2[ko]-64))
        {
            iSetColor(250,130,130);
            iRectangle(a2[ko]-64,b2[ko]-64,64,64);
        }
        if(!ifpositionnull2(a2[ko]+64,b2[ko]-64))
        {
            iSetColor(250,130,130);
            iRectangle(a2[ko]+64,b2[ko]-64,64,64);
        }
    }
    if(flag2[ko]==2 && sp2[ko]!=1)
    {
        if(mxs==a2[ko] && mys==b2[ko]-64)
        {
            if(ifpositionnull2(a2[ko],b2[ko]-64) && ifpositionnull1(a2[ko],b2[ko]-64))
            {
                b2[ko]=b2[ko]-64;
                flag2[ko]=0;
                mode2=1;
                mode1=0;
                f=1;
            }
        }
        else if(mxs==a2[ko] && mys==b2[ko]-128)
        {
            if(b2[ko]==414 && ifpositionnull2(a2[ko],b2[ko]-64) && ifpositionnull1(a2[ko],b2[ko]-64) && ifpositionnull2(a2[ko],b2[ko]-128) && ifpositionnull1(a2[ko],b2[ko]-128))
            {
                b2[ko]=b2[ko]-128;
                flag2[ko]=0;
                mode2=1;
                mode1=0;
                f=1;
            }
        }
        else if(mxs==a2[ko]-64 && mys==b2[ko]-64)
        {
            if(!ifpositionnull2(a2[ko]-64,b2[ko]-64))
            {
                for(l=0; l<16; l++)
                {
                    if(a2[ko]-64==a1[l] && b2[ko]-64==b1[l])
                    {
                        alive1[l]=1;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        a2[ko]=a2[ko]-64;
                        b2[ko]=b2[ko]-64;
                        mode1=0;
                        mode2=1;
                        flag2[ko]=0;
                        f=2;
                        break;
                    }
                }
            }
        }
        else if(mxs==a2[ko]+64 && mys==b2[ko]-64)
        {
            if(!ifpositionnull2(a2[ko]+64,b2[ko]-64))
            {
                for(l=0; l<16; l++)
                {
                    if(a2[ko]+64==a1[l] && b2[ko]-64==b1[l])
                    {
                        alive1[l]=1;
                        idx3=a1[l];
                        idx4=b1[l];
                        a1[l]=0;
                        b1[l]=0;
                        a2[ko]=a2[ko]+64;
                        b2[ko]=b2[ko]-64;
                        mode1=0;
                        mode2=1;
                        flag2[ko]=0;
                        f=2;
                        break;
                    }
                }
            }
        }
        if(f==0)
        {
            mode2=0;
            flag2[ko]=0;
        }
        if(f==1 && check2(a2[3],b2[3]))
        {
            a2[ko]=idx1;
            b2[ko]=idx2;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(f==2 && check2(a2[3],b2[3]))
        {
            a2[ko]=idx1;
            b2[ko]=idx2;
            mode2=0;
            mode1=1;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            checko=1;
        }
        else if((f==1 || f==2) && !check2(a2[3],b2[3]))
        {
            checko=0;
            ci++;
            co=0;
        }
    }
    if(flag2[ko]==3 && sp2[ko]!=1)
    {
        mode2=0;
        flag2[ko]=0;
    }
}

void coordinates()
{
    int i,j;
    x[0][0]=100;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(j==0)
                x[i][j]=x[0][0];
            else
                x[i][j]=x[i][j-1]+64;
        }
    }
    y[0][0]=30;
    for(i=0; i<8; i++)
    {
        j=0;
        if(i!=0)
            y[i][j]=y[i-1][j]+64;
        for(j=0; j<8; j++)
        {
            if(j!=0)
                y[i][j]=y[i][j-1];
        }
    }
}

void spi(int a,int b)
{
    int idx,i,j,f=0,k=0,l,kn=0;
    for(k=8; k<16; k++)
    {
        if(b1[k]==478)
            sp1[k]=1;
    }
    if(mode1==0)
    {
        for(idx=8; idx<16; idx++)
        {
            if(sp1[idx]==1)
            {
                if(a>=a1[idx] && a<=a1[idx]+64 && b>=b1[idx] && b<=b1[idx]+64)
                {
                    flag1[idx]=1;
                    f=1;
                    kis=idx;
                    break;
                }
            }
        }
    }
    if(flag1[kis]==1 && mode1==2 && sp1[kis]==1)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag1[kis]=2;
                    kn=1;
                    break;
                }
            }
        }
        if(kn==0)
            flag1[kis]=3;
    }
    if(f==1)
        mode1=2;
}

void drawspi()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    if(sp1[kis]==1)
    {
        idx1=a1[kis];
        idx2=b1[kis];
    }
    if(flag1[kis]==1 && sp1[kis]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a1[kis],b1[kis],64,64);
        while(a1[kis]+cnt<=548 && b1[kis]+cnt<=478)
        {
            if(ifpositionnull2(a1[kis]+cnt,b1[kis]+cnt))
            {
                iRectangle(a1[kis]+cnt,b1[kis]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]+cnt,b1[kis]+cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]+cnt,b1[kis]+cnt)))
            {
                iRectangle(a1[kis]+cnt,b1[kis]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]-cnt>=100 && b1[kis]+cnt<=478)
        {
            if(ifpositionnull2(a1[kis]-cnt,b1[kis]+cnt))
            {
                iRectangle(a1[kis]-cnt,b1[kis]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]-cnt,b1[kis]+cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]-cnt,b1[kis]+cnt)))
            {
                iRectangle(a1[kis]-cnt,b1[kis]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]-cnt>=100 && b1[kis]-cnt>=30)
        {
            if(ifpositionnull2(a1[kis]-cnt,b1[kis]-cnt))
            {
                iRectangle(a1[kis]-cnt,b1[kis]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]-cnt,b1[kis]-cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]-cnt,b1[kis]-cnt)))
            {
                iRectangle(a1[kis]-cnt,b1[kis]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]+cnt<=548 && b1[kis]-cnt>=30)
        {
            if(ifpositionnull2(a1[kis]+cnt,b1[kis]-cnt))
            {
                iRectangle(a1[kis]+cnt,b1[kis]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]+cnt,b1[kis]-cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]+cnt,b1[kis]-cnt)))
            {
                iRectangle(a1[kis]+cnt,b1[kis]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[kis]+cnt<=478)
        {
            if(ifpositionnull2(a1[kis],b1[kis]+cnt))
            {
                iRectangle(a1[kis],b1[kis]+cnt,64,64);
            }
            if(!((ifpositionnull2(a1[kis],b1[kis]+cnt)))) break;
            if(!(ifpositionnull1(a1[kis],b1[kis]+cnt)))
            {
                iRectangle(a1[kis],b1[kis]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[kis]-cnt>=30)
        {
            if(ifpositionnull2(a1[kis],b1[kis]-cnt))
            {
                iRectangle(a1[kis],b1[kis]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis],b1[kis]-cnt))) break;
            if(!(ifpositionnull1(a1[kis],b1[kis]-cnt)))
            {
                iRectangle(a1[kis],b1[kis]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]+cnt<=548)
        {
            if(ifpositionnull2(a1[kis]+cnt,b1[kis]))
            {
                iRectangle(a1[kis]+cnt,b1[kis],64,64);
            }
            if(!(ifpositionnull2(a1[kis]+cnt,b1[kis]))) break;
            if(!(ifpositionnull1(a1[kis]+cnt,b1[kis])))
            {
                iRectangle(a1[kis]+cnt,b1[kis],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]-cnt>=100)
        {
            if(ifpositionnull2(a1[kis]-cnt,b1[kis]))
            {
                iRectangle(a1[kis]-cnt,b1[kis],64,64);
            }
            if(!(ifpositionnull2(a1[kis]-cnt,b1[kis]))) break;
            if(!(ifpositionnull1(a1[kis]-cnt,b1[kis])))
            {
                iRectangle(a1[kis]-cnt,b1[kis],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag1[kis]==2 && sp1[kis]==1)
    {
        cnt=64;
        if(colouring(a1[kis],b1[kis]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a1[kis],b1[kis],64,64);
        while(a1[kis]+cnt<=548 && b1[kis]+cnt<=478)
        {
            if(ifpositionnull2(a1[kis]+cnt,b1[kis]+cnt))
            {
                if(colouring(a1[kis]+cnt,b1[kis]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[kis]+cnt,b1[kis]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]+cnt,b1[kis]+cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]+cnt,b1[kis]+cnt)))
            {
                if(colouring(a1[kis]+cnt,b1[kis]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[kis]+cnt,b1[kis]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]-cnt>=100 && b1[kis]+cnt<=478)
        {
            if(ifpositionnull2(a1[kis]-cnt,b1[kis]+cnt))
            {
                if(colouring(a1[kis]-cnt,b1[kis]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[kis]-cnt,b1[kis]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]-cnt,b1[kis]+cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]-cnt,b1[kis]+cnt)))
            {
                if(colouring(a1[kis]-cnt,b1[kis]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[kis]-cnt,b1[kis]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]-cnt>=100 && b1[kis]-cnt>=30)
        {
            if(ifpositionnull2(a1[kis]-cnt,b1[kis]-cnt))
            {
                if(colouring(a1[kis]-cnt,b1[kis]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[kis]-cnt,b1[kis]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]-cnt,b1[kis]-cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]-cnt,b1[kis]-cnt)))
            {
                if(colouring(a1[kis]-cnt,b1[kis]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]+cnt<=548 && b1[kis]-cnt>=30)
        {
            if(ifpositionnull2(a1[kis]+cnt,b1[kis]-cnt))
            {
                if(colouring(a1[kis]+cnt,b1[kis]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[kis]+cnt,b1[kis]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis]+cnt,b1[kis]-cnt)))
                break;
            if(!(ifpositionnull1(a1[kis]+cnt,b1[kis]-cnt)))
            {
                if(colouring(a1[kis]+cnt,b1[kis]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[kis]+cnt,b1[kis]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[kis]+cnt<=478)
        {
            if(ifpositionnull2(a1[kis],b1[kis]+cnt))
            {
                if(colouring(a1[kis],b1[kis]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis],b1[kis]+cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis],b1[kis]+cnt))) break;
            if(!(ifpositionnull1(a1[kis],b1[kis]+cnt)))
            {
                if(colouring(a1[kis],b1[kis]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis],b1[kis]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b1[kis]-cnt>=30)
        {
            if(ifpositionnull2(a1[kis],b1[kis]-cnt))
            {
                if(colouring(a1[kis],b1[kis]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis],b1[kis]-cnt,64,64);
            }
            if(!(ifpositionnull2(a1[kis],b1[kis]-cnt))) break;
            if(!(ifpositionnull1(a1[kis],b1[kis]-cnt)))
            {
                if(colouring(a1[kis],b1[kis]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis],b1[kis]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]+cnt<=548)
        {
            if(ifpositionnull2(a1[kis]+cnt,b1[kis]))
            {
                if(colouring(a1[kis]+cnt,b1[kis])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis]+cnt,b1[kis],64,64);
            }
            if(!(ifpositionnull2(a1[kis]+cnt,b1[kis]))) break;
            if(!(ifpositionnull1(a1[kis]+cnt,b1[kis])))
            {
                if(colouring(a1[kis]+cnt,b1[kis])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis]+cnt,b1[kis],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a1[kis]-cnt>=100)
        {
            if(ifpositionnull2(a1[kis]-cnt,b1[kis]))
            {
                if(colouring(a1[kis]-cnt,b1[kis])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis]-cnt,b1[kis],64,64);
            }
            if(!(ifpositionnull2(a1[kis]-cnt,b1[kis]))) break;
            if(!(ifpositionnull1(a1[kis]-cnt,b1[kis])))
            {
                if(colouring(a1[kis]-cnt,b1[kis])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a1[kis]-cnt,b1[kis],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b1[kis];
        c2=mxs-a1[kis];
        cnt=64;
        if(mxs==a1[kis] && c1>0 && c1%64==0)
        {
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[kis]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[kis],b1[kis]+cnt) || !ifpositionnull2(a1[kis],b1[kis]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[kis]=b1[kis]+c1;
                    k=1;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[kis]+cnt !=mys)
                {
                    if(!ifpositionnull1(a1[kis],b1[kis]+cnt) || !ifpositionnull2(a1[kis],b1[kis]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[kis]=b1[kis]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a1[kis] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(b1[kis]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[kis],b1[kis]-cnt) || !ifpositionnull2(a1[kis],b1[kis]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        b1[kis]=b1[kis]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(b1[kis]-cnt !=mys)
                {
                    if(!ifpositionnull1(a1[kis],b1[kis]-cnt) || !ifpositionnull2(a1[kis],b1[kis]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            b1[kis]=b1[kis]+c1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[kis] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[kis]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[kis]+cnt,b1[kis]) || !ifpositionnull2(a1[kis]+cnt,b1[kis]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[kis]=a1[kis]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[kis]+cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[kis]+cnt,b1[kis]) || !ifpositionnull2(a1[kis]+cnt,b1[kis]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[kis]=a1[kis]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b1[kis] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while(a1[kis]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[kis]-cnt,b1[kis]) || !ifpositionnull2(a1[kis]-cnt,b1[kis]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[kis]=a1[kis]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while(a1[kis]-cnt !=mxs)
                {
                    if(!ifpositionnull1(a1[kis]-cnt,b1[kis]) || !ifpositionnull2(a1[kis]-cnt,b1[kis]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[kis]=a1[kis]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[kis]+cnt!=mxs) && (b1[kis]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[kis]+cnt,b1[kis]+cnt) || !ifpositionnull2(a1[kis]+cnt,b1[kis]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b1[kis]=b1[kis]+c1;
                    a1[kis]=a1[kis]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((b1[kis]+cnt!=mys) && (a1[kis]+cnt!=mxs))
                {
                    if(!ifpositionnull1(a1[kis]+cnt,b1[kis]+cnt) || !ifpositionnull2(a1[kis]+cnt,b1[kis]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a1[kis]=a1[kis]+c2;
                            b1[kis]=b1[kis]+c1;
                            a2[l]=0;
                            b2[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && c1==-c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[kis]-cnt!=mxs) && (b1[kis]+cnt!=mys))
                {
                    if(!ifpositionnull1(a1[kis]-cnt,b1[kis]+cnt) || !ifpositionnull2(a1[kis]-cnt,b1[kis]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[kis]=a1[kis]+c2;
                        b1[kis]=b1[kis]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[kis]-cnt !=mxs) && (b1[kis]+cnt !=mys))
                {
                    if(!ifpositionnull1(a1[kis]-cnt,b1[kis]+cnt) || !ifpositionnull2(a1[kis]-cnt,b1[kis]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }

                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[kis]=a1[kis]+c2;
                            b1[kis]=b1[kis]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[kis]-cnt!=mxs) && (b1[kis]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[kis]-cnt,b1[kis]-cnt) || !ifpositionnull2(a1[kis]-cnt,b1[kis]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[kis]=a1[kis]+c2;
                        b1[kis]=b1[kis]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[kis]-cnt !=mxs) && (b1[kis]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[kis]-cnt,b1[kis]-cnt) || !ifpositionnull2(a1[kis]-cnt,b1[kis]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[kis]=a1[kis]+c2;
                            b1[kis]=b1[kis]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
            {
                while((a1[kis]+cnt!=mxs) && (b1[kis]-cnt!=mys))
                {
                    if(!ifpositionnull1(a1[kis]+cnt,b1[kis]-cnt) || !ifpositionnull2(a1[kis]+cnt,b1[kis]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull1(mxs,mys) && ifpositionnull2(mxs,mys))
                    {
                        a1[kis]=a1[kis]+c2;
                        b1[kis]=b1[kis]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull1(mxs,mys)))
            {
                cnt=64;
                while((a1[kis]+cnt !=mxs) && (b1[kis]-cnt !=mys))
                {
                    if(!ifpositionnull1(a1[kis]+cnt,b1[kis]-cnt) || !ifpositionnull2(a1[kis]+cnt,b1[kis]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a2[l] && mys==b2[l])
                        {
                            alive2[l]=1;
                            idx3=a2[l];
                            idx4=b2[l];
                            a2[l]=0;
                            b2[l]=0;
                            a1[kis]=a1[kis]+c2;
                            b1[kis]=b1[kis]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0 && sp1[kis]==1)
        {
            mode1=0;
            flag1[kis]=0;
        }
        if((k==1 || k==2) && !(check1(a1[3],b1[3])))
        {
            flag1[kis]=0;
            mode2=0;
            mode1=1;
            checki=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check1(a1[3],b1[3]))
        {
            a1[kis]=idx1;
            b1[kis]=idx2;
            flag1[kis]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
        else if(k==2 && check1(a1[3],b1[3]))
        {
            a1[kis]=idx1;
            b1[kis]=idx2;
            alive2[l]=0;
            a2[l]=idx3;
            b2[l]=idx4;
            flag1[kis]=0;
            mode1=0;
            mode2=1;
            checki=1;
        }
    }
    if(flag1[kis]==3 && sp1[kis]==1)
    {
        mode1=0;
        flag1[kis]=0;
    }
}

void spo(int a,int b)
{
    int idx,i,j,f=0,k=0,l,kn=0;
    for(k=8; k<16; k++)
    {
        if(b2[k]==30)
            sp2[k]=1;
    }
    if(mode2==0)
    {
        for(idx=8; idx<16; idx++)
        {
            if(sp2[idx]==1)
            {
                if(a>=a2[idx] && a<=a2[idx]+64 && b>=b2[idx] && b<=b2[idx]+64)
                {
                    flag2[idx]=1;
                    f=1;
                    kos=idx;
                    break;
                }
            }
        }
    }
    if(flag2[kos]==1 && mode2==2 && sp2[kos]==1)
    {
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(a>=x[i][j] && a<=x[i][j]+64 && b>=y[i][j] && b<=y[i][j]+64)
                {
                    mxs=x[i][j];
                    mys=y[i][j];
                    flag2[kos]=2;
                    kn=1;
                    break;
                }
            }
        }
        if(kn==0)
            flag2[kos]=3;
    }
    if(f==1)
        mode2=2;
}
void drawspo()
{
    int i,j,k=0,l,c1,c2,cnt=64,k1=1,k2=1,idx1,idx2,idx3,idx4;
    if(sp2[kos]==1)
    {
        idx1=a2[kos];
        idx2=b2[kos];
    }
    if(flag2[kos]==1 && sp2[kos]==1)
    {
        iSetColor(250,130,130);
        iRectangle(a2[kos],b2[kos],64,64);
        while(a2[kos]+cnt<=548 && b2[kos]+cnt<=478)
        {
            if(ifpositionnull1(a2[kos]+cnt,b2[kos]+cnt))
            {
                iRectangle(a2[kos]+cnt,b2[kos]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]+cnt,b2[kos]+cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]+cnt,b2[kos]+cnt)))
            {
                iRectangle(a2[kos]+cnt,b2[kos]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]-cnt>=100 && b2[kos]+cnt<=478)
        {
            if(ifpositionnull1(a2[kos]-cnt,b2[kos]+cnt))
            {
                iRectangle(a2[kos]-cnt,b2[kos]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]-cnt,b2[kos]+cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]-cnt,b2[kos]+cnt)))
            {
                iRectangle(a2[kos]-cnt,b2[kos]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]-cnt>=100 && b2[kos]-cnt>=30)
        {
            if(ifpositionnull1(a2[kos]-cnt,b2[kos]-cnt))
            {
                iRectangle(a2[kos]-cnt,b2[kos]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]-cnt,b2[kos]-cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]-cnt,b2[kos]-cnt)))
            {
                iRectangle(a2[kos]-cnt,b2[kos]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]+cnt<=548 && b2[kos]-cnt>=30)
        {
            if(ifpositionnull1(a2[kos]+cnt,b2[kos]-cnt))
            {
                iRectangle(a2[kos]+cnt,b2[kos]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]+cnt,b2[kos]-cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]+cnt,b2[kos]-cnt)))
            {
                iRectangle(a2[kos]+cnt,b2[kos]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[kos]+cnt<=478)
        {
            if(ifpositionnull1(a2[kos],b2[kos]+cnt))
            {
                iRectangle(a2[kos],b2[kos]+cnt,64,64);
            }
            if(!((ifpositionnull1(a2[kos],b2[kos]+cnt)))) break;
            if(!(ifpositionnull2(a2[kos],b2[kos]+cnt)))
            {
                iRectangle(a2[kos],b2[kos]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[kos]-cnt>=30)
        {
            if(ifpositionnull1(a2[kos],b2[kos]-cnt))
            {
                iRectangle(a2[kos],b2[kos]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos],b2[kos]-cnt))) break;
            if(!(ifpositionnull2(a2[kos],b2[kos]-cnt)))
            {
                iRectangle(a2[kos],b2[kos]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]+cnt<=548)
        {
            if(ifpositionnull1(a2[kos]+cnt,b2[kos]))
            {
                iRectangle(a2[kos]+cnt,b2[kos],64,64);
            }
            if(!(ifpositionnull1(a2[kos]+cnt,b2[kos]))) break;
            if(!(ifpositionnull2(a2[kos]+cnt,b2[kos])))
            {
                iRectangle(a2[kos]+cnt,b2[kos],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]-cnt>=100)
        {
            if(ifpositionnull1(a2[kos]-cnt,b2[kos]))
            {
                iRectangle(a2[kos]-cnt,b2[kos],64,64);
            }
            if(!(ifpositionnull1(a2[kos]-cnt,b2[kos]))) break;
            if(!(ifpositionnull2(a2[kos]-cnt,b2[kos])))
            {
                iRectangle(a2[kos]-cnt,b2[kos],64,64);
                break;
            }
            cnt=cnt+64;
        }
    }
    else if(flag2[kos]==2 && sp2[kos]==1)
    {
        cnt=64;
        if(colouring(a2[kos],b2[kos]))
            iSetColor(0,0,0);
        else
            iSetColor(255,255,255);
        iRectangle(a2[kos],b2[kos],64,64);
        while(a2[kos]+cnt<=548 && b2[kos]+cnt<=478)
        {
            if(ifpositionnull1(a2[kos]+cnt,b2[kos]+cnt))
            {
                if(colouring(a2[kos]+cnt,b2[kos]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[kos]+cnt,b2[kos]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]+cnt,b2[kos]+cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]+cnt,b2[kos]+cnt)))
            {
                if(colouring(a2[kos]+cnt,b2[kos]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[kos]+cnt,b2[kos]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]-cnt>=100 && b2[kos]+cnt<=478)
        {
            if(ifpositionnull1(a2[kos]-cnt,b2[kos]+cnt))
            {
                if(colouring(a2[kos]-cnt,b2[kos]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[kos]-cnt,b2[kos]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]-cnt,b2[kos]+cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]-cnt,b2[kos]+cnt)))
            {
                if(colouring(a2[kos]-cnt,b2[kos]+cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[kos]-cnt,b2[kos]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]-cnt>=100 && b2[kos]-cnt>=30)
        {
            if(ifpositionnull1(a2[kos]-cnt,b2[kos]-cnt))
            {
                if(colouring(a2[kos]-cnt,b2[kos]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[kos]-cnt,b2[kos]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]-cnt,b2[kos]-cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]-cnt,b2[kos]-cnt)))
            {
                if(colouring(a2[kos]-cnt,b2[kos]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a1[2]-cnt,b1[2]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]+cnt<=548 && b2[kos]-cnt>=30)
        {
            if(ifpositionnull1(a2[kos]+cnt,b2[kos]-cnt))
            {
                if(colouring(a2[kos]+cnt,b2[kos]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[kos]+cnt,b2[kos]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos]+cnt,b2[kos]-cnt)))
                break;
            if(!(ifpositionnull2(a2[kos]+cnt,b2[kos]-cnt)))
            {
                if(colouring(a2[kos]+cnt,b2[kos]-cnt))
                    iSetColor(0,0,0);
                else
                    iSetColor(255,255,255);
                iRectangle(a2[kos]+cnt,b2[kos]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[kos]+cnt<=478)
        {
            if(ifpositionnull1(a2[kos],b2[kos]+cnt))
            {
                if(colouring(a2[kos],b2[kos]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos],b2[kos]+cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos],b2[kos]+cnt))) break;
            if(!(ifpositionnull2(a2[kos],b2[kos]+cnt)))
            {
                if(colouring(a2[kos],b2[kos]+cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos],b2[kos]+cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(b2[kos]-cnt>=30)
        {
            if(ifpositionnull1(a2[kos],b2[kos]-cnt))
            {
                if(colouring(a2[kos],b2[kos]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos],b2[kos]-cnt,64,64);
            }
            if(!(ifpositionnull1(a2[kos],b2[kos]-cnt))) break;
            if(!(ifpositionnull2(a2[kos],b2[kos]-cnt)))
            {
                if(colouring(a2[kos],b2[kos]-cnt)) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos],b2[kos]-cnt,64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]+cnt<=548)
        {
            if(ifpositionnull1(a2[kos]+cnt,b2[kos]))
            {
                if(colouring(a2[kos]+cnt,b2[kos])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos]+cnt,b2[kos],64,64);
            }
            if(!(ifpositionnull1(a2[kos]+cnt,b2[kos]))) break;
            if(!(ifpositionnull2(a2[kos]+cnt,b2[kos])))
            {
                if(colouring(a2[kos]+cnt,b2[kos])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos]+cnt,b2[kos],64,64);
                break;
            }
            cnt=cnt+64;
        }
        cnt=64;
        while(a2[kos]-cnt>=100)
        {
            if(ifpositionnull1(a2[kos]-cnt,b2[kos]))
            {
                if(colouring(a2[kos]-cnt,b2[kos])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos]-cnt,b2[kos],64,64);
            }
            if(!(ifpositionnull1(a2[kos]-cnt,b2[kos]))) break;
            if(!(ifpositionnull2(a2[kos]-cnt,b2[kos])))
            {
                if(colouring(a2[kos]-cnt,b2[kos])) iSetColor(0,0,0);
                else iSetColor(255,255,255);
                iRectangle(a2[kos]-cnt,b2[kos],64,64);
                break;
            }
            cnt=cnt+64;
        }
        c1=mys-b2[kos];
        c2=mxs-a2[kos];
        cnt=64;
        if(mxs==a2[kos] && c1>0 && c1%64==0)
        {
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[kos]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[kos],b2[kos]+cnt) || !ifpositionnull1(a2[kos],b2[kos]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[kos]=b2[kos]+c1;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[kos]+cnt !=mys)
                {
                    if(!ifpositionnull2(a2[kos],b2[kos]+cnt) || !ifpositionnull1(a2[kos],b2[kos]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            b2[kos]=b2[kos]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mxs==a2[kos] && c1<0 && c1%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(b2[kos]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[kos],b2[kos]-cnt) || !ifpositionnull1(a2[kos],b2[kos]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        b2[kos]=b2[kos]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(b2[kos]-cnt !=mys)
                {
                    if(!ifpositionnull2(a2[kos],b2[kos]-cnt) || !ifpositionnull1(a2[kos],b2[kos]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            b2[kos]=b2[kos]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[kos] && c2>0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[kos]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[kos]+cnt,b2[kos]) || !ifpositionnull1(a2[kos]+cnt,b2[kos]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[kos]=a2[kos]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[kos]+cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[kos]+cnt,b2[kos]) || !ifpositionnull1(a2[kos]+cnt,b2[kos]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[kos]=a2[kos]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(mys==b2[kos] && c2<0 && c2%64==0)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while(a2[kos]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[kos]-cnt,b2[kos]) || !ifpositionnull1(a2[kos]-cnt,b2[kos]))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[kos]=a2[kos]+c2;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while(a2[kos]-cnt !=mxs)
                {
                    if(!ifpositionnull2(a2[kos]-cnt,b2[kos]) || !ifpositionnull1(a2[kos]-cnt,b2[kos]))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[kos]=a2[kos]+c2;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2>0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[kos]+cnt!=mxs) && (b2[kos]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[kos]+cnt,b2[kos]+cnt) || !ifpositionnull1(a2[kos]+cnt,b2[kos]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    b2[kos]=b2[kos]+c1;
                    a2[kos]=a2[kos]+c2;
                    k=1;
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((b2[kos]+cnt!=mys) && (a2[kos]+cnt!=mxs))
                {
                    if(!ifpositionnull2(a2[kos]+cnt,b2[kos]+cnt) || !ifpositionnull1(a2[kos]+cnt,b2[kos]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            a2[kos]=a2[kos]+c2;
                            b2[kos]=b2[kos]+c1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1>0 && c2<0 && c1%64==0 && c2%64==0 && c1==-c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[kos]-cnt!=mxs) && (b2[kos]+cnt!=mys))
                {
                    if(!ifpositionnull2(a2[kos]-cnt,b2[kos]+cnt) || !ifpositionnull1(a2[kos]-cnt,b2[kos]+cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[kos]=a2[kos]+c2;
                        b2[kos]=b2[kos]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[kos]-cnt !=mxs) && (b2[kos]+cnt !=mys))
                {
                    if(!ifpositionnull2(a2[kos]-cnt,b2[kos]+cnt) || !ifpositionnull1(a2[kos]-cnt,b2[kos]+cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[kos]=a2[kos]+c2;
                            b2[kos]=b2[kos]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2<0 && c1%64==0 && c2%64==0 && c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[kos]-cnt!=mxs) && (b2[kos]-cnt!=mys))
                {
                    if(!ifpositionnull2(a2[kos]-cnt,b2[kos]-cnt) || !ifpositionnull1(a2[kos]-cnt,b2[kos]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[kos]=a2[kos]+c2;
                        b2[kos]=b2[kos]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[kos]-cnt !=mxs) && (b2[kos]-cnt !=mys))
                {
                    if(!ifpositionnull2(a2[kos]-cnt,b2[kos]-cnt) || !ifpositionnull1(a2[kos]-cnt,b2[kos]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[kos]=a2[kos]+c2;
                            b2[kos]=b2[kos]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        else if(c1<0 && c2>0 && c1%64==0 && c2%64==0 && -c1==c2)
        {
            k1=1;
            k2=1;
            cnt=64;
            if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
            {
                while((a2[kos]+cnt!=mxs) && (b2[kos]-cnt!=mys))
                {
                    if(!ifpositionnull2(a2[kos]+cnt,b2[kos]-cnt) || !ifpositionnull1(a2[kos]+cnt,b2[kos]-cnt))
                    {
                        k1=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k1==1)
                {
                    if(ifpositionnull2(mxs,mys) && ifpositionnull1(mxs,mys))
                    {
                        a2[kos]=a2[kos]+c2;
                        b2[kos]=b2[kos]+c1;
                        k=1;
                    }
                }
            }
            else if(!(ifpositionnull2(mxs,mys)))
            {
                cnt=64;
                while((a2[kos]+cnt !=mxs) && (b2[kos]-cnt !=mys))
                {
                    if(!ifpositionnull2(a2[kos]+cnt,b2[kos]-cnt) || !ifpositionnull1(a2[kos]+cnt,b2[kos]-cnt))
                    {
                        k2=0;
                        break;
                    }
                    cnt=cnt+64;
                }
                if(k2==1)
                {
                    for(l=0; l<16; l++)
                    {
                        if(mxs==a1[l] && mys==b1[l])
                        {
                            alive1[l]=1;
                            idx3=a1[l];
                            idx4=b1[l];
                            a1[l]=0;
                            b1[l]=0;
                            a2[kos]=a2[kos]+c2;
                            b2[kos]=b2[kos]+c1;
                            k=2;
                            break;
                        }
                    }
                }
            }
        }
        if(k==0)
        {
            mode2=0;
            flag2[kos]=0;
        }
        if((k==1 || k==2) && !(check2(a2[3],b2[3])))
        {
            flag2[kos]=0;
            mode1=0;
            mode2=1;
            checko=0;
            ci++;
            if(k==2)
            {
                co=0;
            }
            else
                co++;
        }
        else if(k==1 && check2(a2[3],b2[3]))
        {
            a2[kos]=idx1;
            b2[kos]=idx2;
            flag2[kos]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
        else if(k==2 && check2(a2[3],b2[3]))
        {
            a2[kos]=idx1;
            b2[kos]=idx2;
            alive1[l]=0;
            a1[l]=idx3;
            b1[l]=idx4;
            flag2[kos]=0;
            mode2=0;
            mode1=1;
            checko=1;
        }
    }
    if(flag2[kos]==3 && sp2[kos]==1)
    {
        mode2=0;
        flag2[kos]=0;
    }
}

void backtomain()
{
    iSetColor(73,207,35);
    iRectangle(700,40,200,40);
    iSetColor(233,57,27);
    iText(710,50,"BACK TO MAIN",GLUT_BITMAP_TIMES_ROMAN_24);
}
void laterdraw()
{
    if(checkmate1==1)
        {
            iClear();
            mode1=1;
            mode2=1;
            drawTexture(0,-50,checkmate1texture);
            iSetColor(128,0,64);
            iText(450,330,str1,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(460,300,"WON",GLUT_BITMAP_TIMES_ROMAN_24);
            backtomain();
        }
        else if(checkmate2==1)
        {
            iClear();
            mode1=1;
            mode2=1;
            drawTexture(0,-100,checkmate2texture);
            iSetColor(219,136,23);
            iText(450,330,str,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(460,300,"WON",GLUT_BITMAP_TIMES_ROMAN_24);
            backtomain();
        }
        else if(m3>300)
        {
            iClear();
            mode1=1;
            mode2=1;
            drawTexture(0,-100,drawtexture);
            backtomain();
        }
        else if(m4>50)
        {
            iClear();
            mode1=1;
            mode2=1;
            drawTexture(0,-100,drawtexture);
            backtomain();
        }
        else if(stalemate1==1 || stalemate2==1)
        {
            iClear();
            mode1=1;
            mode2=1;
            drawTexture(0,-50,stalematetexture);
            backtomain();
        }

}

void iDraw()
{
    iClear();
    int i,j,k,m1,m2;
    if(open0==1)
    {
        drawTexture(0,0,covertexture);
    }
    if(open1==1)
    {
        loadcheck();
        if(checkmate1==1 || stalemate1==1 || checkmate2==1 || stalemate2==1 || m3>300 || m4>50)
        {
            resume=0;
            checkmate1=0;
            checkmate2=0;
            stalemate1=0;
            stalemate2=0;
            m3=0;
            m4=0;
        }
        frontPage();
    }
    if(open2==1)
    {
        secondPage();
    }
    if(openi[2]==1)
    {
        if(instr1==1)
        {
            drawTexture(0,-80,instruction1texture);
            iSetColor(73,207,35);
            iRectangle(650,590,100,40);
            iSetColor(233,57,27);
            iText(660,600,"NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(73,207,35);
            iRectangle(150,590,200,40);
            iSetColor(233,57,27);
            iText(155,600,"BACK TO MAIN",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(instr2==1)
        {
            drawTexture(0,-140,instruction2texture);
            iSetColor(73,207,35);
            iRectangle(650,590,100,40);
            iSetColor(233,57,27);
            iText(660,600,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(73,207,35);
            iRectangle(150,590,200,40);
            iSetColor(233,57,27);
            iText(155,600,"BACK TO MAIN",GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
    if(openi[3]==1)
    {
        resume=1;
        drawTexture(0,-80,credits1texture);
        iSetColor(73,207,35);
        iRectangle(700,40,200,40);
        iSetColor(233,57,27);
        iText(710,50,"BACK TO MAIN",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(open3==1)
    {
        drawTexture(0,0,chessbehindtexture);
        for(i=0; i<8; i++)
        {
            if(i%2==0)
            {
                for(j=0; j<8; j++)
                {
                    if(j%2==0)
                    {
                        iSetColor(0,0,0);
                        iFilledRectangle(x[i][j],y[i][j],64,64);
                    }
                    else
                    {
                        iSetColor(255,255,255);
                        iFilledRectangle(x[i][j],y[i][j],64,64);
                    }
                }
            }
            if(i%2!=0)
            {
                for(j=0; j<8; j++)
                {
                    if(j%2==1)
                    {
                        iSetColor(0,0,0);
                        iFilledRectangle(x[i][j],y[i][j],64,64);
                    }
                    else
                    {
                        iSetColor(255,255,255);
                        iFilledRectangle(x[i][j],y[i][j],64,64);
                    }
                }
            }
        }
        if(mode==1)
        {
            iSetColor(240,120,250);
            iFilledRectangle(100,50,60,60);
        }
        for(k=8; k<16; k++)
        {
            if(b1[k]==478)
                sp1[k]=1;
            if(b2[k]==30)
                sp2[k]=1;
        }
        for(k=8; k<16; k++)
        {
            if(alive1[k]==0 && sp1[k]!=1)
            {
                if(colouring(a1[k],b1[k]))
                    drawTexture(a1[k],b1[k],whitepawn2texture);
                else
                    drawTexture(a1[k],b1[k],whitepawn1texture);
            }
            if(alive1[k]==0 && sp1[k]==1)
            {
                if(colouring(a1[k],b1[k]))
                    drawTexture(a1[k],b1[k],whitepawn3texture);
                else
                    drawTexture(a1[k],b1[k],whitepawn4texture);
            }
        }
        if(alive1[0]==0)
        {
            if(colouring(a1[0],b1[0]))
                drawTexture(a1[0],b1[0],whitecastle2texture);
            else
                drawTexture(a1[0],b1[0],whitecastle1texture);
        }
        if(alive1[1]==0)
        {
            if(colouring(a1[1],b1[1]))
                drawTexture(a1[1],b1[1],whiteknight2texture);
            else
                drawTexture(a1[1],b1[1],whiteknight1texture);
        }
        if(alive1[2]==0)
        {
            if(colouring(a1[2],b1[2]))
                drawTexture(a1[2],b1[2],whiteelephant2texture);
            else
                drawTexture(a1[2],b1[2],whiteelephant1texture);
        }
        if(alive1[3]==0)
        {
            if(colouring(a1[3],b1[3]))
                drawTexture(a1[3],b1[3],whiteking2texture);
            else
                drawTexture(a1[3],b1[3],whiteking1texture);
        }
        if(alive1[4]==0)
        {
            if(colouring(a1[4],b1[4]))
                drawTexture(a1[4],b1[4],whitequeen2texture);
            else
                drawTexture(a1[4],b1[4],whitequeen1texture);
        }
        if(alive1[5]==0)
        {
            if(colouring(a1[5],b1[5]))
                drawTexture(a1[5],b1[5],whiteelephant2texture);
            else
                drawTexture(a1[5],b1[5],whiteelephant1texture);
        }
        if(alive1[6]==0)
        {
            if(colouring(a1[6],b1[6]))
                drawTexture(a1[6],b1[6],whiteknight2texture);
            else
                drawTexture(a1[6],b1[6],whiteknight1texture);
        }
        if(alive1[7]==0)
        {
            if(colouring(a1[7],b1[7]))
                drawTexture(a1[7],b1[7],whitecastle2texture);
            else
                drawTexture(a1[7],b1[7],whitecastle1texture);
        }
        for(k=8; k<16; k++)
        {
            if(alive2[k]==0 && sp2[k]!=1)
            {
                if(colouring(a2[k],b2[k]))
                    drawTexture(a2[k],b2[k],blackpawn2texture);
                else
                    drawTexture(a2[k],b2[k],blackpawn1texture);
            }
            if(alive2[k]==0 && sp2[k]==1)
            {
                if(colouring(a2[k],b2[k]))
                    drawTexture(a2[k],b2[k],blackpawn3texture);
                else
                    drawTexture(a2[k],b2[k],blackpawn4texture);
            }
        }
        if(alive2[0]==0)
        {
            if(colouring(a2[0],b2[0]))
                drawTexture(a2[0],b2[0],blackcastle2texture);
            else
                drawTexture(a2[0],b2[0],blackcastle1texture);
        }
        if(alive2[1]==0)
        {
            if(colouring(a2[1],b2[1]))
                drawTexture(a2[1],b2[1],blackknight2texture);
            else
                drawTexture(a2[1],b2[1],blackknight1texture);
        }
        if(alive2[2]==0)
        {
            if(colouring(a2[2],b2[2]))
                drawTexture(a2[2],b2[2],blackelephant2texture);
            else
                drawTexture(a2[2],b2[2],blackelephant1texture);
        }
        if(alive2[3]==0)
        {
            if(colouring(a2[3],b2[3]))
                drawTexture(a2[3],b2[3],blackking2texture);
            else
                drawTexture(a2[3],b2[3],blackking1texture);
        }
        if(alive2[4]==0)
        {
            if(colouring(a2[4],b2[4]))
                drawTexture(a2[4],b2[4],blackqueen2texture);
            else
                drawTexture(a2[4],b2[4],blackqueen1texture);
        }
        if(alive2[5]==0)
        {
            if(colouring(a2[5],b2[5]))
                drawTexture(a2[5],b2[5],blackelephant2texture);
            else
                drawTexture(a2[5],b2[5],blackelephant1texture);
        }
        if(alive2[6]==0)
        {
            if(colouring(a2[6],b2[6]))
                drawTexture(a2[6],b2[6],blackknight2texture);
            else
                drawTexture(a2[6],b2[6],blackknight1texture);
        }
        if(alive2[7]==0)
        {
            if(colouring(a2[7],b2[7]))
                drawTexture(a2[7],b2[7],blackcastle2texture);
            else
                drawTexture(a2[7],b2[7],blackcastle1texture);
        }
        if(mode1!=1) pawnidraw();
        if(mode2!=1) pawnodraw();
        if(mode1!=1) drawcastlei1();
        if(mode1!=1) drawcastlei2();
        if(mode2!=1) drawcastleo1();
        if(mode2!=1) drawcastleo2();
        if(mode1!=1) drawknighti1();
        if(mode1!=1) drawknighti2();
        if(mode2!=1) drawknighto1();
        if(mode2!=1) drawknighto2();
        if(mode1!=1) drawelephanti1();
        if(mode1!=1) drawelephanti2();
        if(mode2!=1) drawelephanto1();
        if(mode2!=1) drawelephanto2();
        if(mode1!=1) drawqueeni();
        if(mode2!=1) drawqueeno();
        if(mode1!=1) drawkingi();
        if(mode2!=1) drawkingo();
        if(mode1!=1) drawspi();
        if(mode2!=1) drawspo();
        m1=ci/10;
        m2=co/10;
        m3=ci;
        m4=co;
        sprintf(str3,"%d",ci);
        sprintf(str4,"%d",co);
        checkmatei();
        checkmateo();
        iSetColor(43,22,222);
        iFilledRectangle(20,300,50,30);
        iSetColor(250,238,14);
        if(m1==0)
        {
            iText(25,308,"00",GLUT_BITMAP_HELVETICA_18);
            iText(45,308,str3, GLUT_BITMAP_HELVETICA_18);
        }
        else if(m1>=1 && m1<10)
        {
            iText(25,308,"0",GLUT_BITMAP_HELVETICA_18);
            iText(35,308,str3, GLUT_BITMAP_HELVETICA_18);

        }
        else if(m1>=10)
        {
            iText(25,308,str3,GLUT_BITMAP_HELVETICA_18);

        }
        iSetColor(243,41,5);
        iFilledRectangle(20,240,50,30);
        iSetColor(250,238,14);
        if(m2==0)
        {
            iText(25,248,"00",GLUT_BITMAP_HELVETICA_18);
            iText(45,248,str4, GLUT_BITMAP_HELVETICA_18);
        }
        else if(m2>=1 && m2<10)
        {
            iText(25,248,"0",GLUT_BITMAP_HELVETICA_18);
            iText(35,248,str4, GLUT_BITMAP_HELVETICA_18);

        }
        else if(m2>=10)
        {
            iText(25,248,str4,GLUT_BITMAP_HELVETICA_18);

        }
        if(check1(a1[3],b1[3]))
        {
            iSetColor(16,234,252);
            iFilledRectangle(650,300,300,40);
            iSetColor(252,28,16);
            iText(655,310,"CHECK FOR WHITE KING", GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(check2(a2[3],b2[3]))
        {
            iSetColor(16,234,252);
            iFilledRectangle(650,300,300,40);
            iSetColor(252,28,16);
            iText(655,310,"CHECK FOR BLACK KING", GLUT_BITMAP_TIMES_ROMAN_24);

        }
        if(checki==1 || checko==1)
        {
            iSetColor(16,234,252);
            iFilledRectangle(650,230,200,40);
            iSetColor(252,28,16);
            iText(655,240,"INVALID MOVE", GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(mode2==0 || mode2==2)
        {
            iSetColor(44,118,209);
            iFilledRectangle(650,495,260,40);
            iSetColor(145,60,50);
            iText(657,505,str1,GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(44,118,209);
            iFilledRectangle(650,425,205,40);
            iSetColor(145,60,50);
            iText(657,435,"IT'S YOUR TURN",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(mode1==0 || mode1==2)
        {
            iSetColor(244,233,0);
            iFilledRectangle(650,110,205,40);
            iSetColor(145,60,50);
            iText(657,120,"IT'S YOUR TURN",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(244,233,0);
            iFilledRectangle(650,40,260,40);
            iSetColor(145,60,50);
            iText(657,50,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(checkmate1==1 || checkmate2==1)
        {
            mode1=1;
            mode2=1;
            checki=0;
            checko=0;
            iSetColor(244,70,19);
            iFilledRectangle(650,300,300,40);
            iSetColor(52,220,220);
            iText(655,310,"CHECKMATE", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(655,250,"(PRESS ENTER)",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(m3>200 || m4>50)
        {
            mode1=1;
            mode2=1;
            checki=0;
            checko=0;
            iSetColor(244,70,19);
            iFilledRectangle(650,300,300,40);
            iSetColor(52,220,220);
            iText(655,310,"DRAW", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(655,250,"(PRESS ENTER)",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(stalemate1==1 || stalemate2==1)
        {
            mode1=1;
            mode2=1;
            checki=0;
            checko=0;
            iSetColor(244,70,19);
            iFilledRectangle(650,300,300,40);
            iSetColor(52,220,220);
            iText(655,310,"STALEMATE", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(655,250,"(PRESS ENTER)",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        save();
        savecheck();
    }
    if(checkphoto==1)
        laterdraw();

}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (open1==1)
            frontpageopener(mx,my);
        else if(open2==1)
            secondpageopener(mx,my);
        else if(openi[2]==1)
            instrt1open(mx,my);
        else if(open3==1)
        {
            pawni(mx,my);
            pawno(mx,my);
            castlei1(mx,my);
            castlei2(mx,my);
            castleo1(mx,my);
            castleo2(mx,my);
            knighti1(mx,my);
            knighti2(mx,my);
            knighto1(mx,my);
            knighto2(mx,my);
            elephanti1(mx,my);
            elephanti2(mx,my);
            elephanto1(mx,my);
            elephanto2(mx,my);
            queeni(mx,my);
            queeno(mx,my);
            kingi(mx,my);
            kingo(mx,my);
            spi(mx,my);
            spo(mx,my);
        }
        else if(openi[3]==1)
            openi3(mx,my);
        if((checkmate1==1 || stalemate1==1 || checkmate2==1 || stalemate2==1 || m3>300 || m4>50)&& checkphoto==1)
            backmain(mx,my);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
}

void iKeyboard(unsigned char key)
{
    int i;
    if(open3==1 && (checkmate1==1 || checkmate2==1 || stalemate1==1 || stalemate2==1 || m3>300 || m4>50) && key=='\r')
    {
        open3=0;
        checkphoto=1;
    }
    if(key=='\e' && open3==1)
    {
        open3=0;
        open1=1;

    }
    if(open0==1 && key=='\r')
    {
        open0=0;
        open1=1;
    }
    if(open2 == 1 && openo[1]==1)
    {
        if(key == '\r')
        {
            openo[1] = 0;
        }
        else if(key=='\b')
        {
            str[len1]=' ';
            if(len1>0)
                len1--;
        }
        else
        {
            if(len1<16)
                len1++;
            str[len1] = key;
        }
    }
    if(open2==1 && openo[2]==1)
    {
        if(key == '\r')
        {
            openo[2] = 0;
        }
        else if(key=='\b')
        {
            str1[len2]=' ';
            if(len2>0)
                len2--;
        }
        else
        {
            if(len2<16)
                len2++;
            str1[len2] = key;
        }
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
}

int main()
{
    int i,j,k;
    mxs=0;
    mys=0;
    coordinates();
    mode=0;
    mode1=0;
    mode2=1;
    open3=0;
    len1 = 7;
    len2= 7;
    open0=1;
    open1 = 0;
    open2=0;
    instr1=0;
    instr2=0;
    str[0]= 0;
    strcpy(str,"Player 1");
    strcpy(str1,"Player 2");
    int N=16;
    i=0;
    for(j=0; j<=7; j++)
    {
        a1[j]=x[i][j];
        b1[j]=y[i][j];
    }
    i=1;
    for(j=0,k=8; j<=7,k<=15; j++,k++)
    {
        a1[k]=x[i][j];
        b1[k]=y[i][j];

    }
    i=7;
    for(j=0; j<=7; j++)
    {
        a2[j]=x[i][j];
        b2[j]=y[i][j];
    }
    i=6;
    for(j=0,k=8; j<=7,k<=15; j++,k++)
    {
        a2[k]=x[i][j];
        b2[k]=y[i][j];
    }
    iInitialize( 1024, 720, "Two Player Chess");
    return 0;
}
