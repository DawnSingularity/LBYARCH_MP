section .text
bits 64
default rel

global saxpy
saxpy:
    ; Input:
    ;   xmm0 - A (scalar) & output
    ;   xmm1 - X (vector)
    ;   xmm2 - Y (vector)
    ; Output:
    ;   xmm0 - Z (result vector)
    mulss xmm0, xmm1
    addss xmm0, xmm2
    ret