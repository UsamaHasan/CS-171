#ifndef STRUCTS_H
#define STRUCTS_H

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

/* The following struct is used for representing a point light. */
struct Light
{
    /* Index 0 has the x-coordinate
     * Index 1 has the y-coordinate
     * Index 2 has the z-coordinate
     * Index 3 has the w-coordinate
     */
    float position[4];
    
    /* Index 0 has the r-component
     * Index 1 has the g-component
     * Index 2 has the b-component
     */
    float color[3];

    float k;
};

struct Point
{
    int x, y;
};

struct PointNDC
{
    float x, y, z;
};

struct Quaternion
{
    float qs, qx, qy, qz;
};

/* The following struct is used for representing points and normals in world
 * coordinates.
 */
struct Triple
{
    float x;
    float y;
    float z;
};

struct Face
{
    // coordinates for the vertices and surface normal
    // in their vectors
    int v1, v2, v3;
    int sn1, sn2, sn3;
};

struct Transform
{
    /* if label is "trans"
     * we have translation[3]
     * if label is "rot"
     * we have rotation[3] and rot_angle
     * if label is "scal"
     * we have scaling[3]
     */
    string label;
    float transformation[3];
    float rotation_angle; // only used for rot
};


struct Object
{
    /* See the note above and the comments in the 'draw_objects' and
     * 'create_cubes' functions for details about these buffer vectors.
     */
    string label;
    vector<Face> faces;
    /* Vectors holding just the vertices and normals,
     * no duplicates and in order as read from file */
    vector<Triple> vertices;
    vector<Triple> normals;
    /* Vectors with all the faces represented by vertices
     * and normals in order to be fed to OpenGL to render */
    vector<Triple> vertex_buffer;
    vector<Triple> normal_buffer;
    
    vector<Transform> transformations;
    vector<Transform> Ntransformations;
    
    /* Index 0 has the r-component
     * Index 1 has the g-component
     * Index 2 has the b-component
     */
    float ambient[3];
    float diffuse[3];
    float specular[3];
    
    float shininess;
};

/* The following are the camera specifications and parameters. 
 */

struct Camera
{
    /* Index 0 has the x-coordinate
     * Index 1 has the y-coordinate
     * Index 2 has the z-coordinate
     */
    float position[3];
    float orientation_axis[3];

    /* Angle in degrees. */ 
    float orientation_angle;

    float near, far, left, right, top, bottom;
};
 


#endif
