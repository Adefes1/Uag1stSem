Funcion promediocal <- promedioFunc ( cal1, cal2, cal3 )
	
	promediocal <- (cal1 + cal2 + cal3)/3
	Escribir "El promedio de este alumno es de: ", promediocal
	
Fin Funcion

Algoritmo function
	
	alumnos = 1
	
	Repetir 
		
		Escribir "Ingrese la calificacion 1: "
		leer cal1
		
		Escribir "Ingrese la calificacion 2: "
		leer cal2
		
		Escribir "Ingrese la calificacion 3: "
		leer cal3
		
		a = promedioFunc(cal1, cal2, cal3)
		
		alumnos = alumnos + 1
		
	Hasta Que alumnos = 3
	
FinAlgoritmo
