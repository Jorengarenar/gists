; wersja NASM na system 64-bitowy (x86-64)
; kompilacja: nasm -felf64 hello64.asm -o hello64.o
; linkowanie: ld hello64.o -o hello64

    bits 64

section .code                        ; początek sekcji kodu.
    global _start                    ; linux rozpoczyna wykonywanie programu od etykiety _start
                                     ; musi ona być widoczna na zewnątrz (global)

_start:                              ; punkt startu programu
    mov rax, 1                       ; numer funkcji systemowej:
                                     ;     sys_write - zapisz do pliku
    mov rdi, 1                       ; numer pliku, do którego piszemy.
                                     ;     1 = standardowe wyjście = ekran
    mov rsi, tekst                   ; RSI = adres (offset) tekstu
    mov rdx, dlugosc                 ; RDX = długość tekstu
    syscall                          ; wywołujemy funkcję systemową
    mov rax, 60                      ; numer funkcji systemowej
                                     ;     (sys_exit - wyjdź z programu)
    syscall                          ; wywołujemy funkcję systemową

section .data                        ; początek sekcji danych
    tekst   db  "Hello World!", 0ah  ; nasz napis, który wyświetlimy
    dlugosc equ $ - tekst            ; długość napisu
