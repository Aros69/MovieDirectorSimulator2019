#version 330

#ifdef VERTEX_SHADER
uniform mat4 mvpMatrix;

layout(location= 0) in vec3 position;

out vec3 vertex_uv;
out vec3 vertex_position;

void main()
{
    const vec3 uv[3]= vec3[3](vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
    gl_Position= mvpMatrix * vec4(position, 1);
    vertex_uv = uv[gl_VertexID%3];
    vertex_position = position;
}
    #endif

bool isOnLine(in vec3 origine, in vec3 secondPoint, in vec3 pointTested){
    float d1 = distance(origine, pointTested);
    float d2 = distance(pointTested, secondPoint);
    float d3 = distance(origine, secondPoint);
    return d1+d2>d3-d3/750 && d1+d2<d3+d3/750;
}

bool isOnLinesWeDontWant(in vec3 point, in float distMax){
    return isOnLine(vec3(-1, 1, 0), vec3(1, -1, 0), point)
    || isOnLine(vec3(distMax/2, distMax/2, distMax), vec3(-distMax/2, -distMax/2, distMax), point)
    || isOnLine(vec3(1, -1, 0), vec3(-distMax/2, -distMax/2, distMax), point)
    || isOnLine(vec3(-1, -1, 0), vec3(-distMax/2, distMax/2, distMax), point)
    || isOnLine(vec3(-1, 1, 0), vec3(distMax/2, distMax/2, distMax), point)
    || isOnLine(vec3(-1, 1, 0), vec3(-distMax/2, -distMax/2, distMax), point);
}

    #ifdef FRAGMENT_SHADER
uniform int distanceMax;
uniform bool helpNeeded;

in vec3 vertex_uv;
in vec3 vertex_position;

out vec4 fragment_color;

void main()
{
    // link between all vertex in the mesh
    float a = 1 - vertex_uv.x;
    float b = 1 - vertex_uv.y;
    float c = 1 - vertex_uv.z;
    float test = max(a, max(b, c));

    if (test>0.98){
        if (isOnLinesWeDontWant(vertex_position, distanceMax)){
            discard;
        }
        fragment_color= vec4(0, 0, 0, 1);
    } else {
        // clean the fragment (become transparent)
        if (helpNeeded && vertex_position.z == distanceMax){
            fragment_color= vec4(0.8, 0.8, 0.8, 0.1);
        } else {
            discard;
        }
    }
}
    #endif

// Inversion des couleurs
/*float a = 1 - vertex_uv.x;
    float b = 1 - vertex_uv.y;
    float c = 1 - vertex_uv.z;
    fragment_color= vec4(a,b,c,1);*/

// Distance par rapport aux sommets
/*float a = 1 - vertex_uv.x;
    float b = 1 - vertex_uv.y;
    float c = 1 - vertex_uv.z;
    float test = max(a, max(b,c));
    fragment_color= vec4(1-(test*test),0,0,1);*/

// Delimitation des triangles
/*float a = 1 - vertex_uv.x;
    float b = 1 - vertex_uv.y;
    float c = 1 - vertex_uv.z;
    float test = max(a, max(b,c));
    if(test>0.9){
        fragment_color= vec4(0,0,0,1);
    } else {
        fragment_color= vec4(1,0,0,1);
    }
    */
