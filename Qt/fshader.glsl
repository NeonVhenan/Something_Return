#version 140


uniform sampler2D murs;
uniform sampler2D sol;
uniform sampler2D porte;
uniform int TextN;
//uniform sampler2D texture3;

in vec2 v_texcoord;
in vec3 v_position;
//! [0]
void main()
{
    // Set fragment color from texture
 if(TextN == 1)
        gl_FragColor = texture2D(murs, v_texcoord);
 else{
     if(TextN == 2)
         gl_FragColor = texture2D(porte, v_texcoord);
     else{
         if(TextN == 4)
            gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
         else
            gl_FragColor = texture2D(sol, v_texcoord);
     }
 }
}

