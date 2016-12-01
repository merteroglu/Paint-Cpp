#include <graphics.h>
#include <windows.h>
#include <math.h>
#include <iostream>
#define Brush_Size 10

using namespace std;

POINT cursorPos;  // Mouse x ve y degerini tutucak nokta degiskeni
DWORD Screen_width;
DWORD Screen_hight;
int Button_width;
int Button_hight;
int Colorbtn_size;
int leftingX;
long mX,mY; // mouse x ve y kisa erisim

void CreateColorPalette();

enum Items {
Kalem,Kalem2,Cizgi,Dikdortgen,Ucgen,Daire
};
Items Selected_items;

void Create_Windows(){

Screen_width = GetSystemMetrics(SM_CXSCREEN); // Ekran Max X degeri
Screen_hight = GetSystemMetrics(SM_CYSCREEN); // Ekran Max Y degeri



Button_width = Screen_width/25;
Button_hight = Screen_hight/25;
Colorbtn_size = Screen_hight/40;



initwindow(Screen_width,Screen_hight,"Paint Project-ProLab",-2,-2); //Pencere olusturuyoruz.Max X ve Y degerlerinde

setactivepage(0);
setbkcolor(WHITE);
cleardevice();

bar(0,(Screen_hight/10)+1,Screen_width,Screen_hight);

setcolor(BLUE);
rectangle(0,0,Screen_width-1,Screen_hight/10);

setfillstyle(SOLID_FILL,LIGHTBLUE);
setbkcolor(LIGHTBLUE);
setcolor(WHITE);

//bar(2,2,2+Button_width,2+Button_hight);
readimagefile("images\\pencil.bmp",2,2,2+Button_width,2+Button_hight);
//outtextxy(4,4,"Pen");

//bar(Button_width+6,2,(2*Button_width)+2,2+Button_hight);
readimagefile("images\\Line.bmp",Button_width+6,2,(2*Button_width)+2,2+Button_hight);
//outtextxy(Button_width+8,4,"Line");


//bar(2,Button_hight+4,2+Button_width,(2*Button_hight)+4);
readimagefile("images\\square.bmp",2,Button_hight+4,2+Button_width,(2*Button_hight)+4);
//outtextxy(4,4+Button_hight,"Rect");
//outtextxy(4,18+Button_hight,"Angle");

//bar(Button_width+6,Button_hight+4,(Button_width*2)+2,(Button_hight*2)+4);
readimagefile("images\\triangle.bmp",Button_width+6,Button_hight+4,(Button_width*2)+2,(Button_hight*2)+4);
//outtextxy(Button_width+8,Button_hight+4,"Tri");
//outtextxy(Button_width+8,Button_hight+18,"Angle");

//bar((Button_width*2)+6,Button_hight+4,(Button_width*3)+2,(Button_hight*2)+4);
readimagefile("images\\circle.bmp",(Button_width*2)+6,Button_hight+4,(Button_width*3)+2,(Button_hight*2)+4);
//outtextxy((Button_width*2)+8,Button_hight+10,"Circle");

//bar((Button_width*4),2,Button_width*5,2+Button_hight);
readimagefile("images\\open_file.bmp",(Button_width*4),2,Button_width*5,2+Button_hight);
//outtextxy((Button_width*4)+2,4,"Open");

//bar((Button_width*5)+4,2,(Button_width*6)+4,2+Button_hight);
readimagefile("images\\save_file.bmp",(Button_width*5)+4,2,(Button_width*6)+4,2+Button_hight);
//outtextxy((Button_width*5)+6,4,"Save");

CreateColorPalette();

}

