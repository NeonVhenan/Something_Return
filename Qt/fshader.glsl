#version 140


uniform sampler2D murs;
uniform sampler2D sol;
uniform int TextN;
//uniform sampler2D texture3;

in vec2 v_texcoord;
in vec3 v_position;
//! [0]
void main()
{
    // Set fragment color from texture
 if(TextN ==1 )
        gl_FragColor = texture2D(murs, v_texcoord);
 else
     gl_FragColor = texture2D(sol, v_texcoord);
}
//! [0]

