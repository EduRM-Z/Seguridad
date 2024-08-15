# Programa Keylogger

Este es un simple programa keylogger escrito en C. Registra todas las pulsaciones de teclas realizadas en el sistema y las guarda en un archivo de registro especificado, también guarda capturas de pantalla cada minuto.

## Requisitos previos

- Sistema operativo Linux
- Compilador C (por ejemplo, gcc)
- Tener instalado scrot
- Tener creado el archivo .txt para guardar los tecleos
- Tener creada la carpeta de las rutas donde se van a guardar las capturas

## Instalación

1. Clona el repositorio

2. Navega hasta el directorio del proyecto

3. Compila el programa:

## Uso

Ejecuta el programa en modo super usuario:

    ```bash
    sudo ./keylogger
    ```
El programa comenzará a registrar las pulsaciones de teclas. Para detener el programa, usa `Ctrl+C`.

## Configuración

La ruta del archivo de registro está definida por la macro `LOGFILEPATH` en el código fuente. Por defecto, está configurada en `/home/seguridad/keylogger.txt`. Puedes cambiar esta ruta a cualquier ubicación válida en tu sistema.

No olvides crear la carpeta donde se van a guardar las capturas, cambia la ruta también "scrot /home/seguridad/screenshots/%s.png"

Instala scrot con el siguiente comando: sudo apt-get install scrot


## Supuestos

- El programa supone que el teclado es el único dispositivo de entrada conectado al sistema.
- El programa supone que el usuario tiene los permisos necesarios para leer del dispositivo de entrada y escribir en el archivo de registro.
- El programa supone que las carpetas y librerias estan previamente creadas e instaladas.

## Limitaciones

- El programa no registra las pulsaciones de teclas realizadas en campos de entrada de texto seguros (por ejemplo, campos de contraseña en navegadores web).
- El programa no maneja correctamente los caracteres especiales o combinaciones de teclas (por ejemplo, `Ctrl+C`, `Alt+Tab`) pero si maneja la gran otra mayoría.

## Casos de uso

- Monitoreo de pulsaciones de teclas con fines de seguridad (por ejemplo, detección de acceso no autorizado a un sistema).
- Grabación de pulsaciones de teclas con fines de prueba o depuración.
- Monitoreo de pantalla cada minuto

## Contribuciones

Las solicitudes de extracción son bienvenidas. Para cambios importantes, por favor abre un issue primero para discutir lo que te gustaría cambiar.


