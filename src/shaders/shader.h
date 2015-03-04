#ifndef GAME_SHADER_H
#define GAME_SHADER_H

#include <string>
#include <memory>
#include <glbinding/gl/gl.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

/**
 * Shader contains the relevant information and methods to bind and release an OpenGL shader, and to assign values to the uniform
 * attributes within an OpenGL shader.
 * @author Alec Sobeck
 * @author Matthew Robertson
 */
class Shader
{
protected:
    gl::GLhandleARB programID;

public:
	/**
	 * Creates a new Shader, storing the provided programID.
	 * @param programID an integer, generated by OpenGL, that uniquely identifies this shader
	 */
	Shader(gl::GLhandleARB programID);
	/**
	 * Binds this shader, causing OpenGL to start rendering with it.
	 */
	void bindShader();
	/**
	 * Releases this shader, causing OpenGL to stop rendering with it.
	 */
	void releaseShader();
	void glUniform1(std::string attributeName, gl::GLfloat v);
	void glUniform1(std::string attributeName, gl::GLint v);
	void glUniform1(std::string attributeName, bool v);
	void glUniform2(std::string attributeName, gl::GLfloat v0, gl::GLfloat v1);
	/**
	 * Assigns the values in a Vector2 to one of the variables in this Shader. The variable in the shader
	 * should probably also be a vec2 or this might cause strange results. <br>
	 * <b><u>Note:</u> Values are cast to floats, so there may be a loss of precision.</b>
	 * @param attributeName a std::string which has the name of one of the uniform variables in the shader with global
	 * scope. The values in the Vector2 v will be assigned to this variable.
	 * @param v a Vector2 which will have its values assigned to the corresponding uniform variable, with a name of
	 * attributeName, in the shader.
	 */
	void glUniform2(std::string attributeName, glm::vec2 v);
	void glUniform2(std::string attributeName, gl::GLint v0, gl::GLint v1);
	void glUniform3(std::string attributeName, gl::GLfloat v0, gl::GLfloat v1, gl::GLfloat v2);
	/**
	 * Assigns the values in a Vector3 to one of the variables in this Shader. The variable in the shader
	 * should probably also be a vec3 or this might cause strange results. <br>
	 * <b><u>Note:</u> Values are cast to floats, so there may be a loss of precision.</b>
	 * @param attributeName a std::string which has the name of one of the uniform variables in the shader with global
	 * scope. The values in the Vector3 v will be assigned to this variable.
	 * @param v a Vector3 which will have its values assigned to the corresponding uniform variable, with a name of
	 * attributeName, in the shader.
	 */
	void glUniform3(std::string attributeName, glm::vec3 v);
	void glUniform3(std::string attributeName, gl::GLint v0, gl::GLint v1, gl::GLint v2);
	void glUniform4(std::string attributeName, gl::GLfloat v0, gl::GLfloat v1, gl::GLfloat v2, gl::GLfloat v3);
	/**
	 * Assigns the values in a Vector4 to one of the variables in this Shader. The variable in the shader
	 * should probably also be a vec3 or this might cause strange results. <br>
	 * <b><u>Note:</u> Values are cast to floats, so there may be a loss of precision.</b>
	 * @param attributeName a std::string which has the name of one of the uniform variables in the shader with global
	 * scope. The values in the Vector4 v will be assigned to this variable.
	 * @param v a Vector4 which will have its values assigned to the corresponding uniform variable, with a name of
	 * attributeName, in the shader.
	 */
	void glUniform4(std::string attributeName, glm::vec4 v);
	void glUniform4(std::string attributeName, gl::GLint v0, gl::GLint v1, gl::GLint v2, gl::GLint v3);
	//void glUniformMatrix2(std::string attributeName, bool transpose, java.nio.FloatBuffer matrices);
	//void glUniformMatrix3(std::string attributeName, bool transpose, java.nio.FloatBuffer matrices);
	//void glUniformMatrix4(std::string attributeName, bool transpose, java.nio.FloatBuffer matrices);
    void printProgramInfoLog();
    void printShaderInfoLog();
};

std::shared_ptr<Shader> createShader(const std::string *vertFilepath, const std::string *fragFilepath);

#endif
