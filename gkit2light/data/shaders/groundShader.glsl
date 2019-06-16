#version 330

#ifdef VERTEX_SHADER
uniform mat4 mvpMatrix;

layout(location= 0) in vec3 position;

out vec3 vertex_uv;

void main()
{
    const vec3 uv[3]= vec3[3](vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
    gl_Position= mvpMatrix * vec4(position, 1);
    vertex_uv = uv[gl_VertexID%3];
}
    #endif


    #ifdef FRAGMENT_SHADER

in vec3 vertex_uv;
out vec4 fragment_color;

void main()
{
    float a = 1 - vertex_uv.x;
    float b = 1 - vertex_uv.y;
    float c = 1 - vertex_uv.z;
    float test = max(a, max(b, c));

    if (test>0.98){
        fragment_color= vec4(1, 1, 1, 1);
    } else {
        fragment_color= vec4(0.5, 0.5, 0.5, 1);
    }
}
    #endif

// Inversion des couleurs
/*float a = 1 - vertex_uv.x;
    float b = 1 - vertex_uv.y;
    float c = 1 - vertex_uv.z;
    fragment_color= vec4(a,b,c,1);*/

