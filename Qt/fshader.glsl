#version 140


uniform sampler2D texture;
//uniform sampler2D texture2;
//uniform sampler2D texture3;

in vec2 v_texcoord;
in vec3 v_position;
//! [0]
void main()
{
    // Set fragment color from texture
    if(v_texcoord.x == 5.0 && v_texcoord.y == 0.0){
        gl_FragColor = vec4(1.0, 0.0,0.0,1.0);
    }
    else
        gl_FragColor = texture2D(texture, v_texcoord);

}
//! [0]