void CreateColorPalette(){

leftingX = (Screen_width/2)+250;
setfillstyle(SOLID_FILL,COLOR(250,250,250));
bar(leftingX,20,leftingX+(Colorbtn_size*8)+28,26+Colorbtn_size*2);

setfillstyle(SOLID_FILL,BLACK);
bar(leftingX,20,leftingX+Colorbtn_size,20+Colorbtn_size);

setfillstyle(SOLID_FILL,BLUE);
bar(leftingX+Colorbtn_size+4,20,leftingX+(Colorbtn_size*2)+4,20+Colorbtn_size);

setfillstyle(SOLID_FILL,GREEN);
bar(leftingX+(Colorbtn_size*2)+8,20,leftingX+(Colorbtn_size*3)+8,20+Colorbtn_size);

setfillstyle(SOLID_FILL,CYAN);
bar(leftingX+(Colorbtn_size*3)+12,20,leftingX+(Colorbtn_size*4)+12,20+Colorbtn_size);

setfillstyle(SOLID_FILL,RED);
bar(leftingX+(Colorbtn_size*4)+16,20,leftingX+(Colorbtn_size*5)+16,20+Colorbtn_size);

setfillstyle(SOLID_FILL,MAGENTA);
bar(leftingX+(Colorbtn_size*5)+20,20,leftingX+(Colorbtn_size*6)+20,20+Colorbtn_size);

setfillstyle(SOLID_FILL,BROWN);
bar(leftingX+(Colorbtn_size*6)+24,20,leftingX+(Colorbtn_size*7)+24,20+Colorbtn_size);

setfillstyle(SOLID_FILL,DARKGRAY);
bar(leftingX+(Colorbtn_size*7)+28,20,leftingX+(Colorbtn_size*8)+28,20+Colorbtn_size);

setfillstyle(SOLID_FILL,WHITE);
bar(leftingX,24+Colorbtn_size,leftingX+Colorbtn_size,24+(Colorbtn_size*2));

setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(leftingX+Colorbtn_size+4,24+Colorbtn_size,leftingX+(Colorbtn_size*2)+4,24+(Colorbtn_size*2));

setfillstyle(SOLID_FILL,LIGHTBLUE);
bar(leftingX+(Colorbtn_size*2)+8,24+Colorbtn_size,leftingX+(Colorbtn_size*3)+8,24+(Colorbtn_size*2));

setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(leftingX+(Colorbtn_size*3)+12,24+Colorbtn_size,leftingX+(Colorbtn_size*4)+12,24+(Colorbtn_size*2));

setfillstyle(SOLID_FILL,LIGHTCYAN);
bar(leftingX+(Colorbtn_size*4)+16,24+Colorbtn_size,leftingX+(Colorbtn_size*5)+16,24+(Colorbtn_size*2));

setfillstyle(SOLID_FILL,LIGHTRED);
bar(leftingX+(Colorbtn_size*5)+20,24+Colorbtn_size,leftingX+(Colorbtn_size*6)+20,24+(Colorbtn_size*2));

setfillstyle(SOLID_FILL,LIGHTMAGENTA);
bar(leftingX+(Colorbtn_size*6)+24,24+Colorbtn_size,leftingX+(Colorbtn_size*7)+24,24+(Colorbtn_size*2));

setfillstyle(SOLID_FILL,YELLOW);
bar(leftingX+(Colorbtn_size*7)+28,24+Colorbtn_size,leftingX+(Colorbtn_size*8)+28,24+(Colorbtn_size*2));

}

void openImage(){
readimagefile(NULL,0,(Screen_hight/10)+2,Screen_width,Screen_hight);
}
void saveImage(){
writeimagefile(NULL,0,(Screen_hight/10)+2,Screen_width,Screen_hight);
}

