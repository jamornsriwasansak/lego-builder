/*    
      glm.h
      Nate Robins, 1997
      ndr@pobox.com, http://www.pobox.com/~ndr/
 
      Wavefront OBJ model file format reader/writer/manipulator.

      Includes routines for generating smooth normals with
      preservation of edges, welding redundant vertices & texture
      coordinate generation (spheremap and planar projections) + more.

 */

#pragma once

#include "GL/glut.h"


#ifndef M_PI
#define M_PI 3.14159265
#endif

#define GLM_NONE     (0)		/* render with only vertices */
#define GLM_FLAT     (1 << 0)		/* render with facet normals */
#define GLM_SMOOTH   (1 << 1)		/* render with vertex normals */
#define GLM_TEXTURE  (1 << 2)		/* render with texture coords */
#define GLM_COLOR    (1 << 3)		/* render with colors */
#define GLM_MATERIAL (1 << 4)		/* render with materials */

static GLfloat glmMax(GLfloat a, GLfloat b);
static GLfloat glmAbs(GLfloat f);
static GLfloat glmDot(GLfloat* u, GLfloat* v);
static GLvoid glmCross(GLfloat* u, GLfloat* v, GLfloat* n);
static GLvoid glmNormalize(GLfloat* v);
static GLboolean glmEqual(GLfloat* u, GLfloat* v, GLfloat epsilon);

typedef struct _GLMnode GLMnode;
typedef struct _GLMmaterial GLMmaterial;
typedef struct _GLMtriangle GLMtriangle;
typedef struct _GLMgroup GLMgroup;
typedef struct _GLMmodel GLMmodel;

// funcoes adicionadas
GLvoid 
relScale(GLMmodel* model, GLfloat scalex, GLfloat scaley, GLfloat scalez);

GLvoid 
relTrans(GLMmodel* model, GLfloat transx, GLfloat transy, GLfloat transz);

GLvoid 
relRotat(GLMmodel* model, GLfloat angle, GLfloat rotatex, GLfloat rotatey, GLfloat rotatez);

//fim

/* glmUnitize: "unitize" a model by translating it to the origin and
 * scaling it to fit in a unit cube around the origin.  Returns the
 * scalefactor used.
 *
 * model - properly initialized GLMmodel structure 
 */

GLfloat glmUnitize(GLMmodel* model);

GLvoid glmDimensions(GLMmodel* model, GLfloat* dimensions);

GLvoid glmScale(GLMmodel* model, GLfloat scale);

GLvoid glmReverseWinding(GLMmodel* model);

GLvoid glmFacetNormals(GLMmodel* model);

GLvoid glmVertexNormals(GLMmodel* model, GLfloat angle);

GLvoid glmLinearTexture(GLMmodel* model);

GLvoid glmSpheremapTexture(GLMmodel* model);

GLvoid glmDelete(GLMmodel* model);

GLMmodel* glmReadOBJ(char* filename);

GLvoid glmWriteOBJ(GLMmodel* model, char* filename, GLuint mode);

GLvoid glmDraw(GLMmodel* model, GLuint mode);

GLuint glmList(GLMmodel* model, GLuint mode);

GLvoid glmWeld(GLMmodel* model, GLfloat epsilon);