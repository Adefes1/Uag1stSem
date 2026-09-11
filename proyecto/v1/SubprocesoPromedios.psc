SubProceso  promedio <- CalcProm ( a,b,c )
	promedio <- (a+b+c)/3
FinSubProceso


Algoritmo promedio3alumnos
	
	Repetir
		Escribir "menu"
		Escribir "1. Ingresar datos de los alumnos"
		Escribir "2. Enseñar promedios"
		Escribir "3. mejor promedio"
		Escribir "4. Salir"
		Escribir "Seleccione uno: "
		Leer option
		
		Segun option Hacer
			1:
				// Alumno 1
				Escribir "Ingrese su nombre, alumno 1: "
				Leer Alumno_1_Nombre
				Escribir "Ingrese su calificación 1: "
				Leer Alumno_1_cal_1
				Escribir "Ingrese su calificación 2: "
				Leer Alumno_1_cal_2
				Escribir "Ingrese su calificación 3: "
				Leer Alumno_1_cal_3
				
				// Alumno 2
				Escribir "Ingrese su nombre, alumno 2: "
				Leer Alumno_2_Nombre
				Escribir "Ingrese su calificación 1: "
				Leer Alumno_2_cal_1
				Escribir "Ingrese su calificación 2: "
				Leer Alumno_2_cal_2
				Escribir "Ingrese su calificación 3: "
				Leer Alumno_2_cal_3
				
				// Alumno 3
				Escribir "Ingrese su nombre, alumno 3: "
				Leer Alumno_3_Nombre
				Escribir "Ingrese su calificación 1: "
				Leer Alumno_3_cal_1
				Escribir "Ingrese su calificación 2: "
				Leer Alumno_3_cal_2
				Escribir "Ingrese su calificación 3: "
				Leer Alumno_3_cal_3
				
				//promedios
				promedio1 <- CalcProm(Alumno_1_cal_1, Alumno_1_cal_2, Alumno_1_cal_3)
				promedio2 <- CalcProm(Alumno_2_cal_1, Alumno_2_cal_2, Alumno_2_cal_3)
				promedio3 <- CalcProm(Alumno_3_cal_1, Alumno_3_cal_2, Alumno_3_cal_3)
				
			2:
				//resultados
				Escribir "El promedio de ", Alumno_1_Nombre, " es de: ", promedio1
				Escribir "El promedio de ", Alumno_2_Nombre, " es de: ", promedio2
				Escribir "El promedio de ", Alumno_3_Nombre, " es de: ", promedio3
				
			3:
				//promedio mayor
				Si promedio1 > promedio2 Y promedio1 > promedio3 Entonces
					Escribir Alumno_1_Nombre, " tiene el promedio más alto con ", promedio1
				SiNo
					Si promedio2 > promedio1 Y promedio2 > promedio3 Entonces
						Escribir Alumno_2_Nombre, " tiene el promedio más alto con ", promedio2
					SiNo
						Escribir Alumno_3_Nombre, " tiene el promedio más alto con ", promedio3
					FinSi
				FinSi
				
			4:
				Escribir "adios"
				
			De Otro Modo:
				Escribir "Error"
		FinSegun
		
	Hasta Que option = 4
	
FinAlgoritmo
