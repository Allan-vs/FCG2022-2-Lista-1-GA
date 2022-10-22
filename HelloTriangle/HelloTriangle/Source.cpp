/* Hello Triangle - código adaptado de https://learnopengl.com/#!Getting-started/Hello-Triangle 
 *
 * Adaptado por Rossana Baptista Queiroz
 * para a disciplina de Processamento Gráfico - Unisinos
 * Versão inicial: 7/4/2017
 * Última atualização em 01/08/2022
 *
 */

#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>
#define PI 3.14159265

using namespace std;

// GLAD
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>

// Classe Shader
#include "Shader.h"

// Protótipo da função de callback de teclado
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Protótipos das funções
int setupGeometry();

// Dimensões da janela (pode ser alterado em tempo de execução)
const GLuint WIDTH = 800, HEIGHT = 600;

// Função MAIN
int main()
{
	// Inicialização da GLFW
	glfwInit();

	//Muita atenção aqui: alguns ambientes não aceitam essas configurações
	//Você deve adaptar para a versão do OpenGL suportada por sua placa
	//Sugestão: comente essas linhas de código para desobrir a versão e
	//depois atualize (por exemplo: 4.5 com 4 e 5)
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Essencial para computadores da Apple
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif

	// Criação da janela GLFW
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ola Triangulo!", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Fazendo o registro da função de callback para a janela GLFW
	glfwSetKeyCallback(window, key_callback);

	// GLAD: carrega todos os ponteiros d funções da OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

	}

	// Obtendo as informações de versão
	const GLubyte* renderer = glGetString(GL_RENDERER); /* get renderer string */
	const GLubyte* version = glGetString(GL_VERSION); /* version as a string */
	cout << "Renderer: " << renderer << endl;
	cout << "OpenGL version supported " << version << endl;

	// Definindo as dimensões da viewport com as mesmas dimensões da janela da aplicação
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);


	// Compilando e buildando o programa de shader
	
	//10.
	Shader shader("../Shaders/hello_triangle.vs", "../Shaders/hello_triangle.fs");

	// Gerando um buffer simples, com a geometria de um triângulo
	GLuint VAO = setupGeometry();
	

	// Enviando a cor desejada (vec4) para o fragment shader
	// Utilizamos a variáveis do tipo uniform em GLSL para armazenar esse tipo de info
	// que não está nos buffers
	
	glUseProgram(shader.ID);
	

	// Loop da aplicação - "game loop"
	while (!glfwWindowShouldClose(window))
	{
		// Checa se houveram eventos de input (key pressed, mouse moved etc.) e chama as funções de callback correspondentes
		glfwPollEvents();

		// Limpa o buffer de cor
		glClearColor(0.8f, 0.8f, 0.8f, 1.0f); //cor de fundo
		glClear(GL_COLOR_BUFFER_BIT);

		glLineWidth(10);
		glPointSize(20);

		// Chamada de desenho - drawcall
		// Poligono Preenchido - GL_TRIANGLES

		glBindVertexArray(VAO);

		//5-a)
		/*shader.setVec4("inputColor", 1.0, 0.5, 1.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 6);*/

		//5-b)
		/*shader.setVec4("inputColor", 0.0, 1.0, 1.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 3); //linha triângulo 1
		glDrawArrays(GL_LINE_LOOP, 3, 3); //linha triângulo 2*/

		//5-c)
		/*shader.setVec4("inputColor", 1.0, 1.0, 0.0, 1.0);
		glDrawArrays(GL_POINTS, 0, 6); //pontos 2 triângulos*/

		//5-d)
		/*shader.setVec4("inputColor", 1.0, 0.5, 1.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		shader.setVec4("inputColor", 0.0, 1.0, 1.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 3); //linha triângulo 1
		glDrawArrays(GL_LINE_LOOP, 3, 3); //linha triângulo 2

		shader.setVec4("inputColor", 1.0, 1.0, 0.0, 1.0);
		glDrawArrays(GL_POINTS, 0, 6); //pontos 2 triângulos*/

		//6-a)
		/*shader.setVec4("inputColor", 0.0, 1.0, 1.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 8);*/

		//6-b)
		/*shader.setVec4("inputColor", 0.0, 1.0, 1.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 10);*/

		//6-c)
		/*shader.setVec4("inputColor", 1.0, 1.0, 0.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 8);*/
		
		//6-d)
		/*shader.setVec4("inputColor", 1.0, 0.0, 0.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 8);
		glDrawArrays(GL_LINE_LOOP, 8, 3);*/

		//7. Não consegui deixar perfeito, mas da pra ver a espiral kkkk
		/*shader.setVec4("inputColor", 1.0, 0.0, 0.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 27);*/

		//8.
		/*shader.setVec4("inputColor", 0.0, 0.0, 1.0, 1.0);
		glDrawArrays(GL_LINE_LOOP, 0, 3);

		shader.setVec4("inputColor", 1.0, 0.0, 0.0, 1.0);
		glDrawArrays(GL_POINTS, 0, 1);
		shader.setVec4("inputColor", 0.0, 1.0, 0.0, 1.0);
		glDrawArrays(GL_POINTS, 1, 1);
		shader.setVec4("inputColor", 0.0, 0.0, 1.0, 1.0);
		glDrawArrays(GL_POINTS, 2, 1);*/

		//9 - T.A.R.D.I.S.
		shader.setVec4("inputColor", 0.0, 0.4, 1.0, 1.0); //lampada
		glDrawArrays(GL_LINE_LOOP, 30, 4);

		shader.setVec4("inputColor", 0.0, 0.0, 1.0, 1.0); //corpo
		glDrawArrays(GL_LINE_LOOP, 0, 12);
		glDrawArrays(GL_TRIANGLES, 12, 18);

		shader.setVec4("inputColor", 0.0, 0.0, 0.0, 1.0); //letreiro
		glDrawArrays(GL_LINE_LOOP, 34, 4);
		glDrawArrays(GL_TRIANGLES, 38, 6);
		
		shader.setVec4("inputColor", 1.0, 1.0, 1.0, 1.0); //janela
		glDrawArrays(GL_TRIANGLES, 44, 12);
		shader.setVec4("inputColor", 0.0, 0.0, 1.0, 1.0);
		glDrawArrays(GL_LINE_STRIP, 56, 2);
		glDrawArrays(GL_LINE_STRIP, 58, 2);
		glDrawArrays(GL_LINE_STRIP, 60, 2);
		glDrawArrays(GL_LINE_STRIP, 62, 2);
		glDrawArrays(GL_LINE_STRIP, 64, 2);
		glDrawArrays(GL_LINE_STRIP, 66, 2);

		shader.setVec4("inputColor", 0.8, 0.8, 0.8, 1.0); //placa
		glDrawArrays(GL_TRIANGLES, 68, 6);

		// Chamada de desenho - drawcall
		// CONTORNO - GL_LINE_LOOP
		// PONTOS - GL_POINTS
		
		
		
		glBindVertexArray(0);

		

		// Troca os buffers da tela
		glfwSwapBuffers(window);
	}
	// Pede pra OpenGL desalocar os buffers
	glDeleteVertexArrays(1, &VAO);
	// Finaliza a execução da GLFW, limpando os recursos alocados por ela
	glfwTerminate();
	return 0;
}

