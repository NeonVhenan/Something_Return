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
    if(v_position.y > 0.7 && v_position.y <= 1.0)
        gl_FragColor = texture2D(texture2, v_texcoord);
    else{
        if(v_position.y > 1.0)
            gl_FragColor = texture2D(texture3, v_texcoord);
        else
            gl_FragColor = texture2D(texture1, v_texcoord);
    }
    //alt = texture2D(texture, v_texcoord);
    //prendre v_position.x pour avoir l'altitude

}
//! [0]

