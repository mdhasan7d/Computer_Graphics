//@Author: MD Hasan
//ID : CSE2101022086

#include <graphics.h>
#include <iostream>
#include <conio.h>

using namespace std;

void displayMenu() {
    cout << " \n Menu Card \n\n";
    cout << "1. Draw My Name\n";
    cout << "2. Draw An Emoji\n";
    cout << "3. Draw A HUT\n";
    cout << "4. Draw A KITE\n";
    cout << "5. Draw A Robot\n\n";
}

//1.MY Name
void drawMyName() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Name");
    initwindow(1000, 600);

    // H
    line(100, 200, 100, 400);
    line(200, 200, 200, 400);
    line(100, 300, 200, 300);

    // A
    line(250, 400, 300, 200);
    line(300, 200, 350, 400);
    line(275, 300, 325, 300);

    // S
    line(400, 200, 500, 200);
    line(400, 200, 400, 300);
    line(400, 300, 500, 300);
    line(500, 300, 500, 400);
    line(400, 400, 500, 400);

    // A
    line(550, 400, 600, 200);
    line(600, 200, 650, 400);
    line(575, 300, 625, 300);

    // N
    line(700, 400, 700, 200);
    line(700, 200, 800, 400);
    line(800, 400, 800, 200);
}
//2.Draw Emoji
void drawEmoji() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int X = 300, Y = 300;
    int R = 100;

    int faceColor = YELLOW;
    int eyeColor = WHITE;
    int pupilColor = BLACK;
    int noseColor = WHITE;
    int mouthColor = WHITE;

    setcolor(faceColor);
    setfillstyle(SOLID_FILL, faceColor);
    circle(X, Y, R);
    floodfill(X, Y, faceColor);

    int eyeRadius = 25;
    int leftEyeX = X - 40;
    int leftEyeY = Y - 30;
    setcolor(eyeColor);
    setfillstyle(SOLID_FILL, eyeColor);
    circle(leftEyeX, leftEyeY, eyeRadius);
    floodfill(leftEyeX, leftEyeY, eyeColor);

    int rightEyeX = X + 40;
    int rightEyeY = Y - 30;
    circle(rightEyeX, rightEyeY, eyeRadius);
    floodfill(rightEyeX, rightEyeY, eyeColor);

    int pupilRadius = 15;
    setcolor(pupilColor);
    setfillstyle(SOLID_FILL, pupilColor);
    circle(leftEyeX, leftEyeY, pupilRadius);
    floodfill(leftEyeX, leftEyeY, pupilColor);
    circle(rightEyeX, rightEyeY, pupilRadius);
    floodfill(rightEyeX, rightEyeY, pupilColor);

    setcolor(noseColor);
    setfillstyle(SOLID_FILL, noseColor);
    int noseX1 = X;
    int noseY1 = Y - 10;
    int noseX2 = X - 10;
    int noseY2 = Y + 10;
    int noseX3 = X + 10;
    int noseY3 = Y + 10;
    line(noseX1, noseY1, noseX2, noseY2);
    line(noseX2, noseY2, noseX3, noseY3);
    line(noseX3, noseY3, noseX1, noseY1);
    floodfill(X, Y, noseColor);

    int mouthX = X;
    int mouthY = Y + 50;
    int mouthXRadius = 40;
    int mouthYRadius = 20;
    setcolor(mouthColor);
    setfillstyle(LTSLASH_FILL, mouthColor);
    ellipse(mouthX, mouthY, 0, 360, mouthXRadius, mouthYRadius);
    floodfill(mouthX, mouthY, mouthColor);
}


//3.Draw Hut
void drawHut() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(320, 200, WHITE);

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    line(200, 150, 320, 80);
    line(320, 80, 440, 150);
    line(200, 150, 440, 150);
    floodfill(320, 120, BLUE);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    rectangle(200, 150, 440, 300);
    floodfill(320, 220, BLACK);

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(280, 250, 340, 300);
    floodfill(310, 275, BLUE);

    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(230, 180, 270, 220);
    floodfill(250, 200, LIGHTGRAY);
}


//4.Draw Kite
void drawKite(int x, int y) {

    setcolor(RED);
    setfillstyle(SOLID_FILL, CYAN);
    int points[] = {x, y, x + 100, y + 100, x, y + 200, x - 100, y + 100};
    fillpoly(4, points);


    setcolor(BLACK);
    line(x, y, x, y + 200);

    setcolor(YELLOW);
    line(x, y + 200, x, y + 300);


    for (int i = 1; i <= 5; i++) {
        int tailY = y + 200 + i * 20;
        line(x, tailY, x + 20, tailY + 10);
        line(x, tailY, x - 20, tailY + 10);
    }
}


void animateKite() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Kite Animation");


    int startX = 50;
    int startY = getmaxy() - 50;
    int endX = getmaxx() - 50;
    int endY = 100;


    for (int x = startX, y = startY; x <= endX && y >= endY; x += 5, y -= 5) {
        cleardevice();
        drawKite(x, y);
        delay(20);
    }

    getch();
    closegraph();
}


//5.Draw Robot
void drawHeader() {

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    int x = 10;
    int y = 10;


    outtextxy(x, y, "Name: R-2086");
    outtextxy(x + 250, y, "Version: 1.0");
    outtextxy(x + 500, y, "Creator: MD Hasan");
}

void drawRobot(int x, int y) {

    setcolor(WHITE);
    rectangle(0, y + 180, getmaxx(), y + 220);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(1, y + 181, WHITE);


    setcolor(WHITE);
    rectangle(x, y, x + 100, y + 150);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(x + 1, y + 1, WHITE);

    rectangle(x + 20, y - 50, x + 80, y);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(x + 21, y - 49, WHITE);


    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 35, y - 30, 5);
    floodfill(x + 35, y - 30, BLACK);
    circle(x + 65, y - 30, 5);
    floodfill(x + 65, y - 30, BLACK);


    setcolor(WHITE);
    circle(x + 20, y + 160, 20);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(x + 20, y + 160, WHITE);

    circle(x + 80, y + 160, 20);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(x + 80, y + 160, WHITE);


    line(x + 50, y - 50, x + 50, y - 70);
    circle(x + 50, y - 75, 5);
    floodfill(x + 50, y - 75, WHITE);


    setcolor(WHITE);
    rectangle(x - 40, y, x - 20, y + 50);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(x - 39, y + 1, WHITE);

    rectangle(x + 120, y, x + 140, y + 50);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(x + 121, y + 1, WHITE);


    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(x + 20, y + 60, "2086");
}

void drawMoveableRobot() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Moving Robot");
    initwindow(1200, 600);

    int x = 50, y = 200;
    int endX = getmaxx() - 150;

    while (x <= endX) {
        cleardevice();
        drawHeader();
        drawRobot(x, y);
        delay(10);
        x += 10;
    }

    delay(1000);


    while (x >= 150) {
        cleardevice();
        drawHeader();
        drawRobot(x, y);
        delay(10);
        x -= 10;
    }

    getch();
    closegraph();
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Hasan");

    int choice;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        cleardevice();

        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                drawMyName();
                break;
            case 2:
                drawEmoji();
                break;
            case 3:
                drawHut();
                break;
            case 4:
                animateKite();
                break;
            case 5:
                drawMoveableRobot();
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }

        cout << "Do you want to enter another choice? (y/n): " ;
        cin >> cont ;
    }

    getch();
    closegraph();
    return 0;
}
