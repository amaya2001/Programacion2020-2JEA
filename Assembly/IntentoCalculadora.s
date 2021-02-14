# Calculadora: Pide dos datos, los suma, resta, multiplica, divide y saca el porcentaje
        .data
mensaje1: .asciiz "Hola, bienvenido a la tienda de chucho!!!!!!!\n"
mensaje2: .asciiz "Ingrese el primer dato: "
mensaje3: .asciiz "Ingrese el segundo dato: "
mensaje4: .asciiz "\nEl resultado de la suma es: "
mensaje5: .asciiz "\nEl resultado de la resta es: "
mensaje6: .asciiz "\nEl resultado de la multiplicacion es: "
mensaje7: .asciiz "\nEl resultado de la division es: "
mensaje8: .asciiz "\nEl resultado de la porcentaje es: "

        .text
main:
        li  $v0, 4 # No se si es necesario!
        la  $a0, mensaje1
        syscall
        li  $v0, 4
        la  $a0, mensaje2
        syscall
        jal getData
        add $s0, $0, $v0
        li  $v0, 4
        la  $a0, mensaje3
        syscall
        jal getData
        add $s1, $0, $v0
        # --------------------->
        jal suma
        # --------------------->
        jal resta
        # --------------------->
        jal multi
        # --------------------->
        jal divi
        # --------------------->
        jal porce
exit:
        li  $v0, 10
        syscall       
getData:
        li  $v0, 5
        syscall
        jr $ra
suma:
        # Se realiza la operación suma
        add $s2, $s0, $s1
        # Impresion de resultado suma
        li  $v0, 4
        la  $a0, mensaje4
        # Suma:
        li  $v0, 1
        add $a0, $0, $s2
        syscall
        jr $ra
resta:
        # Se realiza la operación resta
        sub $s3, $s0, $s1 
        # Impresion de resultado Resta
        li  $v0, 4
        la  $a0, mensaje5
        syscall
        # Resta:
        li  $v0, 1
        add $a0, $0, $s3
        syscall
        jr $ra
multi:
        # Se realiza la operación multiplicación
        mul $s4, $s0, $s1 
        # Impresion de resultado Multiplicación
        li  $v0, 4
        la  $a0, mensaje6
        syscall
        # Multiplicación:
        li  $v0, 1
        add $a0, $0, $s4
        syscall
        jr $ra
divi:
        # Se realiza la operación division
        div $s5, $s0, $s1 
        # Impresion de resultado Division
        li  $v0, 4
        la  $a0, mensaje7
        syscall
        # Division:
        li  $v0, 1
        add $a0, $0, $s5
        syscall
        jr $ra
porce:
        # Se realiza la operación porcentaje
        div $s6, $s4, 100 
        # Impresion de resultado Porcentaje
        li  $v0, 4
        la  $a0, mensaje8
        syscall
        # Porcentaje:
        li  $v0, 1
        add $a0, $0, $s6
        syscall
        jr $ra

        .end
        
        
