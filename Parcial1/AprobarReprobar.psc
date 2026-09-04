Algoritmo AprobarReprobar
	
	Definir calA, calB, calC Como Real
	
	Definir Estado Como Caracter
	
	Escribir "Ingrese su primera calificación: "
	Leer calA
	
	Escribir "Ingrese su segunda calificación: "
	Leer calB
	
	Escribir "Ingrese su tercera calificación: "
	Leer calC
	
	Si (calA + calB + calC)/3 < 6
		Entonces
		Escribir "REPROBADO"
		
	SiNo
		Escribir "APROBADO"
	FinSi
	
FinAlgoritmo
