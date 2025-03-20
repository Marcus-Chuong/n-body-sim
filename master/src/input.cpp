#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\input.h"
#include <iostream>
#include <SFML/Window/Event.hpp> // Include the SFML header for MouseEvent

#define LEFT 0
#define RIGHT 1

using namespace std;

extern float camX, camY, camZoom;
extern float mouseX, mouseY, tox, toy, tozoom, dzoom;
extern int mouseButton;

void updateCam() {
  camX = tox + (mouseX - tox) / tozoom;
  camY = toy + (mouseY - toy) / tozoom;
  camZoom = tozoom;
  cout << "Camera updated to position (" << camX << ", " << camY << ") with zoom " << camZoom << endl;
}

void setCamOffsets() {
  tox = camX - mouseX / camZoom;
  toy = camY - mouseY / camZoom;
  tozoom = camZoom;
  cout << "Camera offsets set to (" << tox << ", " << toy << ") with zoom " << tozoom << endl;
}

void setInsertStart() {
  // Logic to set the start of an insertion
  cout << "Insert start set at (" << mouseX << ", " << mouseY << ")" << endl;
}

void insertSquare() {
  // Logic to insert a square
  cout << "Square inserted at (" << mouseX << ", " << mouseY << ")" << endl;
}

void mouseDragged() {
  if (mouseButton == RIGHT) { 
    cout << "Right mouse button dragged" << endl;
    updateCam(); 
    return; 
  }
}

void mousePressed() {
  if (mouseButton == RIGHT) { 
    cout << "Right mouse button pressed" << endl;
    setCamOffsets(); 
    return; 
  }
  if (mouseButton == LEFT) { 
    cout << "Left mouse button pressed" << endl;
    setInsertStart(); 
    return; 
  }
}

void mouseReleased() {
  if (mouseButton == LEFT) { 
    cout << "Left mouse button released" << endl;
    insertSquare(); 
    return; 
  }
}

void mouseWheel(MouseEvent event) {
  float e = event.getCount();
  cout << "Mouse wheel event: " << e << endl;

  if (e < 0) {
    tox -= dzoom * (mouseX - tox);
    toy -= dzoom * (mouseY - toy);
    tozoom *= dzoom + 1;

  } else {
    tox += dzoom / (dzoom + 1) * (mouseX - tox); 
    toy += dzoom / (dzoom + 1) * (mouseY - toy);
    tozoom /= dzoom + 1;
  }
}

void inputLoop() {
  /*
  if (mousePressed) {
    if (mouseButton == LEFT && frameCount % everyInsert == 0) {
      insertSquare(screenToSpace(mouseX, mouseY), 20f);
    }
  }
  */
}