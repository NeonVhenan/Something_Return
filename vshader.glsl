#version 140


uniform mat4 vp_matrix;
uniform mat4 transformation;

in vec4 a_position;
in vec2 a_texcoord;

out vec2 v_texcoord;
out vec3 v_position;

uniform sampler2D texture;

//! [0]
void main()
{
    // Calculate vertex position in screen space
        v_position = a_position.xyz;


    gl_Position = vp_matrix * transformation * vec4(v_position,1.);

   // Pass texture coordinate to fragment shader
    // Value will be automatically interpolated to fragments inside polygon faces
    v_texcoord = a_texcoord;

}
//! [0]