void ButtonClickControl(){

int clickedX,clickedY;
getmouseclick(WM_LBUTTONDOWN,clickedX,clickedY);
clearmouseclick(WM_LBUTTONDOWN);

if(clickedX>=2 && clickedX<=Button_width+2 && clickedY>=2 && clickedY<=Button_hight+2 ){
    Selected_items = Kalem2;
    //cout << "Buton Pen tiklandi" << endl;

}

if(clickedX>=Button_width+6 && clickedX<=2*Button_width+2 && clickedY>=2 && clickedY<=Button_hight+2 ){
    Selected_items = Cizgi;
    //cout << "Buton Line tiklandi" << endl;
}

if(clickedX>=2 && clickedX<=Button_width+2 && clickedY>=Button_hight+4 && clickedY<=2*Button_hight+4 ){
    Selected_items = Dikdortgen;
    //cout << "Buton Rectangle tiklandi" << endl;
}

if(clickedX>=Button_width+6 && clickedX<=(Button_width*2)+2 && clickedY>=Button_hight+4 && clickedY<=(Button_hight*2)+4 ){
    Selected_items = Ucgen;
    //cout << "Buton Triangle tiklandi" << endl;
}

if(clickedX>=(Button_width*2)+6 && clickedX<=(Button_width*3)+2 && clickedY>=Button_hight+4 && clickedY<=(Button_hight*2)+4 ){
    Selected_items = Daire;
    //cout << "Buton Circle tiklandi" << endl;
}

if(clickedX>=(Button_width*4) && clickedX<=Button_width*5 && clickedY>=2 && clickedY<=2+Button_hight ){
   openImage();
    //cout << "Buton Open tiklandi" << endl;
}

if(clickedX>=(Button_width*5)+4 && clickedX<=(Button_width*6)+4 && clickedY>=2 && clickedY<=2+Button_hight ){
   saveImage();
    //cout << "Buton Save tiklandi" << endl;
}

if(clickedX>=(leftingX) && clickedX<=leftingX+(Colorbtn_size) && clickedY>=20 && clickedY<=20+Colorbtn_size){
    setfillstyle(SOLID_FILL,BLACK);
    //cout << "Renk Black tiklandi" << endl;
}

if(clickedX>=(leftingX)+Colorbtn_size+4 && clickedX<=leftingX+(Colorbtn_size*2)+4 && clickedY>=20 && clickedY<=20+Colorbtn_size){
    setfillstyle(SOLID_FILL,BLUE);
    setcolor(BLUE);
    //cout << "Renk Blue tiklandi" << endl;
}


if(clickedX>=(leftingX)+(Colorbtn_size*2)+8 && clickedX<=leftingX+(Colorbtn_size*3)+8 && clickedY>=20 && clickedY<=20+Colorbtn_size){
   setfillstyle(SOLID_FILL,GREEN);
   setcolor(GREEN);
    //cout << "Renk Green tiklandi" << endl;
}


if(clickedX>=(leftingX)+(Colorbtn_size*3)+12 && clickedX<=leftingX+(Colorbtn_size*4)+12 && clickedY>=20 && clickedY<=20+Colorbtn_size){
   setfillstyle(SOLID_FILL,CYAN);
   setcolor(CYAN);
    //cout << "Renk Cyan tiklandi" << endl;
}

if(clickedX>=(leftingX)+(Colorbtn_size*4)+16 && clickedX<=leftingX+(Colorbtn_size*5)+16 && clickedY>=20 && clickedY<=20+Colorbtn_size){
   setfillstyle(SOLID_FILL,RED);
   setcolor(RED);
    //cout << "Renk Red tiklandi" << endl;
}

if(clickedX>=(leftingX)+(Colorbtn_size*5)+20 && clickedX<=leftingX+(Colorbtn_size*6)+20 && clickedY>=20 && clickedY<=20+Colorbtn_size){
   setfillstyle(SOLID_FILL,MAGENTA);
   setcolor(MAGENTA);
   //cout << "Renk Magenta tiklandi" << endl;
}

if(clickedX>=(leftingX)+(Colorbtn_size*6)+24 && clickedX<=leftingX+(Colorbtn_size*7)+24 && clickedY>=20 && clickedY<=20+Colorbtn_size){
   setfillstyle(SOLID_FILL,BROWN);
   setcolor(BROWN);
    //cout << "Renk Brown tiklandi" << endl;
}

if(clickedX>=(leftingX)+(Colorbtn_size*7)+28 && clickedX<=leftingX+(Colorbtn_size*8)+28 && clickedY>=20 && clickedY<=20+Colorbtn_size){
   setfillstyle(SOLID_FILL,DARKGRAY);
   setcolor(DARKGRAY);
    //cout << "Renk Darkgray tiklandi" << endl;
}


if(clickedX>=(leftingX)+(Colorbtn_size)+4 && clickedX<=leftingX+(Colorbtn_size*2)+4 && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   setcolor(LIGHTGRAY);
    //cout << "Renk Lightgray tiklandi" << endl;
}

if(clickedX>=(leftingX) && clickedX<=leftingX+Colorbtn_size && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,WHITE);
   setcolor(WHITE);
    //cout << "Renk White tiklandi" << endl;
}


