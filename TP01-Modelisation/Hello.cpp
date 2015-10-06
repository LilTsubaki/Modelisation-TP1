/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*
 * hello.c
 * This is a simple, introductory OpenGL program.
 */
#include "stdafx.h"
#include <cstdlib>
#include "glut.h"
#include <math.h> 
#include <iostream>
#define M_PI 3.14159265358979323846

void cercle(const float xCentre, const float yCentre, const float rayon, const int nbPointCercle)
{
	glBegin(GL_LINE_LOOP);
	glColor3f (1.0, 0.0, 1.0);
	for(int i = 0; i < nbPointCercle; i++)
	{
		glVertex3f (xCentre+cos(i*2*M_PI/nbPointCercle)*rayon, yCentre+sin(i*2*M_PI/nbPointCercle)*rayon, 0.0);
	}
	glEnd();
}

void cerclePlusEnPlusPetit(const float xCentre, const float yCentre, const float rayon, const int nbPointCercle, const int nbCercle, const float pourcentage)
{
	float facteur = 1.0;
	for(int i = 0; i < nbCercle; i++)
	{
		cercle(xCentre*facteur, yCentre, rayon * facteur, nbPointCercle);
		facteur *= pourcentage;
	}
}

void cercleAligne(float xCentre, const float yCentre, float rayon, const int nbPointCercle, const int nbCercle, const float pourcentage)
{
	float facteur = 1.0;
	for(int i = 0; i < nbCercle; i++)
	{
		xCentre += rayon+rayon*facteur;
		rayon = rayon*facteur;
		cercle(xCentre, yCentre, rayon, nbPointCercle);
		facteur *= pourcentage;
	}
}

void flocon(float xA, float yA, float xB, float yB, int nbActuel, int nbIteration)
{
	if(nbActuel < nbIteration)
	{
		float mX = xA+(xB-xA)/3;
		float mY = yA+(yB-yA)/3;

		float iX = xA+(xB-xA)/2;
		float iY = yA+(yB-yA)/2;

		float nX = xA+(xB-xA)*2/3;
		float nY = yA+(yB-yA)*2/3;

		float oX = iX + (nY-iY) * sin(-M_PI/3);
		float oY = iY - (nX-iX) * sin(-M_PI/3);
		
		nbActuel++;
		flocon(xA, yA, mX, mY, nbActuel, nbIteration);
		flocon(mX, mY, oX, oY, nbActuel, nbIteration);
		flocon(oX, oY, nX, nY, nbActuel, nbIteration);
		flocon(nX, nY, xB, yB, nbActuel, nbIteration);
	}
	else
	{
		glBegin(GL_LINE_STRIP);
		glColor3f (1.0, 0.0, 1.0);
		glVertex3f (xA, yA, 0.0);
		glVertex3f (xB, yB, 0.0);
		glEnd();
	}
}

void triangle3()
{
	glBegin(GL_LINE_LOOP);
	   glColor3f (1.0, 0.0, 1.0);
		  glVertex3f (0.05, 0.25, 0.0);
		  glVertex3f (0.05, 0.75, 0.0);
		  glVertex3f (0.50, 0.25, 0.0);
	   glEnd(); 

	glBegin(GL_LINE_LOOP);
	   glColor3f (1.0, 1.0, 0.0);
		  glVertex3f (0.51, 0.25, 0.0);
		  glVertex3f (0.51, 0.5, 0.0);
		  glVertex3f (0.76, 0.25, 0.0);
	   glEnd();

	   glBegin(GL_LINE_LOOP);
	   glColor3f (0.0, 1.0, 1.0);
		  glVertex3f (0.77, 0.25, 0.0);
		  glVertex3f (0.77, 0.36, 0.0);
		  glVertex3f (0.89, 0.25, 0.0);
	   glEnd();
}


void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at
 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) 
 */
  
   /*glBegin(GL_POLYGON);
   glColor3f (1.0, 0.0, 1.0);
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
   glEnd();*/
   
   //triangle3();
   //cercle(0.5, 0.5, 0.5, 32);
   //cerclePlusEnPlusPetit(0.5, 0.5, 0.5, 64, 8, 0.8);
   //cercleAligne(-0.20, 0.5, 0.20, 64, 5, 0.7);
   flocon(0.0, 0.5, 0.5, 1.0, 0, 1);
   flocon(0.5, 1.0, 1.0, 0.5, 0, 2);
   flocon(1.0, 0.5, 0.0, 0.5, 0, 3);



/* Swap the buffers to show the one
 * on which we writed
 */
   glutSwapBuffers();
}




void init (void)
{
/* select clearing color     */
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*
 * Declare initial window size, position, and display mode
 * (double buffer and RGB).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   init ();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
