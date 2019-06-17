#version 330

#ifdef VERTEX_SHADER
uniform mat4 mvpMatrix;

layout(location= 0) in vec3 position;


void main()
{
    gl_Position= mvpMatrix * vec4(position, 1);
}
    #endif


    #ifdef FRAGMENT_SHADER

uniform vec4 color;

out vec4 fragment_color;

void main()
{
        fragment_color= color;
}
    #endif

// Inversion des couleurs
/*float a = 1 - vertex_uv.x;
    float b = 1 - vertex_uv.y;
    float c = 1 - vertex_uv.z;
    fragment_color= vec4(a,b,c,1);*/

