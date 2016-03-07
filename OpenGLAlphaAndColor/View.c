//
//  View.c
//  OpenGLPerspective
//
//  Created by Laura del Pino Díaz on 7/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "View.h"



void Init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glOrtho(-gl_width/2.0, gl_width/2.0, -gl_height/2.0, gl_height/2.0, gl_near, gl_far);
    //glFrustum(-gl_width/2.0, gl_width/2.0, -gl_height/2.0, gl_height/2.0, gl_near, gl_far);
}


void Display(){

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,0.0,-3.0);
    glVertex3f(0.5, 0.5, -3.0);
    glVertex3f(0.5, -0.5, -3.0);
    glEnd();
    
    glColor4f(0.0, 0.0, 1.0,0.4f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5, 0.0, -2.0);
    glColor4f(0.0, 0.0, 1.0,0.9f);
    glVertex3f(-0.5, 0.5, -2.0);
    glVertex3f(-0.5, -0.5, -2.0);
    glEnd();
    glFlush();
}

void ReshapeSize(int width, int height){
    
    float dx = gl_width;
    float dy = gl_height;
    
    dx *= (float)width / (float)w_width;
    dy *= (float)height / (float)w_height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_near, gl_far); // espacio de trabajo
    glutPostRedisplay();
}