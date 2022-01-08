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
     else
         gl_FragColor = texture2D(sol, v_texcoord);
 }

 //float originalZ = gl_FragCoord.z / gl_FragCoord.w;
 //originalZ=originalZ - floor(originalZ);
// gl_FragColor = vec4(originalZ, originalZ, originalZ,1.);
}
//! [0]