if(clickedX>=(leftingX)+(Colorbtn_size*2)+8 && clickedX<=leftingX+(Colorbtn_size*3)+8 && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,LIGHTBLUE);
   setcolor(LIGHTBLUE);
    //cout << "Renk Lightblue tiklandi" << endl;
}

if(clickedX>=(leftingX)+(Colorbtn_size*3)+12 && clickedX<=leftingX+(Colorbtn_size*4)+12 && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,LIGHTGREEN);
   setcolor(LIGHTGREEN);
    //cout << "Renk Lightgreen tiklandi" << endl;
}


if(clickedX>=(leftingX)+(Colorbtn_size*4)+16 && clickedX<=leftingX+(Colorbtn_size*5)+16 && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,LIGHTCYAN);
   setcolor(LIGHTCYAN);
    //cout << "Renk Lightcyan tiklandi" << endl;
}


if(clickedX>=(leftingX)+(Colorbtn_size*5)+20 && clickedX<=leftingX+(Colorbtn_size*6)+20 && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,LIGHTRED);
   setcolor(LIGHTRED);
    //cout << "Renk Lightred tiklandi" << endl;
}

if(clickedX>=(leftingX)+(Colorbtn_size*6)+24 && clickedX<=leftingX+(Colorbtn_size*7)+24 && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,LIGHTMAGENTA);
   setcolor(LIGHTMAGENTA);
    //cout << "Renk Lightmagenta tiklandi" << endl;
}

if(clickedX>=(leftingX)+(Colorbtn_size*7)+28 && clickedX<=leftingX+(Colorbtn_size*8)+28 && clickedY>=24+Colorbtn_size && clickedY<=24+(Colorbtn_size*2)){
   setfillstyle(SOLID_FILL,YELLOW);
   setcolor(YELLOW);
    //cout << "Renk Yellow tiklandi" << endl;
}

}

