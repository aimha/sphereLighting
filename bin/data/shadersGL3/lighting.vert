// vertex shader

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

uniform float time;

out vec3 v_normal;

void main(){
    vec4 modifiedPosition = modelViewProjectionMatrix * position;

    float scale = 200.;
    float displacementY = sin(position.x / 200.) * scale;
    modifiedPosition.y += displacementY;

    mat4 normalMatrix = transpose(inverse(modelViewMatrix));
    v_normal = normalize(mat3(normalMatrix) * vec3(normal));

    gl_Position = modifiedPosition;
}