ETSIDI-PRÁCTICAS

Información sobre FreeGlut

Para poder usar esta librería se han realizado los siguientes pasos:

1.-Se ha descargado el código fuente y compilado por medio de CMAKE la librería dinámica para 64 bits en modo Release

2.-Se han copiado el .lib y .dll correspondientes 

3.-Se ha copiado el freeglut_std.h

4.-Se ha comentado la linea 94 de dicho include para que el #pragma incluya la librería release también en modo debug, por lo que se ha agregado a continuación la línea:

   #pragma comment (lib, "freeglut.lib")

5.-Se ha cambiado el nombre del fichero a freeglut.h
