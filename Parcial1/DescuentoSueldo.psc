Algoritmo DescuentoSueldo
	
	Definir sueldo como real
	
	Escribir "Ingrese su sueldo bruto: "
	Leer sueldo
	
	Si sueldo <= 1000
		sueldo = sueldo * 0.9
		Escribir "Su sueldo produce una reducción del 10%. Su sueldo neto es de: $" sueldo
		
	SiNo
		
		Si sueldo >1000 y sueldo <2000
			sueldo = sueldo * 0.85
			Escribir "Su sueldo produce una reducción del 15%. Su sueldo neto es de: $" sueldo
			
		SiNo
			
			sueldo = sueldo * 0.82
			Escribir "Su sueldo produce una reducción del 18%. Su sueldo neto es de: $" sueldo
			
		FinSi
		
	FinSi
	
	
FinAlgoritmo
