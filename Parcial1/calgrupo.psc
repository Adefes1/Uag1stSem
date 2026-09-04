Algoritmo calgrupo
	
	Definir cal1, cal2, cal3, promedioindi, promediogrupo Como Real
	definir keeploop Como Caracter
	Definir alumnos Como Entero
	
	alumnos <- 0
	promediogrupo <- 0
	
	Escribir "Desea ingresar la calificación de un alumno? si/no"
	Leer keeploop
	
	Mientras keeploop = "si" Hacer
		Escribir "Ingrese la calificación 1: "
		Leer cal1
		Escribir "Ingrese la calificación 2: "
		Leer cal2
		Escribir "Ingrese la calificación 3: "
		Leer cal3
		promedioindi <- (cal1 + cal2+ cal3)/3
		promediogrupo <- cal1 + cal2+ cal3
		
		alumnos <- alumnos + 1
		
		Escribir "El promedio del alumno es de: ", promedioindi
		
		Escribir "Desea ingresar las calificaciones de otro alumno: si/no"
		Leer keeploop
		
	Fin Mientras
	
	promediogrupo <- promediogrupo/alumnos
	
	Escribir "El promedio del grupo es: ", promediogrupo
	
FinAlgoritmo
