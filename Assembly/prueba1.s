# Prueba laboratorio logica. Primera clase
# Sumar dos valores constantes -> add.

    .data # Valores en memoria.
mensaje1: .asciiz "Ingrese el primer dato: "
mensaje2: .asciiz "Ingrese el segundo dato: "
mensaje3: .asciiz "El resultado de la suma es: "

    .text # Codigo
main: # Aqui arranca el programa.
      # 5 + 10
        addi $t0, $0, 5 # En el registro 0, estoy sumando su valor = 0 + 5.
        addi $t1, $0, 10
        add  $t2, $t1, $t0
      # =====================================================>
        li   $t3, 1000000 # Load inmediate -> Cuando los valores son muy grandes.
        add  $t4, $t3, $t3 # Se suma el registro con el mismo.
      # =====================================================>
      # Pedir primer numero 
        li   $v0, 4
        la   $a0, mensaje1 # Load address
        syscall
        li   $v0, 5
        syscall
        add  $s0, $0, $v0
        li   $v0, 4
        la   $a0, mensaje2
        syscall
        li   $v0, 5
        syscall
        add  $s1, $0, $v0
      # Hace la operación
        add  $s2, $s1, $s0
        li   $v0, 4
        la   $a0, mensaje3
        syscall
        li   $v0, 1
        add  $a0, $0, $s2
        syscall
exit:
        li   $v0, 10 # System call for exit.
        syscall
    .end # Final de la instrucción.