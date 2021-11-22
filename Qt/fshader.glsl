#version 140


uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;

in vec2 v_texcoord;
in vec3 v_position;
//! [0]
void main()
{
    // Set fragment color from texture
    gl_FragColor = vec4(v_texcoord.x, v_texcoord.y, 1.0, 1.0);

}
//! [0]

