# Programa Keylogger

Este es un simple programa keylogger escrito en C. Registra todas las pulsaciones de teclas realizadas en el sistema y las guarda en un archivo de registro especificado.

## Requisitos previos

- Sistema operativo Linux
- Compilador C (por ejemplo, gcc)
- Biblioteca xkbcommon

## Instalación

1. Clona el repositorio:

    ```bash
    git clone https://github.com/tuusuario/keylogger.git
    ```

2. Navega hasta el directorio del proyecto:

    ```bash
    cd keylogger
    ```

3. Compila el programa:

    ```bash
    gcc -o keylogger keylogger.c -lxkbcommon
    ```

## Uso

Ejecuta el programa:

    ```bash
    ./keylogger
    ```
El programa comenzará a registrar las pulsaciones de teclas. Para detener el programa, usa `Ctrl+C`.

## Configuración

La ruta del archivo de registro está definida por la macro `LOGFILEPATH` en el código fuente. Por defecto, está configurada en `/home/seguridad/keylogger.txt`. Puedes cambiar esta ruta a cualquier ubicación válida en tu sistema.

## Supuestos

- El programa supone que el teclado es el único dispositivo de entrada conectado al sistema.
- El programa supone que el usuario tiene los permisos necesarios para leer del dispositivo de entrada y escribir en el archivo de registro.

## Limitaciones

- El programa no registra las pulsaciones de teclas realizadas en campos de entrada de texto seguros (por ejemplo, campos de contraseña en navegadores web).
- El programa no maneja correctamente los caracteres especiales o combinaciones de teclas (por ejemplo, `Ctrl+C`, `Alt+Tab`).

## Casos de uso

- Monitoreo de pulsaciones de teclas con fines de seguridad (por ejemplo, detección de acceso no autorizado a un sistema).
- Grabación de pulsaciones de teclas con fines de prueba o depuración.

## Contribuciones

Las solicitudes de extracción son bienvenidas. Para cambios importantes, por favor abre un issue primero para discutir lo que te gustaría cambiar.