int main()
{

Create_Windows();

setfillstyle(SOLID_FILL,BLACK);
setcolor(BLACK);

Selected_items = Kalem2 ;

    int lBtnDwnX,lBtnDwnY;

    while(1){
        GetCursorPos(&cursorPos);
        mX = cursorPos.x;
        mY = cursorPos.y-32;

     if(mY<0){
        mY=0;
     }

       if(mY<=Screen_hight/10){
         ButtonClickControl();
         clearmouseclick(WM_LBUTTONDOWN);
         clearmouseclick(WM_LBUTTONUP);
       }



     if(mY>Screen_hight/10){

   //--------------------------------------------------------------//  -- iptal edilen fonksiyon
   /*
       if(ismouseclick(WM_LBUTTONDOWN) && Selected_items == Kalem){
        while(!ismouseclick(WM_LBUTTONUP)){
       bar(mousex(),mousey(),mousex()+Brush_Size,mousey()+Brush_Size);
        }
       }

       if(ismouseclick(WM_LBUTTONUP) && Selected_items == Kalem){
        clearmouseclick(WM_LBUTTONDOWN);
        clearmouseclick(WM_LBUTTONUP);
       }
       */
   //--------------------------------------------------------------//
       if(Selected_items == Kalem2){

         if(ismouseclick(WM_LBUTTONDOWN)){

              moveto(mousex(),mousey());

        while(!ismouseclick(WM_LBUTTONUP)){
             if(mousey()>Screen_hight/10)
            lineto(mousex(),mousey());
        }

         if(ismouseclick(WM_LBUTTONUP)){
             clearmouseclick(WM_LBUTTONDOWN);
            clearmouseclick(WM_LBUTTONUP);

         }

          }

       }

   //--------------------------------------------------------------//
       if(Selected_items == Dikdortgen){

            if(ismouseclick(WM_RBUTTONDOWN)){
                 lBtnDwnX = mX;
                 lBtnDwnY = mY;
                // cout << "Mouse left button down\n";
                // cout << "X : " << lBtnDwnX << " Y : " << lBtnDwnY << endl;
                clearmouseclick(WM_RBUTTONDOWN);
            }

            if(ismouseclick(WM_RBUTTONUP)){
                    int tmp;


                    if(lBtnDwnX>mX){
                        tmp = mX;
                        mX = lBtnDwnX;
                        lBtnDwnX = tmp;
                    }
                    if(lBtnDwnY>mY){
                        tmp = mY;
                        mY = lBtnDwnY;
                        lBtnDwnY = tmp;
                    }

                if(mY<=Screen_hight/10){
                  mY=Screen_hight/10;
                }

                if(lBtnDwnY<=Screen_hight/10){
                  lBtnDwnY=Screen_hight/10;
                }

                rectangle(lBtnDwnX,lBtnDwnY,mX,mY);
                //cout << "RectAngle Koordinatlari:" << lBtnDwnX << "," << lBtnDwnY << "," << mX << "," << mY << endl;
                //cout << "Mouse left button up\n";
                //cout << "X : " << mX << " Y : " << mY << endl;
                clearmouseclick(WM_RBUTTONUP);

             }
       }
    //--------------------------------------------------------------//

     if(Selected_items == Daire){

         if(ismouseclick(WM_RBUTTONDOWN)){
            lBtnDwnX = mX;
            lBtnDwnY = mY;
            //cout << "Down X,Y : " << lBtnDwnX << "," << lBtnDwnY << endl;
             clearmouseclick(WM_RBUTTONDOWN);
         }

         if(ismouseclick(WM_RBUTTONUP)){
               // cout << "Up X,Y : " << mX << "," << mY << endl;
            double lenght = sqrt(pow(mX-lBtnDwnX,2)+pow(mY-lBtnDwnY,2));

            if(((mY+lBtnDwnY)/2-lenght/2)<=Screen_hight/10){
                 circle((mX+lBtnDwnX)/2,Screen_hight/10+lenght/2,lenght/2);
            }else{
                 circle((mX+lBtnDwnX)/2,(mY+lBtnDwnY)/2,lenght/2);
            }


           clearmouseclick(WM_RBUTTONUP);

         }

     }
     //--------------------------------------------------------------//
    if(Selected_items == Cizgi){

        if(ismouseclick(WM_RBUTTONDOWN)){
            lBtnDwnX = mX;
            lBtnDwnY = mY;
             clearmouseclick(WM_RBUTTONDOWN);
        }

        if(ismouseclick(WM_RBUTTONUP)){
            line(lBtnDwnX,lBtnDwnY,mX,mY);
            clearmouseclick(WM_RBUTTONUP);
        }



    }
  //--------------------------------------------------------------//

  if(Selected_items == Ucgen){

        if(ismouseclick(WM_RBUTTONDOWN)){
            lBtnDwnX = mX;
            lBtnDwnY = mY;
            //cout << "Down X,Y : " << lBtnDwnX << "," << lBtnDwnY << endl;
             clearmouseclick(WM_RBUTTONDOWN);
         }

          if(ismouseclick(WM_RBUTTONUP)){
               // cout << "Up X,Y : " << mX << "," << mY << endl;
         double lenght = sqrt(pow(mX-lBtnDwnX,2)+pow(mY-lBtnDwnY,2));
         double middlePx = (mX+lBtnDwnX)/2;
         double middlePy = (mY+lBtnDwnY)/2;

            line(middlePx-lenght/2,middlePy+lenght/2,middlePx,middlePy-lenght/2);
            line(middlePx,middlePy-lenght/2,middlePx+lenght/2,middlePy+lenght/2);
            line(middlePx-lenght/2,middlePy+lenght/2,middlePx+lenght/2,middlePy+lenght/2);

           clearmouseclick(WM_RBUTTONUP);
         }


  }



     } // Screen Hight control end


    } // while end


getch();
closegraph();

}


