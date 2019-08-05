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

// custom
uniform sampler2DRect tex0;
in vec2 texCoordVarying;

float getDisplacement( float dx, float dy )
{
	return texture( tex0, texCoordVarying + vec2( dFdx( texCoordVarying.x ) * dx, dFdy( texCoordVarying.y ) * dy )).b;
}

void main()
{
  vec2 st = gl_FragCoord.xy / vec2(1000., 1000.);

  vec3 normal = vec3(.0);

  float o_z = getDisplacement(.0, .0);
  float p1_z = getDisplacement(.0, .0);
  // float p2_z = getDisplacement(.0, 1.);

  // vec3 v1 = vec3(1., .0, p1_z) - vec3(0., 0., o_z);
  // vec3 v2 = vec3(0., 1., p2_z) - vec3(0., 0., o_z);

  // normal = cross(normalize(v1), normalize(v2));

  // vec3 color = normal;

  float b = texture(tex0, texCoordVarying).b;

  outputColor = vec4(0., 0., b, 1.);
}

	// normal.x = -0.5 * (getDisplacement(1,0) - getDisplacement(-1,0));