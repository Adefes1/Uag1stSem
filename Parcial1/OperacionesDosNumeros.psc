Algoritmo OperacionesDosNumeros
	
	definir a, b, resultado Como Real
	
	Escribir "Ingrese su primer número: "
	Leer a
	
	Escribir "Ingrese su segundo número: "
	Leer b
	
	Si a = b
		resultado <- a*b
		Escribir "El producto de ambos números es: ", resultado
		
	SiNo
		Si a > b
			resultado <- a - b
			Escribir "La diferencia de ambos números es: ", resultado
			
		SiNo
			resultado <- a +b
			Escribir "La suma de ambos números es: ", resultado
		FinSi
	FinSi
	
FinAlgoritmo
