Algoritmo Cálculoperímetros
	
	Definir option Como Entero
	Definir resultado, lado, radio Como Real
	
	Escribir "Escoja una opción: 1 para triángulo equilatero, 2 para cuadrado y 3 para circulo: "
	Leer option
	
	Segun option Hacer
		
		1: Escribir "Ingrese la medida de un lado en centimetros: "
			Leer lado
			resultado <- lado*3
			Escribir "El perimetro de su triangulo es de: ", resultado, "centimetros."
			
		2: Escribir "Ingrese la medida de un lado en centimetros: "
			Leer lado
			resultado <- lado*4
			Escribir "El perimetro de su cuadrado es de: ", resultado, "centimetros."
			
		3: Escribir "Ingrese la medida de su radio en centimetros: "
			Leer radio
			resultado <- radio*2*3.141592
			Escribir "El perimetro de su círculo es de: ", resultado, "centimetros."
			
		De Otro Modo:
			Escribir "error"
		
	FinSegun
	
FinAlgoritmo
