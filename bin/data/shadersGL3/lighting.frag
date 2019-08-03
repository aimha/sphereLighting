// fragment shader

#version 150

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec3 normal;
in vec4 color;
in vec2 texcoord;

uniform mat4 normalMatrix;

in vec3 v_normal;

uniform float time;

out vec4 outputColor;

void main()
{
    vec2 st = gl_FragCoord.xy / vec2(1920., 1200.);
    vec3 color = vec3(.8, .0, .24);

    vec3 light_position = vec3(0.5, 0.25, 0.5);
    vec3 pixel_position = vec3(st, .0);

    vec3 lightDir = light_position - pixel_position;
    float dist = distance(light_position, pixel_position);
    lightDir /= dist;
    float attenuation = 1.0 - (dist / 1.5);
    attenuation = clamp(attenuation, .0, 1.);
    attenuation = pow(attenuation, 1.5);
    attenuation *= dot(lightDir, v_normal);

    float diff = dot(lightDir, v_normal);
    attenuation *= clamp(diff, 0.0, 1.0);

    color *= attenuation;
    color += vec3(0., 0., 0.1);

    outputColor = vec4(color, 1.);
}