Algoritmo NotasEstudiante
	Definir cantidadNotas, aprobadas, reprobadas, contadora Como Entero
	Definir promedioNotas, promedioAprobadas, promedioReprobadas, nota Como Real
	
	cantidadNotas <- 0
	aprobadas <- 0
	reprobadas <-0
	promedioAprobadas <- 0
	promedioReprobadas <- 0
	nota <- 0
	
	Escribir "Notas a ingresar: "
	Leer cantidadNotas
	
	contadora <- 1
	
	Mientras contadora <= cantidadNotas Hacer
	
		Escribir "Ingrese la nota: ", contadora
		leer nota
		
		si nota >= 7
			aprobadas <- aprobadas + 1
			promedioAprobadas <- promedioAprobadas + nota
		sino 
			reprobadas <- reprobadas +1
			promedioReprobadas <- promedioReprobadas + nota
		FinSi
		
		contadora <- contadora + 1
		
	Fin mientras
	
	promediogeneral <- (promedioAprobadas + promedioReprobadas)/cantidadNotas
	si aprobadas > 0 Entonces
		promedioAprobadas <- promedioAprobadas/aprobadas
	FinSi
	
	si reprobadas > 0 Entonces
		promedioReprobadas <- promedioReprobadas/reprobadas
	FinSi
	
	Escribir "Reprobó: ", reprobadas, " materias. Aprobó: ", aprobadas, " su promedio general es de: ", promediogeneral, " su promedio de aprobadas es de: ", promedioAprobadas, " y su promedio de reprobadas es de: ", promedioReprobadas
FinAlgoritmo
