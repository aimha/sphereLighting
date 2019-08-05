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

out vec4 outputColor;

float random (in vec2 st) {
  return fract(sin(dot(st.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

float noise (in vec2 st) {
  vec2 i = floor(st);
  vec2 f = fract(st);

  float a = random(i);
  float b = random(i + vec2(1.0, 0.0));
  float c = random(i + vec2(0.0, 1.0));
  float d = random(i + vec2(1.0, 1.0));

  vec2 u = f * f * (3.0 - 2.0 * f);

  return mix(a, b, u.x) + (c - a)* u.y * (1.0 - u.x) + (d - b) * u.x * u.y;
}

void main()
{
    vec2 st = gl_FragCoord.xy / vec2(1920., 1200.);
    st.x *= 1920. / 1200.;

    float b = 0.;
    b += noise(st * 3.0);

    outputColor = vec4(0., 0., b, 1.);
}
