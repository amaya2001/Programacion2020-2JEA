    .data
        word: .space 1000
    .text
    # el arreglo se guardara en s1
main:
    lui $s1, 0x1000
    ori $s1, $s1, 0x0000
    addi $s0, $0, 4000 # Tamaño total
    addi $t0, $0, 0 # Declaración del i 
    addi $s2, $0, 8 # Multiplo constante
For:
    beq $t0, $s0, exit # Compara si i es igual a 1000
    lw $t2, 0($s1) # lee el valor del Array de s1 en t2
    sll $t2, $t2, $s2 # Multiplica el valor del array por el multiplo constante que es 8
    sw $t2, 0($s1) # Escribe el valor 
    addi $t0, $t0, 1 # Incremento i
    addi $s1, $s1, 4 # siquiente posición del array (se suma 4 porque cada valor es de 4 bytes)
    j For # Vuelve a llamar a For hasta que el beq se cumpla

exit:
    jr $ra
    .end