// Função de callback de teclado - só pode ter uma instância (deve ser estática se
// estiver dentro de uma classe) - É chamada sempre que uma tecla for pressionada
// ou solta via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

//Esta função está basntante hardcoded - objetivo é compilar e "buildar" um programa de
// shader simples e único neste exemplo de código
// O código fonte do vertex e fragment shader está nos arrays vertexShaderSource e
// fragmentShader source no iniçio deste arquivo
// A função retorna o identificador do programa de shader

// Esta função está bastante harcoded - objetivo é criar os buffers que armazenam a 
// geometria de um triângulo
// Apenas atributo coordenada nos vértices
// 1 VBO com as coordenadas, VAO com apenas 1 ponteiro para atributo
// A função retorna o identificador do VAO
int setupGeometry()
{
	// Aqui setamos as coordenadas x, y e z do triângulo e as armazenamos de forma
	// sequencial, já visando mandar para o VBO (Vertex Buffer Objects)
	// Cada atributo do vértice (coordenada, cores, coordenadas de textura, normal, etc)
	// Pode ser arazenado em um VBO único ou em VBOs separados

	//5.
	/*GLfloat vertices[] = {
		 0.5, 0.6, 0.0,
		 0.5, -0.4, 0.0,
		 -0.5, 0.6, 0.0,
		 //outro triangulo vai aqui
		 0.5, -0.5, 0.0,
		 -0.5, -0.5, 0.0,
		 -0.5, 0.5, 0.0,
	};*/

	//6-a)
	/*GLfloat vertices[] = {
		cos(0 * PI / 180), sin(0 * PI / 180), 0,
		cos(45 * PI / 180), sin(45 * PI / 180), 0,
		cos(90 * PI / 180), sin(90 * PI / 180), 0,
		cos(135 * PI / 180), sin(135 * PI / 180), 0,
		cos(180 * PI / 180), sin(180 * PI / 180), 0,
		cos(225 * PI / 180), sin(225 * PI / 180), 0,
		cos(270 * PI / 180), sin(270 * PI / 180), 0,
		cos(315 * PI / 180), sin(315 * PI / 180), 0,
		cos(360 * PI / 180), sin(360 * PI / 180), 0,
	};*/

	//6-b)
	/*GLfloat vertices[] = {
		cos(0 * PI / 180), sin(0 * PI / 180), 0,
		cos(36 * PI / 180), sin(36 * PI / 180), 0,
		cos(72 * PI / 180), sin(72 * PI / 180), 0,
		cos(108 * PI / 180), sin(108 * PI / 180), 0,
		cos(144 * PI / 180), sin(144 * PI / 180), 0,
		cos(180 * PI / 180), sin(180 * PI / 180), 0,
		cos(216 * PI / 180), sin(216 * PI / 180), 0,
		cos(252 * PI / 180), sin(252 * PI / 180), 0,
		cos(288 * PI / 180), sin(288 * PI / 180), 0,
		cos(324 * PI / 180), sin(324 * PI / 180), 0,
		cos(360 * PI / 180), sin(360 * PI / 180), 0,
	};*/

	//6-c)
	/*GLfloat vertices[] = {
		0, 0, 0,
		cos(45 * PI / 180), sin(45 * PI / 180), 0,
		cos(90 * PI / 180), sin(90 * PI / 180), 0,
		cos(135 * PI / 180), sin(135 * PI / 180), 0,
		cos(180 * PI / 180), sin(180 * PI / 180), 0,
		cos(225 * PI / 180), sin(225 * PI / 180), 0,
		cos(270 * PI / 180), sin(270 * PI / 180), 0,
		cos(315 * PI / 180), sin(315 * PI / 180), 0,
	};*/

	//6-d)
	/*GLfloat vertices[] = {
		//pizza
		0, 0, 0,
		cos(45 * PI / 180), sin(45 * PI / 180), 0,
		cos(90 * PI / 180), sin(90 * PI / 180), 0,
		cos(135 * PI / 180), sin(135 * PI / 180), 0,
		cos(180 * PI / 180), sin(180 * PI / 180), 0,
		cos(225 * PI / 180), sin(225 * PI / 180), 0,
		cos(270 * PI / 180), sin(270 * PI / 180), 0,
		cos(315 * PI / 180), sin(315 * PI / 180), 0,
		//fatia
		0.1, 0, 0,
		(cos(45 * PI / 180) + 0.1), sin(45 * PI / 180), 0,
		(cos(315 * PI / 180) + 0.1), sin(315 * PI / 180), 0,
	};*/

	//7. Não consegui deixar perfeito, mas da pra ver a espiral kkkk
	/*GLfloat vertices[] = {
		0, 0, 0,
		(cos(315 * PI / 180)-0.75), (sin(315 * PI / 180)+0.75), 0,
		(cos(360 * PI / 180)-0.72), sin(360 * PI / 180), 0,
		(cos(45 * PI / 180)-0.69), (sin(45 * PI / 180)-0.69), 0,
		cos(90 * PI / 180), (sin(90 * PI / 180)-0.66), 0,
		(cos(135 * PI / 180)+0.63), (sin(135 * PI / 180)-0.63), 0,
		(cos(180 * PI / 180)+0.6), sin(180 * PI / 180), 0,
		(cos(225 * PI / 180)+0.57), (sin(225 * PI / 180)+0.57), 0,
		cos(270 * PI / 180), (sin(270 * PI / 180)+0.54), 0,
		(cos(315 * PI / 180)-0.51), (sin(315 * PI / 180)+0.51), 0,
		(cos(360 * PI / 180)-0.48), sin(360 * PI / 180), 0,
		(cos(45 * PI / 180)-0.45), (sin(45 * PI / 180)-0.45), 0,
		cos(90 * PI / 180), (sin(90 * PI / 180)-0.42), 0,
		(cos(135 * PI / 180)+0.39), (sin(135 * PI / 180)-0.39), 0,
		(cos(180 * PI / 180)+0.36), sin(180 * PI / 180), 0,
		(cos(225 * PI / 180)+0.33), (sin(225 * PI / 180)+0.33), 0,
		cos(270 * PI / 180), (sin(270 * PI / 180)+0.30), 0,
		(cos(315 * PI / 180)-0.27), (sin(315 * PI / 180)+0.27), 0,
		(cos(360 * PI / 180)-0.24), sin(360 * PI / 180), 0,
		(cos(45 * PI / 180)-0.21), (sin(45 * PI / 180)-0.21), 0,
		cos(90 * PI / 180), (sin(90 * PI / 180)-0.18), 0,
		(cos(135 * PI / 180)+0.15), (sin(135 * PI / 180)-0.15), 0,
		(cos(180 * PI / 180)+0.12), sin(180 * PI / 180), 0,
		(cos(225 * PI / 180)+0.09), (sin(225 * PI / 180)+0.09), 0,
		cos(270 * PI / 180), (sin(270 * PI / 180)+0.06), 0,
		(cos(315 * PI / 180)-0.03), (sin(315 * PI / 180)+0.03), 0,
		cos(360 * PI / 180), sin(360 * PI / 180), 0,
	};*/

	//8.
	/*GLfloat vertices[] = {
	 0, 0.6, 0.0,
	 -0.6, -0.5, 0.0,
	 0.6, -0.3, 0.0,
	};*/

	//9
	GLfloat vertices[] = {
	//corpo outline
	-0.5, 0.7, 0,
	0.5, 0.7, 0,
	0.5, 0.6, 0,
	0.6, 0.6, 0,
	0.6, -0.8, 0,
	0.7, -0.8, 0,
	0.7, -0.9, 0,
	-0.7, -0.9, 0,
	-0.7, -0.8, 0,
	-0.6, -0.8, 0,
	-0.6, 0.6, 0,
	-0.5, 0.6, 0,
	//corpo triangulos
	-0.5, 0.7, 0,
	0.5, 0.7, 0,
	0.5, -0.9, 0,

	-0.5, -0.9, 0,
	-0.5, 0.7, 0,
	0.5, -0.9, 0,

	-0.6, 0.6, 0,
	0.6, 0.6, 0,
	0.6, -0.9, 0,

	-0.6, -0.9, 0,
	-0.6, 0.6, 0,
	0.6, -0.9, 0,

	-0.7, -0.9, 0,
	-0.7, -0.8, 0,
	0.7, -0.8, 0,

	-0.7, -0.9, 0,
	0.7, -0.8, 0,
	0.7, -0.9, 0,
	//lampada outline
	-0.1, 0.9, 0,
	0.1, 0.9, 0,
	0.1, 0.7, 0,
	-0.1, 0.7, 0,
	//letreiro outline
	-0.5, 0.5, 0,
	0.5, 0.5, 0,
	0.5, 0.4, 0,
	-0.5, 0.4, 0,
	//letreiro triangulos
	-0.5, 0.5, 0,
	0.5, 0.5, 0,
	0.5, 0.4, 0,

	0.5, 0.4, 0,
	-0.5, 0.4, 0,
	-0.5, 0.5, 0,
	//janela 1
	-0.4, 0.3, 0,
	-0.1, 0.3, 0,
	-0.1, -0.1, 0,

	-0.4, -0.1, 0,
	-0.4, 0.3, 0,
	-0.1, -0.1, 0,
	//janela 2
	0.4, 0.3, 0,
	0.1, 0.3, 0,
	0.1, -0.1, 0,

	0.4, -0.1, 0,
	0.4, 0.3, 0,
	0.1, -0.1, 0,
	//linha 1 janela 1
	-0.3, 0.3, 0,
	-0.3, -0.1, 0,
	//linha 2 janela 1
	-0.2, 0.3, 0,
	-0.2, -0.1, 0,
	//linha 3 janela 1
	-0.4, 0.1, 0,
	-0.1, 0.1, 0,
	//linha 1 janela 2
	0.3, 0.3, 0,
	0.3, -0.1, 0,
	//linha 2 janela 2
	0.2, 0.3, 0,
	0.2, -0.1, 0,
	//linha 3 janela 2
	0.4, 0.1, 0,
	0.1, 0.1, 0,
	//placa
	-0.4, -0.2, 0,
	-0.2, -0.2, 0,
	-0.2, -0.5, 0,

	-0.4, -0.5, 0,
	-0.4, -0.2, 0,
	-0.2, -0.5, 0,
	};

	GLuint VBO, VAO;

	//Geração do identificador do VBO
	glGenBuffers(1, &VBO);
	//Faz a conexão (vincula) do buffer como um buffer de array
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//Envia os dados do array de floats para o buffer da OpenGl
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Geração do identificador do VAO (Vertex Array Object)
	glGenVertexArrays(1, &VAO);
	// Vincula (bind) o VAO primeiro, e em seguida  conecta e seta o(s) buffer(s) de vértices
	// e os ponteiros para os atributos 
	glBindVertexArray(VAO);
	//Para cada atributo do vertice, criamos um "AttribPointer" (ponteiro para o atributo), indicando: 
	// Localização no shader * (a localização dos atributos devem ser correspondentes no layout especificado no vertex shader)
	// Numero de valores que o atributo tem (por ex, 3 coordenadas xyz) 
	// Tipo do dado
	// Se está normalizado (entre zero e um)
	// Tamanho em bytes 
	// Deslocamento a partir do byte zero 

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Observe que isso é permitido, a chamada para glVertexAttribPointer registrou o VBO como o objeto de buffer de vértice 
	// atualmente vinculado - para que depois possamos desvincular com segurança
	glBindBuffer(GL_ARRAY_BUFFER, 0); 

	// Desvincula o VAO (é uma boa prática desvincular qualquer buffer ou array para evitar bugs medonhos)
	glBindVertexArray(0); 

	return VAO;
}

