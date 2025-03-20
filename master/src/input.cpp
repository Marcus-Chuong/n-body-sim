#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\input.h"
#include <iostream>

using namespace std;

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